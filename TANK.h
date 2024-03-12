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
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TANK(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

