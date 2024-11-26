/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lectur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:54:07 by joanavar          #+#    #+#             */
/*   Updated: 2024/11/12 18:57:22 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	string_type(t_token *token)
{
	if (token->type == 1)
		return (1);
	else if (token->type == 2)
		return (1);
	else if (token->type == 3)
		return (1);
	else 
		return (0);
}

/*void	remove_quotes(t_token *stack)
{
	int i;
	t_token *new_token;
	t_token *tmp;
	new_token->content = ft_strdup("");
	while (stack->next)
	{
		if (string_type(stack))
		{
			new_token = stack;
			while (string_type(stack))
				stack = stack->next;
			tmp = stack;
			create_one_token(stack, new_token, )
		}
		stack = stack->next;
	}
}*/

void	remove_quotes(t_token *stack)
{
	t_token *tmp;
	char	*tmp_content;

	while(stack)
	{
		if (string_type(stack) && string_type(stack->next))
		{
			tmp = stack->next; // guardo referencia 2do nodo
			tmp_content = stack->content; // guardo referencia 1ra string
			stack->content = ft_strjoin(stack->content, stack->next->content); // fusiono 1era y 2da string, pierdoo referencia 1ra
			stack->next = tmp->next; //asigno siguiente nodo al 3r
			free(tmp_content); // libero 1ra string simple
			free(tmp->content); // libero 2da string simple
			free(tmp); // libero segundo nodo
		}
		else
			stack = stack->next;
	}
}

void	lectur_imput(char *str)
{
	int i = 0;
	t_token **stack;

	stack = NULL;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == ' ')
			is_caracter_token(str[i], stack);
		else if (str[i] == '|')
			is_caracter_token(str[i], stack);
		else if (str[i] == '>' && str[i] == '<')
		{
			 if ((str[i] == '<' && str[i + 1] == '<') ||
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
	for (t_token *tmp = *stack; tmp; tmp = tmp->next)
		printf("<%s>\n", tmp->content);
	//remove_quotes(*stack);
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

int main(int argc, char **argv)
{
	(void)argc;
	lectur_imput(argv[1]);
}
