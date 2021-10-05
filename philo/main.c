/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:45:43 by aborboll          #+#    #+#             */
/*   Updated: 2021/10/05 21:33:14 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/core.h"

int	main(int argc, char **argv)
{
	t_core	*core;

	if (validate_args(argc, argv))
	{
		core = initialize(argc, argv);
		if (initialize_threads(core))
		{
			clear_memory(core);
			return (0);
		}
		clear_memory(core);
	}
	return (1);
}
