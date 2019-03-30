/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:10:28 by bbear             #+#    #+#             */
/*   Updated: 2019/03/26 17:12:01 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	move(int key, t_fract *fract)
{
	if (key == 125)
		fract->starty += 10;
	else if (key == 126)
		fract->starty -= 10;
	else if (key == 123)
		fract->startx -= 10;
	else
		fract->startx += 10;
	draw(fract);
}
