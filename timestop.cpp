//�X�L��_���Ԓ�~���� [timestop.cpp]
#include "timestop.h"
//-----�G�l�~�[.h
#include "firewall.h"

#include "bugincrease.h"
#include "catch.h"

#include "skillrandom.h"

//-----�}�N����`
#define timestoptime 360		//6s��

//-----�v���g�^�C�v�錾
TIMESTOP timestop;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitTimestop(void)
{
	timestop.use = false;
	timestop.timeflag = false;
	timestop.time = 0.0f;
	timestop.usegauge = 80;
	timestop.posnow = D3DXVECTOR2(0.0f, 0.0f);

	return S_OK;
}

//-----���剻����
void _Timestop(void)
{
	FIREWALL* firewall = GetFireWall();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();
	CATCH* cattch = GetCatch();

	//�����_����4���o����A6s�ԓG���s���s�\�ɂȂ�
	if (random->code == 4 && random->active == true && timestop.use == false)
	{
		timestop.posnow = firewall->pos;
		timestop.timeflag = true;
		bug->gaugesize.x = bug->gaugesize.x + timestop.usegauge * bug->gaugeonce;
		timestop.use = true;
	}
	//�X�L���g�p6s��ɂ��Ƃɖ߂�
	if (timestop.timeflag == true)
	{
		timestop.time = timestop.time + 1.0f;
		firewall->pos = timestop.posnow;
		cattch->enemyflag = 2;
		cattch->enemyintervalflag = 2;
	}

	if (timestop.time > timestoptime)
	{
		timestop.timeflag = false;
		timestop.time = 0.0f;
		timestop.use = false;
		cattch->enemyflag = 0;
		cattch->enemyintervalflag = 0;
	}
}