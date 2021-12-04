//スキル_プレイヤーが小さくなる処理 [SmallPlayer.cpp] 
#include "smallplayer.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bug.h"

#include "skillrandom.h"

//-----マクロ定義
#define smallplayertime 180		//3s間

//-----プロトタイプ宣言
SMALLPLAYER smallplayer;

//-----グローバル変数

//-----初期化処理
HRESULT InitSmallPlayer(void)
{
	smallplayer.use = false;
	smallplayer.timeflag = false;
	smallplayer.time = 0.0f;
	smallplayer.usegauge = 10;

	return S_OK;
}

//-----プレイヤー縮小処理
void _SmallPlayer(void)
{
	PLAYER* player = GetPlayer();
	RANDOM* random = GetRandom();
	BUG* bug = GetBug();

	//ランダムで7が選ばれたら、3s間キャラのサイズが0.5倍小さくなるになる
	if (random->code == 7 && random->active == true && smallplayer.use == false)
	{
		bug->gaugesize.x = bug->gaugesize.x + smallplayer.usegauge * bug->gaugeonce;
		player->size = D3DXVECTOR2(player->size.x * 0.5f, player->size.y * 0.5f);
		smallplayer.timeflag = true;
		smallplayer.use = true;
	}
	//スキル使用3s後にもとの大きさに戻る
	if (smallplayer.timeflag == true)
		smallplayer.time = smallplayer.time + 1.0f;
	if (smallplayer.time > smallplayertime)
	{
		smallplayer.timeflag = false;
		player->size = D3DXVECTOR2(player->size.x * 2, player->size.y * 2);
		smallplayer.time = 0.0f;
	}
}