//タイトル処理 [title.cpp]
#include "save.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "player_hp.h"
#include "player.h"
#include "map_player.h"
#include "name_input.h"
#include "ranking_name.h"
#include "ranking_floor.h"
#include "map_floor.h"
#include "ranking_score.h"

#include "map_point.h"

//-----マクロ定義

//-----プロトタイプ宣言
FILE* fp;
SAVE_NAME save_name[8];
SAVE_FLOOR save_floor;
SAVE_SCORE save_score;

//-----グローバル変数
char* savename = "save_name.txt";
char* savefloor = "save_floor.txt";
char* savescore = "save_score.txt";

//-----セーブ処理
//-----名前
void NameSave(void)
{
    FILE* fp;
    NAME_INPUTWARD* playername = GetNameInputWard();

    fp = fopen(savename, "wb");
    if (fp == NULL) return;

    for (int i = 0; i < 8; i++)
    {
        save_name[i].nameu = playername[i].u;
        save_name[i].drawflag = playername[i].drawflag;
    }

    fwrite(&save_name, sizeof(save_name), 1, fp);

    fclose(fp);
}

void NameLoad(void)
{
    FILE* fp;
    RANKING_NAMENUM* namenum = GetRankingNameNum();
    RANKING_NAMECOUNT* namecount = GetRankingCount();

    fp = fopen(savename, "rb");

    if (fp == NULL)
    {

    }
    else
    {
        fread(&save_name, sizeof(save_name), 1, fp);

        for (int i = 0; i < 8; i++)
        {
            namenum[i].u = save_name[i].nameu;
            namenum[i].drawflag = save_name[i].drawflag;
        }
        namecount->count = namecount->count + 1;
        fclose(fp);
    }
}

//-----階層
void FloorSave(void)
{
    FILE* fp;
    MAP_FLOORBG* floornum = GetMapFloorNum();

    fp = fopen(savefloor, "wb");
    if (fp == NULL) return;

    save_floor.floornum = floornum->floornum;

    fwrite(&savefloor, sizeof(savefloor), 1, fp);

    fclose(fp);
}

void FloorLoad(void)
{
    FILE* fp;
    RANKING_FLOORNUM* ranking_floor = GetRankingFloorNum();

    fp = fopen(savefloor, "rb");

    if (fp == NULL)
    {

    }
    else
    {
        fread(&savefloor, sizeof(savefloor), 1, fp);

        if (ranking_floor[0].saveflag == true && ranking_floor[1].saveflag == true && ranking_floor[2].saveflag == true && ranking_floor[3].saveflag == false)
        {
            ranking_floor[3].floornum = save_floor.floornum;
            ranking_floor[3].saveflag = true;
        }
        if (ranking_floor[0].saveflag == true && ranking_floor[1].saveflag == true && ranking_floor[2].saveflag == false)
        {
            ranking_floor[2].floornum = save_floor.floornum + 2;
            ranking_floor[2].saveflag = true;
        }
        if (ranking_floor[0].saveflag == true && ranking_floor[1].saveflag == false)
        {
            ranking_floor[1].floornum = save_floor.floornum + 1;
            ranking_floor[1].saveflag = true;
        }
        if (ranking_floor[0].saveflag == false)
        {
            ranking_floor[0].floornum = save_floor.floornum;
            ranking_floor[0].saveflag = true;
        }

        fclose(fp);
    }
}

//-----スコア
void ScoreSave(void)
{
    FILE* fp;
    PLAYER* player = GetPlayer();

    fp = fopen(savescore, "wb");
    if (fp == NULL) return;

    save_score.scorenum = player->score;

    fwrite(&savescore, sizeof(savescore), 1, fp);

    fclose(fp);
}

void ScoreLoad(void)
{
    FILE* fp;
    RANKING_SCORENUM* ranking_score = GetRankingScoreNum();

    fp = fopen(savescore, "rb");

    if (fp == NULL)
    {

    }
    else
    {
        fread(&savescore, sizeof(savescore), 1, fp);

        if (ranking_score[0].saveflag == true && ranking_score[1].saveflag == true && ranking_score[2].saveflag == true && ranking_score[3].saveflag == false)
        {
            ranking_score[3].gold = save_score.scorenum;
            ranking_score[3].saveflag = true;
        }
        if (ranking_score[0].saveflag == true && ranking_score[1].saveflag == true && ranking_score[2].saveflag == false)
        {
            ranking_score[2].gold = save_score.scorenum;
            ranking_score[2].saveflag = true;
        }
        if (ranking_score[0].saveflag == true && ranking_score[1].saveflag == false)
        {
            ranking_score[1].gold = save_score.scorenum;
            ranking_score[1].saveflag = true;
        }
        if (ranking_score[0].saveflag == false)
        {
            ranking_score[0].gold = save_score.scorenum;
            ranking_score[0].saveflag = true;
        }

        fclose(fp);
    }
}

////-----セーブ処理
void Save(void)
{
//    FILE* fp;
//    PLAYER* player = GetPlayer();
//    PLAYERHP* player_hp = GetPlayerHp();
//    MAP_PLAYER* map_player = GetMapPlayer();
//
//    fp = fopen(name, "wb");
//    if (fp == NULL) return;
//
//    save.atk = player->atk;
//    save.def = player->def;
//    save.gold = player->gold;
//    save.gamecount = map_player->gamecount;
//    save.UDcount = map_player->UDcount;
//
//    fwrite(&save, sizeof(save), 4, fp);
//
//    fclose(fp);
}
//
////-----ロード処理
void Load(void)
{
//    FILE* fp;
//    PLAYER* player = GetPlayer();
//    PLAYERHP* player_hp = GetPlayerHp();
//    MAP_PLAYER* map_player = GetMapPlayer();
//
//    fp = fopen(name, "rb");
//
//    if (fp == NULL)
//    {
//
//    }
//    else
//    {
//        fread(&save, sizeof(save), 4, fp);
//
//        player_hp->gaugesize.x = save.hp;
//        player->atk = save.atk;
//        player->def = save.def;
//        player->gold = save.gold;
//        map_player->gamecount = save.gamecount;
//        map_player->UDcount = save.UDcount;
//
//        fclose(fp);
//    }
}