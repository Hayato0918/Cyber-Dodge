//������� [escape.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	bool intervalflag;	//����̃C���^�[�o�����Ǘ�����t���O
	float intervaltime;	//����̃C���^�[�o���b���Ǘ�����ϐ�
}ESCAPE;

//-----�v���g�^�C�v�錾
HRESULT InitEscape(void);
void _Escape(void);