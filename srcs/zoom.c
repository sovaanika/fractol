/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:36:17 by bbear             #+#    #+#             */
/*   Updated: 2019/03/26 20:02:15 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	zoom(int x, int y, t_fract *f, double zoom)
{
	double	flag;

	f->zoom *= zoom;
	flag = 1;
	if (zoom == 0.9)
		flag = -1;
	f->movey += flag * ((y - 0.5 * f->hei) / 3500.0 / f->zoom / 1.5);
	f->movex += flag * ((x - 0.5 * f->wid) / 3500.0 / f->zoom / 1.5);
}
