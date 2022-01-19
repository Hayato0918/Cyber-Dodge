//プレイヤーHP処理 [player_hp.h]
#include "player_hp.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"

#include "map_player.h"

//-----マクロ定義

//-----プロトタイプ宣言
PLAYERHP hp;

//-----グローバル変数

//-----初期化処理
HRESULT InitPlayerHp(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	if (map_player->gamecount == 1)
	{
		hp.gaugeonce = 8;

		hp.framepos = D3DXVECTOR2(100.0f, SCREEN_HEIGHT - 100.0f);
		hp.framesize = D3DXVECTOR2(80.f * hp.gaugeonce, 60.0f); //HPバーフレームサイズ
		hp.frametexture = LoadTexture("data/TEXTURE/player/hp/player_hpframe.png");

		hp.pos = D3DXVECTOR2(100.0f, SCREEN_HEIGHT - 100.0f);
		hp.gaugesize = D3DXVECTOR2(hp.framesize.x, hp.framesize.y); //残っているHPの量
		hp.gaugeredtexture = LoadTexture("data/TEXTURE/player/hp/player_hpred.png");
		hp.gaugegreentexture = LoadTexture("data/TEXTURE/player/hp/player_hpgreen.png");

		hp.hpsize = hp.gaugesize.x;
		hp.colorcangeflag = false;
	}

	return S_OK;
}

//-----終了処理
void UninitPlayerHp(void)
{

}

//-----更新処理
void UpdatePlayerHp(void)
{
	//-----HPが20%を切ったら
	if (hp.gaugesize.x <= hp.hpsize * 0.2f)
		hp.colorcangeflag = true;
	if (hp.gaugesize.x > hp.hpsize * 0.2f)
		hp.colorcangeflag = false;

	//-----HPのゲージ上限
	if (hp.gaugesize.x >= 640.0f)
	{
		hp.gaugesize.x = 640.0f;
	}
	//-----HPゲージの場所上限
	if (hp.pos.x <= 100.0f)
		hp.pos.x = 100.0f;
}

//-----描画処理
void DrawPlayerHp(void)
{
	//-----HPゲージの描画
	if (hp.colorcangeflag == false)	//HPが2割以上だったら
		DrawSpriteLeftTop(hp.gaugegreentexture, hp.pos.x, hp.pos.y, hp.gaugesize.x, hp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0);
	if(hp.colorcangeflag == true)	//HPが2割を切ったら
	DrawSpriteLeftTop(hp.gaugeredtexture, hp.pos.x, hp.pos.y, hp.gaugesize.x, hp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0);

	//-----HPゲージの枠の描画
	DrawSpriteLeftTop(hp.frametexture, hp.framepos.x, hp.framepos.y, hp.framesize.x, hp.framesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----構造体ポインタ取得処理
PLAYERHP* GetPlayerHp()
{
	return &hp;
}