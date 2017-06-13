/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:23:44 by ksaetern          #+#    #+#             */
/*   Updated: 2017/04/27 16:23:51 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/include/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "./minilibx_macos/mlx.h"

# define KEY_ENTER  36
# define KEY_ESC    53
# define KEY_MORE_1 69
# define KEY_MORE_2 24
# define KEY_LESS_1 78
# define KEY_LESS_2 27
# define KEY_TOP    126
# define KEY_LEFT   123
# define KEY_BOTTOM 125
# define KEY_RIGHT  124
# define KEY_D      2
# define KEY_C      8

typedef struct		s_hooks
{
	int				zr;
	int				yr;
	int				xr;
	int				xt;
	int				yt;
	int				zs;
}					t_hooks;

typedef	struct		s_map
{
	int				**map;
	int				hmin;
	int				hmax;
	int				w;
	int				h;
	int				midx;
	int				midy;
	float			xpixelloc;
	float			ypixelloc;
}					t_map;

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	float			rawz;
}					t_points;

typedef	struct		s_bresen
{
	float			offset;
	float			threshold;
	float			adjust;
	float			delta;
	float			tmp;
	int				colorgrade;
	float			color;
	float			range;
	char			*str;
	char			**coord;
	char			*line;
}					t_bresen;

typedef struct		s_fdf
{
	t_hooks			*hooks;
	t_points		**cart;
	float			y1;
	float			x1;
	float			x2;
	float			y2;
	int				hmin;
	int				hmax;
	float			curr_z;
	float			next_z;
	int				w;
	int				h;
	int				big;
	int				gap;
	int				i;
	int				j;
	float			m;
	float			rise;
	float			run;
	float			max;
	float			maxside;
	void			*mlx;
	void			*win;
}					t_env;

int					hook_funct(int keycode, t_env *fdf);
void				ft_hooked(t_hooks **hooks);
int					ft_findw(char **coord);
void				ft_error(char *str);
void				ft_parse(char *av);
char				*ft_put(char **s, int w);
void				ft_zvalue(int fd, t_map *list);
int					ft_findw(char **coord);
void				ft_findwh(int fd, t_map *list);
void				ft_store(char *av, t_map *list);
int					hook_funct(int keycode, t_env *fdf);
void				ft_makewindow(t_map *list);
t_env				*ft_makeenviroment(t_map *m);
void				ft_draw(t_env *fdf, t_hooks *hooks);
void				ft_rotate(t_env *fdf, t_hooks *hooks);
void				ft_slopestraight(t_env *fdf);
void				ft_slopegradual(t_env *fdf, t_bresen *breezy);
void				ft_slopesharp(t_env *fdf, t_bresen *breezy);
int					ft_color(t_env *fdf, t_bresen *breezy, float distance);
void				ft_translate(t_env **f, t_hooks *hooks);

#endif
