//�X�L������ [skill.cpp]
#include "bg.h"
#include "texture.h"
#include "sprite.h"

#include "autocatch.h"
#include "ballspeedup.h"
#include "ballturnaround.h"
#include "barrier.h"
#include "baseball.h"
#include "bigball.h"
#include "Billiards.h"
#include "buildup.h"
#include "catchjamming.h"
#include "enemy_powerdown.h"
#include "disappear.h"
#include "doubleattack.h"
#include "invade.h"
#include "invincible.h"
#include "landmines.h"
#include "mindhack.h"
#include "otoshiana.h"
#include "penetration.h"
#include "player_powerup.h"
#include "player_regen.h"
#include "player_speedup.h"
#include "rockcreate.h"
#include "slowarea.h"
#include "smallplayer.h"
#include "timestop.h"
#include "warp.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitSkill(void)
{
	InitWarp();

	InitOtosiana();

	InitDouble();

	InitDisappear();

	InitAuto_c();

	InitLandMines();

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

	//-----�G�l�~�[�p���[�_�E��
	InitPowerDown();

	//-----�s�@�N��
	InitInvade();

	//-----���G
	InitInvincible();

	//-----�}�C���h�n�b�N
	InitMindhack();

	//-----�ђ�
	InitKantsuu();

	//-----�v���C���[�p���[�A�b�v
	InitPowerUp();

	//-----�v���C���[���W�F�l
	InitPlayerRegen();

	//-----�v���C���[�X�s�[�h�A�b�v
	InitSpeedUp();

	//----��ΐ���
	InitGanseki();

	//-----�X���E�G���A
	InitSlowArea();

	//-----�v���C���[�k��
	InitSmallPlayer();

	//-----�^�C���X�g�b�v
	InitTimestop();

	return S_OK;
}

void _Skill(void)
{
	_Warp();

	_Otosiana();

	_LandMines();

	_Double();

	_Disappear();

	_Auto_c();

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

	//-----�G�l�~�[�p���[�_�E��
	_PowerDown();

	//-----�s�@�N��
	_Invade();

	//-----���G
	_Invincible();

	//-----�}�C���h�n�b�N
	_Mindhack();

	//-----�ђ�
	_Kantsuu();

	//-----�v���C���[�p���[�A�b�v
	_PowerUp();

	//-----�v���C���[���W�F�l
	_PlayerRegen();

	//-----�v���C���[�X�s�[�h�A�b�v
	_SpeedUp();

	//----��ΐ���
	_Ganseki();

	//-----�X���E�G���A
	_SlowArea();

	//-----�v���C���[�k��
	_SmallPlayer();

	//-----�^�C���X�g�b�v
	_Timestop();
}

void DrawSkill(void)
{
	DrawWarp();

	DrawOtosiana();

	DrawLandMines();

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

	DrawTimestop();

	DrawRegen();

	DrawSpeedup();

	DrawPowerup();
}