//�}�b�v���� [map.cpp]
#include "map.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"

#include "map_point.h"
#include "map_hack.h"
#include "map_line.h"

//-----�萔��`

//-----�\���̐錾

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ��̒�`


//-----�������֐�
void InitMap(void)
{
	InitMapPoint();
	InitMapPlayer();
	InitPolygon();
	InitMapHack();

}

//-----�I�������֐�
void UninitMap()
{
	UninitMapPoint();
	UninitMapPlayer();
	UninitMapHack();
	UninitPolygon();

}

//-----�X�V����������֐�
void UpdateMap(void)
{
	UpdateMapPoint();
	UpdateMapPlayer();
	UpdateMapHack();
	UpdatePolygon();

}

//-----�`�揈���֐�
void DrawMap(void)
{
	DrawMapPoint();
	DrawMapPlayer();
	DrawPolygon();
	DrawMapHack();

}