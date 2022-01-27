//プレイヤー操作反転 [ reverse.cpp ]
#include "reverse.h"
#include "input.h"
#include "Texture.h"
#include "sprite.h"

#include "player.h"
#include "bugrandom.h"
#include "bugincrease.h"
#include "bugrandom.h"

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
	if (bugrandom->code == 7 && bug->breakflag == true && reverse.use == false)
	{
		reverse.use = true;
	}

	//バグゲージが50より小さくなったら操作をもとに戻す
	if (bug->breakflag == false && reverse.use == true)
	{
		reverse.use = false;
		bugrandom->code = (rand() % bugrandom->num) + 1;
	}

}

//-----構造体ポインタ取得処理
REVERSE* GetReverse(void)
{
	return &reverse;
}