//�v���C���[����[player.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXVECTOR2 move;
	int rotate;		//�����Ă�������擾����ϐ�
	D3DXVECTOR2 colPos;	//��΂ɑ΂��čs�������蔻��Ɏg�p����B���ɂ̓v���C���[�̑����̍��W�������Ă���ϐ��B

	float u, v, uw, vh;
	bool drawflag;	//�`�悷�邩���Ǘ�����t���O

	int atk;		//�U����
	int def;		//�h���

	//�e�N�X�`��
	int stand_Ltexture;		//�����E����
	int stand_Rtexture;		//�����E����
	bool standtextureflag;	//�`�悷�邩���Ǘ�����t���O
	bool standLRflag;		//�ǂ��������Ă��邩���Ǘ�����t���O

	int walk_Ltexture;		//�����E����
	int walk_Rtexture;		//����������
	bool walktextureflag;	//�`�悷�邩���Ǘ�����t���O
	bool walkLRflag;		//�ǂ��������Ă��邩���Ǘ�����t���O

	int catch_Ltexture;		//�L���b�`�E����
	int catch_Rtexture;		//�L���b�`������
	bool catchtextureflag;	//�`�悷�邩���Ǘ�����t���O
	bool catchLRflag;		//�ǂ��������Ă��邩���Ǘ�����t���O
	float catchtexturetime;	//�A�j���[�V�����̎��Ԃ��Ǘ�����ϐ�

	int pick_Ltexture;		//�E���E����
	int pick_Rtexture;		//�E��������
	bool picktextureflag;	//�`�悷�邩���Ǘ�����t���O
	bool pickLRflag;		//�ǂ��������Ă��邩���Ǘ�����t���O
	float picktexturetime;	//�A�j���[�V�����̎��Ԃ��Ǘ�����ϐ�

	int throw_Ltexture;	//�����E����
	int throw_Rtexture;	//����������
	bool throwtextureflag;	//�`�悷�邩���Ǘ�����t���O
	bool throwLRflag;		//�ǂ��������Ă��邩���Ǘ�����t���O
	float throwtexturetime;//�A�j���[�V�����̎��Ԃ��Ǘ�����ϐ�

	int skill_Ltexture;	//�X�L���E����
	int skill_Rtexture;	//�X�L��������
	bool skilltextureflag;	//�`�悷�邩���Ǘ�����t���O
	bool skillLRflag;		//�ǂ��������Ă��邩���Ǘ�����t���O
	float skilltexturetime;//�A�j���[�V�����̎��Ԃ��Ǘ�����ϐ�

	int damage_Ltexture;	//�_���[�W�E����
	int damage_Rtexture;	//�_���[�W������
	bool damagetextureflag;	//�`�悷�邩���Ǘ�����t���O
	bool damageLRflag;		//�ǂ��������Ă��邩���Ǘ�����t���O
	float damagetexturetime;//�A�j���[�V�����̎��Ԃ��Ǘ�����ϐ�
	bool skilluseflag;		//�X�L�����g�������ǂ������Ǘ�����t���O

	int deathtexture;		//���S

	bool drawdepth;			//�{�[���ƃv���C���[�̕`�揇�t���O


}PLAYER;

//-----�v���g�^�C�v�錾
HRESULT InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);

PLAYER* GetPlayer(void);