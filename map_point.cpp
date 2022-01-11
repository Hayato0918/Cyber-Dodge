//マップマス/マッププレイヤー/マップライン処理 [map_point.cpp]
#include <stdlib.h>
#include <time.h>

#include "map_point.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "map_hack.h"

//-----マクロ定義
#define map_xnum 4
#define map_ynum 7

//-----プロトタイプ宣言
MAP map[map_ynum][map_xnum];
MAP_PLAYER map_player;
MAP_SB map_sb;

//-----グローバル変数
int map_texture;	//マスのテクスチャを設定する変数

float map_x;	//マスのx座標をランダムにするための変数
float map_y;	//マスのy座標をランダムにするための変数
int mapcount;

//-----初期化処理
HRESULT InitMapPoint(void)
{
	if (map_player.UDcount == 0)	//最初の一回だけ読み込む
	{
		map_y = 300;	//
		//マスのx座標をランダムにする
		map_x = ((rand() % 2) + 2) * 0.1f;
		mapcount = 0;

		map_texture = LoadTexture("data/TEXTURE/map/map_point.png");

		srand((unsigned int)time(NULL));

		for (int y = 0; y < map_ynum; y++)
		{
			for (int x = 0; x < map_xnum; x++)
			{
				map[y][x].size = D3DXVECTOR2(80.0f, 80.0f);
				map[y][x].uw = 0.166f;
				map[y][x].v = 0.0f;
				map[y][x].vh = 1.0f;

				//マスの色をランダムにする
				map[y][x].randomcode = (rand() % 5) + 1;

				for (int i = 0; i < map_xnum; i++)
				{
					map[0][i].randomcode = 1;					//1段目は全部通常敵マスにする
					map[map_ynum-1][i].randomcode = (rand() % 3) + 3;	//ボスマスの手前を戦闘マス以外にする
				}

				switch (map[y][x].randomcode)	//randomcodeの値に応じて色を決める
				{
				case 1:		//オレンジ(通常敵マス)
					map[y][x].u = 0.0f;
					break;
				case 2:		//赤(強敵マス)
					map[y][x].u = 0.166f;
					break;
				case 3:		//緑(休憩マス)
					map[y][x].u = 0.498f;
					break;
				case 4:		//青(イベントマス)
					map[y][x].u = 0.664f;
					break;
				case 5:		//黄色(商人マス)
					map[y][x].u = 0.83f;
					break;
				}
			}
		}

		for (int y = 0; y < map_ynum; y++)
		{
			for (int x = 0; x < map_xnum; x++)
			{
				map[y][x].pos = D3DXVECTOR2(SCREEN_WIDTH * map_x - map[y][x].size.x, map_y);	//map_x…ランダム、map_y…200ずつ増加
				map_x = map_x + ((rand() % 2) + 1) * 0.1f;
				mapcount = mapcount + 1;	//マスを何個置いたかを記録する
				//「aの値が◯だったら、▽のイベントを多く出す」とかもできる
				if (mapcount >= 2 && mapcount < 4)	//マスを2個以上置いたら、改行するかの判断をする
				{
					map[y][x].newline = (rand() % 2);	//newlineに0,1のどちらかを入れる
					if (map[y][x].newline == 1)	//1だったら改行する
					{
						x = x + 2;	//for文の最後まで値を増やし、for文を抜ける
						map_y = map_y + 200;
						map_x = ((rand() % 2) + 2) * 0.1f;
						mapcount = 0;
					}
				}
				if (mapcount >= 4)	//マスが4つ置かれたら、改行する
				{
					x = x + 1;
					map_y = map_y + 200;
					map_x = ((rand() % 2) + 2) * 0.1f;
					mapcount = 0;
				}

				if (map_y >= 1700)	//ボスマスのy座標までたどり着いたら、それ以降のマスを消す
					map_y = 0;	//置かれたマスが用意した分以下だった場合、余った分を一定の座標に配置し、描画部分で消す
			}
		}

		//スタートマス
		map_sb.startsize = D3DXVECTOR2(80, 80);
		map_sb.startpos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f - map_sb.startsize.x, 100);
		//ボスマス
		map_sb.bosssize = D3DXVECTOR2(120, 120);
		map_sb.bosspos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f - map_sb.bosssize.x, 1700);
	}

	return S_OK;
}

//-----終了処理
void UninitMapPoint(void)
{

}

//-----更新処理
void UpdateMapPoint(void)
{
	MAP_HACK* map_hack = GetMapHack();

	//マスをハッキングして、任意のマスに変える
	if (map_hack->isUse == true)
	{
		if (PADUSE == 0)
		{
			if (IsButtonTriggered(0, BUTTON_X))
			{
				if (map_hack->UDcount == 0)		//通常敵マス
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 1;
					map[map_player.UDcount][map_player.LRcount].u = 0.0f;
				}
				if (map_hack->UDcount == 1)		//強敵マス
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 2;
					map[map_player.UDcount][map_player.LRcount].u = 0.166f;
				}
				if (map_hack->UDcount == 2)		//休憩マス
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 3;
					map[map_player.UDcount][map_player.LRcount].u = 0.498f;
				}
				if (map_hack->UDcount == 3)		//イベントマス
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 4;
					map[map_player.UDcount][map_player.LRcount].u = 0.664f;
				}
				if (map_hack->UDcount == 4)		//商人マス
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 5;
					map[map_player.UDcount][map_player.LRcount].u = 0.83f;
				}
			}
		}
		if (PADUSE == 1)
		{
			if (GetKeyboardTrigger(DIK_RETURN))
			{
				if (map_hack->UDcount == 0)		//通常敵マス
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 1;
					map[map_player.UDcount][map_player.LRcount].u = 0.0f;
				}
				if (map_hack->UDcount == 1)		//強敵マス
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 2;
					map[map_player.UDcount][map_player.LRcount].u = 0.166f;
				}
				if (map_hack->UDcount == 2)		//休憩マス
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 3;
					map[map_player.UDcount][map_player.LRcount].u = 0.498f;
				}
				if (map_hack->UDcount == 3)		//イベントマス
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 4;
					map[map_player.UDcount][map_player.LRcount].u = 0.664f;
				}
				if (map_hack->UDcount == 4)		//商人マス
				{
					map[map_player.UDcount][map_player.LRcount].randomcode = 5;
					map[map_player.UDcount][map_player.LRcount].u = 0.83f;
				}
			}
		}
	}

	//マップスクロール
	if (map_hack->isUse == false)
	{
		if (PADUSE == 0)
		{
			if (IsButtonPressed(0, BUTTON_UP))
			{
				map_sb.startpos.y += 3;
				map_sb.bosspos.y += 3;

				for (int y = 0; y < map_ynum; y++)
				{
					for (int x = 0; x < map_xnum; x++)
						map[y][x].pos.y += 3;
				}
			}
			if (IsButtonPressed(0, BUTTON_DOWN))
			{
				map_sb.startpos.y -= 3;
				map_sb.bosspos.y -= 3;

				for (int y = 0; y < map_ynum; y++)
				{
					for (int x = 0; x < map_xnum; x++)
						map[y][x].pos.y -= 3;
				}
			}
		}
		if (PADUSE == 1)
		{
			if (GetKeyboardPress(DIK_W))
			{
				map_sb.startpos.y += 3;
				map_sb.bosspos.y += 3;

				for (int y = 0; y < map_ynum; y++)
				{
					for (int x = 0; x < map_xnum; x++)
						map[y][x].pos.y += 3;
				}
			}
			if (GetKeyboardPress(DIK_S))
			{
				map_sb.startpos.y -= 3;
				map_sb.bosspos.y -= 3;

				for (int y = 0; y < map_ynum; y++)
				{
					for (int x = 0; x < map_xnum; x++)
						map[y][x].pos.y -= 3;
				}
			}
		}
	}
}

//-----描画処理
void DrawMapPoint(void)
{
	//スタートマスの描画
	DrawSpriteLeftTop(map_texture, map_sb.startpos.x, map_sb.startpos.y, map_sb.startsize.x, map_sb.startsize.y, 0.664f, 0.0f, 0.166f, 1.0f);
	//ボスマスの描画
	DrawSpriteLeftTop(map_texture, map_sb.bosspos.x, map_sb.bosspos.y, map_sb.bosssize.x, map_sb.bosssize.y, 0.332f, 0.0f, 0.166f, 1.0f);

	for (int y = 0; y < map_ynum; y++)
	{
		for (int x = 0; x < map_xnum; x++)
		{
			if(map[y][x].pos.x > 0)		//改行された分、余った分以外を描画する
			DrawSpriteLeftTop(map_texture, map[y][x].pos.x, map[y][x].pos.y, map[y][x].size.x, map[y][x].size.y,
				map[y][x].u, map[y][x].v, map[y][x].uw, map[y][x].vh);
		}
	}
}

//-----------------------------------------------//
//--------------|プレイヤーの設定|--------------//
//---------------------------------------------//

//-----初期化処理
HRESULT InitMapPlayer(void)
{
	if (map_player.UDcount == 0)	//最初の一回だけ読み込む
	{
		//プレイヤーの初期化
		map_player.size = D3DXVECTOR2(80.0f, 80.0f);
		map_player.pos = D3DXVECTOR2(map_sb.startpos.x, map_sb.startpos.y - map_player.size.y * 0.5f);
		map_player.texture = LoadTexture("data/TEXTURE/map_player.png");
		map_player.LRcount = 0;
		map_player.UDcount = 0;

		//選択の枠の初期化
		map_player.circlepos = D3DXVECTOR2(map[0][0].pos.x, map[0][0].pos.y);
		map_player.circlesize = D3DXVECTOR2(80.0f, 80.0f);
		map_player.circletexture = LoadTexture("data/TEXTURE/map/circle.png");

		map_player.gamecount = 0;
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

	//マップスクロール
	if (map_hack->isUse == false)
	{
		if (PADUSE == 0)
		{
			if (IsButtonPressed(0, BUTTON_UP))	//上
			{
				map_player.pos.y += 3;
				map_player.circlepos.y += 3;
			}
			if (IsButtonPressed(0, BUTTON_DOWN))	//下
			{
				map_player.pos.y -= 3;
				map_player.circlepos.y -= 3;
			}
			//1つ左のマスにカーソルを合わせる
			if (IsButtonTriggered(0, BUTTON_LEFT) && map_player.LRcount > 0 && map_player.UDcount < 7)
			{
				map_player.LRcount = map_player.LRcount - 1;
				map_player.circlepos.x = map[map_player.UDcount][map_player.LRcount].pos.x;
			}
			//1つ右のマスにカーソルを合わせる
			if (IsButtonTriggered(0, BUTTON_RIGHT) && map_player.circlepos.x < map[map_player.UDcount][map_player.LRcount + 1].pos.x && map_player.UDcount < 7)
			{
				map_player.LRcount = map_player.LRcount + 1;
				map_player.circlepos.x = map[map_player.UDcount][map_player.LRcount].pos.x;
			}
			//カーソルを合わせたマスにプレイヤーを動かす
			if (IsButtonTriggered(0, BUTTON_X) && map_player.UDcount < 8)
			{
				//選択したマスまでプレイヤーを移動させる
				if (map_player.UDcount < 7)		//ボス前まで
				{
					map_player.pos.x = map[map_player.UDcount][map_player.LRcount].pos.x;
					map_player.pos.y = map_player.pos.y + 200;
				}
				if (map_player.UDcount == 7)	//ボスマス
					map_player.pos = D3DXVECTOR2(map_sb.bosspos.x + map_player.size.x * 0.25f, map_sb.bosspos.y);

				//選択したマスに対応したシーンに飛ぶ
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 1)	//通常敵マス
				{
					map_player.gamecount = map_player.gamecount + 1;
					SceneTransition(SCENE_GAME);
				}
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 2)	//強敵マス
				{
					map_player.gamecount = map_player.gamecount + 1;
					SceneTransition(SCENE_GAME);
				}
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 3)	//休憩マス
					SceneTransition(SCENE_REST);
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 4)	//イベントマス
					SceneTransition(SCENE_EVENT);
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 5)	//商人マス
					SceneTransition(SCENE_SHOP);

				map_player.LRcount = 0;
				map_player.UDcount = map_player.UDcount + 1;

				//次の選択肢までカーソルを移動させる
				if (map_player.UDcount < 7)		//ボス前まで
				{
					map_player.circlepos.x = map[map_player.UDcount][map_player.LRcount].pos.x;
					map_player.circlepos.y = map[map_player.UDcount][map_player.LRcount].pos.y;
				}
				if (map_player.UDcount == 7)	//ボスマス
				{
					map_player.circlepos = D3DXVECTOR2(map_sb.bosspos.x, map_sb.bosspos.y);
					map_player.circlesize = D3DXVECTOR2(map_sb.bosssize.x, map_sb.bosssize.y);
				}
			}
		}
		if (PADUSE == 1)
		{
			//スクロール
			if (GetKeyboardPress(DIK_W))	//上
			{
				map_player.pos.y += 3;
				map_player.circlepos.y += 3;
			}
			if (GetKeyboardPress(DIK_S))	//下
			{
				map_player.pos.y -= 3;
				map_player.circlepos.y -= 3;
			}
			//1つ左のマスにカーソルを合わせる
			if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0 && map_player.UDcount < 7)
			{
				map_player.LRcount = map_player.LRcount - 1;
				map_player.circlepos.x = map[map_player.UDcount][map_player.LRcount].pos.x;
			}
			//1つ右のマスにカーソルを合わせる
			if (GetKeyboardTrigger(DIK_D) && map_player.circlepos.x < map[map_player.UDcount][map_player.LRcount + 1].pos.x && map_player.UDcount < 7)
			{
				map_player.LRcount = map_player.LRcount + 1;
				map_player.circlepos.x = map[map_player.UDcount][map_player.LRcount].pos.x;
			}
			//カーソルを合わせたマスにプレイヤーを動かす
			if (GetKeyboardTrigger(DIK_RETURN) && map_player.UDcount < 8)
			{
				//選択したマスまでプレイヤーを移動させる
				if (map_player.UDcount < 7)		//ボス前まで
				{
					map_player.pos.x = map[map_player.UDcount][map_player.LRcount].pos.x;
					map_player.pos.y = map_player.pos.y + 200;
				}
				if (map_player.UDcount == 7)	//ボスマス
					map_player.pos = D3DXVECTOR2(map_sb.bosspos.x + map_player.size.x * 0.25f, map_sb.bosspos.y);

				//選択したマスに対応したシーンに飛ぶ
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 1)	//通常敵マス
				{
					map_player.gamecount = map_player.gamecount + 1;	//ゲームシーンに入った回数を記録する
					map_player.encount = (rand() % 2) + 1;	//ここで出現する敵をランダムに決める
					map_player.encount = 2;
					SceneTransition(SCENE_GAME);
				}
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 2)	//強敵マス
				{
					SceneTransition(SCENE_GAME);
				}
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 3)	//休憩マス
				{
					SceneTransition(SCENE_REST);
				}
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 4)	//イベントマス
				{
					SceneTransition(SCENE_EVENT);
				}
				if (map[map_player.UDcount][map_player.LRcount].randomcode == 5)	//商人マス
				{
					SceneTransition(SCENE_SHOP);
				}

				map_player.LRcount = 0;
				map_player.UDcount = map_player.UDcount + 1;

				//次の選択肢までカーソルを移動させる
				if (map_player.UDcount < 7)		//ボス前まで
				{
					map_player.circlepos.x = map[map_player.UDcount][map_player.LRcount].pos.x;
					map_player.circlepos.y = map[map_player.UDcount][map_player.LRcount].pos.y;
				}
				if (map_player.UDcount == 7)	//ボスマス
				{
					map_player.circlepos = D3DXVECTOR2(map_sb.bosspos.x, map_sb.bosspos.y);
					map_player.circlesize = D3DXVECTOR2(map_sb.bosssize.x, map_sb.bosssize.y);
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

//-----構造体ポインタ取得
MAP_PLAYER* GetMapPlayer()
{
	return &map_player;
}

//------------------------------------------------------//
//---------------マス同士をつなぐ線の設定---------------//
//------------------------------------------------------//

#define map_linenum 28
static ID3D11Buffer* g_VertexBuffer = NULL;	// 頂点情報
int map_linetexture;	//マス同士をつなぐ線のテクスチャを設定する変数

MAP_LINE map_line[map_linenum];
MAP_LINE map_linedrawnum;

HRESULT InitMapLine(void)
{
	if (map_player.UDcount == 0)	//一回だけ呼ぶ
	{
		ID3D11Device* pDevice = GetDevice();

		// 頂点バッファ生成
		D3D11_BUFFER_DESC bd;
		ZeroMemory(&bd, sizeof(bd));
		bd.Usage = D3D11_USAGE_DYNAMIC;
		bd.ByteWidth = sizeof(VERTEX_3D) * 4 * map_linenum;
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		pDevice->CreateBuffer(&bd, NULL, &g_VertexBuffer);

		for (int i = 0; i < map_linenum; i++)
		{
			map_line[i].Ldrawcode = (rand() % 2);
			map_line[i].Rdrawcode = (rand() % 2);
		}

		map_linedrawnum.drawnum = 0;
		map_linedrawnum.a = 0;
	}

	return S_OK;
}

void UninitMapLine(void)
{

}

void UpdateMapLine(void)
{
	D3D11_MAPPED_SUBRESOURCE msr;
	GetDeviceContext()->Map(g_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);

	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;
	int x = 0;
	int y = 0;

	//スタート
	for (int i = 0; i < 2; i++)
	{
		vertex[map_linedrawnum.a].Position = D3DXVECTOR3(map_sb.startpos.x + map_sb.startsize.x * 0.5f - 5.f, map_sb.startpos.y + map_sb.startsize.y * 0.5f, 0.0f);
		vertex[map_linedrawnum.a].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[map_linedrawnum.a].TexCoord = D3DXVECTOR2(0.0f, 0.0f);
		vertex[map_linedrawnum.a + 1].Position = D3DXVECTOR3(map_sb.startpos.x + map_sb.startsize.x * 0.5f + 5.f, map_sb.startpos.y + map_sb.startsize.y * 0.5f, 0.0f);
		vertex[map_linedrawnum.a + 1].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[map_linedrawnum.a + 1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);
		vertex[map_linedrawnum.a + 2].Position = D3DXVECTOR3(map[0][x].pos.x + map[0][x].size.x * 0.5f - 5.f, map[0][x].pos.y + map[0][x].size.y * 0.5f, 0.0f);
		vertex[map_linedrawnum.a + 2].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[map_linedrawnum.a + 2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);
		vertex[map_linedrawnum.a + 3].Position = D3DXVECTOR3(map[0][x].pos.x + map[0][x].size.x * 0.5f + 5.f, map[0][x].pos.y + map[0][x].size.y * 0.5f, 0.0f);
		vertex[map_linedrawnum.a + 3].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[map_linedrawnum.a + 3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);
		x = x + 1;
		map_linedrawnum.a = map_linedrawnum.a + 4;
		map_linedrawnum.drawnum = map_linedrawnum.drawnum + 1;
	}

	x = 0;
	y = 0;
	for (int i = 0; i < 6; i++)
	{
		////左端
		//if (map_line[b].Ldrawcode == 0)
		//{
			vertex[map_linedrawnum.a].Position = D3DXVECTOR3(map[y][x].pos.x + map[y][x].size.x * 0.5f - 5.f, map[y][x].pos.y + map[y][x].size.y * 0.5f, 0.0f);
			vertex[map_linedrawnum.a].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[map_linedrawnum.a].TexCoord = D3DXVECTOR2(0.0f, 0.0f);
			vertex[map_linedrawnum.a + 1].Position = D3DXVECTOR3(map[y][x].pos.x + map[y][x].size.x * 0.5f + 5.f, map[y][x].pos.y + map[y][x].size.y * 0.5f, 0.0f);
			vertex[map_linedrawnum.a + 1].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[map_linedrawnum.a + 1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);
			vertex[map_linedrawnum.a + 2].Position = D3DXVECTOR3(map[y + 1][x].pos.x + map[y + 1][x].size.x * 0.5f - 5.f, map[y + 1][x].pos.y + map[y + 1][x].size.y * 0.5f, 0.0f);
			vertex[map_linedrawnum.a + 2].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[map_linedrawnum.a + 2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);
			vertex[map_linedrawnum.a + 3].Position = D3DXVECTOR3(map[y + 1][x].pos.x + map[y + 1][x].size.x * 0.5f + 5.f, map[y + 1][x].pos.y + map[y + 1][x].size.y * 0.5f, 0.0f);
			vertex[map_linedrawnum.a + 3].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[map_linedrawnum.a + 3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);
			map_linedrawnum.a = map_linedrawnum.a + 4;
			map_linedrawnum.drawnum = map_linedrawnum.drawnum + 1;
		//}

		////左から斜め
		//if (map_line[b].Ldrawcode == 1)
		//{
			vertex[map_linedrawnum.a].Position = D3DXVECTOR3(map[y][x].pos.x + map[y][x].size.x * 0.5f - 5.f, map[y][x].pos.y + map[y][x].size.y * 0.5f, 0.0f);
			vertex[map_linedrawnum.a].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[map_linedrawnum.a].TexCoord = D3DXVECTOR2(0.0f, 0.0f);
			vertex[map_linedrawnum.a + 1].Position = D3DXVECTOR3(map[y][x].pos.x + map[y][x].size.x * 0.5f + 5.f, map[y][x].pos.y + map[y][x].size.y * 0.5f, 0.0f);
			vertex[map_linedrawnum.a + 1].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[map_linedrawnum.a + 1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);
			vertex[map_linedrawnum.a + 2].Position = D3DXVECTOR3(map[y + 1][x + 1].pos.x + map[y + 1][x + 1].size.x * 0.5f - 5.f, map[y + 1][x + 1].pos.y + map[y + 1][x + 1].size.y * 0.5f, 0.0f);
			vertex[map_linedrawnum.a + 2].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[map_linedrawnum.a + 2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);
			vertex[map_linedrawnum.a + 3].Position = D3DXVECTOR3(map[y + 1][x + 1].pos.x + map[y + 1][x + 1].size.x * 0.5f + 5.f, map[y + 1][x + 1].pos.y + map[y + 1][x + 1].size.y * 0.5f, 0.0f);
			vertex[map_linedrawnum.a + 3].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[map_linedrawnum.a + 3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);
			map_linedrawnum.a = map_linedrawnum.a + 4;
			map_linedrawnum.drawnum = map_linedrawnum.drawnum + 1;
		//}

		////右端
		//if (map_line[b].Rdrawcode == 0)
		//{
			vertex[map_linedrawnum.a].Position = D3DXVECTOR3(map[y][x + 1].pos.x + map[y][x + 1].size.x * 0.5f - 5.f, map[y][x + 1].pos.y + map[y][x + 1].size.y * 0.5f, 0.0f);
			vertex[map_linedrawnum.a].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[map_linedrawnum.a].TexCoord = D3DXVECTOR2(0.0f, 0.0f);
			vertex[map_linedrawnum.a + 1].Position = D3DXVECTOR3(map[y][x + 1].pos.x + map[y][x + 1].size.x * 0.5f + 5.f, map[y][x + 1].pos.y + map[y][x + 1].size.y * 0.5f, 0.0f);
			vertex[map_linedrawnum.a + 1].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[map_linedrawnum.a + 1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);
			vertex[map_linedrawnum.a + 2].Position = D3DXVECTOR3(map[y + 1][x + 1].pos.x + map[y + 1][x + 1].size.x * 0.5f - 5.f, map[y + 1][x + 1].pos.y + map[y + 1][x + 1].size.y * 0.5f, 0.0f);
			vertex[map_linedrawnum.a + 2].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[map_linedrawnum.a + 2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);
			vertex[map_linedrawnum.a + 3].Position = D3DXVECTOR3(map[y + 1][x + 1].pos.x + map[y + 1][x + 1].size.x * 0.5f + 5.f, map[y + 1][x + 1].pos.y + map[y + 1][x + 1].size.y * 0.5f, 0.0f);
			vertex[map_linedrawnum.a + 3].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[map_linedrawnum.a + 3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);
			map_linedrawnum.a = map_linedrawnum.a + 4;
			map_linedrawnum.drawnum = map_linedrawnum.drawnum + 1;
		//}

		////右から斜め
		//if (map_line[b].Rdrawcode == 1)
		//{
			vertex[map_linedrawnum.a].Position = D3DXVECTOR3(map[y][x + 1].pos.x + map[y][x + 1].size.x * 0.5f - 5.f, map[y][x + 1].pos.y + map[y][x + 1].size.y * 0.5f, 0.0f);
			vertex[map_linedrawnum.a].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[map_linedrawnum.a].TexCoord = D3DXVECTOR2(0.0f, 0.0f);
			vertex[map_linedrawnum.a + 1].Position = D3DXVECTOR3(map[y][x + 1].pos.x + map[y][x + 1].size.x * 0.5f + 5.f, map[y][x + 1].pos.y + map[y][x + 1].size.y * 0.5f, 0.0f);
			vertex[map_linedrawnum.a + 1].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[map_linedrawnum.a + 1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);
			vertex[map_linedrawnum.a + 2].Position = D3DXVECTOR3(map[y + 1][x].pos.x + map[y + 1][x].size.x * 0.5f - 5.f, map[y + 1][x].pos.y + map[y + 1][x].size.y * 0.5f, 0.0f);
			vertex[map_linedrawnum.a + 2].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[map_linedrawnum.a + 2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);
			vertex[map_linedrawnum.a + 3].Position = D3DXVECTOR3(map[y + 1][x].pos.x + map[y + 1][x].size.x * 0.5f + 5.f, map[y + 1][x].pos.y + map[y + 1][x].size.y * 0.5f, 0.0f);
			vertex[map_linedrawnum.a + 3].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[map_linedrawnum.a + 3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);
			map_linedrawnum.a = map_linedrawnum.a + 4;
			map_linedrawnum.drawnum = map_linedrawnum.drawnum + 1;
		//}

		y = y = 1;
	}


	x = 0;
	//ゴールまで
	for (int i = 0; i < 2; i++)
	{
		vertex[map_linedrawnum.a].Position = D3DXVECTOR3(map[6][x].pos.x + map[6][x].size.x * 0.5f - 5.f, map[6][x].pos.y + map[6][x].size.y * 0.5f, 0.0f);
		vertex[map_linedrawnum.a].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[map_linedrawnum.a].TexCoord = D3DXVECTOR2(0.0f, 0.0f);
		vertex[map_linedrawnum.a + 1].Position = D3DXVECTOR3(map[6][x].pos.x + map[6][x].size.x * 0.5f + 5.f, map[6][x].pos.y + map[6][x].size.y * 0.5f, 0.0f);
		vertex[map_linedrawnum.a + 1].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[map_linedrawnum.a + 1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);
		vertex[map_linedrawnum.a + 2].Position = D3DXVECTOR3(map_sb.bosspos.x + map_sb.bosssize.x * 0.5f - 5.f, map_sb.bosspos.y + map_sb.bosssize.y * 0.5f, 0.0f);
		vertex[map_linedrawnum.a + 2].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[map_linedrawnum.a + 2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);
		vertex[map_linedrawnum.a + 3].Position = D3DXVECTOR3(map_sb.bosspos.x + map_sb.bosssize.x * 0.5f + 5.f, map_sb.bosspos.y + map_sb.bosssize.y * 0.5f, 0.0f);
		vertex[map_linedrawnum.a + 3].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[map_linedrawnum.a + 3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);
		x = x + 1;
		map_linedrawnum.a = map_linedrawnum.a + 4;
		map_linedrawnum.drawnum = map_linedrawnum.drawnum + 1;
	}

}

void DrawMapLine(void)
{
	GetDeviceContext()->Unmap(g_VertexBuffer, 0);

	// 頂点バッファ設定
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);

	// プリミティブトポロジ設定
	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	// テクスチャ設定
	GetDeviceContext()->PSSetShaderResources(0, 1, GetTexture(map_linetexture));

	// ポリゴン描画
	GetDeviceContext()->Draw(4 * map_linedrawnum.drawnum, 0);
}