//マップマス/マッププレイヤー/マップライン処理 [map_point.cpp]
#include <stdlib.h>
#include <time.h>

#include "map_player.h"
#include "map_point.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"
#include "sound.h"
#include "soundvolume_select.h" 

#include "bugincrease.h"
#include "map_hack.h"
#include "map_line.h"
#include "hackeffect.h"
#include "banner_bug.h"
#include "map_save_bg.h"
#include "map_bg.h"

#include "tutorial.h"

//-----マクロ定義

//-----プロトタイプ宣言
MAP_PLAYER map_player;

//-----グローバル変数

//-----初期化処理
HRESULT InitMapPlayer(void)
{
		MAP* map = GetMapPoint();
		MAP_SB* map_sb = GetMapSB();
		MAP_LINE* map_line = GetMapLine();
		SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();

		map_player.sound = LoadSound("data/SE/cursormove.wav");
		SetVolume(map_player.sound, soundvolume_select[1].count * 0.1f + 0.5f);

		//プレイヤーの初期化
		if (map_player.UDcount == 0)
		{
			if (map_player.gamecount == 0)
				map_player.floor = 1;

			map_player.size = D3DXVECTOR2(SCREEN_WIDTH * 0.0625f, SCREEN_HEIGHT * 0.11111f);
			map_player.pos = D3DXVECTOR2(map_sb->startpos.x, map_sb->startpos.y);
			map_player.texture = LoadTexture("data/TEXTURE/map_player.png");
			map_player.UDcount = 0;
			map_player.LRcount = 0;
			map_player.nowpos = 0;

			//選択の枠の初期化
			map_player.circlepos = D3DXVECTOR2(map[0].pos.x, map[0].pos.y);
			map_player.circlesize = D3DXVECTOR2(map[0].size.x, map[0].size.y);
			map_player.circletexture = LoadTexture("data/TEXTURE/map/circle.png");
			map_player.circlenowpos = 0;

			map_player.gamecount = 0;

			map_player.nextflag = true;

			if (map_line->randomcode == 1)
				map_player.mapnum = 21;
			if (map_line->randomcode == 2)
				map_player.mapnum = 20;
			if (map_line->randomcode == 3)
				map_player.mapnum = 18;
			if (map_line->randomcode == 4)
				map_player.mapnum = 24;
		}

	return S_OK;
}

//終了処理
void UninitMapPlayer(void)
{

}

//-----更新処理
void UpdateMapPlayer(void)
{
	MAP_HACK* map_hack = GetMapHack();
	MAP* map = GetMapPoint();
	MAP_SB* map_sb = GetMapSB();
	MAP_LINE* map_line = GetMapLine();
	HACKEFFECT* hackeffect = GetHackEffect();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	BANNER_BUGNUM* banner_bugnum = GetBannerBug();
	MAPSAVE_BG* map_save = GetMapSaveBG();
	MAP_BG* map_bg = GetMapBG();

	TUTORIAL* tutorial = GetTutorial();

	//-----マップスクロール
	if (map_hack->isUse == false && map_save->drawflag == false)
	{
		if (PADUSE == 0)
		{
			if (IsButtonPressed(0, BUTTON_UP) && map_bg->pos.y < 60)	//上
			{
				map_player.pos.y += 5;
				map_player.circlepos.y += 5;
			}
			if (IsButtonPressed(0, BUTTON_DOWN) && map_bg->pos.y > -580)	//上
			{
				map_player.pos.y -= 5;
				map_player.circlepos.y -= 5;
			}

			if (map_player.nextflag == true)
			{
				//-----シート1の場合
				if (map_line->randomcode == 1)
				{
					//7段目
					//18→boss
					if (map_player.nowpos == 19 || map_player.nowpos == 20 || map_player.nowpos == 21)
					{
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
							map_player.nowpos = 22;
							map_player.encount = 3;
							SceneTransition(SCENE_GAME);
							map_player.nextflag = false;
						}
					}

					//6段目
					//15→18
					if (map_player.nowpos == 16)
					{
						map_player.circlenowpos = 18;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
							map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
							map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
							map_player.nowpos = 19;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//16→19
					if (map_player.nowpos == 17)
					{
						map_player.circlenowpos = 19;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[19].pos.x, map[19].pos.y);
							map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
							map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
							map_player.nowpos = 19;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//17→20
					if (map_player.nowpos == 18)
					{
						map_player.circlenowpos = 20;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[20].pos.x, map[20].pos.y);
							map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
							map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
							map_player.nowpos = 21;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//5段目
					//10→15
					if (map_player.nowpos == 11)
					{
						map_player.circlenowpos = 15;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
							map_player.nowpos = 16;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//13→16、13→17
					if (map_player.nowpos == 14)
					{
						map_player.circlenowpos = map_player.LRcount + 16;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 16].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 16].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 16].pos.x, map[map_player.LRcount + 16].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[19].pos.x, map[19].pos.y);
								map_player.nowpos = 17;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[20].pos.x, map[20].pos.y);
								map_player.nowpos = 18;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//14→17
					if (map_player.nowpos == 15)
					{
						map_player.circlenowpos = 17;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[20].pos.x, map[20].pos.y);
							map_player.nowpos = 18;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//-----4段目
					//12→14、12→15
					if (map_player.nowpos == 12)
					{
						map_player.circlenowpos = map_player.LRcount + 13;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 13].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 13].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 13].pos.x, map[map_player.LRcount + 13].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
								map_player.nowpos = 14;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
								map_player.nowpos = 15;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//13→15
					if (map_player.nowpos == 13)
					{
						map_player.circlenowpos = 14;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
							map_player.nowpos = 15;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//-----3段目
					//7→10
					if (map_player.nowpos == 8)
					{
						map_player.circlenowpos = 10;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
							map_player.nowpos = 11;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//8→10、8→11
					if (map_player.nowpos == 9)
					{
						map_player.circlenowpos = map_player.LRcount + 10;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 10].pos.x, map[map_player.LRcount + 10].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
								map_player.nowpos = 11;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
								map_player.nowpos = 12;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//10→12、10→13
					if (map_player.nowpos == 10)
					{
						map_player.circlenowpos = map_player.LRcount + 11;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 11].pos.x, map[map_player.LRcount + 11].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
								map_player.nowpos = 12;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
								map_player.nowpos = 13;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//-----2段目
					//5→8
					if (map_player.nowpos == 5)
					{
						map_player.circlenowpos = 7;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
							map_player.nowpos = 8;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//6→9
					if (map_player.nowpos == 6)
					{
						map_player.circlenowpos = 8;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
							map_player.nowpos = 9;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//7→10
					if (map_player.nowpos == 7)
					{
						map_player.circlenowpos = 9;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[11].pos.x, map[11].pos.y);
							map_player.nowpos = 10;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//-----1段目
					//0→5、1→5
					if (map_player.nowpos == 1 || map_player.nowpos == 2)
					{
						map_player.circlenowpos = 4;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
							map_player.nowpos = 5;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					if (map_player.nowpos == 3)
					{
						map_player.circlenowpos = map_player.LRcount + 5;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 5].pos.x, map[map_player.LRcount + 5].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
								map_player.nowpos = 6;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
								map_player.nowpos = 7;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//4→7
					if (map_player.nowpos == 4)
					{
						map_player.circlenowpos = 6;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
							map_player.nowpos = 7;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//-----0段目
					if (map_player.nowpos == 0)
					{
						map_player.circlenowpos = map_player.LRcount;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 3)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount].pos.x, map[map_player.LRcount].pos.y);
							map_player.nowpos = map_player.LRcount + 1;
							if (map_player.nowpos == 1 || map_player.nowpos == 2)
								map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
							if (map_player.nowpos == 3)
								map_player.circlepos = D3DXVECTOR2(map[5].pos.x, map[5].pos.y);
							if (map_player.nowpos == 4)
								map_player.circlepos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
				}

				//-----シート2の場合
				if (map_line->randomcode == 2)
				{
					//7段目
					//18→boss
					if (map_player.nowpos == 18 || map_player.nowpos == 19 || map_player.nowpos == 20)
					{
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
							map_player.nowpos = 21;
							map_player.encount = 3;
							SceneTransition(SCENE_GAME);
							map_player.nextflag = false;
						}
					}

					//6段目
					//16→18
					if (map_player.nowpos == 16)
					{
						map_player.circlenowpos = 17;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
							map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
							map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
							map_player.nowpos = 18;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//17→19、17→20
					if (map_player.nowpos == 17)
					{
						map_player.circlenowpos = map_player.LRcount + 18;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 18].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 18].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 18].pos.x, map[map_player.LRcount + 18].pos.y);
							map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
							map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
							if (map_player.LRcount == 0)
								map_player.nowpos = 19;
							if (map_player.LRcount == 1)
								map_player.nowpos = 20;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//5段目
					//10→16
					if (map_player.nowpos == 10)
					{
						map_player.circlenowpos = 15;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
							map_player.nowpos = 16;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//14→17
					if (map_player.nowpos == 14)
					{
						map_player.circlenowpos = 16;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
							map_player.nowpos = 17;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//15→17
					if (map_player.nowpos == 15)
					{
						map_player.circlenowpos = 16;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
							map_player.nowpos = 17;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//4段目
					//11→14
					if (map_player.nowpos == 11)
					{
						map_player.circlenowpos = 13;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
							map_player.nowpos = 14;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//12→14、12→15
					if (map_player.nowpos == 12)
					{
						map_player.circlenowpos = map_player.LRcount + 13;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 13].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 13].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 13].pos.x, map[map_player.LRcount + 13].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
								map_player.nowpos = 14;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
								map_player.nowpos = 15;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//13→15
					if (map_player.nowpos == 13)
					{
						map_player.circlenowpos = 14;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
							map_player.nowpos = 15;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//3段目
					//７→10、7→11
					if (map_player.nowpos == 7)
					{
						map_player.circlenowpos = map_player.LRcount + 9;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 9].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 9].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 9].pos.x, map[map_player.LRcount + 9].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
								map_player.nowpos = 10;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
								map_player.nowpos = 11;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//8→12
					if (map_player.nowpos == 8)
					{
						map_player.circlenowpos = 11;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[11].pos.x, map[11].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
							map_player.nowpos = 12;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//9→12、9→13
					if (map_player.nowpos == 9)
					{
						map_player.circlenowpos = map_player.LRcount + 11;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 11].pos.x, map[map_player.LRcount + 11].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
								map_player.nowpos = 12;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
								map_player.nowpos = 13;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//2段目
					//４→7
					if (map_player.nowpos == 4)
					{
						map_player.circlenowpos = 6;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
							map_player.nowpos = 7;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//5→8
					if (map_player.nowpos == 5)
					{
						map_player.circlenowpos = 7;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[11].pos.x, map[11].pos.y);
							map_player.nowpos = 8;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//6→9
					if (map_player.nowpos == 6)
					{
						map_player.circlenowpos = 8;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[11].pos.x, map[11].pos.y);
							map_player.nowpos = 9;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//1段目
					//1→4
					if (map_player.nowpos == 1)
					{
						map_player.circlenowpos = 3;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[3].pos.x, map[3].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
							map_player.nowpos = 4;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//2→5、2→6
					if (map_player.nowpos == 2)
					{
						map_player.circlenowpos = map_player.LRcount + 4;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 4].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 4].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 4].pos.x, map[map_player.LRcount + 4].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
								map_player.nowpos = 5;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
								map_player.nowpos = 6;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//3→6
					if (map_player.nowpos == 3)
					{
						map_player.circlenowpos = 5;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[5].pos.x, map[5].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
							map_player.nowpos = 6;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//0段目
					if (map_player.nowpos == 0)
					{
						map_player.circlenowpos = map_player.LRcount;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 2)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount].pos.x, map[map_player.LRcount].pos.y);
							map_player.nowpos = map_player.LRcount + 1;
							if (map_player.nowpos == 1)
								map_player.circlepos = D3DXVECTOR2(map[3].pos.x, map[3].pos.y);
							if (map_player.nowpos == 2)
								map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
							if (map_player.nowpos == 3)
								map_player.circlepos = D3DXVECTOR2(map[5].pos.x, map[5].pos.y);
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
				}

				//-----シート3の場合
				if (map_line->randomcode == 3)
				{
					//7段目
					//→boss
					if (map_player.nowpos == 17 || map_player.nowpos == 18)
					{
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
							map_player.nowpos = 19;
							map_player.encount = 3;
							SceneTransition(SCENE_GAME);
							map_player.nextflag = false;
						}
					}

					//6段目
					//16→17、16→17
					if (map_player.nowpos == 16)
					{
						map_player.circlenowpos = map_player.LRcount + 16;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 16].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 16].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 16].pos.x, map[map_player.LRcount + 16].pos.y);
							map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
							map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
							if (map_player.LRcount == 0)
								map_player.nowpos = 17;
							if (map_player.LRcount == 1)
								map_player.nowpos = 18;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//5段目
					//14→16、15→16
					if (map_player.nowpos == 14 || map_player.nowpos == 15)
					{
						map_player.circlenowpos = 15;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
							map_player.nowpos = 16;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//4段目
					//11→14、12→14
					if (map_player.nowpos == 11 || map_player.nowpos == 12)
					{
						map_player.circlenowpos = 13;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
							map_player.nowpos = 14;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//13→15
					if (map_player.nowpos == 13)
					{
						map_player.circlenowpos = 14;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
							map_player.nowpos = 15;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//3段目
					//8→11、8→12
					if (map_player.nowpos == 8)
					{
						map_player.circlenowpos = map_player.LRcount + 10;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 10].pos.x, map[map_player.LRcount + 10].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
								map_player.nowpos = 11;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
								map_player.nowpos = 12;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//9→12、8→13
					if (map_player.nowpos == 9)
					{
						map_player.circlenowpos = map_player.LRcount + 11;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 11].pos.x, map[map_player.LRcount + 11].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
								map_player.nowpos = 12;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
								map_player.nowpos = 13;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//10→13
					if (map_player.nowpos == 10)
					{
						map_player.circlenowpos = 12;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
							map_player.nowpos = 13;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//2段目
					//5→8
					if (map_player.nowpos == 5)
					{
						map_player.circlenowpos = 7;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
							map_player.nowpos = 8;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//6→9
					if (map_player.nowpos == 6)
					{
						map_player.circlenowpos = 8;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[11].pos.x, map[11].pos.y);
							map_player.nowpos = 9;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//7→10
					if (map_player.nowpos == 7)
					{
						map_player.circlenowpos = 9;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
							map_player.nowpos = 10;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//1段目
					//1→5
					if (map_player.nowpos == 1 || map_player.nowpos == 2)
					{
						map_player.circlenowpos = 4;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
							map_player.nowpos = 5;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//3→6、3→7
					if (map_player.nowpos == 3)
					{
						map_player.circlenowpos = map_player.LRcount + 5;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 5].pos.x, map[map_player.LRcount + 5].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
								map_player.nowpos = 6;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
								map_player.nowpos = 7;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//4→7
					if (map_player.nowpos == 4)
					{
						map_player.circlenowpos = 6;
						if(IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
							map_player.nowpos = 7;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}


					//0段目
					if (map_player.nowpos == 0)
					{
						map_player.circlenowpos = map_player.LRcount;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 3)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount].pos.x, map[map_player.LRcount].pos.y);
							map_player.nowpos = map_player.LRcount + 1;
							if (map_player.nowpos == 1)
								map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
							if (map_player.nowpos == 2)
								map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
							if (map_player.nowpos == 3)
								map_player.circlepos = D3DXVECTOR2(map[5].pos.x, map[5].pos.y);
							if (map_player.nowpos == 4)
								map_player.circlepos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
				}

				//-----シート4の場合
				if (map_line->randomcode == 4)
				{
					//7段目
					//→boss
					if (map_player.nowpos == 22 || map_player.nowpos == 23 || map_player.nowpos == 24)
					{
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
							map_player.nowpos = 25;
							map_player.encount = 3;
							SceneTransition(SCENE_GAME);
							map_player.nextflag = false;
						}
					}

					//6段目
					//18→22
					if (map_player.nowpos == 18)
					{
						map_player.circlenowpos = 21;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[21].pos.x, map[21].pos.y);
							map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
							map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
							map_player.nowpos = 22;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//19→23
					if (map_player.nowpos == 19)
					{
						map_player.circlenowpos = 22;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[22].pos.x, map[22].pos.y);
							map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
							map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
							map_player.nowpos = 23;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//20→23、20→24
					if (map_player.nowpos == 20)
					{
						map_player.circlenowpos = map_player.LRcount + 22;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 22].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 22].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 22].pos.x, map[map_player.LRcount + 22].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
								map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
								map_player.nowpos = 23;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
								map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
								map_player.nowpos = 24;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//21→24
					if (map_player.nowpos == 21)
					{
						map_player.circlenowpos = 23;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[23].pos.x, map[23].pos.y);
							map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
							map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
							map_player.nowpos = 24;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//5段目
					//15→18、15→19
					if (map_player.nowpos == 15)
					{
						map_player.circlenowpos = map_player.LRcount + 17;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 17].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 17].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 17].pos.x, map[map_player.LRcount + 17].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[21].pos.x, map[21].pos.y);
								map_player.nowpos = 18;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[22].pos.x, map[22].pos.y);
								map_player.nowpos = 19;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//16→19、16→20
					if (map_player.nowpos == 16)
					{
						map_player.circlenowpos = map_player.LRcount + 18;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 18].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 18].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 18].pos.x, map[map_player.LRcount + 18].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[22].pos.x, map[22].pos.y);
								map_player.nowpos = 19;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[22].pos.x, map[22].pos.y);
								map_player.nowpos = 20;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//17→20、17→21
					if (map_player.nowpos == 17)
					{
						map_player.circlenowpos = map_player.LRcount + 19;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 19].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 19].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 19].pos.x, map[map_player.LRcount + 19].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[22].pos.x, map[22].pos.y);
								map_player.nowpos = 20;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[23].pos.x, map[23].pos.y);
								map_player.nowpos = 21;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//4段目
					//11→15
					if (map_player.nowpos == 11)
					{
						map_player.circlenowpos = 14;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
							map_player.nowpos = 15;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//12→16
					if (map_player.nowpos == 12)
					{
						map_player.circlenowpos = 15;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
							map_player.nowpos = 16;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//13→16、13→17
					if (map_player.nowpos == 13)
					{
						map_player.circlenowpos = map_player.LRcount + 15;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 15].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 15].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 15].pos.x, map[map_player.LRcount + 15].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
								map_player.nowpos = 16;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[19].pos.x, map[19].pos.y);
								map_player.nowpos = 17;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//14→17
					if (map_player.nowpos == 14)
					{
						map_player.circlenowpos = 16;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[19].pos.x, map[19].pos.y);
							map_player.nowpos = 17;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//3段目
						//8→11、8→12
					if (map_player.nowpos == 8)
					{
						map_player.circlenowpos = map_player.LRcount + 10;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 10].pos.x, map[map_player.LRcount + 10].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
								map_player.nowpos = 11;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
								map_player.nowpos = 12;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//9→13
					if (map_player.nowpos == 9)
					{
						map_player.circlenowpos = 12;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
							map_player.nowpos = 13;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//10→13、10→14
					if (map_player.nowpos == 10)
					{
						map_player.circlenowpos = map_player.LRcount + 12;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 12].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 12].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 12].pos.x, map[map_player.LRcount + 12].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
								map_player.nowpos = 13;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
								map_player.nowpos = 14;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//2段目
					//5→8
					if (map_player.nowpos == 5)
					{
						map_player.circlenowpos = 7;

						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
							map_player.nowpos = 8;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//6→8、6→9
					if (map_player.nowpos == 6)
					{
						map_player.circlenowpos = map_player.LRcount + 7;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 7].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 7].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 7].pos.x, map[map_player.LRcount + 7].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
								map_player.nowpos = 8;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
								map_player.nowpos = 9;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//7→9、7→10
					if (map_player.nowpos == 7)
					{
						map_player.circlenowpos = map_player.LRcount + 8;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 8].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 8].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 8].pos.x, map[map_player.LRcount + 8].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
								map_player.nowpos = 9;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
								map_player.nowpos = 10;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//1段目
					//1→5
					if (map_player.nowpos == 1)
					{
						map_player.circlenowpos = 4;
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
							map_player.nowpos = 5;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//2→5、2→6
					if (map_player.nowpos == 2)
					{
						map_player.circlenowpos = map_player.LRcount + 4;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 4].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 4].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 4].pos.x, map[map_player.LRcount + 4].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
								map_player.nowpos = 5;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
								map_player.nowpos = 6;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//3→6、3→7
					if (map_player.nowpos == 3)
					{
						map_player.circlenowpos = map_player.LRcount + 5;
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 1)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 5].pos.x, map[map_player.LRcount + 5].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
								map_player.nowpos = 6;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
								map_player.nowpos = 7;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//4→7
					if (map_player.nowpos == 4)
					{
						map_player.circlenowpos = 6;

						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
							map_player.nowpos = 7;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//0段目
					if (map_player.nowpos == 0)
					{
						if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0)	//左
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount].pos.x;
							map_player.circlenowpos = map_player.LRcount;
						}
						if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.LRcount < 3)	//右
						{
							PlaySound(map_player.sound, 0.5f);
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount].pos.x;
							map_player.circlenowpos = map_player.LRcount;
						}
						if (IsButtonTriggered(0, BUTTON_Y))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount].pos.x, map[map_player.LRcount].pos.y);
							map_player.nowpos = map_player.LRcount + 1;
							if (map_player.nowpos == 1)
								map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
							if (map_player.nowpos == 2)
								map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
							if (map_player.nowpos == 3)
								map_player.circlepos = D3DXVECTOR2(map[5].pos.x, map[5].pos.y);
							if (map_player.nowpos == 4)
								map_player.circlepos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
				}
			}
		}

		if (PADUSE == 1)
		{
			if (GetKeyboardPress(DIK_W) && map_bg->pos.y < 60)	//上
			{
				map_player.pos.y += 5;
				map_player.circlepos.y += 5;
			}
			if (GetKeyboardPress(DIK_S) && map_bg->pos.y > -580)	//下
			{
				map_player.pos.y -= 5;
				map_player.circlepos.y -= 5;
			}

			if(map_player.nextflag == true)
			{
			//-----シート1の場合
			if (map_line->randomcode == 1)
			{
				//7段目
				//18→boss
				if (map_player.nowpos == 19 || map_player.nowpos == 20 || map_player.nowpos == 21)
				{
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.nowpos = 22;
						map_player.encount = 3;
						SceneTransition(SCENE_GAME);
						map_player.nextflag = false;
					}
				}

				//6段目
				//15→18
				if (map_player.nowpos == 16)
				{
					map_player.circlenowpos = 18;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						map_player.nowpos = 19;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//16→19
				if (map_player.nowpos == 17)
				{
					map_player.circlenowpos = 19;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[19].pos.x, map[19].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						map_player.nowpos = 19;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//17→20
				if (map_player.nowpos == 18)
				{
					map_player.circlenowpos = 20;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[20].pos.x, map[20].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						map_player.nowpos = 21;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//5段目
				//10→15
				if (map_player.nowpos == 11)
				{
					map_player.circlenowpos = 15;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
						map_player.nowpos = 16;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//13→16、13→17
				if (map_player.nowpos == 14)
				{
					map_player.circlenowpos = map_player.LRcount + 16;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 16].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 16].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 16].pos.x, map[map_player.LRcount + 16].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[19].pos.x, map[19].pos.y);
							map_player.nowpos = 17;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[20].pos.x, map[20].pos.y);
							map_player.nowpos = 18;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//14→17
				if (map_player.nowpos == 15)
				{
					map_player.circlenowpos = 17;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[20].pos.x, map[20].pos.y);
						map_player.nowpos = 18;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//-----4段目
				//12→14、12→15
				if (map_player.nowpos == 12)
				{
					map_player.circlenowpos = map_player.LRcount + 13;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 13].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 13].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 13].pos.x, map[map_player.LRcount + 13].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
							map_player.nowpos = 14;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
							map_player.nowpos = 15;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//13→15
				if (map_player.nowpos == 13)
				{
					map_player.circlenowpos = 14;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
						map_player.nowpos = 15;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//-----3段目
				//7→10
				if (map_player.nowpos == 8)
				{
					map_player.circlenowpos = 10;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
						map_player.nowpos = 11;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//8→10、8→11
				if (map_player.nowpos == 9)
				{
					map_player.circlenowpos = map_player.LRcount + 10;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 10].pos.x, map[map_player.LRcount + 10].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
							map_player.nowpos = 11;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
							map_player.nowpos = 12;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//10→12、10→13
				if (map_player.nowpos == 10)
				{
					map_player.circlenowpos = map_player.LRcount + 11;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 11].pos.x, map[map_player.LRcount + 11].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
							map_player.nowpos = 12;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
							map_player.nowpos = 13;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//-----2段目
				//5→8
				if (map_player.nowpos == 5)
				{
					map_player.circlenowpos = 7;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
						map_player.nowpos = 8;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//6→9
				if (map_player.nowpos == 6)
				{
					map_player.circlenowpos = 8;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
						map_player.nowpos = 9;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//7→10
				if (map_player.nowpos == 7)
				{
					map_player.circlenowpos = 9;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[11].pos.x, map[11].pos.y);
						map_player.nowpos = 10;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//-----1段目
				//0→5、1→5
				if (map_player.nowpos == 1 || map_player.nowpos == 2)
				{
					map_player.circlenowpos = 4;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
						map_player.nowpos = 5;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				if (map_player.nowpos == 3)
				{
					map_player.circlenowpos = map_player.LRcount + 5;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 5].pos.x, map[map_player.LRcount + 5].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
							map_player.nowpos = 6;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
							map_player.nowpos = 7;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//4→7
				if (map_player.nowpos == 4)
				{
					map_player.circlenowpos = 6;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
						map_player.nowpos = 7;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//-----0段目
				if (map_player.nowpos == 0)
				{
					map_player.circlenowpos = map_player.LRcount;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 3)	//右
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount].pos.x, map[map_player.LRcount].pos.y);
						map_player.nowpos = map_player.LRcount + 1;
						if (map_player.nowpos == 1 || map_player.nowpos == 2)
							map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
						if (map_player.nowpos == 3)
							map_player.circlepos = D3DXVECTOR2(map[5].pos.x, map[5].pos.y);
						if (map_player.nowpos == 4)
							map_player.circlepos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
			}

			//-----シート2の場合
			if (map_line->randomcode == 2)
			{
				//7段目
				//18→boss
				if (map_player.nowpos == 18 || map_player.nowpos == 19 || map_player.nowpos == 20)
				{
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.nowpos = 21;
						map_player.encount = 3;
						SceneTransition(SCENE_GAME);
						map_player.nextflag = false;
					}
				}

				//6段目
				//16→18
				if (map_player.nowpos == 16)
				{
					map_player.circlenowpos = 17;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						map_player.nowpos = 18;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//17→19、17→20
				if (map_player.nowpos == 17)
				{
					map_player.circlenowpos = map_player.LRcount + 18;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 18].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 18].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 18].pos.x, map[map_player.LRcount + 18].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						if (map_player.LRcount == 0)
							map_player.nowpos = 19;
						if (map_player.LRcount == 1)
							map_player.nowpos = 20;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//5段目
				//10→16
				if (map_player.nowpos == 10)
				{
					map_player.circlenowpos = 15;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
						map_player.nowpos = 16;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//14→17
				if (map_player.nowpos == 14)
				{
					map_player.circlenowpos = 16;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
						map_player.nowpos = 17;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//15→17
				if (map_player.nowpos == 15)
				{
					map_player.circlenowpos = 16;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
						map_player.nowpos = 17;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//4段目
				//11→14
				if (map_player.nowpos == 11)
				{
					map_player.circlenowpos = 13;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
						map_player.nowpos = 14;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//12→14、12→15
				if (map_player.nowpos == 12)
				{
					map_player.circlenowpos = map_player.LRcount + 13;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 13].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 13].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 13].pos.x, map[map_player.LRcount + 13].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
							map_player.nowpos = 14;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
							map_player.nowpos = 15;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//13→15
				if (map_player.nowpos == 13)
				{
					map_player.circlenowpos = 14;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
						map_player.nowpos = 15;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//3段目
				//７→10、7→11
				if (map_player.nowpos == 7)
				{
					map_player.circlenowpos = map_player.LRcount + 9;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 9].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 9].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 9].pos.x, map[map_player.LRcount + 9].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
							map_player.nowpos = 10;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
							map_player.nowpos = 11;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//8→12
				if (map_player.nowpos == 8)
				{
					map_player.circlenowpos = 11;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[11].pos.x, map[11].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
						map_player.nowpos = 12;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//9→12、9→13
				if (map_player.nowpos == 9)
				{
					map_player.circlenowpos = map_player.LRcount + 11;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 11].pos.x, map[map_player.LRcount + 11].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
							map_player.nowpos = 12;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
							map_player.nowpos = 13;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//2段目
				//４→7
				if (map_player.nowpos == 4)
				{
					map_player.circlenowpos = 6;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
						map_player.nowpos = 7;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//5→8
				if (map_player.nowpos == 5)
				{
					map_player.circlenowpos = 7;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[11].pos.x, map[11].pos.y);
						map_player.nowpos = 8;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//6→9
				if (map_player.nowpos == 6)
				{
					map_player.circlenowpos = 8;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[11].pos.x, map[11].pos.y);
						map_player.nowpos = 9;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//1段目
				//1→4
				if (map_player.nowpos == 1)
				{
					map_player.circlenowpos = 3;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[3].pos.x, map[3].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
						map_player.nowpos = 4;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//2→5、2→6
				if (map_player.nowpos == 2)
				{
					map_player.circlenowpos = map_player.LRcount + 4;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 4].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 4].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 4].pos.x, map[map_player.LRcount + 4].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
							map_player.nowpos = 5;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
							map_player.nowpos = 6;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//3→6
				if (map_player.nowpos == 3)
				{
					map_player.circlenowpos = 5;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[5].pos.x, map[5].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
						map_player.nowpos = 6;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//0段目
				if (map_player.nowpos == 0)
				{
					map_player.circlenowpos = map_player.LRcount;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 2)	//右
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount].pos.x, map[map_player.LRcount].pos.y);
						map_player.nowpos = map_player.LRcount + 1;
						if (map_player.nowpos == 1)
							map_player.circlepos = D3DXVECTOR2(map[3].pos.x, map[3].pos.y);
						if (map_player.nowpos == 2)
							map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
						if (map_player.nowpos == 3)
							map_player.circlepos = D3DXVECTOR2(map[5].pos.x, map[5].pos.y);
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
			}

			//-----シート3の場合
			if (map_line->randomcode == 3)
			{
				//7段目
				//→boss
				if (map_player.nowpos == 17 || map_player.nowpos == 18)
				{
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.nowpos = 19;
						map_player.encount = 3;
						SceneTransition(SCENE_GAME);
						map_player.nextflag = false;
					}
				}

				//6段目
				//16→17、16→17
				if (map_player.nowpos == 16)
				{
					map_player.circlenowpos = map_player.LRcount + 16;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 16].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 16].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 16].pos.x, map[map_player.LRcount + 16].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						if (map_player.LRcount == 0)
							map_player.nowpos = 17;
						if (map_player.LRcount == 1)
							map_player.nowpos = 18;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//5段目
				//14→16、15→16
				if (map_player.nowpos == 14 || map_player.nowpos == 15)
				{
					map_player.circlenowpos = 15;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
						map_player.nowpos = 16;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//4段目
				//11→14、12→14
				if (map_player.nowpos == 11 || map_player.nowpos == 12)
				{
					map_player.circlenowpos = 13;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
						map_player.nowpos = 14;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//13→15
				if (map_player.nowpos == 13)
				{
					map_player.circlenowpos = 14;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
						map_player.nowpos = 15;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//3段目
				//8→11、8→12
				if (map_player.nowpos == 8)
				{
					map_player.circlenowpos = map_player.LRcount + 10;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 10].pos.x, map[map_player.LRcount + 10].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
							map_player.nowpos = 11;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
							map_player.nowpos = 12;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//9→12、8→13
				if (map_player.nowpos == 9)
				{
					map_player.circlenowpos = map_player.LRcount + 11;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 11].pos.x, map[map_player.LRcount + 11].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
							map_player.nowpos = 12;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
							map_player.nowpos = 13;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//10→13
				if (map_player.nowpos == 10)
				{
					map_player.circlenowpos = 12;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
						map_player.nowpos = 13;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//2段目
				//5→8
				if (map_player.nowpos == 5)
				{
					map_player.circlenowpos = 7;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
						map_player.nowpos = 8;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//6→9
				if (map_player.nowpos == 6)
				{
					map_player.circlenowpos = 8;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[11].pos.x, map[11].pos.y);
						map_player.nowpos = 9;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//7→10
				if (map_player.nowpos == 7)
				{
					map_player.circlenowpos = 9;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
						map_player.nowpos = 10;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//1段目
				//1→5
				if (map_player.nowpos == 1 || map_player.nowpos == 2)
				{
					map_player.circlenowpos = 4;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
						map_player.nowpos = 5;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//3→6、3→7
				if (map_player.nowpos == 3)
				{
					map_player.circlenowpos = map_player.LRcount + 5;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 5].pos.x, map[map_player.LRcount + 5].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
							map_player.nowpos = 6;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
							map_player.nowpos = 7;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//4→7
				if (map_player.nowpos == 4)
				{
					map_player.circlenowpos = 6;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
						map_player.circlepos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
						map_player.nowpos = 7;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}


				//0段目
				if (map_player.nowpos == 0)
				{
					map_player.circlenowpos = map_player.LRcount;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 3)	//右
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount].pos.x, map[map_player.LRcount].pos.y);
						map_player.nowpos = map_player.LRcount + 1;
						if (map_player.nowpos == 1)
							map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
						if (map_player.nowpos == 2)
							map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
						if (map_player.nowpos == 3)
							map_player.circlepos = D3DXVECTOR2(map[5].pos.x, map[5].pos.y);
						if (map_player.nowpos == 4)
							map_player.circlepos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
			}

			//-----シート4の場合
			if (map_line->randomcode == 4)
			{
				//7段目
				//→boss
				if (map_player.nowpos == 22 || map_player.nowpos == 23 || map_player.nowpos == 24)
				{
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.nowpos = 25;
						map_player.encount = 3;
						SceneTransition(SCENE_GAME);
						map_player.nextflag = false;
					}
				}

				//6段目
				//18→22
				if (map_player.nowpos == 18)
				{
					map_player.circlenowpos = 21;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[21].pos.x, map[21].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						map_player.nowpos = 22;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//19→23
				if (map_player.nowpos == 19)
				{
					map_player.circlenowpos = 22;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[22].pos.x, map[22].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						map_player.nowpos = 23;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//20→23、20→24
				if (map_player.nowpos == 20)
				{
					map_player.circlenowpos = map_player.LRcount + 22;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 22].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 22].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 22].pos.x, map[map_player.LRcount + 22].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
							map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
							map_player.nowpos = 23;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
							map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
							map_player.nowpos = 24;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//21→24
				if (map_player.nowpos == 21)
				{
					map_player.circlenowpos = 23;
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[23].pos.x, map[23].pos.y);
						map_player.circlepos = D3DXVECTOR2(map_sb->bosspos.x, map_sb->bosspos.y);
						map_player.circlesize = D3DXVECTOR2(map_sb->bosssize.x, map_sb->bosssize.y);
						map_player.nowpos = 24;
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}

				//5段目
				//15→18、15→19
				if (map_player.nowpos == 15)
				{
					map_player.circlenowpos = map_player.LRcount + 17;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 17].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 17].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 17].pos.x, map[map_player.LRcount + 17].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[21].pos.x, map[21].pos.y);
							map_player.nowpos = 18;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[22].pos.x, map[22].pos.y);
							map_player.nowpos = 19;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
					}
				}
				//16→19、16→20
				if (map_player.nowpos == 16)
				{
					map_player.circlenowpos = map_player.LRcount + 18;
					if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
					{
						map_player.LRcount = map_player.LRcount - 1;
						map_player.circlepos.x = map[map_player.LRcount + 18].pos.x;
					}
					if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
					{
						map_player.LRcount = map_player.LRcount + 1;
						map_player.circlepos.x = map[map_player.LRcount + 18].pos.x;
					}
					if (GetKeyboardTrigger(DIK_RETURN))
					{
						map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 18].pos.x, map[map_player.LRcount + 18].pos.y);
						if (map_player.LRcount == 0)
						{
							map_player.circlepos = D3DXVECTOR2(map[22].pos.x, map[22].pos.y);
							map_player.nowpos = 19;
						}
						if (map_player.LRcount == 1)
						{
							map_player.circlepos = D3DXVECTOR2(map[22].pos.x, map[22].pos.y);
							map_player.nowpos = 20;
						}
						map_player.LRcount = 0;
						map_player.UDcount = map_player.UDcount + 1;
						map_player.nextflag = false;
						}
					}
					//17→20、17→21
					if (map_player.nowpos == 17)
					{
						map_player.circlenowpos = map_player.LRcount + 19;
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 19].pos.x;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 19].pos.x;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 19].pos.x, map[map_player.LRcount + 19].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[22].pos.x, map[22].pos.y);
								map_player.nowpos = 20;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[23].pos.x, map[23].pos.y);
								map_player.nowpos = 21;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//4段目
					//11→15
					if (map_player.nowpos == 11)
					{
						map_player.circlenowpos = 14;
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
							map_player.nowpos = 15;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//12→16
					if (map_player.nowpos == 12)
					{
						map_player.circlenowpos = 15;
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
							map_player.nowpos = 16;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//13→16、13→17
					if (map_player.nowpos == 13)
					{
						map_player.circlenowpos = map_player.LRcount + 15;
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 15].pos.x;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 15].pos.x;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 15].pos.x, map[map_player.LRcount + 15].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[18].pos.x, map[18].pos.y);
								map_player.nowpos = 16;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[19].pos.x, map[19].pos.y);
								map_player.nowpos = 17;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//14→17
					if (map_player.nowpos == 14)
					{
						map_player.circlenowpos = 16;
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[19].pos.x, map[19].pos.y);
							map_player.nowpos = 17;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

				//3段目
					//8→11、8→12
					if (map_player.nowpos == 8)
					{
						map_player.circlenowpos = map_player.LRcount + 10;
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 10].pos.x, map[map_player.LRcount + 10].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
								map_player.nowpos = 11;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
								map_player.nowpos = 12;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//9→13
					if (map_player.nowpos == 9)
					{
						map_player.circlenowpos = 12;
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
							map_player.nowpos = 13;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//10→13、10→14
					if (map_player.nowpos == 10)
					{
						map_player.circlenowpos = map_player.LRcount + 12;
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 12].pos.x;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 12].pos.x;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 12].pos.x, map[map_player.LRcount + 12].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
								map_player.nowpos = 13;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
								map_player.nowpos = 14;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//2段目
					//5→8
					if (map_player.nowpos == 5)
					{
						map_player.circlenowpos = 7;

						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
							map_player.nowpos = 8;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//6→8、6→9
					if (map_player.nowpos == 6)
					{
						map_player.circlenowpos = map_player.LRcount + 7;
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 7].pos.x;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 7].pos.x;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 7].pos.x, map[map_player.LRcount + 7].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
								map_player.nowpos = 8;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
								map_player.nowpos = 9;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//7→9、7→10
					if (map_player.nowpos == 7)
					{
						map_player.circlenowpos = map_player.LRcount + 8;
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 8].pos.x;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 8].pos.x;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 8].pos.x, map[map_player.LRcount + 8].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
								map_player.nowpos = 9;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[12].pos.x, map[12].pos.y);
								map_player.nowpos = 10;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//1段目
					//1→5
					if (map_player.nowpos == 1)
					{
						map_player.circlenowpos = 4;
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
							map_player.nowpos = 5;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//2→5、2→6
					if (map_player.nowpos == 2)
					{
						map_player.circlenowpos = map_player.LRcount + 4;
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 4].pos.x;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 4].pos.x;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 4].pos.x, map[map_player.LRcount + 4].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
								map_player.nowpos = 5;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
								map_player.nowpos = 6;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//3→6、3→7
					if (map_player.nowpos == 3)
					{
						map_player.circlenowpos = map_player.LRcount + 5;
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 1)	//右
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 5].pos.x, map[map_player.LRcount + 5].pos.y);
							if (map_player.LRcount == 0)
							{
								map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
								map_player.nowpos = 6;
							}
							if (map_player.LRcount == 1)
							{
								map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
								map_player.nowpos = 7;
							}
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
					//4→7
					if (map_player.nowpos == 4)
					{
						map_player.circlenowpos = 6;

						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
							map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
							map_player.nowpos = 7;
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}

					//0段目
					if (map_player.nowpos == 0)
					{
						if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)	//左
						{
							map_player.LRcount = map_player.LRcount - 1;
							map_player.circlepos.x = map[map_player.LRcount].pos.x;
							map_player.circlenowpos = map_player.LRcount;
						}
						if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 3)	//右
						{
							map_player.LRcount = map_player.LRcount + 1;
							map_player.circlepos.x = map[map_player.LRcount].pos.x;
							map_player.circlenowpos = map_player.LRcount;
						}
						if (GetKeyboardTrigger(DIK_RETURN))
						{
							map_player.pos = D3DXVECTOR2(map[map_player.LRcount].pos.x, map[map_player.LRcount].pos.y);
							map_player.nowpos = map_player.LRcount + 1;
							if (map_player.nowpos == 1)
								map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
							if (map_player.nowpos == 2)
								map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
							if (map_player.nowpos == 3)
								map_player.circlepos = D3DXVECTOR2(map[5].pos.x, map[5].pos.y);
							if (map_player.nowpos == 4)
								map_player.circlepos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
							map_player.LRcount = 0;
							map_player.UDcount = map_player.UDcount + 1;
							map_player.nextflag = false;
						}
					}
				}
			}
		}

		//選択したマスに対応したシーンに飛ぶ
		if (map_player.nowpos < map_player.mapnum + 1)
		{
			if (PADUSE == 0)
			{
				if (IsButtonTriggered(0, BUTTON_Y) && hackeffect->drawflag == false)
				{
					if (map[map_player.nowpos - 1].randomcode == 1)	//通常敵マス
					{
						map_player.gamecount = map_player.gamecount + 1;	//ゲームシーンに入った回数を記録する
						map_player.encount = (rand() % 2) + 1;	//ここで出現する敵をランダムに決める
						if (tutorial->tutorialflag == false)
							map_player.encount = 1;	//ここで出現する敵をランダムに決める
						map_player.encount = 2;	//ここで出現する敵をランダムに決める
						map_player.enemypowerup = false;
						SceneTransition(SCENE_GAME);
					}
					if (map[map_player.nowpos - 1].randomcode == 2)	//強敵マス
					{
						map_player.gamecount = map_player.gamecount + 1;	//ゲームシーンに入った回数を記録する
						map_player.encount = (rand() % 2) + 1;	//ここで出現する敵をランダムに決める
						map_player.enemypowerup = true;
						SceneTransition(SCENE_GAME);
					}
					if (map[map_player.nowpos - 1].randomcode == 3)	//休憩マス
						SceneTransition(SCENE_REST);
					if (map[map_player.nowpos - 1].randomcode == 4)	//イベントマス
					{
						map_player.eventcode = (rand() % 9) + 1;	//ここでイベントをランダムに決める
						map_player.eventcode = 7;	//ここでイベントをランダムに決める
						SceneTransition(SCENE_EVENT);
					}
					if (map[map_player.nowpos - 1].randomcode == 5)	//商人マス
						SceneTransition(SCENE_SHOP);
				}
			}
			if (PADUSE == 1)
			{
				if (GetKeyboardTrigger(DIK_RETURN) && hackeffect->drawflag == false)
				{
					if (map[map_player.nowpos - 1].randomcode == 1)	//通常敵マス
					{
						map_player.gamecount = map_player.gamecount + 1;	//ゲームシーンに入った回数を記録する
						map_player.encount = (rand() % 2) + 1;	//ここで出現する敵をランダムに決める
						if(tutorial->tutorialflag == false)
							map_player.encount = 1;	//ここで出現する敵をランダムに決める
						map_player.enemypowerup = false;
						SceneTransition(SCENE_GAME);
					}
					if (map[map_player.nowpos - 1].randomcode == 2)	//強敵マス
					{
						map_player.encount = (rand() % 2) + 1;	//ここで出現する敵をランダムに決める
						map_player.enemypowerup = true;
						SceneTransition(SCENE_GAME);
					}
					if (map[map_player.nowpos - 1].randomcode == 3)	//休憩マス
						SceneTransition(SCENE_REST);
					if (map[map_player.nowpos - 1].randomcode == 4)	//イベントマス
					{
						map_player.eventcode = (rand() % 9) + 1;	//ここでイベントをランダムに決める
						SceneTransition(SCENE_EVENT);
					}
					if (map[map_player.nowpos - 1].randomcode == 5)	//商人マス
						SceneTransition(SCENE_SHOP);
				}
			}
		}	
	}

}

//-----描画処理
void DrawMapPlayer(void)
{
	//枠の描画
	DrawSpriteLeftTop(map_player.circletexture, map_player.circlepos.x, map_player.circlepos.y, map_player.circlesize.x, map_player.circlesize.y,
		0.0f, 0.0f, 1.0f, 1.0f);
	//プレイヤーの描画
	DrawSpriteLeftTop(map_player.texture, map_player.pos.x, map_player.pos.y, map_player.size.x, map_player.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);
}

MAP_PLAYER* GetMapPlayer()
{
	return &map_player;
}