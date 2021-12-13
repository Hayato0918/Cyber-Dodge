//�v���C���[���씽�] [ reverse.cpp ]
#include "reverse.h"
#include "input.h"
#include "Texture.h"
#include "sprite.h"

#include "player.h"
#include "bugrandom.h"
#include "bugincrease.h"

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
	if (bugrandom->code == 3 && bug->gaugesize.x >= 100 && reverse.use == false)
	{
		reverse.use = true;
	}

	//�o�O�Q�[�W��50��菬�����Ȃ����瑀������Ƃɖ߂�
	if (bug->gaugesize.x <= 80)
		reverse.use = false;

}

//-----�\���̃|�C���^�擾����
REVERSE* GetReverse(void)
{
	return &reverse;
}