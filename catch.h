//�L���b�`���� [catch.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	D3DXCOLOR color;
	bool flag;	//�L���b�`��������Ă��邩���Ǘ�����t���O
	bool intervalflag;	//�L���b�`�̃C���^�[�o�����Ǘ�����t���O
	float intervaltime;	//�L���b�`�̃C���^�[�o���b���Ǘ�����ϐ�
	float coltime;	//�L���b�`�̓����蔻�莞�Ԃ��Ǘ�����ϐ�
	bool colflag;	//�{�[�����L���b�`���Ă��邩���Ǘ�����t���O
}CATCH;

//-----�v���g�^�C�v�錾
HRESULT InitCatch(void);
void UninitCatch(void);
void UpdateCatch(void);
void DrawCatch(void);
void _Catch(void);