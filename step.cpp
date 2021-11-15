//�X�L��_�X�e�b�v���� [step.cpp]
#include "step.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "escape.h"

//-----�}�N����`


//-----�v���g�^�C�v�錾
STEP step;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitStep(void)
{
	step.use = false;

	return S_OK;
}

//-----�X�e�b�v����
void _Step(void)
{
	PLAYER* player = GetPlayer();
	ESCAPE* escape = GetEscape();

	//2�L�[�������Ɖ���̃N�[���_�E�����Z�k����܂�
	if (GetKeyboardTrigger(DIK_2) && step.use == false && escape->intervalflag == true)
	{
		escape->intervaltime = 300.0f;

		step.use = true; //1��̎g�p
	}
}