/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:16:05 by joanavar          #+#    #+#             */
/*   Updated: 2024/11/19 18:23:25 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*find_last(t_token *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static void	stack_token(t_token *token, t_token **stack)
{
	t_token *last_token;

	if (!(*stack))
	{
		*stack = token;
		token->next = NULL;
		return ;
	}
	last_token = find_last(*stack);
	last_token->next = token;
	token->prev = last_token;
}
static void	get_type_token(t_token *token)
{
	if (ft_strcmp(token->content, " ") == 0)
		token->type = 0;
	else if (ft_strcmp(token->content, "|") == 0)
		token->type = 4;
	else if (ft_strcmp(token->content, "<") == 0)
		token->type = 8;
	else if (ft_strcmp(token->content, "<<") == 0)
			token->type = 5;
	else if (ft_strcmp(token->content, ">") == 0)
		token->type = 6;
	else if (ft_strcmp(token->content, ">>") == 0)
			token->type = 7;
	else 
		token->type = 1;
}

void	get_token(char *str, t_token **stack)
{
	t_token *token;
	
	token->content = str;
	//get_type_token(token);
	stack_token(token, stack);

}




