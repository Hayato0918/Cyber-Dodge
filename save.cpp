//タイトル処理 [title.cpp]
#include "save.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "player_hp.h"

#include "map_point.h"

//-----マクロ定義

//-----プロトタイプ宣言
FILE* fp;
SAVE save;

//-----グローバル変数
char* name = "savedata.txt";

//-----セーブ処理
void Save(void)
{
    /*
        ここでセーブする内容を更新する(各ステータス、スキルの状況を構造体に書き写す)
    */

    /*データの内容をファイルにセーブ*/
    if((fp = fopen(name, "wb")) == NULL) {
        printf("ファイルオープンエラー\n");
    }
    else
    { 
        fwrite(&save, sizeof(save), 1, fp);
        fclose(fp);
    }
}

//-----ロード処理
void Load(void)
{
    /*ファイルの内容からデータをロード*/
    if ((fp = fopen(name, "rb")) == NULL) {
        printf("ファイルオープンエラー\n");
    }
    else
    {
        fread(&save, sizeof(save), 1, fp);
        fclose(fp);
    }
}