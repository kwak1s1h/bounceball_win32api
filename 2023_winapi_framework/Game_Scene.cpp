#include "pch.h"
#include "Game_Scene.h"
#include "Object.h"
#include "Core.h"
#include "Player.h"
#include "Ground.h"
#include "KeyMgr.h"
#include "CollisionMgr.h"
#include "ResMgr.h"
void Game_Scene::Init()
{
	Object* pObj = new Player;
	pObj->SetPos((Vec2({Core::GetInst()->GetResolution().x /2, Core::GetInst()->GetResolution().y / 2})));
	pObj->SetScale(Vec2(100.f,100.f));
	AddObject(pObj, OBJECT_GROUP::PLAYER);

	for (int i = 0; i < 5; i++)
	{
		Object* pG1 = new Ground;
		pG1->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 + 200 })));
		Vec2 pos = pG1->GetPos();
		pG1->SetPos(pos + Vec2(i * 59.f, 0.f));
		pG1->SetScale(Vec2(100.f, 100.f));
		AddObject(pG1, OBJECT_GROUP::GROUND);
	}

	// 사운드 세팅
	ResMgr::GetInst()->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	ResMgr::GetInst()->LoadSound(L"Shoot", L"Sound\\laserShoot.wav", false);
	//ResMgr::GetInst()->Play(L"BGM");

	// 충돌체크해야되는것들을 설정하자.
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::GROUND);
}

void Game_Scene::Update()
{
	Scene::Update();
	//if(KEY_DOWN(KEY_TYPE::ENTER))
	//	// 씬 변경
}

void Game_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Game_Scene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
