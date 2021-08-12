/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strevery.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:49:17 by aborboll          #+#    #+#             */
/*   Updated: 2021/08/12 14:13:11 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

t_bool	ft_strevery(char const *s, t_bool (*f)(int))
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(s))
	{
		if (!f(s[i]))
			return (FALSE);
	}
	return (TRUE);
}
