#include "pch.h"
#include "Start_Scene.h"
#include "Button.h"
#include "Core.h"

void Start_Scene::Init()
{
	Button* btn = new Button(L"Play\nGame");
	btn->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	btn->SetScale(Vec2(300.f, 75.f));
	AddObject(btn, OBJECT_GROUP::UI);
}

void Start_Scene::Update()
{
	Scene::Update();
}

void Start_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Start_Scene::Release()
{
	Scene::Release();
}
