/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:42:41 by joanavar          #+#    #+#             */
/*   Updated: 2024/11/19 18:35:36 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int is_command(char c)
{
	if (c == ' ')
		return (1);
	else if (c == '|')	
		return (1);
	else if (c == '<' || c == '>')
		return (1);
	return (0);
}

static int	is_quotes(char *str, int i, t_token **stack)
{
	char *token;
	int j;
	int count;

	j = i + 1;
	count = 0;
	while (str[j] != 9 || str[j] != 4)
	{
		j++;
		count++;
	}
	j = 0;
	token = malloc(sizeof(char *) * (count + 2));
	if (!token)
		return (0);
	while (str[i] != 0 || str[i] != 4)
		token[j++] = str[i++];
	if (token[0] == 9)
		token[j++] = 9;
	else 
		token[j++] = 4;
	token[j] = '\0';
	get_token(token, stack);
	return (i);
}

static int    is_word(char *str, int i, t_token **stack)
{
    char *token;
    int j;
    int count;

    j = i;
    count = 0;
    while (!is_command(str[j]))
    {
        count++;
        j++;
    }
    j = 0;
    token = malloc(sizeof(char *) * (count + 1));
    while (!is_command(str[j]))
        token[j++] = str[i++];
    token[j] = '\0';
    get_token(token, stack);
	return (i--);
}

int is_string(char *str, int i, t_token **stack)
{
	int j;

	j = 0;
	if (str[i] == 9 || str[i] == 4)
		j = is_quotes(str, i, stack);
	else 
		j = is_word(str, i, stack);
	return (j);
}
