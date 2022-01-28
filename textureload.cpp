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
#include "map_bg.h"
#include "map_line.h"
#include "map_player.h"
#include "map_point.h"

//-----ゲーム背景
#include "bg.h"

//-----エネミー
#include "slime.h"
#include "slime_hp.h"
#include "firewall.h"
#include "firewall_hp.h"
#include "enemy_aura.h"

//-----チュートリアル
#include "tutorial.h"
#include "tutorial_map.h"

//-----スキル
#include "barrier.h"
#include "baseball.h"
#include "Billiards.h"
#include "otoshiana.h"

#include "player_powerup.h"
#include "player_regen.h"
#include "player_speedup.h"
#include "rockcreate.h"
#include "slowarea.h"
#include "timestop.h"
#include "warp.h"

//-----名前
#include "name_input.h"
#include "name_keyboard.h"
#include "name_bg.h"

//-----タイトル
#include "title_bg.h"
#include "title_select.h"
#include "title_continue.h"
#include "title_exit.h"
#include "title_gamestart.h"
#include "title_option.h"
#include "title_ranking.h"
#include "title_teamname.h"


#include "screencrack.h"
#include "enemybreak.h"

#include "anten.h"
#include "create.h"
#include "venom.h"

#include "map_hack.h"

#include "avatar.h"
#include "dougyousya.h"
#include "hujyou.h"
#include "kasoukenkyuukuukan.h"
#include "mined.h"
#include "server_recovery.h"
#include "tosyokann.h"
#include "yomigaeru.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数


void TextureLoad()
{
	YOMIGAERU* yomigaeru = GetYomi();
	yomigaeru->texture = LoadTexture("data/TEXTURE/event_bg/yomigaeru_bg.png");
	YOMIGAERUPOINT* yomigaerupoint = GetPomiPoint();
	yomigaerupoint->texture = LoadTexture("data/TEXTURE/rest_frame.png");

	TOSYOKANN* tosyokann = GetTosyo();
	tosyokann->texture = LoadTexture("data/TEXTURE/event_bg/tosyokann_bg.png");
	TOSYOKANNPOINT* tosyokannpoint = GetTosyPoint();
	tosyokannpoint->texture = LoadTexture("data/TEXTURE/rest_frame.png");

	SERVER_RECOVERY* server_recovery = GetServer();
	SERVER_POINT* server_point = GetSuverPoint();
	server_recovery->texture = LoadTexture("data/TEXTURE/server_recovery_bg.png");
	server_point->texture = LoadTexture("data/TEXTURE/rest_frame.png");

	MINED* mined = GetMined();
	mined->texture = LoadTexture("data/TEXTURE/event_bg/mined_bg.png");
	MINEDPOINT* minedpoint = GetMinesPoint();
	minedpoint->texture = LoadTexture("data/TEXTURE/rest_frame.png");

	KASOU* kasou = GetKasou();
	kasou->texture = LoadTexture("data/TEXTURE/kasou.png");
	KASOUPOINT* kasoupoint = GetKasouPoint();
	kasoupoint->texture = LoadTexture("data/TEXTURE/rest_frame.png");

	HUJYOU* hujyou = GetHujyou();
	hujyou->texture = LoadTexture("data/TEXTURE/event_bg/hujyou_bg.png");
	HUJYOUPOINT* hujyoupoint = GetHujyouPoint();
	hujyoupoint->texture = LoadTexture("data/TEXTURE/rest_frame.png");

	DOUGYOUSYA* dougyousya = GetDougyousya();
	dougyousya->texture = LoadTexture("data/TEXTURE/event_bg/dougyousya_bg.png");
	DOUGYOUSYAPOINT* dougyousyapoint = GetDougyousyaPoint();
	dougyousyapoint->texture = LoadTexture("data/TEXTURE/rest_frame.png");

	AVATAR* avatar = GetAvaret();
	AVATARPOINT* avatarpoint = GetAvatarPoint();
	avatarpoint->texture = LoadTexture("data/TEXTURE/rest_frame.png");
	avatar->texture = LoadTexture("data/TEXTURE/event_bg/avatar_bg.png");


	MAP_HACK* map_hack = GetMapHack();
	map_hack->texture = LoadTexture("data/TEXTURE/hackingmenu/hackingmenu.png");
	map_hack->frametexture = LoadTexture("data/TEXTURE/bugframe.png");

	ANTEN* anten = GetAnten();
	anten->texture = LoadTexture("data/TEXTURE/anten.png");
	CREATETEXTURE* createtexture = GetCreateTexture();
	createtexture->texture = LoadTexture("data/TEXTURE/Rock.png");
	VENOM* venom = GetVenom();
	venom->texture = LoadTexture("data/TEXTURE/Venom.png");

	CRACK* crack = GetCrack();
	crack->texture = LoadTexture("data/TEXTURE/buggauge/screencrack.png");

	ENEMYBREAK* enemybreak = GetEnemyBreak();
	enemybreak->texture = LoadTexture("data/TEXTURE/result.png");
	enemybreak->skilltexture = LoadTexture("data/TEXTURE/skill/skill.png");
	GETGOLDNUM* getgoldnum = GetGoldNum();
	getgoldnum->texture = LoadTexture("data/TEXTURE/number.png");

	//-----マップ
	MAP_LINE* map_line = GetMapLine();
	map_line->texture1 = LoadTexture("data/TEXTURE/map/mapline_1.png");
	map_line->texture2 = LoadTexture("data/TEXTURE/map/mapline_2.png");
	map_line->texture3 = LoadTexture("data/TEXTURE/map/mapline_3.png");
	map_line->texture4 = LoadTexture("data/TEXTURE/map/mapline_4.png");
	MAP_PLAYER* map_player = GetMapPlayer();
	map_player->texture = LoadTexture("data/TEXTURE/map_player.png");
	map_player->circletexture = LoadTexture("data/TEXTURE/map/circle.png");
	MAP_SB* map_sb = GetMapSB();
	map_sb->texture = LoadTexture("data/TEXTURE/map/map_point.png");



	//-----タイトル
	TITLE_BG* title_bg_white = GetTitleBG();
	TITLE_BG* title_bg_black = GetTitleBG();
	TITLE_BG* title_bg_game = GetTitleBG();
	title_bg_white->texture = LoadTexture("data/TEXTURE/fade_white.png");
	title_bg_black->texture = LoadTexture("data/TEXTURE/test/black.png");
	title_bg_game->texture = LoadTexture("data/TEXTURE/title/title.png");
	TITLE_SELECT* title_select = GetTitleSelect();
	title_select->texture = LoadTexture("data/TEXTURE/title/select.png");
	TITLE_CONTINUE* title_continue = GetTitleContinue();
	title_continue->texture = LoadTexture("data/TEXTURE/title/continue.png");
	TITLE_EXIT* title_exit = GetTitleExit();
	title_exit->texture = LoadTexture("data/TEXTURE/title/exit.png");
	TITLE_START* title_start = GetTitleStart();
	title_start->texture = LoadTexture("data/TEXTURE/title/gamestart.png");
	TITLE_OPTION* title_option = GetTitleOption();
	title_option->texture = LoadTexture("data/TEXTURE/title/option.png");
	TITLE_RANKING* title_ranking = GetTitleRanking();
	title_ranking->texture = LoadTexture("data/TEXTURE/title/ranking.png");
	TITLE_TEAMNAME* title_teamname = GetTitleTeamName();
	title_teamname->texture = LoadTexture("data/TEXTURE/title/team.png");


	//-----名前
	NAME_INPUTFRAME* name_inputframe = GetNameInput();
	name_inputframe->texture = LoadTexture("data/TEXTURE/rest_frame.png");
	name_inputframe->wardtexture = LoadTexture("data/TEXTURE/name/ward.png");
	NAME_KEYBOARD* name_keyboard = GetNameKeyboard();
	name_keyboard->texture = LoadTexture("data/TEXTURE/name/keyboard.png");
	NAME_BG* name_bg = GetNameBG();
	name_bg->texture = LoadTexture("data/TEXTURE/name/bg.png");

	//-----スキル
	BARRIER* barrier = GetBarrier();
	barrier->texture = LoadTexture("data/TEXTURE/barrier.png");
	BASEBALL* baseball = GetBaseball();
	baseball->texture = LoadTexture("data/TEXTURE/bat.png");
	BILLIARDS* billiards = Getilliards();
	billiards->texture = LoadTexture("data/TEXTURE/cuestick.png");
	OTOSIANA* otoshiana = GetOtosiana();
	otoshiana->texture = LoadTexture("data/TEXTURE/otosiana.png");
	POWERUP_ANIME* powerup_anime = GetPowerupAnime();
	powerup_anime->texture = LoadTexture("data/TEXTURE/skill/effect/Powerup.png");
	REGEN_ANIME* regen_anime = GetRegen();
	regen_anime->texture = LoadTexture("data/TEXTURE/skill/effect/Regen.png");
	SPEEDUP_ANIME* sppedup_anime = GetSpeedup();
	sppedup_anime->texture = LoadTexture("data/TEXTURE/skill/effect/Speedup.png");
	GANSEKI* ganseki = GetGanseki();
	ganseki->texture = LoadTexture("data/TEXTURE/Rock.png");
	SLOWAREA* slowarea = GetSlowarea();
	slowarea->texture = LoadTexture("data/TEXTURE/slow.png");
	TIMESTOP* timestop = GetTimestop();
	timestop->texture = LoadTexture("data/TEXTURE/Timestop.png");
	WARP* warp = GetWarp();
	warp->texture = LoadTexture("data/TEXTURE/circle.png");


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
	MAP_BG* map_bg = GetMapBG();
	map_bg->texture = LoadTexture("data/TEXTURE/map/bg.jpg");

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