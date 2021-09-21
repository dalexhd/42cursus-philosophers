/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:07:51 by aborboll          #+#    #+#             */
/*   Updated: 2021/09/20 17:12:10 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core.h"

int	g_num;

t_core	*initialize(int argc, char **argv)
{
	t_core	*core;

	core = malloc(sizeof(t_core));
	ft_bzero(core, sizeof(t_core));
	core->n_ph = ft_atoi(argv[1]);
	core->t_die = ft_atoi(argv[2]);
	core->t_eat = ft_atoi(argv[3]);
	core->t_sleep = ft_atoi(argv[4]);
	core->philo = (t_philo *)malloc(sizeof(t_philo) * core->n_ph);
	if (argc == 6)
		core->n_times = ft_atoi(argv[5]);
	else
		core->n_times = -1;
	return (core);
}

static	void	*fill_philo(void *arg)
{
	t_philo	*philo;

	philo = ((t_philo *)arg);
	pthread_mutex_init(&philo->mutex, NULL);
	philo->n = g_num;
	philo->status = "sleeping";
	philo->forks.right = 0;
	philo->forks.left = 0;
	report_status(philo);
	return (NULL);
}

t_bool	initialize_threads(t_core *core)
{
	int			err;
	size_t		i;

	pthread_mutex_init(&core->mutex, NULL);
	i = 0;
	g_num = i;
	while (i < core->n_ph)
	{
		pthread_mutex_lock(&core->mutex);
		err = pthread_create(&core->philo[i].thread, NULL, fill_philo,
				(void *)&core->philo[i]);
		if (err)
		{
			ft_error(strerror(err));
			return (false);
		}
		pthread_mutex_unlock(&core->mutex);
		i++;
		g_num++;
	}
	i = 0;
	while (i < core->n_ph)
		pthread_join(core->philo[i++].thread, NULL);
	return (true);
}
