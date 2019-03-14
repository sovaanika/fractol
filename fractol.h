/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 18:31:51 by bbear             #+#    #+#             */
/*   Updated: 2019/03/14 19:59:40 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include "./libft/libft.h"

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
	double		maxre;
	double		maxim;
	double		minre;
	double		minim;
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
	t_frac		frac;
}				t_fract;

int		key_press(int key, void *param);
int		ft_close(void);
//void	winresize(int key, t_fract *fract);
void	julia(t_fract *fract);
void	mandelbrot(t_fract *fract);
int		mouse_move(int x, int y, void *param);
void	draw(t_fract *fract);

#endif
