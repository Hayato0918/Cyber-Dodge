//エネミーHP処理 [enemy_hp.cpp]
#include "enemy_hp.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"

//-----マクロ定義

//-----プロトタイプ宣言
ENEMYHP enemyhp;

//-----グローバル変数

//-----初期化処理
HRESULT InitEnemyHp(void)
{
	enemyhp.gaugeonce = 8;

	enemyhp.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 + 100.f, SCREEN_HEIGHT - 100.0f);
	enemyhp.framesize = D3DXVECTOR2(80.f * enemyhp.gaugeonce, 60.0f); //enemyhpバーフレームサイズ
	enemyhp.frametexture = LoadTexture("data/TEXTURE/bugframe.png");

	enemyhp.gaugesize = D3DXVECTOR2(enemyhp.framesize.x, enemyhp.framesize.y); //残っているenemyhpの量
	enemyhp.gaugetexture = LoadTexture("data/TEXTURE/obstacle.png");

	return S_OK;
}

//-----終了処理
void UninitEnemyHp(void)
{

}

//-----更新処理
void UpdateEnemyHp(void)
{

}

//-----描画処理
void DrawEnemyHp(void)
{
	//-----バグゲージの描画
	DrawSpriteLeftTop(enemyhp.gaugetexture, enemyhp.pos.x, enemyhp.pos.y, enemyhp.gaugesize.x, enemyhp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0f);

	//-----バグゲージの枠の描画
	DrawSpriteLeftTop(enemyhp.frametexture, enemyhp.pos.x, enemyhp.pos.y, enemyhp.framesize.x, enemyhp.framesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----構造体ポインタ取得処理
ENEMYHP* GetEnemyHp()
{
	return &enemyhp;
}