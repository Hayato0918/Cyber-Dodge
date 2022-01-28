//プレイヤー操作処理[player_operate.cpp]
#include "player_operate.h"
//システム.h
#include "input.h"
//
#include "player.h"
#include "reverse.h"
#include "ball.h"
#include "catch.h"

void player_operate()
{
	PLAYER* player = GetPlayer();
	REVERSE* reverse = GetReverse();

	//---------------移動---------------
	//padのとき
	if (PADUSE == 0)
	{
		if (IsButtonPressed(0, BUTTON_UP))
		{
			if (reverse->use == false)
				player->pos.y -= player->move.y;
			if (reverse->use == true)
				player->pos.y += player->move.y;
		}
		if (IsButtonPressed(0, BUTTON_DOWN))
		{
			if (reverse->use == false)
				player->pos.y += player->move.y;
			if (reverse->use == true)
				player->pos.y -= player->move.y;
		}
		if (IsButtonPressed(0, BUTTON_LEFT))
		{
			if (reverse->use == false)
				player->pos.x -= player->move.x;
			if (reverse->use == true)
				player->pos.x += player->move.x;

			player->rotate = 2;		//左向きに更新

			player->walktextureflag = true;		//テクスチャの切り替え
		}
		if (IsButtonPressed(0, BUTTON_RIGHT))
		{
			if (reverse->use == false)
				player->pos.x += player->move.x;
			if (reverse->use == true)
				player->pos.x -= player->move.x;

			player->rotate = 3;		//右向きに更新

			player->walktextureflag = true;		//テクスチャの切り替え
		}

		//if (IsButtonTriggered(0, BUTTON_RELEASE))	//左移動をやめたら
		//	player.walktextureflag = false;
		//if (IsButtonTriggered(0, BUTTON_RELEASE))	//右移動をやめたら
		//	player.walktextureflag = false;
	}

	//-----移動処理(コートの左右端を3sで移動)
	if (PADUSE == 1)
	{
		if (GetKeyboardPress(DIK_W))	//上
		{
			if (reverse->use == false)
				player->pos.y -= player->move.y;
			if (reverse->use == true)
				player->pos.y += player->move.y;
		}
		if (GetKeyboardPress(DIK_S))	//下
		{
			if (reverse->use == false)
				player->pos.y += player->move.y;
			if (reverse->use == true)
				player->pos.y -= player->move.y;
		}
		if (GetKeyboardPress(DIK_A))	//左
		{
			if (reverse->use == false)
				player->pos.x -= player->move.x;
			if (reverse->use == true)
				player->pos.x += player->move.x;

			player->rotate = 2;		//左向きに更新

			player->walktextureflag = true;		//テクスチャの切り替え
		}
		if (GetKeyboardPress(DIK_D))	//右
		{
			if (reverse->use == false)
				player->pos.x += player->move.x;
			if (reverse->use == true)
				player->pos.x -= player->move.x;

			player->rotate = 3;		//右向きに更新

			player->walktextureflag = true;		//テクスチャの切り替え
		}

		/*if (GetKeyboardRelease(DIK_A))	//左移動をやめたら
			player->walktextureflag = false;
		if (GetKeyboardRelease(DIK_D))	//右移動をやめたら
			player->walktextureflag = false;*/
	}


	//---------------投げ---------------
	P_Throw();


	//---------------キャッチ---------------
	P_Catch();


	//---------------スキル---------------
}