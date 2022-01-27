//ファイアーウォール処理[firewall.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXVECTOR2 move;
	D3DXVECTOR2 colPos;
	int rotate;		//向いてる方向を取得する変数

	bool drawflag;	//描画するかを管理するフラグ
	float u, v, uw, vh;

	int hp;			//体力
	int atk;		//攻撃力
	int def;		//防御力

	bool getskill;		//スキルを入手したかを管理するフラグ

	bool floorflag;

	//テクスチャ
	int stand_Ltexture;		//立ち右向き
	int stand_Rtexture;		//立ち右向き
	bool standtextureflag;	//描画するかを管理するフラグ
	bool standLRflag;		//どっち向いているかを管理するフラグ
	float standtexturetime;

	int walk_Ltexture;		//歩き右向き
	int walk_Rtexture;		//歩き左向き
	bool walktextureflag;	//描画するかを管理するフラグ
	bool walkLRflag;		//どっち向いているかを管理するフラグ
	float walktexturetime;

	int catch_Ltexture;	//投げ右向き
	int catch_Rtexture;	//投げ左向き
	bool catchtextureflag;	//描画するかを管理するフラグ
	bool catchLRflag;		//どっち向いているかを管理するフラグ
	float catchtexturetime;//アニメーションの時間を管理する変数

	int throw_Ltexture;	//投げ右向き
	int throw_Rtexture;	//投げ左向き
	bool throwtextureflag;	//描画するかを管理するフラグ
	bool throwLRflag;		//どっち向いているかを管理するフラグ
	float throwtexturetime;//アニメーションの時間を管理する変数

	int damage_Ltexture;	//ダメージ右向き
	int damage_Rtexture;	//ダメージ左向き
	bool damagetextureflag;	//描画するかを管理するフラグ
	bool damageLRflag;		//どっち向いているかを管理するフラグ
	float damagetexturetime;//アニメーションの時間を管理する変数

	int deathtexture;		//死亡

}FIREWALL;

//-----プロトタイプ宣言
HRESULT InitFireWall(void);
void UninitFireWall(void);
void UpdateFireWall(void);
void DrawFireWall(void);

FIREWALL* GetFireWall(void);