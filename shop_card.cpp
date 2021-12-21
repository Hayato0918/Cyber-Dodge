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
#include "skillrandom.h"

SHOP_CARD shop_card[SKILL_NUM];
int notexture;

void InitShopCard()
{
	notexture = LoadTexture("data/TEXTURE/test/yellow.png");

	int t = 0;

	RANDOM* random = GetRandom();
	SKILL* skill = GetSkill();

	for (int i = 0; i < shop_skill; i++)
	{
		shop_card[i].pos = D3DXVECTOR2(160.0f + 360.f * i, 90.0f);
		shop_card[i].size = D3DXVECTOR2(200.0f, 300.0f);
		shop_card[i].drawflag = true;
	}

	for (int i = 0; i < shop_skill; i++)
	{
		do   //重複チェック
		{
			shop_card[i].code = (rand() % skill->num) + 1;

			//for (t = 0; t < skill->num; t++)
			//{
			//	if (shop_card[i].code == random[t].code)	//すでにそのスキルを所持していたらもう一度codeを割り振る
			//	{
			//		if (random[t].haveflag == true)
			//			break;
			//	}
			//}

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
	}
}

void UninitShopCard()
{

}

void UpdateShopCard()
{
	SHOP_SELECT* shop_select = GetShopSelect();
	RANDOM* random = GetRandom();
	SKILL * skill = GetSkill();

	srand((unsigned int)time(NULL));

	if (GetKeyboardTrigger(DIK_RETURN) && shop_select->ycount == 0 && shop_card[shop_select->xcount].drawflag == true)
	{
		skill->slot += 1;
		random[skill->slot].code = shop_card[shop_select->xcount].code;

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