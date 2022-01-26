//�X�L��_�o���A���� [barrier.cpp]
#include "barrier.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----�}�N����`
#define barriertime 180		//3s��

//-----�v���g�^�C�v�錾
BARRIER barrier;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBarrier(void)
{
	PLAYER* player = GetPlayer();
	barrier.pos = D3DXVECTOR2(player->pos.x, player->pos.y);
	barrier.size = D3DXVECTOR2(player->size.y + 100.f, player->size.y + 100.f);
	barrier.u = 0.f;
	barrier.drawflag = false;
	barrier.texture = LoadTexture("data/TEXTURE/barrier.png");

	barrier.use = false;
	barrier.timeflag = false;
	barrier.time = 0.0f;
	barrier.usegauge = 20;

	barrier.bugincrease = false;
	barrier.bugdrawnum = 0;

	return S_OK;
}

//-----�o���A����
void _Barrier(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	RANDOM* random = GetRandom();	
	SKILL* skill = GetSkill();

	barrier.pos = D3DXVECTOR2(player->pos.x - 25.f, player->pos.y - 100.f);
	barrier.size = D3DXVECTOR2(player->size.y + 100.f, player->size.y + 200.f);

	//-----3s�ԃo���A�𒣂�
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 3 && random[i].active == true && barrier.use == false)
		{
			barrier.drawflag = true;
			barrier.timeflag = true;
			//-----�o�O�Q�[�W�̏㏸
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && barrier.bugincrease == false)
				{
					for (int j = i; barrier.bugdrawnum < 4; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						barrier.bugdrawnum = barrier.bugdrawnum + 1;
					}
					barrier.bugincrease = true;
				}
			}
			barrier.use = true;
		}
	}

	//-----�X�L���g�p3s��ɂ��Ƃ̑傫���ɖ߂�
	if (barrier.timeflag == true)
		barrier.time = barrier.time + 1.0f;
	if (barrier.time > barriertime)
	{
		barrier.timeflag = false;
		barrier.drawflag = false;
		barrier.time = 0.0f;
	}


	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && barrier.use == true)
		{
			barrier.use = false;
			barrier.timeflag = false;
			barrier.time = 0.0f;
			barrier.usegauge = 20;

			barrier.bugincrease = false;
			barrier.bugdrawnum = 0;
			barrier.drawflag = false;
		}
	}


	//�o���A�A�j���[�V����
	for (int i = 0; i < 21; i++)
	{
		if (barrier.time >= i * 8.571f && barrier.time < 8.571f + i * 8.571f)
				barrier.u = 0.0476190476f * i;
	}
}

void DrawBarrier(void)
{
	if (barrier.drawflag == true)
		DrawSpriteLeftTop(barrier.texture, barrier.pos.x, barrier.pos.y, barrier.size.x, barrier.size.y, barrier.u, 0.0f, 0.0476190476f, 1.0f);
}

BARRIER* GetBarrier(void)
{
	return &barrier;
}