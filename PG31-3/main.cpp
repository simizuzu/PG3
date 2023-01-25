#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <vector>

#include "Enemy.h"

int main()
{
	std::vector<std::unique_ptr<Enemy>> enemys;

	int enemyNum = 2;

	printf("敵の数は%d体\n", enemyNum);
	printf("\n");

	// 敵の生成
	for (int i = 0; i < enemyNum; i++)
	{
		std::unique_ptr<Enemy> enemy;
		enemy = std::make_unique<Enemy>();
		enemy->Initialize();

		enemys.push_back(std::move(enemy));
	}
	
	printf("\n");

	// 敵の状態
	for (std::unique_ptr<Enemy>& enemy : enemys)
	{
		enemy->Update();
	}

	printf("\n");

	// 敵の状態
	for (std::unique_ptr<Enemy>& enemy : enemys)
	{
		enemy->Update();
	}

	printf("\n");

	// 敵の状態
	for (std::unique_ptr<Enemy>& enemy : enemys)
	{
		enemy->Update();
	}

	printf("\n");

	enemys.clear();
	system("pause");

	return 0;
}