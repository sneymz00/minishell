/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:34:15 by joanavar          #+#    #+#             */
/*   Updated: 2024/11/25 17:58:26 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_error(t_token **stack)
{
	t_token *tmp;

	tmp = find_last(*stack);
	if (!string_type(tmp))
	{
		printf("ERROR SYNTAX\n");
		return (0);
	}
	return (1);
}
