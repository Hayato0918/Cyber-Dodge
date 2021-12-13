//プレイヤー操作反転 [ reverse.cpp ]
#include "reverse.h"
#include "input.h"
#include "Texture.h"
#include "sprite.h"

#include "player.h"
#include "bugrandom.h"
#include "bugincrease.h"

//-----プロトタイプ宣言
REVERSE reverse;

//-----初期化処理
HRESULT InitReverse(void)
{
	reverse.use = false;

	return S_OK;
}

//-----プレイヤー反転処理
void _Reverse(void)
{
	BUG* bug = GetBugIncrease();
	BUGRANDOM* bugrandom = GetBugRandom();

	//バグゲージが100以上になったらプレイヤーの操作を反転させる
	if (bugrandom->code == 3 && bug->gaugesize.x >= 100 && reverse.use == false)
	{
		reverse.use = true;
	}

	//バグゲージが50より小さくなったら操作をもとに戻す
	if (bug->gaugesize.x <= 80)
		reverse.use = false;

}

//-----構造体ポインタ取得処理
REVERSE* GetReverse(void)
{
	return &reverse;
}