/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_readinput.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:20:44 by amenses-          #+#    #+#             */
/*   Updated: 2023/05/19 16:15:13 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	t_data	*data;

	data = malloc(sizeof(t_data));
	ft_bzero(data, sizeof(t_data));
	data->n_philo = ft_long_atoi(argv[1]);
	data->t_die = ft_long_atoi(argv[2]);
	data->t_eat = ft_long_atoi(argv[3]);
	data->t_sleep = ft_long_atoi(argv[4]);
	data->end = 0;
	if (argv[5] != NULL)
	{
		data->cap = malloc(sizeof(long long));
		*data->cap = ft_long_atoi(argv[5]);
		data->end = 1 - data->n_philo;
	}
	if (datacheck(data) == 1 && datafree(data) == 0)
		return (NULL);
	data->t_die = data->t_die * 1000;
	data->t_eat = data->t_eat * 1000;
	data->t_sleep = data->t_sleep * 1000;
	if ((data->t_die - data->t_eat - data->t_sleep) / 2 > 0)
		data->t_think = (data->t_die - data->t_eat - data->t_sleep) / 2;
	return (data);
}
