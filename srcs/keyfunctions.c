/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:24:27 by bbear             #+#    #+#             */
/*   Updated: 2019/03/14 19:59:35 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		key_press(int key, void *param)
{
	t_fract	*fract;

	fract = (t_fract *)param;
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 69 || key == 78)
	{
		if (key == 69)
			fract->maxiter += 100;
		else
			fract->maxiter -= 100;
		draw(fract);
	}
	// else if (key == 27 || key == 24 || key == 25 || key == 29)
	// 	winresize(key, fract);
	return (0);
}

int		ft_close(void)
{
	exit(0);
	return (0);
}
