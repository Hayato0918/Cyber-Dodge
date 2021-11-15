//�X�L������ [skill.cpp]
#include "bg.h"
#include "texture.h"
#include "sprite.h"

#include "buildup.h"
#include "ballspeedup.h"
#include "barrier.h"
#include "smallplayer.h"
#include "bigball.h"
#include "slowarea.h"
#include "invade.h"
#include "step.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitSkill(void)
{
	//-----�v���C���[���剻
	InitBuildUp();

	//-----�{�[���X�s�[�h�A�b�v
	InitBallSpeedUp();

	//-----�o���A
	InitBarrier();

	//-----�v���C���[�k��
	InitSmallPlayer();

	//-----�{�[�����剻
	InitBigBall();

	//-----�X���E�G���A����
	InitSlowArea();

	//-----�s�@�N������
	InitInvade();

	//-----�X�e�b�v
	InitStep();



	return S_OK;
}

void _Skill(void)
{
	//-----�v���C���[���剻
	_BuildUp();

	//-----�{�[���X�s�[�h�A�b�v
	_BallSpeedUp();

	//-----�o���A
	_Barrier();

	//-----�v���C���[�k��
	_SmallPlayer();

	//-----�{�[�����剻
	_BigBall();

	//-----�X���E�G���A����
	_SlowArea();

	//-----�s�@�N��
	_Invade();

	//-----�X�e�b�v
	_Step();


}

void DrawSkill(void)
{
	//-----�o���A�`��
	DrawBarrier();

	//-----�X���E�G���A�`��
	DrawSlowArea();
}