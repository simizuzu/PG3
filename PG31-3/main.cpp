#include <stdio.h>
#include <windows.h>
#include <time.h>

typedef void (*PFunc)(int*);

// �R�[���o�b�N�֐�
void RandResult(int* answer)
{
	srand(time(NULL));

	int randNum = rand() % 10;

	if (randNum == *answer % 2)
	{
		printf("%d�ŕs�����I", randNum); // ��̏ꍇ
	}
	else
	{
		printf("%d�Ő����I", randNum); // �����̏ꍇ
	}
}

// �R�[���o�b�N�֐����Ăяo��
void SetTimeout(PFunc p, int answer, int second)
{
	Sleep(second * 1000);
	p(&answer);
}

int main()
{
	int answer;
	printf("������0��1�œ��͂��Ă�������\n");
	scanf_s("%d", &answer);

	PFunc p = RandResult;
	SetTimeout(p, answer, 3);

	return 0;
}