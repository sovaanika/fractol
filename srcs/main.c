/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 18:31:18 by bbear             #+#    #+#             */
/*   Updated: 2019/03/13 20:01:53 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		mouse_move(int x, int y, void *param)
{
	t_fract	*fract;

	fract = (t_fract *)param;
	if (x > fract->x)
		fract->frac.cre += 0.0025;
	else if (x < fract->x)
		fract->frac.cre -= 0.0025;
	if (y > fract->y)
		fract->frac.cim += 0.0025;
	else if (y < fract->y)
		fract->frac.cim -= 0.0025;
	fract->x = x;
	fract->y = y;
	draw(fract);
	return (0);
}

int		main(void)
{
	t_fract	*fract;

	fract = (t_fract *)malloc(sizeof(*fract));
	fract->mlx_ptr = mlx_init();
	fract->wid = 1500;
	fract->hei = 1500;
	fract->frac.cre = -0.70176;
	fract->frac.cim = -0.3842;
	fract->x = 0;
	fract->y = 0;
	fract->win_ptr = mlx_new_window(fract->mlx_ptr, fract->wid, fract->hei, "fract");
	fract->img_ptr = mlx_new_image(fract->mlx_ptr, fract->wid, fract->hei);
	fract->data = (int *)mlx_get_data_addr(fract->img_ptr, &fract->bpp,
	&fract->size_l, &fract->end);
	//mandelbrot(fract);
	julia(fract);
	mlx_key_hook(fract->win_ptr, key_press, (void *)fract);
	mlx_hook(fract->win_ptr, 6, 0, mouse_move, (void *)fract);
	mlx_hook(fract->win_ptr, 17, 0, ft_close, (void *)0);
	mlx_loop(fract->mlx_ptr);
}