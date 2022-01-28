//�v���C���[HP���� [player_hp.h]
#include "player_hp.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"

#include "map_player.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
PLAYERHP hp;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitPlayerHp(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	if (map_player->gamecount == 1)
	{
		hp.gaugeonce = 8;

		hp.framepos = D3DXVECTOR2(100.0f, SCREEN_HEIGHT - 100.0f);
		hp.framesize = D3DXVECTOR2(80.f * hp.gaugeonce, 60.0f); //HP�o�[�t���[���T�C�Y


		hp.pos = D3DXVECTOR2(100.0f, SCREEN_HEIGHT - 100.0f);
		hp.saidai_pos = D3DXVECTOR2(100.0f, SCREEN_HEIGHT - 100.0f);
		hp.gaugesize = D3DXVECTOR2(hp.framesize.x, hp.framesize.y); //�c���Ă���HP�̗�


		hp.hpsize = hp.gaugesize.x;
		hp.colorcangeflag = false;
	}

	return S_OK;
}

//-----�I������
void UninitPlayerHp(void)
{

}

//-----�X�V����
void UpdatePlayerHp(void)
{
	//-----HP��20%��؂�����
	if (hp.gaugesize.x <= hp.hpsize * 0.2f)
		hp.colorcangeflag = true;
	if (hp.gaugesize.x > hp.hpsize * 0.2f)
		hp.colorcangeflag = false;

	//-----HP�̃Q�[�W���
	if (hp.gaugesize.x >= 640.0f)
	{
		hp.gaugesize.x = 640.0f;
	}
	//-----HP�Q�[�W�̏ꏊ���
	if (hp.pos.x <= 100.0f)
		hp.pos.x = 100.0f;
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

void AddPlayerHp(int index)
{
	hp.gaugesize.x += index / 0.3125f;
	hp.pos.x = hp.pos.x - index / 0.3125f;
	if (hp.gaugesize.x >= hp.framesize.x)
	{
		hp.gaugesize.x = hp.framesize.x;
	}
	if (hp.gaugesize.x < 3.2f)
	{
		hp.gaugesize.x = 3.2f;
	}

	return;
}

void AddPlayerHpMAX(int index)
{
	hp.framesize.x += index / 0.3125f;
	hp.framepos.x = hp.framepos.x - index / 0.3125f;

	if (hp.framesize.x < hp.gaugesize.x)
	{
		hp.pos.x = hp.pos.x + hp.gaugesize.x - hp.framesize.x;
		hp.gaugesize.x = hp.framesize.x;
	}

	if (hp.framesize.x < 3.2f)
	{
		hp.framesize.x = 3.2f;
	}

	return;
}