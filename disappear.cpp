//�X�L��_���ŏ��� [disappear.cpp]
#include "disappear.h"
#include "input.h"
#include "sprite.h"

#include "bugincrease.h"

#include "skillrandom.h"
#include "otoshiana.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
DISAPPEAR disappear;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitDisappear(void)
{

	disappear.use = false;

	disappear.usegauge = 10;

	return S_OK;
}

//-----���ŏ���
void _Disappear(void)
{
	OTOSIANA* otosiana = GetOtosiana();
	RANDOM* random = GetRandom();
	BUG* bug = GetBugIncrease();

	//T�L�[�����������Q��������
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code = 4 && random[i].active == true && disappear.use == false)
		{
			bug->gaugesize.x = bug->gaugesize.x + disappear.usegauge * bug->gaugeonce;
			disappear.use = true;
		}
	}

	if (disappear.use == true)							//���Ƃ��������ł���B
	{
		otosiana->timeflag = false;
	}
}
