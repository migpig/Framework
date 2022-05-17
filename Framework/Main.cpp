#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;




struct Vector3 
{
	int x = 0, y = 0, z = 0;

	Vector3() {};							//�⺻ ������ ���� ���� �����ڸ� ����� ����.

	Vector3(int _x, int _y)
		: x(_x), y(_y), z(0) {};			//���� �����ڸ� ������ ������� �ִ�. �Ű����� 2�� ���⼭ z�� �ʱ�ȭ ���� �� �� ������ ���ǰ�

	Vector3(int _x, int _y, int _z)
		: x(_x), y(_y), z(_z) {};			//���� �����ڸ� ���鶧 �⺻ �����ڸ� ������ ���� ������Ѵ�. �Ű����� 3��
	
	/* tagVector3(int _x, int _y, float _z) �Ű������� ���¿� ���� ȣ��Ǵ� ��������ڰ� �޶���
		: x(_x), y(_y), z(_z) {}; */
};											//vector3�� x ���� y ���� z ������������ ����� �ϳ��� �� 3���� ���ҷ� �̷�����ִ�.
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

	/*Vector3 vPosition = Vector3(10,20);		// �ʱ�ȭ ������ 2�� ȣ���ϸ� �Ű����� 2��¥�� ��������ڰ� �ڵ� ȣ�� , 3���� 3��¥���� �ڵ�ȣ��
	
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
	
	cout << "�Է� : ";
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
