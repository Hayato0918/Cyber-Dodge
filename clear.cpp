//�N���A���� [clear.cpp]
#include "clear.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
CLEAR clear;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitClear(void)
{
	clear.pos = D3DXVECTOR2(0.0f, 0.0f);
	clear.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	clear.texture = LoadTexture("data/TEXTURE/GAMECLEAR.png");

	return S_OK;
}

//-----�I������
void UninitClear(void)
{

}

//-----�X�V����
void UpdateClear(void)
{
	if (GetKeyboardTrigger(DIK_RETURN) && GetFadeState() == FADE_NONE)
	{
		SceneTransition(SCENE_TITLE);
	}
}

//-----�`�揈��
void DrawClear(void)
{
	DrawSpriteLeftTop(clear.texture, clear.pos.x, clear.pos.y, clear.size.x, clear.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}