//�}�b�v���� [map.cpp]
#include <stdlib.h>
#include <time.h>

#include "map_point.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "map_hack.h"

//-----�}�N����`
#define map_xnum 4
#define map_ynum 7

//-----�v���g�^�C�v�錾
MAP map[map_ynum][map_xnum];
MAP_PLAYER map_player;
MAP_SB map_sb;

//-----�O���[�o���ϐ�
int map_texture;	//�}�X�̃e�N�X�`����ݒ肷��ϐ�

float map_x;	//�}�X��x���W�������_���ɂ��邽�߂̕ϐ�
float map_y;	//�}�X��y���W�������_���ɂ��邽�߂̕ϐ�
int mapcount;	

//-----����������
HRESULT InitMapPoint(void)
{
	if (map_player.UDcount == 0)	//��񂾂��Ă�
	{
		map_y = 300;
		//�}�X��x���W�������_���ɂ���
		map_x = ((rand() % 2) + 2) * 0.1f;
		mapcount = 0;

		map_texture = LoadTexture("data/TEXTURE/map_point.png");

		for (int y = 0; y < map_ynum; y++)
		{
			for (int x = 0; x < map_xnum; x++)
			{
				map[y][x].size = D3DXVECTOR2(80.0f, 80.0f);
				map[y][x].uw = 0.166f;
				map[y][x].v = 0.0f;
				map[y][x].vh = 1.0f;

				//�}�X�̐F�������_���ɂ���
				map[y][x].randomcode = (rand() % 5) + 1;
				switch (map[y][x].randomcode)
				{
				case 1:		//�I�����W(�ʏ�G�}�X)
					map[y][x].u = 0.0f;
					break;
				case 2:		//��(���G�܂�)
					map[y][x].u = 0.166f;
					break;
				case 3:		//��(�x�e�}�X)
					map[y][x].u = 0.498f;
					break;
				case 4:		//��(�C�x���g�}�X)
					map[y][x].u = 0.664f;
					break;
				case 5:		//���F(���l�}�X)
					map[y][x].u = 0.83f;
					break;
				}
			}
		}

		for (int y = 0; y < map_ynum; y++)
		{
			for (int x = 0; x < map_xnum; x++)
			{
				map[y][x].pos = D3DXVECTOR2(SCREEN_WIDTH * map_x - map[y][x].size.x, map_y);
				map_x = map_x + ((rand() % 2) + 1) * 0.1f;
				mapcount = mapcount + 1;
				//�ua�̒l������������A���̃C�x���g�𑽂��o���v�Ƃ����ł���
				if (mapcount > 2 && mapcount < 4)
				{
					map[y][x].randomcode = (rand() % 2);
					if (map[y][x].randomcode == 1)
					{
						x = x + 1;
						map_y = map_y + 200;
						map_x = ((rand() % 2) + 2) * 0.1f;
						mapcount = 0;
					}
				}
				if (mapcount >= 4)
				{
					x = x + 1;
					map_y = map_y + 200;
					map_x = ((rand() % 2) + 2) * 0.1f;
					mapcount = 0;
				}

				if (map_y >= 1700)	//�{�X�}�X��y���W�܂ł��ǂ蒅������A����ȍ~�̃}�X������
				{
					map_y = 0;
				}
			}
		}

		//�X�^�[�g�}�X
		map_sb.startsize = D3DXVECTOR2(80, 80);
		map_sb.startpos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f - map_sb.startsize.x, 100);
		//�{�X�}�X
		map_sb.bosssize = D3DXVECTOR2(120, 120);
		map_sb.bosspos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f - map_sb.bosssize.x, 1700);
	}

	return S_OK;
}

//-----�I������
void UninitMapPoint(void)
{

}

//-----�X�V����
void UpdateMapPoint(void)
{
	srand((unsigned int)time(NULL));

	MAP_HACK* map_hack = GetMapHack();

	//�}�X���n�b�L���O���āA�C�ӂ̃}�X�ɕς���
	if (map_hack->isUse == true)
	{
		if (PADUSE == 0)
		{
			if (IsButtonTriggered(0, BUTTON_X))
			{
				if (map_hack->UDcount == 0)		//�ʏ�G�}�X
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 1;
					map[map_player.UDcount][map_player.LRcount].u = 0.0f;
				}
				if (map_hack->UDcount == 1)		//���G�}�X
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 2;
					map[map_player.UDcount][map_player.LRcount].u = 0.166f;
				}
				if (map_hack->UDcount == 2)		//�x�e�}�X
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 3;
					map[map_player.UDcount][map_player.LRcount].u = 0.498f;
				}
				if (map_hack->UDcount == 3)		//�C�x���g�}�X
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 4;
					map[map_player.UDcount][map_player.LRcount].u = 0.664f;
				}
				if (map_hack->UDcount == 4)		//���l�}�X
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 5;
					map[map_player.UDcount][map_player.LRcount].u = 0.83f;
				}
			}
		}
		if (PADUSE == 1)
		{
			if (GetKeyboardTrigger(DIK_RETURN))
			{
				if (map_hack->UDcount == 0)		//�ʏ�G�}�X
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 1;
					map[map_player.UDcount][map_player.LRcount].u = 0.0f;
				}
				if (map_hack->UDcount == 1)		//���G�}�X
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 2;
					map[map_player.UDcount][map_player.LRcount].u = 0.166f;
				}
				if (map_hack->UDcount == 2)		//�x�e�}�X
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 3;
					map[map_player.UDcount][map_player.LRcount].u = 0.498f;
				}
				if (map_hack->UDcount == 3)		//�C�x���g�}�X
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 4;
					map[map_player.UDcount][map_player.LRcount].u = 0.664f;
				}
				if (map_hack->UDcount == 4)		//���l�}�X
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 5;
					map[map_player.UDcount][map_player.LRcount].u = 0.83f;
				}
			}
		}
	}

	//�}�b�v�X�N���[��
	if (map_hack->isUse == false)
	{
		if (PADUSE == 1)
		{
			if (GetKeyboardPress(DIK_W))
			{
				map_sb.startpos.y += 3;
				map_sb.bosspos.y += 3;

				for (int y = 0; y < map_ynum; y++)
				{
					for (int x = 0; x < map_xnum; x++)
						map[y][x].pos.y += 3;
				}
			}
			if (GetKeyboardPress(DIK_S))
			{
				map_sb.startpos.y -= 3;
				map_sb.bosspos.y -= 3;

				for (int y = 0; y < map_ynum; y++)
				{
					for (int x = 0; x < map_xnum; x++)
						map[y][x].pos.y -= 3;
				}
			}
		}
		if (PADUSE == 0)
		{
			if (IsButtonPressed(0, BUTTON_UP))
			{
				map_sb.startpos.y += 3;
				map_sb.bosspos.y += 3;

				for (int y = 0; y < map_ynum; y++)
				{
					for (int x = 0; x < map_xnum; x++)
						map[y][x].pos.y += 3;
				}
			}
			if (IsButtonPressed(0, BUTTON_DOWN))
			{
				map_sb.startpos.y -= 3;
				map_sb.bosspos.y -= 3;

				for (int y = 0; y < map_ynum; y++)
				{
					for (int x = 0; x < map_xnum; x++)
						map[y][x].pos.y -= 3;
				}
			}
		}
	}
}

//-----�`�揈��
void DrawMapPoint(void)
{
	//�X�^�[�g�}�X�̕`��
	DrawSpriteLeftTop(map_texture, map_sb.startpos.x, map_sb.startpos.y, map_sb.startsize.x, map_sb.startsize.y, 0.664f, 0.0f, 0.166f, 1.0f);
	//�{�X�}�X�̕`��
	DrawSpriteLeftTop(map_texture, map_sb.bosspos.x, map_sb.bosspos.y, map_sb.bosssize.x, map_sb.bosssize.y, 0.332f, 0.0f, 0.166f, 1.0f);

	for (int y = 0; y < map_ynum; y++)
	{
		for (int x = 0; x < map_xnum; x++)
		{
			if(map[y][x].pos.x > 0)
			DrawSpriteLeftTop(map_texture, map[y][x].pos.x, map[y][x].pos.y, map[y][x].size.x, map[y][x].size.y,
				map[y][x].u, map[y][x].v, map[y][x].uw, map[y][x].vh);
		}
	}
}

//-----------------------------------------------//
//--------------|�v���C���[�̐ݒ�|--------------//
//---------------------------------------------//

//-----����������
HRESULT InitMapPlayer(void)
{
	if (map_player.UDcount == 0)
	{
		//�v���C���[�̏�����
		map_player.size = D3DXVECTOR2(80.0f, 80.0f);
		map_player.pos = D3DXVECTOR2(map_sb.startpos.x, map_sb.startpos.y - map_player.size.y * 0.5f);
		map_player.texture = LoadTexture("data/TEXTURE/map_player.png");
		map_player.LRcount = 0;
		map_player.UDcount = 0;

		//�I���̘g�̏�����
		map_player.circlepos = D3DXVECTOR2(map[0][0].pos.x, map[0][0].pos.y);
		map_player.circlesize = D3DXVECTOR2(80.0f, 80.0f);
		map_player.circletexture = LoadTexture("data/TEXTURE/circle.png");

		map_player.gamecount = 0;
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

	//�}�b�v�X�N���[��
	if (map_hack->isUse == false)
	{
		if (PADUSE == 0)
		{
			if (IsButtonPressed(0, BUTTON_UP))	//��
			{
				map_player.pos.y += 3;
				map_player.circlepos.y += 3;
			}
			if (IsButtonPressed(0, BUTTON_DOWN))	//��
			{
				map_player.pos.y -= 3;
				map_player.circlepos.y -= 3;
			}
			//1���̃}�X�ɃJ�[�\�������킹��
			if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0 && map_player.UDcount < 7)
			{
				map_player.LRcount = map_player.LRcount - 1;
				map_player.circlepos.x = map[map_player.UDcount][map_player.LRcount].pos.x;
			}
			//1�E�̃}�X�ɃJ�[�\�������킹��
			if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.circlepos.x < map[map_player.UDcount][map_player.LRcount + 1].pos.x && map_player.UDcount < 7)
			{
				map_player.LRcount = map_player.LRcount + 1;
				map_player.circlepos.x = map[map_player.UDcount][map_player.LRcount].pos.x;
			}
			//�J�[�\�������킹���}�X�Ƀv���C���[�𓮂���
			if (IsButtonTriggered(0, BUTTON_X) && map_player.UDcount < 8)
			{
				//�I�������}�X�܂Ńv���C���[���ړ�������
				if (map_player.UDcount < 7)		//�{�X�O�܂�
				{
					map_player.pos.x = map[map_player.UDcount][map_player.LRcount].pos.x;
					map_player.pos.y = map_player.pos.y + 200;
				}
				if (map_player.UDcount == 7)	//�{�X�}�X
					map_player.pos = D3DXVECTOR2(map_sb.bosspos.x + map_player.size.x * 0.25f, map_sb.bosspos.y);

				//�I�������}�X�ɑΉ������V�[���ɔ��
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 1)	//�ʏ�G�}�X
				{
					map_player.gamecount = map_player.gamecount + 1;
					SceneTransition(SCENE_GAME);
				}
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 2)	//���G�}�X
				{
					map_player.gamecount = map_player.gamecount + 1;
					SceneTransition(SCENE_GAME);
				}
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 3)	//�x�e�}�X
					SceneTransition(SCENE_REST);
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 4)	//�C�x���g�}�X
					SceneTransition(SCENE_EVENT);
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 5)	//���l�}�X
					SceneTransition(SCENE_SHOP);

				map_player.LRcount = 0;
				map_player.UDcount = map_player.UDcount + 1;

				//���̑I�����܂ŃJ�[�\�����ړ�������
				if (map_player.UDcount < 7)		//�{�X�O�܂�
				{
					map_player.circlepos.x = map[map_player.UDcount][map_player.LRcount].pos.x;
					map_player.circlepos.y = map[map_player.UDcount][map_player.LRcount].pos.y;
				}
				if (map_player.UDcount == 7)	//�{�X�}�X
				{
					map_player.circlepos = D3DXVECTOR2(map_sb.bosspos.x, map_sb.bosspos.y);
					map_player.circlesize = D3DXVECTOR2(map_sb.bosssize.x, map_sb.bosssize.y);
				}
			}
		}
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
			//1���̃}�X�ɃJ�[�\�������킹��
			if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0 && map_player.UDcount < 7)
			{
				map_player.LRcount = map_player.LRcount - 1;
				map_player.circlepos.x = map[map_player.UDcount][map_player.LRcount].pos.x;
			}
			//1�E�̃}�X�ɃJ�[�\�������킹��
			if (GetKeyboardTrigger(DIK_D) && map_player.circlepos.x < map[map_player.UDcount][map_player.LRcount + 1].pos.x && map_player.UDcount < 7)
			{
				map_player.LRcount = map_player.LRcount + 1;
				map_player.circlepos.x = map[map_player.UDcount][map_player.LRcount].pos.x;
			}
			//�J�[�\�������킹���}�X�Ƀv���C���[�𓮂���
			if (GetKeyboardTrigger(DIK_RETURN) && map_player.UDcount < 8)
			{
				//�I�������}�X�܂Ńv���C���[���ړ�������
				if (map_player.UDcount < 7)		//�{�X�O�܂�
				{
					map_player.pos.x = map[map_player.UDcount][map_player.LRcount].pos.x;
					map_player.pos.y = map_player.pos.y + 200;
				}
				if (map_player.UDcount == 7)	//�{�X�}�X
					map_player.pos = D3DXVECTOR2(map_sb.bosspos.x + map_player.size.x * 0.25f, map_sb.bosspos.y);

				//�I�������}�X�ɑΉ������V�[���ɔ��
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 1)	//�ʏ�G�}�X
				{
					map_player.gamecount = map_player.gamecount + 1;
					SceneTransition(SCENE_GAME);
				}
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 2)	//���G�}�X
					SceneTransition(SCENE_GAME);
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 3)	//�x�e�}�X
					SceneTransition(SCENE_REST);
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 4)	//�C�x���g�}�X
					SceneTransition(SCENE_EVENT);
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 5)	//���l�}�X
					SceneTransition(SCENE_SHOP);

				map_player.LRcount = 0;
				map_player.UDcount = map_player.UDcount + 1;

				//���̑I�����܂ŃJ�[�\�����ړ�������
				if (map_player.UDcount < 7)		//�{�X�O�܂�
				{
					map_player.circlepos.x = map[map_player.UDcount][map_player.LRcount].pos.x;
					map_player.circlepos.y = map[map_player.UDcount][map_player.LRcount].pos.y;
				}
				if (map_player.UDcount == 7)	//�{�X�}�X
				{
					map_player.circlepos = D3DXVECTOR2(map_sb.bosspos.x, map_sb.bosspos.y);
					map_player.circlesize = D3DXVECTOR2(map_sb.bosssize.x, map_sb.bosssize.y);
				}
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

//-----�\���̃|�C���^�擾
MAP_PLAYER* GetMapPlayer()
{
	return &map_player;
}