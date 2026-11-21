#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include <cmath>

using namespace geode::prelude;

class MapImageLayer : public CCLayerColor {
    CCSprite* m_image = nullptr;
    CCMenuItemSpriteExtra* m_closeButton = nullptr;
    CCPoint m_last;
    bool m_dragging = false;

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

        constexpr float zoom = 2.45f;
        m_image->setScaleX((win.width / size.width) * zoom);
        m_image->setScaleY((win.height / size.height) * zoom);
        addChild(m_image);

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

    void onExit() override {
        CCDirector::sharedDirector()->getTouchDispatcher()
            ->removeDelegate(this);

        CCLayerColor::onExit();
    }
};

class $modify(CreatorLayer) {
    void onAdventureMap(CCObject* sender) {
        auto layer = MapImageLayer::create();

        if (layer)
            addChild(layer, 10000);
    }
};
