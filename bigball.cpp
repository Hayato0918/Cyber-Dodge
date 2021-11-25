//�X�L��_�{�[�����剻���� [BigBall.cpp]
#include "bigball.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "ball.h"

//-----�}�N����`
#define bigballtime 180		//3s��

//-----�v���g�^�C�v�錾
BIGBALL bigball;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBigBall(void)
{
	bigball.use = false;
	bigball.timeflag = false;
	bigball.time = 0.0f;

	return S_OK;
}

//-----�{�[�����剻����
void _BigBall(void)
{
	BALL* ball = GetBall();

	//8�L�[����������A3s�ԃ{�[���̃T�C�Y���傫���Ȃ�
	if (GetKeyboardTrigger(DIK_0) && bigball.use == false)
	{
		ball->size = D3DXVECTOR2(ball->size.x * 2, ball->size.y * 2);
		bigball.timeflag = true;
		bigball.use = true;
	}
	//�X�L���g�p3s��ɂ��Ƃ̑傫���ɖ߂�
	if (bigball.timeflag == true)
		bigball.time = bigball.time + 1.0f;
	if (bigball.time > bigballtime)
	{
		bigball.timeflag = false;
		ball->size = D3DXVECTOR2(ball->size.x * 0.5f, ball->size.y * 0.5f);
		bigball.time = 0.0f;
	}
}