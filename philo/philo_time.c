/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:53:21 by amenses-          #+#    #+#             */
/*   Updated: 2023/05/17 17:15:53 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_time(struct timeval *t)
{
	if (gettimeofday(t, NULL) == -1)
	{
		printf("Error: gettimeofday\n");
		return (1);
	}
	return (0);
}

long long	utimestamp(struct timeval t0)
{
	struct timeval	t;

	if (set_time(&t) == 1)
		return (-1);
	t.tv_sec = t.tv_sec - t0.tv_sec;
	t.tv_usec = t.tv_usec - t0.tv_usec;
	if (t.tv_usec < 0)
	{
		t.tv_usec += 1000000;
		t.tv_sec -= 1;
	}
	return (t.tv_sec * 1000000 + t.tv_usec);
}

long long	utime(struct timeval t)
{
	return (t.tv_sec * 1000000 + t.tv_usec);
}

long long	deltatime(struct timeval t0, struct timeval t1)
{
	return ((utime(t1) - utime(t0)) / 1000);
}
