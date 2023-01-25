#pragma once

enum class EnemyState
{
	APPROACH,
	ATTACK,
	ESCAPE,
	STATEMAX
};

class Enemy
{
public:
	// �R���X�g���N�^�E�f�X�g���N�^
	Enemy() = default;
	~Enemy() = default;

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �ڋ�
	/// </summary>
	void Approach();

	/// <summary>
	/// �ˌ�
	/// </summary>
	void Attack();

	/// <summary>
	/// ���E
	/// </summary>
	void Escape();

private:
	EnemyState state;

	static void(Enemy::* stateTable[])();
};

