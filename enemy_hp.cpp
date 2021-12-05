//�G�l�~�[HP���� [enemy_hp.cpp]
#include "enemy_hp.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
ENEMYHP enemyhp;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitEnemyHp(void)
{
	enemyhp.gaugeonce = 8;

	enemyhp.framepos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 + 100.f, SCREEN_HEIGHT - 100.0f);
	enemyhp.framesize = D3DXVECTOR2(80.f * enemyhp.gaugeonce, 60.0f); //enemyhp�o�[�t���[���T�C�Y
	enemyhp.frametexture = LoadTexture("data/TEXTURE/bugframe.png");

	enemyhp.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 + 100.f, SCREEN_HEIGHT - 100.0f);
	enemyhp.gaugesize = D3DXVECTOR2(enemyhp.framesize.x, enemyhp.framesize.y); //�c���Ă���enemyhp�̗�
	enemyhp.gaugegreentexture = LoadTexture("data/TEXTURE/hp_green.png");
	enemyhp.gaugeredtexture = LoadTexture("data/TEXTURE/obstacle.png");

	enemyhp.hpsize = enemyhp.gaugesize.x;
	enemyhp.colorcangeflag = false;

	return S_OK;
}

//-----�I������
void UninitEnemyHp(void)
{

}

//-----�X�V����
void UpdateEnemyHp(void)
{
	if (enemyhp.gaugesize.x <= enemyhp.hpsize * 0.2f)
		enemyhp.colorcangeflag = true;
	if (enemyhp.gaugesize.x > enemyhp.hpsize * 0.2f)
		enemyhp.colorcangeflag = false;
}

//-----�`�揈��
void DrawEnemyHp(void)
{
	//-----HP�Q�[�W�̕`��
	if (enemyhp.colorcangeflag == false)
		DrawSpriteLeftTop(enemyhp.gaugegreentexture, enemyhp.pos.x, enemyhp.pos.y, enemyhp.gaugesize.x, enemyhp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
	if(enemyhp.colorcangeflag == true)
	DrawSpriteLeftTop(enemyhp.gaugeredtexture, enemyhp.pos.x, enemyhp.pos.y, enemyhp.gaugesize.x, enemyhp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0f);

	//-----HP�Q�[�W�̘g�̕`��
	DrawSpriteLeftTop(enemyhp.frametexture, enemyhp.pos.x, enemyhp.pos.y, enemyhp.framesize.x, enemyhp.framesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----�\���̃|�C���^�擾����
ENEMYHP* GetEnemyHp()
{
	return &enemyhp;
}