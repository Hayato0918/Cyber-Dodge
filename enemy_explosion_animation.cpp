//エネミー死亡時のエフェクト追加[enemy_explosion_animation.cpp]
#include "enemy_explosion_animation.h"
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
ENEMY_EXPLOSION enemy_explosion;

HRESULT InitEnemyExplosion(void)
{
	enemy_explosion.pos = D3DXVECTOR2(0.f, 0.f);
	enemy_explosion.size = D3DXVECTOR2(0.f, 0.f);
	enemy_explosion.texture = LoadTexture("data/TEXTURE/enemy/Eff_Explosion.png");
	enemy_explosion.u = 0.f;
	enemy_explosion.animetime = 0.f;
	enemy_explosion.drawflag = false;
	enemy_explosion.animeflag = false;

	return S_OK;
}

void UninitEnemyExplosion(void)
{

}

void UpdateEnemyExplosion(void)
{
	//-----アニメーション
	if (enemy_explosion.drawflag == true)
	{
		MAP_PLAYER* map_player = GetMapPlayer();
		SLIME* slime = GetSlime();
		DELETER* deleter = GetDeleter();
		FIREWALL* firewall = GetFireWall();

		enemy_explosion.texture = LoadTexture("data/TEXTURE/enemy/Eff_Explosion.png");

		if (map_player->encount == 1)
		{
			enemy_explosion.pos = D3DXVECTOR2(slime->pos.x - 25.f, slime->pos.y - 25.f);
			enemy_explosion.size = D3DXVECTOR2(300.0f, 300.0f);
		}
		if (map_player->encount == 2)
		{
			enemy_explosion.pos = D3DXVECTOR2(deleter->pos.x - 25.f, deleter->pos.y - 25.f);
			enemy_explosion.size = D3DXVECTOR2(300.0f, 300.0f);
		}
		if (map_player->encount == 3)
		{
			enemy_explosion.pos = D3DXVECTOR2(firewall->pos.x - 25.f, firewall->pos.y - 25.f);
			enemy_explosion.size = D3DXVECTOR2(300.0f, 300.0f);
		}


		enemy_explosion.animetime = enemy_explosion.animetime + 1;

		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 8.f)
			enemy_explosion.u = 0.f;
		//
		if (enemy_explosion.animetime >= 8.f && enemy_explosion.animetime < 16.f)
			enemy_explosion.u = 0.0417f;
		if (enemy_explosion.animetime >= 16.f && enemy_explosion.animetime < 24.f)
			enemy_explosion.u = 0.0417f * 2;
		if (enemy_explosion.animetime >= 24.f && enemy_explosion.animetime < 32.f)
			enemy_explosion.u = 0.0417f * 3;
		if (enemy_explosion.animetime >= 32.f && enemy_explosion.animetime < 40.f)
			enemy_explosion.u = 0.0417f * 4;
		if (enemy_explosion.animetime >= 40.f && enemy_explosion.animetime < 48.f)
			enemy_explosion.u = 0.0417f * 5;
		if (enemy_explosion.animetime >= 48.f && enemy_explosion.animetime < 56.f)
			enemy_explosion.u = 0.0417f * 6;
		if (enemy_explosion.animetime >= 56.f && enemy_explosion.animetime < 64.f)
			enemy_explosion.u = 0.0417f * 7;
		if (enemy_explosion.animetime >= 64.f && enemy_explosion.animetime < 72.f)
			enemy_explosion.u = 0.0417f * 8;
		if (enemy_explosion.animetime >= 72.f && enemy_explosion.animetime < 80.f)
			enemy_explosion.u = 0.0417f * 9;
		if (enemy_explosion.animetime >= 80.f && enemy_explosion.animetime < 88.f)
			enemy_explosion.u = 0.0417f * 10;
		if (enemy_explosion.animetime >= 88.f && enemy_explosion.animetime < 96.f)
			enemy_explosion.u = 0.0417f * 11;
		if (enemy_explosion.animetime >= 96.f && enemy_explosion.animetime < 104.f)
			enemy_explosion.u = 0.0417f * 12;
		if (enemy_explosion.animetime >= 104.f && enemy_explosion.animetime < 112.f)
			enemy_explosion.u = 0.0417f * 13;
		if (enemy_explosion.animetime >= 112.f && enemy_explosion.animetime < 120.f)
			enemy_explosion.u = 0.0417f * 14;
		if (enemy_explosion.animetime >= 120.f && enemy_explosion.animetime < 128.f)
			enemy_explosion.u = 0.0417f * 15;
		if (enemy_explosion.animetime >= 128.f && enemy_explosion.animetime < 136.f)
			enemy_explosion.u = 0.0417f * 16;
		if (enemy_explosion.animetime >= 136.f && enemy_explosion.animetime < 144.f)
			enemy_explosion.u = 0.0417f * 17;
		if (enemy_explosion.animetime >= 144.f && enemy_explosion.animetime < 152.f)
			enemy_explosion.u = 0.0417f * 18;
		if (enemy_explosion.animetime >= 152.f && enemy_explosion.animetime < 160.f)
			enemy_explosion.u = 0.0417f * 19;
		if (enemy_explosion.animetime >= 160.f && enemy_explosion.animetime < 168.f)
			enemy_explosion.u = 0.0417f * 20;
		if (enemy_explosion.animetime >= 168.f && enemy_explosion.animetime < 176.f)
			enemy_explosion.u = 0.0417f * 21;
		if (enemy_explosion.animetime >= 176.f && enemy_explosion.animetime < 184.f)
			enemy_explosion.u = 0.0417f * 22;
		if (enemy_explosion.animetime >= 184.f && enemy_explosion.animetime < 192.f)
			enemy_explosion.u = 0.0417f * 23;
		//
		if (enemy_explosion.animetime >= 192.f)
		{
			enemy_explosion.u = 0.f;
			enemy_explosion.animeflag = true;
			//enemy_explosion.drawflag =false;
		}
	}
}

void DrawEnemyExplosion(void)
{
	if (enemy_explosion.drawflag == true)
	{
		DrawSpriteLeftTop(enemy_explosion.texture, enemy_explosion.pos.x, enemy_explosion.pos.y, enemy_explosion.size.x, enemy_explosion.size.y, enemy_explosion.u, 0.f, 0.0417f, 1.f);
	}
}

ENEMY_EXPLOSION* GetEnemyExplosion(void)
{
	return &enemy_explosion;
}