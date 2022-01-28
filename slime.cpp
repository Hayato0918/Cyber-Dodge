//スライム処理 [slime.cpp]
#include "slime.h"
//システム.h
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "scene.h"
#include "fade.h"

#include "player.h"
#include "bg.h"
#include "ball.h"
#include "catch.h"
#include "slime_hp.h"
#include "slimeAI.h"
#include "skillrandom.h"
#include "create.h"
#include "map_player.h"
#include "map_floor.h"

#include "enemybreak.h"
#include "slime_animation.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
SLIME slime;

//-----初期化処理
HRESULT InitSlime(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	slime.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.3555f);
	slime.size = D3DXVECTOR2(SCREEN_WIDTH * 0.08f * 2, SCREEN_HEIGHT * 0.14222f * 2);
	slime.move = D3DXVECTOR2(SCREEN_WIDTH * 0.00125f, SCREEN_HEIGHT * 0.002222f);
	slime.colPos = D3DXVECTOR2(slime.pos.x + slime.size.x / 2, slime.pos.y + slime.size.y / 2 + slime.size.y / 4);
	slime.rotate = 2;

	if (map_player->enemypowerup == false)
	{
		slime.atk = 40 + (40 * map_player->floor * 0.1f);
		slime.def = 0;
	}

	if (map_player->enemypowerup == true)
	{
		slime.atk = 40 * 1.2f + (40 * map_player->floor * 0.1f);
		slime.def = 0 * 1.2f;
	}

	slime.u = 0.0f;
	slime.v = 0.0f;
	slime.uw = 1.0f;
	slime.vh = 1.0f;
	slime.drawflag = true;
	slime.getskill = false;
	slime.walktime = 0.0f;

	slime.standtextureflag = true;
	slime.standLRflag = false;
	slime.standtexturetime = 0.0f;

	slime.walktextureflag = false;
	slime.walkLRflag = false;
	slime.walktexturetime = 0.0f;

	slime.throwtextureflag = false;
	slime.throwLRflag = false;
	slime.throwtexturetime = 0.0f;

	slime.damagetextureflag = false;
	slime.damageLRflag = false;
	slime.damagetexturetime = 0.0f;

	/*slime.deathtexture = LoadTexture("data/TEXTURE/enemy/slime/death/death.png");*/


	return S_OK;
}

//-----終了処理
void UninitSlime(void)
{

}

//-----更新処理
void UpdateSlime(void)
{
	BALL* ball = GetBall();
	PLAYER* player = GetPlayer();
	SLIMEHP* slime_hp = GetSlimeHp();
	SKILL* skill = GetSkill();
	BG* bg = GetBG();
	MAP_PLAYER* map_player = GetMapPlayer();
	RANDOM* random = GetRandom();
	ENEMYBREAK* enemybreak = GetEnemyBreak();

	if (slime.walktime > 2)
		slime.u = 0.335f;
	if (slime.walktime > 4)
	{
		slime.u = 0.0f;
		slime.walktime = 0.0f;
	}

	//-----コート外に出ない処理
	if (slime.pos.y <= SCREEN_HEIGHT * 0.27f - slime.size.y * 0.5f)	//上
		slime.pos.y = SCREEN_HEIGHT * 0.27f - slime.size.y * 0.5f;
	if (slime.pos.y >= SCREEN_HEIGHT - slime.size.y - SCREEN_HEIGHT * 0.15f)	//下
		slime.pos.y = SCREEN_HEIGHT - slime.size.y - SCREEN_HEIGHT * 0.15f;
	if (slime.pos.x <= bg->clPos.x)								//左
		slime.pos.x = bg->clPos.x;
	if (slime.pos.x >= SCREEN_WIDTH - slime.size.x)		//右
		slime.pos.x = SCREEN_WIDTH - slime.size.x;


	if (slime.drawflag == true)
	{
		SlimeAI();
	}


	if (ball->playerhitflag == true)
		slime.throwtextureflag = true;

	if (slime.damagetextureflag == false)
		slime.standtextureflag = true;

	//-----アニメーション処理
	slime_animation();

	//-----プレイヤーが投げたボールが、地面,壁に当たらず敵に当たったら敵の描画をやめる(アウト判定)
	if (ball->enemyhitflag == true)
	{
		if (slime.pos.x < ball->pos.x + ball->size.x && slime.pos.x + slime.size.x > ball->pos.x)
		{
			if (slime.pos.y < ball->pos.y + ball->size.y && slime.pos.y + slime.size.y > ball->pos.y)
			{
				slime.damagetextureflag = true;
				slime_hp->gaugesize.x = slime_hp->gaugesize.x - (player->atk - slime.def) * SCREEN_WIDTH * 0.002f;
				ball->enemyhitflag = false;
			}
		}
	}

	//HPが0になったらmapへ移動する
	if (slime_hp->gaugesize.x <= 0)
	{
		slime.drawflag = false;
		if (slime.getskill == false)
		{
			skill->slot = skill->slot + 1;
			slime.getskill = true;
		}
		map_player->nextflag = true;
		enemybreak->drawflag = true;
	}


	//岩石との当たり判定
	slime.colPos = D3DXVECTOR2(slime.pos.x + slime.size.x / 2, slime.pos.y + slime.size.y / 2 + slime.size.y / 4); //当たり判定の座標の更新

	CREATE* create = GetCreate(0);

	if (create->timeflag)
	{
		for (int i = 0; i < 3; i++) // ここの3は生成される岩石の個数を表す。createで数を変更した際はここも変更して下さい。
		{
			CREATE* create = GetCreate(i);

			if (slime.colPos.x > create->pos.x - create->size.x / 2 && slime.colPos.x < create->pos.x + create->size.x / 2 &&
				slime.colPos.y > create->pos.y - create->size.y / 2 && slime.colPos.y < create->pos.y + create->size.y / 2)
			{
				float ax = 0.0f;
				float ay = 0.0f;
				float bx = 0.0f;
				float by = SCREEN_HEIGHT * 0.5f;
				if (slime.colPos.x < create->pos.x)
					//岩石の左側
				{
					ax = (create->pos.x - slime.colPos.x) / create->size.x / 2;
					bx = create->pos.x - create->size.x / 2 - slime.size.x / 2;
				}
				else if (slime.colPos.x > create->pos.x)
					//岩石の右側
				{
					ax = (slime.colPos.x - create->pos.x) / create->size.x / 2;
					bx = create->pos.x + create->size.x / 2 - slime.size.x / 2;
				}

				if (slime.colPos.y < create->pos.y)
					//岩石の上側
				{
					ay = (create->pos.y - slime.colPos.y) / create->size.y / 2;
					by = create->pos.y - create->size.y / 2 - slime.size.y / 2 - slime.size.y / 4;
				}
				else if (slime.colPos.y > create->pos.y)
					//岩石の下側
				{
					ay = (slime.colPos.y - create->pos.y) / create->size.y / 2;
					by = create->pos.y + create->size.y / 2 - slime.size.y / 2 - slime.size.y / 4;
				}

				if (ax > ay)
				{
					slime.pos.x = bx;
				}
				else if (ax < ay)
				{
					slime.pos.y = by;
				}
				else
				{
					slime.pos.x = create->pos.x - create->size.x / 2 - slime.size.x / 2;
				}
			}
		}
	}
}

//-----描画処理
void DrawSlime(void)
{
	if (slime.drawflag == true)
	{
		//ダメージとき && ((右向いてるとき || 左向いてるとき))
		if (slime.damagetextureflag == true && slime.damageLRflag == false)
			DrawSpriteLeftTop(slime.damage_Ltexture, slime.pos.x, slime.pos.y, slime.size.x, slime.size.y, slime.u, slime.v, slime.uw, slime.vh);
		if (slime.damagetextureflag == true && slime.damageLRflag == true)
			DrawSpriteLeftTop(slime.damage_Rtexture, slime.pos.x, slime.pos.y, slime.size.x, slime.size.y, slime.u, slime.v, slime.uw, slime.vh);

		if (slime.damagetextureflag == false)
		{
			//投げたとき && ((右向いてるとき || 左向いてるとき))
			if (slime.throwtextureflag == true && slime.throwLRflag == false)
				DrawSpriteLeftTop(slime.throw_Ltexture, slime.pos.x, slime.pos.y, slime.size.x, slime.size.y, slime.u, slime.v, slime.uw, slime.vh);
			if (slime.throwtextureflag == true && slime.throwLRflag == true)
				DrawSpriteLeftTop(slime.throw_Rtexture, slime.pos.x, slime.pos.y, slime.size.x, slime.size.y, slime.u, slime.v, slime.uw, slime.vh);

			if (slime.throwtextureflag == false)
			{
				//止まってるとき && (右向いてるとき || 左向いてるとき)
				if (slime.walktextureflag == false && slime.standLRflag == false)
					DrawSpriteLeftTop(slime.stand_Ltexture, slime.pos.x, slime.pos.y,
						slime.size.x, slime.size.y, slime.u, slime.v, slime.uw, slime.vh);
				if (slime.walktextureflag == false && slime.standLRflag == true)
					DrawSpriteLeftTop(slime.stand_Rtexture, slime.pos.x, slime.pos.y,
						slime.size.x, slime.size.y, slime.u, slime.v, slime.uw, slime.vh);

				//動いてるとき && (右向いてるとき || 左向いてるとき)
				if (slime.walktextureflag == true && slime.walkLRflag == false)
					DrawSpriteLeftTop(slime.walk_Ltexture, slime.pos.x, slime.pos.y,
						slime.size.x, slime.size.y, slime.u, slime.v, slime.uw, slime.vh);
				if (slime.walktextureflag == true && slime.walkLRflag == true)
					DrawSpriteLeftTop(slime.walk_Rtexture, slime.pos.x, slime.pos.y,
						slime.size.x, slime.size.y, slime.u, slime.v, slime.uw, slime.vh);
			}
		}
	}



	//ダメージを受けたとき

}

//-----構造体ポインタ取得処理
SLIME* GetSlime(void)
{
	return &slime;
}