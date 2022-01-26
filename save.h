//セーブ処理 [save.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	float nameu;
	bool drawflag;
}SAVE_NAME;

typedef struct
{
	int floornum;
}SAVE_FLOOR;

typedef struct
{
	int scorenum;
}SAVE_SCORE;

typedef struct
{
	float nameu;

	float hp;
	int atk;
	int def;
	int gold;

	int gamecount;
	int UDcount;

}SAVE;

//-----プロトタイプ宣言
void NameSave(void);
void NameLoad();
void FloorSave();
void FloorLoad();
void ScoreSave();
void ScoreLoad();
SAVE_SCORE* GetSaveScore();

void Save(void);
void Load(void);