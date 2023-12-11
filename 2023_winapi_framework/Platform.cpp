#include "pch.h"
#include "Platform.h"

Platform::Platform()
{
}

Platform::~Platform()
{
}

bool Platform::Init(HWND _hWnd, HDC _dc)
{
	return false;
}

void Platform::Destroy()
{
}

void Platform::InitMap(int _map[32][18])
{
}

void Platform::Input(float _dt)
{
}

void Platform::Update(float _dt)
{
}

void Platform::Render(HDC _dc, float _dt) const
{
}
