//���l�}�X�X�L���Ē��I����[shop_reload.cpp]
#include "shop_reload.h"
//�V�X�e��.h
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
	shop_reload.pos = D3DXVECTOR2(1100.0f, 525.0f);
	shop_reload.size = D3DXVECTOR2(400.0f, 125.0f);
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

			do   //�d���`�F�b�N
			{
				shop_card[i].code = (rand() % skill->num) + 1;

				//for (t = 0; t < skill->num; t++)
				//{
				//	if (shop_card[i].code == random[t].code)	//���łɂ��̃X�L�����������Ă����������xcode������U��
				//	{
				//		if (random[t].haveflag == true)
				//			break;
				//	}
				//}

				for (t = 0; t < i; t++)
				{
					if (shop_card[i].code == shop_card[t].code)	//��肪�������������xcode������U��
						break;
				}
			} while (i != t);
		}

		for (int i = 0; i < shop_skill; i++)
		{
			//���蓖�Ă�ꂽcode�ɑΉ������e�N�X�`����\��
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