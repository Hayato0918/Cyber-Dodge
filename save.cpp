//タイトル処理 [title.cpp]
#include "save.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "player_hp.h"
#include "player.h"
#include "map_player.h"

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
    FILE* fp;
    PLAYER* player = GetPlayer();
    PLAYERHP* player_hp = GetPlayerHp();
    MAP_PLAYER* map_player = GetMapPlayer();

    fp = fopen(name, "wb");
    if (fp == NULL) return;

    save.hp = player_hp->gaugesize.x;
    save.atk = player->atk;
    save.def = player->def;
    save.gold = player->gold;
    save.gamecount = map_player->gamecount;
    save.UDcount = map_player->UDcount;

    fwrite(&save, sizeof(save), 4, fp);

    fclose(fp);
}

//-----ロード処理
void Load(void)
{
    FILE* fp;
    PLAYER* player = GetPlayer();
    PLAYERHP* player_hp = GetPlayerHp();
    MAP_PLAYER* map_player = GetMapPlayer();

    fp = fopen(name, "rb");

    if (fp == NULL)
    {

    }
    else
    {
        fread(&save, sizeof(save), 4, fp);

        player_hp->gaugesize.x = save.hp;
        player->atk = save.atk;
        player->def = save.def;
        player->gold = save.gold;
        map_player->gamecount = save.gamecount;
        map_player->UDcount = save.UDcount;

        fclose(fp);
    }
}