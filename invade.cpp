//�X�L��_�s�@�N������ [invade.cpp]
#include "invade.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----�}�N����`
#define invadetime 420		//3s��

//-----�v���g�^�C�v�錾
INVADE invade;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitInvade(void)
{
	invade.use = false;
	invade.timeflag = false;
	invade.time = 0.0f;
	invade.usegauge = 10;

	invade.bugincrease = false;
	invade.bugdrawnum = 0;

	return S_OK;
}

//-----�s�@�N������
void _Invade(void)
{
	PLAYER* player = GetPlayer();
	RANDOM* random = GetRandom();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	SKILL* skill = GetSkill();

	//�����_����5���I�΂ꂽ��A3�b�ԓG�̐w�n�ɓ����
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 9 && random[i].active == true && invade.use == false)
		{
			//-----�o�O�Q�[�W�̏㏸
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && invade.bugincrease == false)
				{
					for (int j = i; invade.bugdrawnum < 2; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						invade.bugdrawnum = invade.bugdrawnum + 1;
					}
					invade.bugincrease = true;
				}
			}

			//-----�v���C���[�̈ʒu��G�w�܂Ń��[�v������
			player->pos.x = (SCREEN_WIDTH / 2) + 5;

			invade.timeflag = true;
			invade.use = true;
		}
	}

	//�X�L���I�����ɓG�w�ɂ����ꍇ�Ax���W�����w�ƓG�w�̋��E�܂Ŗ߂�
	if (invade.timeflag == true)
		invade.time = invade.time + 1.0f;
	if (invade.time > invadetime)
	{
		invade.timeflag = false;
		invade.time = 0.0f;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && invade.use == true)
		{
			invade.use = false;
			invade.timeflag = false;
			invade.time = 0.0f;
			invade.usegauge = 10;

			invade.bugincrease = false;
			invade.bugdrawnum = 0;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && invade.use == true)
		{
			invade.use = false;
			invade.timeflag = false;
			invade.time = 0.0f;
			invade.usegauge = 10;

			invade.bugincrease = false;
			invade.bugdrawnum = 0;
		}
	}
}

//-----�\���̃|�C���^�擾����
INVADE* GetInvade(void)
{
	return &invade;
}