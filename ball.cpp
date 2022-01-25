//ボール処理 [ball.cpp]
#include "ball.h"
//システム.h
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"
//プレイヤー.h
#include "player.h"
//エネミー.h
#include "firewall.h"
#include "slime.h"
#include "deleter.h"
//スキル.h
#include "autocatch.h"
#include "invincible.h"
#include "create.h"
//
#include "map_player.h"
#include "ballturnaround.h"

#include "sound.h"
#include "soundvolume_select.h"

//-----マクロ定義
#define auto_ctime_2 60		//1s間

#define RETURNBALLTIME 30

//-----プロトタイプ宣言
BALL ball;

//-----グローバル変数
PLAYER* player = GetPlayer();

int g_balltime[2];

//-----初期化処理
HRESULT InitBall(void)
{
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();

	ball.pos = D3DXVECTOR2(500.0f, 360.0f);
	ball.size = D3DXVECTOR2(60.0f, 60.0f);
	ball.move = D3DXVECTOR2(12.0f, -3.5f);
	ball.startmove = D3DXVECTOR2(ball.move.x, ball.move.y);
	ball.throwway = 1;
	ball.gravity = 0.05f;
	ball.texture = LoadTexture("data/TEXTURE/ball.png");
	ball.throwflag = false;
	ball.fallpos = 0.0f;
	ball.playerhavetime = 0.0f;
	ball.playerhaveflag = false;
	ball.playerhitflag = false;
	ball.playerthrowflag = false;
	ball.enemyhaveflag = false;
	ball.enemyhitflag = false;
	ball.fallflag = true;
	ball.rad = 0.0f;
	ball.plyer_oldposY = 0.0f;
	ball.oldpos = 0.f;
	ball.oldtime = 0.f;

	g_balltime[0] = 0;
	g_balltime[1] = 0;

	ball.throwSE = LoadSound("data/SE/throw.wav");
	SetVolume(ball.throwSE, soundvolume_select[1].count * 0.1f + 0.5f);

	return S_OK;
}

//-----終了処理
void UninitBall(void)
{

}

//-----更新処理
void UpdateBall(void)
{
	PLAYER* player = GetPlayer();
	MAP_PLAYER* map_player = GetMapPlayer();
	FIREWALL* firewall = GetFireWall();
	SLIME* slime = GetSlime();
	DELETER* deleter = GetDeleter();
	BALLTURNAROUND* ballTA = GetBallTurnAround();

	if (ball.oldpos == ball.pos.x)
		ball.oldtime = ball.oldtime + 1.f;
	if (ball.oldtime > 180.f)
	{
		ball.pos = D3DXVECTOR2(500.0f, 360.0f);
		ball.oldtime = 0.f;
	}


	ball.oldpos = ball.pos.x;


	//-----ボールの座標を決める(Player)
	if (ball.throwflag == false && ball.playerhaveflag == true)		//ボールが飛んでいないとき&&プレイヤーが持ってるとき
	{
		if (player->rotate == 2)
		{
			ball.pos = D3DXVECTOR2(player->pos.x, player->pos.y + player->size.y * 0.3f - ball.size.y * 0.5f);
			ball.throwway = -1;
		}
		if (player->rotate == 3 || player->rotate == 0 || player->rotate == 1)
		{
			ball.pos = D3DXVECTOR2(player->pos.x + ball.size.x * 2.f, player->pos.y + player->size.y * 0.3f - ball.size.y * 0.5f);
			ball.throwway = 1;
		}
	}

	//-----ボールの座標を決める(slime)
	if (map_player->encount == 1)
	{
		if (ball.throwflag == false && ball.enemyhaveflag == true)		//ボールが飛んでいないとき&&エネミーが持ってるとき
		{
			if (slime->rotate == 2)
			{
				ball.pos = D3DXVECTOR2(slime->pos.x - ball.size.x * 0.5f, slime->pos.y + slime->size.y * 0.5f - ball.size.y * 0.5f);
				ball.throwway = -1;
			}
			if (slime->rotate == 3)
			{
				ball.pos = D3DXVECTOR2(slime->pos.x + ball.size.x * 0.5f, slime->pos.y + slime->size.y * 0.5f - ball.size.y * 0.5f);
				ball.throwway = 1;
			}
		}
	}
	//-----ボールの座標を決める(deleter)
	if (map_player->encount == 2)
	{
		if (ball.throwflag == false && ball.enemyhaveflag == true)		//ボールが飛んでいないとき&&エネミーが持ってるとき
		{
			if (deleter->rotate == 2)
			{
				ball.pos = D3DXVECTOR2(deleter->pos.x - ball.size.x * 0.5f, deleter->pos.y + deleter->size.y * 0.5f - ball.size.y * 0.5f);
				ball.throwway = -1;
			}
			if (deleter->rotate == 3 || deleter->rotate == 0 || deleter->rotate == 1)
			{
				ball.pos = D3DXVECTOR2(deleter->pos.x + ball.size.x * 0.5f, deleter->pos.y + deleter->size.y * 0.5f - ball.size.y * 0.5f);
				ball.throwway = 1;
			}
		}
	}
	//-----ボールの座標を決める(FireWall)
	if (map_player->encount == 3)
	{
		if (ball.throwflag == false && ball.enemyhaveflag == true)		//ボールが飛んでいないとき&&エネミーが持ってるとき
		{
			if (firewall->rotate == 2)
			{
				ball.pos = D3DXVECTOR2(firewall->pos.x - ball.size.x * 0.5f, firewall->pos.y + firewall->size.y * 0.5f - ball.size.y * 0.5f);
				ball.throwway = -1;
			}
			if (firewall->rotate == 3 || firewall->rotate == 0 || firewall->rotate == 1)
			{
				ball.pos = D3DXVECTOR2(firewall->pos.x + ball.size.x * 0.5f, firewall->pos.y + firewall->size.y * 0.5f - ball.size.y * 0.5f);
				ball.throwway = 1;
			}
		}
	}

	//-----軌道計算
	if (ball.throwflag == true)
	{
		if (ballTA->use == 1)//方向転換のスキル。発動中は他のボールの動きを制限する。
		{
			//y = ax2乗 の a は分かったので、後は当てはめて計算。
			ballTA->n += 12; // 進む速度。
			ball.pos.x = ballTA->b_x + ballTA->n;
			if (ballTA->n_flag)
			{
				ball.pos.y = ballTA->a * (ballTA->f_x - ballTA->b_x - ballTA->n) * (ballTA->f_x - ballTA->b_x - ballTA->n) + ballTA->f_y;
				if (ballTA->f_y + 1.0f > ball.pos.y && ballTA->f_x - 1.0f < ball.pos.x)//目的地に着いた
				{
					ballTA->use = 2;
					SetBallTurnAround_2();
				}
			}
			else
			{
				ball.pos.y = -ballTA->a * (ballTA->f_x - ballTA->b_x - ballTA->n) * (ballTA->f_x - ballTA->b_x - ballTA->n) + ballTA->f_y;
				if (ballTA->f_y - 1.0f < ball.pos.y && ballTA->f_x - 1.0f < ball.pos.x)//目的地に着いた
				{
					ballTA->use = 2;
					SetBallTurnAround_2();
				}
			}
		}

		if (ballTA->use == 2)//記憶座標の更新と軌道計算と更新。
		{
			ballTA->n += 12; // 進む速度。
			ball.pos.x = ballTA->f_x + ballTA->n;
			if (ballTA->n_flag)
			{
				ball.pos.y = ballTA->a * ballTA->n * ballTA->n + ballTA->f_y;
				if (ballTA->b_y - 1.0f < ball.pos.y && ballTA->b_x - 1.0f < ball.pos.x)//目的地に着いた
				{
					ballTA->use = 3;
					SetBallTurnAround_3();
				}
			}
			else
			{
				//下に向かっていく
				ball.pos.y = -ballTA->a * ballTA->n * ballTA->n + ballTA->f_y;
				if (ballTA->b_y + 1.0f > ball.pos.y && ballTA->b_x - 1.0f < ball.pos.x)//目的地に着いた
				{
					ballTA->use = 3;
					SetBallTurnAround_3();
				}
			}
		}

		if (ballTA->use == 3)//方向転換のスキル。発動中は他のボールの動きを制限する。
		{
			//y = ax2乗 の a は分かったので、後は当てはめて計算。
			ballTA->n -= 8; // 進む速度。
			ball.pos.x = ballTA->b_x + ballTA->n;
			if (ballTA->n_flag)
			{
				ball.pos.y = ballTA->a * (ballTA->f_x - ballTA->b_x - ballTA->n) * (ballTA->f_x - ballTA->b_x - ballTA->n) + ballTA->f_y;
				if (ballTA->f_y + 1.0f > ball.pos.y && ballTA->f_x + 1.0f > ball.pos.x)//目的地に着いた
				{
					ballTA->use = 4;
				}
			}
			else
			{
				ball.pos.y = -ballTA->a * (ballTA->f_x - ballTA->b_x - ballTA->n) * (ballTA->f_x - ballTA->b_x - ballTA->n) + ballTA->f_y;
				if (ballTA->f_y - 1.0f < ball.pos.y && ballTA->f_x + 1.0f > ball.pos.x)//目的地に着いた
				{
					ballTA->use = 4;
				}
			}
		}

		if (ballTA->use == 4)
		{
			ball.move = D3DXVECTOR2(-2.0f, -6.0f);
			ball.fallpos = ballTA->f_y + firewall->size.y / 2;
			ballTA->use = 0;
		}

		if (ballTA->use == 0)
		{
			ball.pos.x += ball.move.x * ball.throwway;
			ball.pos.y += ball.move.y;
			ball.move.y += ball.gravity;

			//-----慣性計算
			if (ball.move.y < 0)	//上に向かう
			{
				ball.move.y += 0.02f;
				if (ball.move.y >= 0)
					ball.move.y = 0;
			}
			if (ball.move.y > 0)	//下に向かう
			{
				ball.move.y -= 0.02f;
				if (ball.move.y <= 0)
					ball.move.y = 0;
			}
			if (ball.move.x < 0)	//左に向かう
			{
				ball.move.x += 0.02f;
				if (ball.move.x >= 0)
					ball.move.x = 0;
			}
			if (ball.move.x > 0)	//右に向かう
			{
				ball.move.x -= 0.02f;
				if (ball.move.x <= 0)
					ball.move.x = 0;
			}
		}

		//-----反射,ゲームっぽい減速計算
		if (ball.pos.y < 0.0f)							//上
			ball.move.y *= -1;
		if (ball.pos.y + ball.size.y > ball.fallpos)	//下(投げた瞬間のプレイヤーのy座標)
		{
			ball.move.y *= -1;
			ball.enemyhitflag = false;
			ball.playerhitflag = false;
			ball.fallflag = true;
		}
		if (ball.pos.x < 0.0f)							//左
		{
			if (ball.move.x < 0)
				ball.move.x += 5.0f;
			if (ball.move.x > 0)
				ball.move.x -= 5.0f;
			ball.enemyhitflag = false;
			ball.playerhitflag = false;
			ball.fallflag = true;

			g_balltime[0]++;
		}
		if (ball.pos.x + ball.size.x > SCREEN_WIDTH)	//右
		{
			if (ball.move.x > 0)
				ball.move.x -= 5.0f;
			if (ball.move.x < 0)
				ball.move.x += 5.0f;
			ball.move.x *= -1;
			ball.enemyhitflag = false;
			ball.playerhitflag = false;
			ball.fallflag = true;

			g_balltime[0]++;
		}

		if (g_balltime[0] != 0)
		{
			if (g_balltime[1] == g_balltime[0])
			{
				g_balltime[0] = 0;
				g_balltime[1] = 0;
			}
			g_balltime[1] = g_balltime[0];
		}

		if (g_balltime[0] > RETURNBALLTIME - 1)
		{
			ball.pos.x = SCREEN_WIDTH / 2;
			ball.pos.y = 0.0f;

			ball.move.x = 0;
			ball.fallpos = SCREEN_HEIGHT / 2;
		}
	}

	//岩石との当たり判定
	CREATE* create = GetCreate(0);

	if (create->timeflag)
	{
		for (int i = 0; i < 3; i++) // ここの3は生成される岩石の個数を表す。createで数を変更した際はここも変更して下さい。
		{
			CREATE* create = GetCreate(i);

			if (ball.pos.x + ball.size.x > create->pos.x - create->size.x / 2 && ball.pos.x < create->pos.x + create->size.x / 2 &&
				ball.pos.y + ball.size.y > create->pos.y - create->size.y / 2 && ball.pos.y < create->pos.y + create->size.y / 2)
			{
				float ax = 0.0f;
				float ay = 0.0f;
				if (ball.pos.x + ball.size.x < create->pos.x)
					//岩石の左側
				{
					ax = (create->pos.x - ball.pos.x + ball.size.x) / create->size.x / 2;
				}
				else if (ball.pos.x > create->pos.x)
					//岩石の右側
				{
					ax = (ball.pos.x - create->pos.x) / create->size.x / 2;
				}

				if (ball.pos.y + ball.size.y < create->pos.y)
					//岩石の上側
				{
					ay = (create->pos.y - ball.pos.y + ball.size.y) / create->size.y / 2;
				}
				else if (ball.pos.y > create->pos.y)
					//岩石の下側
				{
					ay = (ball.pos.y - create->pos.y) / create->size.y / 2;
				}

				if (ax > ay)
				{
					ball.move.x *= -1;
				}
				else if (ax < ay)
				{
					ball.move.y *= -1;
				}
				else
				{
					ball.move.x *= -1;
				}
			}
		}
	}
}

//-----描画処理
void DrawBall(void)
{
	if(ball.playerhaveflag == false)
	DrawSpriteLeftTop(ball.texture, ball.pos.x, ball.pos.y, ball.size.x, ball.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----エネミーが投げる処理
void E_Throw(void)
{
	INVINCIBLE* invincible = GetInvincible();

	if (ball.throwflag == false && ball.enemyhaveflag == true)
	{
		ball.fallpos = player->pos.y + player->size.y;
		ball.fallflag = false;
		ball.enemyhaveflag = false;
		if (invincible->use == true) //-----無敵スキルを使ってるか？どうかの判定
			ball.playerhitflag = false;
		if (invincible->use == false)
			ball.playerhitflag = true;
		ball.throwflag = true;
	}
}

//プレイヤーが投げる処理
void P_Throw(void)
{
	AUTO* auto_c = GetAuto();
	BALLTURNAROUND* ballTA = GetBallTurnAround();

	if (PADUSE == 0)
	{
		//-----プレイヤーの投げ動作
		if (IsButtonTriggered(0, BUTTON_R2) && ball.throwflag == false && ball.playerhaveflag == true)
		{
			PlaySound(ball.throwSE, 0.5f);

			ball.playerhavetime = 0.0f;
			ball.fallpos = player->pos.y + player->size.y;
			ball.fallflag = false;
			ball.playerhaveflag = false;
			ball.playerthrowflag = true;
			ball.enemyhitflag = true;
			ball.throwflag = true;

			//プレイヤーがスキル：オートキャッチ使用中に投げた場合の吸い寄せ防止
			if (auto_c->timeflag_2 == true)
				auto_c->auto_catch = false;
			auto_c->time_2 = auto_c->time_2 + 1.0f;
			if (auto_c->time_2 > auto_ctime_2)
			{
				auto_c->auto_catch = true;
				auto_c->timeflag_2 = false;
				auto_c->time_2 = 0.0f;
			}

			if (ballTA->use == 1) // 方向転換のスキル。発動中は他のボールの動きを制限する。
			{
				SetBallTurnAround(); // 計算に必要な座標のセット
			}
		}
	}

	if (PADUSE == 1)
	{
		//-----プレイヤーの投げ動作
		if (GetKeyboardTrigger(DIK_L) && ball.throwflag == false && ball.playerhaveflag == true)
		{
			PlaySound(ball.throwSE, 0.5f);

			ball.playerhavetime = 0.0f;
			ball.fallpos = player->pos.y + player->size.y;
			ball.fallflag = false;
			ball.playerhaveflag = false;
			ball.playerthrowflag = true;
			ball.enemyhitflag = true;
			ball.throwflag = true;
		}


		//プレイヤーがスキル：オートキャッチ使用中に投げた場合の吸い寄せ防止
		if (auto_c->timeflag_2 == true)
			auto_c->auto_catch = false;
		auto_c->time_2 = auto_c->time_2 + 1.0f;
		if (auto_c->time_2 > auto_ctime_2)
		{
			auto_c->auto_catch = true;
			auto_c->timeflag_2 = false;
			auto_c->time_2 = 0.0f;
		}

		if (ballTA->use == 1) // 方向転換のスキル。発動中は他のボールの動きを制限する。
		{
			SetBallTurnAround(); // 計算に必要な座標のセット
		}
	}
}

void AddBallMove(float move, float rotato, float set_pos_y, float set_size_y)
//渡された角度に渡された速度で加算する。角度はラジアン。反時計回り。
{
	ball.move.x = cosf(rotato) * move; // 玉の撃ちだすスピードを計算
	ball.move.y = sinf(rotato) * -move;
	ball.fallpos = set_pos_y + set_size_y;
}

//-----構造体ポインタ取得処理
BALL* GetBall()
{
	return &ball;
}