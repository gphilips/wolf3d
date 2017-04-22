#include "wolf3d.h"

void	change_sound(int keycode, t_env *e)
{
	if (keycode == DEL && e->sound != 0)
	{
		system("killall afplay");
		e->sound = 0;
	}
	else if (keycode == AT)
	{
		if (e->sound > 2)
		{
			system("killall afplay");
			e->sound = 1;
		}
		else
			e->sound++;
	}
	if (e->sound == 1)
	{
		system("afplay musics/commas.mp3 -v 0.3&");
	}
	else if (e->sound == 2)
	{
		system("killall afplay");
		system("afplay musics/mask-off.mp3 -v 0.3&");
	}
	else if (e->sound == 3)
	{
		system("killall afplay");
		system("afplay musics/blase.mp3 -v 0.3&");
	}
}
