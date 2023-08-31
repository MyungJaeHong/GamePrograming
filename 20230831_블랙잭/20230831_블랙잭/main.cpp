#include "main.h"
#include "MainGame.h"

int main()
{
	srand(time(NULL));

	MainGame* mainGame = new MainGame();
	mainGame->Initialize();
	mainGame->ShuffleCard();
	mainGame->InitDrawCard();
	while (!mainGame->IsGameEnd())
	{
		switch (mainGame->GetGameStage())
		{
		case eGameStage::GAMESTAGE_BETTINGSTAGE:
			mainGame->BetGold();
			break;
		case eGameStage::GAMESTAGE_PLAYINGSTAGE:
			mainGame->UpdateGame();
			break;
		case eGameStage::GAMESTAGE_CARDRESET:
			mainGame->ResetCard();
			break;
		default:
			break;
		}
	}

	mainGame->Release();

	return 0;
}

/*
다음 숙제 : 블랙잭
```
목표: 핸드의 카드 합계가 21에 가깝게 만들되, 21을 넘지 않는 것입니다. 가장 가까운 플레이어가 이기게 됩니다.

카드 값:
숫자 카드(2~10): 그대로의 숫자값을 갖습니다.
페이스 카드(J, Q, K): 각각 10의 값을 갖습니다.
에이스(A): 1 또는 11로 계산할 수 있습니다. 플레이어나 딜러의 핸드에 따라 자동으로 가장 유리한 방향으로 계산됩니다. 즉, 21을 넘지 않을 경우 11로, 넘을 경우 1로 계산합니다.

게임 진행:
처음에 플레이어와 딜러는 각각 두 장의 카드를 받습니다. 플레이어의 카드는 두 장 모두 앞면이 위로 향하도록 합니다. 딜러의 카드 중 한 장은 앞면이 위로, 다른 한 장은 뒷면이 위로 합니다.
플레이어는 '히트(Hit)' 또는 '스탠드(Stand)'를 선택할 수 있습니다. 히트는 추가 카드를 받는 것을 의미하고, 스탠드는 더 이상 카드를 받지 않겠다는 것을 의미합니다.
플레이어의 핸드 합계가 21을 넘으면 "버스트(Bust)"되어 바로 패배합니다.
플레이어가 스탠드를 선택하면, 딜러는 숨겨진 카드를 공개하고, 핸드의 합계가 17 또는 그 이상이 될 때까지 계속 히트합니다.


결과 판정:
딜러가 버스트하면 플레이어가 승리합니다.
둘 다 버스트하지 않은 경우, 21에 더 가까운 쪽이 승리합니다.
둘 다 같은 점수일 경우 비긴 것으로 처리됩니다.
```
*/