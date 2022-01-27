//�t�@�C�A�[�E�H�[������[firewall.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXVECTOR2 move;
	D3DXVECTOR2 colPos;
	int rotate;		//�����Ă�������擾����ϐ�

	bool drawflag;	//�`�悷�邩���Ǘ�����t���O
	float u, v, uw, vh;

	int hp;			//�̗�
	int atk;		//�U����
	int def;		//�h���

	bool getskill;		//�X�L������肵�������Ǘ�����t���O

	bool floorflag;

	//�e�N�X�`��
	int stand_Ltexture;		//�����E����
	int stand_Rtexture;		//�����E����
	bool standtextureflag;	//�`�悷�邩���Ǘ�����t���O
	bool standLRflag;		//�ǂ��������Ă��邩���Ǘ�����t���O
	float standtexturetime;

	int walk_Ltexture;		//�����E����
	int walk_Rtexture;		//����������
	bool walktextureflag;	//�`�悷�邩���Ǘ�����t���O
	bool walkLRflag;		//�ǂ��������Ă��邩���Ǘ�����t���O
	float walktexturetime;

	int catch_Ltexture;	//�����E����
	int catch_Rtexture;	//����������
	bool catchtextureflag;	//�`�悷�邩���Ǘ�����t���O
	bool catchLRflag;		//�ǂ��������Ă��邩���Ǘ�����t���O
	float catchtexturetime;//�A�j���[�V�����̎��Ԃ��Ǘ�����ϐ�

	int throw_Ltexture;	//�����E����
	int throw_Rtexture;	//����������
	bool throwtextureflag;	//�`�悷�邩���Ǘ�����t���O
	bool throwLRflag;		//�ǂ��������Ă��邩���Ǘ�����t���O
	float throwtexturetime;//�A�j���[�V�����̎��Ԃ��Ǘ�����ϐ�

	int damage_Ltexture;	//�_���[�W�E����
	int damage_Rtexture;	//�_���[�W������
	bool damagetextureflag;	//�`�悷�邩���Ǘ�����t���O
	bool damageLRflag;		//�ǂ��������Ă��邩���Ǘ�����t���O
	float damagetexturetime;//�A�j���[�V�����̎��Ԃ��Ǘ�����ϐ�

	int deathtexture;		//���S

}FIREWALL;

//-----�v���g�^�C�v�錾
HRESULT InitFireWall(void);
void UninitFireWall(void);
void UpdateFireWall(void);
void DrawFireWall(void);

FIREWALL* GetFireWall(void);