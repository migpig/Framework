#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std; //iostream�� �� �� �� using namespace std;�� �� ������Ѵ�.


typedef struct tagInfo
{
	int iNumber;

	tagInfo()
	{
		cout << "�⺻ ������" << endl;
	}

	tagInfo(int _iNumber) // int _iNumber �޾ƿ� ��
	{
		iNumber = _iNumber; // _iNumber �޾ƿ� ������ iNumber �� �ʱ�ȭ
		cout << "���� ������" << endl;
	}
}INFO;


int main(void)
{
	//** ���
	//printf_s("���� ���");
	//cout << "���� ���"; //�ڿ��ִ� �� ���ڿ��� c �ܼ�â���� out �������� cout
						 // << �� ����Ʈ ������ ���� ��Ʈ���� �� �� ���� ��� (������ �����ڸ� ��� �� �� ���� ���) ������ ������ �����ϰ� Ǯ�� �� �� ������ ��û ������ �ʴ�

	
						 
						 
						 
	//** �ٹٲ�
	//printf_s("\n�� ����ϸ�\n�ٹٲ�");
	//cout << "endl �� ����ϸ�" << endl << "�ٹٲ�"; // end ������ l ���� endl �ٹٲ�

	
	
	
	
	//** �Է�
	/*
	int iNumber = 0;

	
	//printf_s("�Է�: ");
	//scanf_s("%d", &iNumber);

	//printf_s("��� : %d",iNumber);
	
	cout << "�Է�: ";
	cin >> iNumber;

	cout << "���: " << iNumber;
	*/

	// ** �����Ҵ�
	//INFO* pInfo = (INFO*)malloc(sizeof(INFO));		//void �����ʹ� 4byte void�� ������ ������ ũ�⸦ ������ ������ ���¸� ������ ���� �ʰ� ������ �Ҵ� �� �� �ִ�//malloc()�� void*
													//(siceof(INFO))�� ����ü�ȿ� �� �ڷ����� ������ �����Ӱ� ��� �ϰ� ũ�⸦ �޾� �� �� �ֵ��� ���ش�
	INFO* pInfo = new INFO(10);				// c++���� malloc�� new�� �����ϴ� new�� ������
	cout << pInfo->iNumber << endl;									// pInfo �� new INFO�� �ʱ�ȭ �ϴ� �����Ϸ��� �˾Ƽ� ����ü �ȿ� �ִ� �����ڸ� ȣ������

	//free(pInfo);
	delete pInfo;



	return 0;
}
