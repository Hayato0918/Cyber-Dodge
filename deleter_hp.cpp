//�f���[�^�[HP���� [deleter_hp.cpp]
#include "deleter_hp.h"
#include "texture.h"
#include "sprite.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
DELETERHP deleterhp;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitDeleterHp(void)
{
	deleterhp.gaugeonce = 8;

	deleterhp.framepos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 + 60.f, SCREEN_HEIGHT - 100.0f);
	deleterhp.framesize = D3DXVECTOR2(80.f * deleterhp.gaugeonce, 60.0f); //slimehp�o�[�t���[���T�C�Y
	deleterhp.frametexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpframe.png");

	deleterhp.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 + 60.f, SCREEN_HEIGHT - 100.0f);
	deleterhp.gaugesize = D3DXVECTOR2(deleterhp.framesize.x, deleterhp.framesize.y); //�c���Ă���slimehp�̗�
	deleterhp.gaugegreentexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpgreen.png");
	deleterhp.gaugeredtexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpred.png");

	deleterhp.hpsize = deleterhp.gaugesize.x;
	deleterhp.colorcangeflag = false;

	return S_OK;
}

//-----�I������
void UninitDeleterHp(void)
{

}

//-----�X�V����
void UpdateDeleterHp(void)
{
	if (deleterhp.gaugesize.x <= deleterhp.hpsize * 0.2f)
		deleterhp.colorcangeflag = true;
	if (deleterhp.gaugesize.x > deleterhp.hpsize * 0.2f)
		deleterhp.colorcangeflag = false;

	//HP����̐ݒ�
	if (deleterhp.gaugesize.x > 640.0f)
		deleterhp.gaugesize.x = 640.0f;
}

//-----�`�揈��
void DrawDeleterHp(void)
{
	//-----HP�Q�[�W�̕`��
	if (deleterhp.colorcangeflag == false)
		DrawSpriteLeftTop(deleterhp.gaugegreentexture, deleterhp.pos.x, deleterhp.pos.y,
			deleterhp.gaugesize.x, deleterhp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
	if (deleterhp.colorcangeflag == true)
		DrawSpriteLeftTop(deleterhp.gaugeredtexture, deleterhp.pos.x, deleterhp.pos.y,
			deleterhp.gaugesize.x, deleterhp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0f);

	//-----HP�Q�[�W�̘g�̕`��
	DrawSpriteLeftTop(deleterhp.frametexture, deleterhp.pos.x, deleterhp.pos.y,
		deleterhp.framesize.x, deleterhp.framesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----�\���̃|�C���^�擾����
DELETERHP* GetDeleterHp()
{
	return &deleterhp;
}