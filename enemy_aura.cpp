//エネミーオーラ処理[enemy_aura.cpp]
#include "enemy_aura.h"
//システム.h
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"
#include "Texture.h"
#include "sprite.h"
//slime.h
#include "slime.h"
//deleter.h
#include "deleter.h"
//firewall.h
#include "firewall.h"
//
#include "map_player.h"

ENEMY_AURA enemy_aura;

HRESULT InitEnemyAura(void)
{
	enemy_aura.pos = D3DXVECTOR2(0.f, 0.f);
	enemy_aura.size = D3DXVECTOR2(0.f, 0.f);
	enemy_aura.u = 0.f;
	enemy_aura.animetime = 0.f;
	enemy_aura.texture = LoadTexture("data/TEXTURE/enemy/Aura.png");

	return S_OK;
}

void UninitEnemyAura(void)
{

}

void UpdateEnemyAura(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();
	SLIME* slime = GetSlime();
	DELETER* deleter = GetDeleter();
	FIREWALL* firewall = GetFireWall();

	if (map_player->encount == 1)
	{
		enemy_aura.pos = D3DXVECTOR2(slime->pos.x - 25.f, slime->pos.y - 25.f);
		enemy_aura.size = D3DXVECTOR2(slime->size.x + 50.f, slime->size.y + 50.f);
	}
	if (map_player->encount == 2)
	{
		enemy_aura.pos = D3DXVECTOR2(deleter->pos.x - 25.f, deleter->pos.y - 25.f);
		enemy_aura.size = D3DXVECTOR2(deleter->size.x + 50.f, deleter->size.y + 50.f);
	}
	if (map_player->encount == 3)
	{
		enemy_aura.pos = D3DXVECTOR2(firewall->pos.x - 25.f, firewall->pos.y - 25.f);
		enemy_aura.size = D3DXVECTOR2(firewall->size.x + 50.f, firewall->size.y + 50.f);
	}

	//-----アニメーション
	enemy_aura.animetime = enemy_aura.animetime + 1;

	if (enemy_aura.animetime >= 0.f && enemy_aura.animetime < 8.f)
		enemy_aura.u = 0.f;
	if (enemy_aura.animetime >= 8.f && enemy_aura.animetime < 16.f)
		enemy_aura.u = 0.0666666f;
	if (enemy_aura.animetime >= 16.f && enemy_aura.animetime < 24.f)
		enemy_aura.u = 0.1333332f;
	if (enemy_aura.animetime >= 24.f && enemy_aura.animetime < 32.f)
		enemy_aura.u = 0.1999998f;
	if (enemy_aura.animetime >= 32.f && enemy_aura.animetime < 40.f)
		enemy_aura.u = 0.2666664f;
	if (enemy_aura.animetime >= 40.f && enemy_aura.animetime < 48.f)
		enemy_aura.u = 0.3333333f;
	if (enemy_aura.animetime >= 48.f && enemy_aura.animetime < 56.f)
		enemy_aura.u = 0.3999996f;
	if (enemy_aura.animetime >= 56.f && enemy_aura.animetime < 64.f)
		enemy_aura.u = 0.4666662f;
	if (enemy_aura.animetime >= 64.f && enemy_aura.animetime < 72.f)
		enemy_aura.u = 0.5333328f;
	if (enemy_aura.animetime >= 72.f && enemy_aura.animetime < 80.f)
		enemy_aura.u = 0.5999994f;
	if (enemy_aura.animetime >= 80.f && enemy_aura.animetime < 88.f)
		enemy_aura.u = 0.6666666f;
	if (enemy_aura.animetime >= 88.f && enemy_aura.animetime < 96.f)
		enemy_aura.u = 0.7333326f;
	if (enemy_aura.animetime >= 96.f && enemy_aura.animetime < 104.f)
		enemy_aura.u = 0.7999992f;
	if (enemy_aura.animetime >= 104.f && enemy_aura.animetime < 112.f)
		enemy_aura.u = 0.8666658f;
	if (enemy_aura.animetime >= 112.f && enemy_aura.animetime < 120.f)
		enemy_aura.u = 0.93333324f;
	if (enemy_aura.animetime >= 120.f && enemy_aura.animetime < 128.f)
		enemy_aura.u = 0.99999999f;
	if (enemy_aura.animetime >= 128.f)
		enemy_aura.animetime = 0.f;
}

void DrawEnemyAura(void)
{
	DrawSpriteLeftTop(enemy_aura.texture, enemy_aura.pos.x, enemy_aura.pos.y, enemy_aura.size.x, enemy_aura.size.y, enemy_aura.u, 0.f, 0.0666666f, 1.f);
}