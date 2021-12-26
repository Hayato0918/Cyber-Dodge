//�X�L��_�s�@�N������ [invade.cpp]
#include "invade.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bugincrease.h"

#include "skillrandom.h"

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
	invade.usegauge = 10;

	return S_OK;
}

//-----�s�@�N������
void _Invade(void)
{
	PLAYER* player = GetPlayer();
	RANDOM* random = GetRandom();
	BUG* bug = GetBugIncrease();;

	//�����_����5���I�΂ꂽ��A3�b�ԓG�̐w�n�ɓ����
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 9 && random[i].active == true && invade.use == false)
		{
			bug->gaugesize.x = bug->gaugesize.x + invade.usegauge * bug->gaugeonce;

			//-----�v���C���[�̈ʒu��G�w�܂Ń��[�v������
			player->pos.x = (SCREEN_WIDTH / 2) + 5;

			invade.timeflag = true;
			invade.use = true;
		}
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