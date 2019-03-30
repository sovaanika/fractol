/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 18:31:51 by bbear             #+#    #+#             */
/*   Updated: 2019/03/30 17:11:16 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/uio.h>
# include "./libft/libft.h"

# define THREAD 120
# define THREAD_W 10

typedef struct	s_frac
{
	double		newim;
	double		newre;
	double		oldre;
	double		oldim;
	int			i;
	int			x;
	int			y;
	double		cre;
	double		cim;
}				t_frac;

typedef struct	s_fract
{
	void		*mlx_ptr;
	void		*img_ptr;
	void		*win_ptr;
	int			*data;
	int			bpp;
	int			size_l;
	int			end;
	int			wid;
	int			hei;
	int			maxiter;
	int			x;
	int			y;
	int			y_max;
	double		buff;
	double		zoom;
	t_frac		frac;
	double		movex;
	double		movey;
	int			flag;
	char		*arg;
}				t_fract;

int				key_press(int key, void *param);
int				ft_close(void);
//void	winresize(int key, t_fract *fract);
void			julia(t_fract *f);
void			mandelbrot(t_fract *f);
int				mouse_move(int x, int y, void *param);
void			draw(t_fract *fract);
//int		zoom(int button, int x, int y, void *param);
void			zoom(int x, int y, t_fract *f, double zoom);
double			interpolate(double start, double end, double interpolation);
int				mouse_press(int button, int x, int y, void *param);
void			fract(t_fract *f);
void			*fract_alg(void *fra);
void			burningship(t_fract *f);
void			trimandelbrot(t_fract *f);
void			biomorph(t_fract *f);

#endif
