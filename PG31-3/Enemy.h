#pragma once
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
	/// �`��
	/// </summary>
	void Draw();

private:
	/// <summary>
	/// �G��|��
	/// </summary>
	void Defeat();

private:
	static bool IsAlive;
};

