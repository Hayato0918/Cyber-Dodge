/*------------------------------------------
[ �N���G�C�g [ create.cpp ] ]
-------------------------------------------*/
#include "create.h"
#include "input.h"
#include "Texture.h"
#include "sprite.h"

#include "bugincrease.h"

//-----�}�N����`
#define createtime 420		//�L���b�`������o������
#define createnumber 3		//��̌�

//-----�v���g�^�C�v�錾
CREATE create[createnumber];

//-----�O���[�o���ϐ�

HRESULT InitCreate(void)
{
	for (int i = 0; i < createnumber; i++)
	{
		create[i].pos = D3DXVECTOR2(0.0f, 0.0f);
		create[i].size = D3DXVECTOR2(120.0f, 160.0f);
		create[i].texture = LoadTexture("data/TEXTURE/Rock.png");
		create[i].use = false;
		create[i].time = 0.0f;
		create[i].timeflag = false;
	}

	return S_OK;
}

void _Create(void)
{
	BUG* bug = GetBugIncrease();

	for (int i = 0; i < createnumber; i++)
	{
		//�o�O�Q�[�W�����܂�ƁA7�b�ԃL���b�`���o���Ȃ��Ȃ�B
		if (bug->gaugesize.x >= 100)
		{
			create[i].time = 0.0f;
			if (create[i].use == false)
			{
				create[i].timeflag = true;
				create[i].use = true;

				//���W�����_���ɓ���鏈��
				int a = create[i].size.x * 2;
				create[i].pos.x = rand() % (SCREEN_WIDTH - 15 - a) + 15 + create[i].size.x;
				create[i].pos.y = rand() % (SCREEN_HEIGHT - 420 - 120) - create[i].size.y / 2 + 420;
			}
		}

		if (create[i].timeflag == true)
		{
			create[i].time = create[i].time + 1.0f;
		}

		//7�b��ɂ��Ƃɖ߂�
		if (create[i].time > createtime)
		{
			create[i].timeflag = false;
			create[i].time = 0.0f;

			create[i].use = false;
		}
	}
}

void DrawCreate(void)
{
	for (int i = 0; i < createnumber; i++)
	{
		if (create[i].use == true)
		{
			DrawSpriteColor(create[i].texture, create[i].pos.x, create[i].pos.y, create[i].size.x, create[i].size.y, 0.0f, 0.0f, 1.0f, 1.0f,
				D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		}
	}
}

CREATE* GetCreate(int number)
{
	if (number < 0 || createnumber - 1 < number)
	{
		return &create[0];
	}

	return &create[number];
}


