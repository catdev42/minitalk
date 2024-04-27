/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_old2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:18:17 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/27 15:57:08 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>

char	*make_bit_array(char *string);
int		err(int error);

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i++] = '\0';
	}
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

int	main(int argc, char **argv)
{
	int		pid_server;
	int		i;
	char	*bitarray;
	int		length_of_string;

	if (argc != 3)
		return (err(1));
	i = 0;
	while (argv[1][i] >= '0' && argv[1][i] <= '9')
		if (argv[1][i] < '0' || argv[1][i++] > '9')
			return (err(2));
	i = 0;
	pid_server = atoi(argv[1]);
	if (pid_server <= 0)
		return (-1);
	bitarray = make_bit_array(argv[2]);
	if (!bitarray)
		return (err(3));
	length_of_string = bit_to_int(bitarray);
}

int	bit_to_int(char *bitarray)
{
	int	i;
	int	j;
	int	intofbit;
	int	num;

	// int	len;
	num = 0;
	// len = ft_strlen(bitarray);
	i = 0;
	while (bitarray[i])
	{
		j = 7;
		while (j >= 0)
		{
			intofbit = bitarray[8 * i + j] - 48;
			if (intofbit == 1)
				num = num + (ft_recursive_power(2, 7 - j));
			j--;
		}
		i++;
	}
}

char	*make_bit_array(char *string)
{
	int		len;
	int		i;
	int		j;
	int		intofbit;
	char	*bitarray;

	len = ft_strlen(string);
	len = len * 8;
	bitarray = ft_calloc(len + 2, sizeof(char));
	if (!bitarray)
		return (0);
	i = 0;
	while (string[i])
	{
		j = 7;
		while (j >= 0)
		{
			intofbit = string[i];
			string[i] >> j & 1;
			printf("%i", intofbit);
			bitarray[8 * i + j] = intofbit;
			j--;
		}
		i++;
	}
	return (bitarray);
}

int	err(int error)
{
	// if (error == 1)
	// {
	// 	ft_putstr_fd("Please enter the server PID and the STRING to send.", 2);
	// 	return (1);
	// }
	// if (error == 2)
	// {
	// 	ft_putstr_fd("The PID must be a number", 2);
	// 	return (2);
	// }
	// if (error == 3)
	// {
	// 	ft_putstr_fd("Problems with malloc", 2);
	// 	return (3);
	// }
	return (0);
}