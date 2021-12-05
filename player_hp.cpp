//�v���C���[HP���� [player_hp.h]
#include "player_hp.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
PLAYERHP hp;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitPlayerHp(void)
{
	hp.gaugeonce = 8;

	hp.framepos = D3DXVECTOR2(100.0f, SCREEN_HEIGHT - 100.0f);
	hp.framesize = D3DXVECTOR2(80.f * hp.gaugeonce, 60.0f); //HP�o�[�t���[���T�C�Y
	hp.frametexture = LoadTexture("data/TEXTURE/bugframe.png");

	hp.pos = D3DXVECTOR2(100.0f, SCREEN_HEIGHT - 100.0f);
	hp.gaugesize = D3DXVECTOR2(hp.framesize.x, hp.framesize.y); //�c���Ă���HP�̗�
	hp.gaugeredtexture = LoadTexture("data/TEXTURE/obstacle.png");
	hp.gaugegreentexture = LoadTexture("data/TEXTURE/hp_green.png");

	hp.hpsize = hp.gaugesize.x;
	hp.colorcangeflag = false;

	return S_OK;
}

//-----�I������
void UninitPlayerHp(void)
{

}

//-----�X�V����
void UpdatePlayerHp(void)
{
	if (hp.gaugesize.x <= hp.hpsize * 0.2f)
		hp.colorcangeflag = true;
	if (hp.gaugesize.x > hp.hpsize * 0.2f)
		hp.colorcangeflag = false;

}

//-----�`�揈��
void DrawPlayerHp(void)
{
	//-----HP�Q�[�W�̕`��
	if (hp.colorcangeflag == false)	//HP��2���ȏゾ������
		DrawSpriteLeftTop(hp.gaugegreentexture, hp.pos.x, hp.pos.y, hp.gaugesize.x, hp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0);
	if(hp.colorcangeflag == true)	//HP��2����؂�����
	DrawSpriteLeftTop(hp.gaugeredtexture, hp.pos.x, hp.pos.y, hp.gaugesize.x, hp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0);

	//-----HP�Q�[�W�̘g�̕`��
	DrawSpriteLeftTop(hp.frametexture, hp.framepos.x, hp.framepos.y, hp.framesize.x, hp.framesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----�\���̃|�C���^�擾����
PLAYERHP* GetPlayerHp()
{
	return &hp;
}