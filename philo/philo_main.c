/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:41:17 by amenses-          #+#    #+#             */
/*   Updated: 2023/05/24 16:34:42 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*p;
	t_fork	*f;
	t_data	*d;

	if (argccheck(argc) == 1 || inputcheck(argv) == 1)
		return (1);
	d = get_data(argv);
	if (!d)
		return (1);
	if (set_aux_mutexes(d) == 1 && datafree(d) == 0)
		return (1);
	p = philo_init(d);
	if (!p)
		return (1);
	f = forkinit(p);
	if (!f)
		return (1);
	set_forks(p, f);
	if (set_threads(p) == 1 || join_threads(p) == 1 || destroyer(d, f) == 1)
	{
		philofree(p, f);
		return (1);
	}
	philofree(p, f);
	return (0);
}
