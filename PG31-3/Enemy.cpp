#include "Enemy.h"
#include <stdio.h>
#include <Windows.h>

void (Enemy::* Enemy::stateTable[])() =
{
	&Enemy::Approach,
	&Enemy::Attack,
	&Enemy::Escape,
};

void Enemy::Initialize()
{
	printf("敵が現れた！！\n");
	state = EnemyState::APPROACH;
}

void Enemy::Update()
{
	(this->*stateTable[static_cast<size_t>(state)])();
}

void Enemy::Approach()
{
	printf("敵が接近して来た！\n");
	state = EnemyState::ATTACK;
}

void Enemy::Attack()
{
	printf("敵の攻撃！\n");
	state = EnemyState::ESCAPE;
}

void Enemy::Escape()
{
	printf("敵は逃げ出した...\n");
}
