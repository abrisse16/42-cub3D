/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:06:11 by abrisse           #+#    #+#             */
/*   Updated: 2023/05/31 00:34:25 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include <limits.h>
# include <float.h>

# include "libft.h"
# include "mlx.h"

# define FOV_ANGLE 60					// field of view in degrees
# define TILE_SIZE 64					// size of a tile in pixels
# define MINIMAP_SCALE_FACTOR 0.3		// size of the minimap relative to the window
# define RADIUS 4						// size of the player circle on the minimap
# define WALL_STRIP_WIDTH 1				// width of a wall strip in pixels
# define WALK_SPEED 2.0f				// walk speed in pixels per frame
# define TURN_SPEED 2					// rotation speed in degrees per frame

/* structure validée */
typedef struct s_to_draw
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}	t_to_draw;

/* structure validée */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

/* structure validée */
typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

/* structure validée */
typedef struct s_player
{
	t_point	coord;
	float	angle;
	int		turn_direction;
	int		walk_direction;
	int		side_direction;
	float	turn_speed;
	float	walk_speed;
}	t_player;

typedef struct s_graphic
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	float	distance_projection;	// à déplacer dans data
	t_img	game;
	t_img	mini_map;

	/* structure validée jusqu'ici */

	t_img 	north_texture;
	t_img 	south_texture;
	t_img 	west_texture;
	t_img 	east_texture;
}	t_graphic;

/* structure validée */
typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	char	dir;
}	t_map;

typedef struct s_ray
{
	float	angle;
	t_point	hit_coord;
	float	hit_distance;
	int		was_hit_horizontal;
	int		is_facing_up;
	int		is_facing_left;

	int		horz_hit_found;
	float	horz_hit_distance;
	t_point horz_hit_coord;
	int		vert_hit_found;
	float	vert_hit_distance;
	t_point vert_hit_coord;

	t_point intercept;
	t_point step;
	
	float		wall_distance;
	t_to_draw	strip;
}	t_ray;

typedef struct s_data
{
	t_map		map;
	t_graphic	graphic;
	t_player	player;
	t_ray		*rays;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			celling[3];
	int			floor[3];
	int			data_count;
	float		fov_angle;
	int			num_rays;
	int			display_mini_map;
	t_to_draw	to_draw;
//	float		distance_projection;
}	t_data;


/* error.c : fichier validé */
int	ft_error(char *str);
int	ft_perror(char *str);

/* init.c */
void	init_data(t_data *data);
int		init_graphic(t_data *data);

/* game.c */
void	start(t_data *data);
int		has_wall_at(t_data *data, float x, float y);

/* events.c : fichier validé */
int	key_pressed(int key, t_data *data);
int	key_released(int key, t_data *data);
int	cross_pressed(t_data *data);

/* player.c : fichier validée */
void	update_player(t_data *data);

/* init_player.c : fichier validé */
void	init_player(t_data *data);

/* raycasting.c : fichier validé */
void	cast_all_rays(t_data *data);
float	normalize_angle(float angle);

/* ray_intercept.c : fichier validé */
void	horizontal_intercept(t_ray *ray, t_data *data);
void	vertical_intercept(t_ray *ray, t_data *data);

/* render.c */
void	render_background(t_data *data);
void	render_walls(t_data *data);		// pour l'instant affiche juste des couleurs, pas les textures
void	render_minimap(t_data *data);
void	render_player(t_data *data);

/* draw.c */
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_color_rect(t_img *img, t_to_draw *to_draw);
void	draw_circle(t_img *img, t_point *center, int radius, int color);
void	draw_ray(t_img *img, t_point *start, float angle, int distance);

/* parsing.c */
int	parsing(int fd, t_data *data);

/* check_description.c */
int	check_description(t_data *data);

/* check_map.c */
int	check_map(t_list **lst, t_data *data);

/* get_map.c */
char	*line_no_space(char *line);
int		create_map(t_list *lst, t_data *data);

/* point.c */
void	set_point(t_point *point, double x, double y);
double	distance(t_point a, t_point b);
t_point	create_point(double x, double y);

#endif