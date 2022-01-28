  //�o�O�Q�[�W���� [bug.cpp]
#include "bugincrease.h"
#include "texture.h"
#include "sprite.h"
#include "sound.h"

#include "player.h"
#include "ball.h"
#include "map_player.h"
#include "skillrandom.h"

#include "enemybreak.h"
#include "soundvolume_select.h"
#include "screencrack.h"

//-----�}�N����`
#define gaugedecrease 0.2f	//�Q�[�W�̌�����
#define gaugeincrease 4.0f  //�Q�[�W������
#define gaugeincreasetime 30
#define gaugedecreasetime 30

#define gaugenum 20		//�Q�[�W�̐�(�Q�[�W�ʊ��Z��1��5)

//-----�v���g�^�C�v�錾
BUG bug;
BUGGAUGE buggauge[gaugenum];
BUGNUMBER bugnumber[3];

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBugIncrease(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();

	if (map_player->gamecount == 1)
	{
		//�t���[���̐ݒ�
		bug.gaugeonce = 8;
		bug.framepos = D3DXVECTOR2(SCREEN_WIDTH * 0.09375f, SCREEN_HEIGHT * 0.0222f);	//1600:900��150:20
		bug.framesize = D3DXVECTOR2(SCREEN_WIDTH * 0.09375f * bug.gaugeonce, SCREEN_HEIGHT * 0.2444f);
		bug.breakflag = false;
		bug.breaktime = 0.f;
		bug.drawnum = 0;
		bug.decreasetime = 0.f;
		bug.decreaseflag = false;

		bug.gaugeoverflag = false;
		bug.gaugeovertime = 0.f;

		//�Q�[�W�̐ݒ�
		for (int i = 0; i < gaugenum; i++)
		{
			buggauge[i].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.231f + i * SCREEN_WIDTH * 0.025f, SCREEN_HEIGHT * 0.07222f);
			buggauge[i].size = D3DXVECTOR2(SCREEN_WIDTH * 0.0593f, SCREEN_HEIGHT * 0.07777f);
			buggauge[i].drawflag = false;
		}

		//�����̐ݒ�
		for (int i = 0; i < 3; i++)
		{
			bugnumber[i].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.53125f + i * SCREEN_WIDTH * 0.040625f , SCREEN_HEIGHT * 0.17222f);
			bugnumber[i].size = D3DXVECTOR2(SCREEN_WIDTH * 0.040625f, SCREEN_HEIGHT * 0.077777f);
			bugnumber[i].u = 0.0f;
			bugnumber[i].v = 0.0f;
			bugnumber[i].uw = 0.2f;
			bugnumber[i].vh = 0.5f;
			bugnumber[i].drawflag = false;
		}
		bugnumber[0].u = 0.2f;
		bugnumber[0].v = 0.f;
		bugnumber[0].uw = 0.2f;
		bugnumber[0].vh = 0.5f;
	}

	bug.sound = LoadSound("data/BGM/bugBGM.wav");
	bug.soundflag = false;
	SetVolume(bug.sound, soundvolume_select[0].count * 0.1f + 0.5f);

	bug.sesound = LoadSound("data/SE/Warning-Siren.wav");
	bug.sesoundflag = false;
	SetVolume(bug.sesound, soundvolume_select[1].count * 0.1f + 0.5f);

	return S_OK;
}

//-----�I������
void UninitBugIncrease(void)
{

}

//-----�X�V����
void UpdateBugIncrease(void)
{
	PLAYER* player = GetPlayer();
	BALL* ball = GetBall();
	RANDOM* random = GetRandom();
	ENEMYBREAK* enemybreak = GetEnemyBreak();
	CRACK* crack = GetCrack();

	if(bug.breakflag == false && bug.drawnum > 16)
		bug.gaugetexture = LoadTexture("data/TEXTURE/buggauge/gaugebar.png");

	if (bug.drawnum > 20)
		bug.drawnum = 20;

	if (enemybreak->drawflag == false)
	{

		//-----�v���C���[���{�[�������������Ă��鎞�Ԃ����ȏ�ɂȂ�����A�o�O�Q�[�W�𑝂₷
		if (bug.gaugeoverflag == false && bug.breakflag == false)
		{
			if (ball->playerhaveflag == true && bug.drawnum < gaugenum)
			{
				ball->playerhavetime = ball->playerhavetime + 1.0f;

				if (ball->playerhavetime >= gaugeincreasetime)
				{
					buggauge[bug.drawnum].drawflag = true;
					bug.drawnum = bug.drawnum + 1;
					ball->playerhavetime = 0.f;
				}
			}
		}

		//-----�o�O�Q�[�W��100�ɒB������A�ՊE��Ԃɂ���
		if (buggauge[19].drawflag == true)
			bug.gaugeoverflag = true;

		if (bug.gaugeoverflag == true)
			bug.gaugeovertime = bug.gaugeovertime + 1.f;

		if (bug.gaugeovertime > 0.f && bug.gaugeovertime < 10.f)
		{
			PlaySound(bug.sesound, 0.5f);
		}

		if (bug.gaugeovertime > 480.f)
		{
			buggauge[19].drawflag = false;
			bug.gaugeoverflag = false;
			bug.gaugeovertime = 0.f;
		}

		//-----�ՊE��ԂŃX�L�����g������A�o�O�Q�[�W��j�󂷂�
		/*if (bug.gaugeoverflag == true && player->skilluseflag == true && crack->bugflag == true)
			bug.breakflag = true;*/

		if (bug.breakflag == true)
			bug.breaktime = bug.breaktime + 1.f;

		if (bug.breaktime > 900.f)
		{
			bug.breakflag = false;
			StopSound(bug.sound);
			bug.breaktime = 0.f;
		}

		if (bug.breaktime > 0.f && bug.breaktime < 10.f)
		{
			PlaySound(bug.sound, -1);
		}

		if (bug.drawnum <= 1)
		{
			bugnumber[0].drawflag = false;
			bugnumber[1].drawflag = false;
			bugnumber[2].drawflag = true;
		}
		if (bug.drawnum >= 2 && bug.drawnum <= 19)
		{
			bugnumber[0].drawflag = false;
			bugnumber[1].drawflag = true;
			bugnumber[2].drawflag = true;
		}
		if (bug.drawnum > 19)
		{
			bugnumber[0].drawflag = true;
			bugnumber[1].drawflag = true;
			bugnumber[2].drawflag = true;
		}

		if (bug.drawnum > 0)
			bug.decreaseflag = true;
		if (bug.drawnum == 0)
			bug.decreaseflag = false;

		//-----���Ԍo�߂ɂ��Q�[�W�̌���
		if (bug.decreaseflag == true)
		{
			if (bug.gaugeoverflag == false && bug.breakflag == false)
			{
				if (ball->playerhaveflag == false && bug.drawnum >= 0)
				{
					bug.decreasetime = bug.decreasetime + 1.f;

					if (bug.decreasetime > gaugedecreasetime)
					{
						buggauge[bug.drawnum - 1].drawflag = false;
						bug.drawnum = bug.drawnum - 1;
						bug.decreasetime = 0.f;
						crack->bugflag = false;
					}
				}
			}
		}
	}

	//-----�Q�[�W���̐����̕`��ݒ�
	if (bug.drawnum == 0)	//0
	{
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 1)	//5
	{
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}

	if (bug.drawnum == 2)	//10
	{
		bugnumber[1].u = 0.2f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 3)	//15
	{
		bugnumber[1].u = 0.2f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 4)	//20
	{
		bugnumber[1].u = 0.4f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 5)	//25
	{
		bugnumber[1].u = 0.4f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 6)	//30
	{
		bugnumber[1].u = 0.6f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 7)	//35
	{
		bugnumber[1].u = 0.6f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 8)	//40
	{
		bugnumber[1].u = 0.8f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 9)	//45
	{
		bugnumber[1].u = 0.8f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 10)	//50
	{
		bugnumber[1].u = 0.0f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 11)	//55
	{
		bugnumber[1].u = 0.0f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 12)	//60
	{
		bugnumber[1].u = 0.2f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 13)	//65
	{
		bugnumber[1].u = 0.2f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 14)	//70
	{
		bugnumber[1].u = 0.4f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 15)	//75
	{
		bugnumber[1].u = 0.4f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 16)	//80
	{
		bugnumber[1].u = 0.6f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 17)	//85
	{
		bugnumber[1].u = 0.6f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 18)	//90
	{
		bugnumber[1].u = 0.8f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 19)	//95
	{
		bugnumber[1].u = 0.8f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 20)	//100
	{
		bugnumber[0].u = 0.2f;
		bugnumber[0].v = 0.0f;
		bugnumber[0].uw = 0.2f;
		bugnumber[0].vh = 0.5f;
		bugnumber[1].u = 0.0f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
}

//-----�`�揈��
void DrawBugIncrease(void)
{
	if (bug.breakflag == false)
	{
		//-----�o�O�Q�[�W�̕`��
		for (int i = 0; i < gaugenum; i++)
		{
			if (buggauge[i].drawflag == true)
				DrawSpriteLeftTop(bug.gaugetexture, buggauge[i].pos.x, buggauge[i].pos.y, buggauge[i].size.x, buggauge[i].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		}

		DrawSpriteLeftTop(bug.frametexture, bug.framepos.x, bug.framepos.y, bug.framesize.x, bug.framesize.y, 0.0f, 0.0f, 1.0f, 1.0f);

		//-----�����̕`��
		for (int i = 0; i < 3; i++)
		{
			if (bugnumber[i].drawflag == true)
				DrawSpriteLeftTop(bug.numbertexture, bugnumber[i].pos.x, bugnumber[i].pos.y, bugnumber[i].size.x, bugnumber[i].size.y, bugnumber[i].u, bugnumber[i].v, bugnumber[i].uw, bugnumber[i].vh);
		}
	}

	//-----�o�O�Q�[�W�̘g�̕`��
	if (bug.breakflag == true)
		DrawSpriteLeftTop(bug.breaktexture, bug.framepos.x, bug.framepos.y, bug.framesize.x, bug.framesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----�\���̃|�C���^�擾����
BUG* GetBugIncrease()
{
	return &bug;
}

BUGGAUGE* GetBugGauge()
{
	return &buggauge[0];
}