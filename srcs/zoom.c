/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:36:17 by bbear             #+#    #+#             */
/*   Updated: 2019/03/25 19:55:13 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// int		zoom(int button, int x, int y, void *param)
// {
// 	t_fract	*fract;

// 	fract = (t_fract *)param;
// 	if (button == 4)
// 		zoomin(x, y, fract);
// 	// else if (button == 5)
// 	// 	zoomout(x, y, fract);
// 	return (0);
// }

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	zoomin(int x, int y, t_fract *fract, double zoom)
{
	double	mre;
	double	mim;
	double	interpolation;
	double	flag;

	fract->zoom *= zoom;
	flag = 1;
	if (zoom == 0.9)
		flag = -1;
	mre = (double)x / (fract->wid / (fract->maxre - fract->minre)) + fract->minre;
	mim = (double)y / (fract->hei / (fract->maxim - fract->minim)) + fract->minim;
	fract->mre = mre;
	fract->mim = mim;
	interpolation = 1.0 / zoom;
	fract->minre = interpolate(mre, fract->minre, interpolation);
	fract->maxre = interpolate(mre, fract->maxre, interpolation);
	fract->minim = interpolate(mim, fract->minim, interpolation);
	fract->maxim = interpolate(mim, fract->maxim, interpolation);
	fract->movey += flag * ((y - 0.5 * fract->hei) / 3500.0 / fract->zoom / 1.5);
	fract->movex += flag * ((x - 0.5 * fract->wid) / 3500.0 / fract->zoom / 1.5);
	// printf("%f\n", fract->minre);
	// printf("%f\n", fract->maxre);
	// printf("%f\n", fract->minim);
	// printf("%f\n", fract->maxim);
}
