//プレイヤー処理 [player.cpp]
#include "player.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "escape.h"
#include "ball.h"
#include "catch.h"
#include "skill.h"
#include "invade.h"
#include "player_hp.h"

#include "reverse.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
PLAYER player;

//-----初期化処理
HRESULT InitPlayer(void)
{
	player.pos = D3DXVECTOR2(240.0f, 320.0f);
	player.size = D3DXVECTOR2(200.0f, 240.0f);
	player.move = D3DXVECTOR2(4.0f, 4.0f);
	player.rotate = 3;
	player.drawflag = true;

	player.u = 0.0f;
	player.v = 0.0f;
	player.uw = 0.5f;
	player.vh = 1.0f;

	player.stand_Ltexture = LoadTexture("data/TEXTURE/player/stand/stand_L.png");
	player.stand_Rtexture = LoadTexture("data/TEXTURE/player/stand/stand_R.png");
	player.standtextureflag = true;
	player.standLRflag = false;

	player.walk_Ltexture = LoadTexture("data/TEXTURE/player/walk/walk_L.png");
	player.walk_Rtexture = LoadTexture("data/TEXTURE/player/walk/walk_R.png");
	player.walktextureflag = false;
	player.walkLRflag = false;

	player.catch_Ltexture = LoadTexture("data/TEXTURE/player/catch/catch_L.png");
	player.catch_Rtexture = LoadTexture("data/TEXTURE/player/catch/catch_R.png");
	player.catchtextureflag = false;
	player.catchLRflag = false;
	player.catchtexturetime = 0.0f;

	player.pick_Ltexture = LoadTexture("data/TEXTURE/player/pick/pick_L.png");
	player.pick_Rtexture = LoadTexture("data/TEXTURE/player/pick/pick_R.png");
	player.picktextureflag = false;
	player.pickLRflag = false;
	player.picktexturetime = 0.0f;

	player.damage_Ltexture = LoadTexture("data/TEXTURE/player/damage/damage_L.png");
	player.damage_Rtexture = LoadTexture("data/TEXTURE/player/damage/damage_R.png");
	player.damagetextureflag = false;
	player.damageLRflag = false;
	player.damagetexturetime = 0.0f;

	player.deathtexture = LoadTexture("data/TEXTURE/player/death/death.png");


	InitSkill();
	InitReverse();

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

	REVERSE* reverse = GetReverse();

	_Reverse();

	//-----移動処理(コートの左右端を3sで移動)
	if (GetKeyboardPress(DIK_W))	//上
	{
		if(reverse->use == false)
		player.pos.y -= player.move.y;
		if(reverse->use == true)
		player.pos.y += player.move.y;

		player.rotate = 0;
	}
	if (GetKeyboardPress(DIK_S))	//下
	{
		if (reverse->use == false)
		player.pos.y += player.move.y;
		if (reverse->use == true)
		player.pos.y -= player.move.y;

		player.rotate = 1;
	}
	if (GetKeyboardPress(DIK_A))	//左
	{
		if (reverse->use == false)
		player.pos.x -= player.move.x;
		if (reverse->use == true)
		player.pos.x += player.move.x;

		player.rotate = 2;		//左向きに更新

		player.walktextureflag = true;		//テクスチャの切り替え
	}
	if (GetKeyboardPress(DIK_D))	//右
	{
		if (reverse->use == false)
		player.pos.x += player.move.x;
		if (reverse->use == true)
			player.pos.x -= player.move.x;

		player.rotate = 3;		//右向きに更新

		player.walktextureflag = true;		//テクスチャの切り替え
	}

	if (GetKeyboardRelease(DIK_A))	//左移動をやめたら
		player.walktextureflag = false;
	if (GetKeyboardRelease(DIK_D))	//右移動をやめたら
		player.walktextureflag = false;





	//-----コート外に出ない処理
	if (player.pos.y <= 180.f - player.size.y * 0.5f)	//上
		player.pos.y = 180.f - player.size.y * 0.5f;
	if (player.pos.y >= SCREEN_HEIGHT - player.size.y - 15 -120)	//下
		player.pos.y = SCREEN_HEIGHT - player.size.y - 15 -120;
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

	//-----ダメージ判定
	//if (barrier->drawflag == false)
	//{
	if (ball->playerhitflag == true)
	{
		if (player.pos.x < ball->pos.x + ball->size.x && player.pos.x + player.size.x > ball->pos.x)
		{
			if (player.pos.y < ball->pos.y + ball->size.y && player.pos.y + player.size.y > ball->pos.y)
			{
				player.damagetextureflag = true;
				hp->gaugesize.x = hp->gaugesize.x - 6000.0f;
				ball->playerhitflag = false;
			}
		}
	}
	//}

	//-----死亡判定
	if (hp->gaugesize.x <= 0)
		player.drawflag = false;




	//-----回避処理
	_Escape();

	//-----投げる処理
	P_Throw();

	//-----キャッチ処理
	P_Catch();

	//-----スキル処理
	_Skill();









	//-----描画設定
		//止まってるとき
	if (player.walktextureflag == false)
	{
		if (ball->playerhaveflag == false)	//ボールを持てなかったら
		{
			if (player.rotate == 3)		//右を向いてたら
			{
				player.u = 0.0f;
				player.uw = 0.5f;
				player.standLRflag = false;
			}
			if (player.rotate == 2)		//左を向いてたら
			{
				player.u = 0.5f;
				player.uw = 0.5f;
				player.standLRflag = true;
			}
		}

		if (ball->playerhaveflag == true)	//ボールを持ってるとき
		{
			if (player.rotate == 3)		//右を向いてたら
			{
				player.u = 0.5f;
				player.uw = 0.5f;
				player.standLRflag = false;
			}
			if (player.rotate == 2)		//左を向いてたら
			{
				player.u = 0.0f;
				player.uw = 0.5f;
				player.standLRflag = true;
			}
		}
	}

	//動いているとき
	if (player.walktextureflag == true)
	{
		if (ball->playerhaveflag == false)	//ボールを持てなかったら
		{
			if (player.rotate == 3)		//右を向いてたら
			{
				player.u = 0.f;
				player.uw = 0.5f;
				player.walkLRflag = false;
			}
			if (player.rotate == 2)		//左を向いてたら
			{
				player.u = 0.5f;
				player.uw = 0.5f;
				player.walkLRflag = true;
			}
		}

		if (ball->playerhaveflag == true)	//ボールを持ってるとき
		{
			if (player.rotate == 3)		//右を向いてたら
			{
				player.u = 0.5f;
				player.uw = 0.5f;
				player.walkLRflag = false;
			}
			if (player.rotate == 2)		//左を向いてたら
			{
				player.u = 0.0f;
				player.uw = 0.5f;
				player.walkLRflag = true;
			}
		}
	}

	//キャッチしたとき
	if (ball->playerhaveflag == true)	//プレイヤーがボールをキャッチしたら
	{
		if (ball->fallflag == false)
		{
			player.catchtexturetime = player.catchtexturetime + 1.0f;
			if (player.rotate == 3)		//右を向いていたら
			{
				player.catchtextureflag = true;
				player.catchLRflag = false;
				if (player.catchtexturetime < 5)	//
				{
					player.u = 0.7f;
					player.uw = 0.3f;
				}
				if (player.catchtexturetime >= 5 && player.catchtexturetime < 15)
				{
					player.u = 0.33f;
					player.uw = 0.375f;
				}
				if (player.catchtexturetime >= 15 && player.catchtexturetime < 20)
				{
					player.u = 0.0f;
					player.uw = 0.33f;
				}
				if (player.catchtexturetime >= 20)
					player.catchtextureflag = false;
			}
			if (player.rotate == 2)
			{
				player.catchtextureflag = true;
				player.catchLRflag = true;
				if (player.catchtexturetime < 5)
				{
					player.u = 0.0f;
					player.uw = 0.3f;
				}
				if (player.catchtexturetime >= 5 && player.catchtexturetime < 15)
				{
					player.u = 0.29f;
					player.uw = 0.375f;
				}
				if (player.catchtexturetime >= 15 && player.catchtexturetime < 20)
				{
					player.u = 0.67f;
					player.uw = 0.33f;
				}
				if (player.catchtexturetime >= 20)
					player.catchtextureflag = false;
			}
		}
	}
	if (ball->playerhaveflag == false)
	{
		player.catchtexturetime = 0.0f;
		player.catchtextureflag = false;
	}

	//落ちているボールを拾ったとき
	if (ball->playerhaveflag == true)
	{
		if (ball->fallflag == true)
		{
			player.picktexturetime = player.picktexturetime + 1.0f;
			if (player.rotate == 3)		//右を向いていたら
			{
				player.picktextureflag = true;
				player.pickLRflag = false;
				if (player.picktexturetime < 15)	//
				{
					player.u = 0.0f;
					player.uw = 0.55f;
				}
				if (player.picktexturetime >= 15 && player.picktexturetime < 20)
				{
					player.u = 0.55f;
					player.uw = 0.45f;
				}
				if (player.picktexturetime >= 20)
				{
					player.picktextureflag = false;
					
				}
			}
			if (player.rotate == 2)
			{
				player.picktextureflag = true;
				player.pickLRflag = true;
				if (player.picktexturetime < 10)
				{
					player.u = 0.45f;
					player.uw = 0.55f;
				}
				if (player.picktexturetime >= 10 && player.picktexturetime < 15)
				{
					player.u = 0.0f;
					player.uw = 0.45f;
				}
				if (player.picktexturetime >= 15)
				{
					player.picktextureflag = false;
				}
			}
		}
	}
	if (ball->playerhaveflag == false)
	{
		player.picktexturetime = 0.0f;
		player.picktextureflag = false;
	}

	//ダメージを受けたとき
	if (player.damagetextureflag == true)
	{
		player.damagetexturetime = player.damagetexturetime + 1.0f;
		if (player.rotate == 3)
		{
			player.u = 0.0f;
			player.uw = 1.0f;
			player.damageLRflag = false;
			if (player.damagetexturetime > 15)
			{
				player.damagetextureflag = false;
				player.damagetexturetime = 0.0f;
			}
		}
		if (player.rotate == 2)
		{
			player.u = 0.0f;
			player.uw = 1.0f;
			player.damageLRflag = true;
			if (player.damagetexturetime > 15)
			{
				player.damagetextureflag = false;
				player.damagetexturetime = 0.0f;
			}
		}
	}

	if (player.drawflag == false)
	{
		//player.size.y = 180.0f;
		player.u = 0.0f;
		player.uw = 1.0f;
	}













}

//-----描画処理
void DrawPlayer(void)
{
	BALL* ball = GetBall();

	if (player.drawflag == true)
	{
		if (player.damagetextureflag == false)	//ダメージモーションを優先
		{
			if (player.catchtextureflag == false)	//キャッチモーションを優先
			{
				if (player.picktextureflag == false)	//ピックモーションを優先
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
		}

		//ダメージを受けたとき && (右向いてるとき || 左向いてるとき)
		if (player.damagetextureflag == true && player.damageLRflag == false)
			DrawSpriteLeftTop(player.damage_Ltexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
		if (player.damagetextureflag == true && player.damageLRflag == true)
			DrawSpriteLeftTop(player.damage_Rtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);



	}

	if (player.drawflag == false)	//死亡時
	{
		DrawSpriteLeftTop(player.deathtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
	}



	//-----スキル描画
	DrawSkill();
}

//-----構造体ポインタ取得処理
PLAYER* GetPlayer(void)
{
	return &player;
}