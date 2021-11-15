//������� [escape.cpp]
#include "escape.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"

//-----�}�N����`
#define escapetime 300	//����̃C���^�[�o������(5s)

//-----�v���g�^�C�v�錾
ESCAPE escape;

//-----����������
HRESULT InitEscape(void)
{
	escape.intervalflag = false;
	escape.intervaltime = 0.0f;

	return S_OK;
}

//-----�������
void _Escape(void)
{
	PLAYER* player = GetPlayer();

	//-----space�L�[�ŉ��
	if (GetKeyboardTrigger(DIK_SPACE) && escape.intervalflag == false)
	{
		if (player->rotate == 0)
			player->pos.y -= player->size.x * 2;
		if (player->rotate == 1)
			player->pos.y += player->size.x * 2;
		if (player->rotate == 2)
			player->pos.x -= player->size.x * 2;
		if (player->rotate == 3)
			player->pos.x += player->size.x * 2;

		escape.intervalflag = true;
	}
	//-----�C���^�[�o��(5s)
	if (escape.intervalflag == true)
		escape.intervaltime += 1.0f;
	if (escape.intervaltime > escapetime)
	{
		escape.intervalflag = false;
		escape.intervaltime = 0.0f;
	}
}

ESCAPE* GetEscape()
{
	return &escape;
}