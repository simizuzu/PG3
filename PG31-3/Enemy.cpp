#include "Enemy.h"
#include <stdio.h>
#include <Windows.h>

// 静的メンバ変数の実態
bool Enemy::IsAlive = true;

void Enemy::Initialize()
{
	printf("敵が現れた！！\n");
}

void Enemy::Update()
{
	Defeat();
}

void Enemy::Draw()
{
	if (IsAlive)
	{
		printf("敵はまだ死んでいない\n");
	}
	else
	{
		printf("敵は死んでいる\n");
	}
}

void Enemy::Defeat()
{
	IsAlive = false;
	printf("敵が死んだ\n");
}
