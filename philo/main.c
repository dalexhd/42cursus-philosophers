/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:45:43 by aborboll          #+#    #+#             */
/*   Updated: 2021/08/13 12:51:47 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/core.h"

int	main(int argc, char **argv)
{
	t_core	*core;

	if (validate_args(argc, argv))
	{
		core = initialize(argc, argv);
		free(core);
		return (0);
	}
	return (1);
}
