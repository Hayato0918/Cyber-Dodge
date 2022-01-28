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
			enemy_explosion.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.355555f);
			enemy_explosion.size = D3DXVECTOR2(300.0f, 300.0f);
		}
		if (map_player->encount == 2)
		{
			enemy_explosion.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.355555f);
			enemy_explosion.size = D3DXVECTOR2(300.0f, 300.0f);
		}
		if (map_player->encount == 3)
		{
			enemy_explosion.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.355555f);
			enemy_explosion.size = D3DXVECTOR2(300.0f, 300.0f);
		}


		enemy_explosion.animetime = enemy_explosion.animetime + 1;

		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 8.f)
			enemy_explosion.u = 0.f;
		//
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 16.f)
			enemy_explosion.u = 0.05f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 24.f)
			enemy_explosion.u = 0.10f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 32.f)
			enemy_explosion.u = 0.15f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 40.f)
			enemy_explosion.u = 0.20f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 48.f)
			enemy_explosion.u = 0.25f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 56.f)
			enemy_explosion.u = 0.30f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 64.f)
			enemy_explosion.u = 0.35f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 72.f)
			enemy_explosion.u = 0.40f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 80.f)
			enemy_explosion.u = 0.45f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 88.f)
			enemy_explosion.u = 0.50f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 96.f)
			enemy_explosion.u = 0.55f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 104.f)
			enemy_explosion.u = 0.60f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 112.f)
			enemy_explosion.u = 0.65f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 120.f)
			enemy_explosion.u = 0.70f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 128.f)
			enemy_explosion.u = 0.75f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 136.f)
			enemy_explosion.u = 0.80f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 144.f)
			enemy_explosion.u = 0.85f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 152.f)
			enemy_explosion.u = 0.90f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 160.f)
			enemy_explosion.u = 0.95f;
		if (enemy_explosion.animetime >= 0.f && enemy_explosion.animetime < 168.f)
			enemy_explosion.u = 0.99f;
		//
		if (enemy_explosion.animetime >= 168.f)
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
		DrawSpriteLeftTop(enemy_explosion.texture, enemy_explosion.pos.x, enemy_explosion.pos.y, enemy_explosion.size.x, enemy_explosion.size.y, enemy_explosion.u, 0.f, 0.05f, 1.f);
	}
}

ENEMY_EXPLOSION* GetEnemyExplosion(void)
{
	return &enemy_explosion;
}