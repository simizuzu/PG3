#include "SceneManager.h"
#include "stdio.h"

void SceneManager::ChangeScene(int sceneNo)
{
	switch (scene)
	{
	case SceneManager::Scene::TitleScene:
		break;
	case SceneManager::Scene::NewGameScene:
		break;
	case SceneManager::Scene::GamePlayScene:
		break;
	case SceneManager::Scene::GameClearScene:
		break;
	default:
		break;
	}
}

SceneManager* SceneManager::GetInstance()
{
    static SceneManager instance;
    return &instance;
}
