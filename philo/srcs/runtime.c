/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:34:14 by aborboll          #+#    #+#             */
/*   Updated: 2021/10/11 18:39:03 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core.h"

t_bool	forking(t_philo *ph)
{
	if (ph->n_ph != 1)
	{
		pthread_mutex_lock(ph->forks.left);
		pthread_mutex_lock(ph->forks.right);
	}
	if ((get_time() - ph->start_time) > (t_llong)ph->t_d)
		died(ph);
	if (ph->n_ph == 1)
	{
		ph->status = "forking1";
		report_status(ph);
		ph->status = "died";
		report_status(ph);
		ph->any_died[0] = 1;
		ft_usleep(1);
		return (true);
	}
	ph->status = "forking";
	report_status(ph);
	return (true);
}

t_bool	eating(t_philo *ph)
{
	if (ph->n_ph == 1 || ph->any_died[0])
		return (false);
	ph->last_meal = get_time();
	ph->status = "eating";
	report_status(ph);
	ft_usleep(ph->t_eat);
	return (true);
}

t_bool	sleeping(t_philo *ph)
{
	if (ph->n_ph == 1 || ph->any_died[0])
		return (false);
	ph->status = "sleeping";
	report_status(ph);
	pthread_mutex_unlock(ph->forks.right);
	pthread_mutex_unlock(ph->forks.left);
	ft_usleep(ph->t_sleep);
	return (true);
}

t_bool	thinking(t_philo *ph)
{
	if (ph->n_ph == 1 || ph->any_died[0])
		return (false);
	ph->status = "thinking";
	report_status(ph);
	return (true);
}

t_bool	died(t_philo *ph)
{
	if (ph->n_ph == 1 || ph->any_died[0])
		return (false);
	pthread_mutex_lock(ph->shared_mutex);
	ph->status = "died";
	pthread_mutex_unlock(ph->shared_mutex);
	report_status(ph);
	ph->any_died[0] = true;
	return (true);
}
