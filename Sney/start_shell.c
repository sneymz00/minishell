/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:48:04 by camurill          #+#    #+#             */
/*   Updated: 2024/08/09 21:00:26 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int start_shell(t_shell *shell)
{
	if (parssing(&shell) == -1) // redefinir los errores de entrada
		return (-1);
	shell->arg = ft_split(shell->prompt, ' '); //TODO TOKENS AND  MAKE STRUCT
	return (0);
}