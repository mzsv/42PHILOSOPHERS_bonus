/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:45:48 by amenses-          #+#    #+#             */
/*   Updated: 2023/05/17 21:09:56 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philo_new(int id, t_data *data)
{
	t_philo	*p;
	t_fork	f[2];

	p = malloc(sizeof(t_philo));
	if (!p)
		return (NULL);
	ft_bzero(p, sizeof(t_philo));
	ft_bzero(f, sizeof(t_fork) * 2);
	p->id = id;
	p->d = data;
	if (data->n_philo > 2 && id % 2 == 0)
		p->go = 1;
	return (p);
}

void	philo_add(t_philo **p, t_philo *new)
{
	t_philo	*tmp;

	if (!*p)
	{
		*p = new;
		return ;
	}
	tmp = *p;
	while (tmp->id != new->id - 1)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	new->next = *p;
	(*p)->prev = new;
}

t_philo	*philo_init(t_data *data)
{
	int		i;
	t_philo	*p;
	t_philo	*new;

	p = NULL;
	new = NULL;
	i = 0;
	while (++i <= data->n_philo)
	{
		new = philo_new(i, data);
		if (!new)
		{
			philofree(p, NULL);
			datafree(data);
			return (NULL);
		}
		philo_add(&p, new);
	}
	return (p);
}

int	set_threads(t_philo *p)
{
	t_philo	*tmp;

	tmp = p;
	while (tmp->next != NULL && tmp->next != p)
	{
		if (pthread_create(&tmp->thread, NULL, philo_routine, (void *)tmp) != 0)
		{
			printf("Error: pthread_create\n");
			return (1);
		}
		tmp = tmp->next;
	}
	if (pthread_create(&tmp->thread, NULL, philo_routine, (void *)tmp) != 0)
	{
		printf("Error: pthread_create\n");
		return (1);
	}
	return (0);
}
