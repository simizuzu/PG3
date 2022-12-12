#pragma once
class SceneManager
{
public:
	/// <summary>
	/// �V�[����؂�ւ���֐�
	/// </summary>
	/// <param name="sceneNo">���̃V�[���ԍ�</param>
	void ChangeScene(int& sceneNo);

	/// <summary>
	/// delete�����s
	/// </summary>
	void Delete();

	// �V���O���g��
	static SceneManager* GetInstance();

private:
	//// �ŏ��̃V�[����ݒ�
	//Scene scene = Scene::TitleScene;
	int number = 0;

private:
	SceneManager() = default;
	~SceneManager() = default;
	SceneManager(const SceneManager&) = delete;
	const SceneManager& operator = (const SceneManager&) = delete;
};

