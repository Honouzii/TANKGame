#pragma once
#include "Engine/GameObject.h"
#include "PlayScene.h"
class Bullet :
    public GameObject
{
	int hModel_; //弾丸のモデル番号を収めておくやつ
	float bulletSpeed_; //弾丸の速さ
	XMFLOAT3 moveDir_; //向きのベクトル
	PlayScene* playScene_;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Bullet(GameObject* parent);
	~Bullet();
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void SetMoveDir(XMFLOAT3 _move) { moveDir_ = _move; }
	void SetSpeed(float _speed) { bulletSpeed_ = _speed; }
	void OnCollision(GameObject* pTarget) override;
};

