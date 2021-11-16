//�}�b�v���� [map.cpp]
#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "map_player.h"

//-----�}�N����`
#define map_num 24

//-----�v���g�^�C�v�錾
MAP map[map_num];

//-----�O���[�o���ϐ�
int map_texture;

//-----����������
HRESULT InitMap(void)
{
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
	map[9].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.2 - map[9].size.x, 700);
	map[9].u = 0.0f;
	map[9].v = 0.0f;











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
	}
	if (GetKeyboardPress(DIK_S))
	{
		for (int i = 0; i < map_num; i++)
			map[i].pos.y -= 3;
	}



	////������2�Ԗڏォ��1�Ԗڂ̃}�X�ɍs������
	//if (map_player->LRcount == 1 && map_player->UDcount == 0)
	//	//�o�g���V�[���ɐi��
	//	SceneTransition(SCENE_GAME);

	////-----�Q�[����ʂɖ߂鏈��
	//if (GetKeyboardTrigger(DIK_M))
	//	SceneTransition(SCENE_GAME);
}

//-----�`�揈��
void DrawMap(void)
{
	for (int i = 0; i < map_num; i++)
		DrawSpriteLeftTop(map_texture, map[i].pos.x, map[i].pos.y, map[i].size.x, map[i].size.y,
			map[i].u, map[i].v, map[i].uw, map[i].vh);
}

//-----�\���̃|�C���^�擾����
MAP* GetMap()
{
	return &map[0];
}