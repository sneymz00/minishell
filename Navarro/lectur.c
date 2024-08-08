#include "../inc/minishell.h"

char	*tokenize(char *line)
{}

int count_tokens(char *line, char dif)
{
	int i;
	int tokens;

	i = 0;
	tokens = 0;
	while (line)
	{
		if (i = 0 && line[i] != dif)
			tokens++;
		if (i > 0 && line[i] != dif && line[i - 1] == dif)
			tokens++
		i++;
	}
	return (tokens);
}
char **lectur_line(char *line, char dif)
{
	char *tokens[];
	char *new_line;
	int i;
	int j;

	j = 0;
	new_line = ft_strtrim(line, " ");
	i = count_tokens(new_line);
	char *tokens = malloc(sizeof(char *) * i + 1);
	while (i > j)
	{

	}





}


