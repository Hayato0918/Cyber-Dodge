//�o�i�[�o�O�Q�[�W���� [banner_bug.cpp]
#include "banner_bug.h"
//�V�X�e��.h
#include "texture.h"
#include "sprite.h"

#include "bugincrease.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
BANNER_BUGFRAME banner_bugframe;
BANNER_BUGGAUGE banner_buggauge;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBannerBug(void)
{
	BUG* bug = GetBugIncrease();
	banner_bugframe.size = D3DXVECTOR2(600.0f, 60.0f);
	banner_bugframe.pos = D3DXVECTOR2(1000.f, 0.0f);
	banner_bugframe.texture = LoadTexture("data/TEXTURE/bugframe.png");
	banner_buggauge.size = D3DXVECTOR2(bug->gaugesize.x * 0.5f, 60.0f);
	banner_buggauge.pos = D3DXVECTOR2(1100.f, 0.0f);
	banner_buggauge.texture = LoadTexture("data/TEXTURE/obstacle.png");

	return S_OK;
}

//-----�I������
void UninitBannerBug(void)
{

}

//-----�X�V����
void UpdateBannerBug(void)
{

}

//-----�`�揈��
void DrawBannerBug(void)
{
	//�o�i�[�o�O�Q�[�W
	DrawSpriteLeftTop(banner_buggauge.texture, banner_buggauge.pos.x, banner_buggauge.pos.y, banner_buggauge.size.x, banner_buggauge.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);
	//�o�i�[�o�O�Q�[�W�t���[��
	DrawSpriteLeftTop(banner_bugframe.texture, banner_bugframe.pos.x, banner_bugframe.pos.y, banner_bugframe.size.x, banner_bugframe.size.y,
			0.0f, 0.0f, 1.0f, 1.0f);
}