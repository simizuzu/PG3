#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<functional>

int main()
{
	//���[�U�̓���
	int answer;

	printf("�������Ǝv���Ȃ�0����́A����Ǝv���Ȃ�1����͂��Ă�������\n");

	scanf_s("%d", &answer);

	printf("���ʂ�.");


	std::function<void()> lottery = [answer]()
	{
		// �����_��������
		srand(time(NULL));
		// ���I
		rand() % 2 == answer ? printf("����!\n") : printf("�s����\n");
	};

	std::function<void(int, std::function<void()>)> SetTimeout = [](int second, std::function<void()> func)
	{
		// 1000�~���b�ҋ@
		Sleep(second * 1000);
		// �R�[���o�b�N�֐��Ăяo��
		func();
	};

	SetTimeout(3, lottery);

	return 0;
}