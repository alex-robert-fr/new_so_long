#ifndef	WINDOW_H
# define WINDOW_H
#include <mlx.h>

typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		error_code;
}	t_window;

void		*mlx_init();
void		*mlx_new_window(void *mlx, int x, int y, char *title);
t_window	create_window(int x, int y, char *title);
#endif
