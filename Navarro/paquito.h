/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paquito.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:25:14 by joanavar          #+#    #+#             */
/*   Updated: 2024/11/26 16:43:42 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PAQUITO_H
# define PAQUITO_H

# include <stdio.h> //printf-perror
# include <stdlib.h> //malloc-free-getenv
# include <string.h> //streeror
# include <unistd.h> //read-access-fork-execve-unlink-ttyname
# include <dirent.h> //opendir-readdir-closedir
# include <signal.h> //signal-signaction-kill
# include <sys/wait.h> //wait-waitpid-wait3
# include <termios.h> //tcsetattr-tcgetattr-ioctl
# include <sys/stat.h> //stat-lstat-fstat
# include <readline/readline.h> //readline-rl_replace_line
# include <readline/history.h> //add_history
# include <curses.h> //tgetent-tputs
# include <term.h> //tgoto-tgetent
# include "../Libreries/Libft/libft.h"

#define DELIM		" \t\r\n\a"

/***COLORS***/
# define GBD	    "\033[0m"
# define BLACK       "\033[30m"
# define RED         "\033[31m"
# define GREEN       "\033[32m"
# define YELLOW      "\033[33m"
# define BLUE        "\033[34m"
# define MAGENTA     "\033[35m"
# define CYAN        "\033[36m"
# define WHITE       "\033[37m"
# define BOLD_BLACK  "\033[1m\033[30m"
# define BOLD_RED    "\033[1m\033[31m"
# define BOLD_GREEN  "\033[1m\033[32m"
# define BOLD_YELLOW "\033[1m\033[33m"
# define BOLD_BLUE   "\033[1m\033[34m"
# define BOLD_MAGENTA "\033[1m\033[35m"
# define BOLD_CYAN   "\033[1m\033[36m"
# define BOLD_WHITE  "\033[1m\033[37m"

# define SPACES		0 // 0 = ESPACIOS
# define STRING 	1  // 1 = STRING SIN COMILLAS
# define STRINGCS	2 // 2 = STRING CON COMILLAS SIMPLES
# define STRINGCD	3 // 3 = STRING CON COMILLAS DOBLES
# define PIPE 		4 //  = PIPE |
# define HDOC		5 //  = HEREDOC <<
# define REDIROUT	6 //  = REDIRECCION >
# define APPEND		7 //  = APEND >>
# define REDIRIN	8 //  = REDIRECCION <
//# define DOLLAR		9 //  = $
/*	STRUCTS		*/
/*	struct with tokens	*/

extern volatile sig_atomic_t signal_received;

typedef struct s_token
{
	char			*content;
	int				type;
	//int				expanded;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;



//lectur.c
t_token	*lectur_imput(char *str);

//token.c
void	get_token(char *str, t_token **stack);
t_token	*find_last(t_token *stack);
//string.c
int		is_string(char *str, int i, t_token **stack);
//remove_quotes.c
void	remove_quotes(t_token *stack);
int		string_type(t_token *token);
//utils.c
int		ft_strcmp(const char *src, char *s);
void	print_token(t_token *stack);
//syntax_error.c
int		syntax_error(t_token **stack);
int		redir_type(t_token *token);

#endif
