//スキル_プレイヤーが小さくなる処理 [SmallPlayer.cpp] 
#include "smallplayer.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"

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

	return S_OK;
}

//-----プレイヤー縮小処理
void _SmallPlayer(void)
{
	PLAYER* player = GetPlayer();

	//7キーを押したら、3s間キャラのサイズが0.5倍小さくなるになる
	if (GetKeyboardTrigger(DIK_0) && smallplayer.use == false)
	{
		player->size = D3DXVECTOR2(player->size.x * 0.5, player->size.y * 0.5);
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