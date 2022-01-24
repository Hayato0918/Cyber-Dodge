//�X���C��HP���� [slime_hp.cpp]
#include "slime_hp.h"
#include "texture.h"
#include "sprite.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
SLIMEHP slimehp;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitSlimeHp(void)
{
	slimehp.gaugeonce = 8;

	slimehp.framepos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f + SCREEN_WIDTH * 0.0375f, SCREEN_HEIGHT - SCREEN_HEIGHT * 0.11111f);
	slimehp.framesize = D3DXVECTOR2(SCREEN_WIDTH * 0.05f * slimehp.gaugeonce, SCREEN_HEIGHT * 0.066666f); //slimehp�o�[�t���[���T�C�Y
	slimehp.frametexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpframe.png");

	slimehp.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f + SCREEN_WIDTH * 0.0375f, SCREEN_HEIGHT - SCREEN_HEIGHT * 0.11111f);
	slimehp.gaugesize = D3DXVECTOR2(slimehp.framesize.x, slimehp.framesize.y); //�c���Ă���slimehp�̗�
	slimehp.gaugegreentexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpgreen.png");
	slimehp.gaugeredtexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpred.png");

	slimehp.hpsize = slimehp.gaugesize.x;
	slimehp.colorcangeflag = false;

	return S_OK;
}

//-----�I������
void UninitSlimeHp(void)
{

}

//-----�X�V����
void UpdateSlimeHp(void)
{
	if (slimehp.gaugesize.x <= slimehp.hpsize * 0.2f)
		slimehp.colorcangeflag = true;
	if (slimehp.gaugesize.x > slimehp.hpsize * 0.2f)
		slimehp.colorcangeflag = false;

	//HP����̐ݒ�
	if (slimehp.gaugesize.x > SCREEN_WIDTH * 0.4f)
		slimehp.gaugesize.x = SCREEN_WIDTH * 0.4f;
}

//-----�`�揈��
void DrawSlimeHp(void)
{
	//-----HP�Q�[�W�̕`��
	if (slimehp.colorcangeflag == false)
		DrawSpriteLeftTop(slimehp.gaugegreentexture, slimehp.pos.x, slimehp.pos.y,
			slimehp.gaugesize.x, slimehp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
	if (slimehp.colorcangeflag == true)
		DrawSpriteLeftTop(slimehp.gaugeredtexture, slimehp.pos.x, slimehp.pos.y,
			slimehp.gaugesize.x, slimehp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0f);

	//-----HP�Q�[�W�̘g�̕`��
	DrawSpriteLeftTop(slimehp.frametexture, slimehp.pos.x, slimehp.pos.y,
			slimehp.framesize.x, slimehp.framesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----�\���̃|�C���^�擾����
SLIMEHP* GetSlimeHp()
{
	return &slimehp;
}