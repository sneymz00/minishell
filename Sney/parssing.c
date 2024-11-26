/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:35:51 by camurill          #+#    #+#             */
/*   Updated: 2024/11/22 14:53:51 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_doubles(char *str, char ltr)
{
	int	i;
	int counter;

	i = 0;
	counter = 0;
	if (!str)
		return (0);
	while(str[i])
	{
		if (str[i] == ltr)
			counter++;
		if (counter % 2 == 1)
			counter += check_doubles(str + i + 1, ltr);
		if (counter % 2 == 0)
			return (1);
	}
	return (counter);
}

int	check_specials(char *str, char ltr)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == ltr)
			return (1);
		i++;
	}
	return (0);
}

int	parssing(t_shell **shell)
{
	if (check_doubles((*shell)->prompt, 34))
		return (-1);
	else if (check_doubles((*shell)->prompt, 34) && !check_doubles((*shell)->prompt, 34))
		return (0);
	if (!check_doubles((*shell)->prompt, 39) == 1)
		return (-1);
	return (0);
}
