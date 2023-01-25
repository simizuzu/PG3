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
	printf("“G‚ªŒ»‚ê‚½II\n");
	state = EnemyState::APPROACH;
}

void Enemy::Update()
{
	(this->*stateTable[static_cast<size_t>(state)])();
}

void Enemy::Approach()
{
	printf("“G‚ªÚ‹ß‚µ‚Ä—ˆ‚½I\n");
	state = EnemyState::ATTACK;
}

void Enemy::Attack()
{
	printf("“G‚ÌUŒ‚I\n");
	state = EnemyState::ESCAPE;
}

void Enemy::Escape()
{
	printf("“G‚Í“¦‚°o‚µ‚½...\n");
}
