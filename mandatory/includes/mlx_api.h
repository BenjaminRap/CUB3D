/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_api.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:23:46 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 18:07:42 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_API_H
# define MLX_API_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>

# define EVENT_LOOP_FRAME_TARGET	4000

# define KEY_ESC 					65307
# define KEY_LEFT 					65361
# define KEY_RIGHT					65363
# define KEY_W 						119
# define KEY_A 						97
# define KEY_S 						115
# define KEY_D 						100

typedef struct s_mlx		t_mlx;
typedef struct s_image		t_image;
typedef union u_argb_color	t_argb_color;
typedef struct s_mlx_coords	t_mlx_coords;

struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_image	*img1;
	t_image	*img2;
	t_image	*img_buff;
	size_t	event_loop_counter;
	int		width;
	int		height;
	char	*title;
};

struct s_image
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		bpp_factor;
	int		line_len;
	int		endian;
	int		width;
	int		height;
};

union u_argb_color
{
	uint32_t	val;
	struct s_rgba
	{
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
		uint8_t	a;
	} rgba;
};

struct s_mlx_coords
{
	int16_t	x;
	int16_t	y;
};

enum e_mlx_event
{
	MLX_ON_KEYPRESS = 2,
	MLX_ON_KEYRELEASE = 3,
	MLX_ON_MOUSEDOWN = 4,
	MLX_ON_MOUSEUP = 5,
	MLX_ON_MOUSEMOVE = 6,
	MLX_ON_EXPOSE = 12,
	MLX_ON_DESTROY = 17
};

enum e_hook_type
{
	HOOK_DESTROY,
	HOOK_KEY,
	HOOK_KEY_RELEASE,
	HOOK_KEY_PRESS,
	HOOK_MOUSE,
	HOOK_LOOP
};

// t_mlx functions
bool	t_mlx_init(t_mlx *mlx, int win_width, int win_height, char *title);
bool	t_mlx_launch(t_mlx *mlx);
void	t_mlx_destroy(t_mlx *mlx);
bool	t_mlx_add_hook(t_mlx *mlx, int (*handler)(), void *game, \
			enum e_hook_type hook_type);
bool	t_mlx_render(t_mlx *mlx);

// t_image functions
t_image	*t_image_init(void *mlx_ptr, int img_width, int img_height);
void	t_image_destroy(void *mlx_ptr, t_image *img);
void	t_image_clear(t_image *img);
bool	t_image_import_file(t_image *image, char *filename, void *mlx);

// Draw functions
void	t_mlx_draw_pixel(t_image *img, t_mlx_coords *coords, \
			uint32_t color);
void	t_mlx_draw_pixel_secured(t_image *img, t_mlx_coords *coords, \
			uint32_t color);
void	t_mlx_draw_line(t_image *img, t_mlx_coords coords_start, \
			t_mlx_coords coords_end, uint32_t color);
void	t_mlx_draw_rectangle(t_image *img, t_mlx_coords *coords, \
			t_mlx_coords *size, uint32_t color);
char	*t_mlx_get_pixel(t_image *image, size_t x, size_t y);
bool	set_color(unsigned int *result, int r, int g, int b);

#endif
