//�t�@�C�A�[�E�H�[��HP���� [firewall_hp.cpp]
#include "firewall_hp.h"
#include "texture.h"
#include "sprite.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
FIREWALLHP firewallhp;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitFireWallHp(void)
{
	firewallhp.gaugeonce = 8;

	firewallhp.framepos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f + SCREEN_WIDTH * 0.0375f, SCREEN_HEIGHT - SCREEN_HEIGHT * 0.11111f);
	firewallhp.framesize = D3DXVECTOR2(SCREEN_WIDTH * 0.05f * firewallhp.gaugeonce, SCREEN_HEIGHT * 0.066666f); //slimehp�o�[�t���[���T�C�Y
	firewallhp.frametexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpframe.png");

	firewallhp.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f + SCREEN_WIDTH * 0.0375f, SCREEN_HEIGHT - SCREEN_HEIGHT * 0.11111f);
	firewallhp.gaugesize = D3DXVECTOR2(firewallhp.framesize.x, firewallhp.framesize.y); //�c���Ă���firewallhp�̗�
	firewallhp.gaugegreentexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpgreen.png");
	firewallhp.gaugeredtexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpred.png");

	firewallhp.hpsize = firewallhp.gaugesize.x;
	firewallhp.colorcangeflag = false;

	return S_OK;
}

//-----�I������
void UninitFireWallHp(void)
{

}

//-----�X�V����
void UpdateFireWallHp(void)
{
	if (firewallhp.gaugesize.x <= firewallhp.hpsize * 0.2f)
		firewallhp.colorcangeflag = true;
	if (firewallhp.gaugesize.x > firewallhp.hpsize * 0.2f)
		firewallhp.colorcangeflag = false;

	//HP����̐ݒ�
	if (firewallhp.gaugesize.x > SCREEN_WIDTH * 0.4f)
		firewallhp.gaugesize.x = SCREEN_WIDTH * 0.4f;
}

//-----�`�揈��
void DrawFireWallHp(void)
{
	//-----HP�Q�[�W�̕`��
	if (firewallhp.colorcangeflag == false)
		DrawSpriteLeftTop(firewallhp.gaugegreentexture, firewallhp.pos.x, firewallhp.pos.y, 
							firewallhp.gaugesize.x, firewallhp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
	if(firewallhp.colorcangeflag == true)
	DrawSpriteLeftTop(firewallhp.gaugeredtexture, firewallhp.pos.x, firewallhp.pos.y, 
							firewallhp.gaugesize.x, firewallhp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0f);

	//-----HP�Q�[�W�̘g�̕`��
	DrawSpriteLeftTop(firewallhp.frametexture, firewallhp.pos.x, firewallhp.pos.y, 
							firewallhp.framesize.x, firewallhp.framesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----�\���̃|�C���^�擾����
FIREWALLHP* GetFireWallHp()
{
	return &firewallhp;
}