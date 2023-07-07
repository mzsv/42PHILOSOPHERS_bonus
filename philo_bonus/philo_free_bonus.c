/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:13:43 by amenses-          #+#    #+#             */
/*   Updated: 2023/05/24 15:52:24 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	datafree(t_data *d)
{
	if (d->cap != NULL)
		free(d->cap);
	free(d);
	return (0);
}

void	philofree(t_philo *p)
{
	t_philo	*tmp;
	t_philo	*next;

	tmp = p;
	next = tmp;
	datafree(p->d);
	if (p != NULL)
	{
		while (tmp->next != NULL && tmp->next != p)
		{
			next = tmp->next;
			free(tmp);
			tmp = next;
		}
		free(tmp);
	}
}

int	semunlinker(void)
{
	if (sem_unlink("forks") != 0 || sem_unlink("print") != 0)
	{
		printf("Error: sem_unlink (forks)\n");
		return (1);
	}
	if (sem_unlink("death") != 0 || sem_unlink("end") != 0)
	{
		printf("Error: sem_unlink (death)\n");
		return (1);
	}
	if (sem_unlink("time") != 0 || sem_unlink("go") != 0)
	{
		printf("Error: sem_unlink (time)\n");
		return (1);
	}
	return (0);
}

int	semdestroyer(t_data *d)
{
	if (sem_close(d->sem_forks) != 0 || sem_close(d->sem_print) != 0)
	{
		printf("Error: sem_close (forks)\n");
		return (1);
	}
	if (sem_close(d->sem_death) != 0 || sem_close(d->sem_end) != 0)
	{
		printf("Error: sem_close (death)\n");
		return (1);
	}
	if (sem_close(d->sem_time) != 0 || sem_close(d->sem_go) != 0)
	{
		printf("Error: sem_close (time)\n");
		return (1);
	}
	if (semunlinker() == 1)
		return (1);
	return (0);
}
