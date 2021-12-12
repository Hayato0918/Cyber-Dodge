//�X�L��_�o���A���� [barrier.cpp]
#include "barrier.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bug.h"

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
	barrier.size = D3DXVECTOR2(player->size.y, player->size.y);
	barrier.drawflag = false;
	barrier.texture = LoadTexture("data/TEXTURE/barrier.png");

	barrier.use = false;
	barrier.timeflag = false;
	barrier.time = 0.0f;
	barrier.usegauge = 20;

	return S_OK;
}

//-----�o���A����
void _Barrier(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBug();
	RANDOM* random = GetRandom();

	barrier.pos = D3DXVECTOR2(player->pos.x - player->size.x * 0.5f, player->pos.y);

	//-----3s�ԃo���A�𒣂�
	for (int i = 0; i < 36; i++)
	{
		if (random[i].code == 3 && random[i].active == true && barrier.use == false)
		{
			barrier.drawflag = true;
			barrier.timeflag = true;
			bug->gaugesize.x = bug->gaugesize.x + barrier.usegauge * bug->gaugeonce;
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
}

void DrawBarrier(void)
{
	if (barrier.drawflag == true)
		DrawSpriteLeftTop(barrier.texture, barrier.pos.x, barrier.pos.y, barrier.size.x, barrier.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

BARRIER* GetBarrier(void)
{
	return &barrier;
}