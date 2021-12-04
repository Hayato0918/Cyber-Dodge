//マップ移動処理 [map_hack.cpp]
#include "map_hack.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"

#include "map.h"

//-----マクロ定義

//-----プロトタイプ宣言
MAP_HACK map_hack;

//-----グローバル変数

//-----初期化処理
HRESULT InitMapHack(void)
{
	map_hack.pos = D3DXVECTOR2(325.0f, 450.0f);
	map_hack.size = D3DXVECTOR2(600.0f, 850.0f);
	map_hack.texture = LoadTexture("data/TEXTURE/hackingmenu/hackingmenu.png");

	map_hack.frame_pos = D3DXVECTOR2(350.0f, 250.0f);
	map_hack.frame_size = D3DXVECTOR2(450.0f, 100.0f);
	map_hack.frametexture = LoadTexture("data/TEXTURE/bugframe.png");

	map_hack.UDcount = 0;
	map_hack.isUse = true;

	return S_OK;
}

//-----終了処理
void UninitMapHack(void)
{

}

//-----更新処理
void UpdateMapHack(void)
{
	//TABキーで表示非表示切り替え
	if (GetKeyboardTrigger(DIK_TAB))
	{
		if (map_hack.isUse == true)
			map_hack.isUse = false;
		else
			map_hack.isUse = true;
	}

	//どのシーンに変えるかを選択する
	if (map_hack.isUse == true)
	{
		if (GetKeyboardTrigger(DIK_W) && map_hack.UDcount > 0)
		{
			map_hack.UDcount -= 1;
			map_hack.frame_pos.y -= 115.0f;
		}
		if (GetKeyboardTrigger(DIK_S) && map_hack.UDcount < 4)
		{
			map_hack.UDcount += 1;
			map_hack.frame_pos.y += 115.0f;
		}
	}
}

//-----描画処理
void DrawMapHack(void)
{
	if (map_hack.isUse == true)
	{
		DrawSpriteColor(map_hack.texture, map_hack.pos.x, map_hack.pos.y, map_hack.size.x, map_hack.size.y, 0.0f, 0.0f, 1.0f, 1.0f,
			D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
		DrawSpriteColor(map_hack.frametexture, map_hack.frame_pos.x, map_hack.frame_pos.y, map_hack.frame_size.x, map_hack.frame_size.y, 0.0f, 0.0f, 1.0f, 1.0f,
			D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
	}
}

MAP_HACK* GetMapHack()
{
	return &map_hack;
}
