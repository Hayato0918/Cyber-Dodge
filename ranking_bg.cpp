//�����L���O_�w�i���� [ranking_bg.cpp]
#include "ranking_bg.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "Texture.h"
#include "sprite.h"
#include "sound.h"

//-----�萔��`

//-----�\���̐錾

//-----�v���g�^�C�v�錾
RANKING_BG ranking_bg;

//-----�O���[�o���ϐ��̒�`


//-----�������֐�
HRESULT InitRankingBG(void)
{
	ranking_bg.pos = D3DXVECTOR2(0.f, 0.f);
	ranking_bg.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	ranking_bg.texture = LoadTexture("data/TEXTURE/ranking.png");

	return S_OK;
}

//-----�I�������֐�
void UninitRankingBG(void)
{

}

//-----�X�V����������֐�
void UpdateRankingBG(void)
{

}

//-----�`�揈���֐�
void DrawRankingBG(void)
{
	DrawSpriteLeftTop(ranking_bg.texture, ranking_bg.pos.x, ranking_bg.pos.y, ranking_bg.size.x, ranking_bg.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}