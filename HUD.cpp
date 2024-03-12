#include "HUD.h"
#include "Engine/Image.h"
#include "PlayScene.h"

string HUD::ConstructEnemyNumberString()
{
	int enemys = ((PlayScene*)GetParent())->GetEnemyNum();
	string enemyNumStr = std::to_string(enemys);
	return enemyNumStr;
}

HUD::HUD(GameObject* parent)
	:GameObject(parent,"HUD"),hHUD_(-1),hNumbers_(-1)
{
}

void HUD::Initialize()
{
	hHUD_ = Image::Load("hud02.png");
	assert(hHUD_ >= 0);

	hNumbers_ = Image::Load("numbers2.png");
	assert(hHUD_ >= 0);
}

void HUD::Update()
{
	tHud_.scale_ = { 0.5,0.5,1.0 };
	tHud_.position_ = { -0.6,0.85,0 };
}


PlayScene* DescEnemy;
void HUD::Draw()
{
	Image::SetTransform(hHUD_, tHud_);
	Image::Draw(hHUD_);

	Transform trans;
	trans.scale_ = { 0.5,0.5,1.0 };
	trans.position_ = { -0.6,0.855,0 };

	Image::SetRect(hNumbers_, 51.2 * 4, 0, 51.2, 99);
	Image::SetTransform(hNumbers_, trans);
	Image::Draw(hNumbers_);

	trans.position_ = { -0.57, 0.855, 0 };
	Image::SetRect(hNumbers_, 51.2 * 6, 0, 51.2, 99);
	Image::SetTransform(hNumbers_, trans);
	Image::Draw(hNumbers_);

}

void HUD::Release()
{
}
