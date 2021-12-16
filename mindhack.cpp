//スキル_マインドハック処理 [mindhack.cpp]
#include "mindhack.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "enemy.h"
#include "bugincrease.h"
#include "catch.h"
#include "reverse.h"

#include "skillrandom.h"

//-----マクロ定義
#define mindhacktime 360		//6s間

//-----プロトタイプ宣言
MINDHACK mindhack;

//-----グローバル変数

//-----初期化処理
HRESULT InitMindhack(void)
{
	mindhack.use = false;
	mindhack.timeflag = false;
	mindhack.time = 0.0f;
	mindhack.usegauge = 40;

	return S_OK;
}

//-----マインドハック処理
void _Mindhack(void)
{
	PLAYER* player = GetPlayer();
	ENEMY* enemy = GetEnemy();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();
	REVERSE* reverse = GetReverse();

	//ランダムで4が出たら、6s間敵が行動不能になる
	if (random->code == 4 && random->active == true && mindhack.use == false)
	{
		mindhack.timeflag = true;
		bug->gaugesize.x = bug->gaugesize.x + mindhack.usegauge * bug->gaugeonce;
		mindhack.use = true;
	}
	//スキル使用6s後にもとに戻る
	if (mindhack.timeflag == true)
	{
		mindhack.time = mindhack.time + 1.0f;
		if (GetKeyboardPress(DIK_W))	//上
		{
			if (reverse->use == false)
				enemy->pos.y -= player->move.y;
			if (reverse->use == true)
				enemy->pos.y += player->move.y;
		}
		if (GetKeyboardPress(DIK_S))	//下
		{
			if (reverse->use == false)
				enemy->pos.y += player->move.y;
			if (reverse->use == true)
				enemy->pos.y -= player->move.y;
		}
		if (GetKeyboardPress(DIK_A))	//左
		{
			if (reverse->use == false)
				enemy->pos.x -= player->move.x;
			if (reverse->use == true)
				enemy->pos.x += player->move.x;

			enemy->rotate = 2;		//左向きに更新

			enemy->walktextureflag = true;		//テクスチャの切り替え
		}
		if (GetKeyboardPress(DIK_D))	//右
		{
			if (reverse->use == false)
				enemy->pos.x += player->move.x;
			if (reverse->use == true)
				enemy->pos.x -= player->move.x;

			enemy->rotate = 3;		//右向きに更新

			enemy->walktextureflag = true;		//テクスチャの切り替え
		}
	}

	if (mindhack.time > mindhacktime)
	{
		mindhack.timeflag = false;
		mindhack.time = 0.0f;
		mindhack.use = false;
	}
}