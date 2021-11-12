//スキル_ビルドアップ処理 [uildup.cpp]
#include "buildup.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bug.h"

//-----マクロ定義
#define builduptime 180		//3s間

//-----プロトタイプ宣言
BUILDUP buildup;

//-----グローバル変数

//-----初期化処理
HRESULT InitBuildUp(void)
{
	buildup.use = false;
	buildup.timeflag = false;
	buildup.time = 0.0f;
	buildup.usegauge = 10;

	return S_OK;
}

//-----巨大化処理
void _BuildUp(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBug();

	//1キーを押したら、3s間キャラのサイズが2倍になる
	if (GetKeyboardTrigger(DIK_1) && buildup.use == false)
	{
		player->size = D3DXVECTOR2(player->size.x * 2, player->size.y * 2);
		buildup.timeflag = true;
		bug->gaugesize.x = bug->gaugesize.x + buildup.usegauge * bug->gaugeonce;
		buildup.use = true;
	}
	//スキル使用3s後にもとの大きさに戻る
	if (buildup.timeflag == true)
		buildup.time = buildup.time + 1.0f;
	if (buildup.time > builduptime)
	{
		buildup.timeflag = false;
		player->size = D3DXVECTOR2(player->size.x * 0.5, player->size.y * 0.5);
		buildup.time = 0.0f;
	}
}