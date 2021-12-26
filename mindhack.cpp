//�X�L��_�}�C���h�n�b�N���� [mindhack.cpp]
#include "mindhack.h"
//�V�X�e��.h
#include "input.h"
//�G�l�~�[.h
#include "firewall.h"
#include "slime.h"

#include "player.h"
#include "bugincrease.h"
#include "catch.h"
#include "reverse.h"

#include "skillrandom.h"
#include "map_point.h"

//-----�}�N����`
#define mindhacktime 360		//6s��

//-----�v���g�^�C�v�錾
MINDHACK mindhack;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitMindhack(void)
{
	mindhack.use = false;
	mindhack.timeflag = false;
	mindhack.time = 0.0f;
	mindhack.usegauge = 40;

	return S_OK;
}

//-----�}�C���h�n�b�N����
void _Mindhack(void)
{
	PLAYER* player = GetPlayer();
	FIREWALL* firewall = GetFireWall();
	SLIME* slime = GetSlime();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();
	REVERSE* reverse = GetReverse();
	MAP_PLAYER* map_player = GetMapPlayer();

	//�����_����4���o����A6s�ԓG���s���s�\�ɂȂ�
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 4 && random[i].active == true && mindhack.use == false)
		{
			mindhack.timeflag = true;
			bug->gaugesize.x = bug->gaugesize.x + mindhack.usegauge * bug->gaugeonce;
			mindhack.use = true;
		}
	}
	//�X�L���g�p6s��ɂ��Ƃɖ߂�
	if (mindhack.timeflag == true)
	{
		mindhack.time = mindhack.time + 1.0f;
		if (GetKeyboardPress(DIK_W))	//��
		{
			if (map_player->encount == 1)
			{
				if (reverse->use == false)
					slime->pos.y -= player->move.y;
				if (reverse->use == true)
					slime->pos.y += player->move.y;
			}
			if (map_player->encount == 2)
			{
				if (reverse->use == false)
					firewall->pos.y -= player->move.y;
				if (reverse->use == true)
					firewall->pos.y += player->move.y;
			}
		}
		if (GetKeyboardPress(DIK_S))	//��
		{
			if (map_player->encount == 1)
			{
				if (reverse->use == false)
					slime->pos.y += player->move.y;
				if (reverse->use == true)
					slime->pos.y -= player->move.y;
			}
			if (map_player->encount == 2)
			{
				if (reverse->use == false)
					firewall->pos.y += player->move.y;
				if (reverse->use == true)
					firewall->pos.y -= player->move.y;
			}
		}
		if (GetKeyboardPress(DIK_A))	//��
		{
			if (map_player->encount == 1)
			{
				if (reverse->use == false)
					slime->pos.x -= player->move.x;
				if (reverse->use == true)
					slime->pos.x += player->move.x;

				slime->rotate = 2;		//�������ɍX�V
			}
			if (map_player->encount == 2)
			{
				if (reverse->use == false)
					firewall->pos.x -= player->move.x;
				if (reverse->use == true)
					firewall->pos.x += player->move.x;

				firewall->rotate = 2;		//�������ɍX�V
				firewall->walktextureflag = true;		//�e�N�X�`���̐؂�ւ�
			}
		}
		if (GetKeyboardPress(DIK_D))	//�E
		{
			if (map_player->encount == 1)
			{
				if (reverse->use == false)
					slime->pos.x += player->move.x;
				if (reverse->use == true)
					slime->pos.x -= player->move.x;

				slime->rotate = 3;		//�E�����ɍX�V
			}
			if (map_player->encount == 2)
			{
				if (reverse->use == false)
					firewall->pos.x += player->move.x;
				if (reverse->use == true)
					firewall->pos.x -= player->move.x;

				firewall->rotate = 3;		//�E�����ɍX�V
				firewall->walktextureflag = true;		//�e�N�X�`���̐؂�ւ�
			}
		}
	}

	if (mindhack.time > mindhacktime)
	{
		mindhack.timeflag = false;
		mindhack.time = 0.0f;
		mindhack.use = false;
	}
}