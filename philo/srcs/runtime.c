/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:34:14 by aborboll          #+#    #+#             */
/*   Updated: 2021/10/05 18:23:22 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core.h"

t_bool	forking(t_philo *philo)
{
	if (philo->n_ph == 1)
		died(philo);
	pthread_mutex_lock(philo->forks.left);
	pthread_mutex_lock(philo->forks.right);
	if ((get_time() - philo->start_time) > (t_llong)philo->t_die)
		died(philo);
	philo->status = "forking";
	report_status(philo);
	return (true);
}

t_bool	eating(t_philo *philo)
{
	if (philo->any_died[0])
		return (false);
	philo->last_meal = get_time();
	philo->status = "eating";
	philo->n_times++;
	report_status(philo);
	ft_usleep(philo->t_eat);
	return (true);
}

t_bool	sleeping(t_philo *philo)
{
	if (philo->any_died[0])
		return (false);
	philo->status = "sleeping";
	report_status(philo);
	pthread_mutex_unlock(philo->forks.right);
	pthread_mutex_unlock(philo->forks.left);
	ft_usleep(philo->t_sleep);
	return (true);
}

t_bool	thinking(t_philo *philo)
{
	if (philo->any_died[0])
		return (false);
	philo->status = "thinking";
	report_status(philo);
	return (true);
}

t_bool	died(t_philo *philo)
{
	if (philo->any_died[0])
		return (false);
	philo->status = "died";
	report_status(philo);
	return (true);
}
