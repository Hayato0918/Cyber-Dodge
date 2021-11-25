//�X�L��_�X���E�G���A���� [slowarea.cpp]
#include "slowarea.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "time.h"

#include "player.h"

#include "skillrandom.h"

//-----�}�N����`
#define slowareatime 180		//3s��

//-----�v���g�^�C�v�錾
SLOWAREA slowarea;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitSlowArea(void)
{
	slowarea.size = D3DXVECTOR2(60.0f, 60.0f);
	srand((unsigned int)time(NULL));
	slowarea.xrand = rand() % 10 + 1;
	srand((unsigned int)time(NULL) + 1);
	slowarea.yrand = rand() % 10 + 1;
	slowarea.pos = D3DXVECTOR2(slowarea.xrand * SCREEN_WIDTH * 0.05f - slowarea.size.x, 320.0f + slowarea.yrand * 22 - slowarea.size.y);
	slowarea.use = false;
	slowarea.timeflag = false;
	slowarea.time = 0.0f;

	slowarea.texture = LoadTexture("data/TEXTURE/slow.png");

	return S_OK;
}

//-----�X���[����
void _SlowArea(void)
{
	PLAYER* player = GetPlayer();
	RANDOM* random = GetRandom();

	//-----�����_����6���I�΂ꂽ��A3s�ԑ����������Ȃ�G���A���ł���
	if (random->code == 6 && random->active == true && slowarea.use == false)
	{
		slowarea.timeflag = true;
		slowarea.use = true;
	}

	//-----�G���A�̏�ɂ����瑫���x���Ȃ�
	if (slowarea.timeflag == true)
	{
		if (player->pos.x + player->size.x > slowarea.pos.x && player->pos.x < slowarea.pos.x + slowarea.size.x)
		{
			if (player->pos.y + player->size.y > slowarea.pos.y && player->pos.y < slowarea.pos.y + slowarea.size.y)
				player->move = D3DXVECTOR2(3.0f, 3.0f);
			else
				player->move = D3DXVECTOR2(10.0f, 10.0f);
		}
		else
			player->move = D3DXVECTOR2(10.0f, 10.0f);
	}

	//-----�X�L���g�p3s��ɂ��Ƃɖ߂�
	if (slowarea.timeflag == true)
		slowarea.time = slowarea.time + 1.0f;
	if (slowarea.time > slowareatime)
	{
		slowarea.timeflag = false;
		player->move = D3DXVECTOR2(10, 10);
		slowarea.time = 0.0f;
	}
}

//-----�`�揈��
void DrawSlowArea(void)
{
	if (slowarea.timeflag == true)
		DrawSpriteLeftTop(slowarea.texture, slowarea.pos.x, slowarea.pos.y, slowarea.size.x, slowarea.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}