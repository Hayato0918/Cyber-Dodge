//�`���[�g���A������ [tutorial.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{

}TUTORIAL;

//-----�v���g�^�C�v�錾
HRESULT InitTutorial(void);
void UninitTutorial(void);
void UpdateTutorial(void);
void DrawTutorial(void);
TUTORIAL* GetTutorial(void);