###############################################################################
#								STANDARS	 								  #
###############################################################################
NAME 		= 		minishell
RM 			= 		rm -rf
INCLUDE		=		inc/minishell.h
OBJS		= 		obj/
SRC_DIR_NAV	=		Navarro/
SRC_DIR_SNY	=		Sney/
LIBFT		=		Libreries/Libft
LIBFT_A   =		Libreries/Libft/libft.a


###############################################################################
#								COMPILER	  								  #
###############################################################################

CC 			= 		gcc
CCFLAGS		= 		-g #-fsanitize=address-Wall -Wextra -Werror -fsanitize=address
READLINE	=		-lreadline

###############################################################################
#									SRC    									  #
###############################################################################

SRC 		= 		$(SRC_DIR_SNY)main.c\
					$(SRC_DIR_SNY)parssing.c\
					$(SRC_DIR_SNY)start_shell.c\
					$(SRC_DIR_SNY)get_env.c\
					$(SRC_DIR_SNY)signal.c\
					$(SRC_DIR_SNY)built_ins.c\
					$(SRC_DIR_SNY)built_ins_aux.c\
					$(SRC_DIR_NAV)remove_quotes.c\
					$(SRC_DIR_NAV)string.c\
					$(SRC_DIR_NAV)token.c\
					$(SRC_DIR_NAV)utils.c\
					$(SRC_DIR_NAV)lectur.c


###############################################################################
#									OBJ_DIR	   								  #
###############################################################################

OBJ_DIR = $(patsubst $(SRC_DIR_SNY)%.c, $(OBJS)%.o, $(SRC))

###############################################################################
#								RULES	      								  #
###############################################################################

all:
	@make -C $(LIBFT) --no-print-directory
	@make $(NAME) --no-print-directory

$(NAME):: $(OBJ_DIR) $(LIBFT)
	@echo "Compiling file"
	@$(CC) $(CCFLAGS) $(OBJ_DIR) $(LIBFT_A) -o $(NAME) $(READLINE)
$(NAME)::
	@echo "Minishell is alived"

$(OBJS)%.o: $(SRC_DIR_SNY)%.c Makefile $(INCLUDE)
	@echo "Compiling..."
	@mkdir -p $(OBJS)
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT) fclean --no-print-directory
	@echo "Cleaning up..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "Cleaning file..."
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
