//プレイヤーダメージ計算処理 [player_damage.cpp]
#include "player_damage.h"
#include "player.h"
#include "player_hp.h"
//エネミー.h
#include "slime.h"
#include "firewall.h"

#include "ball.h"
#include "catch.h"
//スキル.h
#include "barrier.h"
#include "autocatch.h"

//-----スライムからのダメージ処理
void Player_SlimeDamage()
{
	PLAYER* player = GetPlayer();
	PLAYERHP* hp = GetPlayerHp();
	BARRIER* barrier = GetBarrier();
	BALL* ball = GetBall();
	SLIME* slime = GetSlime();
	AUTO* auto_c = GetAuto();
	CATCH* Catch = GetCatch();

	//-----スライムからのダメージ判定
	if (barrier->drawflag == false)
	{
		if (ball->playerhitflag == true)
		{
			if (player->rotate == 3)
			{
				if (player->pos.x < ball->pos.x + ball->size.x && player->pos.x + player->size.x * 0.8f > ball->pos.x)
				{
					if (player->pos.y + player->size.y * 0.2f < ball->pos.y + ball->size.y && player->pos.y + player->size.y * 0.8f > ball->pos.y)
					{
						//スキル：オートキャッチが機能していない場合
						if (auto_c->auto_catchflag == false)
						{
							player->damagetextureflag = true;
							hp->gaugesize.x = hp->gaugesize.x - (slime->atk - player->def) * 3.2f;
							hp->pos.x = hp->pos.x + (slime->atk - player->def) * 3.2f;
							ball->playerhitflag = false;
						}
						//スキル：オートキャッチが機能している場合
						if (auto_c->auto_catchflag == true && auto_c->auto_catch == true)
						{
							Catch->playerflag = true;
							Catch->playerintervalflag = true;
							ball->playerhitflag = false;
						}
					}
				}
			}

			if (player->rotate == 2)
			{
				if (player->pos.x < ball->pos.x + ball->size.x && player->pos.x + player->size.x * 0.5f > ball->pos.x)
				{
					if (player->pos.y + player->size.y * 0.2f < ball->pos.y + ball->size.y && player->pos.y + player->size.y * 0.8f > ball->pos.y)
					{
						//スキル：オートキャッチが機能していない場合
						if (auto_c->auto_catchflag == false)
						{
							player->damagetextureflag = true;
							hp->gaugesize.x = hp->gaugesize.x - (slime->atk - player->def);
							hp->pos.x = hp->pos.x + (slime->atk - player->def);
							ball->playerhitflag = false;
						}
						//スキル：オートキャッチが機能している場合
						if (auto_c->auto_catchflag == true && auto_c->auto_catch == true)
						{
							Catch->playerflag = true;
							Catch->playerintervalflag = true;
							ball->playerhitflag = false;
						}
					}
				}
			}
		}
	}
}

//-----ファイアーウォールからのダメージ処理
void Player_FireWallDamage()
{
	PLAYER* player = GetPlayer();
	PLAYERHP* hp = GetPlayerHp();
	BARRIER* barrier = GetBarrier();
	BALL* ball = GetBall();
	FIREWALL* firewall = GetFireWall();

	//-----ファイアーウォールからのダメージ判定
	if (barrier->drawflag == false)
	{
		if (ball->playerhitflag == true)
		{
			if (player->rotate == 3)
			{
				if (player->pos.x < ball->pos.x + ball->size.x && player->pos.x + player->size.x * 0.8f > ball->pos.x)
				{
					if (player->pos.y + player->size.y * 0.2f < ball->pos.y + ball->size.y && player->pos.y + player->size.y * 0.8f > ball->pos.y)
					{
						player->damagetextureflag = true;
						hp->gaugesize.x = hp->gaugesize.x - (firewall->atk - player->def) * 3.2f;
						hp->pos.x = hp->pos.x + (firewall->atk - player->def) * 3.2f;
						ball->playerhitflag = false;
					}
				}
			}

			if (player->rotate == 2)
			{
				if (player->pos.x < ball->pos.x + ball->size.x && player->pos.x + player->size.x * 0.5f > ball->pos.x)
				{
					if (player->pos.y + player->size.y * 0.2f < ball->pos.y + ball->size.y && player->pos.y + player->size.y * 0.8f > ball->pos.y)
					{
						player->damagetextureflag = true;
						hp->gaugesize.x = hp->gaugesize.x - (firewall->atk - player->def);
						hp->pos.x = hp->pos.x + (firewall->atk - player->def);
						ball->playerhitflag = false;
					}
				}
			}
		}
	}
}