//�Z�[�u���� [map_save.cpp]
#include "map_save.h"
//�V�X�e��.h
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
	//�I��
	InitMapSaveSelect();

	return S_OK;
}

void UninitMapSave(void)
{
	//bg
	UninitMapSaveBG();
	//�I��
	UninitMapSaveSelect();

}

void UpdateMapSave(void)
{
	//bg
	UpdateMapSaveBG();
	//�I��
	UpdateMapSaveSelect();
}

void DrawMapSave(void)
{
	//bg
	DrawMapSaveBG();
	//�I��
	DrawMapSaveSelect();
}