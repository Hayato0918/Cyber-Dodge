//タイトルランキングボタン処理 [title_ranking.cpp]
#include "title_ranking.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"
#include "sound.h"

#include "soundvolume_select.h"

#include "title_bg.h"
#include "title_select.h"

//-----マクロ定義

//-----プロトタイプ宣言
TITLE_RANKING title_ranking;

//-----グローバル変数

//-----初期化処理
HRESULT InitTitleRanking(void)
{
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();

	title_ranking.sound = LoadSound("data/SE/titleselect.wav");
	SetVolume(title_ranking.sound, soundvolume_select[1].count * 0.1f + 0.5f);

	title_ranking.pos = D3DXVECTOR2(1270.f, 670.f);	//1600:900→1240,740
	title_ranking.size = D3DXVECTOR2(290.f, 70.f);	//1600:900→380,70

	return S_OK;
}

//-----終了処理
void UninitTitleRanking(void)
{

}

//-----更新処理
void UpdateTitleRanking(void)
{
	TITLE_SELECT* title_select = GetTitleSelect();
	TITLE_BG* title_bg = GetTitleBG();

	//if (PADUSE == 0)
	//{
	//	if (title_select->count == 2 && IsButtonTriggered(0, BUTTON_Y) && title_bg->drawflag == true)
	//	{
	//		PlaySound(title_ranking.sound, 0.5f);
	//		SceneTransition(SCENE_RANKING);
	//	}
	//}

	//if (PADUSE == 1)
	//{
	//	if (title_select->count == 2 && GetKeyboardTrigger(DIK_RETURN) && title_bg->drawflag == true)
	//	{
	//		PlaySound(title_ranking.sound, 0.5f);
	//		SceneTransition(SCENE_RANKING);
	//	}
	//}
}

//-----描画処理
void DrawTitleRanking(void)
{
	TITLE_BG* title_bg = GetTitleBG();

	if (title_bg->drawflag == true)
		DrawSpriteLeftTop(title_ranking.texture, title_ranking.pos.x, title_ranking.pos.y, title_ranking.size.x, title_ranking.size.y,
			0.0f, 0.0f, 1.0f, 1.0f);
}

TITLE_RANKING* GetTitleRanking(void)
{
	return &title_ranking;
}