//デリーター処理 [deleter.cpp]
#include "textureload.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "scene.h"
#include "fade.h"

//-----バナー
#include "banner_bg.h"

//-----休憩
#include "rest_bg.h"
#include "rest_command.h"
#include "rest_exit.h"
#include "rest_select.h"

//-----ショップ
#include "shop_bg.h"
#include "shop_card.h"
#include "shop_exit.h"
#include "shop_gold.h"
#include "shop_reload.h"
#include "shop_select.h"

//-----プレイヤー
#include "player.h"
#include "player_hp.h"

//-----ボール
#include "ball.h"

//-----バグ
#include "bugincrease.h"

#include "hackeffect.h"

//-----マップ
#include "map_floor.h"

//-----ゲーム背景
#include "bg.h"

//-----エネミー
#include "slime.h"
#include "slime_hp.h"
#include "deleter.h"
#include "deleter_hp.h"
#include "firewall.h"
#include "firewall_hp.h"
#include "enemy_aura.h"

//-----チュートリアル
#include "tutorial.h"
#include "tutorial_map.h"

//-----スキル
#include "barrier.h"
#include "baseball.h"


//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数


void TextureLoad()
{
	//-----スキル
	BARRIER* barrier = GetBarrier();
	barrier->texture = LoadTexture("data/TEXTURE/barrier.png");
	BASEBALL* baseball = GetBaseball();
	baseball->texture = LoadTexture("data/TEXTURE/bat.png");







	HACKEFFECT* hackeffect = GetHackEffect();
	hackeffect->texture = LoadTexture("data/TEXTURE/hackingmenu/effect.png");

	//-----はいけい
	BG* bg = GetBG();
	bg->texture = LoadTexture("data/TEXTURE/gym.jpg");

	//-----バナー
	BANNER_BG* banner_bg = GetBannerBG();
	banner_bg->texture = LoadTexture("data/TEXTURE/banner.png");

	//-----マップ
	MAP_FLOORBG* map_floor = GetMapFloorNum();
	map_floor->texture = LoadTexture("data/TEXTURE/map/floor.png");
	map_floor->numtexture = LoadTexture("data/TEXTURE/number.png");

	//-----休憩
	REST_BG* rest_bg = GetRestBG();
	rest_bg->texture = LoadTexture("data/TEXTURE/test/black.png");
	REST_HPUP* rest_hpup = GetRestCommandHP();
	rest_hpup->texture = LoadTexture("data/TEXTURE/map/rest/hpup.png");
	REST_STATUSUP* rest_statusup = GetRestCommandStatus();
	rest_statusup->texture = LoadTexture("data/TEXTURE/map/rest/statusup.png");
	REST_EXIT* rest_exit = GetRestExit();
	rest_exit->texture = LoadTexture("data/TEXTURE/map/rest/exit.png");
	REST_SELECT* rest_select = GetRestSelect();
	rest_select->texture = LoadTexture("data/TEXTURE/rest_frame.png");

	//-----ショップ
	SHOP_BG* shop_bg = GetShopBG();
	shop_bg->texture = LoadTexture("data/TEXTURE/test/black.png");
	SHOP_CARDTEXTURE* shop_cardtexture = GetShopCardTexture();
	shop_cardtexture->texture = LoadTexture("data/TEXTURE/skill/skill.png");
	SHOP_EXIT* shop_exit = GetShopExit();
	shop_exit->texture = LoadTexture("data/TEXTURE/map/shop/exit.png");
	SHOP_GOLDTEXTURE* shop_goldtxture = GetShopGoldTexture();
	shop_goldtxture->texture = LoadTexture("data/TEXTURE/map/shop/gold.png");
	SHOP_RELOAD* shop_reload = GetShopReload();
	shop_reload->texture = LoadTexture("data/TEXTURE/map/shop/reload.png");
	SHOP_SELECT* shop_select = GetShopSelect();
	shop_select->texture = LoadTexture("data/TEXTURE/test/select.png");

	//-----ボール
	BALL* ball = GetBall();
	ball->texture = LoadTexture("data/TEXTURE/ball.png");

	//-----バグ
	BUG* bug = GetBugIncrease();
	bug->frametexture = LoadTexture("data/TEXTURE/buggauge/gaugeframe.png");
	bug->breaktexture = LoadTexture("data/TEXTURE/buggauge/gaugebreak.png");
	bug->gaugetexture = LoadTexture("data/TEXTURE/buggauge/gaugebar.png");
	bug->numbertexture = LoadTexture("data/TEXTURE/buggauge/Number.png");

	//-----プレイヤー
	PLAYER* player = GetPlayer();
	player->stand_Ltexture = LoadTexture("data/TEXTURE/player/stand/stand_R.png");
	player->stand_Rtexture = LoadTexture("data/TEXTURE/player/stand/stand_L.png");
	player->walk_Ltexture = LoadTexture("data/TEXTURE/player/walk/walk_R.png");
	player->walk_Rtexture = LoadTexture("data/TEXTURE/player/walk/walk_L.png");
	player->catch_Ltexture = LoadTexture("data/TEXTURE/player/catch/catch_R.png");
	player->catch_Rtexture = LoadTexture("data/TEXTURE/player/catch/catch_L.png");
	player->pick_Ltexture = LoadTexture("data/TEXTURE/player/pick/pick_R.png");
	player->pick_Rtexture = LoadTexture("data/TEXTURE/player/pick/pick_L.png");
	player->throw_Ltexture = LoadTexture("data/TEXTURE/player/throw/throw_R.png");
	player->throw_Rtexture = LoadTexture("data/TEXTURE/player/throw/throw_L.png");
	player->skill_Ltexture = LoadTexture("data/TEXTURE/player/skill/skill_R.png");
	player->skill_Rtexture = LoadTexture("data/TEXTURE/player/skill/skill_L.png");
	player->damage_Ltexture = LoadTexture("data/TEXTURE/player/damage/damage_R.png");
	player->damage_Rtexture = LoadTexture("data/TEXTURE/player/damage/damage_L.png");
	player->deathtexture = LoadTexture("data/TEXTURE/player/death/death.png");
	PLAYERHP* playerhp = GetPlayerHp();
	playerhp->frametexture = LoadTexture("data/TEXTURE/player/hp/player_hpframe.png");
	playerhp->gaugeredtexture = LoadTexture("data/TEXTURE/player/hp/player_hpred.png");
	playerhp->gaugegreentexture = LoadTexture("data/TEXTURE/player/hp/player_hpgreen.png");

	//-----チュートリアル
	TUTORIAL_GAME* tutorial_game = GetTutorialGame();
	tutorial_game->texture = LoadTexture("data/TEXTURE/tutorial/game.png");
	TUTORIAL_SKILL* tutorial_skill = GetTutorialSkill();
	tutorial_skill->texture = LoadTexture("data/TEXTURE/tutorial/skill.png");
	TUTORIAL_IDOU* tutorial_idou = GetTutorialIdou();
	tutorial_idou->texture = LoadTexture("data/TEXTURE/tutorial/game_idou.png");
	TUTORIAL_NAGE* tutorial_nage = GetTutorialNage();
	tutorial_nage->texture = LoadTexture("data/TEXTURE/tutorial/game_nage.png");
	TUTORIAL_SUKILL* tutorial_sukill = GetTutorialSukill();
	tutorial_sukill->texture = LoadTexture("data/TEXTURE/tutorial/game_skill.png");
	TUTORIAL_MAP* tutorial_map = GetTutorialMap();
	tutorial_map->texture = LoadTexture("data/TEXTURE/tutorial/map.png");

	//-----スライム
	SLIME* slime = GetSlime();
	slime->stand_Ltexture = LoadTexture("data/TEXTURE/enemy/slime/stand/stand_R.png");
	slime->stand_Rtexture = LoadTexture("data/TEXTURE/enemy/slime/stand/stand_L.png");
	slime->walk_Rtexture = LoadTexture("data/TEXTURE/enemy/slime/walk/walk_R.png");
	slime->walk_Ltexture = LoadTexture("data/TEXTURE/enemy/slime/walk/walk_L.png");
	slime->throw_Ltexture = LoadTexture("data/TEXTURE/enemy/slime/throw/throw_R.png");
	slime->throw_Rtexture = LoadTexture("data/TEXTURE/enemy/slime/throw/throw_L.png");
	slime->damage_Ltexture = LoadTexture("data/TEXTURE/enemy/slime/damage/damage_R.png");
	slime->damage_Rtexture = LoadTexture("data/TEXTURE/enemy/slime/damage/damage_L.png");
	SLIMEHP* slimehp = GetSlimeHp();
	slimehp->frametexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpframe.png");
	slimehp->gaugegreentexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpgreen.png");
	slimehp->gaugeredtexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpred.png");

	//-----デリーター
	DELETER* deleter = GetDeleter();
	deleter->stand_Ltexture = LoadTexture("data/TEXTURE/enemy/Deleter/stand/stand_R.png");
	deleter->stand_Rtexture = LoadTexture("data/TEXTURE/enemy/Deleter/stand/stand_L.png");
	deleter->walk_Ltexture = LoadTexture("data/TEXTURE/enemy/Deleter/walk/walk_R.png");
	deleter->walk_Rtexture = LoadTexture("data/TEXTURE/enemy/Deleter/walk/walk_L.png");
	deleter->throw_Ltexture = LoadTexture("data/TEXTURE/enemy/Deleter/throw/throw_R.png");
	deleter->throw_Rtexture = LoadTexture("data/TEXTURE/enemy/Deleter/throw/throw_L.png");
	deleter->catch_Ltexture = LoadTexture("data/TEXTURE/enemy/Deleter/catch/catch_R.png");
	deleter->catch_Rtexture = LoadTexture("data/TEXTURE/enemy/Deleter/catch/catch_L.png");
	deleter->damage_Ltexture = LoadTexture("data/TEXTURE/enemy/Deleter/damage/damage_R.png");
	deleter->damage_Rtexture = LoadTexture("data/TEXTURE/enemy/Deleter/damage/damage_L.png");
	deleter->deathtexture = LoadTexture("data/TEXTURE/enemy/firewall/death/death.png");
	DELETERHP* deleterhp = GetDeleterHp();
	deleterhp->frametexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpframe.png");
	deleterhp->gaugegreentexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpgreen.png");
	deleterhp->gaugeredtexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpred.png");

	//-----ファイアーウォール
	FIREWALL* firewall = GetFireWall();
	firewall->stand_Ltexture = LoadTexture("data/TEXTURE/enemy/firewall/stand/stand_R.png");
	firewall->stand_Rtexture = LoadTexture("data/TEXTURE/enemy/firewall/stand/stand_L.png");
	firewall->walk_Ltexture = LoadTexture("data/TEXTURE/enemy/firewall/walk/walk_R.png");
	firewall->walk_Rtexture = LoadTexture("data/TEXTURE/enemy/firewall/walk/walk_L.png");
	firewall->catch_Ltexture = LoadTexture("data/TEXTURE/enemy/firewall/catch/catch_R.png");
	firewall->catch_Rtexture = LoadTexture("data/TEXTURE/enemy/firewall/catch/catch_L.png");
	firewall->throw_Ltexture = LoadTexture("data/TEXTURE/enemy/firewall/throw/throw_R.png");
	firewall->throw_Rtexture = LoadTexture("data/TEXTURE/enemy/firewall/throw/throw_L.png");
	firewall->damage_Ltexture = LoadTexture("data/TEXTURE/enemy/firewall/damage/damage_R.png");
	firewall->damage_Rtexture = LoadTexture("data/TEXTURE/enemy/firewall/damage/damage_L.png");
	firewall->deathtexture = LoadTexture("data/TEXTURE/enemy/firewall/death/death.png");
	FIREWALLHP* firewallhp = GetFireWallHp();
	firewallhp->frametexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpframe.png");
	firewallhp->gaugegreentexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpgreen.png");
	firewallhp->gaugeredtexture = LoadTexture("data/TEXTURE/enemy/hp/enemy_hpred.png");

	ENEMY_AURA* enemy_aura = GetEnemyAura();
	enemy_aura->texture = LoadTexture("data/TEXTURE/enemy/Aura.png");
}