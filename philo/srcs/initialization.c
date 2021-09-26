/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:07:51 by aborboll          #+#    #+#             */
/*   Updated: 2021/09/26 18:04:39 by aborboll         ###   ########.fr       */
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
	core->philo = (t_philo *)ft_calloc(core->n_ph + 1, sizeof(t_philo));
	if (argc == 6)
		core->n_times = ft_atoi(argv[5]);
	else
		core->n_times = -1;
	return (core);
}

static	void	*fill_philo(t_core *core, size_t i)
{
	t_philo	*philo;

	philo = &core->philo[i];
	philo->n = i;
	philo->t_die = core->t_die;
	philo->t_eat = core->t_eat;
	philo->t_sleep = core->t_sleep;
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
	return (NULL);
}

static	void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = ((t_philo *)arg);
	forking(philo);
	eating(philo);
	usleep(philo->t_eat * 1000);
	sleeping(philo);
	return (NULL);
}

t_bool	initialize_threads(t_core *core)
{
	int			err;
	size_t		i;

	i = 1;
	while (i <= core->n_ph)
	{
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
	i = 0;
	while (i < core->n_ph)
		pthread_join(core->philo[i++].thread, NULL);
	return (true);
}
