#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>

using namespace geode::prelude;

class MapImageLayer : public CCLayerColor {
    CCSprite* m_image = nullptr;
    CCPoint m_last;

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

        if (!m_image->boundingBox().containsPoint(pos))
            return false;

        m_last = pos;
        return true;
    }

    void ccTouchMoved(CCTouch* touch, CCEvent*) override {
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
};

class $modify(MyCreatorLayer, CreatorLayer) {
    void onAdventureMap(CCObject* sender) {
        auto layer = MapImageLayer::create();

        if (layer)
            addChild(layer, 1000);
    }
};
