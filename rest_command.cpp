//休憩マスコマンド処理 [rest_command.cpp]
#include "rest_command.h"
//システム.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
//
#include "rest_select.h"
#include "player_hp.h"

REST_HPUP rest_hpup;
REST_STATUSUP rest_statusup;

HRESULT InitRestCommand(void)
{
	//---------- HP回復 ----------//
	rest_hpup.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.30625f, SCREEN_HEIGHT * 0.211111f);
	rest_hpup.size = D3DXVECTOR2(SCREEN_WIDTH * 0.15625f, SCREEN_HEIGHT * 0.277777f);
	rest_hpup.texture = LoadTexture("data/TEXTURE/test/yellow.png");

	//---------- ステータス強化 ----------//
	rest_statusup.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5125f, SCREEN_HEIGHT * 0.211111f);
	rest_statusup.size = D3DXVECTOR2(SCREEN_WIDTH * 0.15625f, SCREEN_HEIGHT * 0.277777f);
	rest_statusup.texture = LoadTexture("data/TEXTURE/test/yellow.png");

	return S_OK;
}

void UninitRestCommand(void)
{

}

void UpdateRestCommand(void)
{
	REST_SELECT* rest_select = GetRestSelect();
	PLAYERHP* player_hp = GetPlayerHp();

	if (rest_select->count == 0)
	{
		if (GetKeyboardTrigger(DIK_RETURN))
		{

		}
	}


}

void DrawRestCommand(void)
{
	//----------HP回復----------//
	DrawSpriteLeftTop(rest_hpup.texture, rest_hpup.pos.x, rest_hpup.pos.y, rest_hpup.size.x, rest_hpup.size.y, 0.0f, 0.0f, 1.0f, 1.0f);

	//----------ステータス強化----------//
	DrawSpriteLeftTop(rest_statusup.texture, rest_statusup.pos.x, rest_statusup.pos.y, rest_statusup.size.x, rest_statusup.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

REST_HPUP* GetRestCommandHP()
{
	return &rest_hpup;
}
REST_STATUSUP* GetRestCommandStatus()
{
	return &rest_statusup;
}