#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
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
	char* Texture;
	int Speed;
	Transnsform TransInfo;
};

void Initialize(Object* _Object, char* _Name, int _PosX, int _PosY);
char* SetName();
void SetCursorPosition(int _x, int _y);
// ** 텍스트의 색을 변경함.
void SetTextColor(int _Color);
// ** 출력할 Text의 위치와 색상을 변경해준다. [Color 값은 기본값 : 흰색(15)]
void OnDrawText(char* _str, int _x, int _y, int _Color = 15);
// ** 출력할 숫자의 위치와 색상을 변경해준다. [Color 값은 기본값 : 흰색(15)]
void OnDrawText(int _Value, int _x, int _y, int _Color = 15);
// ** 커서를 보이거나(true)/안보이게(false) 만들어줌.
void HideCursor(bool _Visible);


int main(void)
{
	HideCursor(false);
	//Object* Player = nullptr;
	Object* Player = new Object;
	Initialize(Player,nullptr,50,10);

	Object* Enemy = new Object;
	Initialize(Enemy,(char*)"Enemy",80,10);

	// ** 현재 시간으로 초기화.
	ULONGLONG Time = GetTickCount64();

	while (true)
	{

		// ** 할당받은 시간으로부터 +50 만큼 증가하면...
		// ** (프레임과 프레임 사이의 시간 간격을 0.5초로 셋팅)
		if (Time + 50 < GetTickCount64())
		{
			// ** 증가된 값만큼 다시 초기화.
			Time = GetTickCount64();

			//** 콘솔창 버퍼 전체 삭제
			system("cls");

			//**[상] 키를 입력받음.
			if (GetAsyncKeyState(VK_UP))
				Player->TransInfo.Position.y -= 1;
			//**[하] 키를 입력받음.
			if (GetAsyncKeyState(VK_DOWN))
				Player->TransInfo.Position.y += 1;
			//**[좌] 키를 입력받음.
			if (GetAsyncKeyState(VK_LEFT))
				Player->TransInfo.Position.x -= 1;
			//**[우] 키를 입력받음.
			if (GetAsyncKeyState(VK_RIGHT))
				Player->TransInfo.Position.x += 1;
			//**[Space] 키를 입력받음.
			if (GetAsyncKeyState(VK_SPACE))
			{
				OnDrawText((char*)"장풍!!",
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

	/*Vector3 vPosition = Vector3(10,20);		// 초기화 변수를 2개 호출하면 매개변수 2개짜리 복사생성자가 자동 호출 , 3개는 3개짜리가 자동호출
	
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
	
	cout << "입력 : ";
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