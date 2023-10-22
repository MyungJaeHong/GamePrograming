#pragma once
#include <bitset>
using namespace std;
//STL (vector와 아주 유사)
// 훨씬빠른, 
#define KEYMAX 256
class KeyManager
{
	DECLARE_SINGLE(KeyManager)

private:
	bitset<KEYMAX> _keyDown = {};
	//256개의 배열을 생성해준다.
	//자료형은 모두 BIT
public:
	//키를 지금 눌렀는지?
	bool GetKeyDown(int vKey);
	//키가 눌려져 있는지?
	bool GetKey(int vKey);

	void Init();
	void Release();
};
