#pragma once
#include "Engine/GameObject.h"
class TANK :
    public GameObject
{
	int hModel_;
	XMVECTOR front_;
	float Speed_;
	int camState_;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TANK(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

