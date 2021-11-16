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
#include "Billiards.h"
#include "baseball.h"
#include "invincible.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�
int skill_num;


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

	//-----�r�����[�h
	InitBilliards();

	//-----�싅
	InitBaseball();

	//-----���G
	InitInvincible();



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
	//-----�r�����[�h
	_Billiards();
	//-----�싅
	_Baseball();
	//-----���G
	_Invincible();

	//skill_num�ɗ�����ݒ�


	//switch (skill_num)
	//{
	//case 1:
	//	//-----�v���C���[���剻
	//	_BuildUp();
	//case 2:
	//	//-----�{�[���X�s�[�h�A�b�v
	//	_BallSpeedUp();
	//case 3:
	//	//-----�o���A
	//	_Barrier();
	//case 4:
	//	//-----�v���C���[�k��
	//	_SmallPlayer();
	//case 5:
	//	//-----�{�[�����剻
	//	_BigBall();
	//case 6:
	//	//-----�X���E�G���A����
	//	_SlowArea();
	//case 7:
	//	//-----�s�@�N��
	//	_Invade();
	//case 8:
	//	//-----�X�e�b�v
	//	_Step();
	//case 9:
	//	//-----�r�����[�h
	//	_Billiards();
	//case 10:
	//	//-----�싅
	//	_Baseball();
	//}
}

void DrawSkill(void)
{
	//-----�o���A�`��
	DrawBarrier();

	//-----�X���E�G���A�`��
	DrawSlowArea();

	//-----�r�����[�h�`��
	DrawBilliards();

	//-----�o�b�g�`��
	DrawBaseball();

	//-----���G�`��
	DrawInvincible();
}