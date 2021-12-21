//スライム処理 [slime.cpp]
#include "slime.h"
//システム.h
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "scene.h"
#include "fade.h"

#include "player.h"
#include "ball.h"
#include "catch.h"
#include "slime_hp.h"
#include "slimeAI.h"
#include "skillrandom.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
SLIME slime;

//-----初期化処理
HRESULT InitSlime(void)
{
	slime.pos = D3DXVECTOR2(800.0f, 320.0f);
	slime.size = D3DXVECTOR2(128.0f, 128);
	slime.move = D3DXVECTOR2(2.0f, 2.0f);
	slime.rotate = 2;

	slime.atk = 150;
	slime.def = 50;

	slime.u = 0.0f;
	slime.v = 1.0f;
	slime.uw = 0.335f;
	slime.vh = 1.0f;
	slime.drawflag = true;
	slime.walktime = 0.0f;

	slime.texture = LoadTexture("data/TEXTURE/enemy/slime.png");

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

	if (slime.walktime > 2)
		slime.u = 0.335f;
	if (slime.walktime > 4)
	{
		slime.u = 0.0f;
		slime.walktime = 0.0f;
	}

	if (GetKeyboardPress(DIK_LEFTARROW))
	{
		slime.pos.x = slime.pos.x - 3.0f;
		slime.walktime = slime.walktime + 0.1f;
		if (GetKeyboardPress(DIK_RIGHTARROW))
			slime.walktime = 0.0f;
	}
	if (GetKeyboardPress(DIK_RIGHTARROW))
	{
		slime.pos.x = slime.pos.x + 3.0f;
		slime.walktime = slime.walktime + 0.1f;
		if (GetKeyboardPress(DIK_LEFTARROW))
			slime.walktime = 0.0f;
	}
	if (GetKeyboardPress(DIK_UPARROW))
	{
		slime.pos.y = slime.pos.y - 3.0f;
		slime.walktime = slime.walktime + 0.1f;
		if (GetKeyboardPress(DIK_DOWNARROW))
			slime.walktime = 0.0f;
	}
	if (GetKeyboardPress(DIK_DOWNARROW))
	{
		slime.pos.y = slime.pos.y + 3.0f;
		slime.walktime = slime.walktime + 0.1f;
		if (GetKeyboardPress(DIK_UPARROW))
			slime.walktime = 0.0f;
	}

	//-----コート外に出ない処理
	if (slime.pos.y <= 280.f - slime.size.y * 0.5f)	//上
		slime.pos.y = 280.f - slime.size.y * 0.5f;
	if (slime.pos.y >= SCREEN_HEIGHT - slime.size.y - 15 - 120)	//下
		slime.pos.y = SCREEN_HEIGHT - slime.size.y - 15 - 120;
	if (slime.pos.x <= SCREEN_WIDTH * 0.5f)		//左
		slime.pos.x = SCREEN_WIDTH * 0.5f;
	if (slime.pos.x >= SCREEN_WIDTH - slime.size.x)		//右
		slime.pos.x = SCREEN_WIDTH - slime.size.x;


	if (slime.drawflag == true)
	{
		SlimeAI();
	}

	//-----コート外に出ない処理


	//-----プレイヤーが投げたボールが、地面,壁に当たらず敵に当たったら敵の描画をやめる(アウト判定)
	if (ball->enemyhitflag == true)
	{
		if (slime.pos.x < ball->pos.x + ball->size.x && slime.pos.x + slime.size.x > ball->pos.x)
		{
			if (slime.pos.y < ball->pos.y + ball->size.y && slime.pos.y + slime.size.y > ball->pos.y)
			{
				slime_hp->gaugesize.x = slime_hp->gaugesize.x - (player->atk - slime.def) * 3.2f;
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
		SceneTransition(SCENE_MAP);
	}
}

//-----描画処理
void DrawSlime(void)
{
	if (slime.drawflag == true)
		DrawSpriteLeftTop(slime.texture, slime.pos.x, slime.pos.y, slime.size.x, slime.size.y, slime.u, slime.v, slime.uw, slime.vh);
}

//-----構造体ポインタ取得処理
SLIME* GetSlime(void)
{
	return &slime;
}