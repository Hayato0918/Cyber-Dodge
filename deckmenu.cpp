//�f�b�L���j���[���� [deckmenu.cpp]
#include "deckmenu.h"
//�V�X�e��.h
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "map_player.h"
#include "skillrandom.h"

//-----�}�N����`

#define CARD_SPACE_WIDTH 300.0f
#define CARD_SPACE_HIGHT 300.0f
#define ynum 12
#define xnum 3

//-----�v���g�^�C�v�錾
DECKMENUCARD deckmenu_card[ynum][xnum];
DECKMENU deckmenu;
SELECTION g_Selection;
NUMBER g_number;

//-----�O���[�o���ϐ�
int a, b;
int deckmenutexture;

//-----����������
HRESULT InitDeckMenu(void)
{
	deckmenutexture = LoadTexture("data/TEXTURE/skill/skill.png");

	a = 0;
	b = 0;

	MAP_PLAYER* map_player = GetMapPlayer();

	for (int y = 0; y < ynum; y++)
	{
		for (int x = 0; x < xnum; x++)
		{
			deckmenu_card[y][x].pos = D3DXVECTOR2(120.0f + CARD_SPACE_WIDTH * x, 120.0f + CARD_SPACE_HIGHT * y + CARD_SPACE_HIGHT * y * 0.3f);
			deckmenu_card[y][x].size = D3DXVECTOR2(200.0f, 300.0f);
			deckmenu_card[y][x].drawflag = false;
			deckmenu_card[y][x].nottexture = LoadTexture("data/TEXTURE/deckmenu/notget.png");
		}
	}

	RANDOM* random = GetRandom();
	SKILL* skill = GetSkill();

	for (int i = 0; i < skill->slot; i++)
	{
		if (b == xnum)
		{
			a = a + 1;
			b = 0;
		}


		//���蓖�Ă�ꂽcode�ɑΉ������e�N�X�`����\��
		for (int j = 1; j < 27; j++)
		{
			if (random[i].code == j)
			{
				deckmenu_card[a][b].u = 0.0384615385f * (j - 1);
				deckmenu_card[a][b].drawflag = true;
			}
		}

		b = b + 1;
	}

	deckmenu.pos = D3DXVECTOR2(0.0f, 0.0f);
	deckmenu.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	deckmenu.texture = LoadTexture("data/TEXTURE/deckmenu/bg.png");
	deckmenu.use = false;
	deckmenu.openflag = false;

	g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x, deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
	g_Selection.size = D3DXVECTOR2(200.0f, 300.0f);
	g_Selection.texture = LoadTexture("data/TEXTURE/deckmenu/frame.png");
	g_Selection.use = true;
	g_Selection.LRcount = 0;
	g_Selection.UDcount = 0;

	g_number.pos = D3DXVECTOR2(1415.f, 115.0f);
	g_number.size = D3DXVECTOR2(60.0f, 60.0f);
	g_number.texture = LoadTexture("data/TEXTURE/number.png");
	g_number.u = 0.2f;
	g_number.v = 0.0f;
	g_number.uw = 0.2f;
	g_number.vh = 0.5f;

	return S_OK;
}

//-----�I������
void UninitDeckMenu(void)
{

}

//-----�X�V����
void UpdateDeckMenu(void)
{
	// �y�[�W���؂�ւ�����
	if (g_Selection.UDcount == 0)
	{
		g_number.u = 0.2f;
		g_number.v = 0.0f;
	}
	if (g_Selection.UDcount == 2)
	{
		g_number.u = 0.4f;
		g_number.v = 0.0f;
	}
	if (g_Selection.UDcount == 4)
	{
		g_number.u = 0.6f;
		g_number.v = 0.0f;
	}
	if (g_Selection.UDcount == 6)
	{
		g_number.u = 0.8f;
		g_number.v = 0.0f;
	}
	if (g_Selection.UDcount == 8)
	{
		g_number.u = 0.0f;
		g_number.v = 0.5f;
	}
	if (g_Selection.UDcount == 10)
	{
		g_number.u = 0.2f;
		g_number.v = 0.5f;
	}
	if (g_Selection.UDcount == 12)
	{
		g_number.u = 0.4f;
		g_number.v = 0.5f;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_RIGHT) && g_Selection.LRcount >= xnum - 1 && g_Selection.use == true)
		{
			g_Selection.pos = D3DXVECTOR2(1100.f, 690.f);
			g_Selection.size = D3DXVECTOR2(460.f, 170.f);
		}

		//�E�ړ�
		if (IsButtonTriggered(0, BUTTON_RIGHT) && g_Selection.LRcount < xnum - 1 && g_Selection.use == true)
		{
			g_Selection.LRcount = g_Selection.LRcount + 1;
			g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
		}
		//���ړ�
		if (IsButtonTriggered(0, BUTTON_LEFT) && g_Selection.LRcount > 0 && g_Selection.use == true)
		{
			g_Selection.LRcount = g_Selection.LRcount - 1;
			g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
			g_Selection.size = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].size.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].size.y);
		}
		//���ړ�
		if (IsButtonTriggered(0, BUTTON_DOWN) && g_Selection.UDcount < ynum - 1 && g_Selection.use == true)
		{
			g_Selection.UDcount = g_Selection.UDcount + 1;
			//2�i����؂�ɁA�J�[�h�̈ʒu���ړ�
			if (g_Selection.UDcount == 2 || g_Selection.UDcount == 4 || g_Selection.UDcount == 6 || g_Selection.UDcount == 8 || g_Selection.UDcount == 10 || g_Selection.UDcount == 12)
			{
				for (int y = 0; y < ynum; y++)
				{
					for (int x = 0; x < xnum; x++)
						deckmenu_card[y][x].pos.y = deckmenu_card[y][x].pos.y - 360.0f - CARD_SPACE_HIGHT * 2 + CARD_SPACE_HIGHT * 2 * 0.3f;
				}
			}
			g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
		}

		if (IsButtonTriggered(0, BUTTON_UP) && g_Selection.UDcount > 0 && g_Selection.use == true)
		{
			g_Selection.UDcount = g_Selection.UDcount - 1;
			//2�i����؂�ɁA�J�[�h�̈ʒu���ړ�
			if (g_Selection.UDcount == 1 || g_Selection.UDcount == 3 || g_Selection.UDcount == 5 || g_Selection.UDcount == 7
				|| g_Selection.UDcount == 9 || g_Selection.UDcount == 11)
			{
				for (int y = 0; y < ynum; y++)
				{
					for (int x = 0; x < xnum; x++)
						deckmenu_card[y][x].pos.y = deckmenu_card[y][x].pos.y + 360.0f + CARD_SPACE_HIGHT * 2 - CARD_SPACE_HIGHT * 2 * 0.3f;
				}
			}
			g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
		}

		//�u��������v�R�}���h�̏ꏊ��Enter�L�[����������MAP�ɖ߂�
		if (IsButtonTriggered(0, BUTTON_Y) && g_Selection.pos == D3DXVECTOR2(1100.f, 690.f))
		{
			deckmenu.openflag = true;
			SceneTransition(SCENE_MAP);
			deckmenu.use = false;
		}
	}

	if (PADUSE == 1)
	{
		//�E�ړ�
		if (GetKeyboardRelease(DIK_D) && g_Selection.LRcount < xnum - 1 && g_Selection.use == true)
		{
			g_Selection.LRcount = g_Selection.LRcount + 1;
			g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
		}
		//���ړ�
		if (GetKeyboardRelease(DIK_A) && g_Selection.LRcount > 0 && g_Selection.use == true)
		{
			g_Selection.LRcount = g_Selection.LRcount - 1;
			g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
		}
		//���ړ�
		if (GetKeyboardTrigger(DIK_S) && g_Selection.UDcount < ynum - 1 && g_Selection.use == true)
		{
			g_Selection.UDcount = g_Selection.UDcount + 1;
			//2�i����؂�ɁA�J�[�h�̈ʒu���ړ�
			if (g_Selection.UDcount == 2 || g_Selection.UDcount == 4 || g_Selection.UDcount == 6 || g_Selection.UDcount == 8 || g_Selection.UDcount == 10 || g_Selection.UDcount == 12)
			{
				for (int y = 0; y < ynum; y++)
				{
					for (int x = 0; x < xnum; x++)
						deckmenu_card[y][x].pos.y = deckmenu_card[y][x].pos.y - 360.0f - CARD_SPACE_HIGHT * 2 + CARD_SPACE_HIGHT * 2 * 0.3f;
				}
			}
			g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
		}

		if (GetKeyboardTrigger(DIK_W) && g_Selection.UDcount > 0 && g_Selection.use == true)
		{
			g_Selection.UDcount = g_Selection.UDcount - 1;
			//2�i����؂�ɁA�J�[�h�̈ʒu���ړ�
			if (g_Selection.UDcount == 1 || g_Selection.UDcount == 3 || g_Selection.UDcount == 5 || g_Selection.UDcount == 7
				|| g_Selection.UDcount == 9 || g_Selection.UDcount == 11)
			{
				for (int y = 0; y < ynum; y++)
				{
					for (int x = 0; x < xnum; x++)
						deckmenu_card[y][x].pos.y = deckmenu_card[y][x].pos.y + 360.0f + CARD_SPACE_HIGHT * 2 - CARD_SPACE_HIGHT * 2 * 0.3f;
				}
			}
			g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
		}

		//�u��������v�R�}���h�̏ꏊ��Enter�L�[����������MAP�ɖ߂�
		if (GetKeyboardTrigger(DIK_RETURN) && g_Selection.pos == D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
			deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y))
		{
			deckmenu.openflag = true;
			SceneTransition(SCENE_MAP);
			deckmenu.use = false;
		}
	}
}

//-----�`�揈��
void DrawDeckMenu(void)
{
	//���j���[�w�i�̕`��
	DrawSpriteLeftTop(deckmenu.texture, deckmenu.pos.x, deckmenu.pos.y, deckmenu.size.x, deckmenu.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	//�X�L���J�[�h�`��
	for (int y = 0; y < ynum; y++)
	{
		for (int x = 0; x < xnum; x++)
		{
			if(deckmenu_card[y][x].drawflag == true)
			DrawSpriteLeftTop(deckmenutexture, deckmenu_card[y][x].pos.x, deckmenu_card[y][x].pos.y,
				deckmenu_card[y][x].size.x, deckmenu_card[x][y].size.y, deckmenu_card[x][y].u, 0.0f, 0.0384615385f, 1.0f);

			if (deckmenu_card[y][x].drawflag == false)
				DrawSpriteLeftTop(deckmenu_card[y][x].nottexture, deckmenu_card[y][x].pos.x, deckmenu_card[y][x].pos.y,
					deckmenu_card[y][x].size.x, deckmenu_card[x][y].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		}
	}
	//�Z���N�g�t���[���`��
	DrawSpriteLeftTop(g_Selection.texture, g_Selection.pos.x, g_Selection.pos.y, g_Selection.size.x, g_Selection.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	//���݂̃y�[�W���`��
	DrawSpriteLeftTop(g_number.texture, g_number.pos.x, g_number.pos.y, g_number.size.x, g_number.size.y, g_number.u, g_number.v, g_number.uw, g_number.vh);
}

//-----�\���̃|�C���^�擾����
SELECTION* GetSelection(void)
{
	return &g_Selection;
}

DECKMENU* GetDeckmenu(void)
{
	return &deckmenu;
}