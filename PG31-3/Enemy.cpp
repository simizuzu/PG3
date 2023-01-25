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
	printf("�G�����ꂽ�I�I\n");
	state = EnemyState::APPROACH;
}

void Enemy::Update()
{
	(this->*stateTable[static_cast<size_t>(state)])();
}

void Enemy::Approach()
{
	printf("�G���ڋ߂��ė����I\n");
	state = EnemyState::ATTACK;
}

void Enemy::Attack()
{
	printf("�G�̍U���I\n");
	state = EnemyState::ESCAPE;
}

void Enemy::Escape()
{
	printf("�G�͓����o����...\n");
}
