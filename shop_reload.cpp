//商人マススキル再抽選処理[shop_reload.cpp]
#include "shop_reload.h"
//システム.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
//
#include "shop.h"
#include "shop_select.h"
#include "shop_card.h"
#include "skillrandom.h"

SHOP_RELOAD shop_reload;

HRESULT InitShopReload()
{
	shop_reload.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.6875f, SCREEN_HEIGHT * 0.5833333f);
	shop_reload.size = D3DXVECTOR2(SCREEN_WIDTH * 0.25f, SCREEN_HEIGHT * 0.1388888f);
	shop_reload.reloadflag = false;
	shop_reload.texture = LoadTexture("data/TEXTURE/test/red.png");

	return S_OK;
}

void UninitShopReload()
{

}

void UpdateShopReload()
{
	SHOP_SELECT* shop_select = GetShopSelect();
	SHOP_CARD* shop_card = GetShopCard();
	RANDOM* random = GetRandom();
	SKILL* skill = GetSkill();

	if (GetKeyboardTrigger(DIK_RETURN) && shop_select->xcount > 1 && shop_select->ycount == 1)
		shop_reload.reloadflag = true;

	int t = 0;

	if (shop_reload.reloadflag == true)
	{
		for (int i = 0; i < shop_skill; i++)
		{
			shop_card[i].drawflag = true;

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

		shop_reload.reloadflag = false;
	}
}

void DrawShopReload()
{
	DrawSpriteLeftTop(shop_reload.texture, shop_reload.pos.x, shop_reload.pos.y, shop_reload.size.x, shop_reload.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

SHOP_RELOAD* GetShopReload()
{
	return &shop_reload;
}