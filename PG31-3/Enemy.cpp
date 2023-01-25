#include "Enemy.h"
#include <stdio.h>
#include <Windows.h>

// Ã“Iƒƒ“ƒo•Ï”‚ÌÀ‘Ô
bool Enemy::IsAlive = true;

void Enemy::Initialize()
{
	printf("“G‚ªŒ»‚ê‚½II\n");
}

void Enemy::Update()
{
	Defeat();
}

void Enemy::Draw()
{
	if (IsAlive)
	{
		printf("“G‚Í‚Ü‚¾€‚ñ‚Å‚¢‚È‚¢\n");
	}
	else
	{
		printf("“G‚Í€‚ñ‚Å‚¢‚é\n");
	}
}

void Enemy::Defeat()
{
	IsAlive = false;
	printf("“G‚ª€‚ñ‚¾\n");
}
