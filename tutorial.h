//�`���[�g���A������ [tutorial.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	bool tutorialflag;
}TUTORIAL;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	bool drawflag;
}TUTORIAL_GAME;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	bool drawflag;
}TUTORIAL_SKILL;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	bool drawflag;
	float time;
}TUTORIAL_IDOU;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	bool drawflag;
	bool throwflag;
	bool catchflag;
}TUTORIAL_NAGE;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	bool drawflag;
	int skillusenum;
	bool reloadflag;
}TUTORIAL_SUKILL;

//-----�v���g�^�C�v�錾
HRESULT InitTutorial(void);
void UninitTutorial(void);
void UpdateTutorial(void);
void DrawTutorial(void);
TUTORIAL* GetTutorial(void);

TUTORIAL_GAME* GetTutorialGame();
TUTORIAL_SKILL* GetTutorialSkill();
TUTORIAL_IDOU* GetTutorialIdou();
TUTORIAL_NAGE* GetTutorialNage();
TUTORIAL_SUKILL* GetTutorialSukill();