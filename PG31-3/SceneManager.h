#pragma once
class SceneManager
{
public:
	/// <summary>
	/// �V�[����؂�ւ���֐�
	/// </summary>
	/// <param name="sceneNo">���̃V�[���ԍ�</param>
	void ChangeScene(int sceneNo);

	// �V���O���g��
	static SceneManager* GetInstance();

private:
	enum class Scene
	{
		TitleScene,
		NewGameScene,
		GamePlayScene,
		GameClearScene,
	};

	// �ŏ��̃V�[����ݒ�
	Scene scene = Scene::TitleScene;

private:
	SceneManager() = default;
	~SceneManager() = default;
	SceneManager(const SceneManager&) = delete;
	const SceneManager& operator = (const SceneManager&) = delete;
};

