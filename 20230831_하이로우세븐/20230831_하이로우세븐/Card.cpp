#include "main.h"
#include "Card.h"

void Card::Initialize(int num)
{
	_shape = num / 13;
	_num = num % 13 + 1;
}

void Card::Release()
{
	_shape = 0;
	_num = 0;
}

void Card::PrintCard()
{
	switch (_shape)
	{
	case eShape::SPADE:
		cout << "¢»";
		break;
	case eShape::DIAMOND:
		cout << "¡ß";
		break;
	case eShape::HEART:
		cout << "¢¾";
		break;
	case eShape::CLOVER:
		cout << "¢¿";
		break;
	default:
		break;
	}

	switch (_num)
	{
	case 1:
		cout << "A";
		break;
	case 11:
		cout << "J";
		break;
	case 12:
		cout << "Q";
		break;
	case 13:
		cout << "K";
		break;
	default:
		cout << _num;
		break;
	}
}

int Card::GetCardNum()
{
	return _num;
}
