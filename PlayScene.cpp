#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
#include "Enemy.h"
#include "Engine/Text.h"
#include "Engine/Camera.h"
#include "HUD.h"
#include "Engine/SceneManager.h"

namespace {
	const int ENEMY_NUM(30);
}

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene"),pText(nullptr)
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	enemyNum = ENEMY_NUM;
	for (int i = 0; i < enemyNum; i++) {
		Instantiate<Enemy>(this);
	}
	pText = new Text;
	pText->Initialize();

	Instantiate<HUD>(this);
	player = Instantiate<TANK>(this);
}

void PlayScene::Update()
{
	if (enemyNum == 0) {
		SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
		pSM->ChangeScene(SCENE_ID_GAMEOVER);
	}

	Camera::SetTarget(player->GetPosition());
	XMFLOAT3 camPos = player->GetPosition();
	camPos.y += 8;
	camPos.z -= 15;
	Camera::SetPosition(camPos);
}

void PlayScene::Draw()
{
	pText->Draw(30, 30, "Yahoo!");
}

void PlayScene::Release()
{
}
