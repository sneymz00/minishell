/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 00:08:20 by camurill          #+#    #+#             */
/*   Updated: 2024/08/08 02:09:43 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int m_comprobation(t_shell *shell, int args)
{
	int		i;

	i = 0;
	while (shell->arg[i])
	{
		if (args < i)
			return (1);
		i++;
	}
	return (0);
}
void	print_env(t_shell *shell)
{
	size_t	i;

	i = 0;
	while (shell->env[i])
	{
		printf("%s\n", shell->env[i]);
		i++;
	}
}

void	get_pwd()
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
	else
		perror("pwd");
}

void	get_export(t_shell *shell)
{
	size_t	i;

	i = 0;
	while (shell->env[i])
	{
		printf("declare -x %s\n", shell->env[i]);
		i++;
	}
}

void	unset_shell(t_shell *shell, char *arg)
{
	size_t i;

	//cubrir las flags
	i = 0;
	while (shell->env[i])
	{
		if (!ft_strncmp(shell->arg[1], shell->env[0], sizeof(arg)))//Hasta que llegue a =
		{
			if (unsetenv(shell->env[i]) != 0)
				perror("unset");
		}
		i++;
	}
}

int	built_ins(t_shell *shell) //corregir errores
{
	if (!strncmp("exit", shell->arg[0], 5) && !m_comprobation(shell, 0))
		{
			printf("exit\n");
			return (-1);
		}
	if (!strncmp("env", shell->arg[0], 4) && !m_comprobation(shell, 0))
		print_env(shell);
	if (!strncmp("pwd", shell->arg[0], 4) && !m_comprobation(shell, 0))
		get_pwd();
	if (!strncmp("export", shell->arg[0], 7) && !m_comprobation(shell, 0))
		get_export(shell);
	if (!strncmp("unset", shell->arg[0], 7) && !m_comprobation(shell, 0))
		unset_shell(shell, shell->arg[1]);
	return (0);
}
