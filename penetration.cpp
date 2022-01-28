//�X�L��_�ђ� [kantsuu.cpp]
#include "penetration.h"
#include "input.h"
#include "bugincrease.h"
#include "skillrandom.h"
#include "rockcreate.h"
#include "enemybreak.h"

//-----�}�N����`
#define kantsuutime 180	//3s��

//-----�v���g�^�C�v�錾
KANTSUU kantsuu;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitKantsuu(void)
{
	kantsuu.use = false;
	kantsuu.timeflag = false;
	kantsuu.time = 0.0f;
	kantsuu.usegauge = 10;

	kantsuu.bugincrease = false;
	kantsuu.bugdrawnum = 0;

	return S_OK;
}

//-----�s�@�N������
void _Kantsuu(void)
{
	RANDOM* random = GetRandom();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	SKILL* skill = GetSkill();
	ENEMYBREAK* enemybreak = GetEnemyBreak();

	//-----��������3�b�ԁA�{�[������Q���̔�����ђʂ���悤�ɂȂ�B
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 11 && random[i].active == true && kantsuu.use == false)
		{
			//-----�o�O�Q�[�W�̏㏸
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && kantsuu.bugincrease == false)
				{
					for (int j = i; kantsuu.bugdrawnum < 2; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						kantsuu.bugdrawnum = kantsuu.bugdrawnum + 1;
					}
					kantsuu.bugincrease = true;
				}
			}
			kantsuu.timeflag = true;
			kantsuu.use = true;
		}
	}

	//-----
	if (kantsuu.timeflag == true)
		kantsuu.time = kantsuu.time + 1.0f;

	if (kantsuu.time > kantsuutime)
	{
		kantsuu.timeflag = false;
		kantsuu.time = 0.0f;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && kantsuu.use == true)
		{
			kantsuu.use = false;
			kantsuu.timeflag = false;
			kantsuu.time = 0.0f;
			kantsuu.usegauge = 10;

			kantsuu.bugincrease = false;
			kantsuu.bugdrawnum = 0;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && kantsuu.use == true)
		{
			kantsuu.use = false;
			kantsuu.timeflag = false;
			kantsuu.time = 0.0f;
			kantsuu.usegauge = 10;

			kantsuu.bugincrease = false;
			kantsuu.bugdrawnum = 0;
		}
	}

	if (enemybreak->drawflag == true && kantsuu.use == true)
	{
		kantsuu.use = false;
		kantsuu.timeflag = false;
		kantsuu.time = 0.0f;
		kantsuu.usegauge = 10;

		kantsuu.bugincrease = false;
		kantsuu.bugdrawnum = 0;
	}
}

//-----�\���̃|�C���^�擾����
KANTSUU* GetKantsuu(void)
{
	return &kantsuu;
}