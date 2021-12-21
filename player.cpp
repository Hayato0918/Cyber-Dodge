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
#include "slime.h"

#include "player_operate.h"
#include "player_animation.h"
#include "player_damage.h"

#include "ball.h"
#include "catch.h"
#include "skill.h"
#include "invade.h"
#include "player_hp.h"
#include "skillrandom.h"

#include "map_point.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
PLAYER player;

//-----初期化処理
HRESULT InitPlayer(void)
{
	InitSkill();

	MAP_PLAYER* map_player = GetMapPlayer();

	if (map_player->gamecount == 1)
	{
		player.pos = D3DXVECTOR2(240.0f, 320.0f);
		player.size = D3DXVECTOR2(200.0f, 240.0f);
		player.move = D3DXVECTOR2(4.0f, 4.0f);
		player.rotate = 3;
		player.drawflag = true;

		player.atk = 150;
		player.def = 0;

		player.u = 0.0f;
		player.v = 0.0f;
		player.uw = 0.5f;
		player.vh = 1.0f;

		//立ち状態のテクスチャ設定
		player.stand_Ltexture = LoadTexture("data/TEXTURE/player/stand/orgnl_stand_L.png");
		player.stand_Rtexture = LoadTexture("data/TEXTURE/player/stand/orgnl_stand_R.png");
		player.standtextureflag = true;
		player.standLRflag = false;
		//歩き状態のテクスチャ設定
		player.walk_Ltexture = LoadTexture("data/TEXTURE/player/walk/orgnl_walk_L.png");
		player.walk_Rtexture = LoadTexture("data/TEXTURE/player/walk/orgnl_walk_R.png");
		player.walktextureflag = false;
		player.walkLRflag = false;
		//キャッチ状態のテクスチャ設定
		player.catch_Ltexture = LoadTexture("data/TEXTURE/player/catch/orgnl_catch_L.png");
		player.catch_Rtexture = LoadTexture("data/TEXTURE/player/catch/orgnl_catch_R.png");
		player.catchtextureflag = false;
		player.catchLRflag = false;
		player.catchtexturetime = 0.0f;
		//拾い状態のテクスチャ設定
		player.pick_Ltexture = LoadTexture("data/TEXTURE/player/pick/orgnl_pick_L.png");
		player.pick_Rtexture = LoadTexture("data/TEXTURE/player/pick/orgnl_pick_R.png");
		player.picktextureflag = false;
		player.pickLRflag = false;
		player.picktexturetime = 0.0f;
		//投げ状態のテクスチャ設定
		player.throw_Ltexture = LoadTexture("data/TEXTURE/player/throw/orgnl_throw_L.png");
		player.throw_Rtexture = LoadTexture("data/TEXTURE/player/throw/orgnl_throw_R.png");
		player.throwtextureflag = false;
		player.throwLRflag = false;
		player.throwtexturetime = 0.0f;
		//スキル使用時のテクスチャ設定
		player.skill_Ltexture = LoadTexture("data/TEXTURE/player/skill/orgnl_skill_L.png");
		player.skill_Rtexture = LoadTexture("data/TEXTURE/player/skill/orgnl_skill_R.png");
		player.skilltextureflag = false;
		player.skillLRflag = false;
		player.skilltexturetime = 0.0f;
		player.skilluseflag = false;
		//ダメージ状態のテクスチャ設定
		player.damage_Ltexture = LoadTexture("data/TEXTURE/player/damage/orgnl_damage_L.png");
		player.damage_Rtexture = LoadTexture("data/TEXTURE/player/damage/orgnl_damage_R.png");
		player.damagetextureflag = false;
		player.damageLRflag = false;
		player.damagetexturetime = 0.0f;
		//死亡時のテクスチャ設定
		player.deathtexture = LoadTexture("data/TEXTURE/player/death/orgnl_death.png");

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

	//-----操作処理
	player_operate();

	//-----コート外に出ない処理
	if (player.pos.y <= 230.f - player.size.y * 0.5f)	//上
		player.pos.y = 230.f - player.size.y * 0.5f;
	if (player.pos.y >= SCREEN_HEIGHT - player.size.y - 15 - 120)	//下
		player.pos.y = SCREEN_HEIGHT - player.size.y - 15 - 120;
	if (player.pos.x <= 0 + 15)		//左
		player.pos.x = 0 + 15;

	if (invade->timeflag == false)		//不法侵入スキルの判別
	{
		if (player.pos.x >= SCREEN_WIDTH * 0.5f - player.size.x - 5)	//右
			player.pos.x = SCREEN_WIDTH * 0.5f - player.size.x - 5;
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
	Player_FireWallDamage();

	//-----死亡判定
	if (hp->gaugesize.x <= 0)
	{
		player.drawflag = false;
		SceneTransition(SCENE_MAP);
	}

	//-----アニメーション処理
	player_animation();

	//-----スキル処理
	_Skill();
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

	//-----スキル描画
	DrawSkill();
}

//-----構造体ポインタ取得処理
PLAYER* GetPlayer(void)
{
	return &player;
}