//�X�L��_�p���[�_�E������ [enemy_powerdown.cpp]
#include "enemy_powerdown.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "enemy.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----�}�N����`
#define powerdowntime 600		//10s��

//-----�v���g�^�C�v�錾
POWERDOWN powerdown;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitPowerDown(void)
{
	powerdown.use = false;
	powerdown.timeflag = false;
	powerdown.time = 0.0f;
	powerdown.usegauge = 30;

	return S_OK;
}

//-----���剻����
void _PowerDown(void)
{
	ENEMY* enemy = GetEnemy();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();

	//�����_����4���o����A10s�ԓG�̃p���[��-50�ɂȂ�
	if (random->code == 4 && random->active == true && powerdown.use == false)
	{
		enemy->atk = enemy->atk - 50;
		powerdown.timeflag = true;
		bug->gaugesize.x = bug->gaugesize.x + powerdown.usegauge * bug->gaugeonce;
		powerdown.use = true;
	}
	//�X�L���g�p10s��ɂ��Ƃ̋����ɖ߂�
	if (powerdown.timeflag == true)
		powerdown.time = powerdown.time + 1.0f;
	if (powerdown.time > powerdowntime)
	{
		powerdown.timeflag = false;
		enemy->atk = enemy->atk + 50;
		powerdown.time = 0.0f;
	}
}