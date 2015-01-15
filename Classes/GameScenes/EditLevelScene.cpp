//
//  EditLevelScene.cpp
//  SuperLife
//
//  Created by wang haibo on 15/1/14.
//
//

#include "EditLevelScene.h"
#include "TerrainMgr.h"
#include "UIMgr.h"
#include "UIConst.h"
USING_NS_CC;
//构造
LevelEditorScene::LevelEditorScene()
{
    m_pLevelEditorUI = nullptr;
}
//析构
LevelEditorScene::~LevelEditorScene()
{
}
void LevelEditorScene::onEnter()
{
    BaseScene::onEnter();
    TerrainMgr::getInstance()->addTerrain(TerrainCell::RECTANGLE, 60, 60, 6, Vec2(70, 102));
    m_pLevelEditorUI = UIMgr::getInstance()->createUI(LEVEL_EDITOR_UI);
}
void LevelEditorScene::onExit()
{
    TerrainMgr::getInstance()->removeTerrain();
    BaseScene::onExit();
}
// 更新处理
void LevelEditorScene::update(float delta)
{
    BaseScene::update(delta);
    if(!m_bPause)
        TerrainMgr::getInstance()->update(delta);
    if(m_pLevelEditorUI)
        m_pLevelEditorUI->update(delta);
}
// 设置场景颜色
void LevelEditorScene::setSceneColor(const cocos2d::Color3B& color)
{
    m_pLevelEditorUI->setColor(color);
    TerrainMgr::getInstance()->updateTerrain();
}