#include "map.h"
#include <stdio.h>
#include <unistd.h>

t_map	check_file(char *map_file)
{
	t_map	map;

	map.error_code = 1;
	if (check_path(map_file))
		return (map);
	map = read_map(map_file);
	if (map.error_code)
		return (map);
	map = set_map(map_file);
	map.error_code = 0;
	if (map.error_code)
		return (map);
	return (map);	
}

int	check_path(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (1);
	if (read(fd, 0, 0))
		return (1);
	close(fd);
	return (0);
}

t_map	read_map(char *map_file)
{
	t_map	map;
	int	fd;
	char	*str;
	t_vector	size;

	map.error_code = 1;
	size = v_zero();
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (map);
	while (str)
	{
		str = ft_strtrim(get_next_line(fd), "\n");
		if (!size.y)
			size.x = ft_strlen(str);
		if (str)
		{
			printf("%i => %s\n", size.y, str);
			if (size.x != ft_strlen(str))
			{
				printf("La map n'est pas rectangle[%i, %i] %s\n", size.x, (int)ft_strlen(str), str);
				return (map);
			}
			size.y++;
		}
	}
	close(fd);
	map.size = size;
	map.error_code = 0;
	return (map);
}

t_map 	set_map(char *map_file)
{
	t_map	map;
	int	fd;
	int	y;
	char	*str;

	map.error_code = 1;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (map);
	str = "";
	y = 0;
	map.map = ft_calloc(map.size.y, sizeof(char*));
	while (str)
	{
		str = ft_strtrim(get_next_line(fd), "\n");
		printf("%i ==> %s\n", y, str);
		map.map[y] = ft_calloc(map.size.x, 1);
		map.map[y] = str;
		y++;
	}
	close(fd);
	map.error_code = 0;
	return (map);
}

void	generate_map(t_window window, t_map map)
{
	t_sprites	imgs;
	int		x;
	int		y;

	imgs = import_img(window);
	printf("TEST\n");
	fflush(stdout);
	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			printf("%c", map.map[y][x]);
			fflush(stdout);
			//if (map.map[y][x] == '1')
			//{
			//	if (x == 0 && map.map[y][x + 1] == '0')
			//	{
			mlx_put_image_to_window(window.mlx, window.win, imgs.sp3_0.original, (x * 24), (y * 24));
			//	}
			//}
	//		mlx_put_image_to_window(window.mlx, window.win, imgs.sp3_0.original, (x * 24), (y * 24));
			x++;
		}
		printf("\n");
		y++;
	}
}

t_sprites	import_img(t_window window)
{
	t_sprites	sprites;
	int		size;

	size = 24;
	printf("TEST");
	fflush(stdout);
	sprites.sp3_0.original = mlx_xpm_file_to_image(window.mlx, "../assets/map/map3_0.xpm", &size, &size);
	printf("TEST");
	fflush(stdout);
	return (sprites);
}
