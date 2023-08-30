#include "main.h"
#include "MainGame.h"

int main()
{
	//하이로우세븐
	//게임시작
	//플레이어 초기자본 : 1000골드
	//맨위에서 4장이 화면에 보여진다
	//마지막카드는 ??

	//현재 골드 : 1000
	//♤A ♧K ♧3 ♤2 ??
	//베팅 금액을 정해주세요. : 
	//베팅 유형을 골라주세요 ( 0: 하이, 1: 로우, 2: 세븐)
	//하이 => ?? 숫자가 7보다 크면 베팅금액 * 2
	//로우 => ?? 숫자가 7보다 작으면 베팅금액 * 2
	//세븐 => ?? 숫자가 7이면 베팅금액 * 10

	//◆4
	//로우! 플레이어 승리! 
	//현재 얼마!

	//현재 골드 : 1000
	//♧K ♧3 ♤2 ◆4 ??
	//베팅 금액을 정해주세요. : 
	//베팅 유형을 골라주세요 ( 0: 하이, 1: 로우, 2: 세븐)

	//플레이어 골드가 0원이거나, 52장을 다 소진했으면.. 게임끝.

	//[메인게임]
	// - 카드52장
	//		- 모양
	//		- 번호
	// - 플레이어
	//		- 골드
	// - 베팅골드
	// - 베팅유형
	srand(time(NULL));

	MainGame* mainGame = new MainGame();
	mainGame->Initialize();
	mainGame->CardShuffle();
	while (!mainGame->IsGameEnd())
	{
		mainGame->UpdateGame();
	}

	mainGame->Release();

	return 0;
}