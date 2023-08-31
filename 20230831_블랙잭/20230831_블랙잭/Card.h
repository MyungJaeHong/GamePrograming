#pragma once

enum eShape { SPADE, HEART, DIAMOND, CLOVER };

class Card
{
private:
	int _shape;
	int _num;
public:
	void Initialize(int num);
	void Release();
	void PrintCard();
	int GetCardNum();
};