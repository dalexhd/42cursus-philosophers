/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:07:51 by aborboll          #+#    #+#             */
/*   Updated: 2021/09/20 16:50:24 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core.h"

void	report_status(t_philo *philo)
{
	struct timeval	time;
	t_llong			milliseconds;

	gettimeofday(&time, NULL);
	milliseconds = (time.tv_sec) * 1000 + (time.tv_usec) / 1000;
	if (!ft_strcmp(philo->status, "forking"))
		printf("%lld %zu %s\n", milliseconds, philo->n, D_R_FORKING);
	else if (!ft_strcmp(philo->status, "eating"))
		printf("%lld %li %s\n", milliseconds, philo->n, D_R_EATING);
	else if (!ft_strcmp(philo->status, "sleeping"))
		printf("%lld %zu %s\n", milliseconds, philo->n, D_R_SLEEPING);
	else if (!ft_strcmp(philo->status, "thinking"))
		printf("%lld %zu %s\n", milliseconds, philo->n, D_R_THINKING);
	else if (!ft_strcmp(philo->status, "died"))
		printf("%lld %zu %s\n", milliseconds, philo->n, D_R_DIED);
}