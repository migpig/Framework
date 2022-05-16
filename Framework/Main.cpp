#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std; //iostream을 쓸 때 는 using namespace std;를 꼭 써줘야한다.


typedef struct tagInfo
{
	int iNumber;

	tagInfo()
	{
		cout << "기본 생성자" << endl;
	}

	tagInfo(int _iNumber) // int _iNumber 받아온 값
	{
		iNumber = _iNumber; // _iNumber 받아온 값으로 iNumber 를 초기화
		cout << "복사 생성자" << endl;
	}
}INFO;


int main(void)
{
	//** 출력
	//printf_s("문자 출력");
	//cout << "문자 출력"; //뒤에있는 이 문자열을 c 콘솔창으로 out 내보내라 cout
						 // << 는 쉬프트 연산자 보통 비트연산 할 때 많이 사용 (복잡한 연산자를 사용 할 때 많이 사용) 복잡한 연산을 수월하게 풀어 줄 수 있지만 엄청 빠르진 않다

	
						 
						 
						 
	//** 줄바꿈
	//printf_s("\n을 사용하면\n줄바꿈");
	//cout << "endl 을 사용하면" << endl << "줄바꿈"; // end 마지막 l 라인 endl 줄바꿈

	
	
	
	
	//** 입력
	/*
	int iNumber = 0;

	
	//printf_s("입력: ");
	//scanf_s("%d", &iNumber);

	//printf_s("출력 : %d",iNumber);
	
	cout << "입력: ";
	cin >> iNumber;

	cout << "출력: " << iNumber;
	*/

	// ** 동적할당
	//INFO* pInfo = (INFO*)malloc(sizeof(INFO));		//void 포인터는 4byte void는 데이터 공간의 크기를 가지고 있지만 형태를 가지고 있지 않고 뭐든지 할당 할 수 있다//malloc()은 void*
													//(siceof(INFO))는 구조체안에 들어갈 자료형의 갯수를 자유롭게 사용 하고 크기를 받아 올 수 있도록 해준다
	INFO* pInfo = new INFO(10);				// c++에서 malloc은 new로 가능하다 new는 생성자
	cout << pInfo->iNumber << endl;									// pInfo 를 new INFO로 초기화 하니 컴파일러가 알아서 구조체 안에 있는 생성자를 호출해줌

	//free(pInfo);
	delete pInfo;



	return 0;
}
