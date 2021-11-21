//�}�b�v���� [map.cpp]
#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"
#include "map.h"
#include "map_player.h"

//-----�}�N����`
#define map_num 24

//-----�v���g�^�C�v�錾
MAP map[map_num];
MAPSEN mapsen;

//-----�O���[�o���ϐ�
int map_texture;
int mapsen_texture;

//-----����������
HRESULT InitMap(void)
{
	mapsen.pos = D3DXVECTOR2(0.0, 0.0);
	mapsen.size = D3DXVECTOR2(SCREEN_WIDTH, 2000);
	mapsen.u = 0.0f;
	mapsen.v = 0.0f;
	mapsen.uw = 1.0f;
	mapsen.vh = 1.0f;
	mapsen_texture = LoadTexture("data/TEXTURE/mapsen.png");

	for (int i = 0; i < map_num; i++)
	{
		map[i].size = D3DXVECTOR2(40.0f, 40.0f);
		map[i].uw = 0.25f;
		map[i].vh = 0.5f;
	}
	map_texture = LoadTexture("data/TEXTURE/map_point.png");

	//�X�^�[�g�}�X/���F
	map[0].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 - map[0].size.x, 100);
	map[0].u = 0.5f;
	map[0].v = 0.5f;
	//0-0�ʏ�G�}�X/�I�����W
	map[1].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.2 - map[1].size.x, 300);
	map[1].u = 0.0f;
	map[1].v = 0.5f;
	//0-1�ʏ�G�}�X/�I�����W
	map[2].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.4 - map[2].size.x, 300);
	map[2].u = 0.0f;
	map[2].v = 0.5f;
	//0-2�ʏ�G�}�X/�I�����W
	map[3].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.6 - map[3].size.x, 300);
	map[3].u = 0.0f;
	map[3].v = 0.5f;
	//0-3�ʏ�G�}�X/�I�����W
	map[4].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.8 - map[4].size.x, 300);
	map[4].u = 0.0f;
	map[4].v = 0.5f;
	//1-0�ʏ�G�}�X/�I�����W
	map[5].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.3 - map[5].size.x, 500);
	map[5].u = 0.0f;
	map[5].v = 0.5f;
	//1-1�ʏ�G�}�X/�I�����W
	map[6].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 - map[6].size.x, 500);
	map[6].u = 0.0f;
	map[6].v = 0.5f;
	//1-2���G�}�X/��
	map[7].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.7 - map[7].size.x, 500);
	map[7].u = 0.0f;
	map[7].v = 0.0f;
	//2-0���G�}�X/��
	map[8].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.2 - map[8].size.x, 700);
	map[8].u = 0.0f;
	map[8].v = 0.0f;
	//2-1�C�x���g�}�X/��
	map[9].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.4 - map[9].size.x, 700);
	map[9].u = 0.25f;
	map[9].v = 0.0f;
	//2-2�x�e�}�X/��
	map[10].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.9 - map[10].size.x, 700);
	map[10].u = 0.75f;
	map[10].v = 0.0f;
	//3-0�C�x���g�}�X/��
	map[11].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.25 - map[11].size.x, 900);
	map[11].u = 0.25f;
	map[11].v = 0.0f;
	//3-1�C�x���g�}�X/��
	map[12].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 - map[12].size.x, 900);
	map[12].u = 0.25f;
	map[12].v = 0.0f;
	//3-2�C�x���g�}�X/��
	map[13].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.75 - map[13].size.x, 900);
	map[13].u = 0.25f;
	map[13].v = 0.0f;
	//4-0���G�}�X/��
	map[14].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.4 - map[14].size.x, 1100);
	map[14].u = 0.0f;
	map[14].v = 0.0f;
	//4-1���l�}�X/��
	map[15].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.7 - map[15].size.x, 1100);
	map[15].u = 0.5f;
	map[15].v = 0.0f;
	//5-0���G�}�X/��
	map[16].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.1 - map[16].size.x, 1300);
	map[16].u = 0.0f;
	map[16].v = 0.0f;
	//5-1�C�x���g�}�X/��
	map[17].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.4 - map[17].size.x, 1300);
	map[17].u = 0.25f;
	map[17].v = 0.0f;
	//5-2���G�}�X/��
	map[18].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.7 - map[18].size.x, 1300);
	map[18].u = 0.0f;
	map[18].v = 0.0f;
	//5-3�C�x���g�}�X/��
	map[19].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.9 - map[19].size.x, 1300);
	map[19].u = 0.25f;
	map[19].v = 0.0f;
	//6-0�x�e�}�X/��
	map[20].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.2 - map[20].size.x, 1500);
	map[20].u = 0.75f;
	map[20].v = 0.0f;
	//6-1�x�e�}�X/��
	map[21].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 - map[21].size.x, 1500);
	map[21].u = 0.75f;
	map[21].v = 0.0f;
	//6-2���l�}�X/��
	map[22].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.8 - map[22].size.x, 1500);
	map[22].u = 0.5f;
	map[22].v = 0.0f;
	//7-0�{�X�}�X/��
	map[23].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 - map[23].size.x, 1700);
	map[23].u = 0.25f;
	map[23].v = 0.5f;

	return S_OK;
}

//-----�I������
void UninitMap(void)
{

}

//-----�X�V����
void UpdateMap(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	if (GetKeyboardPress(DIK_W))
	{
		for (int i = 0; i < map_num; i++)
			map[i].pos.y += 3;

		mapsen.pos.y += 3;
	}
	if (GetKeyboardPress(DIK_S))
	{
		for (int i = 0; i < map_num; i++)
			map[i].pos.y -= 3;

		mapsen.pos.y -= 3;
	}
}

//-----�`�揈��
void DrawMap(void)
{
	DrawSpriteLeftTop(mapsen_texture, mapsen.pos.x, mapsen.pos.y, mapsen.size.x, mapsen.size.y,
		mapsen.u, mapsen.v, mapsen.uw, mapsen.vh);

	for (int i = 0; i < map_num; i++)
		DrawSpriteLeftTop(map_texture, map[i].pos.x, map[i].pos.y, map[i].size.x, map[i].size.y,
			map[i].u, map[i].v, map[i].uw, map[i].vh);
}

MAP* GetMap(void)
{
	return &map[0];
}