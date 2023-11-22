#include "pch.h"
#include "Button.h"
#include "SelectGDI.h"

Button::Button() : m_text(L"Button")
{
}

Button::Button(wstring _text) : m_text(_text)
{
}

Button::~Button()
{
}

void Button::Update()
{
}

void Button::Render(HDC _dc)
{
	PEN_TYPE ePen = PEN_TYPE::RED;
	SelectGDI pen(_dc, ePen);
	SelectGDI brush(_dc, BRUSH_TYPE::HOLLOW);

	SetBkMode(_dc, TRANSPARENT);
	
	RECT rt = RECT_MAKE(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y);
	Rectangle(_dc, rt.left, rt.top, rt.right, rt.bottom);
	DrawText(_dc, m_text.c_str(), m_text.length(), &rt, DT_CENTER | DT_VCENTER);
	
	SetBkMode(_dc, OPAQUE);
}
