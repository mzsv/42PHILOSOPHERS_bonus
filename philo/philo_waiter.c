/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_waiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:41:26 by amenses-          #+#    #+#             */
/*   Updated: 2023/05/17 17:14:56 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_forks(t_philo *p, t_fork *f)
{
	t_philo	*tmp;

	tmp = p;
	while (tmp->next != NULL && tmp->next != p)
	{
		tmp->f[(tmp->id - 1) % 2] = &f[tmp->id - 1];
		tmp->f[tmp->id % 2] = &f[tmp->id];
		tmp = tmp->next;
	}
	if (p->d->n_philo == 2)
	{
		tmp->f[0] = &f[0];
		tmp->f[1] = &f[1];
		return ;
	}
	tmp->f[0] = &f[tmp->id - 1];
	if (tmp->id > 1)
		tmp->f[1] = &f[0];
}

int	forkcheck(t_philo *p, int fork_id, int philo_id)
{
	int	status;

	status = 0;
	if (pthread_mutex_lock(p->d->mtx_fcheck.mtx) == 0)
	{
		if (p->f[fork_id]->philo_id != philo_id)
			status = -1;
		if (pthread_mutex_unlock(p->d->mtx_fcheck.mtx) != 0)
		{
			printf("Error: pthread_mutex_unlock (mtx_fcheck)\n");
			return (1);
		}
	}
	else
	{
		printf("Error: pthread_mutex_lock (mtx_fcheck)\n");
		return (1);
	}
	return (status);
}

int	forkupdate(t_philo *p, int fork_id, int philo_id)
{
	if (pthread_mutex_lock(p->d->mtx_fcheck.mtx) == 0)
	{
		p->f[fork_id]->philo_id = philo_id;
		if (pthread_mutex_unlock(p->d->mtx_fcheck.mtx) != 0)
		{
			printf("Error: pthread_mutex_unlock (mtx_fcheck)\n");
			return (1);
		}
	}
	else
	{
		printf("Error: pthread_mutex_lock (mtx_fcheck)\n");
		return (1);
	}
	return (0);
}

int	drop_fork(t_philo *p, int fork_id)
{
	if (p->f[fork_id] == NULL)
		return (0);
	if (forkcheck(p, fork_id, p->id) == 0)
	{
		forkupdate(p, fork_id, 0);
		if (pthread_mutex_unlock(p->f[fork_id]->mtx) != 0)
		{
			printf("Error: pthread_mutex_unlock (fork)\n");
			return (1);
		}
	}
	return (0);
}

int	join_threads(t_philo *p)
{
	t_philo	*tmp;

	tmp = p;
	while (tmp->next != NULL && tmp->next != p)
	{
		if (pthread_join(tmp->thread, NULL) != 0)
		{
			printf("Error: pthread_join\n");
			return (1);
		}
		tmp = tmp->next;
	}
	if (pthread_join(tmp->thread, NULL) != 0)
	{
		printf("Error: pthread_join\n");
		return (1);
	}
	return (0);
}
