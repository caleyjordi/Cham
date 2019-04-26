#pragma once
class Enemy
{
public:
	Enemy() {};
	~Enemy() {};
	void Update(const HandType a_Hand);
	void ChamRender();
	void Render(const HandType a_Hand);
	HandType RandomFace();
private:
	int Score = 0;
	HandType Face;
	bool Victory;
};

