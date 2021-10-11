/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:07:51 by aborboll          #+#    #+#             */
/*   Updated: 2021/10/11 18:01:44 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core.h"

t_core	*initialize(int argc, char **argv)
{
	t_core	*core;

	core = malloc(sizeof(t_core));
	ft_bzero(core, sizeof(t_core));
	core->n_ph = ft_atoi(argv[1]);
	core->t_d = ft_atoi(argv[2]);
	core->t_eat = ft_atoi(argv[3]);
	core->t_sleep = ft_atoi(argv[4]);
	core->start_time = get_time();
	core->any_died = false;
	core->all_ate = false;
	core->ph = (t_philo *)ft_calloc(core->n_ph + 1, sizeof(t_philo));
	core->shared_mutex = malloc(sizeof(pthread_mutex_t));
	if (argc == 6)
		core->n_times = ft_atoi(argv[5]);
	else
		core->n_times = 1;
	return (core);
}

static	void	fill_philo(t_core *core, size_t i)
{
	t_philo	*ph;

	ph = &core->ph[i];
	ph->n_ph = core->n_ph;
	ph->t_d = core->t_d;
	ph->t_eat = core->t_eat;
	ph->t_sleep = core->t_sleep;
	ph->n_times = core->n_times;
	ph->start_time = core->start_time;
	ph->any_died = &core->any_died;
	ph->shared_mutex = core->shared_mutex;
	if (ph->n == 1)
	{
		core->ph[core->n_ph].forks.right = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(core->ph[core->n_ph].forks.right, NULL);
	}
	if (ph->n < core->n_ph)
	{
		ph->forks.right = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(ph->forks.right, NULL);
	}
	if (ph->n > 1)
		ph->forks.left = core->ph[ph->n - 1].forks.right;
	else
		ph->forks.left = core->ph[core->n_ph].forks.right;
}

static	void	*monitor(void *arg)
{
	t_philo	*ph;
	t_llong	times;

	times = 0;
	ph = ((t_philo *)arg);
	ph->tm_time = ph->start_time;
	ph->last_meal = ph->start_time;
	while (times < ph->n_times && !ph->all_ate[0])
	{
		ph->start_time = get_time();
		forking(ph);
		eating(ph);
		sleeping(ph);
		thinking(ph);
		if (ph->n_times > 1)
			times++;
	}
	return (NULL);
}

static	t_bool	check_loop(t_core *core)
{
	size_t	i;
	size_t	e;

	while (1)
	{
		if (core->any_died)
			return (false);
		i = 0;
		e = 0;
		while (++i <= core->n_ph)
		{
			if ((size_t)(get_time() - core->ph[i].last_meal) >= core->ph[i].t_d
					&& core->ph[i].n_times < core->n_times)
				return (!died(&core->ph[i]));
			if (!ft_strcmp(core->ph[i].status, "died"))
				return (false);
			else if (!ft_strcmp(core->ph[i].status, "thinking"))
				e++;
		}
		if (core->n_ph > 1 && e == core->n_ph)
		{
			core->all_ate = true;
			return (true);
		}
	}
}

t_bool	initialize_threads(t_core *core)
{
	int			err;
	size_t		i;

	i = 1;
	pthread_mutex_init(core->shared_mutex, NULL);
	while (i <= core->n_ph)
	{
		core->ph[i].n = i;
		core->ph[i].status = "thinking";
		core->ph[i].all_ate = &core->all_ate;
		fill_philo(core, i);
		err = pthread_create(&core->ph[i].thread, NULL, monitor,
				(void *)&core->ph[i]);
		if (err)
		{
			ft_error(strerror(err));
			return (false);
		}
		i++;
	}
	return (check_loop(core));
}
