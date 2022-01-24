//プレイヤー処理 [player.cpp]
#include "player.h"
//システム.h
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "scene.h"
#include "fade.h"
//エネミー.h
#include "firewall.h"
#include "deleter.h"
#include "slime.h"
//プレイヤー.h
#include "player_operate.h"
#include "player_animation.h"
#include "player_damage.h"
#include "player_hp.h"
//ボール.h
#include "ball.h"
#include "catch.h"
//マップ.h
#include "map_player.h"
//スキル.h
#include "skill.h"
#include "skillrandom.h"
#include "invade.h"
#include "create.h"
#include "bg.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
PLAYER player;

//-----初期化処理
HRESULT InitPlayer(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	player.pos = D3DXVECTOR2(240.0f, 320.0f);
	player.size = D3DXVECTOR2(200.0f, 240.0f);
	player.move = D3DXVECTOR2(4.0f, 4.0f);
	player.rotate = 3;
	player.drawflag = true;

	player.u = 0.0f;
	player.v = 0.0f;
	player.uw = 0.5f;
	player.vh = 1.0f;

	if (map_player->gamecount == 1)
	{
		player.atk = 100;
		player.def = 0;
		player.gold = 1000;

		//立ち状態のテクスチャ設定
		player.stand_Ltexture = LoadTexture("data/TEXTURE/player/stand/stand_R.png");
		player.stand_Rtexture = LoadTexture("data/TEXTURE/player/stand/stand_L.png");
		player.standtextureflag = true;
		player.standLRflag = false;
		//歩き状態のテクスチャ設定
		player.walk_Ltexture = LoadTexture("data/TEXTURE/player/walk/walk_R.png");
		player.walk_Rtexture = LoadTexture("data/TEXTURE/player/walk/walk_L.png");
		player.walktextureflag = false;
		player.walkLRflag = false;
		//キャッチ状態のテクスチャ設定
		player.catch_Ltexture = LoadTexture("data/TEXTURE/player/catch/catch_R.png");
		player.catch_Rtexture = LoadTexture("data/TEXTURE/player/catch/catch_L.png");
		player.catchtextureflag = false;
		player.catchLRflag = false;
		player.catchtexturetime = 0.0f;
		//拾い状態のテクスチャ設定
		player.pick_Ltexture = LoadTexture("data/TEXTURE/player/pick/pick_R.png");
		player.pick_Rtexture = LoadTexture("data/TEXTURE/player/pick/pick_L.png");
		player.picktextureflag = false;
		player.pickLRflag = false;
		player.picktexturetime = 0.0f;
		//投げ状態のテクスチャ設定
		player.throw_Ltexture = LoadTexture("data/TEXTURE/player/throw/throw_R.png");
		player.throw_Rtexture = LoadTexture("data/TEXTURE/player/throw/throw_L.png");
		player.throwtextureflag = false;
		player.throwLRflag = false;
		player.throwtexturetime = 0.0f;
		//スキル使用時のテクスチャ設定
		player.skill_Ltexture = LoadTexture("data/TEXTURE/player/skill/skill_R.png");
		player.skill_Rtexture = LoadTexture("data/TEXTURE/player/skill/skill_L.png");
		player.skilltextureflag = false;
		player.skillLRflag = false;
		player.skilltexturetime = 0.0f;
		player.skilluseflag = false;
		//ダメージ状態のテクスチャ設定
		player.damage_Ltexture = LoadTexture("data/TEXTURE/player/damage/damage_R.png");
		player.damage_Rtexture = LoadTexture("data/TEXTURE/player/damage/damage_L.png");
		player.damagetextureflag = false;
		player.damageLRflag = false;
		player.damagetexturetime = 0.0f;
		//死亡時のテクスチャ設定
		player.deathtexture = LoadTexture("data/TEXTURE/player/death/death.png");

		player.drawdepth = false;
	}

	return S_OK;
}

//-----終了処理
void UninitPlayer(void)
{

}

//-----更新処理
void UpdatePlayer(void)
{
	BALL* ball = GetBall();
	INVADE* invade = GetInvade();
	PLAYERHP* hp = GetPlayerHp();
	MAP_PLAYER* map_player = GetMapPlayer();
	BG* bg = GetBG();

	//-----操作処理
	player_operate();

	//-----コート外に出ない処理
	if (player.pos.y <= 230.f - player.size.y * 0.5f)	//上
		player.pos.y = 230.f - player.size.y * 0.5f;
	if (player.pos.y >= SCREEN_HEIGHT - player.size.y - 15 - 120)	//下
		player.pos.y = SCREEN_HEIGHT - player.size.y - 15 - 120;
	for (int i = 0; i < 100; i++)
	{
		if (player.pos.y <= 525 - 4.15f * i)
		{
			if (player.pos.x <= 1.55f * i + 10)		//左
				player.pos.x = 1.55f * i + 10;
		}
	}

	if (invade->timeflag == false)		//不法侵入スキルの判別
	{
		if (player.pos.x >= bg->clPos.x - player.size.x - 5)	//右
			player.pos.x = bg->clPos.x - player.size.x - 5;
	}
	if (invade->timeflag == true)
	{
		if (player.pos.x >= SCREEN_WIDTH - player.size.x - 5)	//右
			player.pos.x = SCREEN_WIDTH - player.size.x - 5;
	}

	//-----プレイヤーとボールの描画順を整える計算
	if (player.pos.y + player.size.y - ball->size.y >= ball->pos.y)
		player.drawdepth = false;
	if (player.pos.y + player.size.y - ball->size.y < ball->pos.y)
		player.drawdepth = true;

	//-----ダメージ処理
	if(map_player->encount == 1)
		Player_SlimeDamage();
	if (map_player->encount == 2)
		Player_DeleterDamage();
	if (map_player->encount == 3)
		Player_FireWallDamage();

	//-----死亡判定
	if (hp->gaugesize.x <= 0)
	{
		player.drawflag = false;
		SceneTransition(SCENE_GAMEOVER);
	}

	//-----アニメーション処理
	player_animation();

	//岩石との当たり判定
	player.colPos = D3DXVECTOR2(player.pos.x + player.size.x / 2, player.pos.y + player.size.y / 2 + player.size.y / 4); //当たり判定の座標の更新

	CREATE* create = GetCreate(0);

	if (create->timeflag)
	{
		for (int i = 0; i < 3; i++) // ここの3は生成される岩石の個数を表す。createで数を変更した際はここも変更して下さい。
		{
			CREATE* create = GetCreate(i);

			if (player.colPos.x > create->pos.x - create->size.x / 2 && player.colPos.x < create->pos.x + create->size.x / 2 &&
				player.colPos.y > create->pos.y - create->size.y / 2 && player.colPos.y < create->pos.y + create->size.y / 2)
			{
				float ax = 0.0f;
				float ay = 0.0f;
				float bx = 0.0f;
				float by = 450.0f;
				if (player.colPos.x < create->pos.x)
					//岩石の左側
				{
					ax = (create->pos.x - player.colPos.x) / create->size.x / 2;
					bx = create->pos.x - create->size.x / 2 - player.size.x / 2;
				}
				else if (player.colPos.x > create->pos.x)
					//岩石の右側
				{
					ax = (player.colPos.x - create->pos.x) / create->size.x / 2;
					bx = create->pos.x + create->size.x / 2 - player.size.x / 2;
				}

				if (player.colPos.y < create->pos.y)
					//岩石の上側
				{
					ay = (create->pos.y - player.colPos.y) / create->size.y / 2;
					by = create->pos.y - create->size.y / 2 - player.size.y / 2 - player.size.y / 4;
				}
				else if (player.colPos.y > create->pos.y)
					//岩石の下側
				{
					ay = (player.colPos.y - create->pos.y) / create->size.y / 2;
					by = create->pos.y + create->size.y / 2 - player.size.y / 2 - player.size.y / 4;
				}

				if (ax > ay)
				{
					player.pos.x = bx;
				}
				else if (ax < ay)
				{
					player.pos.y = by;
				}
				else
				{
					player.pos.x = create->pos.x - create->size.x / 2 - player.size.x / 2;
				}
			}
		}
	}
}

//-----描画処理
void DrawPlayer(void)
{
	if (player.drawflag == true)
	{
		if (player.damagetextureflag == false)	//ダメージモーションを優先
		{
			if (player.catchtextureflag == false)	//キャッチモーションを優先
			{
				if (player.picktextureflag == false)	//ピックモーションを優先
				{
					if (player.throwtextureflag == false)	//投げモーションを優先
					{
						if (player.skilltextureflag == false)	//スキルモーションを優先
						{
							//止まってるとき && (右向いてるとき || 左向いてるとき)
							if (player.walktextureflag == false && player.standLRflag == false)
								DrawSpriteLeftTop(player.stand_Ltexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
							if (player.walktextureflag == false && player.standLRflag == true)
								DrawSpriteLeftTop(player.stand_Rtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);

							//動いているとき && (右向いてるとき || 左向いてるとき)
							if (player.walktextureflag == true && player.walkLRflag == false)
								DrawSpriteLeftTop(player.walk_Ltexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
							if (player.walktextureflag == true && player.walkLRflag == true)
								DrawSpriteLeftTop(player.walk_Rtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
						}
					}
				}
			}
		}

		if (player.damagetextureflag == false)	//ダメージモーションを優先
		{
			//キャッチしたとき && (右向いてるとき || 左向いてるとき)
			if (player.catchtextureflag == true && player.catchLRflag == false)
				DrawSpriteLeftTop(player.catch_Ltexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
			if (player.catchtextureflag == true && player.catchLRflag == true)
				DrawSpriteLeftTop(player.catch_Rtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);

			//落ちているボールを拾ったとき && (右向いてるとき || 左向いてるとき)
			if (player.picktextureflag == true && player.pickLRflag == false)
				DrawSpriteLeftTop(player.pick_Ltexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
			if (player.picktextureflag == true && player.pickLRflag == true)
				DrawSpriteLeftTop(player.pick_Rtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);

			//投げたとき && ((右向いてるとき || 左向いてるとき))
			if (player.throwtextureflag == true && player.throwLRflag == false)
				DrawSpriteLeftTop(player.throw_Ltexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
			if (player.throwtextureflag == true && player.throwLRflag == true)
				DrawSpriteLeftTop(player.throw_Rtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);

			//スキルを使ったとき && ((右向いてるとき || 左向いてるとき))
			if (player.skilltextureflag == true && player.skillLRflag == false)
				DrawSpriteLeftTop(player.skill_Ltexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
			if (player.skilltextureflag == true && player.skillLRflag == true)
				DrawSpriteLeftTop(player.skill_Rtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
		}

		//ダメージを受けたとき && (右向いてるとき || 左向いてるとき)
		if (player.damagetextureflag == true && player.damageLRflag == false)
			DrawSpriteLeftTop(player.damage_Ltexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
		if (player.damagetextureflag == true && player.damageLRflag == true)
			DrawSpriteLeftTop(player.damage_Rtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
	}

	if (player.drawflag == false)	//死亡時
		DrawSpriteLeftTop(player.deathtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
}

//-----構造体ポインタ取得処理
PLAYER* GetPlayer(void)
{
	return &player;
}