//�^�C�g������ [title.cpp]
#include "save.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "player_hp.h"

#include "map_point.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
FILE* fp;
SAVE save;

//-----�O���[�o���ϐ�
char* name = "savedata.txt";

//-----�Z�[�u����
void Save(void)
{
    /*
        �����ŃZ�[�u������e���X�V����(�e�X�e�[�^�X�A�X�L���̏󋵂��\���̂ɏ����ʂ�)
    */

    /*�f�[�^�̓��e���t�@�C���ɃZ�[�u*/
    if((fp = fopen(name, "wb")) == NULL) {
        printf("�t�@�C���I�[�v���G���[\n");
    }
    else
    { 
        fwrite(&save, sizeof(save), 1, fp);
        fclose(fp);
    }
}

//-----���[�h����
void Load(void)
{
    /*�t�@�C���̓��e����f�[�^�����[�h*/
    if ((fp = fopen(name, "rb")) == NULL) {
        printf("�t�@�C���I�[�v���G���[\n");
    }
    else
    {
        fread(&save, sizeof(save), 1, fp);
        fclose(fp);
    }
}