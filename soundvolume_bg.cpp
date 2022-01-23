//�T�E���h�{�����[��bg���� [soundvolume_bg.cpp]
#include "soundvolume_bg.h"
//
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
BGM bgm;
SE se;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitSoundVolumeBG(void)
{
	//-----bgm
	bgm.pos = D3DXVECTOR2(200.f, 250.f);
	bgm.size = D3DXVECTOR2(1200.f, 200.f);
	bgm.texture = LoadTexture("data/TEXTURE/option/bgm.png");

	//-----se
	se.pos = D3DXVECTOR2(200.f, 550.f);
	se.size = D3DXVECTOR2(1200.f, 200.f);
	se.texture = LoadTexture("data/TEXTURE/option/se.png");


	return S_OK;
}

//-----�I������
void UninitSoundVolumeBG(void)
{

}

//-----�X�V����
void UpdateSoundVolumeBG(void)
{

}

//-----�`�揈��
void DrawSoundVolumeBG(void)
{
	DrawSpriteLeftTop(bgm.texture, bgm.pos.x, bgm.pos.y, bgm.size.x, bgm.size.y,0.0f, 0.0f, 1.0f, 1.0f);
	DrawSpriteLeftTop(se.texture, se.pos.x, se.pos.y, se.size.x, se.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

BGM* GetBGM()
{
	return &bgm;
}
SE* GetSE()
{
	return &se;
}