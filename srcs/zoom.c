/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:36:17 by bbear             #+#    #+#             */
/*   Updated: 2019/03/15 20:39:20 by bbear            ###   ########.fr       */
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

void	zoomin(int x, int y, t_fract *fract)
{
	double	mre;
	double	mim;
	double	interpolation;

	mre = x / (fract->wid / (fract->maxre - fract->minre)) + fract->minre;
	mim = y / (fract->hei / (fract->maxim - fract->minim)) + fract->minim;
	interpolation = 1.0 / 1.1;
	fract->minre = interpolate(mre, fract->minre, interpolation);
	fract->maxre = interpolate(mre, fract->maxre, interpolation);
	fract->minim = interpolate(mim, fract->minim, interpolation);
	fract->maxim = interpolate(mim, fract->maxim, interpolation);
}
