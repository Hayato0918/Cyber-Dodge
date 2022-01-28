//エネミー処理[enemy.cpp]
#include "enemy.h"
//システム.h
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"
//slime.h
#include "slime.h"
#include "slime_hp.h"
//deleter.h
#include "deleter.h"
#include "deleter_hp.h"
//firewall.h
#include "firewall.h"
#include "firewall_hp.h"
//
#include "map_player.h"
#include "enemy_aura.h"
#include "enemy_explosion_animation.h"

HRESULT InitEnemy(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	if (map_player->encount == 1)
	{
		InitSlime();
		InitSlimeHp();
	}
	if (map_player->encount == 2)
	{
		InitDeleter();
		InitDeleterHp();
	}
	if (map_player->encount == 3)
	{
		InitFireWall();
		InitFireWallHp();
	}

	InitEnemyAura();
	InitEnemyExplosion();
	return S_OK;
}

void UninitEnemy(void)
{

}

void UpdateEnemy(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	if (map_player->encount == 1)
	{
		UpdateSlime();
		UpdateSlimeHp();
	}
	if (map_player->encount == 2)
	{
		UpdateDeleter();
		UpdateDeleterHp();
	}
	if (map_player->encount == 3)
	{
		UpdateFireWall();
		UpdateFireWallHp();
	}

	UpdateEnemyAura();
	UpdateEnemyExplosion();
	
}

void DrawEnemy(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	if (map_player->encount == 1)
	{
		DrawSlime();
		DrawSlimeHp();
	}
	if (map_player->encount == 2)
	{
		DrawDeleter();
		DrawDeleterHp();
	}
	if (map_player->encount == 3)
	{
		DrawFireWall();
		DrawFireWallHp();
	}

	if(map_player->enemypowerup == true)
		DrawEnemyAura();
	    DrawEnemyExplosion();
}