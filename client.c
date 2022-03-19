/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 18:05:19 by tapetros          #+#    #+#             */
/*   Updated: 2021/07/25 18:05:23 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send(int pid, char *msg, int len)
{
    int i = 0;
    int n;

    while(i < len)
    {
        n = 0;
        while (n <= 7)
        {
            if((msg[i] >> n) & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            n++;
            usleep(100);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        ft_putstr_fd("Wrong number of arguments\nusage: ./client [pid] [message]",1);
        exit(0);
    }
    send(ft_atoi(argv[1]), argv[2], ft_strlen(argv[2]));
    return (0);
}
