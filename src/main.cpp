#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include <cmath>

using namespace geode::prelude;

class MapImageLayer : public CCLayerColor {
    CCSprite* m_image = nullptr;
    CCMenuItemSpriteExtra* m_closeButton = nullptr;

public:
    bool init() override {
        if (!CCLayerColor::initWithColor({0, 0, 0, 255}))
            return false;

        auto win = CCDirector::sharedDirector()->getWinSize();

        m_image = CCSprite::create("map.png"_spr);
        if (!m_image)
            return false;

        auto size = m_image->getContentSize();
        m_image->setPosition(win / 2);

        constexpr float zoom = 1.50f;
        m_image->setScaleX((win.width / size.width) * zoom);
        m_image->setScaleY((win.height / size.height) * zoom);

        addChild(m_image);

        // Botão X
        auto closeSprite = CCSprite::create("GJ_closeBtn_001.png"_spr);
        if (!closeSprite)
            return false;

        m_closeButton = CCMenuItemSpriteExtra::create(
            closeSprite,
            this,
            menu_selector(MapImageLayer::onClose)
        );

        auto menu = CCMenu::create(m_closeButton, nullptr);
        menu->setPosition(CCPointZero);

        m_closeButton->setPosition({
            win.width - 25,
            win.height - 25
        });

        addChild(menu, 100);

        setTouchEnabled(true);
        setKeypadEnabled(true);

        return true;
    }

    static MapImageLayer* create() {
        auto ret = new MapImageLayer();

        if (ret && ret->init()) {
            ret->autorelease();
            return ret;
        }

        CC_SAFE_DELETE(ret);
        return nullptr;
    }

    void onClose(CCObject*) {
        removeFromParentAndCleanup(true);
    }

    void registerWithTouchDispatcher() override {
        CCDirector::sharedDirector()->getTouchDispatcher()
            ->addTargetedDelegate(this, -500, true);
    }

    void onExit() override {
        CCDirector::sharedDirector()->getTouchDispatcher()
            ->removeDelegate(this);

        CCLayerColor::onExit();
    }

    bool ccTouchBegan(CCTouch* touch, CCEvent*) override {
        auto pos = convertToNodeSpace(touch->getLocation());

        if (m_closeButton &&
            m_closeButton->boundingBox().containsPoint(pos))
            return false;

        m_dragging = m_image->boundingBox().containsPoint(pos);

        if (m_dragging)
            m_last = pos;

        return true;
    }

    void ccTouchEnded(CCTouch*, CCEvent*) override {
        m_dragging = false;
    }

    void ccTouchCancelled(CCTouch*, CCEvent*) override {
        m_dragging = false;
    }

    void ccTouchMoved(CCTouch* touch, CCEvent*) override {
        if (!m_dragging)
            return;

        auto pos = convertToNodeSpace(touch->getLocation());

        auto delta = pos - m_last;
        auto newPos = m_image->getPosition() + delta;

        auto size = m_image->getContentSize();
        auto anchor = m_image->getAnchorPoint();
        auto win = CCDirector::sharedDirector()->getWinSize();

        float width = size.width * m_image->getScaleX();
        float height = size.height * m_image->getScaleY();

        float minX = win.width - width * (1.0f - anchor.x);
        float maxX = width * anchor.x;

        float minY = win.height - height * (1.0f - anchor.y);
        float maxY = height * anchor.y;

        newPos.x = fmaxf(minX, fminf(maxX, newPos.x));
        newPos.y = fmaxf(minY, fminf(maxY, newPos.y));

        m_image->setPosition(newPos);
        m_last = pos;
    }

    void keyBackClicked() override {
        removeFromParentAndCleanup(true);
    }

private:
    CCPoint m_last;
    bool m_dragging = false;
};

class $modify(MyCreatorLayer, CreatorLayer) {
    bool init() {
        if (!CreatorLayer::init())
            return false;

        // Diagnostico dos nos da CreatorLayer
        std::function<void(CCNode*, int)> inspect = [&](CCNode* node, int depth) {
            if (!node) return;

            auto indent = std::string(depth * 2, ' ');
            log::info("{}Node: {} | ID: {} | Tag: {}",
                indent,
                typeid(*node).name(),
                node->getID(),
                node->getTag()
            );

            if (auto sprite = typeinfo_cast<CCSprite*>(node)) {
                auto color = sprite->getColor();
                log::info("{}Sprite color: {},{},{} opacity: {}",
                    indent, color.r, color.g, color.b, sprite->getOpacity());
            }

            if (auto menu = typeinfo_cast<CCMenu*>(node)) {
                for (auto* child : CCArrayExt<CCNode*>(menu->getChildren())) {
                    if (auto btn = typeinfo_cast<CCMenuItemSpriteExtra*>(child)) {
                        log::info("{}BUTTON enabled: {}", indent, btn->isEnabled());
                    }
                }
            }

            for (auto* child : CCArrayExt<CCNode*>(node->getChildren())) {
                inspect(child, depth + 1);
            }
        };

        log::info("=== THE MAP: CREATORLAYER DIAGNOSTIC ===");
        inspect(this, 0);
        log::info("=== END DIAGNOSTIC ===");

        return true;
    }

    void onAdventureMap(CCObject* sender) {
        auto layer = MapImageLayer::create();

        if (layer)
            addChild(layer, 10000);
    }
};
