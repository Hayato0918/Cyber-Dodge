//���O����_���͏ꏊ���� [name_input.cpp]
#include "name_input.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "Texture.h"
#include "sprite.h"
#include "sound.h"

#include "name_keyboard.h"

//-----�萔��`
#define NAME_INPUTWARD_NUM 8

//-----�\���̐錾

//-----�v���g�^�C�v�錾
NAME_INPUTFRAME name_inputframe;
NAME_INPUTWARD name_inputward[NAME_INPUTWARD_NUM];

//-----�O���[�o���ϐ��̒�`


//-----�������֐�
HRESULT InitNameInput(void)
{
	float wardx = 0.f;

	name_inputframe.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.188f, SCREEN_HEIGHT * 0.122f);	//1600:900��300,100
	name_inputframe.size = D3DXVECTOR2(SCREEN_WIDTH * 0.625f, SCREEN_HEIGHT * 0.222f);		//1600:900��1000,200

	for (int i = 0; i < NAME_INPUTWARD_NUM; i++)
	{
		name_inputward[i].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.25f + wardx, SCREEN_HEIGHT * 0.166f);	//1600:900��400 + wardx,150
		name_inputward[i].size = D3DXVECTOR2(SCREEN_WIDTH * 0.0625f, SCREEN_HEIGHT * 0.111f);		//1600:900��100,100
		name_inputward[i].u = 0.f;
		name_inputward[i].v = 0.f;
		name_inputward[i].uw = 0.037037037f;
		name_inputward[i].vh = 1.f;
		name_inputward[i].drawflag = false;
		wardx = wardx + SCREEN_WIDTH * 0.0625f;
	}

	return S_OK;
}

//-----�I�������֐�
void UninitNameInput(void)
{

}

//-----�X�V����������֐�
void UpdateNameInput(void)
{



}

//-----�`�揈���֐�
void DrawNameInput(void)
{
	//�O�g�̕`��
	DrawSpriteLeftTop(name_inputframe.texture, name_inputframe.pos.x, name_inputframe.pos.y, name_inputframe.size.x, name_inputframe.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	//�����̕`��
	for (int i = 0; i < NAME_INPUTWARD_NUM; i++)
	{
		if(name_inputward[i].drawflag == true)
		DrawSpriteLeftTop(name_inputframe.wardtexture, name_inputward[i].pos.x, name_inputward[i].pos.y, name_inputward[i].size.x, name_inputward[i].size.y,
			name_inputward[i].u, name_inputward[i].v, name_inputward[i].uw, name_inputward[i].vh);
	}
}

NAME_INPUTWARD* GetNameInputWard()
{
	return &name_inputward[0];
}

NAME_INPUTFRAME* GetNameInput()
{
	return &name_inputframe;
}