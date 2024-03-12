#include "GameOver.h"
#include "Engine/Image.h"

GameOver::GameOver(GameObject* parent)
	:GameObject(parent,"GameOver"),hPict_(-1)
{
}

void GameOver::Initialize()
{
	hPict_ = Image::Load("kuria.png");
	assert(hPict_ >= 0);
}

void GameOver::Update()
{
}

void GameOver::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void GameOver::Release()
{
}
