#pragma once

// 登録シーン一覧
enum SCENE
{
	SCENE_NONE,		//シーン処理なし
	SCENE_TITLE,	//タイトル
	SCENE_RANKING,
	SCENE_OPTION,	//設定画面
	SCENE_NAME,		//名前決め
	SCENE_MAP,		//ローグライク部分
	SCENE_DECKMENU,	//デッキメニュー
	SCENE_REST,		//休憩マス
	SCENE_EVENT,	//イベントマス
	SCENE_SHOP,		//商人（ショップ）マス
	SCENE_GAME,		//ドッジボール部分

	SCENE_CLEAR,
	SCENE_GAMEOVER,

	SCENE_MAX		//最後だとわかる奴をいれる
};

void InitScene(SCENE index);
void UninitScene(void);
void UpdateScene(void);
void DrawScene(void);

void SetScene(SCENE index);
void CheckScene(void);
