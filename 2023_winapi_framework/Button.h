#pragma once
#include "Object.h"
class Button : public Object
{
public:
	Button();
	Button(wstring _text);
	~Button();
	
	void Update() override;
	void Render(HDC _dc) override;

	const wstring GetText() const { return m_text; }
	void SetText(wstring _str) { m_text = _str; }

private:
	wstring m_text;
};

