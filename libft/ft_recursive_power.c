/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:41:57 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/26 15:45:31 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_recursive_power(int num, int pow)
{
	if (pow == 0)
		return (1);
	if (pow < 0)
		return (0);
	return (num * ft_recursive_power(num, pow - 1));
}
