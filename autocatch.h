#pragma once
//スキル_自動キャッチ処理 [auto_catch.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	bool use;	//スキルを使用したかを管理するフラグ
	float time;		//スキルの適用時間を管理する変数
	float time_2;		//スキル使用中に投げたボールを吸い寄せない為の適用時間を管理する変数
	bool timeflag;	//スキルの適用時間を管理するフラグ
	bool timeflag_2;	//スキル使用中に投げたボールを吸い寄せない為の適用時間を管理するフラグ
	bool auto_catchflag;	//スキル：オートキャッチが機能しているかのフラグ
	bool auto_catch;		//スキル：オートキャッチが機能し、キャッチに成功したかの状態

	int usegauge;	//バグゲージの上昇量
}AUTO;

//-----プロトタイプ宣言
HRESULT InitAuto_c(void);
void _Auto_c(void);

AUTO* GetAuto(void);