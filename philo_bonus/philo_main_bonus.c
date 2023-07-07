/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:28:37 by amenses-          #+#    #+#             */
/*   Updated: 2023/05/24 15:53:23 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*d;
	t_philo	*p;

	if (argccheck(argc) == 1 || inputcheck(argv) == 1)
		return (1);
	d = get_data(argv);
	if (!d)
		return (1);
	p = philo_init(d);
	if (!p)
		return (1);
	if (seminit(d) == 1 || set_processes(p) == 1)
	{
		philofree(p);
		return (1);
	}
	philo_waiter(p);
	semdestroyer(d);
	philofree(p);
	return (0);
}
