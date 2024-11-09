/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:42:41 by joanavar          #+#    #+#             */
/*   Updated: 2024/11/09 12:37:58 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*find_last(t_token *stack)
{
	if (!stack)
		return ;
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int is_command(char c)
{
	if (c == ' ')
		return (1);
	else if (c == '|')	
		return (1);
	else if (c == '<' || c == '>')
		return (1);
	return (0);
}

int	is_quotes(char *str, int i, char **stack)
{
	char *token;
	int j;
	int count;

	j = i;
	count = 0;
	while (str[j] != "'" || str[j] != 4)
	{
		j++;
		count++;
	}
	j = 0;
	token = malloc(sizeof(char *) * (count + 2));
	if (!token)
		return ;
	while (str[i] != "'" || str[i] != 4)
		token[j++] = str[i++];
	if (token[0] == "'")
		token[j++] = "'";
	else 
		token[j++] = 4;
	token[j] = '\0';
	get_token(token);
	return (i);
}

int is_string(char *str, int i, t_token **stack)
{
	int j;

	j = 0;
	if (str[i] == "'" || str[i] == 4)
		j = is_quotes(str, i, stack);
	else 
		j = is_word(str, i, stack);
	return (j);
}
