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
		hp.frametexture = LoadTexture("data/TEXTURE/player/hp/player_hpframe.png");

		hp.pos = D3DXVECTOR2(100.0f, SCREEN_HEIGHT - 100.0f);
		hp.gaugesize = D3DXVECTOR2(hp.framesize.x, hp.framesize.y); //�c���Ă���HP�̗�
		hp.gaugeredtexture = LoadTexture("data/TEXTURE/player/hp/player_hpred.png");
		hp.gaugegreentexture = LoadTexture("data/TEXTURE/player/hp/player_hpgreen.png");

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