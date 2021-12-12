//�X�L�������_�� [skillrandom.cpp]
#include "skillrandom.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include <stdlib.h>
#include <time.h>

//-----�}�N����`
// 
//-----�v���g�^�C�v�錾
SKILL skill;
RANDOM random[40];

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitRandom(void)
{
	skill.usecount = 0;	//���I������Ă�X�L��
	skill.num = 14;		//�X�L���̑���
	skill.slot = 14;
	int t;

	for (int i = 0; i < skill.slot; i++)
	{
		random[i].pos = D3DXVECTOR2(100.0f - i * 10, 120.0f - i * 10);
		random[i].size = D3DXVECTOR2(90.0f, 130.0f);
		random[i].drawflag = true;

		random[i].active = false;

		do   //�d���`�F�b�N
		{
			random[i].code = (rand() % skill.num) + 1;
			for (t = 0; t < i; t++)
			{
				if (random[i].code == random[t].code)	//��肪�������������xcode������U��
					break;
			}
		} while (i != t);
	}

	//�e�X�L���Ƀ����_����code�����蓖�Ă�(�d���Ȃ�)


	return S_OK;
}

void UninitRandom(void)
{

}

void UpdateRandom(void)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < skill.slot; i++)
	{
			//���蓖�Ă�ꂽcode�ɑΉ������e�N�X�`����\��
		if (random[i].code == 1)
			random[i].texture = LoadTexture("data/TEXTURE/skill/speedup.png");
		if (random[i].code == 2)
			random[i].texture = LoadTexture("data/TEXTURE/skill/turnaround.png");
		if (random[i].code == 3)
			random[i].texture = LoadTexture("data/TEXTURE/skill/barrier.png");
		if (random[i].code == 4)
			random[i].texture = LoadTexture("data/TEXTURE/skill/baseball.png");
		if (random[i].code == 5)
			random[i].texture = LoadTexture("data/TEXTURE/skill/bigball.png");
		if (random[i].code == 6)
			random[i].texture = LoadTexture("data/TEXTURE/skill/billiards.png");
		if (random[i].code == 7)
			random[i].texture = LoadTexture("data/TEXTURE/skill/buildup.png");
		if (random[i].code == 8)
			random[i].texture = LoadTexture("data/TEXTURE/skill/catchjamming.png");
		if (random[i].code == 9)
			random[i].texture = LoadTexture("data/TEXTURE/skill/invade.png");
		if (random[i].code == 10)
			random[i].texture = LoadTexture("data/TEXTURE/skill/invincible.png");
		if (random[i].code == 11)
			random[i].texture = LoadTexture("data/TEXTURE/skill/penetration.png");
		if (random[i].code == 12)
			random[i].texture = LoadTexture("data/TEXTURE/skill/rockcreate.png");
		if (random[i].code == 13)
			random[i].texture = LoadTexture("data/TEXTURE/skill/slowarea.png");
		if (random[i].code == 14)
			random[i].texture = LoadTexture("data/TEXTURE/skill/smallplayer.png");
	}

	//�u1�v����������X�L������
	if (GetKeyboardTrigger(DIK_1) && random[skill.usecount].drawflag == true)
	{
		for (int i = 0; i < skill.slot; i++)
		{
			random[i].pos.x = random[i].pos.x + 10;
			random[i].pos.y = random[i].pos.y + 10;
		}
		random[skill.usecount].active = true;
		random[skill.usecount].drawflag = false;
		skill.usecount = skill.usecount + 1;
	}
	//�X�L����S���g���؂�����A�u2�v�������ăX�L���Ē��I
	if (GetKeyboardTrigger(DIK_2) && skill.usecount == skill.slot)
	{
		for (int i = 0; i < skill.slot; i++)
		{
			random[i].pos = D3DXVECTOR2(100.0f - i * 10, 120.0f - i * 10);
			random[i].drawflag = true;
			random[i].active = false;
		}
		skill.usecount = 0;
	}

}

void DrawRandom(void)
{
	for (int i = skill.slot - 1; i >= 0; i--)
	{
		if (random[i].drawflag == true)
			DrawSpriteLeftTop(random[i].texture, random[i].pos.x, random[i].pos.y, random[i].size.x, random[i].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
}

RANDOM* GetRandom()
{
	return &random[0];
}