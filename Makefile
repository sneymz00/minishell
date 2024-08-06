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
					$(SRC_DIR_NAV)printfs.c\


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
	@echo "Compiling $<"
	@mkdir -p $(OBJS)
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "Cleaning file..."
	@$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re
