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
	//MAP_POINT* map_point = GetMapPoint();
	////�v���C���[�̓����Ԋu,�����镝�̂��߂�map����ϐ��������Ă���
	//map_player.distance = D3DXVECTOR2(map_point->distance.x, map_point->distance.y);
	//map_player.num = D3DXVECTOR2(map_point->num.x, map_point->num.y);

	//map_player.pos = D3DXVECTOR2(195.0f - 20.0f, 67.5f - 60.0f);
	//map_player.size = D3DXVECTOR2(80.0f, 80.0f);
	//map_player.texture = LoadTexture("data/TEXTURE/map_player.png");

	return S_OK;
}

//-----�I������
void UninitMapPlayer(void)
{

}

//-----�X�V����
void UpdateMapPlayer(void)
{

	//if (GetKeyboardRelease(DIK_D) && map_player.LRcount < map_player.num.x - 1)
	//{
	//	map_player.LRcount = map_player.LRcount + 1;
	//	map_player.pos.x = map_player.pos.x + map_player.distance.x;
	//}

	//if (GetKeyboardRelease(DIK_A) && map_player.LRcount > 0)
	//{
	//	map_player.LRcount = map_player.LRcount - 1;
	//	map_player.pos.x = map_player.pos.x - map_player.distance.x;
	//}

	//if (GetKeyboardTrigger(DIK_S) && map_player.UDcount < map_player.num.y - 1)
	//{
	//	map_player.UDcount = map_player.UDcount + 1;
	//	map_player.pos.y = map_player.pos.y + map_player.distance.y;
	//}

	//if (GetKeyboardTrigger(DIK_W) && map_player.UDcount > 0)
	//{
	//	map_player.UDcount = map_player.UDcount - 1;
	//	map_player.pos.y = map_player.pos.y - map_player.distance.y;
	//}
}

//-----�`�揈��
void DrawMapPlayer(void)
{
	//DrawSpriteLeftTop(map_player.texture, map_player.pos.x, map_player.pos.y, map_player.size.x, map_player.size.y, 
	//	0.0f, 0.0f, 1.0f, 1.0f);
}

MAP_PLAYER* GetMapPlayer()
{
	return &map_player;
}