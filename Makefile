# Names
NAME		= libftprintf.a
LIBFT_A		= libft.a
LIBFT_DIR	= ./libft/
SRCS		= ft_printf \
				debugs
UTILS		= ft_parse_format ft_check_flags ft_print_format \
				ft_print_chars ft_print_nbrs ft_print_ptr
SRC_DIR		= ./src/
UTILS_DIR	= ./src/utils/
OBJ_DIR		= ./obj/
SRC_FILES	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCS))) $(addprefix $(UTILS_DIR), $(addsuffix .c, $(UTILS)))
OBJ_FILES	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS))) $(addprefix $(OBJ_DIR), $(addsuffix .o, $(UTILS)))

# Verbs
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

all: $(NAME)

# TODO: relinkの回避
$(NAME): $(OBJ_FILES) $(LIBFT_A)
	@echo "$(GREEN)Creating $(NAME)…$(DEF_COLOR)"
	cp $(LIBFT_DIR)$(LIBFT_A) .
	mv $(LIBFT_A) $(NAME)
	$(AR) $(NAME) $(OBJ_FILES)
	@echo "\n"

bonus: all
	touch bonus

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(YELLOW)Compiling $<…$(DEF_COLOR)"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "\n"

$(OBJ_DIR)%.o: $(UTILS_DIR)%.c
	@echo "$(YELLOW)Compiling $<…$(DEF_COLOR)"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "\n"

clean:
	@echo "$(GREEN)Cleaning object files…$(DEF_COLOR)"
	$(RM) $(OBJ_FILES) bonus
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\n"

fclean: clean
	@echo "$(GREEN)Cleaning $(NAME)…$(DEF_COLOR)"
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\n"

re: fclean all

# tests
test: test-all

test-%: $(NAME)
	$(CC) $(CFLAGS) -o test test.c $(NAME) $(LIBFT_DIR)/$(LIBFT_A)
	@echo "$(YELLOW)"
	./test $(@:test-%=%)
	@echo "$(DEF_COLOR)"

retest: retest-all

retest-%: tclean
	$(MAKE) test-$(@:retest-%=%)

tclean: fclean
	@echo "$(GREEN)Cleaning test files…$(DEF_COLOR)"
	$(RM) test


# Colors
DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m
