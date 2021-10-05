/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:07:51 by aborboll          #+#    #+#             */
/*   Updated: 2021/10/05 21:43:46 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core.h"

t_core	*initialize(int argc, char **argv)
{
	t_core	*core;

	core = malloc(sizeof(t_core));
	ft_bzero(core, sizeof(t_core));
	core->n_ph = ft_atoi(argv[1]);
	core->t_die = ft_atoi(argv[2]);
	core->t_eat = ft_atoi(argv[3]);
	core->t_sleep = ft_atoi(argv[4]);
	core->start_time = get_time();
	core->any_died = false;
	core->philo = (t_philo *)ft_calloc(core->n_ph + 1, sizeof(t_philo));
	core->shared_mutex = malloc(sizeof(pthread_mutex_t));
	if (argc == 6)
		core->n_times = ft_atoi(argv[5]);
	else
		core->n_times = 1;
	return (core);
}

static	void	fill_philo(t_core *core, size_t i)
{
	t_philo	*philo;

	philo = &core->philo[i];
	philo->n_ph = core->n_ph;
	philo->t_die = core->t_die;
	philo->t_eat = core->t_eat;
	philo->t_sleep = core->t_sleep;
	philo->n_times = core->n_times;
	philo->start_time = core->start_time;
	philo->any_died = &core->any_died;
	philo->shared_mutex = core->shared_mutex;
	if (philo->n == 1)
	{
		core->philo[core->n_ph].forks.right = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(core->philo[core->n_ph].forks.right, NULL);
	}
	if (philo->n < core->n_ph)
	{
		philo->forks.right = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo->forks.right, NULL);
	}
	if (philo->n > 1)
		philo->forks.left = core->philo[philo->n - 1].forks.right;
	else
		philo->forks.left = core->philo[core->n_ph].forks.right;
}

static	void	*monitor(void *arg)
{
	t_philo	*philo;
	t_llong	times;

	times = 0;
	philo = ((t_philo *)arg);
	philo->tm_time = philo->start_time;
	philo->last_meal = philo->start_time;
	while (times < philo->n_times)
	{
		philo->start_time = get_time();
		forking(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
		if (philo->n_times > 1)
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
		i = 1;
		e = 0;
		while (i <= core->n_ph)
		{
			if ((size_t)(get_time() - core->philo[i].last_meal)
				>= core->philo[i].t_die
					&& core->philo[i].n_times < core->n_times)
				return (!died(&core->philo[i]));
			if (!ft_strcmp(core->philo[i].status, "died"))
				return (false);
			else if (!ft_strcmp(core->philo[i].status, "thinking"))
				e++;
			i++;
		}
		if (core->n_ph > 1 && e == core->n_ph)
			return (true);
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
		core->philo[i].n = i;
		core->philo[i].status = "thinking";
		fill_philo(core, i);
		err = pthread_create(&core->philo[i].thread, NULL, monitor,
				(void *)&core->philo[i]);
		if (err)
		{
			ft_error(strerror(err));
			return (false);
		}
		i++;
	}
	return (check_loop(core));
}
