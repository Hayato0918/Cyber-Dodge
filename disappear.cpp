//�X�L��_���ŏ��� [disappear.cpp]
#include "disappear.h"
#include "input.h"
#include "sprite.h"

#include "bugincrease.h"

#include "skillrandom.h"
#include "otoshiana.h"
#include "enemybreak.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
DISAPPEAR disappear;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitDisappear(void)
{

	disappear.use = false;

	disappear.usegauge = 10;

	disappear.bugincrease = false;
	disappear.bugdrawnum = 0;

	return S_OK;
}

//-----���ŏ���
void _Disappear(void)
{
	OTOSIANA* otosiana = GetOtosiana();
	RANDOM* random = GetRandom();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	SKILL* skill = GetSkill();
	ENEMYBREAK* enemybreak = GetEnemyBreak();

	//T�L�[�����������Q��������
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 16 && random[i].active == true && disappear.use == false)
		{
			//-----�o�O�Q�[�W�̏㏸
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && disappear.bugincrease == false)
				{
					for (int j = i; disappear.bugdrawnum < 3; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						disappear.bugdrawnum = disappear.bugdrawnum + 1;
					}
					disappear.bugincrease = true;
				}
			}
			disappear.use = true;
		}
	}

	if (disappear.use == true)							//���Ƃ��������ł���B
	{
		otosiana->timeflag = false;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && disappear.use == true)
		{
			disappear.bugincrease = false;
			disappear.bugdrawnum = 0;
			disappear.use = false;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && disappear.use == true)
		{
			disappear.bugincrease = false;
			disappear.bugdrawnum = 0;
			disappear.use = false;
		}
	}

	if (enemybreak->drawflag == true && disappear.use == true)
	{
		disappear.bugincrease = false;
		disappear.bugdrawnum = 0;
		disappear.use = false;
	}
}
