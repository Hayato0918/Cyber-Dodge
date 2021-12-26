//休憩マス処理 [rest.cpp]
#include "rest.h"
//システム.h
#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"
//
#include "rest_bg.h"
#include "rest_picture.h"
#include "rest_status.h"
#include "rest_command.h"
#include "rest_exit.h"
#include "rest_select.h"

#include "player_hp.h"

REST rest;
RESTPOINT restpoint;

HRESULT InitRest(void)
{
	//bg
	InitRestBG();
	//一枚絵
	InitRestPicture();
	//ステータス表示
	InitRestStatus();
	//各種コマンド(HP回復、ステータス強化)
	InitRestCommand();
	//退出
	InitRestExit();
	//選択
	InitRestSelect();

	return S_OK;
}

void UninitRest(void)
{
	//bg
	UninitRestBG();
	//一枚絵
	UninitRestPicture();
	//ステータス表示
	UninitRestStatus();
	//各種コマンド(HP回復、ステータス強化)
	UninitRestCommand();
	//退出
	UninitRestExit();
	//選択
	UninitRestSelect();

}

void UpdateRest(void)
{
	//bg
	UpdateRestBG();
	//一枚絵
	UpdateRestPicture();
	//ステータス表示
	UpdateRestStatus();
	//各種コマンド(HP回復、ステータス強化)
	UpdateRestCommand();
	//退出
	UpdateRestExit();
	//選択
	UpdateRestSelect();
}

void DrawRest(void)
{
	//bg
	DrawRestBG();
	//一枚絵
	DrawRestPicture();
	//ステータス表示
	DrawRestStatus();
	//各種コマンド(HP回復、ステータス強化)
	DrawRestCommand();
	//退出
	DrawRestExit();
	//選択
	DrawRestSelect();
}