//�`���[�g���A������ [tutorial_map.cpp]
#include "tutorial_map.h"

#include "main.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"

#include "map_player.h"

//�K�v�Ȃ���

//-----�}�N����`

//-----�v���g�^�C�v�錾
TUTORIAL_MAP tutorial_map;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitTutorialMap(void)
{
	tutorial_map.pos = D3DXVECTOR2(350.f, 220.0f);
	tutorial_map.size = D3DXVECTOR2(300.f, 100.0f);
	tutorial_map.drawflag = false;

	return S_OK;
}

//-----�I������
void UninitTutorialMap(void)
{

}

//-----�X�V����
void UpdateTutorialMap(void)
{




}

//-----�`�揈��
void DrawTutorialMap(void)
{
	if (tutorial_map.drawflag == true)
		DrawSpriteLeftTop(tutorial_map.texture, tutorial_map.pos.x, tutorial_map.pos.y, tutorial_map.size.x, tutorial_map.size.y, 0.f, 0.f, 1.f, 1.f);
}

TUTORIAL_MAP* GetTutorialMap()
{
	return &tutorial_map;
}