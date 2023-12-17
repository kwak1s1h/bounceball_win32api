#pragma once
class GameMgr
{
	SINGLE(GameMgr);
public:
	void Init();
	const int* GetStarCount() const
	{
		return m_starCount;
	}
	bool GetBtnActive()
	{
		return isActiveBtn;
	}
	void SetStarCount(int value)
	{
		*m_starCount = value;
	}
	void DiscountStar() {
		m_starCount -= 1;
		CheckStar();
	}
	void CheckStar() {
		if (GetStarCount() == 0) {
			*isNoStar = true;
		}
	}
	void ActivateBtnBlock() {
		isActiveBtn = !isActiveBtn;
	}
public:
	int* m_starCount = 0;
	bool isActiveBtn;
	bool* isNoStar;
};

