//�Z�[�u���� [save.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	float hp;
	int atk;
	int def;
	int gold;

	int gamecount;
	int UDcount;

}SAVE;

//-----�v���g�^�C�v�錾
void Save(void);
void Load(void);