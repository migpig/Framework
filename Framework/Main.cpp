#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
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
	char* Texture;
	int Speed;
	Transnsform TransInfo;
};

void Initialize(Object* _Object, char* _Name, int _PosX, int _PosY);
char* SetName();
void SetCursorPosition(int _x, int _y);
// ** �ؽ�Ʈ�� ���� ������.
void SetTextColor(int _Color);
// ** ����� Text�� ��ġ�� ������ �������ش�. [Color ���� �⺻�� : ���(15)]
void OnDrawText(char* _str, int _x, int _y, int _Color = 15);
// ** ����� ������ ��ġ�� ������ �������ش�. [Color ���� �⺻�� : ���(15)]
void OnDrawText(int _Value, int _x, int _y, int _Color = 15);
// ** Ŀ���� ���̰ų�(true)/�Ⱥ��̰�(false) �������.
void HideCursor(bool _Visible);


int main(void)
{
	HideCursor(false);
	//Object* Player = nullptr;
	Object* Player = new Object;
	Initialize(Player,nullptr,50,10);

	Object* Enemy = new Object;
	Initialize(Enemy,(char*)"Enemy",80,10);

	// ** ���� �ð����� �ʱ�ȭ.
	ULONGLONG Time = GetTickCount64();

	while (true)
	{

		// ** �Ҵ���� �ð����κ��� +50 ��ŭ �����ϸ�...
		// ** (�����Ӱ� ������ ������ �ð� ������ 0.5�ʷ� ����)
		if (Time + 50 < GetTickCount64())
		{
			// ** ������ ����ŭ �ٽ� �ʱ�ȭ.
			Time = GetTickCount64();

			//** �ܼ�â ���� ��ü ����
			system("cls");

			//**[��] Ű�� �Է¹���.
			if (GetAsyncKeyState(VK_UP))
				Player->TransInfo.Position.y -= 1;
			//**[��] Ű�� �Է¹���.
			if (GetAsyncKeyState(VK_DOWN))
				Player->TransInfo.Position.y += 1;
			//**[��] Ű�� �Է¹���.
			if (GetAsyncKeyState(VK_LEFT))
				Player->TransInfo.Position.x -= 1;
			//**[��] Ű�� �Է¹���.
			if (GetAsyncKeyState(VK_RIGHT))
				Player->TransInfo.Position.x += 1;
			//**[Space] Ű�� �Է¹���.
			if (GetAsyncKeyState(VK_SPACE))
			{
				OnDrawText((char*)"��ǳ!!",
				Player->TransInfo.Position.x + strlen(Player->Texture) + 1,
				Player->TransInfo.Position.y,
				13);
			}
				

			OnDrawText(Player->Texture,
				Player->TransInfo.Position.x,
				Player->TransInfo.Position.y,
				10);
			OnDrawText(Enemy->Texture,
				Enemy->TransInfo.Position.x,
				Enemy->TransInfo.Position.y,
				12);
			
			OnDrawText((char*)"Score : ", 60 - strlen("Score : "), 1);
			OnDrawText(++Score, 60, 1);
		}
		
	}
		
		
	//Output(Enemy);

	/*Vector3 vPosition = Vector3(10,20);		// �ʱ�ȭ ������ 2�� ȣ���ϸ� �Ű����� 2��¥�� ��������ڰ� �ڵ� ȣ�� , 3���� 3��¥���� �ڵ�ȣ��
	
	cout << vPosition.x << ", " << vPosition.y << endl;*/



	return 0;
}


void Initialize(Object* _Object, char* _Name, int _PosX, int _PosY, int _PosZ)
{
	_Object->Texture = (_Name == nullptr) ? SetName() : _Name;


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

	return pName;
}

void SetCursorPosition(int _x, int _y)
{
	COORD Pos = {(SHORT)_x,(SHORT)_y};

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void SetTextColor(int _Color)
{
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE), _Color);
}

void OnDrawText(char* _str, int _x, int _y, int _Color)
{
	SetCursorPosition(_x, _y);
	SetTextColor(_Color);
	cout << _str;
}

void OnDrawText(int _Value, int _x, int _y, int _Color)
{
	SetCursorPosition(_x, _y);
	SetTextColor(_Color);
	
	char* pText = new char[4];
	_itoa(_Value, pText, 10);
	cout << _Value;
}

void HideCursor(bool _Visible)
{
	CONSOLE_CURSOR_INFO CursorInfo;

	CursorInfo.bVisible = _Visible;
	CursorInfo.dwSize = 1;

	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);


}