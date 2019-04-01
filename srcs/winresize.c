/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winresize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 18:52:25 by bbear             #+#    #+#             */
/*   Updated: 2019/04/01 16:46:51 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	winresize(int key, t_fract *f)
{
	if (key == 27)
	{
		f->hei -= 10;
		f->wid -= 10;
		f->thread--;
	}
	else if (key == 24)
	{
		f->hei += 10;
		f->wid += 10;
		f->thread++;
	}
	mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	f->data = NULL;
	f->win_ptr = mlx_new_window(f->mlx_ptr, f->wid,
	f->hei, "fractol");
	f->img_ptr = mlx_new_image(f->mlx_ptr, f->wid, f->wid);
	f->data = (int *)mlx_get_data_addr(f->img_ptr, &f->bpp,
	&f->size_l, &f->end);
	mlx_hook(f->win_ptr, 6, 0, mouse_move, (void *)f);
	mlx_key_hook(f->win_ptr, key_press, (void *)f);
	mlx_hook(f->win_ptr, 17, 0, ft_close, (void *)0);
	mlx_mouse_hook(f->win_ptr, mouse_press, (void *)f);
}
