//スキル_岩石生成 [rockcreate.cpp]
#include "rockcreate.h"
//システム.h
#include "Texture.h"
#include "sprite.h"
#include "input.h"
//エネミー.h
#include "firewall.h"
#include "deleter.h"
#include "slime.h"
#include "map_player.h"

#include "player.h"
#include "bugincrease.h"
#include "ball.h"
#include "skillrandom.h"
#include "penetration.h"
#include "enemybreak.h"

//-----マクロ定義
#define gansekitime 1800		//30s間

//-----プロトタイプ宣言
GANSEKI ganseki;

//-----グローバル変数

//-----初期化処理
HRESULT InitGanseki(void)
{
	ganseki.use = false;
	ganseki.timeflag = false;
	ganseki.time = 0.0f;
	ganseki.usegauge = 10;
	ganseki.pos = D3DXVECTOR2(0.0f, 0.0f);
	ganseki.size = D3DXVECTOR2(200.0f, 300.0f);
	ganseki.texture = LoadTexture("data/TEXTURE/Rock.png");

	ganseki.bugincrease = false;
	ganseki.bugdrawnum = 0;

	return S_OK;
}

//-----不法侵入処理
void _Ganseki(void)
{
	PLAYER* player = GetPlayer();
	RANDOM* random = GetRandom();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	BALL* ball = GetBall();
	FIREWALL* firewall = GetFireWall();
	DELETER* deleter = GetDeleter();
	SLIME* slime = GetSlime();
	MAP_PLAYER* map_player = GetMapPlayer();
	KANTSUU* kantsuu = GetKantsuu();
	SKILL* skill = GetSkill();
	ENEMYBREAK* enemybreak = GetEnemyBreak();

	//-----発動から30秒間、フィールドに残る障害物として岩石を生成する
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 12 && random[i].active == true && ganseki.use == false)
		{
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && ganseki.bugincrease == false)
				{
					for (int j = i; ganseki.bugdrawnum < 4; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						ganseki.bugdrawnum = ganseki.bugdrawnum + 1;
					}
					ganseki.bugincrease = true;
				}
			}
			ganseki.pos.y = player->pos.y;
			if (player->rotate == 3)
				ganseki.pos.x = player->pos.x + 540.0f;
			if (player->rotate == 2)
				ganseki.pos.x = player->pos.x - 540.0f;

			ganseki.timeflag = true;
			ganseki.use = true;
		}
	}

	//-----
	if (ganseki.timeflag == true && kantsuu->use == false)
	{
		ganseki.time = ganseki.time + 1.0f;

		//ボールコリジョン
		if (ganseki.pos.x < ball->pos.x + ball->size.x && ganseki.pos.x + ganseki.size.x * 0.8f > ball->pos.x)
		{
			if (ganseki.pos.y + ganseki.size.y * 0.2f < ball->pos.y + ball->size.y && ganseki.pos.y + ganseki.size.y * 0.8f > ball->pos.y)
			{
				if (ball->move.x > 0)
					ball->move.x -= 5.0f;
				if (ball->move.x < 0)
					ball->move.x += 5.0f;
				ball->move.x *= -0.3f;
			}
		}

		//プレイヤーコリジョン
		if (ganseki.pos.x < player->pos.x + player->size.x && ganseki.pos.x + ganseki.size.x * 0.8f > player->pos.x)
		{
			if (ganseki.pos.y + ganseki.size.y * 0.2f < player->pos.y + player->size.y && ganseki.pos.y + ganseki.size.y * 0.8f > player->pos.y)
			{
				if (player->move.x > 0)
					player->pos.x -= 4.0f;
				if (player->move.x < 0)
					player->pos.x += 4.0f;
			}
		}

		//エネミーコリジョン
		if (map_player->encount == 1)
		{
			if (ganseki.pos.x < slime->pos.x + slime->size.x && ganseki.pos.x + ganseki.size.x * 0.8f > slime->pos.x)
			{
				if (ganseki.pos.y + ganseki.size.y * 0.2f < slime->pos.y + slime->size.y && ganseki.pos.y + ganseki.size.y * 0.8f > slime->pos.y)
				{
					if (slime->move.x < 0)
						slime->pos.x -= 2.0f;
					if (slime->move.x > 0)
						slime->pos.x += 2.0f;
				}
			}
		}
		if (map_player->encount == 2)
		{
			if (ganseki.pos.x < deleter->pos.x + deleter->size.x && ganseki.pos.x + ganseki.size.x * 0.8f > deleter->pos.x)
			{
				if (ganseki.pos.y + ganseki.size.y * 0.2f < deleter->pos.y + deleter->size.y && ganseki.pos.y + ganseki.size.y * 0.8f > deleter->pos.y)
				{
					if (deleter->move.x < 0)
						deleter->pos.x -= 2.0f;
					if (deleter->move.x > 0)
						deleter->pos.x += 2.0f;
				}
			}
		}
		if (map_player->encount == 3)
		{
			if (ganseki.pos.x < firewall->pos.x + firewall->size.x && ganseki.pos.x + ganseki.size.x * 0.8f > firewall->pos.x)
			{
				if (ganseki.pos.y + ganseki.size.y * 0.2f < firewall->pos.y + firewall->size.y && ganseki.pos.y + ganseki.size.y * 0.8f > firewall->pos.y)
				{
					if (firewall->move.x < 0)
						firewall->pos.x -= 2.0f;
					if (firewall->move.x > 0)
						firewall->pos.x += 2.0f;
				}
			}
		}
	}

	if (ganseki.time > gansekitime)
	{
		ganseki.timeflag = false;
		ganseki.time = 0.0f;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && ganseki.use == true)
		{
			ganseki.use = false;
			ganseki.timeflag = false;
			ganseki.time = 0.0f;
			ganseki.usegauge = 10;
			ganseki.bugincrease = false;
			ganseki.bugdrawnum = 0;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && ganseki.use == true)
		{
			ganseki.use = false;
			ganseki.timeflag = false;
			ganseki.time = 0.0f;
			ganseki.usegauge = 10;
			ganseki.bugincrease = false;
			ganseki.bugdrawnum = 0;
		}
	}

	if (enemybreak->drawflag == true && ganseki.use == true)
	{
		ganseki.use = false;
		ganseki.timeflag = false;
		ganseki.time = 0.0f;
		ganseki.usegauge = 10;
		ganseki.bugincrease = false;
		ganseki.bugdrawnum = 0;
	}
}

void DrawGanseki(void)
{
	if (ganseki.timeflag == true)
	{
		DrawSpriteLeftTop(ganseki.texture, ganseki.pos.x, ganseki.pos.y, ganseki.size.x, ganseki.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
}

//-----構造体ポインタ取得処理
GANSEKI* GetGanseki(void)
{
	return &ganseki;
}