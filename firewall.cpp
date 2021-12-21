//ファイアーウォール処理 [firewall.cpp]
#include "firewall.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "scene.h"
#include "fade.h"

#include "player.h"
#include "ball.h"
#include "catch.h"
#include "firewall_animation.h"
#include "firewall_hp.h"
#include "firewallAI.h"
#include "skillrandom.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
FIREWALL firewall;

//-----初期化処理
HRESULT InitFireWall(void)
{
	firewall.pos = D3DXVECTOR2(800.0f, 320.0f);
	firewall.size = D3DXVECTOR2(256.0f, 256.0f);
	firewall.move = D3DXVECTOR2(2.0f, 2.0f);
	firewall.rotate = 2;

	firewall.atk = 150;
	firewall.def = 50;

	firewall.getskill = false;

	firewall.u = 0.0f;
	firewall.v = 0.0f;
	firewall.uw = 0.5f;
	firewall.vh = 1.0f;
	firewall.drawflag = true;

	firewall.stand_Ltexture = LoadTexture("data/TEXTURE/enemy/stand/orgnl_stand_L.png");
	firewall.stand_Rtexture = LoadTexture("data/TEXTURE/enemy/stand/orgnl_stand_R.png");
	firewall.standtextureflag = true;
	firewall.standLRflag = false;
	firewall.standtexturetime = 0.0f;

	firewall.walk_Ltexture = LoadTexture("data/TEXTURE/enemy/walk/orgnl_walk_L.png");
	firewall.walk_Rtexture = LoadTexture("data/TEXTURE/enemy/walk/orgnl_walk_R.png");
	firewall.walktextureflag = false;
	firewall.walkLRflag = false;
	firewall.walktexturetime = 0.0f;

	firewall.throw_Ltexture = LoadTexture("data/TEXTURE/enemy/throw/orgnl_throw_L.png");
	firewall.throw_Rtexture = LoadTexture("data/TEXTURE/enemy/throw/orgnl_throw_R.png");
	firewall.throwtextureflag = false;
	firewall.throwLRflag = false;
	firewall.throwtexturetime = 0.0f;

	firewall.damage_Ltexture = LoadTexture("data/TEXTURE/enemy/damage/orgnl_damage_L.png");
	firewall.damage_Rtexture = LoadTexture("data/TEXTURE/enemy/damage/orgnl_damage_R.png");
	firewall.damagetextureflag = false;
	firewall.damageLRflag = false;
	firewall.damagetexturetime = 0.0f;

	firewall.deathtexture = LoadTexture("data/TEXTURE/enemy/death/orgnl_death.png");

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

	if (firewall.drawflag == true)
		FireWallAI();

	//-----コート外に出ない処理
	if (firewall.pos.y <= 180 - firewall.size.y * 0.5f)			//上
		firewall.pos.y = 180 - firewall.size.y * 0.5f;
	if (firewall.pos.y >= SCREEN_HEIGHT - firewall.size.y - 15 -120)	//下
		firewall.pos.y = SCREEN_HEIGHT - firewall.size.y - 15 -120;
	if (firewall.pos.x <= SCREEN_WIDTH * 0.5f)								//左
		firewall.pos.x = SCREEN_WIDTH * 0.5f;
	if (firewall.pos.x >= SCREEN_WIDTH - firewall.size.x - 5)								//右
		firewall.pos.x = SCREEN_WIDTH - firewall.size.x - 5;


	//-----プレイヤーが投げたボールが、地面,壁に当たらず敵に当たったら敵にダメージを与える(アウト判定)
	if (ball->enemyhitflag == true)
	{
		if (firewall.pos.x < ball->pos.x + ball->size.x && firewall.pos.x + firewall.size.x > ball->pos.x)
		{
			if (firewall.pos.y < ball->pos.y + ball->size.y && firewall.pos.y + firewall.size.y > ball->pos.y)
			{
				firewall.damagetextureflag = true;
				firewall_hp->gaugesize.x = firewall_hp->gaugesize.x - (player->atk - firewall.def) * 3.2f;
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
		SceneTransition(SCENE_MAP);
	}

	//-----アニメーション処理
	firewall_animation();


}

//-----描画処理
void DrawFireWall(void)
{
	if (firewall.drawflag == true)
	{
		//止まってるとき && (右向いてるとき || 左向いてるとき)
		if (firewall.walktextureflag == false && firewall.standLRflag == false)
			DrawSpriteLeftTop(firewall.stand_Ltexture, firewall.pos.x, firewall.pos.y, 
								firewall.size.x, firewall.size.y, firewall.u, firewall.v, firewall.uw, firewall.vh);
		if (firewall.walktextureflag == false && firewall.standLRflag == true)
			DrawSpriteLeftTop(firewall.stand_Rtexture, firewall.pos.x, firewall.pos.y, 
								firewall.size.x, firewall.size.y, firewall.u, firewall.v, firewall.uw, firewall.vh);

		//動いてるとき && (右向いてるとき || 左向いてるとき)
		if (firewall.walktextureflag == true && firewall.walkLRflag == false)
			DrawSpriteLeftTop(firewall.walk_Ltexture, firewall.pos.x, firewall.pos.y, 
								firewall.size.x, firewall.size.y, firewall.u, firewall.v, firewall.uw, firewall.vh);
		if (firewall.walktextureflag == true && firewall.walkLRflag == true)
			DrawSpriteLeftTop(firewall.walk_Rtexture, firewall.pos.x, firewall.pos.y, 
								firewall.size.x, firewall.size.y, firewall.u, firewall.v, firewall.uw, firewall.vh);
	}

	//死んだとき
	if (firewall.drawflag == false)
		DrawSpriteLeftTop(firewall.deathtexture, firewall.pos.x, firewall.pos.y, 
								firewall.size.x, firewall.size.y, firewall.u, firewall.v, firewall.uw, firewall.vh);
}

//-----構造体ポインタ取得処理
FIREWALL* GetFireWall(void)
{
	return &firewall;
}