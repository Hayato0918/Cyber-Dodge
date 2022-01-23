//�^�C�g������ [title.cpp]
#include "save.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "player_hp.h"
#include "player.h"

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
    PLAYER* player = GetPlayer();
    PLAYERHP* player_hp = GetPlayerHp();

    /*�f�[�^�̓��e���t�@�C���ɃZ�[�u*/
    if((fp = fopen(name, "w")) == NULL) {
        printf("�t�@�C���I�[�v���G���[\n");
    }
    else
    { 
        fprintf(fp, "�U���� = %d\n ������ = %d\n", player->atk, player->gold);
        fclose(fp);
    }
}

//-----���[�h����
void Load(void)
{
    /*�t�@�C���̓��e����f�[�^�����[�h*/
    if ((fp = fopen(name, "r")) == NULL) {
        printf("�t�@�C���I�[�v���G���[\n");
    }
    else
    {
        fread(&save, sizeof(save), 1, fp);
        fclose(fp);
    }
}