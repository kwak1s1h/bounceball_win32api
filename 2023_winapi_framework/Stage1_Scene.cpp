#include "pch.h"
#include "Stage1_Scene.h"
#include "Scene.h"
#include "Ground.h"
#include "DisappearGround.h"
#include "ButtonGround.h"
#include "OperatingGround.h"
#include "StarItem.h"
#include "ElectricObstacle.h"
#include "Core.h"
#include "GameMgr.h"
#include "EventMgr.h"

void Stage1_Scene::Init()
{
	Vec2 PlayerPos;
	int m_iStarCount = 0;

	for (int h = 0; h < 18; h++) {
		for (int w = 0; w < 32; w++) {
			switch (m_iMapSet[h][w]) {
			case 0:
				break;
			case 1:
				Ground * pGround = nullptr;
				pGround = new Ground;
				pGround->SetPos(Vec2(h * 60, w * 60));
				pGround->SetScale(Vec2(60, 60));
				AddObject(pGround, OBJECT_GROUP::GROUND);
				break;
			case 2:
				DisappearGround * pDisGround = nullptr;
				pDisGround = new DisappearGround;
				pDisGround->SetPos(Vec2(h * 60, w * 60));
				pDisGround->SetScale(Vec2(60, 60));
				AddObject(pDisGround, OBJECT_GROUP::GROUND);
				break;
			case 3:
				ButtonGround * pBtnGround = nullptr;
				pBtnGround = new ButtonGround;
				pBtnGround->SetPos(Vec2(h * 60, w * 60));
				pBtnGround->SetScale(Vec2(60, 60));
				AddObject(pBtnGround, OBJECT_GROUP::GROUND);
				break;
			case 4:
				OperatingGround * pOprGround = nullptr;
				pOprGround = new OperatingGround;
				pOprGround->SetPos(Vec2(h * 60, w * 60));
				pOprGround->SetScale(Vec2(60, 60));
				AddObject(pOprGround, OBJECT_GROUP::GROUND);
				break;
			case 5:
				StarItem * pStarItem = nullptr;
				pStarItem = new StarItem;
				pStarItem->SetPos(Vec2(h * 60, w * 60));
				pStarItem->SetScale(Vec2(60, 60));
				AddObject(pStarItem, OBJECT_GROUP::ITEM);
				m_iStarCount++;
				break;
			case 6:
				ElectricObstacle * pElectricObstacle = nullptr;
				pElectricObstacle = new ElectricObstacle;
				pElectricObstacle->SetPos(Vec2(h * 60, w * 60));
				pElectricObstacle->SetScale(Vec2(60, 60));
				AddObject(pElectricObstacle, OBJECT_GROUP::OBSTACLE);
				break;
			case 7:
				PlayerPos = Vec2(h * 60, w * 60);
				break;
			}
		}
	}

	GameMgr::GetInst()->SetStarCount(m_iStarCount);
	
}

void Stage1_Scene::Update()
{
	if (GameMgr::GetStarCount == 0) {
	}
}

void Stage1_Scene::Render(HDC _dc)
{
}

void Stage1_Scene::Release()
{
}
