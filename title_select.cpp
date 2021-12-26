//タイトル選択処理 [title_select.cpp]
#include "title_select.h"
//システム.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
//
#include "title_bg.h"
#include "title_gamestart.h"
#include "title_exit.h"

TITLE_SELECT title_select;

HRESULT InitTitleSelect(void)
{
	TITLE_START* title_start = GetTitleStart();

	title_select.pos = D3DXVECTOR2(title_start->pos.x, title_start->pos.y);
	title_select.size = D3DXVECTOR2(title_start->size.x, title_start->size.y);
	title_select.count = 0;
	title_select.texture = LoadTexture("data/TEXTURE/rest_frame.png");

	return S_OK;
}

void UninitTitleSelect(void)
{

}

void UpdateTitleSelect(void)
{
	TITLE_START* title_start = GetTitleStart();
	TITLE_EXIT* title_exit = GetTitleExit();

	//if (PADUSE == 0)
	//{
	//	//休憩マスの選択
	//	if (IsButtonTriggered(0, BUTTON_UP) && rest_select.count > 0)
	//	{
	//		rest_select.pos.y -= 116;
	//		rest_select.count -= 1;
	//	}
	//	if (IsButtonTriggered(0, BUTTON_DOWN) && rest_select.count < 2)
	//	{
	//		rest_select.pos.y += 116;
	//		rest_select.count += 1;
	//	}
	//	//選択した時の効果
	//	if (IsButtonTriggered(0, BUTTON_X) && rest_select.count == 0)
	//	{
	//		player_hp->gaugesize.x = player_hp->gaugesize.x + 100;
	//		player_hp->pos.x = player_hp->pos.x - 100;
	//		SceneTransition(SCENE_MAP);
	//	}

	//}
	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_W) && title_select.count > 0)		//上移動
			title_select.count -= 1;
		if (GetKeyboardTrigger(DIK_S) && title_select.count < 1)		//下移動
			title_select.count += 1;
	}


	if (title_select.count == 0)
	{
		title_select.pos = D3DXVECTOR2(title_start->pos.x, title_start->pos.y);
		title_select.size = D3DXVECTOR2(title_start->size.x, title_start->size.y);
	}
	if (title_select.count == 1)
	{
		title_select.pos = D3DXVECTOR2(title_exit->pos.x, title_exit->pos.y);
		title_select.size = D3DXVECTOR2(title_exit->size.x, title_exit->size.y);
	}
}

void DrawTitleSelect(void)
{
	TITLE_BG* title_bg = GetTitleBG();

	if(title_bg->drawflag == true)
	DrawSpriteLeftTop(title_select.texture, title_select.pos.x, title_select.pos.y, title_select.size.x, title_select.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

TITLE_SELECT* GetTitleSelect()
{
	return &title_select;
}