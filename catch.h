//�L���b�`���� [catch.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 playerpos;	//�v���C���[���̃L���b�`�]�[���̈ʒu
	D3DXVECTOR2 size;
	int texture;
	D3DXCOLOR color;
	bool playerflag;	//�v���C���[���L���b�`��������Ă��邩���Ǘ�����t���O
	bool playerintervalflag;	//�v���C���[�̃L���b�`�̃C���^�[�o�����Ǘ�����t���O
	float playerintervaltime;	//�v���C���[�̃L���b�`�̃C���^�[�o���b���Ǘ�����ϐ�
	float playercoltime;	//�v���C���[�̃L���b�`�̓����蔻�莞�Ԃ��Ǘ�����ϐ�
	bool playercolflag;	//�v���C���[���{�[�����L���b�`���Ă��邩���Ǘ�����t���O

	D3DXVECTOR2 enemypos;	//�G�l�~�[���̃L���b�`�]�[���̈ʒu
	bool enemyflag;		//�G�l�~�[���L���b�`��������Ă��邩���Ǘ�����t���O
	bool enemyintervalflag;	//�G�l�~�[�̃L���b�`�̃C���^�[�o�����Ǘ�����t���O
	float enemyintervaltime;	//�G�l�~�[�̃L���b�`�̃C���^�[�o���b���Ǘ�����ϐ�
	float enemycoltime;	//�G�l�~�[�̃L���b�`�̓����蔻�莞�Ԃ��Ǘ�����ϐ�
	bool enemycolflag;	//�G�l�~�[���{�[�����L���b�`���Ă��邩���Ǘ�����t���O
	bool enemyAIcatch;	//�G�l�~�[���L���b�`����������Ƃ��Ɏg���t���O
}CATCH;

//-----�v���g�^�C�v�錾
HRESULT InitCatch(void);
void UninitCatch(void);
void UpdateCatch(void);
void DrawCatch(void);
void P_Catch(void);
void M_Catch(void);

CATCH* GetCatch(void);