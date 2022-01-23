//�v���C���[�_���[�W�v�Z���� [player_damage.cpp]
#include "player_damage.h"
#include "player.h"
#include "player_hp.h"
//�G�l�~�[.h
#include "slime.h"
#include "deleter.h"
#include "firewall.h"

#include "ball.h"
#include "catch.h"
//�X�L��.h
#include "barrier.h"
#include "autocatch.h"

#include "sound.h"
#include "soundvolume_select.h"

int hitsound;

//-----�X���C������̃_���[�W����
void Player_SlimeDamage()
{
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();

	hitsound = LoadSound("data/SE/hit.wav");
	SetVolume(hitsound, soundvolume_select[1].count * 0.1f + 0.5f);

	PLAYER* player = GetPlayer();
	PLAYERHP* hp = GetPlayerHp();
	BARRIER* barrier = GetBarrier();
	BALL* ball = GetBall();
	SLIME* slime = GetSlime();
	AUTO* auto_c = GetAuto();
	CATCH* Catch = GetCatch();

	//-----�X���C������̃_���[�W����
	if (barrier->drawflag == false)
	{
		if (ball->playerhitflag == true)
		{
			if (player->rotate == 3)
			{
				if (player->pos.x < ball->pos.x + ball->size.x && player->pos.x + player->size.x * 0.8f > ball->pos.x)
				{
					if (player->pos.y + player->size.y * 0.2f < ball->pos.y + ball->size.y && player->pos.y + player->size.y * 0.8f > ball->pos.y)
					{
						//�X�L���F�I�[�g�L���b�`���@�\���Ă��Ȃ��ꍇ
						if (auto_c->auto_catchflag == false)
						{
							PlaySound(hitsound, 0.5f);
							player->damagetextureflag = true;
							hp->gaugesize.x = hp->gaugesize.x - (slime->atk - player->def) * 3.2f;
							hp->pos.x = hp->pos.x + (slime->atk - player->def) * 3.2f;
							ball->playerhitflag = false;
						}
						//�X�L���F�I�[�g�L���b�`���@�\���Ă���ꍇ
						if (auto_c->auto_catchflag == true && auto_c->auto_catch == true)
						{
							Catch->playerflag = true;
							Catch->playerintervalflag = true;
							ball->playerhitflag = false;
						}
					}
				}
			}

			if (player->rotate == 2)
			{
				if (player->pos.x < ball->pos.x + ball->size.x && player->pos.x + player->size.x * 0.5f > ball->pos.x)
				{
					if (player->pos.y + player->size.y * 0.2f < ball->pos.y + ball->size.y && player->pos.y + player->size.y * 0.8f > ball->pos.y)
					{
						//�X�L���F�I�[�g�L���b�`���@�\���Ă��Ȃ��ꍇ
						if (auto_c->auto_catchflag == false)
						{
							PlaySound(hitsound, 0.5f);
							player->damagetextureflag = true;
							hp->gaugesize.x = hp->gaugesize.x - (slime->atk - player->def);
							hp->pos.x = hp->pos.x + (slime->atk - player->def);
							ball->playerhitflag = false;
						}
						//�X�L���F�I�[�g�L���b�`���@�\���Ă���ꍇ
						if (auto_c->auto_catchflag == true && auto_c->auto_catch == true)
						{
							Catch->playerflag = true;
							Catch->playerintervalflag = true;
							ball->playerhitflag = false;
						}
					}
				}
			}
		}
	}
}

//-----�f���[�^�[����̃_���[�W����
void Player_DeleterDamage()
{
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();

	hitsound = LoadSound("data/SE/hit.wav");
	SetVolume(hitsound, soundvolume_select[1].count * 0.1f + 0.5f);

	PLAYER* player = GetPlayer();
	PLAYERHP* hp = GetPlayerHp();
	BARRIER* barrier = GetBarrier();
	BALL* ball = GetBall();
	AUTO* auto_c = GetAuto();
	CATCH* Catch = GetCatch();
	DELETER* deleter = GetDeleter();

	//-----�f���[�^�[����̃_���[�W����
	if (barrier->drawflag == false)
	{
		if (ball->playerhitflag == true)
		{
			if (player->rotate == 3)
			{
				if (player->pos.x < ball->pos.x + ball->size.x && player->pos.x + player->size.x * 0.8f > ball->pos.x)
				{
					if (player->pos.y + player->size.y * 0.2f < ball->pos.y + ball->size.y && player->pos.y + player->size.y * 0.8f > ball->pos.y)
					{
						//�X�L���F�I�[�g�L���b�`���@�\���Ă��Ȃ��ꍇ
						if (auto_c->auto_catchflag == false)
						{
							PlaySound(hitsound, 0.5f);
							player->damagetextureflag = true;
							hp->gaugesize.x = hp->gaugesize.x - (deleter->atk - player->def) * 3.2f;
							hp->pos.x = hp->pos.x + (deleter->atk - player->def) * 3.2f;
							ball->playerhitflag = false;
						}
						//�X�L���F�I�[�g�L���b�`���@�\���Ă���ꍇ
						if (auto_c->auto_catchflag == true && auto_c->auto_catch == true)
						{
							Catch->playerflag = true;
							Catch->playerintervalflag = true;
							ball->playerhitflag = false;
						}
					}
				}
			}

			if (player->rotate == 2)
			{
				if (player->pos.x < ball->pos.x + ball->size.x && player->pos.x + player->size.x * 0.5f > ball->pos.x)
				{
					if (player->pos.y + player->size.y * 0.2f < ball->pos.y + ball->size.y && player->pos.y + player->size.y * 0.8f > ball->pos.y)
					{
						//�X�L���F�I�[�g�L���b�`���@�\���Ă��Ȃ��ꍇ
						if (auto_c->auto_catchflag == false)
						{
							PlaySound(hitsound, 0.5f);
							player->damagetextureflag = true;
							hp->gaugesize.x = hp->gaugesize.x - (deleter->atk - player->def) * 3.2f;
							hp->pos.x = hp->pos.x + (deleter->atk - player->def) * 3.2f;
							ball->playerhitflag = false;
						}
						//�X�L���F�I�[�g�L���b�`���@�\���Ă���ꍇ
						if (auto_c->auto_catchflag == true && auto_c->auto_catch == true)
						{
							Catch->playerflag = true;
							Catch->playerintervalflag = true;
							ball->playerhitflag = false;
						}
					}
				}
			}
		}
	}
}

//-----�t�@�C�A�[�E�H�[������̃_���[�W����
void Player_FireWallDamage()
{
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();

	hitsound = LoadSound("data/SE/hit.wav");
	SetVolume(hitsound, soundvolume_select[1].count * 0.1f + 0.5f);

	PLAYER* player = GetPlayer();
	PLAYERHP* hp = GetPlayerHp();
	BARRIER* barrier = GetBarrier();
	BALL* ball = GetBall();
	AUTO* auto_c = GetAuto();
	CATCH* Catch = GetCatch();
	FIREWALL* firewall = GetFireWall();

	//-----�t�@�C�A�[�E�H�[������̃_���[�W����
	if (barrier->drawflag == false)
	{
		if (ball->playerhitflag == true)
		{
			if (player->rotate == 3)
			{
				if (player->pos.x < ball->pos.x + ball->size.x && player->pos.x + player->size.x * 0.8f > ball->pos.x)
				{
					if (player->pos.y + player->size.y * 0.2f < ball->pos.y + ball->size.y && player->pos.y + player->size.y * 0.8f > ball->pos.y)
					{
						//�X�L���F�I�[�g�L���b�`���@�\���Ă��Ȃ��ꍇ
						if (auto_c->auto_catchflag == false)
						{
							PlaySound(hitsound, 0.5f);
							player->damagetextureflag = true;
							hp->gaugesize.x = hp->gaugesize.x - (firewall->atk - player->def) * 3.2f;
							hp->pos.x = hp->pos.x + (firewall->atk - player->def) * 3.2f;
							ball->playerhitflag = false;
						}
						//�X�L���F�I�[�g�L���b�`���@�\���Ă���ꍇ
						if (auto_c->auto_catchflag == true && auto_c->auto_catch == true)
						{
							Catch->playerflag = true;
							Catch->playerintervalflag = true;
							ball->playerhitflag = false;
						}
					}
				}
			}

			if (player->rotate == 2)
			{
				if (player->pos.x < ball->pos.x + ball->size.x && player->pos.x + player->size.x * 0.5f > ball->pos.x)
				{
					if (player->pos.y + player->size.y * 0.2f < ball->pos.y + ball->size.y && player->pos.y + player->size.y * 0.8f > ball->pos.y)
					{
						//�X�L���F�I�[�g�L���b�`���@�\���Ă��Ȃ��ꍇ
						if (auto_c->auto_catchflag == false)
						{
							PlaySound(hitsound, 0.5f);
							player->damagetextureflag = true;
							hp->gaugesize.x = hp->gaugesize.x - (firewall->atk - player->def) * 3.2f;
							hp->pos.x = hp->pos.x + (firewall->atk - player->def) * 3.2f;
							ball->playerhitflag = false;
						}
						//�X�L���F�I�[�g�L���b�`���@�\���Ă���ꍇ
						if (auto_c->auto_catchflag == true && auto_c->auto_catch == true)
						{
							Catch->playerflag = true;
							Catch->playerintervalflag = true;
							ball->playerhitflag = false;
						}
					}
				}
			}
		}
	}
}