#pragma once
#include "Engine/GameObject.h"
#include <vector>
#include <string>


using std::string;

class HUD :
    public GameObject
{
	string ConstructEnemyNumberString();
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	HUD(GameObject* parent);
	int hHUD_;
	int hNumbers_;
	Transform tHud_;
	std::vector<Transform> tNumbers_;

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

};

