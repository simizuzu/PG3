#include "Enemy.h"
#include <stdio.h>
#include <Windows.h>

// �ÓI�����o�ϐ��̎���
bool Enemy::IsAlive = true;

void Enemy::Initialize()
{
	printf("�G�����ꂽ�I�I\n");
}

void Enemy::Update()
{
	Defeat();
}

void Enemy::Draw()
{
	if (IsAlive)
	{
		printf("�G�͂܂�����ł��Ȃ�\n");
	}
	else
	{
		printf("�G�͎���ł���\n");
	}
}

void Enemy::Defeat()
{
	IsAlive = false;
	printf("�G������\n");
}
