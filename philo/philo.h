/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:30:10 by amenses-          #+#    #+#             */
/*   Updated: 2023/05/19 21:29:03 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define FORK 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DEAD 4
# define INTMAX	2147483647
# define INTMIN	-2147483648

typedef struct s_fork
{
	int				id;
	int				philo_id;
	pthread_mutex_t	*mtx;
}	t_fork;

typedef struct s_data
{
	int				n_philo;
	long long		t_die;
	long long		t_eat;
	long long		t_sleep;
	long long		t_think;
	long long		*cap;
	struct timeval	offset;
	long long		end;
	t_fork			mtx_offset;
	t_fork			mtx_print;
	t_fork			mtx_death;
	t_fork			mtx_fcheck;
	t_fork			mtx_end;
}	t_data;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	t_fork				*f[2];
	t_data				*d;
	struct timeval		t0;
	int					meals;
	int					go;
	struct s_philo		*prev;
	struct s_philo		*next;
}	t_philo;

int			argccheck(int argc);
int			inputcheck(char **argv);
int			datacheck(t_data *d);
t_data		*get_data(char **argv);

int			set_time(struct timeval *t);
long long	utimestamp(struct timeval t0);
long long	utime(struct timeval t);
long long	deltatime(struct timeval t0, struct timeval t1);

t_philo		*philo_new(int id, t_data *data);
void		philo_add(t_philo **p, t_philo *new);
t_philo		*philo_init(t_data *data);
int			set_threads(t_philo *p);

int			set_aux_mutexes(t_data *d);
t_fork		*forkinit(t_philo *p);
int			mtxdestroy(pthread_mutex_t *mtx);
int			destroyer(t_data *d, t_fork *f);

int			grab_fork(t_philo *p, int fork_id);
int			eat(t_philo *p);
int			nap(t_philo *p);
int			think(t_philo *p);
void		*philo_routine(void *philo);

int			set_offset(t_philo *p);
int			endset(t_philo *p, int state);
int			endcheck(t_philo *p);
int			deathcheck(t_philo *p, struct timeval *t);
int			printstate(t_philo *p, int state, struct timeval t);

void		set_forks(t_philo *p, t_fork *f);
int			forkcheck(t_philo *p, int fork_id, int philo_id);
int			forkupdate(t_philo *p, int fork_id, int philo_id);
int			drop_fork(t_philo *p, int fork_id);
int			join_threads(t_philo *p);

int			datafree(t_data *d);
void		forkfree(t_fork *f, int n_philo);
void		philofree(t_philo *p, t_fork *f);

size_t		ft_strlen(const char *s);
long long	ft_long_atoi(const char *nptr);
void		ft_bzero(void *s, size_t n);
long long	ft_min(long long a, long long b);

#endif
