/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:41:59 by rvarela-          #+#    #+#             */
/*   Updated: 2024/12/28 17:20:57 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define SH_RED     "\033[1;31m"
# define SH_GREEN   "\033[1;32m"
# define SH_YELLOW  "\033[1;33m"
# define RESET      "\033[0m"

// D
# define WIDTH 1024
# define HEIGHT 800
// COLOR
# define GRAY 0x808080
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000  
# define GREEN 0x00FF00 
# define BLUE 0x0000FF
# define PURPLE  0x8b00ff
# define YELLOW 0xfcff0f

# define ERR_CODE   0
# define MSG_CD     1

typedef struct s_ray
{
	int		pos_mapx;
	int		pos_mapy;
	int		step_x;
	int		step_y;
	double	p_x;
	double	p_y;
	double	next_x;
	double	next_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	mult;
	double	ray_pixel;
	double	raydir;
	double	raydir_x;
	double	raydir_y;
	double	deltadirx;
	double	deltadiry;
	double	disttox;
	double	disttoy;
	int		hit_side;
	int		hit_x;
	int		hit_y;
	double	walldist;
	double	speed;
}		t_ray;

typedef struct s_txtr
{
	void	*texture[4];
	char	*filename[4];
	int		txt_w[4];
	int		txt_h[4];
	int		start_y;
	int		last_y;
	double	start_x;
	double	len_wall;
	double	scale;
	double	txtr_pos;
	char	*pixels_adr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}		t_txtr;

typedef struct s_mlx
{
	//minilibx ptr
	void		*mlx_connection;
	void		*mlx_window;
	void		*img;
	// t_img 
	char		*pixels_adr;
	int			bits_per_pixel;
	int			endian;
	int			line_len;
}		t_mlx;

typedef struct s_flag
{
	char	*no_tex;
	char	*so_tex;
	char	*ea_tex;
	char	*we_tex;
	int		c_color;
	int		f_color;
}			t_flag;

typedef struct s_data
{
	t_mlx	*mlx;
	t_ray	*ray;
	t_txtr	*txtr;
	t_flag	*flags;
	int		fd;
	int		n_textures_set;
	int		n_plan_colors_set;
	char	*f_line;
	int		f_hexa;
	int		c_hexa;
	size_t	map_x;
	size_t	map_y;
	char	*map_str;
	char	**map_mtrx;
	char	play_dir;
}			t_data;

// 	CUB3D_INIT

void			cub3d_init(t_data *cub);
void			init_mlx(t_data *cub);
void			init_ray(t_data *cub);
void			init_player(t_data *cub);

// init_DIR

void			init_dir(char c, t_data *cub);
void			sector_n(t_data *cub);
void			sector_s(t_data *cub);
void			sector_e(t_data *cub);
void			sector_w(t_data *cub);

// 	CUB3D_EVENTS

void			cub3d_events(t_data *cub);
int				key_imput(int keysym, t_data *cub);
int				close_window(t_data *cub);

// 	CUB3D_IMG

void			cub3d_img(t_data *cub);
void			ft_put_pixels(t_mlx *mlx, int x, int y, int color);

// 	CHECK MOVE

void			check_move(t_data *cub);
void			player_move(t_data *cub, double rad, double speed);
void			move_h_v(t_data *cub, double rad, double speed);

// CHECK ROTATE

void			rotate(t_ray *ray, double speed);

// RAYCASTING

void			raycasting(t_data *cub);
int				hit_wall(t_data *cub, t_ray *ray, int hit);
void			uptade_vectors(t_data *cub, int x);
void			find_dist(t_ray *ray);
void			update_dir(t_data *cub, double rad);

// DRAW WALL

void			draw_wall(t_data *cub, int x);
void			get_texture_ranges(t_data *cub);
void			put_texture(t_data *cub, int x, int img_index);
unsigned int	get_pixel_color(t_txtr *txtr, int x, int y, int index);

// MOVE

void			move_up(t_ray *ray, double speed);
void			move_down(t_ray *ray, double speed);
void			move_right(t_ray *ray, double speed);
void			move_left(t_ray *ray, double speed);

/*parse*/
bool			all_textures_colors(t_data *cub);
void			parse_file(t_data *cub, char *map);

/*parse_texture*/
void			parse_texture(t_data *cub, char wall);

/*parse_color*/
void			missing_text_color(t_data *cub);
void			parse_color(t_data *cub, char plane);

/*map_plan*/
void			get_map_plan(t_data *cub, char *line);
void			parse_map_plan(t_data *cub);

/*check_map_plan*/
void			check_map(t_data *cub);

/*utils*/
void			safe_exit(t_data *cub, char *msg, int exit_code);
void			*safe_malloc(t_data *cub, size_t size);
void			*safe_calloc(t_data *cub, size_t n_args, size_t size);
bool			is_space(char c);
bool			empty_line(char *line);

/*clean*/
void			cub_clean(t_data *cub);
void			safe_memfree(void *mem);
void			clean_err_quit(t_data *cub, char *err_msg);

#endif