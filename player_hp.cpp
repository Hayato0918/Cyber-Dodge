//プレイヤーHP処理 [player_hp.h]
#include "player_hp.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"

//-----マクロ定義

//-----プロトタイプ宣言
PLAYERHP hp;

//-----グローバル変数

//-----初期化処理
HRESULT InitPlayerHp(void)
{
	hp.gaugeonce = 8;

	hp.framesize = D3DXVECTOR2(80.f * hp.gaugeonce, 60.0f); //HPバーフレームサイズ
	hp.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f - hp.framesize.x - 100.f , SCREEN_HEIGHT - 100.0f);
	hp.frametexture = LoadTexture("data/TEXTURE/bugframe.png");

	hp.gaugesize = D3DXVECTOR2(hp.framesize.x, hp.framesize.y); //残っているHPの量
	hp.gaugetexture = LoadTexture("data/TEXTURE/obstacle.png");

	return S_OK;
}

//-----終了処理
void UninitPlayerHp(void)
{

}

//-----更新処理
void UpdatePlayerHp(void)
{

}

//-----描画処理
void DrawPlayerHp(void)
{
	//-----バグゲージの描画
	DrawSpriteLeftTop(hp.gaugetexture, hp.pos.x, hp.pos.y, hp.gaugesize.x, hp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0f);

	//-----バグゲージの枠の描画
	DrawSpriteLeftTop(hp.frametexture, hp.pos.x, hp.pos.y, hp.framesize.x, hp.framesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----構造体ポインタ取得処理
PLAYERHP* GetPlayerHp()
{
	return &hp;
}