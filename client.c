/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:19:56 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/26 22:54:19 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	send_string(int server_pid, char *str)
// {
// 	int	counter;
// 	int	j;

// 	counter = 0;
// 	while (str[counter])
// 	{
// 		j = 0;
// 		while (j < 8)
// 		{
// 			if ((str[counter] & (1 << j)) != 0)
// 				kill(server_pid, SIGUSR1);
// 			else
// 				kill(server_pid, SIGUSR2);
// 			j++;
// 			usleep(400);
// 		}
// 		counter++;
// 	}
// }
void	send_string(int server_pid, char *str)
{
	int	i;

	while (*str)
	{
		i = 0;
		while (i < 8)
		{
			if ((*str & (1 << i)) != 0)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			i++;
			usleep(400);
		}
		str++;
	}
}
// int	main(int argc, char **argv)
// {
// 	if (argc != 3)
// 		return (1);
// 	send_string(ft_atoi(argv[1]), argv[2]);
// 	return (0);
// }
int	main(int argc, char **argv)
{
	if (!(argc == 3))
		exit(1);
	send_string(ft_atoi(argv[1]), argv[2]);
	return (0);
}