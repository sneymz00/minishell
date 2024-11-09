#include "minishell.h"

void	get_token(char *str, t_token **stack)
{
	t_token *token;
	
	token->content = str;
	get_type_token(str, token);
	stack_token(token, stack);
	


}
void	get_type_token(char *str, token)
{
	if (str[0] == ' ')
		token->type = 0;
	else if (str[0] == is_alpha(str))// hacer is_alpha en utilsc o cojer de libft;
		token->type = 1;
	else if (str[0] == "'")
		token->type = 2;
	else if (str[0] == 4)
		token->type == 3;
	else if (str[0] == "|")
		token->type = 4;
	else if (str[0] == "<")
	{
		token->type = 8;
		if (str[1] == "<")
			token->type = 5;
	}
	else if (str[0] == ">")
	{
		token->type = 6;
		if (str[1] == ">")
			token->type = 7;
	}	
}

void    is_caracter_token(char c, t_token **stack)
{
    char *token;

    token = malloc(sizeof(char *) * 2);
	if (!token)
		return ;
    token[0] = c;
    token[1] = '\0';
    get_token(token);
}

void    is_redireccion(char *str, int i, t_token **stack)
{
    char *token;
    int j;

    j = 0;
    token = malloc(sizeof(char *) * 3);
    while (str[i] = '<' || str[i])
    {
        token[j] = str[i];
        j++;
        i++;
    }
    token[j] = '\0';

    get_token(token);
}

int    is_word(char *str, int i, t_token **stack)
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
    Token[j] = '\0';
    get_token(token);
	return (i--);
}
