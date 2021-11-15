//回避処理 [escape.cpp]
#include "escape.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"

//-----マクロ定義
#define escapetime 300	//回避のインターバル時間(5s)

//-----プロトタイプ宣言
ESCAPE escape;

//-----初期化処理
HRESULT InitEscape(void)
{
	escape.intervalflag = false;
	escape.intervaltime = 0.0f;

	return S_OK;
}

//-----回避処理
void _Escape(void)
{
	PLAYER* player = GetPlayer();

	//-----spaceキーで回避
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
	//-----インターバル(5s)
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