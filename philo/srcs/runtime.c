/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:34:14 by aborboll          #+#    #+#             */
/*   Updated: 2021/10/02 16:48:51 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core.h"

t_bool	forking(t_philo *philo)
{
	if (philo->n_ph == 1)
		died(philo);
	pthread_mutex_lock(philo->forks.left);
	pthread_mutex_lock(philo->forks.right);
	if ((get_time() - philo->start_time) >= (t_llong)philo->t_die)
		died(philo);
	philo->status = "forking";
	report_status(philo);
	return (true);
}

t_bool	eating(t_philo *philo)
{
	if (philo->any_died[0])
		return (false);
	philo->status = "eating";
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
	ft_usleep(philo->t_sleep);
	pthread_mutex_unlock(philo->forks.right);
	pthread_mutex_unlock(philo->forks.left);
	return (true);
}

t_bool	thinking(t_philo *philo)
{
	if (philo->any_died[0])
		return (false);
	philo->status = "thinking";
	report_status(philo);
	ft_usleep(1);
	return (true);
}

t_bool	died(t_philo *philo)
{
	if (philo->any_died[0])
		return (false);
	philo->status = "died";
	report_status(philo);
	philo->any_died[0] = true;
	exit(1);
}
