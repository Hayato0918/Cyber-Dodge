#pragma once

// �o�^�V�[���ꗗ
enum SCENE
{
	SCENE_NONE,		//�V�[�������Ȃ�
	SCENE_TITLE,	//�^�C�g��
	SCENE_RANKING,
	SCENE_OPTION,	//�ݒ���
	SCENE_NAME,		//���O����
	SCENE_MAP,		//���[�O���C�N����
	SCENE_DECKMENU,	//�f�b�L���j���[
	SCENE_REST,		//�x�e�}�X
	SCENE_EVENT,	//�C�x���g�}�X
	SCENE_SHOP,		//���l�i�V���b�v�j�}�X
	SCENE_GAME,		//�h�b�W�{�[������

	SCENE_CLEAR,
	SCENE_GAMEOVER,

	SCENE_MAX		//�Ōゾ�Ƃ킩��z�������
};

void InitScene(SCENE index);
void UninitScene(void);
void UpdateScene(void);
void DrawScene(void);

void SetScene(SCENE index);
void CheckScene(void);
