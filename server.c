/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 18:05:47 by tapetros          #+#    #+#             */
/*   Updated: 2021/07/25 18:05:50 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int signum)
{
	static char c = 0;
	static int count = 0;

	if (signum == SIGUSR1)
		c |= (1 << count);
	count++;
	if(count == 8)
	{
		ft_putchar(c,1);
		count = 0;
		c = 0;
	}
}

int main()
{
	pid_t PID;

	PID = getpid();
	ft_putstr_fd("The process ID is ",1);
	ft_putnbr_fd(PID,1);
	write(1,"\n",1);
	struct sigaction sact;

	sigemptyset(&sact.sa_mask);
	sact.sa_flags = SA_SIGINFO;
	sact.sa_handler = handler;
	
	sigaction(SIGUSR1, &sact, NULL);
	sigaction(SIGUSR2, &sact, NULL);
	while(1);
	return (0);
}
