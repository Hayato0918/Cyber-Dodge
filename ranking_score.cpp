//�����L���O_�X�R�A���� [ranking_score.cpp]
#include "ranking_score.h"
//�V�X�e��.h
#include "texture.h"
#include "sprite.h"
#include "save.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
RANKING_SCORE ranking_score[4][4];
RANKING_SCORENUM ranking_scorenum[4];

//-----�O���[�o���ϐ�
int ranking_scoretexture;

//-----����������
HRESULT InitRankingScore(void)
{
	//�ꏊ�A�T�C�Y�Auv����
	for (int y = 0; y < 4; y++)
	{
		for (int i = 0; i < 4; i++)
		{
			ranking_score[y][i].pos = D3DXVECTOR2(880.f + i * 40.f, 180.f + 160.f * y);
			ranking_score[y][i].size = D3DXVECTOR2(40.f, 60.f);
			ranking_score[y][i].drawflag = true;
		}
	}

	ranking_scoretexture = LoadTexture("data/TEXTURE/number.png");

	if (ranking_scorenum[3].saveflag == true)
		ranking_scorenum[3].saveflag = false;


	ScoreLoad();

	return S_OK;
}

//-----�I������
void UninitRankingScore(void)
{

}

//-----�X�V����
void UpdateRankingScore(void)
{
	for (int i = 0; i < 4; i++)
	{
		ranking_scorenum[i].a = ranking_scorenum[i].gold * 0.001f;
		ranking_scorenum[i].b = (ranking_scorenum[i].gold - ranking_scorenum[i].a * 1000) * 0.01f;
		ranking_scorenum[i].c = (ranking_scorenum[i].gold - ranking_scorenum[i].a * 1000 - ranking_scorenum[i].b * 100) * 0.1f;
		ranking_scorenum[i].d = ranking_scorenum[i].gold - ranking_scorenum[i].a * 1000 - ranking_scorenum[i].b * 100 - ranking_scorenum[i].c * 10;

		//gold��1000�̈�
		if (ranking_scorenum[i].a < 5)
		{
			ranking_score[i][0].u = 0.2f * ranking_scorenum[i].a;
			ranking_score[i][0].v = 0.f;
		}
		if (ranking_scorenum[i].a >= 5)
		{
			ranking_score[i][0].u = 0.2f * ranking_scorenum[i].a;
			ranking_score[i][0].v = 0.5f;
		}
		if (ranking_scorenum[i].a <= 0)
			ranking_score[i][0].drawflag = false;
		if (ranking_scorenum[i].a > 0)
			ranking_score[i][0].drawflag = true;
		//gold��100�̈�
		if (ranking_scorenum[i].b < 5)
		{
			ranking_score[i][1].u = 0.2f * ranking_scorenum[i].b;
			ranking_score[i][1].v = 0.f;
		}
		if (ranking_scorenum[i].b >= 5)
		{
			ranking_score[i][1].u = 0.2f * ranking_scorenum[i].b;
			ranking_score[i][1].v = 0.5f;
		}
		if (ranking_scorenum[i].b >= 0)
			ranking_score[i][1].drawflag = true;
		if (ranking_scorenum[i].a <= 0 && ranking_scorenum[i].b <= 0)
			ranking_score[i][1].drawflag = false;
		//gold��10�̈�
		if (ranking_scorenum[i].c < 5)
		{
			ranking_score[i][2].u = 0.2f * ranking_scorenum[i].c;
			ranking_score[i][2].v = 0.f;
		}
		if (ranking_scorenum[i].c >= 5)
		{
			ranking_score[i][2].u = 0.2f * ranking_scorenum[i].c;
			ranking_score[i][2].v = 0.5f;
		}
		if (ranking_scorenum[i].c >= 0)
			ranking_score[i][2].drawflag = true;
		if (ranking_scorenum[i].a <= 0 && ranking_scorenum[i].b <= 0 && ranking_scorenum[i].c <= 0)
			ranking_score[i][2].drawflag = false;
		//gold��1�̈�
		if (ranking_scorenum[i].d < 5)
		{
			ranking_score[i][3].u = 0.2f * ranking_scorenum[i].d;
			ranking_score[i][3].v = 0.f;
		}
		if (ranking_scorenum[i].d >= 5)
		{
			ranking_score[i][3].u = 0.2f * ranking_scorenum[i].d;
			ranking_score[i][3].v = 0.5f;
		}
	}
}

//-----�`�揈��
void DrawRankingScore(void)
{
	//�o�i�[GOLD
	for (int i = 0; i < 4; i++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (ranking_score[y][i].drawflag == true)
				DrawSpriteLeftTop(ranking_scoretexture, ranking_score[y][i].pos.x, ranking_score[y][i].pos.y, ranking_score[y][i].size.x, ranking_score[y][i].size.y,
					ranking_score[y][i].u, ranking_score[y][i].v, 0.2f, 0.5f);
		}
	}
}

RANKING_SCORENUM* GetRankingScoreNum()
{
	return &ranking_scorenum[0];
}