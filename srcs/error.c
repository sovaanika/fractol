/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:16:05 by bbear             #+#    #+#             */
/*   Updated: 2019/03/11 19:47:22 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_error(int nb)
{
	if (nb == 1)
		ft_putendl("Empty file");
	else if (nb == 2)
		ft_putendl("Map error");
	else if (nb == 3)
		ft_putendl("No input file");
	exit(EXIT_FAILURE);
}
