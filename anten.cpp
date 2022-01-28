/*------------------------------------------
[ �Ó] [ Bug_anten.cpp ] ]
-------------------------------------------*/
#include "anten.h"
#include "input.h"
#include "Texture.h"
#include "sprite.h"

#include "bugincrease.h"
#include "bugrandom.h"
#include "screencrack.h"

//-----�v���g�^�C�v�錾
ANTEN anten;

//-----����������
HRESULT InitAnten(void)
{
	anten.pos = D3DXVECTOR2(0.0f, 0.f);
	anten.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

	anten.use = false;
	anten.drawflag = false;

	return S_OK;
}

//-----�v���C���[���]����
void _Anten(void)
{
	BUG* bug = GetBugIncrease();
	BUGRANDOM* bugrandom = GetBugRandom();
	CRACK* crack = GetCrack();

	//�o�O�Q�[�W��100�ȏ�ɂȂ��āA�X�L�����g�����{�[����������Ɖ�ʂ𖶂�����
	if (bugrandom->code == 1 && bug->breakflag == true && anten.use == false)
	{
		anten.use = true;
		anten.drawflag = true;
	}

	//�o�O�Q�[�W��100�ȉ��ɂȂ����疶�������
	if (bug->breakflag == false && anten.use == true)
	{
		anten.use = false;
		anten.drawflag = false;
		bugrandom->code = (rand() % bugrandom->num) + 1;
	}
}

//-----�`�揈��
void DrawAnten(void)
{
	if (anten.drawflag == true)
		DrawSpriteLeftTop(anten.texture, anten.pos.x, anten.pos.y, anten.size.x, anten.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

ANTEN* GetAnten()
{
	return &anten;
}