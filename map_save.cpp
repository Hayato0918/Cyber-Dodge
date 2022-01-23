//セーブ処理 [map_save.cpp]
#include "map_save.h"
//システム.h
#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"
//
#include "map_save_bg.h"
#include "map_save_select.h"

HRESULT InitMapSave(void)
{
	//bg
	InitMapSaveBG();
	//選択
	InitMapSaveSelect();

	return S_OK;
}

void UninitMapSave(void)
{
	//bg
	UninitMapSaveBG();
	//選択
	UninitMapSaveSelect();

}

void UpdateMapSave(void)
{
	//bg
	UpdateMapSaveBG();
	//選択
	UpdateMapSaveSelect();
}

void DrawMapSave(void)
{
	//bg
	DrawMapSaveBG();
	//選択
	DrawMapSaveSelect();
}