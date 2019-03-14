/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:36:17 by bbear             #+#    #+#             */
/*   Updated: 2019/03/14 20:38:09 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		zoom(int button, int x, int y, void *param)
{
	t_fract	*fract;

	fract = (t_fract *)param;
	if (button == 4)
		zoomin(x, y, fract);
	else if (button == 5)
		zoomout(x, y, fract);
	return (0);
}

int		zoomin(void *param)
{


}