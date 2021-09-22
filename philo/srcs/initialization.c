/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:07:51 by aborboll          #+#    #+#             */
/*   Updated: 2021/09/22 18:52:25 by aborboll         ###   ########.fr       */
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
	core->philo = (t_philo *)ft_calloc(core->n_ph, sizeof(t_philo));
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
	philo->forks.right = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo->forks.right, NULL);
	if (philo->n > 0)
		philo->forks.left = core->philo[philo->n - 1].forks.right;
	if (philo->n == core->n_ph - 1)
		core->philo[0].forks.left = philo->forks.right;
	philo->status = "test";
	if (philo->n != 0)
		report_status(&core->philo[i]);
	if (philo->n == core->n_ph - 1)
		report_status(&core->philo[0]);
	return (NULL);
}

static	void	*test(void *arg)
{
	(void)arg;
	return (NULL);
}

t_bool	initialize_threads(t_core *core)
{
	int			err;
	size_t		i;

	pthread_mutex_init(&core->mutex, NULL);
	i = 0;
	while (i < core->n_ph)
	{
		pthread_mutex_lock(&core->mutex);
		fill_philo(core, i);
		err = pthread_create(&core->philo[i].thread, NULL, test,
				(void *)&core);
		if (err)
		{
			ft_error(strerror(err));
			return (false);
		}
		pthread_mutex_unlock(&core->mutex);
		i++;
	}
	i = 0;
	while (i < core->n_ph)
	{
		pthread_join(core->philo[i++].thread, NULL);
	}
	return (true);
}
