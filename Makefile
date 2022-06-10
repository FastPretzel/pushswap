NAME	= push_swap
NAME_B	= checker
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Iincludes# -g -fsanitize=address

FILES	= push_swap.c ft_atoi.c separ_utils.c ft_split.c errs.c \
		ft_lstadd.c ft_lstnew.c ft_lstlast.c ft_lstclear.c creating.c\
		s_utils.c r_utils.c rr_utils.c ft_lstsize.c p_utils.c \
		shuffle3_5.c shuffle100_500.c clean.c

FILES_B = checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c\
		ft_atoi.c separ_utils.c ft_split.c errs.c ft_lstadd.c\
	   	ft_lstnew.c ft_lstlast.c ft_lstclear.c creating.c\
		s_utils.c r_utils.c rr_utils.c ft_lstsize.c p_utils.c \
		shuffle3_5.c shuffle100_500.c check_utils_bonus.c clean.c

VPATH	= srcs/\
		  srcs_b/\

HEADERS	= includes/ps_h.h\

FILES_O = $(addprefix objs/, $(notdir $(FILES)))
FILES_O_B = $(addprefix objs/, $(notdir $(FILES_B)))
SRCS	= $(addprefix srcs/, $(FILES))
OBJS	= $(FILES_O:.c=.o)
OBJS_B	= $(FILES_O_B:.c=.o)
OBJDIR	= objs/

NB		= $(words $(FILES))
INDEX	= 0

objs/%.o : %.c Makefile $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval PERCENT=$(shell expr $(INDEX) '*' 100 / $(NB)))
	@$(eval PROGRESS=$(shell expr $(INDEX) '*' 30 / $(NB)))
	@printf "\r\033[38;5;87mMAKE PUSH_SWAP %2d%%\033[0m \033[48;5;32m%*s\033[0m %s\033[K" $(PERCENT) $(PROGRESS) "" $(notdir $@)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir objs/

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@printf "\r\033[38;5;82mPUSH_SWAP DONE\033[0m\033[K\n"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJDIR)
	@printf "\033[38;5;85mCLEAN\033[0m\n"

fclean : clean
	@rm -rf $(NAME) $(NAME_B)
	@printf "\033[38;5;84mFULL CLEAN\033[0m\n"

bonus: $(OBJDIR) $(NAME_B)

$(NAME_B): $(OBJS_B)
	@$(CC) $(CFLAGS) -o $(NAME_B) $(OBJS_B)
	@printf "\r\033[38;5;82mCHECKER DONE\033[0m\033[K\n"




re: fclean all
