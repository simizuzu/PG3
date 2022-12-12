#include "SceneManager.h"
#include "DxLib.h"

// �ŐV�̃L�[�{�[�h���p
char keys[256] = { 0 };

// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
char oldkeys[256] = { 0 };

void SceneManager::ChangeScene(int& sceneNo)
{
	// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
	for (int i = 0; i < 256; ++i)
	{
		oldkeys[i] = keys[i];
	}

	GetHitKeyStateAll(keys);

	switch (sceneNo)
	{
	case 0: // TitleScene
		DrawBox(0, 0, 600, 400, GetColor(222, 56, 56), true);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			// ���̃V�[����
			sceneNo = 1;
		}
		break;

	case 1: // NewGameScene
		DrawBox(0, 0, 600, 400, GetColor(95, 75, 139), true);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			// ���̃V�[����
			sceneNo = 2;
		}
		break;

	case 2: // GamePlayScene
		DrawBox(0, 0, 600, 400, GetColor(169, 183, 53), true);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			// ���̃V�[����
			sceneNo = 3;
		}
		break;

	case 3: // GameClearScene
		DrawBox(0, 0, 600, 400, GetColor(76, 108, 179), true);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			// �ŏ��̃V�[����
			sceneNo = 0;
		}
		break;
	}

	int Cr = GetColor(255, 255, 255);
	DrawFormatString(50, 50, Cr, _T("SceneNo: %d"), sceneNo);
	DrawFormatString(50, 70, Cr, _T("Press Space to Scene Change"));
}

SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;
	return &instance;
}
