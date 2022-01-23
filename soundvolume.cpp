//サウンドボリューム処理 [soundvolume.cpp]
#include "soundvolume.h"
//
#include "soundvolume_bg.h"
#include "soundvolume_select.h"

#include "option_select.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数

//-----初期化処理
HRESULT InitSoundVolume(void)
{
	InitSoundVolumeBG();
	InitSoundVolumeSelect();

	return S_OK;
}

//-----終了処理
void UninitSoundVolume(void)
{
	UninitSoundVolumeBG();
	UninitSoundVolumeSelect();
}

//-----更新処理
void UpdateSoundVolume(void)
{
	OPTION_SELECT* option_select = GetOptionSelect();

	if (option_select->count == 2)
	{
		UpdateSoundVolumeBG();
		UpdateSoundVolumeSelect();
	}

}

//-----描画処理
void DrawSoundVolume(void)
{
	OPTION_SELECT* option_select = GetOptionSelect();

	if (option_select->count == 2)
	{
		DrawSoundVolumeBG();
		DrawSoundVolumeSelect();
	}

}