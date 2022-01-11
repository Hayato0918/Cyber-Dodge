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

	slimehp.framepos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 + 60.f, SCREEN_HEIGHT - 100.0f);
	slimehp.framesize = D3DXVECTOR2(80.f * slimehp.gaugeonce, 60.0f); //slimehp�o�[�t���[���T�C�Y
	slimehp.frametexture = LoadTexture("data/TEXTURE/bugframe.png");

	slimehp.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 + 60.f, SCREEN_HEIGHT - 100.0f);
	slimehp.gaugesize = D3DXVECTOR2(slimehp.framesize.x, slimehp.framesize.y); //�c���Ă���slimehp�̗�
	slimehp.gaugegreentexture = LoadTexture("data/TEXTURE/hp_green.png");
	slimehp.gaugeredtexture = LoadTexture("data/TEXTURE/obstacle.png");

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
	if (slimehp.gaugesize.x > 640.0f)
		slimehp.gaugesize.x = 640.0f;
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