//�}�b�v�}�X/�}�b�v�v���C���[/�}�b�v���C������ [map_point.cpp]
#include <stdlib.h>
#include <time.h>

#include "map_player.h"
#include "map_point.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "map_hack.h"
#include "map_line.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
MAP_PLAYER map_player;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitMapPlayer(void)
{
		MAP* map = GetMapPoint();
		MAP_SB* map_sb = GetMapSB();
		MAP_LINE* map_line = GetMapLine();

		//�v���C���[�̏�����
		if (map_player.UDcount == 0)
		{
			map_player.size = D3DXVECTOR2(100.0f, 100.0f);
			map_player.pos = D3DXVECTOR2(map_sb->startpos.x, map_sb->startpos.y);
			map_player.texture = LoadTexture("data/TEXTURE/map_player.png");
			map_player.UDcount = 0;
			map_player.LRcount = 0;
			map_player.nowpos = 0;

			//�I���̘g�̏�����
			map_player.circlepos = D3DXVECTOR2(map[0].pos.x, map[0].pos.y);
			map_player.circlesize = D3DXVECTOR2(map[0].size.x, map[0].size.y);
			map_player.circletexture = LoadTexture("data/TEXTURE/circle.png");
			map_player.circlenowpos = 0;

			map_player.gamecount = 0;

			map_player.nextflag = true;

			if (map_line->randomcode == 1)
				map_player.mapnum = 21;
			if (map_line->randomcode == 2)
				map_player.mapnum = 20;
			if (map_line->randomcode == 3)
				map_player.mapnum = 18;
			if (map_line->randomcode == 4)
				map_player.mapnum = 24;
		}

	return S_OK;
}

//�I������
void UninitMapPlayer(void)
{

}

//-----�X�V����
void UpdateMapPlayer(void)
{
	MAP_HACK* map_hack = GetMapHack();
	MAP* map = GetMapPoint();
	MAP_SB* map_sb = GetMapSB();
	MAP_LINE* map_line = GetMapLine();

	//-----�}�b�v�X�N���[��
	if (map_hack->isUse == false)
	{
		if (PADUSE == 1)
		{
			if (GetKeyboardPress(DIK_W))	//��
			{
				map_player.pos.y += 3;
				map_player.circlepos.y += 3;
			}
			if (GetKeyboardPress(DIK_S))	//��
			{
				map_player.pos.y -= 3;
				map_player.circlepos.y -= 3;
			}

			if(map_player.nextflag == true)
			{
			//-----�V�[�g1�̏ꍇ
			if (map_line->randomcode == 1)
			{
				//7�i��
				//18��boss
				if (map_player.nowpos == 19 || map_player.nowpos == 20 || map_player.nowpos == 21)
				{
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.nowpos = 22;
						map_player.nextflag = false;
					}
				}

				//6�i��
				//15��18
				if (map_player.nowpos == 16)
				{
					map_player.circlenowpos = 18;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						map_player.nowpos = 19;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//16��19
				if (map_player.nowpos == 17)
				{
					map_player.circlenowpos = 19;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[19].pos.x, map[19].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						map_player.nowpos = 19;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//17��20
				if (map_player.nowpos == 18)
				{
					map_player.circlenowpos = 20;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[20].pos.x, map[20].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						map_player.nowpos = 21;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//5�i��
				//10��15
				if (map_player.nowpos == 11)
				{
					map_player.circlenowpos = 15;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
						map_player.nowpos = 16;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//13��16�A13��17
				if (map_player.nowpos == 14)
				{
					map_player.circlenowpos = map_player.LRcount + 16;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 16].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 16].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 16].pos.x, map[map_player.LRcount + 16].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[19].pos.x, map[19].pos.y);
							map_player.nowpos = 17;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[20].pos.x, map[20].pos.y);
							map_player.nowpos = 18;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//14��17
				if (map_player.nowpos == 15)
				{
					map_player.circlenowpos = 17;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[20].pos.x, map[20].pos.y);
						map_player.nowpos = 18;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//-----4�i��
				//12��14�A12��15
				if (map_player.nowpos == 12)
				{
					map_player.circlenowpos = map_player.LRcount + 13;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 13].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 13].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 13].pos.x, map[map_player.LRcount + 13].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
							map_player.nowpos = 14;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
							map_player.nowpos = 15;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//13��15
				if (map_player.nowpos == 13)
				{
					map_player.circlenowpos = 14;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
						map_player.nowpos = 15;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//-----3�i��
				//7��10
				if (map_player.nowpos == 8)
				{
					map_player.circlenowpos = 10;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
						map_player.nowpos = 11;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//8��10�A8��11
				if (map_player.nowpos == 9)
				{
					map_player.circlenowpos = map_player.LRcount + 10;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 10].pos.x, map[map_player.LRcount + 10].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
							map_player.nowpos = 11;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
							map_player.nowpos = 12;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//10��12�A10��13
				if (map_player.nowpos == 10)
				{
					map_player.circlenowpos = map_player.LRcount + 11;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 11].pos.x, map[map_player.LRcount + 11].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
							map_player.nowpos = 12;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
							map_player.nowpos = 13;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//-----2�i��
				//5��8
				if (map_player.nowpos == 5)
				{
					map_player.circlenowpos = 7;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
						map_player.nowpos = 8;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//6��9
				if (map_player.nowpos == 6)
				{
					map_player.circlenowpos = 8;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
						map_player.nowpos = 9;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//7��10
				if (map_player.nowpos == 7)
				{
					map_player.circlenowpos = 9;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[11].pos.x, map[11].pos.y);
						map_player.nowpos = 10;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//-----1�i��
				//0��5�A1��5
				if (map_player.nowpos == 1 || map_player.nowpos == 2)
				{
					map_player.circlenowpos = 4;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
						map_player.nowpos = 5;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				if (map_player.nowpos == 3)
				{
					map_player.circlenowpos = map_player.LRcount + 5;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 5].pos.x, map[map_player.LRcount + 5].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
							map_player.nowpos = 6;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
							map_player.nowpos = 7;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//4��7
				if (map_player.nowpos == 4)
				{
					map_player.circlenowpos = 6;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
						map_player.nowpos = 7;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//-----0�i��
				if (map_player.nowpos == 0)
				{
					map_player.circlenowpos = map_player.LRcount;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 3)	//�E
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount].pos.x, map[map_player.LRcount].pos.y);
						map_player.nowpos = map_player.LRcount + 1;
						if (map_player.nowpos == 1 || map_player.nowpos == 2)
							map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
						if (map_player.nowpos == 3)
							map_player.circlepos = D3DXVECTOR2(map[5].pos.x, map[5].pos.y);
						if (map_player.nowpos == 4)
							map_player.circlepos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
			}

			//-----�V�[�g2�̏ꍇ
			if (map_line->randomcode == 2)
			{
				//7�i��
				//18��boss
				if (map_player.nowpos == 18 || map_player.nowpos == 19 || map_player.nowpos == 20)
				{
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.nowpos = 21;
						map_player.nextflag = false;
					}
				}

				//6�i��
				//16��18
				if (map_player.nowpos == 16)
				{
					map_player.circlenowpos = 17;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						map_player.nowpos = 18;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//17��19�A17��20
				if (map_player.nowpos == 17)
				{
					map_player.circlenowpos = map_player.LRcount + 18;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 18].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 18].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 18].pos.x, map[map_player.LRcount + 18].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						if (map_player.LRcount == 0)
							map_player.nowpos = 19;
						if (map_player.LRcount == 1)
							map_player.nowpos = 20;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//5�i��
				//10��16
				if (map_player.nowpos == 10)
				{
					map_player.circlenowpos = 15;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
						map_player.nowpos = 16;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//14��17
				if (map_player.nowpos == 14)
				{
					map_player.circlenowpos = 16;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
						map_player.nowpos = 17;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//15��17
				if (map_player.nowpos == 15)
				{
					map_player.circlenowpos = 16;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
						map_player.nowpos = 17;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//4�i��
				//11��14
				if (map_player.nowpos == 11)
				{
					map_player.circlenowpos = 13;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
						map_player.nowpos = 14;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//12��14�A12��15
				if (map_player.nowpos == 12)
				{
					map_player.circlenowpos = map_player.LRcount + 13;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 13].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 13].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 13].pos.x, map[map_player.LRcount + 13].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
							map_player.nowpos = 14;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
							map_player.nowpos = 15;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//13��15
				if (map_player.nowpos == 13)
				{
					map_player.circlenowpos = 14;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
						map_player.nowpos = 15;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//3�i��
				//�V��10�A7��11
				if (map_player.nowpos == 7)
				{
					map_player.circlenowpos = map_player.LRcount + 9;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 9].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 9].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 9].pos.x, map[map_player.LRcount + 9].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
							map_player.nowpos = 10;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
							map_player.nowpos = 11;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//8��12
				if (map_player.nowpos == 8)
				{
					map_player.circlenowpos = 11;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[11].pos.x, map[11].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
						map_player.nowpos = 12;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//9��12�A9��13
				if (map_player.nowpos == 9)
				{
					map_player.circlenowpos = map_player.LRcount + 11;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 11].pos.x, map[map_player.LRcount + 11].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
							map_player.nowpos = 12;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
							map_player.nowpos = 13;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//2�i��
				//�S��7
				if (map_player.nowpos == 4)
				{
					map_player.circlenowpos = 6;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
						map_player.nowpos = 7;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//5��8
				if (map_player.nowpos == 5)
				{
					map_player.circlenowpos = 7;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[11].pos.x, map[11].pos.y);
						map_player.nowpos = 8;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//6��9
				if (map_player.nowpos == 6)
				{
					map_player.circlenowpos = 8;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[11].pos.x, map[11].pos.y);
						map_player.nowpos = 9;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//1�i��
				//1��4
				if (map_player.nowpos == 1)
				{
					map_player.circlenowpos = 3;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[3].pos.x, map[3].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
						map_player.nowpos = 4;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//2��5�A2��6
				if (map_player.nowpos == 2)
				{
					map_player.circlenowpos = map_player.LRcount + 4;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 4].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 4].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 4].pos.x, map[map_player.LRcount + 4].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
							map_player.nowpos = 5;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
							map_player.nowpos = 6;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//3��6
				if (map_player.nowpos == 3)
				{
					map_player.circlenowpos = 5;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[5].pos.x, map[5].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
						map_player.nowpos = 6;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//0�i��
				if (map_player.nowpos == 0)
				{
					map_player.circlenowpos = map_player.LRcount;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 2)	//�E
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount].pos.x, map[map_player.LRcount].pos.y);
						map_player.nowpos = map_player.LRcount + 1;
						if (map_player.nowpos == 1)
							map_player.circlepos = D3DXVECTOR2(map[3].pos.x, map[3].pos.y);
						if (map_player.nowpos == 2)
							map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
						if (map_player.nowpos == 3)
							map_player.circlepos = D3DXVECTOR2(map[5].pos.x, map[5].pos.y);
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
			}

			//-----�V�[�g3�̏ꍇ
			if (map_line->randomcode == 3)
			{
				//7�i��
				//��boss
				if (map_player.nowpos == 17 || map_player.nowpos == 18)
				{
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.nextflag = false;
						map_player.nowpos = 19;
					}
				}

				//6�i��
				//16��17�A16��17
				if (map_player.nowpos == 16)
				{
					map_player.circlenowpos = map_player.LRcount + 16;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 16].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 16].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 16].pos.x, map[map_player.LRcount + 16].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						if (map_player.LRcount == 0)
							map_player.nowpos = 17;
						if (map_player.LRcount == 1)
							map_player.nowpos = 18;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//5�i��
				//14��16�A15��16
				if (map_player.nowpos == 14 || map_player.nowpos == 15)
				{
					map_player.circlenowpos = 15;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
						map_player.nowpos = 16;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//4�i��
				//11��14�A12��14
				if (map_player.nowpos == 11 || map_player.nowpos == 12)
				{
					map_player.circlenowpos = 13;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
						map_player.nowpos = 14;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//13��15
				if (map_player.nowpos == 13)
				{
					map_player.circlenowpos = 14;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
						map_player.nowpos = 15;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//3�i��
				//8��11�A8��12
				if (map_player.nowpos == 8)
				{
					map_player.circlenowpos = map_player.LRcount + 10;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 10].pos.x, map[map_player.LRcount + 10].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
							map_player.nowpos = 11;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
							map_player.nowpos = 12;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//9��12�A8��13
				if (map_player.nowpos == 9)
				{
					map_player.circlenowpos = map_player.LRcount + 11;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 11].pos.x, map[map_player.LRcount + 11].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
							map_player.nowpos = 12;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
							map_player.nowpos = 13;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//10��13
				if (map_player.nowpos == 10)
				{
					map_player.circlenowpos = 12;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
						map_player.nowpos = 13;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//2�i��
				//5��8
				if (map_player.nowpos == 5)
				{
					map_player.circlenowpos = 7;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
						map_player.nowpos = 8;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//6��9
				if (map_player.nowpos == 6)
				{
					map_player.circlenowpos = 8;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[11].pos.x, map[11].pos.y);
						map_player.nowpos = 9;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//7��10
				if (map_player.nowpos == 7)
				{
					map_player.circlenowpos = 9;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
						map_player.nowpos = 10;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//1�i��
				//1��5
				if (map_player.nowpos == 1 || map_player.nowpos == 2)
				{
					map_player.circlenowpos = 4;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
						map_player.nowpos = 5;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//3��6�A3��7
				if (map_player.nowpos == 3)
				{
					map_player.circlenowpos = map_player.LRcount + 5;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 5].pos.x, map[map_player.LRcount + 5].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
							map_player.nowpos = 6;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
							map_player.nowpos = 7;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//4��7
				if (map_player.nowpos == 4)
				{
					map_player.circlenowpos = 6;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
						map_player.nowpos = 7;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}


				//0�i��
				if (map_player.nowpos == 0)
				{
					map_player.circlenowpos = map_player.LRcount;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 3)	//�E
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount].pos.x, map[map_player.LRcount].pos.y);
						map_player.nowpos = map_player.LRcount + 1;
						if (map_player.nowpos == 1)
							map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
						if (map_player.nowpos == 2)
							map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
						if (map_player.nowpos == 3)
							map_player.circlepos = D3DXVECTOR2(map[5].pos.x, map[5].pos.y);
						if (map_player.nowpos == 4)
							map_player.circlepos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
			}

			//-----�V�[�g4�̏ꍇ
			if (map_line->randomcode == 4)
			{
				//7�i��
				//��boss
				if (map_player.nowpos == 22 || map_player.nowpos == 23 || map_player.nowpos == 24)
				{
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.nowpos = 25;
						map_player.nextflag = false;
					}
				}

				//6�i��
				//18��22
				if (map_player.nowpos == 18)
				{
					map_player.circlenowpos = 21;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[21].pos.x, map[21].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						map_player.nowpos = 22;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//19��23
				if (map_player.nowpos == 19)
				{
					map_player.circlenowpos = 22;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[22].pos.x, map[22].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						map_player.nowpos = 23;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//20��23�A20��24
				if (map_player.nowpos == 20)
				{
					map_player.circlenowpos = map_player.LRcount + 22;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 22].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 22].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 22].pos.x, map[map_player.LRcount + 22].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
							map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
							map_player.nowpos = 23;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
							map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
							map_player.nowpos = 24;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//21��24
				if (map_player.nowpos == 21)
				{
					map_player.circlenowpos = 23;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[23].pos.x, map[23].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						map_player.nowpos = 24;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//5�i��
				//15��18�A15��19
				if (map_player.nowpos == 15)
				{
					map_player.circlenowpos = map_player.LRcount + 17;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 17].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 17].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 17].pos.x, map[map_player.LRcount + 17].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[21].pos.x, map[21].pos.y);
							map_player.nowpos = 18;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[22].pos.x, map[22].pos.y);
							map_player.nowpos = 19;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//16��19�A16��20
				if (map_player.nowpos == 16)
				{
					map_player.circlenowpos = map_player.LRcount + 18;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 18].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 18].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 18].pos.x, map[map_player.LRcount + 18].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[22].pos.x, map[22].pos.y);
							map_player.nowpos = 19;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[22].pos.x, map[22].pos.y);
							map_player.nowpos = 20;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
						}
					}
					//17��20�A17��21
					if (map_player.nowpos == 17)
					{
						map_player.circlenowpos = map_player.LRcount + 19;
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 19].pos.x;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 19].pos.x;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 19].pos.x, map[map_player.LRcount + 19].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[22].pos.x, map[22].pos.y);
								map_player.nowpos = 20;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[23].pos.x, map[23].pos.y);
								map_player.nowpos = 21;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//4�i��
					//11��15
					if (map_player.nowpos == 11)
					{
						map_player.circlenowpos = 14;
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
							map_player.nowpos = 15;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//12��16
					if (map_player.nowpos == 12)
					{
						map_player.circlenowpos = 15;
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
							map_player.nowpos = 16;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//13��16�A13��17
					if (map_player.nowpos == 13)
					{
						map_player.circlenowpos = map_player.LRcount + 15;
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 15].pos.x;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 15].pos.x;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 15].pos.x, map[map_player.LRcount + 15].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
								map_player.nowpos = 16;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[19].pos.x, map[19].pos.y);
								map_player.nowpos = 17;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//14��17
					if (map_player.nowpos == 14)
					{
						map_player.circlenowpos = 16;
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[19].pos.x, map[19].pos.y);
							map_player.nowpos = 17;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

				//3�i��
					//8��11�A8��12
					if (map_player.nowpos == 8)
					{
						map_player.circlenowpos = map_player.LRcount + 10;
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 10].pos.x, map[map_player.LRcount + 10].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
								map_player.nowpos = 11;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
								map_player.nowpos = 12;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//9��13
					if (map_player.nowpos == 9)
					{
						map_player.circlenowpos = 12;
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
							map_player.nowpos = 13;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//10��13�A10��14
					if (map_player.nowpos == 10)
					{
						map_player.circlenowpos = map_player.LRcount + 12;
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 12].pos.x;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 12].pos.x;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 12].pos.x, map[map_player.LRcount + 12].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
								map_player.nowpos = 13;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
								map_player.nowpos = 14;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//2�i��
					//5��8
					if (map_player.nowpos == 5)
					{
						map_player.circlenowpos = 7;

						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
							map_player.nowpos = 8;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//6��8�A6��9
					if (map_player.nowpos == 6)
					{
						map_player.circlenowpos = map_player.LRcount + 7;
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 7].pos.x;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 7].pos.x;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 7].pos.x, map[map_player.LRcount + 7].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
								map_player.nowpos = 8;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
								map_player.nowpos = 9;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//7��9�A7��10
					if (map_player.nowpos == 7)
					{
						map_player.circlenowpos = map_player.LRcount + 8;
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 8].pos.x;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 8].pos.x;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 8].pos.x, map[map_player.LRcount + 8].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
								map_player.nowpos = 9;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
								map_player.nowpos = 10;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//1�i��
					//1��5
					if (map_player.nowpos == 1)
					{
						map_player.circlenowpos = 4;
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
							map_player.nowpos = 5;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//2��5�A2��6
					if (map_player.nowpos == 2)
					{
						map_player.circlenowpos = map_player.LRcount + 4;
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 4].pos.x;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 4].pos.x;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 4].pos.x, map[map_player.LRcount + 4].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
								map_player.nowpos = 5;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
								map_player.nowpos = 6;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//3��6�A3��7
					if (map_player.nowpos == 3)
					{
						map_player.circlenowpos = map_player.LRcount + 5;
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//�E
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 5].pos.x, map[map_player.LRcount + 5].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
								map_player.nowpos = 6;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
								map_player.nowpos = 7;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//4��7
					if (map_player.nowpos == 4)
					{
						map_player.circlenowpos = 6;

						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
							map_player.nowpos = 7;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//0�i��
					if (map_player.nowpos == 0)
					{
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//��
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount].pos.x;
							map_player.circlenowpos = map_player.LRcount;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 3)	//�E
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount].pos.x;
							map_player.circlenowpos = map_player.LRcount;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount].pos.x, map[map_player.LRcount].pos.y);
							map_player.nowpos = map_player.LRcount + 1;
							if (map_player.nowpos == 1)
								map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
							if (map_player.nowpos == 2)
								map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
							if (map_player.nowpos == 3)
								map_player.circlepos = D3DXVECTOR2(map[5].pos.x, map[5].pos.y);
							if (map_player.nowpos == 4)
								map_player.circlepos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

				}
			}
		}

		//�I�������}�X�ɑΉ������V�[���ɔ��
		if (map_player.nowpos < map_player.mapnum + 1)
		{
			if (GetKeyboardTrigger(DIK_RETURN))
			{
				if (map[map_player.nowpos - 1].randomcode == 1)	//�ʏ�G�}�X
				{
					map_player.gamecount = map_player.gamecount + 1;	//�Q�[���V�[���ɓ������񐔂��L�^����
					map_player.encount = (rand() % 3) + 1;	//�����ŏo������G�������_���Ɍ��߂�
					map_player.encount = 2;
					SceneTransition(SCENE_GAME);
				}
				if (map[map_player.nowpos - 1].randomcode == 2)	//���G�}�X
					SceneTransition(SCENE_GAME);
				if (map[map_player.nowpos - 1].randomcode == 3)	//�x�e�}�X
					SceneTransition(SCENE_REST);
				if (map[map_player.nowpos - 1].randomcode == 4)	//�C�x���g�}�X
					SceneTransition(SCENE_EVENT);
				if (map[map_player.nowpos - 1].randomcode == 5)	//���l�}�X
					SceneTransition(SCENE_SHOP);
			}
		}	
	}

}

//-----�`�揈��
void DrawMapPlayer(void)
{
	//�g�̕`��
	DrawSpriteLeftTop(map_player.circletexture, map_player.circlepos.x, map_player.circlepos.y, map_player.circlesize.x, map_player.circlesize.y,
		0.0f, 0.0f, 1.0f, 1.0f);
	//�v���C���[�̕`��
	DrawSpriteLeftTop(map_player.texture, map_player.pos.x, map_player.pos.y, map_player.size.x, map_player.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);
}

MAP_PLAYER* GetMapPlayer()
{
	return &map_player;
}