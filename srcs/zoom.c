/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:36:17 by bbear             #+#    #+#             */
/*   Updated: 2019/03/21 19:01:07 by bbear            ###   ########.fr       */
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

	fract->zoom *= zoom;
	mre = (double)x / (fract->wid / (fract->maxre - fract->minre)) + fract->minre;
	mim = (double)y / (fract->hei / (fract->maxim - fract->minim)) + fract->minim;
	interpolation = 1.0 / zoom;
	fract->minre = interpolate(mre, fract->minre, interpolation);
	fract->maxre = interpolate(mre, fract->maxre, interpolation);
	fract->minim = interpolate(mim, fract->minim, interpolation);
	fract->maxim = interpolate(mim, fract->maxim, interpolation);
}
