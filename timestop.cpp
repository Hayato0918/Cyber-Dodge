//�X�L��_���Ԓ�~���� [timestop.cpp]
#include "timestop.h"
#include "input.h"
//-----�G�l�~�[.h
#include "firewall.h"
#include "slime.h"

#include "bugincrease.h"
#include "catch.h"

#include "skillrandom.h"

//-----�}�N����`
#define timestoptime 360		//6s��

//-----�v���g�^�C�v�錾
TIMESTOP timestop;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitTimestop(void)
{
	timestop.use = false;
	timestop.timeflag = false;
	timestop.time = 0.0f;
	timestop.posnow = D3DXVECTOR2(0.0f, 0.0f);

	timestop.bugincrease = false;
	timestop.bugdrawnum = 0;

	return S_OK;
}

//-----���剻����
void _Timestop(void)
{
	FIREWALL* firewall = GetFireWall();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	SKILL* skill = GetSkill();
	RANDOM* random = GetRandom();
	CATCH* cattch = GetCatch();

	//�����_����4���o����A6s�ԓG���s���s�\�ɂȂ�
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 25 && random[i].active == true && timestop.use == false)
		{
			timestop.posnow = firewall->pos;
			timestop.timeflag = true;
			//-----�o�O�Q�[�W�̏㏸
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && timestop.bugincrease == false)
				{
					for (int j = i; timestop.bugdrawnum < 16; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						timestop.bugdrawnum = timestop.bugdrawnum + 1;
					}
					timestop.bugincrease = true;
				}
			}
			timestop.use = true;
		}
	}
	//�X�L���g�p6s��ɂ��Ƃɖ߂�
	if (timestop.timeflag == true)
	{
		timestop.time = timestop.time + 1.0f;
		firewall->pos = timestop.posnow;
		cattch->enemyflag = 2;
		cattch->enemyintervalflag = 2;
	}

	if (timestop.time > timestoptime)
	{
		timestop.timeflag = false;
		timestop.time = 0.0f;
		cattch->enemyflag = 0;
		cattch->enemyintervalflag = 0;
	}

	if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && timestop.use == true)
	{
		timestop.use = false;
		timestop.timeflag = false;
		timestop.time = 0.0f;
		timestop.posnow = D3DXVECTOR2(0.0f, 0.0f);
		cattch->enemyflag = 0;
		cattch->enemyintervalflag = 0;

		timestop.bugincrease = false;
		timestop.bugdrawnum = 0;
	}
}