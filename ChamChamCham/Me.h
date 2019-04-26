#pragma once
class Me
{
public:
	Me() = default;
	~Me() = default;
	HandType GetChar();
	HandType GetHand();
private:
	HandType Hand;
};

