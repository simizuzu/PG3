#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <functional>

// コールバック関数を呼び出す
void SetTimeout(int answer, int second, std::function<void(int)> p)
{
	printf("結果は...\n");
	Sleep(second * 1000);
	p(answer);
}

int main()
{
	int answer;
	printf("正解を0か1で入力してください : ");
	scanf_s("%d", &answer);

	SetTimeout(answer, 3, [](int answer) 
		{
			srand(time(nullptr));

			int randNum = rand() % 10;

			if (randNum == answer % 2)
			{
				printf("%dで不正解！", randNum); // 奇数の場合
			}
			else
			{
				printf("%dで正解！", randNum); // 偶数の場合
			}
		});

	return 0;
}
