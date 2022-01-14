//設定選択処理 [option_select.cpp]
#include "option_select.h"
//システム.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
//

OPTION_SELECT option_select;

HRESULT InitOptionSelect(void)
{
	option_select.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.093f, SCREEN_HEIGHT * 0.111f);		//1600:900→150:100
	option_select.size = D3DXVECTOR2(SCREEN_WIDTH * 0.056f, SCREEN_HEIGHT * 0.1f);		//1600:900→90:90
	option_select.count = 0;
	option_select.texture = LoadTexture("data/TEXTURE/option/option_select.png");

	return S_OK;
}

void UninitOptionSelect(void)
{

}

void UpdateOptionSelect(void)
{
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
		if (GetKeyboardTrigger(DIK_A) && option_select.count > 0)		//左移動
		{
			option_select.pos.x -= SCREEN_WIDTH * 0.3f;	//1600:900→500
			option_select.count -= 1;
		}
		if (GetKeyboardTrigger(DIK_D) && option_select.count < 2)		//右移動
		{
			option_select.pos.x += SCREEN_WIDTH * 0.3f;	//1600:900→500
			option_select.count += 1;
		}
	}
}

void DrawOptionSelect(void)
{
	DrawSpriteLeftTop(option_select.texture, option_select.pos.x, option_select.pos.y, option_select.size.x, option_select.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

OPTION_SELECT* GetOptionSelect()
{
	return &option_select;
}