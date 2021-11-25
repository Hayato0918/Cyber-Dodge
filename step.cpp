//スキル_ステップ処理 [step.cpp]
#include "step.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "escape.h"

#include "skillrandom.h"

//-----マクロ定義


//-----プロトタイプ宣言
STEP step;

//-----グローバル変数

//-----初期化処理
HRESULT InitStep(void)
{
	step.use = false;

	return S_OK;
}

//-----ステップ処理
void _Step(void)
{
	PLAYER* player = GetPlayer();
	ESCAPE* escape = GetEscape();
	RANDOM* random = GetRandom();

	//2キーを押すと回避のクールダウンが短縮されます
	if (random->code == 8 && random->active == true && step.use == false && escape->intervalflag == true)
	{
		escape->intervaltime = 300.0f;

		step.use = true; //1回の使用
	}
}