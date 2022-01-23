//ボリューム選択処理 [soundvolume_select.cpp]
#include "soundvolume_select.h"
//システム.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "sound.h"
//

SOUNDVOLUME_SELECT soundvolume_select[2];	//音量をいじる方
SOUNDVOLUME_SELECT soundvolume;			//bgmかseかを選ぶ方

HRESULT InitSoundVolumeSelect(void)
{
	for (int i = 0; i < 2; i++)
	{
		soundvolume_select[i].pos = D3DXVECTOR2(870.f, 430.f + i * 300.f);		//1600:900→150:100
		soundvolume_select[i].size = D3DXVECTOR2(60.f, 60.f);		//1600:900→90:90

		soundvolume_select[i].count = 0;

		soundvolume_select[i].texture = LoadTexture("data/TEXTURE/option/soundvolume_select.png");
		soundvolume_select[i].soundchangeflag = false;
	}

	soundvolume.pos = D3DXVECTOR2(190.f, 250.f);
	soundvolume.size = D3DXVECTOR2(90.f, 90.f);
	soundvolume.texture = LoadTexture("data/TEXTURE/option/option_select.png");
	soundvolume.count = 0;

	return S_OK;
}

void UninitSoundVolumeSelect(void)
{

}

void UpdateSoundVolumeSelect(void)
{
	if (PADUSE == 0)
	{
		//bgmかseかの選択
		if (IsButtonTriggered(0, BUTTON_UP) && soundvolume.count > 0 && soundvolume_select[0].soundchangeflag == false && soundvolume_select[1].soundchangeflag == false)		//上移動
		{
			soundvolume.pos.y -= 300;	//1600:900→500
			soundvolume.count -= 1;
		}
		if (IsButtonTriggered(0, BUTTON_DOWN) && soundvolume.count < 1 && soundvolume_select[0].soundchangeflag == false && soundvolume_select[1].soundchangeflag == false)		//下移動
		{
			soundvolume.pos.y += 300;	//1600:900→500
			soundvolume.count += 1;
		}

		//bgmに決定
		if (IsButtonTriggered(0, BUTTON_Y) && soundvolume.count == 0 && soundvolume_select[0].soundchangeflag == false && soundvolume_select[1].soundchangeflag == false)
			soundvolume_select[0].soundchangeflag = true;

		//bgmの音量をいじる
		if (soundvolume_select[0].soundchangeflag == true)
		{
			if (IsButtonTriggered(0, BUTTON_LEFT) && soundvolume_select[0].count > -5)		//上移動
			{
				soundvolume_select[0].pos.x -= 100;	//1600:900→500
				soundvolume_select[0].count -= 1;
			}
			if (IsButtonTriggered(0, BUTTON_RIGHT) && soundvolume_select[0].count < 5)		//下移動
			{
				soundvolume_select[0].pos.x += 100;	//1600:900→500
				soundvolume_select[0].count += 1;
			}
			if (IsButtonTriggered(0, BUTTON_A))
				soundvolume_select[0].soundchangeflag = false;
		}

		//seに決定
		if (IsButtonTriggered(0, BUTTON_Y) && soundvolume.count == 1 && soundvolume_select[0].soundchangeflag == false && soundvolume_select[1].soundchangeflag == false)
			soundvolume_select[1].soundchangeflag = true;

		//seの音量をいじる
		if (soundvolume_select[1].soundchangeflag == true)
		{
			if (IsButtonTriggered(0, BUTTON_LEFT) && soundvolume_select[1].count > -5)		//上移動
			{
				soundvolume_select[1].pos.x -= 100;	//1600:900→500
				soundvolume_select[1].count -= 1;
			}
			if (IsButtonTriggered(0, BUTTON_RIGHT) && soundvolume_select[1].count < 5)		//下移動
			{
				soundvolume_select[1].pos.x += 100;	//1600:900→500
				soundvolume_select[1].count += 1;
			}
			if (IsButtonTriggered(0, BUTTON_A))
				soundvolume_select[1].soundchangeflag = false;
		}
	}

	if (PADUSE == 1)
	{
		//bgmかseかの選択
		if (GetKeyboardTrigger(DIK_W) && soundvolume.count > 0 && soundvolume_select[0].soundchangeflag == false && soundvolume_select[1].soundchangeflag == false)		//上移動
		{
			soundvolume.pos.y -= 300;	//1600:900→500
			soundvolume.count -= 1;
		}
		if (GetKeyboardTrigger(DIK_S) && soundvolume.count < 1 && soundvolume_select[0].soundchangeflag == false && soundvolume_select[1].soundchangeflag == false)		//下移動
		{
			soundvolume.pos.y += 300;	//1600:900→500
			soundvolume.count += 1;
		}

		//bgmに決定
		if (GetKeyboardTrigger(DIK_RETURN) && soundvolume.count == 0 && soundvolume_select[0].soundchangeflag == false && soundvolume_select[1].soundchangeflag == false)
			soundvolume_select[0].soundchangeflag = true;

		//bgmの音量をいじる
		if (soundvolume_select[0].soundchangeflag == true)
		{
			if (GetKeyboardTrigger(DIK_A) && soundvolume_select[0].count > -5)		//上移動
			{
				soundvolume_select[0].pos.x -= 100;	//1600:900→500
				soundvolume_select[0].count -= 1;
			}
			if (GetKeyboardTrigger(DIK_D) && soundvolume_select[0].count < 5)		//下移動
			{
				soundvolume_select[0].pos.x += 100;	//1600:900→500
				soundvolume_select[0].count += 1;
			}
			if (GetKeyboardTrigger(DIK_Q))
				soundvolume_select[0].soundchangeflag = false;
		}

		//seに決定
		if (GetKeyboardTrigger(DIK_RETURN) && soundvolume.count == 1 && soundvolume_select[0].soundchangeflag == false && soundvolume_select[1].soundchangeflag == false)
			soundvolume_select[1].soundchangeflag = true;

		//seの音量をいじる
		if (soundvolume_select[1].soundchangeflag == true)
		{
			if (GetKeyboardTrigger(DIK_A) && soundvolume_select[1].count > -5)		//上移動
			{
				soundvolume_select[1].pos.x -= 100;	//1600:900→500
				soundvolume_select[1].count -= 1;
			}
			if (GetKeyboardTrigger(DIK_D) && soundvolume_select[1].count < 5)		//下移動
			{
				soundvolume_select[1].pos.x += 100;	//1600:900→500
				soundvolume_select[1].count += 1;
			}
			if (GetKeyboardTrigger(DIK_Q))
				soundvolume_select[1].soundchangeflag = false;
		}
	}
}

void DrawSoundVolumeSelect(void)
{
	DrawSpriteLeftTop(soundvolume.texture, soundvolume.pos.x, soundvolume.pos.y,
		soundvolume.size.x, soundvolume.size.y, 0.0f, 0.0f, 1.0f, 1.0f);

	for (int i = 0; i < 2; i++)
		DrawSpriteLeftTop(soundvolume_select[i].texture, soundvolume_select[i].pos.x, soundvolume_select[i].pos.y,
			soundvolume_select[i].size.x, soundvolume_select[i].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

SOUNDVOLUME_SELECT* GetSoundVolumeSelect(void)
{
	return &soundvolume_select[0];
}