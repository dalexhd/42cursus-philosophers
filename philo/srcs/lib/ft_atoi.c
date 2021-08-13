/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:48:37 by aborboll          #+#    #+#             */
/*   Updated: 2021/08/13 12:51:47 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int	ft_atoi(const char *str)
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
	if (res > 0x7fffffffffffffff)
		return (sign);
	if (sign == -1)
		return (res);
	else
		return (-res);
}
