//サウンドボリュームbg処理 [soundvolume_bg.cpp]
#include "soundvolume_bg.h"
//
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

//-----マクロ定義

//-----プロトタイプ宣言
BGM bgm;
SE se;

//-----グローバル変数

//-----初期化処理
HRESULT InitSoundVolumeBG(void)
{
	//-----bgm
	bgm.pos = D3DXVECTOR2(200.f, 250.f);
	bgm.size = D3DXVECTOR2(1200.f, 200.f);
	bgm.texture = LoadTexture("data/TEXTURE/option/bgm.png");

	//-----se
	se.pos = D3DXVECTOR2(200.f, 550.f);
	se.size = D3DXVECTOR2(1200.f, 200.f);
	se.texture = LoadTexture("data/TEXTURE/option/se.png");


	return S_OK;
}

//-----終了処理
void UninitSoundVolumeBG(void)
{

}

//-----更新処理
void UpdateSoundVolumeBG(void)
{

}

//-----描画処理
void DrawSoundVolumeBG(void)
{
	DrawSpriteLeftTop(bgm.texture, bgm.pos.x, bgm.pos.y, bgm.size.x, bgm.size.y,0.0f, 0.0f, 1.0f, 1.0f);
	DrawSpriteLeftTop(se.texture, se.pos.x, se.pos.y, se.size.x, se.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

BGM* GetBGM()
{
	return &bgm;
}
SE* GetSE()
{
	return &se;
}