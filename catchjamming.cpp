//�X�L��_�L���b�`�W�Q���� [cacthjamming.cpp]
#include "catchjamming.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "bugincrease.h"

#include "skillrandom.h"

//-----�}�N����`
#define catchjammingtime 240

//-----�v���g�^�C�v�錾
CATCHJAMMING catchjamming;

HRESULT InitCatchJamming(void)
{
	catchjamming.use = false;
	catchjamming.timeflag = false;
	catchjamming.time = 0.0f;
	catchjamming.usegauge = 60;

	catchjamming.bugincrease = false;
	catchjamming.bugdrawnum = 0;

	return S_OK;
}

void _CatchJamming(void)
{
	BUG* bug = GetBugIncrease();;
	RANDOM* random = GetRandom();
	BUGGAUGE* buggauge = GetBugGauge();
	SKILL* skill = GetSkill();

	//I�L�[����������A4�b�ԃL���b�`���o���Ȃ��Ȃ�B
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 8 && random[i].active == true && catchjamming.use == false)
		{
			catchjamming.timeflag = true;
			//-----�o�O�Q�[�W�̏㏸
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && catchjamming.bugincrease == false)
				{
					for (int j = i; catchjamming.bugdrawnum < 12; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						catchjamming.bugdrawnum = catchjamming.bugdrawnum + 1;
					}
					catchjamming.bugincrease = true;
				}
			}
			catchjamming.use = true;
		}
	}
	//�X�L���g�p4�b��ɂ��Ƃɖ߂�
	if (catchjamming.timeflag == true)
		catchjamming.time = catchjamming.time + 1.0f;
	if (catchjamming.time > catchjammingtime)
	{
		catchjamming.timeflag = false;
		catchjamming.time = 0.0f;
	}
	if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && catchjamming.use == true)
	{
		catchjamming.use = false;
		catchjamming.timeflag = false;
		catchjamming.time = 0.0f;
		catchjamming.usegauge = 60;

		catchjamming.bugincrease = false;
		catchjamming.bugdrawnum = 0;
	}



}

CATCHJAMMING* GetCatchJamming()
{
	return &catchjamming;
}