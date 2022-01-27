//�����L���O���� [ranking.cpp]
#include "ranking.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"

#include "ranking_bg.h"
#include "ranking_name.h"
#include "ranking_floor.h"
#include "ranking_score.h"

//-----�萔��`

//-----�\���̐錾

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ��̒�`


//-----�������֐�
HRESULT InitRanking(void)
{
	InitRankingBG();
	InitRankingName();
	InitRankingFloor();
	InitRankingScore();

	return S_OK;
}

//-----�I�������֐�
void UninitRanking(void)
{
	UninitRankingBG();
	UninitRankingName();
	UninitRankingFloor();
	UninitRankingScore();
}

//-----�X�V����������֐�
void UpdateRanking(void)
{
	UpdateRankingBG();
	UpdateRankingName();
	UpdateRankingFloor();
	UpdateRankingScore();

	if (IsButtonTriggered(0, BUTTON_Y))
		SceneTransition(SCENE_TITLE);
}

//-----�`�揈���֐�
void DrawRanking(void)
{
	DrawRankingBG();
	DrawRankingName();
	DrawRankingFloor();
	DrawRankingScore();
}