/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lectur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:54:07 by joanavar          #+#    #+#             */
/*   Updated: 2024/11/06 19:33:04 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char	*	token(char *s, int i)
{
	int j;
	char *new_token

	j = 0;
	while ()
}


void	lectur_imput(char *str)
{
	int i = 0;
	t_token **stack;
	t_token *token;

	stack = NULL;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == ' ')
			token = is_caracter_token(str[i], stack);
		else if (str[i] == '|')
			is_caracter_token(str[i], stack);
		else if (str[i] == '>' && str[i] == '<')
		{
			 if (str[i] == '<' && str[i + 1] == '<' ||
				str[i] == '>' && str[i + 1] == '>')
				{
					is_redireccion(str, i, stack);
					i++;
				}
			 else
				 is_caracter_token(str[i], stack);
		}
		else 
			is_string(str, i, stack);
		i++;
	}
}

void	stack_token(t_token *token, t_token **stack)
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
