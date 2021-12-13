/*------------------------------------------
[ �Ó] [ Bug_anten.cpp ] ]
-------------------------------------------*/
#include "anten.h"
#include "input.h"
#include "Texture.h"
#include "sprite.h"

#include "bugincrease.h"
#include "bugrandom.h"

//-----�v���g�^�C�v�錾
ANTEN anten;

//-----����������
HRESULT InitAnten(void)
{
	anten.pos = D3DXVECTOR2(0.0f, SCREEN_HEIGHT - 450.0f);
	anten.size = D3DXVECTOR2(960.0f, 540.0f);

	anten.use = false;
	anten.drawflag = false;

	anten.texture = LoadTexture("data/TEXTURE/anten.png");

	return S_OK;
}

//-----�v���C���[���]����
void _Anten(void)
{
	BUG* bug = GetBugIncrease();
	BUGRANDOM* bugrandom = GetBugRandom();

	//�o�O�Q�[�W��100�ȏ�ɂȂ������ʂ𖶂�����
	if (bugrandom->code == 1 && bug->gaugesize.x >= 100 == true && anten.use == false)
	{
		anten.use = true;
		anten.drawflag = true;
	}

	//�o�O�Q�[�W��100�ȉ��ɂȂ����疶�������
	if (bug->gaugesize.x <= 100  && anten.use == true)
	{
		anten.use = false;
		anten.drawflag = false;
	}
}

//-----�`�揈��
void DrawAnten(void)
{
	if (anten.drawflag == true)
		DrawSpriteLeftTop(anten.texture, anten.pos.x, anten.pos.y, anten.size.x, anten.size.y, 0.0f, 0.0f, 1.0f, 1.0f);

}