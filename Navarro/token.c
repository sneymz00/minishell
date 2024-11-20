/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:16:05 by joanavar          #+#    #+#             */
/*   Updated: 2024/11/20 19:08:41 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*find_last(t_token *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static void	stack_token(t_token *token, t_token *stack)
{
	t_token *last_token;

	last_token = find_last(stack);
	last_token->next = token;
	token->prev = last_token;
}
static void	get_type_token(t_token *token)
{
	if (!ft_strcmp(token->content, " "))
		token->type = 0;
	else if (!ft_strcmp(token->content, "|"))
		token->type = 4;
	else if (!ft_strcmp(token->content, "<"))
		token->type = 8;
	else if (!ft_strcmp(token->content, "<<"))
			token->type = 5;
	else if (!ft_strcmp(token->content, ">"))
		token->type = 6;
	else if (!ft_strcmp(token->content, ">>"))
			token->type = 7;
	else if (token->content[0] == 9)
		token->type = 2;
	else if (token->content[0] == 4)
		token->type = 3;
	else 
		token->type = 1;
}

void	get_token(char *str, t_token *stack)
{
	t_token token;

	token.content = str;
	get_type_token(&token);
	if (!stack)
	{
		stack = &token;
		token.next = NULL;
	}
	else
		stack_token(&token, stack);

}




