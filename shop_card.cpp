//商人マススキルカード処理[shop_card.cpp]
#include "shop_card.h"
//システム.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include <stdlib.h>
#include <time.h>
//
#include "shop.h"
#include "shop_select.h"
#include "shop_gold.h"
#include "player.h"
#include "skillrandom.h"

SHOP_CARD shop_card[SKILL_NUM];
int notexture;

HRESULT InitShopCard()
{
	notexture = LoadTexture("data/TEXTURE/test/yellow.png");

	int t = 0;

	RANDOM* random = GetRandom();
	SKILL* skill = GetSkill();

	for (int i = 0; i < shop_skill; i++)
	{
		shop_card[i].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.1f + SCREEN_WIDTH * 0.225f * i, SCREEN_HEIGHT * 0.1f);
		shop_card[i].size = D3DXVECTOR2(SCREEN_WIDTH * 0.125f, SCREEN_HEIGHT * 0.33333f);
		shop_card[i].drawflag = true;
	}

	for (int i = 0; i < shop_skill; i++)
	{
		srand((unsigned int)time(NULL));

		do   //重複チェック
		{
			shop_card[i].code = (rand() % skill->num) + 1;

			for (t = 0; t < i; t++)
			{
				if (shop_card[i].code == shop_card[t].code)	//被りがあったらもう一度codeを割り振る
					break;
			}
		} while (i != t);
	}

	for (int i = 0; i < shop_skill; i++)
	{
		//割り当てられたcodeに対応したテクスチャを表示
		if (shop_card[i].code == 1)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/speedup.png");
		if (shop_card[i].code == 2)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/turnaround.png");
		if (shop_card[i].code == 3)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/barrier.png");
		if (shop_card[i].code == 4)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/baseball.png");
		if (shop_card[i].code == 5)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/bigball.png");
		if (shop_card[i].code == 6)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/billiards.png");
		if (shop_card[i].code == 7)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/buildup.png");
		if (shop_card[i].code == 8)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/catchjamming.png");
		if (shop_card[i].code == 9)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/invade.png");
		if (shop_card[i].code == 10)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/invincible.png");
		if (shop_card[i].code == 11)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/penetration.png");
		if (shop_card[i].code == 12)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/rockcreate.png");
		if (shop_card[i].code == 13)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/slowarea.png");
		if (shop_card[i].code == 14)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/smallplayer.png");
		//if (shop_card[i].code == 15)
		//	shop_card[i].texture = LoadTexture("data/TEXTURE/skill/autocatch.png");
		if (shop_card[i].code == 16)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/disappear.png");
		if (shop_card[i].code == 17)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/doubleattack.png");
		if (shop_card[i].code == 18)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/enemy_powerdown.png");
		if (shop_card[i].code == 19)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/landmine.png");
		if (shop_card[i].code == 20)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/mindhack.png");
		if (shop_card[i].code == 21)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/otoshiana.png");
		if (shop_card[i].code == 22)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/player_powerup.png");
		if (shop_card[i].code == 23)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/player_regen.png");
		if (shop_card[i].code == 24)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/player_speedup.png");
		if (shop_card[i].code == 25)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/timestop.png");
		if (shop_card[i].code == 26)
			shop_card[i].texture = LoadTexture("data/TEXTURE/skill/warp.png");
	}

	return S_OK;
}

void UninitShopCard()
{

}

void UpdateShopCard()
{
	SHOP_SELECT* shop_select = GetShopSelect();
	RANDOM* random = GetRandom();
	SKILL * skill = GetSkill();
	SHOP_GOLD* shop_gold = GetShopGold();
	PLAYER* player = GetPlayer();

	if (GetKeyboardTrigger(DIK_RETURN) && shop_select->ycount == 0 && shop_card[shop_select->xcount].drawflag == true
		&& shop_gold[shop_select->xcount].gold < player->gold)
	{
		player->gold = player->gold - shop_gold[shop_select->xcount].gold;
		random[skill->slot].code = shop_card[shop_select->xcount].code;
		skill->slot = skill->slot + 1;
		shop_card[shop_select->xcount].drawflag = false;
	}
}

void DrawShopCard()
{
	for (int i = 0; i < shop_skill; i++)
	{
		if(shop_card[i].drawflag == true)
		DrawSpriteLeftTop(shop_card[i].texture, shop_card[i].pos.x, shop_card[i].pos.y, shop_card[i].size.x, shop_card[i].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		if (shop_card[i].drawflag == false)
			DrawSpriteLeftTop(notexture, shop_card[i].pos.x, shop_card[i].pos.y, shop_card[i].size.x, shop_card[i].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
}

//-----構造体ポインタ取得処理
SHOP_CARD* GetShopCard(void)
{
	return &shop_card[0];
}