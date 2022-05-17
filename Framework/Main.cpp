#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;




struct Vector3 
{
	int x = 0, y = 0, z = 0;

	Vector3() {};							//기본 생성자 없이 복사 생성자를 만들수 없다.

	Vector3(int _x, int _y)
		: x(_x), y(_y), z(0) {};			//복사 생성자를 여러개 만들수도 있다. 매개변수 2개 여기서 z는 초기화 안해 줄 수 없으니 임의값

	Vector3(int _x, int _y, int _z)
		: x(_x), y(_y), z(_z) {};			//복사 생성자를 만들때 기본 생성자를 무조건 정의 해줘야한다. 매개변수 3개
	
	/* tagVector3(int _x, int _y, float _z) 매개변수의 형태에 따라서 호출되는 복사생성자가 달라짐
		: x(_x), y(_y), z(_z) {}; */
};											//vector3은 x 수평 y 수직 z 외적을했을때 생기는 하나의 선 3개의 원소로 이루어져있다.
											//3d = vector3 2d = vector2

struct Transnsform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
};

struct Object
{
	char* Name;
	int Speed;
	Transnsform TransInfo;
};

void Initialize(Object* _Object, char* _Name, int _PosX, int _PosY, int _PosZ);
char* SetName();
void Output(Object* _Object);


int main(void)
{
	//Object* Player = nullptr;
	Object* Player = new Object;
	Initialize(Player,nullptr,10,20,30);

	Object* Enemy = new Object;
	Initialize(Enemy,(char*)"Enemy",100,200,300);


	Output(Player);
	Output(Enemy);

	/*Vector3 vPosition = Vector3(10,20);		// 초기화 변수를 2개 호출하면 매개변수 2개짜리 복사생성자가 자동 호출 , 3개는 3개짜리가 자동호출
	
	cout << vPosition.x << ", " << vPosition.y << endl;*/



	return 0;
}


void Initialize(Object* _Object, char* _Name, int _PosX, int _PosY, int _PosZ)
{
	_Object->Name = (_Name == nullptr) ? SetName() : _Name;


	_Object->Speed = 0;

	_Object->TransInfo.Position = Vector3(_PosX, _PosY, _PosZ);
	_Object->TransInfo.Rotation = Vector3(0, 0, 0);
	_Object->TransInfo.Scale = Vector3(0, 0, 0);
}

char* SetName()
{
	char Buffer[128] = "";
	
	cout << "입력 : ";
	cin >> Buffer;
	//char* pName = (char*)malloc(strlen(Buffer) + 1);
	char* pName = new char[strlen(Buffer) + 1];

	strcpy(pName, Buffer);

	return nullptr;
}

void Output(Object* _Object)
{
	if (_Object->Name != nullptr)
		cout << "Name : " << _Object->Name << endl;

	cout << "Speed : " << _Object->Speed << endl;

	cout << "X : " << _Object->TransInfo.Position.x <<
		", Y : " << _Object->TransInfo.Position.y <<
		", Z : " << _Object->TransInfo.Position.z << endl;
}
