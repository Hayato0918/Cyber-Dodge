//�X�L��_�v���C���[���������Ȃ鏈�� [SmallPlayer.cpp] 
#include "smallplayer.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"

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

	return S_OK;
}

//-----�v���C���[�k������
void _SmallPlayer(void)
{
	PLAYER* player = GetPlayer();

	//7�L�[����������A3s�ԃL�����̃T�C�Y��0.5�{�������Ȃ�ɂȂ�
	if (GetKeyboardTrigger(DIK_0) && smallplayer.use == false)
	{
		player->size = D3DXVECTOR2(player->size.x * 0.5, player->size.y * 0.5);
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