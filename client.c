/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:19:56 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/27 15:59:48 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_string(int server_pid, char *str)
{
	int	counter;
	int	j;

	counter = 0;
	while (str[counter])
	{
		j = 0;
		while (j < 8)
		{
			if ((str[counter] & (1 << j)) != 0)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			j++;
			usleep(400);
		}
		counter++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	send_string(ft_atoi(argv[1]), argv[2]);
	return (0);
}