//�X�L������ [skill.cpp]
#include "bg.h"
#include "texture.h"
#include "sprite.h"

#include "buildup.h"
#include "ballspeedup.h"
#include "barrier.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitSkill(void)
{
	//-----���剻����
	InitBuildUp();

	//-----�{�[���X�s�[�h�A�b�v����
	InitBallSpeedUp();

	//-----�o���A����
	InitBarrier();


	return S_OK;
}

void _Skill(void)
{
	//-----���剻����
	_BuildUp();

	//-----�{�[���X�s�[�h�A�b�v����
	_BallSpeedUp();

	//-----�o���A����
	_Barrier();


}

void DrawSkill(void)
{
	//-----�o���A�`��
	DrawBarrier();
}