//�X�L��_�v���C���[���������Ȃ鏈�� [SmallPlayer.cpp] 
#include "smallplayer.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bug.h"

#include "skillrandom.h"

//-----�}�N����`
#define smallplayertime 180		//3s��

//-----�v���g�^�C�v�錾
SMALLPLAYER smallplayer;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitSmallPlayer(void)
{
	smallplayer.use = false;
	smallplayer.timeflag = false;
	smallplayer.time = 0.0f;
	smallplayer.usegauge = 10;

	return S_OK;
}

//-----�v���C���[�k������
void _SmallPlayer(void)
{
	PLAYER* player = GetPlayer();
	RANDOM* random = GetRandom();
	BUG* bug = GetBug();

	//�����_����7���I�΂ꂽ��A3s�ԃL�����̃T�C�Y��0.5�{�������Ȃ�ɂȂ�
	if (random->code == 7 && random->active == true && smallplayer.use == false)
	{
		bug->gaugesize.x = bug->gaugesize.x + smallplayer.usegauge * bug->gaugeonce;
		player->size = D3DXVECTOR2(player->size.x * 0.5f, player->size.y * 0.5f);
		smallplayer.timeflag = true;
		smallplayer.use = true;
	}
	//�X�L���g�p3s��ɂ��Ƃ̑傫���ɖ߂�
	if (smallplayer.timeflag == true)
		smallplayer.time = smallplayer.time + 1.0f;
	if (smallplayer.time > smallplayertime)
	{
		smallplayer.timeflag = false;
		player->size = D3DXVECTOR2(player->size.x * 2, player->size.y * 2);
		smallplayer.time = 0.0f;
	}
}