//���l�}�X�I������[shop_select.cpp]
#include "shop_select.h"
//�V�X�e��.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
//
#include "shop.h"
#include "shop_card.h"
#include "shop_gold.h"
#include "shop_reload.h"
#include "shop_exit.h"

SHOP_SELECT shop_select;

HRESULT InitShopSelect()
{
	SHOP_CARD* shop_card = GetShopCard();

	shop_select.pos = D3DXVECTOR2(shop_card[0].pos.x, shop_card[0].pos.y);
	shop_select.size = D3DXVECTOR2(shop_card[0].size.x, shop_card[0].size.y);
	shop_select.texture = LoadTexture("data/TEXTURE/test/select.png");

	shop_select.xcount = 0;
	shop_select.ycount = 0;

	return S_OK;
}

void UninitShopSelect()
{

}

void UpdateShopSelect()
{
	SHOP_CARD* shop_card = GetShopCard();
	SHOP_RELOAD* shop_reload = GetShopReload();
	SHOP_EXIT* shop_exit = GetShopExit();

	if (PADUSE == 1)
	{
		//�I��
		if (GetKeyboardTrigger(DIK_A) && shop_select.xcount > 0)	//���ړ�
		{
			if (shop_select.ycount == 0)
			{
				shop_select.xcount -= 1;
				shop_select.pos.x = shop_card[shop_select.xcount].pos.x;
			}
		}
		if (GetKeyboardTrigger(DIK_D) && shop_select.xcount < shop_skill - 1)	//�E�ړ�
		{
			if (shop_select.ycount == 0)
			{
				shop_select.xcount += 1;
				shop_select.pos.x = shop_card[shop_select.xcount].pos.x;
			}
			if (shop_select.ycount == 1)
			{
				shop_select.xcount = 3;
				shop_select.pos = D3DXVECTOR2(shop_reload->pos.x, shop_reload->pos.y);
				shop_select.size = D3DXVECTOR2(shop_reload->size.x, shop_reload->size.y);
			}
		}
		if (GetKeyboardTrigger(DIK_S))	//���i�Ɉړ�
		{
			if (shop_select.ycount == 1 && shop_select.xcount > 1)	//�����[�h���痧������ֈړ�
			{
				shop_select.pos = D3DXVECTOR2(shop_exit->pos.x, shop_exit->pos.y);
				shop_select.size = D3DXVECTOR2(shop_exit->size.x, shop_exit->size.y);
				shop_select.ycount += 1;
			}
			if (shop_select.ycount == 0)
			{
				if (shop_select.xcount > 1)		//�I���J�[�h��2�Ԗڈȍ~�Ȃ�A�����[�h�R�}���h�ֈړ�
				{
					shop_select.pos = D3DXVECTOR2(shop_reload->pos.x, shop_reload->pos.y);
					shop_select.size = D3DXVECTOR2(shop_reload->size.x, shop_reload->size.y);
					shop_select.ycount += 1;
				}
			}
		}
		if (GetKeyboardTrigger(DIK_W))	//���i�����i�Ɉړ�
		{
			if (shop_select.ycount == 1)
			{
				shop_select.pos = D3DXVECTOR2(shop_card[shop_select.xcount].pos.x, shop_card[shop_select.xcount].pos.y);
				shop_select.size = D3DXVECTOR2(shop_card[shop_select.xcount].size.x, shop_card[shop_select.xcount].size.y);
				shop_select.ycount -= 1;
			}
			if (shop_select.ycount == 2)
			{
				shop_select.pos = D3DXVECTOR2(shop_reload->pos.x, shop_reload->pos.y);
				shop_select.size = D3DXVECTOR2(shop_reload->size.x, shop_reload->size.y);
				shop_select.ycount -= 1;
			}
		}

	}
}

void DrawShopSelect()
{
	DrawSpriteLeftTop(shop_select.texture, shop_select.pos.x, shop_select.pos.y, shop_select.size.x, shop_select.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

SHOP_SELECT* GetShopSelect()
{
	return &shop_select;
}