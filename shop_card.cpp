//商人マススキルカード処理[shop_card.cpp]
#include "shop_card.h"
//システム.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include <stdlib.h>
#include <time.h>
#include "sound.h"
//
#include "shop.h"
#include "shop_select.h"
#include "shop_gold.h"
#include "player.h"
#include "skillrandom.h"
#include "soundvolume_select.h"

SHOP_CARD shop_card[SKILL_NUM];
int notexture;
int shopsound;
int shopcardtexture;

HRESULT InitShopCard()
{	
	shopcardtexture = LoadTexture("data/TEXTURE/skill/skill.png");

	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();
	shopsound = LoadSound("data/SE/buy.wav");
	SetVolume(shopsound, soundvolume_select[1].count * 0.1f + 0.5f);

	notexture = LoadTexture("data/TEXTURE/test/yellow.png");

	int t = 0;

	RANDOM* random = GetRandom();
	SKILL* skill = GetSkill();

	for (int i = 0; i < shop_skill; i++)
	{
		shop_card[i].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.1f + SCREEN_WIDTH * 0.225f * i, SCREEN_HEIGHT * 0.1f);
		shop_card[i].size = D3DXVECTOR2(SCREEN_WIDTH * 0.125f, SCREEN_HEIGHT * 0.33333f);
		shop_card[i].drawflag = true;
		shop_card[i].u = 0.f;
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
		for (int j = 1; j < 27; j++)
		{
			if (shop_card[i].code == j)
					shop_card[i].u = 0.0384615385f * (j - 1);
		}
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

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_Y) && shop_select->ycount == 0 && shop_card[shop_select->xcount].drawflag == true
			&& shop_gold[shop_select->xcount].gold < player->gold)
		{
			PlaySound(shopsound, 0.5f);
			player->gold = player->gold - shop_gold[shop_select->xcount].gold;
			random[skill->slot].code = shop_card[shop_select->xcount].code;
			skill->slot = skill->slot + 1;
			shop_card[shop_select->xcount].drawflag = false;
		}
	}


	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_RETURN) && shop_select->ycount == 0 && shop_card[shop_select->xcount].drawflag == true
			&& shop_gold[shop_select->xcount].gold < player->gold)
		{
			PlaySound(shopsound, 0.5f);
			player->gold = player->gold - shop_gold[shop_select->xcount].gold;
			random[skill->slot].code = shop_card[shop_select->xcount].code;
			skill->slot = skill->slot + 1;
			shop_card[shop_select->xcount].drawflag = false;
		}
	}
}

void DrawShopCard()
{
	for (int i = 0; i < shop_skill; i++)
	{
		if(shop_card[i].drawflag == true)
			DrawSpriteLeftTop(shopcardtexture, shop_card[i].pos.x, shop_card[i].pos.y, shop_card[i].size.x, shop_card[i].size.y, shop_card[i].u, 0.0f, 0.0384615385f, 1.0f);
		if (shop_card[i].drawflag == false)
			DrawSpriteLeftTop(notexture, shop_card[i].pos.x, shop_card[i].pos.y, shop_card[i].size.x, shop_card[i].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
}

//-----構造体ポインタ取得処理
SHOP_CARD* GetShopCard(void)
{
	return &shop_card[0];
}