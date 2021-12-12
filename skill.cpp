//�X�L������ [skill.cpp]
#include "bg.h"
#include "texture.h"
#include "sprite.h"

#include "ballspeedup.h"
#include "ballturnaround.h"
#include "barrier.h"
#include "baseball.h"
#include "bigball.h"
#include "Billiards.h"
#include "buildup.h"
#include "catchjamming.h"
#include "invade.h"
#include "invincible.h"
#include "penetration.h"
#include "rockcreate.h"
#include "slowarea.h"
#include "smallplayer.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitSkill(void)
{
	//-----�u�[�X�g�{�[��
	InitBallSpeedUp();

	//-----�����]��
	InitBallTurnAround();

	//-----�o���A
	InitBarrier();

	//-----�v���C�I�x�[�X�{�[��
	InitBaseball();

	//-----�{�[�����剻
	InitBigBall();

	//-----�r�����[�h�͏��߂āH
	InitBilliards();

	//-----�r���h�A�b�v
	InitBuildUp();

	//-----�L���b�`�s��
	InitCatchJamming();

	//-----�s�@�N��
	InitInvade();

	//-----���G
	InitInvincible();

	//-----�ђ�
	InitKantsuu();

	//----��ΐ���
	InitGanseki();

	//-----�X���E�G���A
	InitSlowArea();

	//-----�v���C���[�k��
	InitSmallPlayer();

	return S_OK;
}

void _Skill(void)
{
	//-----�u�[�X�g�{�[��
	_BallSpeedUp();

	//-----�����]��
	_BallTurnAround();

	//-----�o���A
	_Barrier();

	//-----�v���C�I�x�[�X�{�[��
	_Baseball();

	//-----�{�[�����剻
	_BigBall();

	//-----�r�����[�h�͏��߂āH
	_Billiards();

	//-----�r���h�A�b�v
	_BuildUp();

	//-----�L���b�`�s��
	_CatchJamming();

	//-----�s�@�N��
	_Invade();

	//-----���G
	_Invincible();

	//-----�ђ�
	_Kantsuu();

	//----��ΐ���
	_Ganseki();

	//-----�X���E�G���A
	_SlowArea();

	//-----�v���C���[�k��
	_SmallPlayer();
}

void DrawSkill(void)
{
	//-----�o���A
	DrawBarrier();

	//-----�v���C�I�x�[�X�{�[��
	DrawBaseball();

	//-----�r�����[�h�͏��߂āH
	DrawBilliards();

	//-----���G
	DrawInvincible();

	//-----��ΐ���
	DrawGanseki();

	//-----�X���E�G���A�`��
	DrawSlowArea();
}