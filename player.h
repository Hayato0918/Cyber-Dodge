//プレイヤー処理[player.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXVECTOR2 move;
	int rotate;		//向いてる方向を取得する変数
	D3DXVECTOR2 colPos;	//岩石に対して行う当たり判定に使用する。中にはプレイヤーの足元の座標が入っている変数。

	float u, v, uw, vh;
	bool drawflag;	//描画するかを管理するフラグ

	int atk;		//攻撃力
	int def;		//防御力

	//テクスチャ
	int stand_Ltexture;		//立ち右向き
	int stand_Rtexture;		//立ち右向き
	bool standtextureflag;	//描画するかを管理するフラグ
	bool standLRflag;		//どっち向いているかを管理するフラグ

	int walk_Ltexture;		//歩き右向き
	int walk_Rtexture;		//歩き左向き
	bool walktextureflag;	//描画するかを管理するフラグ
	bool walkLRflag;		//どっち向いているかを管理するフラグ

	int catch_Ltexture;		//キャッチ右向き
	int catch_Rtexture;		//キャッチ左向き
	bool catchtextureflag;	//描画するかを管理するフラグ
	bool catchLRflag;		//どっち向いているかを管理するフラグ
	float catchtexturetime;	//アニメーションの時間を管理する変数

	int pick_Ltexture;		//拾い右向き
	int pick_Rtexture;		//拾い左向き
	bool picktextureflag;	//描画するかを管理するフラグ
	bool pickLRflag;		//どっち向いているかを管理するフラグ
	float picktexturetime;	//アニメーションの時間を管理する変数

	int throw_Ltexture;	//投げ右向き
	int throw_Rtexture;	//投げ左向き
	bool throwtextureflag;	//描画するかを管理するフラグ
	bool throwLRflag;		//どっち向いているかを管理するフラグ
	float throwtexturetime;//アニメーションの時間を管理する変数

	int skill_Ltexture;	//スキル右向き
	int skill_Rtexture;	//スキル左向き
	bool skilltextureflag;	//描画するかを管理するフラグ
	bool skillLRflag;		//どっち向いているかを管理するフラグ
	float skilltexturetime;//アニメーションの時間を管理する変数

	int damage_Ltexture;	//ダメージ右向き
	int damage_Rtexture;	//ダメージ左向き
	bool damagetextureflag;	//描画するかを管理するフラグ
	bool damageLRflag;		//どっち向いているかを管理するフラグ
	float damagetexturetime;//アニメーションの時間を管理する変数
	bool skilluseflag;		//スキルを使ったかどうかを管理するフラグ

	int deathtexture;		//死亡

	bool drawdepth;			//ボールとプレイヤーの描画順フラグ


}PLAYER;

//-----プロトタイプ宣言
HRESULT InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);

PLAYER* GetPlayer(void);