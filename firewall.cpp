//ファイアーウォール処理 [firewall.cpp]
#include "firewall.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "scene.h"
#include "fade.h"

#include "player.h"
#include "bg.h"
#include "ball.h"
#include "catch.h"
#include "firewall_animation.h"
#include "firewall_hp.h"
#include "firewallAI.h"
#include "skillrandom.h"
#include "create.h"
#include "map_player.h"
#include "enemybreak.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
FIREWALL firewall;

int enemytexture;

//-----初期化処理
HRESULT InitFireWall(void)
{
	enemytexture = LoadTexture("data/TEXTURE/enemy/firewall/firewall.png");
	MAP_PLAYER* map_player = GetMapPlayer();

	firewall.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.3555f);
	firewall.size = D3DXVECTOR2(SCREEN_WIDTH * 0.16f, SCREEN_HEIGHT * 0.28444f);
	firewall.move = D3DXVECTOR2(SCREEN_WIDTH * 0.00125f, SCREEN_HEIGHT * 0.0022222f);
	firewall.colPos = D3DXVECTOR2(firewall.pos.x + firewall.size.x / 2, firewall.pos.y + firewall.size.y / 2 + firewall.size.y / 4);
	firewall.rotate = 2;

	firewall.atk = 150 + (150 * map_player->floor * 0.1f);
	firewall.def = 40; +(40 * map_player->floor * 0.1f);

	firewall.getskill = false;
	firewall.floorflag = false;

	firewall.u = 0.0f;
	firewall.v = 0.0f;
	firewall.uw = 0.5f;
	firewall.vh = 1.0f;
	firewall.drawflag = true;


	firewall.standtextureflag = true;
	firewall.standLRflag = false;
	firewall.standtexturetime = 0.0f;

	firewall.walktextureflag = false;
	firewall.walkLRflag = false;
	firewall.walktexturetime = 0.0f;

	firewall.catchtextureflag = false;
	firewall.catchLRflag = false;
	firewall.catchtexturetime = 0.0f;

	firewall.throwtextureflag = false;
	firewall.throwLRflag = false;
	firewall.throwtexturetime = 0.0f;


	firewall.damagetextureflag = false;
	firewall.damageLRflag = false;
	firewall.damagetexturetime = 0.0f;


	return S_OK;
}

//-----終了処理
void UninitFireWall(void)
{

}

//-----更新処理
void UpdateFireWall(void)
{
	BALL* ball = GetBall();
	PLAYER* player = GetPlayer();
	FIREWALLHP* firewall_hp = GetFireWallHp();
	SKILL* skill = GetSkill();
	BG* bg = GetBG();
	MAP_PLAYER* map_player = GetMapPlayer();
	ENEMYBREAK* enemybreak = GetEnemyBreak();

	if (firewall.drawflag == true)
		FireWallAI();


	//-----コート外に出ない処理
	if (firewall.pos.y <= SCREEN_HEIGHT * 0.27f - firewall.size.y * 0.5f)			//上
		firewall.pos.y = SCREEN_HEIGHT * 0.27f - firewall.size.y * 0.5f;
	if (firewall.pos.y >= SCREEN_HEIGHT - firewall.size.y - SCREEN_HEIGHT * 0.15f)	//下
		firewall.pos.y = SCREEN_HEIGHT - firewall.size.y - SCREEN_HEIGHT * 0.15f;
	if (firewall.pos.x <= bg->clPos.x)								//左
		firewall.pos.x = bg->clPos.x;
	if (firewall.pos.x >= SCREEN_WIDTH - firewall.size.x - SCREEN_WIDTH * 0.003125f)								//右
		firewall.pos.x = SCREEN_WIDTH - firewall.size.x - SCREEN_WIDTH * 0.003125f;


	//-----プレイヤーが投げたボールが、地面,壁に当たらず敵に当たったら敵にダメージを与える(アウト判定)
	if (ball->enemyhitflag == true)
	{
		if (firewall.pos.x < ball->pos.x + ball->size.x && firewall.pos.x + firewall.size.x > ball->pos.x)
		{
			if (firewall.pos.y < ball->pos.y + ball->size.y && firewall.pos.y + firewall.size.y > ball->pos.y)
			{
				firewall.damagetextureflag = true;
				firewall_hp->gaugesize.x = firewall_hp->gaugesize.x - (player->atk - firewall.def) * SCREEN_WIDTH * 0.002f;
				ball->enemyhitflag = false;
			}
		}
	}

	//HPが0になったらmapへ移動する
	if (firewall_hp->gaugesize.x <= 0)
	{
		firewall.drawflag = false;
		if (firewall.getskill == false)
		{
			skill->slot = skill->slot + 1;
			firewall.getskill = true;
		}
		map_player->nextflag = true;
		map_player->UDcount = 0;
		if (firewall.floorflag == false)
		{
			map_player->floor = map_player->floor + 1;
			firewall.floorflag = true;
		}
		enemybreak->drawflag = true;
	}

	//-----アニメーション処理
	firewall_animation();

	//岩石との当たり判定
	firewall.colPos = D3DXVECTOR2(firewall.pos.x + firewall.size.x / 2, firewall.pos.y + firewall.size.y / 2 + firewall.size.y / 4); //当たり判定の座標の更新

	CREATE* create = GetCreate(0);

	if (create->timeflag)
	{
		for (int i = 0; i < 3; i++) // ここの3は生成される岩石の個数を表す。createで数を変更した際はここも変更して下さい。
		{
			CREATE* create = GetCreate(i);

			if (firewall.colPos.x > create->pos.x - create->size.x / 2 && firewall.colPos.x < create->pos.x + create->size.x / 2 &&
				firewall.colPos.y > create->pos.y - create->size.y / 2 && firewall.colPos.y < create->pos.y + create->size.y / 2)
			{
				float ax = 0.0f;
				float ay = 0.0f;
				float bx = 0.0f;
				float by = SCREEN_HEIGHT * 0.5f;
				if (firewall.colPos.x < create->pos.x)
					//岩石の左側
				{
					ax = (create->pos.x - firewall.colPos.x) / create->size.x / 2;
					bx = create->pos.x - create->size.x / 2 - firewall.size.x / 2;
				}
				else if (firewall.colPos.x > create->pos.x)
					//岩石の右側
				{
					ax = (firewall.colPos.x - create->pos.x) / create->size.x / 2;
					bx = create->pos.x + create->size.x / 2 - firewall.size.x / 2;
				}

				if (firewall.colPos.y < create->pos.y)
					//岩石の上側
				{
					ay = (create->pos.y - firewall.colPos.y) / create->size.y / 2;
					by = create->pos.y - create->size.y / 2 - firewall.size.y / 2 - firewall.size.y / 4;
				}
				else if (firewall.colPos.y > create->pos.y)
					//岩石の下側
				{
					ay = (firewall.colPos.y - create->pos.y) / create->size.y / 2;
					by = create->pos.y + create->size.y / 2 - firewall.size.y / 2 - firewall.size.y / 4;
				}

				if (ax > ay)
				{
					firewall.pos.x = bx;
				}
				else if (ax < ay)
				{
					firewall.pos.y = by;
				}
				else
				{
					firewall.pos.x = create->pos.x - create->size.x / 2 - firewall.size.x / 2;
				}
			}
		}
	}
}

//-----描画処理
void DrawFireWall(void)
{
	
	DrawSpriteLeftTop(enemytexture, firewall.pos.x, firewall.pos.y,firewall.size.x, firewall.size.y, 0.f, 0.f, 1.f, 1.f);

	//if (firewall.drawflag == true)
	//{
	//	if (firewall.catchtextureflag == false)
	//	{
	//		//止まってるとき && (右向いてるとき || 左向いてるとき)
	//		if (firewall.walktextureflag == false && firewall.standLRflag == false)
	//			DrawSpriteLeftTop(firewall.stand_Ltexture, firewall.pos.x, firewall.pos.y,
	//				firewall.size.x, firewall.size.y, firewall.u, firewall.v, firewall.uw, firewall.vh);
	//		if (firewall.walktextureflag == false && firewall.standLRflag == true)
	//

	//		//動いてるとき && (右向いてるとき || 左向いてるとき)
	//		if (firewall.walktextureflag == true && firewall.walkLRflag == false)
	//			DrawSpriteLeftTop(firewall.walk_Ltexture, firewall.pos.x, firewall.pos.y,
	//				firewall.size.x, firewall.size.y, firewall.u, firewall.v, firewall.uw, firewall.vh);
	//		if (firewall.walktextureflag == true && firewall.walkLRflag == true)
	//			DrawSpriteLeftTop(firewall.walk_Rtexture, firewall.pos.x, firewall.pos.y,
	//				firewall.size.x, firewall.size.y, firewall.u, firewall.v, firewall.uw, firewall.vh);
	//	}

	//	//キャッチしたとき && (右向いてるとき || 左向いてるとき)
	//	if (firewall.catchtextureflag == true && firewall.catchLRflag == false)
	//		DrawSpriteLeftTop(firewall.catch_Ltexture, firewall.pos.x, firewall.pos.y,
	//			firewall.size.x, firewall.size.y, firewall.u, firewall.v, firewall.uw, firewall.vh);
	//	if (firewall.catchtextureflag == true && firewall.catchLRflag == true)
	//		DrawSpriteLeftTop(firewall.catch_Rtexture, firewall.pos.x, firewall.pos.y,
	//			firewall.size.x, firewall.size.y, firewall.u, firewall.v, firewall.uw, firewall.vh);
	//}

	//死んだとき
	//if (firewall.drawflag == false)
	//	DrawSpriteLeftTop(firewall.deathtexture, firewall.pos.x, firewall.pos.y, 
	//							firewall.size.x, firewall.size.y, firewall.u, firewall.v, firewall.uw, firewall.vh);
}

//-----構造体ポインタ取得処理
FIREWALL* GetFireWall(void)
{
	return &firewall;
}