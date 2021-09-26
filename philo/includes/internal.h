/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:11:17 by aborboll          #+#    #+#             */
/*   Updated: 2021/09/26 16:51:29 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

/*
** Define errors
*/
# define ERR_NOT_NUMBER "Error: You must enter a valid number!\n"
# define ERR_NOT_INT_NUMBER "Error: You must enter a int number!\n"
# define ERR_FILE_OP "Error: Could not open \"%s\" file.\n"
# define ERR_BAD_ARGS "Error: Please enter 4 or 5 arguments!\n"
# define ERR_BAD_N_PH "Error: Argument 'number_of_philosophers' must be > 1\n"
# define ERR_BAD_T_DIE "Error: Argument 'time_to_die' must be > 0\n"
# define ERR_BAD_T_EAT "Error: Argument 'time_to_eat' must be > 0\n"
# define ERR_BAD_T_SLEEP "Error: Argument 'time_to_sleep' must be > 0\n"
# define ERR_BAD_N_TIMES_1 "Error: Argument 'number_of_times_each_philosopher"
# define ERR_BAD_N_TIMES_2 "_must_eat' must be > 0\n"

/*
** Define debug lines
*/
# define D_R_FORKING "has taken a fork"
# define D_R_EATING "is eating"
# define D_R_SLEEPING "is sleeping"
# define D_R_THINKING "is thinking"
# define D_R_DIED "died"

#endif
