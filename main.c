#include "map/map.h"
#include "pacman.h"
#include "window/window.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	game;

	if (argc == 2)	
	{
		printf("With map\n");
		game = start(argv[1]);
		if (game)
		{
			printf("Error\n");
			return (1);
		}
	}
	else
	{
		printf("Il manque un argument");
		return (1);
	}

	return (0);
}

int	start(char *map_file)
{
	t_game		game;
	t_window	window;

	game.map = check_file(map_file);
	if (game.map.error_code)
		return (1);
	window = create_window(24 * 24, 32 * 24, "Pacman");
	sleep(1);
	generate_map(window, game.map);
	mlx_loop(window.mlx);
	return(0);
}
