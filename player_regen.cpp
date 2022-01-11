//�X�L��_���W�F�l���� [player_regen.cpp]
#include "player_regen.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bugincrease.h"
#include "player_hp.h"

#include "skillrandom.h"

//-----�}�N����`
#define regentime 60		//1s��

//-----�v���g�^�C�v�錾
PLAYERREGEN regen;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitPlayerRegen(void)
{
	regen.use = false;
	regen.timeflag = false;
	regen.time = 0.0f;
	regen.number = 0;
	regen.usegauge = 30;

	regen.bugincrease = false;
	regen.bugdrawnum = 0;

	return S_OK;
}

//-----���剻����
void _PlayerRegen(void)
{
	PLAYERHP* hp = GetPlayerHp();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	RANDOM* random = GetRandom();

	//�����_����4���o����A10s�ԃL�����̗̑͂�1s����10�񕜂���
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 23 && random[i].active == true && regen.use == false)
		{
			regen.timeflag = true;
			//-----�o�O�Q�[�W�̏㏸
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && regen.bugincrease == false)
				{
					for (int j = i; regen.bugdrawnum < 4; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						regen.bugdrawnum = regen.bugdrawnum + 1;
					}
					regen.bugincrease = true;
				}
			}
			regen.use = true;
		}
	}
	//�X�L��������b�����J�E���g
	if (regen.timeflag == true)
		regen.time = regen.time + 1.0f;
	//1s���Ƃɑ̗͂�1��
	if (regen.time > regentime)
	{
		if (hp->gaugesize.x < 640)
		{
			hp->gaugesize.x += 10 * 3.2f;
			hp->pos.x -= 10 * 3.2f;
		}
		regen.time = 0.0f;
		regen.number += 1;
	}

	if (hp->gaugesize.x > 640)
	{
		hp->gaugesize.x = 640;
		hp->pos.x = 100.0f;
	}

	//���v100�񕜌�b���J�E���g���~�߂�
	if (regen.number > 10)
	{
		regen.timeflag = false;
		regen.time = 0.0f;
		regen.use = false;
		regen.bugincrease = false;
		regen.bugdrawnum = 0;
		regen.number = 0;
	}
}