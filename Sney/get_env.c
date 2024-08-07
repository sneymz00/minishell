/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:43:52 by camurill          #+#    #+#             */
/*   Updated: 2024/08/07 17:06:17 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	get_env(t_shell **shell, char **env)
{
	size_t	i;

	i = 0;
	while (env[i])
		i++;
	(* shell)->env	= malloc(sizeof(char **) * (i + 1));
	i = 0;
	while (env[i])
	{
		(* shell)->env[i] = ft_strdup(env[i]);
		i++;
	}
	(*shell)->env[i] = NULL;
}