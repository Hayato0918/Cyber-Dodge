//チュートリアル処理 [tutorial.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{

}TUTORIAL;

//-----プロトタイプ宣言
HRESULT InitTutorial(void);
void UninitTutorial(void);
void UpdateTutorial(void);
void DrawTutorial(void);
TUTORIAL* GetTutorial(void);