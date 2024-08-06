/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:35:51 by camurill          #+#    #+#             */
/*   Updated: 2024/08/06 23:13:53 by camurill         ###   ########.fr       */
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
		return (1);
	while (str[i])
	{
		if (str[i] == ltr)
			counter++;
		i++;
	}
	if (counter % 2 == 0)
		return (0);
	return (1);
}

int	check_specials(char *str, char ltr)
{
	int	i;
	int counter;

	i = 0;
	counter = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == ltr)
			return (0);
		i++;
	}
	return (1);
}

int	parssing(t_shell **shell)
{
	t_shell	*cmd;

	cmd = *shell;
	if (check_doubles(cmd->prompt, 42)) // ""
		return (-1);
	if (check_doubles(cmd->prompt, 39)) // ''
		return (-1); //salir y liberar
	if (check_specials(cmd->prompt, 47) || check_specials(cmd->prompt, 59))
		return (-1);
	return (0);
}