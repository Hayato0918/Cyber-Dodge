//�}�b�v���� [map.cpp]
#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "map_player.h"

//-----�}�N����`
#define map_x 4
#define map_y 4
#define mapdistance_x 190	//�}�X�̍��E�Ԋu
#define mapdistance_y 135	//�}�X�̏㉺�Ԋu

//-----�v���g�^�C�v�錾
MAP_POINT map_point;
MAP map[map_x][map_y];

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitMap(void)
{
	map_point.num = D3DXVECTOR2(map_x, map_y);
	map_point.distance = D3DXVECTOR2(mapdistance_x, mapdistance_y);

	for (int i = 0; i < map_point.num.y; i++)
	{
		for (int j = 0; j < map_point.num.x; j++)
		{
			map[j][i].pos = D3DXVECTOR2(195.0f + map_point.distance.x * j, 67.5f + map_point.distance.y * i);
			map[j][i].size = D3DXVECTOR2(40.0f, 40.0f);
			map[j][i].texture = LoadTexture("data/TEXTURE/map_point.png");
			map[j][i].u = 0.0f;
			map[j][i].v = 0.0f;
			map[j][i].uw = 0.25f;
			map[j][i].vh = 0.5f;

		}
	}

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

	//������2�Ԗڏォ��1�Ԗڂ̃}�X�ɍs������
	if (map_player->LRcount == 1 && map_player->UDcount == 0)
		//�o�g���V�[���ɐi��
		SceneTransition(SCENE_GAME);

	//-----�Q�[����ʂɖ߂鏈��
	if (GetKeyboardTrigger(DIK_M))
		SceneTransition(SCENE_GAME);
}

//-----�`�揈��
void DrawMap(void)
{
	for (int i = 0; i < map_y; i++)
	{
		for (int j = 0; j < map_x; j++)
			DrawSpriteLeftTop(map[j][i].texture, map[j][i].pos.x, map[j][i].pos.y, map[j][i].size.x, map[j][i].size.y,
				map[j][i].u, map[j][i].v, map[j][i].uw, map[j][i].vh);
	}
}

//-----�\���̃|�C���^�擾����
MAP_POINT* GetMapPoint()
{
	return &map_point;
}