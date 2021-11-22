//�}�b�v�ړ����� [map_player.cpp]
#include "map_player.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "map.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
MAP_PLAYER map_player;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitMapPlayer(void)
{
	MAP* map = GetMap();
	map_player.size = D3DXVECTOR2(80.0f, 80.0f);
	map_player.pos = D3DXVECTOR2(map[0].pos.x - map[0].size.x * 0.5, map[0].pos.y - map_player.size.y + map[0].size.y * 0.5);
	map_player.texture = LoadTexture("data/TEXTURE/map_player.png");
	map_player.LRcount = 0;
	map_player.UDcount = 0;
	map_player.move = false;
	map_player.moveflag = false;
	map_player.movespeedflag = false;

	map_player.circlepos = D3DXVECTOR2(map[1].pos.x, map[1].pos.y);
	map_player.circlesize = D3DXVECTOR2(40.0f, 40.0f);
	map_player.circletexture = LoadTexture("data/TEXTURE/circle.png");

	map_player.x = 0.0f;
	map_player.y = 0.0f;

	map_player.movespeedflag = false;

	return S_OK;
}

//-----�I������
void UninitMapPlayer(void)
{

}

//-----�X�V����
void UpdateMapPlayer(void)
{
	MAP* map = GetMap();

	//1�i�ڂ̑I��
	if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 3 && map_player.UDcount == 0 && map_player.move == false)
	{
		map_player.LRcount = map_player.LRcount + 1;
		map_player.circlepos.x = map_player.circlepos.x + SCREEN_WIDTH * 0.2;
	}
	if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0 && map_player.UDcount == 0 && map_player.move == false)
	{
		map_player.LRcount = map_player.LRcount - 1;
		map_player.circlepos.x = map_player.circlepos.x - SCREEN_WIDTH * 0.2;
	}
	//2�i�ڂ̑I��
	if (map_player.UDcount == 1 && map_player.LRcount == 0)		//1�i�ڂ�map[1]��I�������ꍇ
	{
		map_player.circlepos.x = map[5].pos.x;
		map_player.circlepos.y = map[5].pos.y;
	}
	if (map_player.UDcount == 1 && map_player.LRcount == 1)		//1�i�ڂ�map[2]��I�������ꍇ
	{
		map_player.circlepos.x = map[5].pos.x;
		map_player.circlepos.y = map[5].pos.y;
	}
	if (map_player.UDcount == 1 && map_player.LRcount == 2)		//1�i�ڂ�map[3]��I�������ꍇ
	{
		if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 2 && map_player.move == false)
		{
			map_player.LRcount = map_player.LRcount + 1;
			map_player.circlepos.x = map_player.circlepos.x + SCREEN_WIDTH * 0.2;
		}
		if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0 && map_player.move == false)
		{
			map_player.LRcount = map_player.LRcount - 1;
			map_player.circlepos.x = map_player.circlepos.x - SCREEN_WIDTH * 0.2;
		}
		//map_player.circlepos.x = map[6].pos.x;
		//map_player.circlepos.y = map[6].pos.y;
	}


	//-----�ړ���̌���
	if (GetKeyboardTrigger(DIK_RETURN))
		map_player.move = true;
	if (map_player.move == true)
	{
		for (int i = 0; i < 4; i++)
		{
			//1�i��
			if (map_player.UDcount == 0 && map_player.LRcount == i && map_player.movespeedflag == false)
			{
				map_player.x = (map[i + 1].pos.x - map_player.pos.x - map[i + 1].size.x * 0.5) * 0.01;
				map_player.y = (map[i + 1].pos.y - map_player.pos.y - map_player.size.y + map[i + 1].size.y * 0.5) * 0.01;
				map_player.movespeedflag == true;
			}
			//2�i��
			if (map_player.UDcount == 1 && map_player.LRcount == 0 && map_player.movespeedflag == false)
			{
				map_player.x = (map[5].pos.x - map_player.pos.x - map[5].size.x * 0.5) * 0.01;
				map_player.y = (map[5].pos.y - map_player.pos.y - map_player.size.y + map[5].size.y * 0.5) * 0.01;
				map_player.movespeedflag == true;
			}
			if (map_player.UDcount == 1 && map_player.LRcount == 2 && map_player.movespeedflag == false)
			{
				map_player.x = (map[5].pos.x - map_player.pos.x - map[5].size.x * 0.5) * 0.01;
				map_player.y = (map[5].pos.y - map_player.pos.y - map_player.size.y + map[5].size.y * 0.5) * 0.01;
				map_player.movespeedflag == true;
			}
		}
		map_player.pos.x += map_player.x;
		map_player.pos.y += map_player.y;
	}

	//-----�v���C���[���}�X�ɓ���������AUDcount��+1����
	for (int i = 1; i < 25; i++)
	{
		if (map_player.pos.x + map_player.size.x > map[i].pos.x && map_player.pos.x < map[i].pos.x + map[i].size.x)
		{
			if (map_player.pos.y + map_player.size.y > map[i].pos.y && map_player.pos.y + map_player.size.y * 0.7f < map[i].pos.y + map[i].size.y)
			{
				if (map_player.moveflag == true)
				{
					map_player.pos = D3DXVECTOR2(map[i].pos.x - map[i].size.x * 0.5, map[i].pos.y - map_player.size.y + map[i].size.y * 0.5);
					map_player.LRcount = 0;
					map_player.UDcount = map_player.UDcount + 1;
					map_player.movespeedflag = false;
					map_player.move = false;
					map_player.moveflag = false;
				}
			}
		}
	}

	if (GetKeyboardTrigger(DIK_0))
	{
		map_player.moveflag = true;
	}
}

//-----�`�揈��
void DrawMapPlayer(void)
{
	DrawSpriteLeftTop(map_player.circletexture, map_player.circlepos.x, map_player.circlepos.y, map_player.circlesize.x, map_player.circlesize.y,
		0.0f, 0.0f, 1.0f, 1.0f);

	DrawSpriteLeftTop(map_player.texture, map_player.pos.x, map_player.pos.y, map_player.size.x, map_player.size.y, 
		0.0f, 0.0f, 1.0f, 1.0f);
}

MAP_PLAYER* GetMapPlayer()
{
	return &map_player;
}

