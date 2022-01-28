//チュートリアル処理 [tutorial.cpp]
#include "tutorial.h"

#include "main.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"

#include "map_player.h"

//必要なもの

//-----マクロ定義

//-----プロトタイプ宣言
TUTORIAL tutorial;

TUTORIAL_GAME tutorial_game;
TUTORIAL_SKILL tutorial_skill;
TUTORIAL_IDOU tutorial_idou;
TUTORIAL_NAGE tutorial_nage;
TUTORIAL_SUKILL tutorial_sukill;

//-----グローバル変数

//-----初期化処理
HRESULT InitTutorial(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	if (map_player->gamecount == 1)
	{
		tutorial.tutorialflag = true;

		tutorial_game.pos = D3DXVECTOR2(1350.f, 50.0f);
		tutorial_game.size = D3DXVECTOR2(200.f, 200.0f);
		tutorial_game.drawflag = true;

		tutorial_skill.pos = D3DXVECTOR2(1350.f, 50.0f);
		tutorial_skill.size = D3DXVECTOR2(200.f, 200.0f);
		tutorial_skill.drawflag = false;

		tutorial_idou.pos = D3DXVECTOR2(350.f, 220.0f);
		tutorial_idou.size = D3DXVECTOR2(300.f, 100.0f);
		tutorial_idou.time = 0.f;
		tutorial_idou.drawflag = true;

		tutorial_nage.pos = D3DXVECTOR2(350.f, 220.0f);
		tutorial_nage.size = D3DXVECTOR2(300.f, 100.0f);
		tutorial_nage.drawflag = false;
		tutorial_nage.throwflag = false;
		tutorial_nage.catchflag = false;

		tutorial_sukill.pos = D3DXVECTOR2(350.f, 220.0f);
		tutorial_sukill.size = D3DXVECTOR2(300.f, 100.0f);
		tutorial_sukill.drawflag = false;
		tutorial_sukill.skillusenum = 0;
		tutorial_sukill.reloadflag = false;
	}

	return S_OK;
}

//-----終了処理
void UninitTutorial(void)
{

}

//-----更新処理
void UpdateTutorial(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	if (map_player->gamecount == 1)
	{
		if (PADUSE == 0)
		{
			if (tutorial_idou.drawflag == true)
			{
				if (IsButtonPressed(0, BUTTON_UP) || IsButtonPressed(0, BUTTON_DOWN) || IsButtonPressed(0, BUTTON_LEFT) || IsButtonPressed(0, BUTTON_RIGHT))
					tutorial_idou.time = tutorial_idou.time + 1.f;
			}

			if (tutorial_nage.drawflag == true)
			{
				if (IsButtonTriggered(0, BUTTON_R))
					tutorial_nage.catchflag = true;
				if (IsButtonTriggered(0, BUTTON_R2))
					tutorial_nage.throwflag = true;
			}

			if (tutorial_sukill.drawflag == true)
			{
				if (IsButtonTriggered(0, BUTTON_L))
					tutorial_sukill.skillusenum = tutorial_sukill.skillusenum + 1;
				if (IsButtonTriggered(0, BUTTON_L2) && tutorial_sukill.skillusenum >= 3)
					tutorial_sukill.reloadflag = true;
			}

		}

		if (tutorial_idou.time > 140.f)
		{
			tutorial_nage.drawflag = true;
			tutorial_idou.drawflag = false;
			tutorial_idou.time = 0.f;
		}

		if (tutorial_nage.catchflag == true && tutorial_nage.throwflag == true)
		{
			tutorial_nage.drawflag = false;
			tutorial_game.drawflag = false;
			tutorial_skill.drawflag = true;
			tutorial_sukill.drawflag = true;
		}

		if (tutorial_sukill.reloadflag == true)
		{
			tutorial_sukill.drawflag = false;
			tutorial_skill.drawflag = false;
		}
	}
}

//-----描画処理
void DrawTutorial(void)
{
	if(tutorial_game.drawflag == true)
	DrawSpriteLeftTop(tutorial_game.texture, tutorial_game.pos.x, tutorial_game.pos.y, tutorial_game.size.x, tutorial_game.size.y, 0.f, 0.f, 1.f, 1.f);
	if (tutorial_skill.drawflag == true)
		DrawSpriteLeftTop(tutorial_skill.texture, tutorial_skill.pos.x, tutorial_skill.pos.y, tutorial_skill.size.x, tutorial_skill.size.y, 0.f, 0.f, 1.f, 1.f);

	if(tutorial_idou.drawflag == true)
	DrawSpriteLeftTop(tutorial_idou.texture, tutorial_idou.pos.x, tutorial_idou.pos.y, tutorial_idou.size.x, tutorial_idou.size.y, 0.f, 0.f, 1.f, 1.f);
	if (tutorial_nage.drawflag == true)
		DrawSpriteLeftTop(tutorial_nage.texture, tutorial_nage.pos.x, tutorial_nage.pos.y, tutorial_nage.size.x, tutorial_nage.size.y, 0.f, 0.f, 1.f, 1.f);
	if (tutorial_sukill.drawflag == true)
		DrawSpriteLeftTop(tutorial_sukill.texture, tutorial_sukill.pos.x, tutorial_sukill.pos.y, tutorial_sukill.size.x, tutorial_sukill.size.y, 0.f, 0.f, 1.f, 1.f);
}

TUTORIAL* GetTutorial(void)
{
	return &tutorial;
}

TUTORIAL_GAME* GetTutorialGame()
{
	return &tutorial_game;
}

TUTORIAL_SKILL* GetTutorialSkill()
{
	return &tutorial_skill;
}

TUTORIAL_IDOU* GetTutorialIdou()
{
	return &tutorial_idou;
}

TUTORIAL_NAGE* GetTutorialNage()
{
	return &tutorial_nage;
}

TUTORIAL_SUKILL* GetTutorialSukill()
{
	return &tutorial_sukill;
}