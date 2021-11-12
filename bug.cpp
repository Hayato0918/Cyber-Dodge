//�o�O�Q�[�W���� [bug.cpp]
#include "bug.h"
#include "texture.h"
#include "sprite.h"

//-----�}�N����`
#define gaugedecrease 0.2f	//�Q�[�W�̌�����

//-----�v���g�^�C�v�錾
BUG bug;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBug(void)
{
	bug.gaugeonce = 5;

	bug.pos = D3DXVECTOR2(105.0f, 20.0f);
	bug.framesize = D3DXVECTOR2(150 * bug.gaugeonce, 60.0f);
	bug.frametexture = LoadTexture("data/TEXTURE/bugframe.png");

	bug.gaugesize = D3DXVECTOR2(0.0f, bug.framesize.y);
	bug.gaugetexture = LoadTexture("data/TEXTURE/obstacle.png");

	return S_OK;
}

//-----�I������
void UninitBug(void)
{

}

//-----�X�V����
void UpdateBug(void)
{
	//-----���Ԍo�߂ɂ��Q�[�W�̌���
	if (bug.gaugesize >= 0)
		bug.gaugesize.x = bug.gaugesize.x - gaugedecrease;
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