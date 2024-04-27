/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:18:17 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/25 16:45:02 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		pid_server;
	int		i;
	char	*bitarray;

	if (argc != 3)
		return (err(1));
	i = 0;
	while (argv[1][i] >= '0' && argv[1][i++] <= '9')
		if (argv[1][i] < '0' || argv[1][i] > '9')
			return (err(2));
	i = 0;
	pid_server = atoi(argv[1]);
	if (pid_server <= 0)
		return (-1);
	bitarray = make_bit_array(argv[2]);
	if (!bitarray)
		return (err(3));
}

char	*make_bit_array(char *string)
{
	int		len;
	int		i;
	int		j;
	char	*bitarray;

	len = ft_strlen(string);
	len = len * 8;
	bitarray = ft_calloc(len + 2, sizeof(char));
	if (!bitarray)
		return (0);
}

int	err(int error)
{
	if (error == 1)
	{
		ft_putstr_fd("Please enter the server PID and the STRING to send.", 2);
		return (1);
	}
	if (error == 2)
	{
		ft_putstr_fd("The PID must be a number", 2);
		return (2);
	}
	if (error == 3)
	{
		ft_putstr_fd("Problems with malloc", 2);
		return (3);
	}
}