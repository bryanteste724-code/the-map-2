#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>

using namespace geode::prelude;

class MapImageLayer : public CCLayer {
    CCSprite* m_image = nullptr;
    CCPoint m_last;

public:
    bool init() override {
        if (!CCLayer::init())
            return false;

        auto win = CCDirector::sharedDirector()->getWinSize();

        m_image = CCSprite::create("map.png"_spr);

        if (!m_image)
            return false;

        auto size = m_image->getContentSize();

        m_image->setPosition(win / 2);
        m_image->setScaleX(win.width / size.width);
        m_image->setScaleY(win.height / size.height);

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

        CCLayer::onExit();
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
        m_image->setPosition(m_image->getPosition() + pos - m_last);
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
