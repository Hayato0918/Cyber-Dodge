//休憩マス退出処理 [rest.cpp]
#include "rest_exit.h"
//システム.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"
//
#include "rest_select.h"

REST_EXIT rest_exit;

HRESULT InitRestExit(void)
{
	rest_exit.pos = D3DXVECTOR2(1050.f, 700.0f);
	rest_exit.size = D3DXVECTOR2(500.0f, 150.0f);
	rest_exit.texture = LoadTexture("data/TEXTURE/test/yellow.png");

	return S_OK;
}

void UninitRestExit(void)
{

}

void UpdateRestExit(void)
{
	REST_SELECT* rest_select = GetRestSelect();

	//if (PADUSE == 0)
	//{
	//	if (IsButtonTriggered(0, BUTTON_X) && 1 < restpoint.count < 2)
	//		SceneTransition(SCENE_MAP);
	//}
	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_RETURN) && rest_select->count == 2)
			SceneTransition(SCENE_MAP);
	}
}

void DrawRestExit(void)
{
	DrawSpriteLeftTop(rest_exit.texture, rest_exit.pos.x, rest_exit.pos.y, rest_exit.size.x, rest_exit.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

REST_EXIT* GetRestExit()
{
	return &rest_exit;
}