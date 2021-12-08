//�X�L��_�L���b�`�W�Q���� [cacthjamming.cpp]
#include "catchjamming.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "bug.h"

#include "skillrandom.h"

//-----�}�N����`
#define catchjammingtime 180		//3s��

//-----�v���g�^�C�v�錾
CATCHJAMMING catchjamming;

HRESULT InitCatchJamming(void)
{
	catchjamming.use = false;
	catchjamming.timeflag = false;
	catchjamming.time = 0.0f;
	catchjamming.usegauge = 100;

	return S_OK;
}

void _CatchJamming(void)
{
	BUG* bug = GetBug();
	RANDOM* random = GetRandom();

	//I�L�[����������A3�b�ԃL���b�`���o���Ȃ��Ȃ�B
	for (int i = 0; i < 5; i++)
	{
		if (random[i].code == 8 && random[i].active == true && catchjamming.use == false)
		{
			catchjamming.timeflag = true;
			bug->gaugesize.x = bug->gaugesize.x + catchjamming.usegauge * bug->gaugeonce;
			catchjamming.use = true;
		}
	}
	//�X�L���g�p3�b��ɂ��Ƃɖ߂�
	if (catchjamming.timeflag == true)
		catchjamming.time = catchjamming.time + 1.0f;
	if (catchjamming.time > catchjammingtime)
	{
		catchjamming.timeflag = false;
		catchjamming.time = 0.0f;
	}
}

CATCHJAMMING* GetCatchJamming()
{
	return &catchjamming;
}