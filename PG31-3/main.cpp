#include <stdio.h>
#include <windows.h>
#include <time.h>

typedef void (*PFunc)(int*);

// コールバック関数
void RandResult(int* answer)
{
	srand(time(NULL));

	int randNum = rand() % 10;

	if (randNum == *answer % 2)
	{
		printf("%dで不正解！", randNum); // 奇数の場合
	}
	else
	{
		printf("%dで正解！", randNum); // 偶数の場合
	}
}

// コールバック関数を呼び出す
void SetTimeout(PFunc p, int answer, int second)
{
	Sleep(second * 1000);
	p(&answer);
}

int main()
{
	int answer;
	printf("正解を0か1で入力してください\n");
	scanf_s("%d", &answer);

	PFunc p = RandResult;
	SetTimeout(p, answer, 3);

	return 0;
}