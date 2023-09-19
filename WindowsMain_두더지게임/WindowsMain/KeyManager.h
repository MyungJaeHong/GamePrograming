#pragma once
#include <bitset>
using namespace std;
//STL (vector�� ���� ����)
// �ξ�����, 
#define KEYMAX 256
class KeyManager
{
private:
	bitset<KEYMAX> _keyDown;
	//256���� �迭�� �������ش�.
	//�ڷ����� ��� BIT
public:
	//Ű�� ���� ��������?
	bool GetKeyDown(int vKey);
	//Ű�� ������ �ִ���?
	bool GetKey(int vKey);


	//�̱��� ���ó���
private:
	static KeyManager* _instance;
	KeyManager() {}
	~KeyManager() {}

	void Init();
	void Release();
public:
	static KeyManager* GetInstance()
	{
		if (_instance == nullptr)
		{
			_instance = new KeyManager();
		}

		return _instance;
	}
};


#define KEYMANAGER KeyManager::GetInstance()