//タイトルチームロゴ処理 [title_teamname.cpp]
#include "title_teamname.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"
#include <time.h>
#include "sound.h"

#include "map_point.h"

//-----マクロ定義

//-----プロトタイプ宣言
TITLE_TEAMNAME title_teamname;

//-----グローバル変数

//-----初期化処理
HRESULT InitTitleTeamName(void)
{
	title_teamname.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
	title_teamname.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	title_teamname.a = 0.0f;
	title_teamname.color = D3DXCOLOR(1.0f, 1.0f, 1.0f, title_teamname.a);
	title_teamname.time = 0.0f;

	title_teamname.timeflag = false;

	title_teamname.callrandom = (rand() % 6) + 1;

	if (title_teamname.callrandom == 1)
		title_teamname.call = LoadSound("data/titlecall/benadasu.wav");
	if (title_teamname.callrandom == 2)
		title_teamname.call = LoadSound("data/titlecall/koyanagi.wav");
	if (title_teamname.callrandom == 3)
		title_teamname.call = LoadSound("data/titlecall/matsubara.wav");
	if (title_teamname.callrandom == 4)
		title_teamname.call = LoadSound("data/titlecall/tominaga.wav");
	if (title_teamname.callrandom == 5)
		title_teamname.call = LoadSound("data/titlecall/yanagi.wav");
	if (title_teamname.callrandom == 6)
		title_teamname.call = LoadSound("data/titlecall/hodono.wav");


	PlaySound(title_teamname.call, 0.5f);

	return S_OK;
}

//-----終了処理
void UninitTitleTeamName(void)
{

}

//-----更新処理
void UpdateTitleTeamName(void)
{
	srand((unsigned int)time(NULL));

	if(title_teamname.timeflag == false)
	title_teamname.time = title_teamname.time + 1.0f;

	title_teamname.color = D3DXCOLOR(1.0f, 1.0f, 1.0f, title_teamname.a);

	if(title_teamname.time > 0 && title_teamname.time < 60 && title_teamname.a < 1.0f)
	title_teamname.a = title_teamname.a + 0.016f;	//フェードイン

	if(title_teamname.time > 240 && title_teamname.a > 0.0f)
		title_teamname.a = title_teamname.a - 0.016f;	//フェードアウト

	if (title_teamname.time > 310)
	{
		title_teamname.timeflag = true;
		title_teamname.time = 0.f;
	}
}

//-----描画処理
void DrawTitleTeamName(void)
{
	DrawSpriteColor(title_teamname.texture, title_teamname.pos.x, title_teamname.pos.y, title_teamname.size.x, title_teamname.size.y,
		0.0f, 0.0f, 1.0f, 1.0f, title_teamname.color);
}

TITLE_TEAMNAME* GetTitleTeamName()
{
	return &title_teamname;
}