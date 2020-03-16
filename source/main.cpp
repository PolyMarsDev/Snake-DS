#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include "segment.h"
#include "snake.h"

const int up = 0;
const int down = 1;
const int left = 2;
const int right = 3;

Snake snake(4);	
int timer = 0;
int direction = right;
char score[32];

void updateScore()
{
	sprintf(score, "SCORE: %d", snake.getScore());
	NF_ClearTextLayer(0, 0);
	NF_WriteText(0, 0, 2, 2, score);
	NF_UpdateTextLayers();
}

void reset()
{
	for (int i = 0; i < snake.getSize()*2 + 2; i++)
	{
		NF_DeleteSprite(0, i);
	}
	snake = Snake(4);
	snake.randomizeApple();
	timer = 0;
	direction = right;
	updateScore();
}

int main(int argc, char **argv) 
{

	consoleDemoInit();	
	consoleClear();		
	NF_Set2D(0,0);
	NF_SetRootFolder("NITROFS");
	
	NF_InitTiledBgBuffers();
	NF_InitTiledBgSys(0);
	
	NF_LoadTiledBg("backgrounds/bg", "bg", 256, 256);
	NF_CreateTiledBg(0, 3, "bg");
	
	NF_InitSpriteBuffers();
	NF_InitSpriteSys(0);
	
	NF_LoadSpriteGfx("sprites/tile", 0, 8, 8); 
	NF_LoadSpritePal("palettes/segment", 0);
	NF_LoadSpritePal("palettes/apple", 1);
	NF_LoadSpritePal("palettes/segment_dropshadow", 2);
	NF_LoadSpritePal("palettes/apple_dropshadow", 3);
	
	NF_VramSpriteGfx(0, 0, 0, true);
	NF_VramSpritePal(0, 0, 0);
	NF_VramSpritePal(0, 1, 1);
	NF_VramSpritePal(0, 2, 2);
	NF_VramSpritePal(0, 3, 3);
	
	NF_InitTextSys(0);
	
	NF_LoadTextFont("fonts/font", "default", 256, 256, 0);
	NF_CreateTextLayer(0, 0, 0, "default");

	NF_WriteText(0, 0, 2, 2, "SCORE: 0");
	NF_UpdateTextLayers();
	
	while(1) 
	{
		scanKeys();
		
		if (keysHeld() & KEY_START)
		{
			break;
		}
		
		NF_CreateSprite(0, 0, 0, 1, snake.getApple().getX(), snake.getApple().getY());
		for (int i = 0; i < snake.getSize(); i++)
		{
			NF_CreateSprite(0, i + 1, 0, 0, snake.getSegment(i).getX(), snake.getSegment(i).getY());
			NF_CreateSprite(0, i + snake.getSize() + 1, 0, 2, snake.getSegment(i).getX(), snake.getSegment(i).getY() + 3);
		}
		NF_CreateSprite(0, snake.getSize()*2+1, 0, 3, snake.getApple().getX(), snake.getApple().getY() + 3);
		

		if (keysHeld() & KEY_UP)
		{
			if (direction != down)
			{
				direction = up;
			}
		}
		else if (keysHeld() & KEY_DOWN)
		{
			if (direction != up)
			{
				direction = down;
			}
		}
		else if (keysHeld() & KEY_LEFT)
		{
			if (direction != right)
			{
				direction = left;
			}
		}
		else if (keysHeld() & KEY_RIGHT)
		{
			if (direction != left)
			{
				direction = right;
			}
		}
		
		if (timer >= snake.getDelay())
		{
			if (!snake.move(direction))
			{
				reset();
			}
			updateScore();
			timer = 0;
		} 
		else 
		{
			timer += 1;
		}
		
		NF_SpriteOamSet(0);
		swiWaitForVBlank();
		oamUpdate(&oamMain);	
	}

	return 0;

}
