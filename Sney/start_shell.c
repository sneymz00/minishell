/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:48:04 by camurill          #+#    #+#             */
/*   Updated: 2024/11/26 16:13:56 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	start_shell(t_shell *shell)
{
	//if (parssing(&shell) == -1)
	//	return (-1);
	shell->eco_token = lectur_imput(shell->prompt);
	return (0);
}
