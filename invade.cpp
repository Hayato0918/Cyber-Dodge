//�X�L��_�s�@�N������ [invade.cpp]
#include "invade.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"

//-----�}�N����`
#define invadetime 180		//3s��

//-----�v���g�^�C�v�錾
INVADE invade;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitInvade(void)
{
	invade.use = false;
	invade.timeflag = false;
	invade.time = 0.0f;

	return S_OK;
}

//-----�s�@�N������
void _Invade(void)
{
	PLAYER* player = GetPlayer();

	//1�L�[�Ŏg�p/3�b�ԓG�̐w�n�ɓ����
	if (GetKeyboardTrigger(DIK_0) && invade.use == false)
	{
		//-----�v���C���[�̈ʒu��G�w�܂Ń��[�v������
		player->pos.x = (SCREEN_WIDTH / 2) + 5;

		invade.timeflag = true;
		invade.use = true;
	}

	//�X�L���I�����ɓG�w�ɂ����ꍇ�Ax���W�����w�ƓG�w�̋��E�܂Ŗ߂�
	if (invade.timeflag == true)
		invade.time = invade.time + 1.0f;
	if (invade.time > invadetime)
	{
		invade.timeflag = false;
		invade.time = 0.0f;
	}
}

//-----�\���̃|�C���^�擾����
INVADE* GetInvade(void)
{
	return &invade;
}