/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:34:14 by aborboll          #+#    #+#             */
/*   Updated: 2021/09/26 17:27:03 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core.h"

t_bool	forking(t_philo *philo)
{
	pthread_mutex_lock(philo->forks.left);
	pthread_mutex_lock(philo->forks.right);
	philo->status = "forking";
	report_status(philo);
	report_status(philo);
	return (true);
}

t_bool	eating(t_philo *philo)
{
	philo->status = "eating";
	report_status(philo);
	return (true);
}

t_bool	sleeping(t_philo *philo)
{
	philo->status = "sleeping";
	report_status(philo);
	pthread_mutex_unlock(philo->forks.right);
	pthread_mutex_unlock(philo->forks.left);
	return (true);
}

t_bool	thinking(t_philo *philo)
{
	philo->status = "thinking";
	report_status(philo);
	return (true);
}

t_bool	died(t_philo *philo)
{
	philo->status = "died";
	report_status(philo);
	return (true);
}
