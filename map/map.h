#ifndef MAP_H
# define MAP_H
#include <fcntl.h>
#include <unistd.h>
#include "../engine/vector.h"
#include "../window/window.h"
#include "../lib/get_next_line/get_next_line.h"

typedef struct s_sprite
{
	void	*original;
	void	*white;
}	t_sprite;

typedef struct s_sprites
{
	t_sprite	sp0_0;
	t_sprite	sp1_0;
	t_sprite	sp2_0;
	t_sprite	sp3_0;
	t_sprite	sp4_0;
	t_sprite	sp4_1;
	t_sprite	sp5_0;
	t_sprite	sp6_1;
	t_sprite	sp7_1;
	t_sprite	sp8_1;
	t_sprite	sp9_1;
	t_sprite	sp9_2;
	t_sprite	sp10_0;
	t_sprite	sp10_1;
	t_sprite	sp10_2;
	t_sprite	*sp12_2;
	t_sprite	sp11_2;
	t_sprite	sp13_0;
	t_sprite	sp14_0;
	t_sprite	spxxx;
}	t_sprites;


typedef struct s_map
{
	t_vector	size;
	char		**map;
	int		error_code;
}	t_map;

int			check_path(char *path);
void			generate_map(t_window win, t_map map);
t_map			check_file(char *map_file);
t_map			read_map(char *map_file);
t_sprites		import_img(t_window window);
void			*mlx_xpm_file_to_image(void *mlx, char *img, int *x, int *y);
//int			mlx_put_image_to_window(void *mlx, void *window, void *img, int x, int y);
t_map			set_map(char *map_file);
#endif
