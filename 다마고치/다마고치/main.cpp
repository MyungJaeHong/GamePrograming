#include "stdafx.h"
#include "MainGame.h"

int main()
{
	//다마고치 게임 만들기
	//[기획]
	//다마고치 몬스터 키우기 (디지몬 다마고치 참고)
	//0단계부터 7단계까지 있다. (알~최종진화까지)
	//단계별로 진화시에는 특정 조건이 있다.
	//
	//몬스터 상태 관련
	// 배고픔
	// 피로도
	// HP
	// - 배고픔이 0이되면 지속적으로 HP가 감소하며 HP가 0이될 시 몬스터가 죽음
	// - UI 종류
	//		배고픔 표시
	//		HP 표시
	//		게임 경과 시간 표시
	//		플레이어 행동 관련
	//
	//

	vector<MainGame*> maingame;
	maingame.push_back(new MainGame());

	maingame[0]->Initialize();
	
	while (maingame[0]->IsGamePlaying())
	{
		maingame[0]->RunningGame();
	}

	//MainGame maingame = new MainGame();
	//maingame->Initialize();

	return 0;
}