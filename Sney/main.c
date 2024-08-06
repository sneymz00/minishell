/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:49:47 by camurill          #+#    #+#             */
/*   Updated: 2024/08/06 21:12:02 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minishell.h"

void	error_message(char *str)
{
	printf(RED"Error found: %s\n"GBD, str);
	exit(1);
}	

void	init_shell(t_shell **shell, char **env)
{
	(* shell) = malloc(sizeof(t_shell));
	if (!shell || !(* shell))
		error_message("Problems with mallocs");
	(* shell)->prompt = NULL;
	(* shell)->token = 0;
	(* shell)->status = 0;
	//shell->env = get_env(env);//toDo
}

void	clean_data(t_shell **shell)
{
	if ((* shell)->prompt)
	{
		free((*shell)->prompt);
		(*shell)->prompt = NULL;
	}
	free((* shell));
}

int main(int ac, char **ag, char **env)
{
	t_shell	*shell;

	if (ac > 1)
		error_message("Enter only one argument");
	shell = NULL;
	init_shell(&shell, env);
	while (1)
	{
		shell->prompt = readline(BLUE"/home/minishell$ "GBD);
		if (!shell->prompt)
			break;
		printf("%s\n", shell->prompt);
		if (!strncmp("exit", shell->prompt, 5))
		{
			free(shell->prompt);
			break;
		}
		else
			add_history(shell->prompt);
		free(shell->prompt);
	}
	clean_data(&shell);
	return (0);
}
