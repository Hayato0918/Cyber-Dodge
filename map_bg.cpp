//�}�b�vBG���� [map_BG.cpp]
#include "map_bg.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
MAP_BG map_bg;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitMapBG(void)
{
	map_bg.pos = D3DXVECTOR2(0.0f, 0.0f);
	map_bg.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	map_bg.texture = LoadTexture("data/TEXTURE/map/bg.jpg");

	return S_OK;
}

//-----�I������
void UninitMapBG(void)
{

}

//-----�X�V����
void UpdateMapBG(void)
{
	//if (GetKeyboardPress(DIK_W))
	//	map_bg.pos.y += 3;
	//if (GetKeyboardPress(DIK_S))
	//	map_bg.pos.y -= 3;
}

//-----�`�揈��
void DrawMapBG(void)
{
	DrawSpriteLeftTop(map_bg.texture, map_bg.pos.x, map_bg.pos.y, map_bg.size.x, map_bg.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);
}