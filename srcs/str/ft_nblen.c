/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 11:07:46 by nle-bret          #+#    #+#             */
/*   Updated: 2016/10/22 11:07:50 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nblen(long long value)
{
	int		i;

	i = 0;
	if (value < 0)
		i++;
	if (value == 0)
		i++;
	while (value)
	{
		value /= 10;
		i++;
	}
	return (i);
}
