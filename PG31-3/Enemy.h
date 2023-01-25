#pragma once
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
	/// 描画
	/// </summary>
	void Draw();

private:
	/// <summary>
	/// 敵を倒す
	/// </summary>
	void Defeat();

private:
	static bool IsAlive;
};

