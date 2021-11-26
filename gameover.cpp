//�Q�[���I�[�o�[���� [gameover.cpp]
#include "gameover.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
GAMEOVER gameover;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitGameOver(void)
{
	gameover.pos = D3DXVECTOR2(0.0f, 0.0f);
	gameover.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	gameover.texture = LoadTexture("data/TEXTURE/GAMEOVER.png");

	return S_OK;
}

//-----�I������
void UninitGameOver(void)
{

}

//-----�X�V����
void UpdateGameOver(void)
{
	if (GetKeyboardTrigger(DIK_RETURN) && GetFadeState() == FADE_NONE)
	{
		SceneTransition(SCENE_TITLE);
	}
}

//-----�`�揈��
void DrawGameOver(void)
{
	DrawSpriteLeftTop(gameover.texture, gameover.pos.x, gameover.pos.y, gameover.size.x, gameover.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}