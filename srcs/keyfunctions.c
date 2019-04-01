/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:24:27 by bbear             #+#    #+#             */
/*   Updated: 2019/04/01 19:52:32 by bbear            ###   ########.fr       */
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
	}
	else if (key == 125 || key == 126 || key == 123 || key == 124)
		move(key, fract);
	else if (key == 27 || key == 24)
		winresize(key, fract);
	else if (key == 8)
		changeflag(fract);
	else if (key == 15 || key == 5 || key == 11)
		changecolor(fract, key);
	draw(fract);
	return (0);
}

int		ft_close(void)
{
	exit(0);
	return (0);
}

void	changeflag(t_fract *f)
{
	if (f->colorflag)
		f->colorflag--;
	else
		f->colorflag++;
}
