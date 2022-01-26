//�o�i�[���� [banner.cpp]
#include "banner.h"
//�V�X�e��.h
#include "texture.h"
#include "sprite.h"

#include "banner_bg.h"
#include "banner_name.h"
#include "banner_hp.h"
#include "banner_gold.h"
#include "banner_bug.h"
#include "banner_score.h"

#include "map_point.h"
#include "bugincrease.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBanner(void)
{
	//BG
	InitBannerBG();
	//name
	InitBannerName();
	//hp
	InitBannerHp();
	//gold
	InitBannerGold();
	//bug
	InitBannerBug();
	//score
	InitBannerScore();

	return S_OK;
}

//-----�I������
void UninitBanner(void)
{
	//BG
	UninitBannerBG();
	//name
	UninitBannerName();
	//hp
	UninitBannerHp();
	//gold
	UninitBannerGold();
	//bug
	UninitBannerBug();
	//score
	UninitBannerScore();
}

//-----�X�V����
void UpdateBanner(void)
{
	//BG
	UpdateBannerBG();
	//name
	UpdateBannerName();
	//hp
	UpdateBannerHp();
	//gold
	UpdateBannerGold();
	//bug
	UpdateBannerBug();
	//score
	UpdateBannerScore();
}

//-----�`�揈��
void DrawBanner(void)
{
	//BG
	DrawBannerBG();
	//name
	DrawBannerName();
	//hp
	DrawBannerHp();
	//gold
	DrawBannerGold();
	//bug
	DrawBannerBug();
	//score
	DrawBannerScore();
}