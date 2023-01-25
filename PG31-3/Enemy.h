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
	// コンストラクタ・デストラクタ
	Enemy() = default;
	~Enemy() = default;

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 接近
	/// </summary>
	void Approach();

	/// <summary>
	/// 射撃
	/// </summary>
	void Attack();

	/// <summary>
	/// 離脱
	/// </summary>
	void Escape();

private:
	EnemyState state;

	static void(Enemy::* stateTable[])();
};

