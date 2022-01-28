//�X�L��_�v���C���[���������Ȃ鏈�� [SmallPlayer.cpp] 
#include "smallplayer.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "catch.h"
#include "bugincrease.h"

#include "skillrandom.h"
#include "enemybreak.h"

//-----�}�N����`
#define smallplayertime 420		//3s��

//-----�v���g�^�C�v�錾
SMALLPLAYER smallplayer;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitSmallPlayer(void)
{
	smallplayer.use = false;
	smallplayer.timeflag = false;
	smallplayer.time = 0.0f;
	smallplayer.usegauge = 10;

	smallplayer.bugincrease = false;
	smallplayer.bugdrawnum = 0;

	return S_OK;
}

//-----�v���C���[�k������
void _SmallPlayer(void)
{
	PLAYER* player = GetPlayer();
	RANDOM* random = GetRandom();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	CATCH* Catch = GetCatch();
	SKILL* skill = GetSkill();
	ENEMYBREAK* enemybreak = GetEnemyBreak();

	//�����_����7���I�΂ꂽ��A3s�ԃL�����̃T�C�Y��0.5�{�������Ȃ�ɂȂ�
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 14 && random[i].active == true && smallplayer.use == false)
		{
			//-----�o�O�Q�[�W�̏㏸
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && smallplayer.bugincrease == false)
				{
					for (int j = i; smallplayer.bugdrawnum < 2; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						smallplayer.bugdrawnum = smallplayer.bugdrawnum + 1;
					}
					smallplayer.bugincrease = true;
				}
			}
			player->size = D3DXVECTOR2(player->size.x * 0.5f, player->size.y * 0.5f);
			Catch->playersize = D3DXVECTOR2(Catch->playersize.x / 2, Catch->playersize.y / 2);
			smallplayer.timeflag = true;
			smallplayer.use = true;
		}
	}
	//�X�L���g�p3s��ɂ��Ƃ̑傫���ɖ߂�
	if (smallplayer.timeflag == true)
		smallplayer.time = smallplayer.time + 1.0f;
	if (smallplayer.time > smallplayertime)
	{
		smallplayer.timeflag = false;
		player->size = D3DXVECTOR2(player->size.x * 2, player->size.y * 2);
		Catch->playersize = D3DXVECTOR2(Catch->playersize.x * 2, Catch->playersize.y * 2);
		smallplayer.time = 0.0f;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && smallplayer.use == true)
		{
			if (smallplayer.time < smallplayertime && smallplayer.timeflag == true)
			{
				player->size = D3DXVECTOR2(player->size.x * 2, player->size.y * 2);
				Catch->playersize = D3DXVECTOR2(Catch->playersize.x * 2, Catch->playersize.y * 2);
			}

			smallplayer.use = false;
			smallplayer.timeflag = false;
			smallplayer.time = 0.0f;
			smallplayer.usegauge = 10;

			smallplayer.bugincrease = false;
			smallplayer.bugdrawnum = 0;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && smallplayer.use == true)
		{
			if (smallplayer.time < smallplayertime && smallplayer.timeflag == true)
			{
				player->size = D3DXVECTOR2(player->size.x * 2, player->size.y * 2);
				Catch->playersize = D3DXVECTOR2(Catch->playersize.x * 2, Catch->playersize.y * 2);
			}

			smallplayer.use = false;
			smallplayer.timeflag = false;
			smallplayer.time = 0.0f;
			smallplayer.usegauge = 10;

			smallplayer.bugincrease = false;
			smallplayer.bugdrawnum = 0;
		}
	}

	if (enemybreak->drawflag == true && smallplayer.use == true)
	{
		if (smallplayer.time < smallplayertime && smallplayer.timeflag == true)
		{
			player->size = D3DXVECTOR2(player->size.x * 2, player->size.y * 2);
			Catch->playersize = D3DXVECTOR2(Catch->playersize.x * 2, Catch->playersize.y * 2);
		}

		smallplayer.use = false;
		smallplayer.timeflag = false;
		smallplayer.time = 0.0f;
		smallplayer.usegauge = 10;

		smallplayer.bugincrease = false;
		smallplayer.bugdrawnum = 0;
	}

}