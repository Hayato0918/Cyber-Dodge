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
	firewall.colPos = D3DXVECTOR2(firewall.pos.x + firewall.size.x / 2, firewall.pos.y + firewall.size.y / 2 + firewall.size.y / 4);
	firewall.rotate = 2;

	firewall.atk = 150;
	firewall.def = 50;

	firewall.getskill = false;

	firewall.u = 0.0f;
	firewall.v = 0.0f;
	firewall.uw = 0.5f;
	firewall.vh = 1.0f;
	firewall.drawflag = true;

	firewall.stand_Ltexture = LoadTexture("data/TEXTURE/enemy/firewall/stand/stand_R.png");
	firewall.stand_Rtexture = LoadTexture("data/TEXTURE/enemy/firewall/stand/stand_L.png");
	firewall.standtextureflag = true;
	firewall.standLRflag = false;
	firewall.standtexturetime = 0.0f;

	firewall.walk_Ltexture = LoadTexture("data/TEXTURE/enemy/firewall/walk/walk_R.png");
	firewall.walk_Rtexture = LoadTexture("data/TEXTURE/enemy/firewall/walk/walk_L.png");
	firewall.walktextureflag = false;
	firewall.walkLRflag = false;
	firewall.walktexturetime = 0.0f;

	firewall.throw_Ltexture = LoadTexture("data/TEXTURE/enemy/firewall/throw/throw_R.png");
	firewall.throw_Rtexture = LoadTexture("data/TEXTURE/enemy/firewall/throw/throw_L.png");
	firewall.throwtextureflag = false;
	firewall.throwLRflag = false;
	firewall.throwtexturetime = 0.0f;

	firewall.damage_Ltexture = LoadTexture("data/TEXTURE/enemy/firewall/damage/damage_R.png");
	firewall.damage_Rtexture = LoadTexture("data/TEXTURE/enemy/firewall/damage/damage_L.png");
	firewall.damagetextureflag = false;
	firewall.damageLRflag = false;
	firewall.damagetexturetime = 0.0f;

	firewall.deathtexture = LoadTexture("data/TEXTURE/enemy/firewall/death/death.png");

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

	if (firewall.drawflag == true)
		FireWallAI();


	//-----コート外に出ない処理
	if (firewall.pos.y <= 180 - firewall.size.y * 0.5f)			//上
		firewall.pos.y = 180 - firewall.size.y * 0.5f;
	if (firewall.pos.y >= SCREEN_HEIGHT - firewall.size.y - 15 -120)	//下
		firewall.pos.y = SCREEN_HEIGHT - firewall.size.y - 15 -120;
	if (firewall.pos.x <= bg->clPos.x)								//左
		firewall.pos.x = bg->clPos.x;
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
		map_player->nextflag = true;
		SceneTransition(SCENE_MAP);
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
				float by = 450.0f;
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