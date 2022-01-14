/*------------------------------------------
[ �Ó] [ notCatch.cpp ] ]
-------------------------------------------*/
#include "notCatch.h"
#include "input.h"
#include "Texture.h"
#include "sprite.h"

#include "bugincrease.h"

//-----�}�N����`
#define notCatchtime	1800		//�o�O�̌��ʎ��ԁB30�b�ԁB

//-----�v���g�^�C�v�錾
NOTCATCH notCatch;

HRESULT InitNotCatch(void)
{
	notCatch.use = false;
	notCatch.timeflag = false;
	notCatch.time = 0.0f;
	notCatch.usegauge = 100;

	return S_OK;
}

void _NotCatch(void)
{
	BUG* bug = GetBugIncrease();

	//�o�O�Q�[�W�����܂�ƁA30�b�ԃL���b�`���o���Ȃ��Ȃ�B
	if (bug->gaugesize.x >= 100)
	{
		notCatch.time = 0.0f;
		if (notCatch.use == false)
		{
			notCatch.timeflag = true;
			notCatch.use = true;
		}
	}

	//30�b��ɂ��Ƃɖ߂�
	if (notCatch.timeflag == true)
		notCatch.time = notCatch.time + 1.0f;
	if (notCatch.time > notCatchtime)
	{
		notCatch.timeflag = false;
		notCatch.time = 0.0f;

		notCatch.use = false;
	}
}

NOTCATCH* GetNotCatch()
{
	return &notCatch;
}