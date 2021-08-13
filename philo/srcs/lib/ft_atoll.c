/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:45:34 by aborboll          #+#    #+#             */
/*   Updated: 2021/08/13 12:51:47 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

t_llong	ft_atoll(const char *str)
{
	long long int			i;
	int						sign;
	unsigned long long		res;

	i = 0;
	res = 0;
	sign = -1;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = 0;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res > 9223372036854775807LL)
		return (sign);
	if (sign == -1)
		return (res);
	else
		return (-res);
}
