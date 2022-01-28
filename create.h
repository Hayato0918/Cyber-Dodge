/*------------------------------------------
[ �N���G�C�g [ create.h ] ]
-------------------------------------------*/
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;	//���W
	D3DXVECTOR2 size;	//�傫��
	bool use;			//�o�O�������Ǘ�����t���O
	float time;			//�o�O�̓K�p���Ԃ��Ǘ�����ϐ�
	bool timeflag;		//�o�O�̓K�p���Ԃ��Ǘ�����t���O
}CREATE;

typedef struct
{
	int texture;
}CREATETEXTURE;

HRESULT InitCreate(void);
void _Create(void);
void DrawCreate(void);
CREATE* GetCreate(int number);
CREATETEXTURE* GetCreateTexture();