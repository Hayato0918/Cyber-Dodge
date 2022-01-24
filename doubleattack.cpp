//�X�L��_�_�u���A�^�b�N���� [double_attack.cpp]
#include "doubleattack.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----�}�N����`
#define doubletime 600		//10s��

//-----�v���g�^�C�v�錾
DABLE dable;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitDouble(void)
{
	dable.use = false;
	dable.timeflag = false;
	dable.time = 0.0f;
	dable.usegauge = 30;

	dable.bugincrease = false;
	dable.bugdrawnum = 0;

	return S_OK;
}

//-----�_�u���A�^�b�N����
void _Double(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();
	BUGGAUGE* buggauge = GetBugGauge();
	SKILL* skill = GetSkill();

	//�����_����4���o����A10s�ԃL�����̍U���͂�2�{�ɂȂ�
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 17 && random[i].active == true && dable.use == false)
		{
			player->atk *= 2;
			dable.timeflag = true;
			//-----�o�O�Q�[�W�̏㏸
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && dable.bugincrease == false)
				{
					for (int j = i; dable.bugdrawnum < 6; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						dable.bugdrawnum = dable.bugdrawnum + 1;
					}
					dable.bugincrease = true;
				}
			}
			dable.use = true;
		}
	}
	//�X�L���g�p10s��ɂ��Ƃ̍U���͂ɖ߂�
	if (dable.timeflag == true)
		dable.time = dable.time + 1.0f;
	if (dable.time > doubletime)
	{
		dable.timeflag = false;
		player->atk /= 2;
		dable.time = 0.0f;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && dable.use == true)
		{
			if (dable.timeflag == true)
				player->atk /= 2;

			dable.use = false;
			dable.timeflag = false;
			dable.time = 0.0f;
			dable.usegauge = 30;

			dable.bugincrease = false;
			dable.bugdrawnum = 0;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && dable.use == true)
		{
			if (dable.timeflag == true)
				player->atk /= 2;

			dable.use = false;
			dable.timeflag = false;
			dable.time = 0.0f;
			dable.usegauge = 30;

			dable.bugincrease = false;
			dable.bugdrawnum = 0;
		}
	}
}