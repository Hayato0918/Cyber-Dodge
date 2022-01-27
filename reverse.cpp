//�v���C���[���씽�] [ reverse.cpp ]
#include "reverse.h"
#include "input.h"
#include "Texture.h"
#include "sprite.h"

#include "player.h"
#include "bugrandom.h"
#include "bugincrease.h"
#include "bugrandom.h"

//-----�v���g�^�C�v�錾
REVERSE reverse;

//-----����������
HRESULT InitReverse(void)
{
	reverse.use = false;

	return S_OK;
}

//-----�v���C���[���]����
void _Reverse(void)
{
	BUG* bug = GetBugIncrease();
	BUGRANDOM* bugrandom = GetBugRandom();

	//�o�O�Q�[�W��100�ȏ�ɂȂ�����v���C���[�̑���𔽓]������
	if (bugrandom->code == 7 && bug->breakflag == true && reverse.use == false)
	{
		reverse.use = true;
	}

	//�o�O�Q�[�W��50��菬�����Ȃ����瑀������Ƃɖ߂�
	if (bug->breakflag == false && reverse.use == true)
	{
		reverse.use = false;
		bugrandom->code = (rand() % bugrandom->num) + 1;
	}

}

//-----�\���̃|�C���^�擾����
REVERSE* GetReverse(void)
{
	return &reverse;
}