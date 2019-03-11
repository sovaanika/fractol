/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 18:31:18 by bbear             #+#    #+#             */
/*   Updated: 2019/03/11 20:46:22 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		main(int argc, char **argv)
{
	t_fract	*fract;

	if (argc > 1)
	{
		fract = (t_fract *)malloc(sizeof(*fract));
		fract->mlx_ptr = mlx_init();
		fract->win_ptr = mlx_new_window(fract->mlx_ptr, fract->wid, fract->hei, "fract");
		fract->img_ptr = mlx_new_image(fract->mlx_ptr, fract->wid, fract->wid);
		fract->data = (int *)mlx_get_data_addr(fract->img_ptr, &fract->bpp,
		&fract->size_l, &fract->end);
		mlx_key_hook(fract->win_ptr, key_press, (void *)fract);
		mlx_hook(fract->win_ptr, 17, 0, ft_close, (void *)0);
		mlx_loop(fract->mlx_ptr);
}