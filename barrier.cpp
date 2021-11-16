//スキル_バリア処理 [barrier.cpp]
#include "barrier.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bug.h"

//-----マクロ定義
#define barriertime 180		//3s間

//-----プロトタイプ宣言
BARRIER barrier;

//-----グローバル変数

//-----初期化処理
HRESULT InitBarrier(void)
{
	PLAYER* player = GetPlayer();
	barrier.pos = D3DXVECTOR2(player->pos.x, player->pos.y);
	barrier.size = D3DXVECTOR2(player->size.y, player->size.y);
	barrier.drawflag = false;
	barrier.texture = LoadTexture("data/TEXTURE/barrier.png");

	barrier.use = false;
	barrier.timeflag = false;
	barrier.time = 0.0f;
	barrier.usegauge = 100;

	return S_OK;
}

//-----バリア処理
void _Barrier(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBug();

	barrier.pos = D3DXVECTOR2(player->pos.x - player->size.x * 0.5, player->pos.y);

	//-----9キーを押したら、3s間バリアを張る
	if (GetKeyboardTrigger(DIK_0) && barrier.use == false)
	{
		barrier.drawflag = true;
		barrier.timeflag = true;
		bug->gaugesize.x = bug->gaugesize.x + barrier.usegauge * bug->gaugeonce;
		barrier.use = true;
	}
	//-----スキル使用3s後にもとの大きさに戻る
	if (barrier.timeflag == true)
		barrier.time = barrier.time + 1.0f;
	if (barrier.time > barriertime)
	{
		barrier.timeflag = false;
		barrier.drawflag = false;
		barrier.time = 0.0f;
	}
}

void DrawBarrier(void)
{
	if (barrier.drawflag == true)
		DrawSpriteLeftTop(barrier.texture, barrier.pos.x, barrier.pos.y, barrier.size.x, barrier.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

BARRIER* GetBarrier(void)
{
	return &barrier;
}