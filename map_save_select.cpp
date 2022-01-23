//�Z�[�u���� [map_save_select.cpp]
#include "map_save_select.h"
//�V�X�e��.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
//
#include "map_save_bg.h"
#include "save.h"

MAPSAVE_SELECT map_save_select;

HRESULT InitMapSaveSelect(void)
{
	map_save_select.pos = D3DXVECTOR2(600.f, 390.f);
	map_save_select.size = D3DXVECTOR2(80.f, 80.f);
	map_save_select.count = 0;
	map_save_select.texture = LoadTexture("data/TEXTURE/option/option_select.png");
	map_save_select.drawflag = false;

	return S_OK;
}

void UninitMapSaveSelect(void)
{

}

void UpdateMapSaveSelect(void)
{
	MAPSAVE_BG* map_save_bg = GetMapSaveBG();
	map_save_select.drawflag = map_save_bg->drawflag;

	//if (PADUSE == 0)
	//{
	//	//�x�e�}�X�̑I��
	//	if (IsButtonTriggered(0, BUTTON_UP) && rest_select.count > 0)
	//	{
	//		rest_select.pos.y -= 116;
	//		rest_select.count -= 1;
	//	}
	//	if (IsButtonTriggered(0, BUTTON_DOWN) && rest_select.count < 2)
	//	{
	//		rest_select.pos.y += 116;
	//		rest_select.count += 1;
	//	}
	//	//�I���������̌���
	//	if (IsButtonTriggered(0, BUTTON_X) && rest_select.count == 0)
	//	{
	//		player_hp->gaugesize.x = player_hp->gaugesize.x + 100;
	//		player_hp->pos.x = player_hp->pos.x - 100;
	//		SceneTransition(SCENE_MAP);
	//	}

	//}
	
	if (map_save_select.drawflag == true)
	{

		if (PADUSE == 1)
		{
			if (GetKeyboardTrigger(DIK_W) && map_save_select.count > 0)		//��ړ�
			{
				map_save_select.pos.y -= 100.f;
				map_save_select.count -= 1;
			}
			if (GetKeyboardTrigger(DIK_S) && map_save_select.count < 1)		//���ړ�
			{
				map_save_select.pos.y += 100.f;
				map_save_select.count += 1;
			}
		}
	}

	if (map_save_select.count == 0)
	{
		if (GetKeyboardTrigger(DIK_RETURN))
		{
			Save();
		}
	}
	if (map_save_select.count == 1)
	{
		if (GetKeyboardTrigger(DIK_RETURN))
		{
			map_save_bg->drawflag = false;
			map_save_select.pos.y -= 100.f;
			map_save_select.count = 0;
		}
	}


}

void DrawMapSaveSelect(void)
{
	if(map_save_select.drawflag == true)
	DrawSpriteLeftTop(map_save_select.texture, map_save_select.pos.x, map_save_select.pos.y, map_save_select.size.x, map_save_select.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}