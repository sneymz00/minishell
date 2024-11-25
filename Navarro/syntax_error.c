/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:34:15 by joanavar          #+#    #+#             */
/*   Updated: 2024/11/25 19:53:08 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redir_type(t_token *token)
{
	if (token->type == 5)
		return (1);
	else if (token->type == 6)
		return (1);
	else if (token->type == 7)
		return (1);
	else if (token->type == 8)
		return (1);
	else 
		return (0);

}
static int syntax_pipe_or_redi(t_token *token)
{
	/*if (token->type == 4 && !(token->next->type = 4))
		return (0);*/ // MIrar porque da segmentesion fault;
	else if (redir_type(token) && !redir_type(token->next))
		return (0);
	else 
		return (1);
}

int	syntax_error(t_token **stack)
{
	t_token *tmp;

	tmp = find_last(*stack);
	if (!string_type(tmp))
	{
		printf("ERROR SYNTAX\n");
		return (0);
	}
	tmp = *stack;
	while (tmp)
	{
		if (!syntax_pipe_or_redi(tmp))
		{
			printf("error syntax pipe or redi\n");
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
