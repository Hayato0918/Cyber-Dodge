//�x�e�}�X���� [rest.cpp]
#include "rest.h"
//�V�X�e��.h
#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"
//
#include "rest_bg.h"
#include "rest_picture.h"
#include "rest_status.h"
#include "rest_command.h"
#include "rest_exit.h"
#include "rest_select.h"

#include "player_hp.h"

REST rest;
RESTPOINT restpoint;

HRESULT InitRest(void)
{
	//bg
	InitRestBG();
	//�ꖇ�G
	InitRestPicture();
	//�X�e�[�^�X�\��
	InitRestStatus();
	//�e��R�}���h(HP�񕜁A�X�e�[�^�X����)
	InitRestCommand();
	//�ޏo
	InitRestExit();
	//�I��
	InitRestSelect();

	return S_OK;
}

void UninitRest(void)
{
	//bg
	UninitRestBG();
	//�ꖇ�G
	UninitRestPicture();
	//�X�e�[�^�X�\��
	UninitRestStatus();
	//�e��R�}���h(HP�񕜁A�X�e�[�^�X����)
	UninitRestCommand();
	//�ޏo
	UninitRestExit();
	//�I��
	UninitRestSelect();

}

void UpdateRest(void)
{
	//bg
	UpdateRestBG();
	//�ꖇ�G
	UpdateRestPicture();
	//�X�e�[�^�X�\��
	UpdateRestStatus();
	//�e��R�}���h(HP�񕜁A�X�e�[�^�X����)
	UpdateRestCommand();
	//�ޏo
	UpdateRestExit();
	//�I��
	UpdateRestSelect();
}

void DrawRest(void)
{
	//bg
	DrawRestBG();
	//�ꖇ�G
	DrawRestPicture();
	//�X�e�[�^�X�\��
	DrawRestStatus();
	//�e��R�}���h(HP�񕜁A�X�e�[�^�X����)
	DrawRestCommand();
	//�ޏo
	DrawRestExit();
	//�I��
	DrawRestSelect();
}