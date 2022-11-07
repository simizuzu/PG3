#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<functional>

int main()
{
	//ユーザの答え
	int answer;

	printf("偶数だと思うなら0を入力、奇数だと思うなら1を入力してください\n");

	scanf_s("%d", &answer);

	printf("結果は.");


	std::function<void()> lottery = [answer]()
	{
		// ランダム初期化
		srand(time(NULL));
		// 抽選
		rand() % 2 == answer ? printf("正解!\n") : printf("不正解\n");
	};

	std::function<void(int, std::function<void()>)> SetTimeout = [](int second, std::function<void()> func)
	{
		// 1000ミリ秒待機
		Sleep(second * 1000);
		// コールバック関数呼び出し
		func();
	};

	SetTimeout(3, lottery);

	return 0;
}