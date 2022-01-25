/*------------------------------------------
[ ��ʊ��� [ Bug_screencrack.cpp ] ]
-------------------------------------------*/
#include "screencrack.h"
#include "input.h"
#include "Texture.h"
#include "sprite.h"

#include "bugincrease.h"
#include "bugrandom.h"
#include "player.h"

//-----�}�N����`
#define cracktime 180		//3s��
#define cracktime_yure 10		//0.5s��

//-----�v���g�^�C�v�錾
CRACK crack;

//-----����������
HRESULT InitCrack(void)
{
	crack.pos = D3DXVECTOR2(SCREEN_WIDTH / 2 + 300.0f, SCREEN_HEIGHT / 2 - 300.0f);
	crack.move = D3DXVECTOR2(-50, 50);
	crack.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

	crack.oldpos = crack.pos;
	crack.oldmove = crack.move;

	crack.use = false;
	crack.drawflag = false;
	crack.texture = LoadTexture("data/TEXTURE/buggauge/screencrack.png");
	crack.timeflag = false;
	crack.time = 0.0f;
	crack.time_yure = 0.0f;
	crack.bugflag = false;
	crack.a = 1.0f;
	//crack.color = D3DXCOLOR(1.0f, 1.0f, 1.0f, crack.a);

	return S_OK;
}

//-----�v���C���[���]����
void _Crack(void)
{
	BUG* bug = GetBugIncrease();
	BUGRANDOM* bugrandom = GetBugRandom();
	PLAYER* player = GetPlayer();

	//�o�O�Q�[�W��100�ȏ�ɂȂ��āA�X�L�����g�����{�[����������Ɖ�ʂ������
	if (bug->gaugeoverflag == true && player->skilluseflag == true && crack.use == false && crack.bugflag == false)
	{
		crack.use = true;
		crack.drawflag = true;
		crack.timeflag = true;
		crack.bugflag = true;
	}

	crack.color = D3DXCOLOR(1.0f, 1.0f, 1.0f, crack.a);

	//-----��ʂ����ꂽ3s��Ƀo�O��ԂɈڍs
	if (crack.timeflag == true)
	{
		crack.time = crack.time + 1.0f;
		crack.time_yure = crack.time_yure + 1.0f;
		crack.pos += crack.move;
		crack.a = crack.a - 0.005f;
	}

	//��ʂ�h�炷
	if (crack.time_yure > cracktime_yure)
	{
		crack.move /= 2.0f;
		crack.move *= -1.0f;
		crack.time_yure = 0.0f;
	}

	//��ʊ���̃t�F�[�h�A�E�g��A���̐��l�ɖ߂�
	if (crack.time > cracktime)
	{
		crack.timeflag = false;
		crack.drawflag = false;
		crack.time = 0.0f;
		bug->breakflag = true;
		crack.a = 1.0f;
		/*crack.pos = crack.oldpos;
		crack.move = crack.oldmove;*/
	}

	//�o�O�Q�[�W��100�ȉ��ɂȂ�����
	if (bug->gaugeoverflag == false && crack.use == true)
	{
		crack.use = false;
		crack.pos = D3DXVECTOR2(SCREEN_WIDTH / 2 + 300.0f, SCREEN_HEIGHT / 2 - 300.0f);
		crack.move = D3DXVECTOR2(-50, 50);
		crack.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

		crack.oldpos = crack.pos;
		crack.oldmove = crack.move;

		crack.use = false;
		crack.drawflag = false;
		crack.timeflag = false;
		crack.time = 0.0f;
		crack.time_yure = 0.0f;
		crack.bugflag = false;
		crack.a = 1.0f;
	}
}

//-----�`�揈��
void DrawCrack(void)
{
	if (crack.drawflag == true && crack.bugflag == true)
	{
		//DrawSpriteLeftTop(crack.texture, crack.pos.x, crack.pos.y, crack.size.x, crack.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		DrawSpriteColor(crack.texture, crack.pos.x, crack.pos.y, crack.size.x, crack.size.y, 0.0f, 0.0f, 1.0f, 1.0f, crack.color);
	}
}

//-----�\���̃|�C���^�擾����
CRACK* GetCrack()
{
	return &crack;
}