/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lectur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:54:07 by joanavar          #+#    #+#             */
/*   Updated: 2024/11/21 19:38:54 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"

static void    is_caracter_token(char c, t_token **stack)
{
    char *token;

    token = malloc(sizeof(char *) * 2);
	if (!token)
		return ;
    token[0] = c;
    token[1] = '\0';
    get_token(token, stack);
}

static void    is_redireccion(char *str, int i, t_token **stack)
{
    char *token;
    int j;

    j = 0;
    token = malloc(sizeof(char *) * 3);
    while (str[i] == '<' || str[i] == '>') // proteger si te mandan >< o <>;
    {
        token[j] = str[i];
        j++;
        i++;
    }
    token[j] = '\0';

    get_token(token, stack);
}

void	lectur_imput(char *str)
{
	int i = 0;
	t_token *stack;

	stack = NULL;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == ' ')
			is_caracter_token(str[i], &stack);
		else if (str[i] == '|')
			is_caracter_token(str[i], &stack);
		else if (str[i] == '>' || str[i] == '<')
		{
			 if ((str[i] == '<' && str[i + 1] == '<') ||
				str[i] == '>' && str[i + 1] == '>')
				{
					is_redireccion(str, i, &stack);
					i++;
				}
			 else
				 is_caracter_token(str[i], &stack);
		}
		else
		{
			i = is_string(str, i, &stack);
			i--;
		}
		i++;
	}
	/*for (t_token *tmp = *stack; tmp; tmp = tmp->next)
		printf("<%s>\n", tmp->content);*/
	//remove_quotes(*stack);
}



int main(/*int argc, char **argv*/)
{
	char *c;
	//lectur_imput("'e' |ls>cat -e");
	//(void)argc;
	while (1)
	{
		c = readline("prueba>");
		lectur_imput(c);
	}
	return (0);
}
