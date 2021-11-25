//�v���C���[HP���� [player_hp.h]
#include "player_hp.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
PLAYERHP hp;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitPlayerHp(void)
{
	hp.gaugeonce = 8;

	hp.pos = D3DXVECTOR2(60.0f, SCREEN_HEIGHT - 100.0f);
	hp.framesize = D3DXVECTOR2(80.f * hp.gaugeonce, 60.0f); //HP�o�[�t���[���T�C�Y
	hp.frametexture = LoadTexture("data/TEXTURE/bugframe.png");

	hp.gaugesize = D3DXVECTOR2(hp.framesize.x, hp.framesize.y); //�c���Ă���HP�̗�
	hp.gaugetexture = LoadTexture("data/TEXTURE/obstacle.png");

	return S_OK;
}

//-----�I������
void UninitPlayerHp(void)
{

}

//-----�X�V����
void UpdatePlayerHp(void)
{
	//hp�̌������@�\���Ă��邩�ǂ������m�F���邽�߂Ɏg�p���܂��B
	//�����N���b�N -10 hp // 2.0f = 1hp
	//if (GetKeyboardTrigger(DIK_2))
	//{
	//	hp.gaugesize.x = hp.gaugesize.x - 20.0f;
	//}
}

//-----�`�揈��
void DrawPlayerHp(void)
{
	//-----�o�O�Q�[�W�̕`��
	DrawSpriteLeftTop(hp.gaugetexture, hp.pos.x, hp.pos.y, hp.gaugesize.x, hp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0f);

	//-----�o�O�Q�[�W�̘g�̕`��
	DrawSpriteLeftTop(hp.frametexture, hp.pos.x, hp.pos.y, hp.framesize.x, hp.framesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----�\���̃|�C���^�擾����
PLAYERHP* GetPlayerHp()
{
	return &hp;
}