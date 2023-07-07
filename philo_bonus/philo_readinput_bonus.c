/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_readinput_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:20:44 by amenses-          #+#    #+#             */
/*   Updated: 2023/05/24 15:54:54 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	argccheck(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: invalid number of arguments\n");
		return (1);
	}
	return (0);
}

int	inputcheck(char **argv)
{
	int		i;
	char	*t;
	int		sign;

	i = 0;
	while (argv[++i])
	{
		t = argv[i];
		sign = 1;
		while (*t)
		{
			if (((*t == '-' || *t == '+') && sign) || (*t >= '0' && *t <= '9'))
			{
				sign = 0;
				t++;
			}
			else
			{
				printf("Error: invalid arguments\n");
				return (1);
			}
		}
	}
	return (0);
}

int	datacheck(t_data *d)
{
	int	r;

	r = 0;
	if (d->n_philo < 1 || d->n_philo > INTMAX || d->n_philo < INTMIN)
		r = 1;
	if (d->t_die < 0 || d->t_die > INTMAX || d->t_die < INTMIN)
		r = 1;
	if (d->t_eat < 0 || d->t_eat > INTMAX || d->t_eat < INTMIN)
		r = 1;
	if (d->t_sleep < 0 || d->t_sleep > INTMAX || d->t_sleep < INTMIN)
		r = 1;
	if (d->cap != NULL && (*d->cap < 1 || *d->cap > INTMAX || *d->cap < INTMIN))
		r = 1;
	if (r == 1)
		printf("Error: invalid arguments\n");
	return (r);
}

t_data	*get_data(char **argv)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	ft_bzero(d, sizeof(t_data));
	d->n_philo = ft_long_atoi(argv[1]);
	d->t_die = ft_long_atoi(argv[2]);
	d->t_eat = ft_long_atoi(argv[3]);
	d->t_sleep = ft_long_atoi(argv[4]);
	if (argv[5] != NULL)
	{
		d->cap = malloc(sizeof(long long));
		*d->cap = ft_long_atoi(argv[5]);
	}
	if (datacheck(d) == 1 && datafree(d) == 0)
		return (NULL);
	d->t_die = d->t_die * 1000;
	d->t_eat = d->t_eat * 1000;
	d->t_sleep = d->t_sleep * 1000;
	if (d->n_philo % 2 && (d->t_die - d->t_eat - d->t_sleep) / 2 > 0)
		d->t_think = (d->t_die - d->t_eat - d->t_sleep) / 2;
	return (d);
}
