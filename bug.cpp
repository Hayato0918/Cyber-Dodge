//�o�O�Q�[�W���� [bug.cpp]
#include "bug.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "ball.h"
#include "map_point.h"

//-----�}�N����`
#define gaugedecrease 0.2f	//�Q�[�W�̌�����
#define gaugeincrease 4.0f  //�Q�[�W������
#define gaugeincreasetime 300

//-----�v���g�^�C�v�錾
BUG bug;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBug(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	if (map_player->gamecount == 1)
	{
		bug.gaugeonce = 8;
		bug.pos = D3DXVECTOR2(105.0f, 20.0f);
		bug.framesize = D3DXVECTOR2(150.f * bug.gaugeonce, 60);
		bug.frametexture = LoadTexture("data/TEXTURE/bugframe.png");

		bug.gaugesize = D3DXVECTOR2(0.0f, bug.framesize.y);
		bug.gaugetexture = LoadTexture("data/TEXTURE/obstacle.png");
	}

	return S_OK;
}

//-----�I������
void UninitBug(void)
{

}

//-----�X�V����
void UpdateBug(void)
{
	PLAYER* player = GetPlayer();
	BALL* ball = GetBall();

	//-----�v���C���[���{�[�������������Ă��鎞�Ԃ����ȏ�ɂȂ�����A�o�O�Q�[�W�𑝂₷
	if (ball->playerhaveflag == true)
	{
		ball->playerhavetime = ball->playerhavetime + 1.0f;
		if (ball->playerhavetime >= gaugeincreasetime && bug.gaugesize.x < 150.f * bug.gaugeonce)
			bug.gaugesize.x = bug.gaugesize.x + gaugeincrease;
		else if (bug.gaugesize.x >= 150.f * bug.gaugeonce)
		{
			bug.gaugesize.x = 150.f * bug.gaugeonce;
		}
	}

	//-----���Ԍo�߂ɂ��Q�[�W�̌���
	if (ball->playerhaveflag == false || ball->playerhavetime < gaugeincreasetime)
	{
		if (bug.gaugesize.x >= 0)
			bug.gaugesize.x = bug.gaugesize.x - gaugedecrease;
	}
}

//-----�`�揈��
void DrawBug(void)
{
	//-----�o�O�Q�[�W�̕`��
	DrawSpriteLeftTop(bug.gaugetexture, bug.pos.x, bug.pos.y, bug.gaugesize.x, bug.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0f);

	//-----�o�O�Q�[�W�̘g�̕`��
	DrawSpriteLeftTop(bug.frametexture, bug.pos.x, bug.pos.y, bug.framesize.x, bug.framesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----�\���̃|�C���^�擾����
BUG* GetBug()
{
	return &bug;
}