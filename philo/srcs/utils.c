/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:38:02 by aborboll          #+#    #+#             */
/*   Updated: 2021/09/26 16:39:58 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core.h"

t_llong	get_time(void)
{
	struct timeval	time;
	t_llong			milliseconds;

	gettimeofday(&time, NULL);
	milliseconds = (time.tv_sec) * 1000 + (time.tv_usec) / 1000;
	return (milliseconds);
}
