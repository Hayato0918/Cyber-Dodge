//�X�L��_�����L���b�`���� [autocatch.cpp]
#include "autocatch.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bugincrease.h"
#include "catch.h"

#include "skillrandom.h"

//-----�}�N����`
#define auto_ctime 600		//10s��

//-----�v���g�^�C�v�錾
AUTO auto_c;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitAuto_c(void)
{
	auto_c.use = false;
	auto_c.timeflag = false;
	auto_c.time = 0.0f;
	auto_c.usegauge = 50;
	auto_c.auto_catch = false;
	auto_c.auto_catchflag = false;

	auto_c.bugincrease = false;
	auto_c.bugdrawnum = 0;

	return S_OK;
}

//-----�����L���b�`����
void _Auto_c(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();
	SKILL* skill = GetSkill();
	CATCH* Catch = GetCatch();
	BUGGAUGE* buggauge = GetBugGauge();

	//�����_����15���o����A10s�ԃL�����̍U���͂�2�{�ɂȂ�
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 15 && random[i].active == true && auto_c.use == false)
		{
			Catch->playerpos.y -= Catch->playersize.y;
			Catch->playersize.y *= 4;
			auto_c.auto_catch = true;
			auto_c.auto_catchflag = true;
			auto_c.timeflag = true;

			//-----�o�O�Q�[�W�̏㏸
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && auto_c.bugincrease == false)
				{
					for (int j = i; auto_c.bugdrawnum < 10; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						auto_c.bugdrawnum = auto_c.bugdrawnum + 1;
					}
					auto_c.bugincrease = true;
				}
			}

			auto_c.use = true;
		}
	}
	//�X�L���g�p10s��ɂ��Ƃ̏�Ԗ߂�
	if (auto_c.timeflag == true)
		auto_c.time = auto_c.time + 1.0f;
	if (auto_c.time > auto_ctime)
	{
		Catch->playerpos.y += Catch->playersize.y;
		Catch->playersize.y /= 4;
		auto_c.timeflag = false;
		auto_c.auto_catch = false;
		auto_c.auto_catchflag = false;
		auto_c.bugdrawnum = 0;
		auto_c.bugincrease = false;
		auto_c.time = 0.0f;
	}
	if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && auto_c.use == true)
	{
		if (auto_c.timeflag == true)
		{
			Catch->playerpos.y += Catch->playersize.y;
			Catch->playersize.y /= 4;
		}
		auto_c.timeflag = false;
		auto_c.auto_catch = false;
		auto_c.auto_catchflag = false;
		auto_c.bugdrawnum = 0;
		auto_c.bugincrease = false;
		auto_c.time = 0.0f;
		auto_c.use = false;
	}
}

AUTO* GetAuto()
{
	return &auto_c;
}