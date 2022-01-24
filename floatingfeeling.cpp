/*------------------------------------------
[ 浮遊感を感じて [ event_FloatingFeeling.cpp ] ]
-------------------------------------------*/
#include "floatingfeeling.h"
#include "input.h"
#include "Texture.h"
#include "sprite.h"
#include "fade.h"
#include "player_hp.h"
#include "map_player.h"

//-----マクロ定義

//-----プロトタイプ宣言
E_FLOATINGFEELING frame;
E_FLOATINGFEELING sentence;
E_FLOATINGFEELING title;
E_FLOATINGFEELING choices_A;
E_FLOATINGFEELING choices_B;
E_FLOATINGFEELING choices_A_success;
E_FLOATINGFEELING choices_A_failure;
E_FLOATINGFEELING choices_B_failure;

//-----グローバル変数
int EFF_flag;
int EFF_UDcount;
int EFF_time;

HRESULT Inite_FloatingFeeling()
{
	EFF_flag = 0;
	EFF_UDcount = 0;
	EFF_time = 0;

	frame.pos = D3DXVECTOR2(800.0f + 100.0f, 750.0f);
	frame.size = D3DXVECTOR2(560.0f, 35.0f);
	frame.use = false;
	frame.texture = LoadTexture("data/TEXTURE/bugframe.png");

	sentence.pos = D3DXVECTOR2(800.0f + 50.0f, 170.0f);
	sentence.size = D3DXVECTOR2(700.0f, 210.0f);
	sentence.use = false;
	sentence.texture = LoadTexture("data/TEXTURE/event/event_FloatingFeeling/sentence.png");

	title.pos = D3DXVECTOR2(800.0f + 100.0f, 100.0f);
	title.size = D3DXVECTOR2(350.0f, 50.0f);
	title.use = false;
	title.texture = LoadTexture("data/TEXTURE/event/event_FloatingFeeling/title.png");

	choices_A.pos = D3DXVECTOR2(800.0f + 100.0f, 750.0f);
	choices_A.size = D3DXVECTOR2(560.0f, 35.0f);
	choices_A.use = false;
	choices_A.texture = LoadTexture("data/TEXTURE/event/event_FloatingFeeling/choices_A.png");

	choices_B.pos = D3DXVECTOR2(800.0f + 100.0f, 800.0f);
	choices_B.size = D3DXVECTOR2(420.0f, 35.0f);
	choices_B.use = false;
	choices_B.texture = LoadTexture("data/TEXTURE/event/event_FloatingFeeling/choices_B.png");

	choices_A_success.pos = D3DXVECTOR2(800.0f + 50.0f, 100.0f);
	choices_A_success.size = D3DXVECTOR2(700.0f, 140.0f);
	choices_A_success.use = false;
	choices_A_success.texture = LoadTexture("data/TEXTURE/event/event_FloatingFeeling/choices_A_success.png");

	choices_A_failure.pos = D3DXVECTOR2(800.0f + 50.0f, 100.0f);
	choices_A_failure.size = D3DXVECTOR2(700.0f, 140.0f);
	choices_A_failure.use = false;
	choices_A_failure.texture = LoadTexture("data/TEXTURE/event/event_FloatingFeeling/choices_A_failure.png");

	choices_B_failure.pos = D3DXVECTOR2(800.0f + 50.0f, 100.0f);
	choices_B_failure.size = D3DXVECTOR2(700.0f, 140.0f);
	choices_B_failure.use = false;
	choices_B_failure.texture = LoadTexture("data/TEXTURE/event/event_FloatingFeeling/choices_B_failure.png");

	return S_OK;
}

void _FloatingFeeling(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	if (EFF_flag == 0)
	{
		title.use = true;
		sentence.use = true;
		choices_A.use = true;
		choices_B.use = true;
		frame.use = true;
		EFF_flag = 1;
	}
	if (EFF_flag == 1)
	{
		if (PADUSE == 0)
		{
			if (IsButtonTriggered(0, BUTTON_UP) && EFF_UDcount > 0)
			{
				EFF_UDcount -= 1;
				frame.pos.y -= 50.0f;
			}
			if (IsButtonTriggered(0, BUTTON_DOWN) && EFF_UDcount < 1)
			{
				EFF_UDcount += 1;
				frame.pos.y += 50.0f;
			}
			if (IsButtonTriggered(0, BUTTON_Y))
			{
				if (EFF_UDcount == 0)
				{
					if (rand() % 100 > 19)
					{
						EFF_flag = 2;
						//何もしない
					}
					else
					{
						EFF_flag = 3;
						//体力-30
						AddPlayerHp(-30);
					}
				}
				if (EFF_UDcount == 1)
				{
					EFF_flag = 4;
					//体力最大値を-50
					AddPlayerHpMAX(-50);

					//現在のHPを半分に
					PLAYERHP* player_hp = GetPlayerHp();
					int n = player_hp->gaugesize.x * 0.3125f;
					n = n / 2 * -1;
					AddPlayerHp(n);
				}
				sentence.use = false;
				choices_A.use = false;
				choices_B.use = false;
				frame.use = false;
			}

		}
		if (PADUSE == 1)
		{
			if (GetKeyboardTrigger(DIK_W) && EFF_UDcount > 0)
			{
				EFF_UDcount -= 1;
				frame.pos.y -= 50.0f;
			}
			if (GetKeyboardTrigger(DIK_S) && EFF_UDcount < 1)
			{
				EFF_UDcount += 1;
				frame.pos.y += 50.0f;
			}
			if (GetKeyboardTrigger(DIK_RETURN))
			{
				if (EFF_UDcount == 0)
				{
					if (rand() % 100 > 19)
					{
						EFF_flag = 2;
						//何もしない
					}
					else
					{
						EFF_flag = 3;
						//体力-30
						AddPlayerHp(-30);
					}
				}
				if (EFF_UDcount == 1)
				{
					EFF_flag = 4;
					//体力最大値を-50
					AddPlayerHpMAX(-50);

					//現在のHPを半分に
					PLAYERHP* player_hp = GetPlayerHp();
					int n = player_hp->gaugesize.x * 0.3125f;
					n = n / 2 * -1;
					AddPlayerHp(n);
				}
				sentence.use = false;
				choices_A.use = false;
				choices_B.use = false;
				frame.use = false;
			}
		}
	}
	if (EFF_flag == 2)
	{
		choices_A_success.use = true;
		EFF_flag = 5;
	}
	if (EFF_flag == 3)
	{
		choices_A_failure.use = true;
		EFF_flag = 5;
	}
	if (EFF_flag == 4)
	{
		choices_B_failure.use = true;
		EFF_flag = 5;
	}
	if (EFF_flag == 5)
	{
		if (PADUSE == 0)
		{
			if (IsButtonTriggered(0, BUTTON_Y) && EFF_time > 19)
			{
				map_player->nextflag = true;
				SceneTransition(SCENE_MAP);
			}
		}

		if (PADUSE == 1)
		{
			if (GetKeyboardTrigger(DIK_RETURN) && EFF_time > 19)
			{
				map_player->nextflag = true;
				SceneTransition(SCENE_MAP);
			}
		}
		EFF_time++;
	}
}

void Drawe_FloatingFeeling(void)
{
	if (sentence.use)
	{
		DrawSpriteLeftTop(sentence.texture, sentence.pos.x, sentence.pos.y, sentence.size.x, sentence.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
	if (title.use)
	{
		DrawSpriteLeftTop(title.texture, title.pos.x, title.pos.y, title.size.x, title.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
	if (choices_A.use)
	{
		DrawSpriteLeftTop(choices_A.texture, choices_A.pos.x, choices_A.pos.y, choices_A.size.x, choices_A.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
	if (choices_B.use)
	{
		DrawSpriteLeftTop(choices_B.texture, choices_B.pos.x, choices_B.pos.y, choices_B.size.x, choices_B.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
	if (choices_A_success.use)
	{
		DrawSpriteLeftTop(choices_A_success.texture, choices_A_success.pos.x, choices_A_success.pos.y, choices_A_success.size.x, choices_A_success.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
	if (choices_A_failure.use)
	{
		DrawSpriteLeftTop(choices_A_failure.texture, choices_A_failure.pos.x, choices_A_failure.pos.y, choices_A_failure.size.x, choices_A_failure.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
	if (choices_B_failure.use)
	{
		DrawSpriteLeftTop(choices_B_failure.texture, choices_B_failure.pos.x, choices_B_failure.pos.y, choices_B_failure.size.x, choices_B_failure.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
	if (frame.use)
	{
		DrawSpriteLeftTop(frame.texture, frame.pos.x, frame.pos.y, frame.size.x, frame.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
}
