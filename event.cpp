//イベント処理 [event.cpp]
#include "event.h"
#include "texture.h"
#include "sprite.h"

#include "avatar.h"
#include "dougyousya.h"
#include "floatingfeeling.h"
#include "hujyou.h"
#include "kasoukenkyuukuukan.h"
#include "mined.h"
#include "server_recovery.h"
#include "tosyokann.h"
#include "yomigaeru.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数

//-----初期化処理
HRESULT InitEvent(void)
{
	InitAvatar();
	InitDougyousya();
	Inite_FloatingFeeling();
	InitHujyou();
	InitKasou();
	InitMined();
	InitServerRecovery();
	InitTosyokann();
	InitYomigaeru();

	return S_OK;
}

//-----終了処理
void UninitEvent(void)
{
	UninitYomigaeru();
	UninitTosyokann();
	UninitServerRecovery();
	UninitMined();
	UninitKasou();
	UninitHujyou();
	UninitDougyousya();
	UninitAvatar();
}

//-----更新処理
void UpdateEvent(void)
{
	UpdateAvatar();
	UpdateDougyousya();
	_FloatingFeeling();
	UpdateHujyou();
	UpdateKasou();
	UpdateMined();
	UpdateServerRecovery();
	UpdateTosyokann();
	UpdateYomigaeru();
}

//-----描画処理
void DrawEvent(void)
{
	DrawAvatar();
	DrawDougyousya();
	DrawHujyou();
	DrawKasou();
	DrawMined();
	DrawServerRecovery();
	DrawTosyokann();
	DrawYomigaeru();
}