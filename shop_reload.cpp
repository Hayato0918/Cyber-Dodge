//���l�}�X�X�L���Ē��I����[shop_reload.cpp]
#include "shop_reload.h"
//�V�X�e��.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "sound.h"
//
#include "shop.h"
#include "shop_select.h"
#include "shop_card.h"
#include "skillrandom.h"
#include "soundvolume_select.h"

#include "player.h"

SHOP_RELOAD shop_reload;

HRESULT InitShopReload()
{
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();

	shop_reload.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.6875f, SCREEN_HEIGHT * 0.5833333f);
	shop_reload.size = D3DXVECTOR2(SCREEN_WIDTH * 0.25f, SCREEN_HEIGHT * 0.1388888f);
	shop_reload.reloadflag = false;
	shop_reload.gold = 10;
	shop_reload.sound = LoadSound("data/SE/reload.wav");
	SetVolume(shop_reload.sound, soundvolume_select[1].count * 0.1f + 0.5f);

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

	PLAYER* player = GetPlayer();

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_Y) && shop_select->xcount > 1 && shop_select->ycount == 1 && player->gold >= shop_reload.gold)
		{
			PlaySound(shop_reload.sound, 0.5f);
			shop_reload.reloadflag = true;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_RETURN) && shop_select->xcount > 1 && shop_select->ycount == 1 && player->gold >= shop_reload.gold)
		{
			PlaySound(shop_reload.sound, 0.5f);
			shop_reload.reloadflag = true;
		}
	}

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
			for (int j = 1; j < 27; j++)
			{
				if (shop_card[i].code == j)
					shop_card[i].u = 0.0384615385f * (j - 1);
			}
		}

		player->gold = player->gold - shop_reload.gold;
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