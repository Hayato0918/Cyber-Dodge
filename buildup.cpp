//�X�L��_�r���h�A�b�v���� [buildup.cpp]
#include "buildup.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bugincrease.h"
#include "catch.h"

#include "skillrandom.h"

//-----�}�N����`
#define builduptime 1000		//20s��

//-----�v���g�^�C�v�錾
BUILDUP buildup;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBuildUp(void)
{
	buildup.use = false;
	buildup.timeflag = false;
	buildup.time = 0.0f;
	buildup.usegauge = 10;

	buildup.bugincrease = false;
	buildup.bugdrawnum = 0;

	return S_OK;
}

//-----���剻����
void _BuildUp(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBugIncrease();;
	RANDOM* random = GetRandom();
	BUGGAUGE* buggauge = GetBugGauge();
	CATCH* Catch = GetCatch();
	SKILL* skill = GetSkill();

	//�����_����4���o����A20s�ԃL�����̃T�C�Y��2�{�ɂȂ�
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 7 && random[i].active == true && buildup.use == false)
		{
			player->size = D3DXVECTOR2(player->size.x * 2, player->size.y * 2);
			Catch->playersize = D3DXVECTOR2(Catch->playersize.x * 2, Catch->playersize.y * 2);
			buildup.time = 0.f;
			buildup.timeflag = true;
			//-----�o�O�Q�[�W�̏㏸
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && buildup.bugincrease == false)
				{
					for (int j = i; buildup.bugdrawnum < 3; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						buildup.bugdrawnum = buildup.bugdrawnum + 1;
					}
					buildup.bugincrease = true;
				}
			}
			buildup.use = true;
		}
	}

	if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && buildup.use == true)
	{
		if (buildup.timeflag == true)
		{
			player->size = D3DXVECTOR2(player->size.x * 0.5f, player->size.y * 0.5f);
			Catch->playersize = D3DXVECTOR2(Catch->playersize.x * 0.5f, Catch->playersize.y * 0.5f);
		}

		buildup.timeflag = false;
		buildup.bugincrease = false;
		buildup.bugdrawnum = 0;
		buildup.time = builduptime;
		buildup.use = false;

	}

	//�X�L���g�p20s��ɂ��Ƃ̑傫���ɖ߂�
	if (buildup.timeflag == true)
		buildup.time = buildup.time + 1.0f;
	if (buildup.time > builduptime)
	{
		buildup.timeflag = false;
		player->size = D3DXVECTOR2(player->size.x * 0.5f, player->size.y * 0.5f);
		Catch->playersize = D3DXVECTOR2(Catch->playersize.x * 0.5f, Catch->playersize.y * 0.5f);
		buildup.time = 0.0f;
	}
}