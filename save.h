//�Z�[�u���� [save.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	int hp = 100;
	int atk = 100;
	int def = 100;
	int gold = 100;
}SAVE;

//-----�v���g�^�C�v�錾
void Save(void);
void Load(void);