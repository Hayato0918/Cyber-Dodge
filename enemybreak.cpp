//エネミー撃破処理[enemy.cpp]
#include "enemybreak.h"
//システム.h
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"
#include "texture.h"
#include "sprite.h"
//slime.h
#include "slime.h"
//deleter.h
#include "deleter.h"
//firewall.h
#include "firewall.h"

#include "skillrandom.h"
#include "map_player.h"

ENEMYBREAK enemybreak;
GETSKILL getskill;
GETGOLD getgold;


HRESULT InitEnemyBreak(void)
{
	enemybreak.pos = D3DXVECTOR2(300.f, 100.f);
	enemybreak.size = D3DXVECTOR2(1000.f, 700.f);
	enemybreak.texture = LoadTexture("data/TEXTURE/result.png");
	enemybreak.drawflag = false;

	getskill.pos = D3DXVECTOR2(420.f, 380.f);
	getskill.size = D3DXVECTOR2(200.f, 300.f);
	getskill.skillcode = 0;

	getgold.pos = D3DXVECTOR2(800.f, 400.f);
	getgold.size = D3DXVECTOR2(400.f, 100.f);


	return S_OK;
}

void UninitEnemyBreak(void)
{

}

void UpdateEnemyBreak(void)
{
	SKILL* skill = GetSkill();
	RANDOM* random = GetRandom();


	if (GetKeyboardTrigger(DIK_RETURN))
		SceneTransition(SCENE_MAP);

	//-----スキル獲得
	if (enemybreak.drawflag == true)
		getskill.skillcode = random[skill->slot - 1].code;

	//割り当てられたcodeに対応したテクスチャを表示
	if (getskill.skillcode == 1)
		getskill.texture = LoadTexture("data/TEXTURE/skill/speedup.png");
	if (getskill.skillcode == 2)
		getskill.texture = LoadTexture("data/TEXTURE/skill/turnaround.png");
	if (getskill.skillcode == 3)
		getskill.texture = LoadTexture("data/TEXTURE/skill/barrier.png");
	if (getskill.skillcode == 4)
		getskill.texture = LoadTexture("data/TEXTURE/skill/baseball.png");
	if (getskill.skillcode == 5)
		getskill.texture = LoadTexture("data/TEXTURE/skill/bigball.png");
	if (getskill.skillcode == 6)
		getskill.texture = LoadTexture("data/TEXTURE/skill/billiards.png");
	if (getskill.skillcode == 7)
		getskill.texture = LoadTexture("data/TEXTURE/skill/buildup.png");
	if (getskill.skillcode == 8)
		getskill.texture = LoadTexture("data/TEXTURE/skill/catchjamming.png");
	if (getskill.skillcode == 9)
		getskill.texture = LoadTexture("data/TEXTURE/skill/invade.png");
	if (getskill.skillcode == 10)
		getskill.texture = LoadTexture("data/TEXTURE/skill/invincible.png");
	if (getskill.skillcode == 11)
		getskill.texture = LoadTexture("data/TEXTURE/skill/penetration.png");
	if (getskill.skillcode == 12)
		getskill.texture = LoadTexture("data/TEXTURE/skill/rockcreate.png");
	if (getskill.skillcode == 13)
		getskill.texture = LoadTexture("data/TEXTURE/skill/slowarea.png");
	if (getskill.skillcode == 14)
		getskill.texture = LoadTexture("data/TEXTURE/skill/smallplayer.png");
	//if (getskill.skillcode == 15)
	//	getskill.texture = LoadTexture("data/TEXTURE/skill/autocatch.png");
	if (getskill.skillcode == 16)
		getskill.texture = LoadTexture("data/TEXTURE/skill/disappear.png");
	if (getskill.skillcode == 17)
		getskill.texture = LoadTexture("data/TEXTURE/skill/doubleattack.png");
	if (getskill.skillcode == 18)
		getskill.texture = LoadTexture("data/TEXTURE/skill/enemy_powerdown.png");
	if (getskill.skillcode == 19)
		getskill.texture = LoadTexture("data/TEXTURE/skill/landmine.png");
	if (getskill.skillcode == 20)
		getskill.texture = LoadTexture("data/TEXTURE/skill/mindhack.png");
	if (getskill.skillcode == 21)
		getskill.texture = LoadTexture("data/TEXTURE/skill/otoshiana.png");
	if (getskill.skillcode == 22)
		getskill.texture = LoadTexture("data/TEXTURE/skill/player_powerup.png");
	if (getskill.skillcode == 23)
		getskill.texture = LoadTexture("data/TEXTURE/skill/player_regen.png");
	if (getskill.skillcode == 24)
		getskill.texture = LoadTexture("data/TEXTURE/skill/player_speedup.png");
	if (getskill.skillcode == 25)
		getskill.texture = LoadTexture("data/TEXTURE/skill/timestop.png");
	if (getskill.skillcode == 26)
		getskill.texture = LoadTexture("data/TEXTURE/skill/warp.png");


	//-----ゴールド獲得





}

void DrawEnemyBreak(void)
{
	if (enemybreak.drawflag == true)
	{
		DrawSpriteLeftTop(enemybreak.texture, enemybreak.pos.x, enemybreak.pos.y, enemybreak.size.x, enemybreak.size.y, 0.f, 0.f, 1.f, 1.f);

		DrawSpriteLeftTop(getskill.texture, getskill.pos.x, getskill.pos.y, getskill.size.x, getskill.size.y, 0.f, 0.f, 1.f, 1.f);
	}
}

ENEMYBREAK* GetEnemyBreak(void)
{
	return &enemybreak;
}