#pragma once

#include "Object.h"

class Platform : public Object
{
public:
	Platform();
	~Platform();
public:
	bool Init(HWND _hWnd, HDC _dc);
	void Destroy();
	void InitMap(int _map[32][18]);
	void Input(float _dt);
	void Update(float _dt);
	void Render(HDC _dc, float _dt) const;
public:
	static const int m_iMapW = 32;
	static const int m_iMapH = 18;
	int m_iMapSet[m_iMapH][m_iMapW];

	static const int m_iTileH = 60;
	static const int m_iTileW = 60;
};

