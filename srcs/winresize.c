/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winresize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 18:52:25 by bbear             #+#    #+#             */
/*   Updated: 2019/03/11 20:44:08 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	winresize(int key, t_fract *fract)
{
	if (key == 27)
		fract->hei -= 10;
	else if (key == 24)
		fract->hei += 10;
	else if (key == 25)
		fract->wid -= 10;
	else if (key == 29)
		fract->wid += 10;
	mlx_destroy_image(fract->mlx_ptr, fract->img_ptr);
	mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	fract->data = NULL;
	fract->win_ptr = mlx_new_window(fract->mlx_ptr, fract->wid,
	fract->hei, "fract");
	fract->img_ptr = mlx_new_image(fract->mlx_ptr, fract->wid, fract->wid);
	fract->data = (int *)mlx_get_data_addr(fract->img_ptr, &fract->bpp,
	&fract->size_l, &fract->end);
	mlx_key_hook(fract->win_ptr, key_press, (void *)fract);
	mlx_hook(fract->win_ptr, 17, 0, ft_close, (void *)0);
}
