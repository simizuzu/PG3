#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <functional>

// �R�[���o�b�N�֐����Ăяo��
void SetTimeout(int answer, int second, std::function<void(int)> p)
{
	printf("���ʂ�...\n");
	Sleep(second * 1000);
	p(answer);
}

int main()
{
	int answer;
	printf("������0��1�œ��͂��Ă������� : ");
	scanf_s("%d", &answer);

	SetTimeout(answer, 3, [](int answer) 
		{
			srand(time(nullptr));

			int randNum = rand() % 10;

			if (randNum == answer % 2)
			{
				printf("%d�ŕs�����I", randNum); // ��̏ꍇ
			}
			else
			{
				printf("%d�Ő����I", randNum); // �����̏ꍇ
			}
		});

	return 0;
}
