#pragma once

#define DECLARE_SINGLE(ClassName)		\
private:								\
	ClassName() {}						\
	~ClassName() {}						\
public:									\
	static ClassName* GetInstance()		\
	{									\
		static ClassName _instance;		\
		return &_instance;				\
	}


#define GET_SINGLE(ClassName)	ClassName::GetInstance()

#define DeltaTime	GET_SINGLE(TimeManager)->GetDeltaTime()

//부동소수점 오차
#define EPSILON 1e-6f // 0.000001
#define PI 3.14159265358979f //180도
#define Deg2Rad(deg) (0.0174533 * deg)
#define Rad2Deg(rad) (57.2958 * rad)

#define RandomHeight Random::GetInt(0, WIN_SIZE_HEIGHT)
#define RandomWidth Random::GetInt(0, WIN_SIZE_WIDTH)