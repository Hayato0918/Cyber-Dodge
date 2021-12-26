//�X�L��_�ђ� [kantsuu.cpp]
#include "penetration.h"
#include "input.h"
#include "bugincrease.h"
#include "skillrandom.h"
#include "rockcreate.h"

//-----�}�N����`
#define kantsuutime 180	//3s��

//-----�v���g�^�C�v�錾
KANTSUU kantsuu;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitKantsuu(void)
{
	kantsuu.use = false;
	kantsuu.timeflag = false;
	kantsuu.time = 0.0f;
	kantsuu.usegauge = 10;

	return S_OK;
}

//-----�s�@�N������
void _Kantsuu(void)
{
	RANDOM* random = GetRandom();
	BUG* bug = GetBugIncrease();;

	//-----��������3�b�ԁA�{�[������Q���̔�����ђʂ���悤�ɂȂ�B
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 11 && random[i].active == true && kantsuu.use == false)
		{
			bug->gaugesize.x = bug->gaugesize.x + kantsuu.usegauge * bug->gaugeonce;
			kantsuu.timeflag = true;
			kantsuu.use = true;
		}
	}

	//-----
	if (kantsuu.timeflag == true)
		kantsuu.time = kantsuu.time + 1.0f;

	if (kantsuu.time > kantsuutime)
	{
		kantsuu.timeflag = false;
		kantsuu.time = 0.0f;
	}
}

//-----�\���̃|�C���^�擾����
KANTSUU* GetKantsuu(void)
{
	return &kantsuu;
}