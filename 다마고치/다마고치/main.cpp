#include "stdafx.h"
#include "MainGame.h"

int main()
{
	//�ٸ���ġ ���� �����
	//[��ȹ]
	//�ٸ���ġ ���� Ű��� (������ �ٸ���ġ ����)
	//0�ܰ���� 7�ܰ���� �ִ�. (��~������ȭ����)
	//�ܰ躰�� ��ȭ�ÿ��� Ư�� ������ �ִ�.
	//
	//���� ���� ����
	// �����
	// �Ƿε�
	// HP
	// - ������� 0�̵Ǹ� ���������� HP�� �����ϸ� HP�� 0�̵� �� ���Ͱ� ����
	// - UI ����
	//		����� ǥ��
	//		HP ǥ��
	//		���� ��� �ð� ǥ��
	//		�÷��̾� �ൿ ����
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