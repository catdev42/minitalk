/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:17:48 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/26 18:59:44 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void	decode(int sig)
{
	static unsigned char	c;
	static int				i;

	if (sig == SIGUSR1)
		c |= 1 << i;
	if (i++ == 7)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}
int	main(void)
{
	int pid_server;
	struct sigaction sig;

	pid_server = getpid();
	ft_printf("%d \n", pid_server);
    sig.sa_handler = decode;
    SIGUSR1;
}