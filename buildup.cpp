//�X�L��_�r���h�A�b�v���� [uildup.cpp]
#include "buildup.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bug.h"

//-----�}�N����`
#define builduptime 180		//3s��

//-----�v���g�^�C�v�錾
BUILDUP buildup;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBuildUp(void)
{
	buildup.use = false;
	buildup.timeflag = false;
	buildup.time = 0.0f;
	buildup.usegauge = 10;

	return S_OK;
}

//-----���剻����
void _BuildUp(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBug();

	//1�L�[����������A3s�ԃL�����̃T�C�Y��2�{�ɂȂ�
	if (GetKeyboardTrigger(DIK_1) && buildup.use == false)
	{
		player->size = D3DXVECTOR2(player->size.x * 2, player->size.y * 2);
		buildup.timeflag = true;
		bug->gaugesize.x = bug->gaugesize.x + buildup.usegauge * bug->gaugeonce;
		buildup.use = true;
	}
	//�X�L���g�p3s��ɂ��Ƃ̑傫���ɖ߂�
	if (buildup.timeflag == true)
		buildup.time = buildup.time + 1.0f;
	if (buildup.time > builduptime)
	{
		buildup.timeflag = false;
		player->size = D3DXVECTOR2(player->size.x * 0.5, player->size.y * 0.5);
		buildup.time = 0.0f;
	}
}