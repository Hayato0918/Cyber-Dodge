//�n�b�L���O�G�t�F�N�g���� [hackeffect.cpp]
#include "hackeffect.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "map_point.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
HACKEFFECT hackeffect;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitHackEffect(void)
{
	hackeffect.pos = D3DXVECTOR2(0.0f, 0.0f);
	hackeffect.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	hackeffect.u = 0.f;
	hackeffect.v = 0.f;
	hackeffect.drawflag = false;
	hackeffect.texture = LoadTexture("data/TEXTURE/hackingmenu/effect.png");

	return S_OK;
}

//-----�I������
void UninitHackEffect(void)
{

}

//-----�X�V����
void UpdateHackEffect(void)
{
	MAP_SB* map_sb = GetMapSB();

	if(map_sb->hackflag == true)
		hackeffect.drawflag = true;

}

//-----�`�揈��
void DrawHackEffect(void)
{
	if(hackeffect.drawflag == true)
	DrawSpriteLeftTop(hackeffect.texture, hackeffect.pos.x, hackeffect.pos.y, hackeffect.size.x, hackeffect.size.y,
		hackeffect.u, hackeffect.v, 0.125f, 0.09f);
}