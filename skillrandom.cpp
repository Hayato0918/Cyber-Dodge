//�X�L�������_�� [skillrandom.cpp]
#include "skillrandom.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"

#include "ballspeedup.h"
#include "barrier.h"
#include "bigball.h"
#include "buildup.h"
#include "invade.h"
#include "slowarea.h"
#include "smallplayer.h"
#include "step.h"

#include <stdlib.h>
#include <time.h>

//-----�}�N����`

//-----�v���g�^�C�v�錾
RANDOM random;

//-----�O���[�o���ϐ�
PLAYER* player = GetPlayer();
//-----����������
HRESULT InitRandom(void)
{
	random.code = 0;
	random.use = false;
	random.active = false;
	random.move = D3DXVECTOR2(player->move.x, player->move.y);

	return S_OK;
}

void UninitRandom(void)
{

}

void UpdateRandom(void)
{
	random.pos = D3DXVECTOR2(player->pos.x, player->pos.y - 60.0f);
	random.move = D3DXVECTOR2(player->move.x, player->move.y);

	if (GetKeyboardTrigger(DIK_1) && random.use == false)
	{
		//�����_��
		srand(time(0));
		random.code = (rand() % 6) + 1;

		random.use = true;
		random.active = false;

		switch (random.code)
		{
			case 1:	//�X�s�[�h�A�b�v
			{
				if (random.code == 1 && random.use == true)
				{
					random.size = D3DXVECTOR2(100.0f, 40.0f);
					random.texture = LoadTexture("data/TEXTURE/speedup.png");
				}
				break;
			}

			case 2:	//�o���A
			{
				if (random.code == 2 && random.use == true)
				{
					random.size = D3DXVECTOR2(100.0f, 40.0f);
					random.texture = LoadTexture("data/TEXTURE/barrierR.png");
				}
				break;
			}

			case 3:	//�{�[�����剻
			{
				if (random.code == 3 && random.use == true)
				{
					random.size = D3DXVECTOR2(100.0f, 40.0f);
					random.texture = LoadTexture("data/TEXTURE/bigball.png");
				}
				break;
			}

			case 4:	//�v���C���[���剻
			{
				if (random.code == 4 && random.use == true)
				{
					random.size = D3DXVECTOR2(100.0f, 40.0f);
					random.texture = LoadTexture("data/TEXTURE/buildup.png");
				}
				break;
			}

			case 5:	//�s�@�N��
			{
				if (random.code == 5 && random.use == true)
				{
					random.size = D3DXVECTOR2(100.0f, 40.0f);
					random.texture = LoadTexture("data/TEXTURE/invade.png");
				}
				break;
			}

			case 6:	//�X���E�G���A
			{
				if (random.code == 6 && random.use == true)
				{
					random.size = D3DXVECTOR2(100.0f, 40.0f);
					random.texture = LoadTexture("data/TEXTURE/slowarea.png");
				}
				break;
			}

			case 7:	//�v���C���[�k��
			{
				if (random.code == 7 && random.use == true)
				{
					random.size = D3DXVECTOR2(100.0f, 40.0f);
					random.texture = LoadTexture("data/TEXTURE/smallplayer.png");
				}
				break;
			}

			case 8:	//����N�[���^�C������
			{
				if (random.code == 8 && random.use == true)
				{
					random.size = D3DXVECTOR2(100.0f, 40.0f);
					random.texture = LoadTexture("data/TEXTURE/step.png");
				}
				break;
			}
		}
	}

	//2�L�[�������ƁA�������Z�b�g
	if (GetKeyboardTrigger(DIK_2) && random.active == false && random.use == true)
	{
		random.texture = LoadTexture("data/TEXTURE/blank.png");
		random.active = true;
		random.use = false;
	}
}

void DrawRandom(void)
{
	DrawSpriteLeftTop(random.texture, random.pos.x, random.pos.y, random.size.x, random.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

RANDOM* GetRandom()
{
	return &random;
}