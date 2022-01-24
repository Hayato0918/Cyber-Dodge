//デリーター処理 [deleter.cpp]
#include "deleter.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "scene.h"
#include "fade.h"

#include "player.h"
#include "bg.h"
#include "ball.h"
#include "catch.h"
#include "deleter_animation.h"
#include "deleter_hp.h"
#include "deleterAI.h"
#include "skillrandom.h"
#include "create.h"
#include "map_player.h"
#include "enemybreak.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
DELETER deleter;

//-----初期化処理
HRESULT InitDeleter(void)
{
	deleter.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.355555f);
	deleter.size = D3DXVECTOR2(SCREEN_WIDTH * 0.16f, SCREEN_HEIGHT * 0.2844444f);
	deleter.move = D3DXVECTOR2(SCREEN_WIDTH * 0.00125f, SCREEN_HEIGHT * 0.002222f);
	deleter.colPos = D3DXVECTOR2(deleter.pos.x + deleter.size.x / 2, deleter.pos.y + deleter.size.y / 2 + deleter.size.y / 4);
	deleter.rotate = 2;

	deleter.atk = 150;
	deleter.def = 50;

	deleter.getskill = false;

	deleter.u = 0.0f;
	deleter.v = 0.0f;
	deleter.uw = 0.5f;
	deleter.vh = 1.0f;
	deleter.drawflag = true;

	deleter.stand_Ltexture = LoadTexture("data/TEXTURE/enemy/firewall/stand/stand_R.png");
	deleter.stand_Rtexture = LoadTexture("data/TEXTURE/enemy/firewall/stand/stand_L.png");
	deleter.standtextureflag = true;
	deleter.standLRflag = false;
	deleter.standtexturetime = 0.0f;

	deleter.walk_Ltexture = LoadTexture("data/TEXTURE/enemy/firewall/walk/walk_R.png");
	deleter.walk_Rtexture = LoadTexture("data/TEXTURE/enemy/firewall/walk/walk_L.png");
	deleter.walktextureflag = false;
	deleter.walkLRflag = false;
	deleter.walktexturetime = 0.0f;

	deleter.throw_Ltexture = LoadTexture("data/TEXTURE/enemy/firewall/throw/throw_R.png");
	deleter.throw_Rtexture = LoadTexture("data/TEXTURE/enemy/firewall/throw/throw_L.png");
	deleter.throwtextureflag = false;
	deleter.throwLRflag = false;
	deleter.throwtexturetime = 0.0f;

	deleter.damage_Ltexture = LoadTexture("data/TEXTURE/enemy/firewall/damage/damage_R.png");
	deleter.damage_Rtexture = LoadTexture("data/TEXTURE/enemy/firewall/damage/damage_L.png");
	deleter.damagetextureflag = false;
	deleter.damageLRflag = false;
	deleter.damagetexturetime = 0.0f;

	deleter.deathtexture = LoadTexture("data/TEXTURE/enemy/firewall/death/death.png");

	return S_OK;
}

//-----終了処理
void UninitDeleter(void)
{

}

//-----更新処理
void UpdateDeleter(void)
{
	BALL* ball = GetBall();
	PLAYER* player = GetPlayer();
	DELETERHP* deleter_hp = GetDeleterHp();
	SKILL* skill = GetSkill();
	BG* bg = GetBG();
	MAP_PLAYER* map_player = GetMapPlayer();
	ENEMYBREAK* enemybreak = GetEnemyBreak();

	if (deleter.drawflag == true)
		DeleterAI();

	//-----コート外に出ない処理
	if (deleter.pos.y <= SCREEN_HEIGHT * 0.27f - deleter.size.y * 0.5f)			//上
		deleter.pos.y = SCREEN_HEIGHT * 0.27f - deleter.size.y * 0.5f;
	if (deleter.pos.y >= SCREEN_HEIGHT - deleter.size.y - SCREEN_HEIGHT * 0.188888f)	//下
		deleter.pos.y = SCREEN_HEIGHT - deleter.size.y - SCREEN_HEIGHT * 0.188888f;
	if (deleter.pos.x <= bg->clPos.x)								//左
		deleter.pos.x = bg->clPos.x;
	if (deleter.pos.x >= SCREEN_WIDTH - deleter.size.x - SCREEN_WIDTH * 0.003125f)								//右
		deleter.pos.x = SCREEN_WIDTH - deleter.size.x - SCREEN_WIDTH * 0.003125f;


	//-----プレイヤーが投げたボールが、地面,壁に当たらず敵に当たったら敵にダメージを与える(アウト判定)
	if (ball->enemyhitflag == true)
	{
		if (deleter.pos.x < ball->pos.x + ball->size.x && deleter.pos.x + deleter.size.x > ball->pos.x)
		{
			if (deleter.pos.y < ball->pos.y + ball->size.y && deleter.pos.y + deleter.size.y > ball->pos.y)
			{
				deleter.damagetextureflag = true;
				deleter_hp->gaugesize.x = deleter_hp->gaugesize.x - (player->atk - deleter.def) * SCREEN_WIDTH * 0.002f;
				ball->enemyhitflag = false;
			}
		}
	}

	//HPが0になったらmapへ移動する
	if (deleter_hp->gaugesize.x <= 0)
	{
		deleter.drawflag = false;
		if (deleter.getskill == false)
		{
			skill->slot = skill->slot + 1;
			deleter.getskill = true;
		}
		map_player->nextflag = true;
		enemybreak->drawflag = true;
	}

	//-----アニメーション処理
	deleter_animation();

	//岩石との当たり判定
	deleter.colPos = D3DXVECTOR2(deleter.pos.x + deleter.size.x / 2, deleter.pos.y + deleter.size.y / 2 + deleter.size.y / 4); //当たり判定の座標の更新

	CREATE* create = GetCreate(0);

	if (create->timeflag)
	{
		for (int i = 0; i < 3; i++) // ここの3は生成される岩石の個数を表す。createで数を変更した際はここも変更して下さい。
		{
			CREATE* create = GetCreate(i);

			if (deleter.colPos.x > create->pos.x - create->size.x / 2 && deleter.colPos.x < create->pos.x + create->size.x / 2 &&
				deleter.colPos.y > create->pos.y - create->size.y / 2 && deleter.colPos.y < create->pos.y + create->size.y / 2)
			{
				float ax = 0.0f;
				float ay = 0.0f;
				float bx = 0.0f;
				float by = SCREEN_HEIGHT * 0.5f;
				if (deleter.colPos.x < create->pos.x)
					//岩石の左側
				{
					ax = (create->pos.x - deleter.colPos.x) / create->size.x / 2;
					bx = create->pos.x - create->size.x / 2 - deleter.size.x / 2;
				}
				else if (deleter.colPos.x > create->pos.x)
					//岩石の右側
				{
					ax = (deleter.colPos.x - create->pos.x) / create->size.x / 2;
					bx = create->pos.x + create->size.x / 2 - deleter.size.x / 2;
				}

				if (deleter.colPos.y < create->pos.y)
					//岩石の上側
				{
					ay = (create->pos.y - deleter.colPos.y) / create->size.y / 2;
					by = create->pos.y - create->size.y / 2 - deleter.size.y / 2 - deleter.size.y / 4;
				}
				else if (deleter.colPos.y > create->pos.y)
					//岩石の下側
				{
					ay = (deleter.colPos.y - create->pos.y) / create->size.y / 2;
					by = create->pos.y + create->size.y / 2 - deleter.size.y / 2 - deleter.size.y / 4;
				}

				if (ax > ay)
				{
					deleter.pos.x = bx;
				}
				else if (ax < ay)
				{
					deleter.pos.y = by;
				}
				else
				{
					deleter.pos.x = create->pos.x - create->size.x / 2 - deleter.size.x / 2;
				}
			}
		}
	}
}

//-----描画処理
void DrawDeleter(void)
{
	if (deleter.drawflag == true)
	{
		//止まってるとき && (右向いてるとき || 左向いてるとき)
		if (deleter.walktextureflag == false && deleter.standLRflag == false)
			DrawSpriteLeftTop(deleter.stand_Ltexture, deleter.pos.x, deleter.pos.y,
				deleter.size.x, deleter.size.y, deleter.u, deleter.v, deleter.uw, deleter.vh);
		if (deleter.walktextureflag == false && deleter.standLRflag == true)
			DrawSpriteLeftTop(deleter.stand_Rtexture, deleter.pos.x, deleter.pos.y,
				deleter.size.x, deleter.size.y, deleter.u, deleter.v, deleter.uw, deleter.vh);

		//動いてるとき && (右向いてるとき || 左向いてるとき)
		if (deleter.walktextureflag == true && deleter.walkLRflag == false)
			DrawSpriteLeftTop(deleter.walk_Ltexture, deleter.pos.x, deleter.pos.y,
				deleter.size.x, deleter.size.y, deleter.u, deleter.v, deleter.uw, deleter.vh);
		if (deleter.walktextureflag == true && deleter.walkLRflag == true)
			DrawSpriteLeftTop(deleter.walk_Rtexture, deleter.pos.x, deleter.pos.y,
				deleter.size.x, deleter.size.y, deleter.u, deleter.v, deleter.uw, deleter.vh);
	}

	//死んだとき
	if (deleter.drawflag == false)
		DrawSpriteLeftTop(deleter.deathtexture, deleter.pos.x, deleter.pos.y,
			deleter.size.x, deleter.size.y, deleter.u, deleter.v, deleter.uw, deleter.vh);
}

//-----構造体ポインタ取得処理
DELETER* GetDeleter(void)
{
	return &deleter;
}