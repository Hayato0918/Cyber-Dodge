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

	enemyhp.framepos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 + 100.f, SCREEN_HEIGHT - 100.0f);
	enemyhp.framesize = D3DXVECTOR2(80.f * enemyhp.gaugeonce, 60.0f); //enemyhpバーフレームサイズ
	enemyhp.frametexture = LoadTexture("data/TEXTURE/bugframe.png");

	enemyhp.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 + 100.f, SCREEN_HEIGHT - 100.0f);
	enemyhp.gaugesize = D3DXVECTOR2(enemyhp.framesize.x, enemyhp.framesize.y); //残っているenemyhpの量
	enemyhp.gaugegreentexture = LoadTexture("data/TEXTURE/hp_green.png");
	enemyhp.gaugeredtexture = LoadTexture("data/TEXTURE/obstacle.png");

	enemyhp.hpsize = enemyhp.gaugesize.x;
	enemyhp.colorcangeflag = false;

	return S_OK;
}

//-----終了処理
void UninitEnemyHp(void)
{

}

//-----更新処理
void UpdateEnemyHp(void)
{
	if (enemyhp.gaugesize.x <= enemyhp.hpsize * 0.2f)
		enemyhp.colorcangeflag = true;
	if (enemyhp.gaugesize.x > enemyhp.hpsize * 0.2f)
		enemyhp.colorcangeflag = false;
}

//-----描画処理
void DrawEnemyHp(void)
{
	//-----HPゲージの描画
	if (enemyhp.colorcangeflag == false)
		DrawSpriteLeftTop(enemyhp.gaugegreentexture, enemyhp.pos.x, enemyhp.pos.y, enemyhp.gaugesize.x, enemyhp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
	if(enemyhp.colorcangeflag == true)
	DrawSpriteLeftTop(enemyhp.gaugeredtexture, enemyhp.pos.x, enemyhp.pos.y, enemyhp.gaugesize.x, enemyhp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0f);

	//-----HPゲージの枠の描画
	DrawSpriteLeftTop(enemyhp.frametexture, enemyhp.pos.x, enemyhp.pos.y, enemyhp.framesize.x, enemyhp.framesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----構造体ポインタ取得処理
ENEMYHP* GetEnemyHp()
{
	return &enemyhp;
}