//タイトル処理 [title.cpp]
#include "save.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "player_hp.h"
#include "player.h"

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
    PLAYER* player = GetPlayer();
    PLAYERHP* player_hp = GetPlayerHp();

    /*データの内容をファイルにセーブ*/
    if((fp = fopen(name, "w")) == NULL) {
        printf("ファイルオープンエラー\n");
    }
    else
    { 
        fprintf(fp, "攻撃力 = %d\n 所持金 = %d\n", player->atk, player->gold);
        fclose(fp);
    }
}

//-----ロード処理
void Load(void)
{
    /*ファイルの内容からデータをロード*/
    if ((fp = fopen(name, "r")) == NULL) {
        printf("ファイルオープンエラー\n");
    }
    else
    {
        fread(&save, sizeof(save), 1, fp);
        fclose(fp);
    }
}