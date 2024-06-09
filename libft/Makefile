NAME	= libft.a
# SRCS	= ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c \
# 			ft_putendl_fd.c ft_split.c ft_striteri.c ft_strlcpy.c ft_strncmp.c \
# 			ft_strtrim.c ft_toupper.c ft_bzero.c ft_isalpha.c ft_isprint.c \
# 			ft_memcmp.c ft_memset.c ft_putnbr_fd.c ft_strchr.c ft_strjoin.c \
# 			ft_strlen.c ft_strnstr.c ft_substr.c ft_calloc.c ft_isascii.c \
# 			ft_itoa.c ft_memcpy.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c \
# 			ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c \
#			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
# 			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
SRCS	= ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_strchr.c ft_atoi.c ft_isdigit.c ft_calloc.c ft_bzero.c ft_memset.c ft_memmove.c ft_strlen.c ft_itoa.c ft_strlcpy.c ft_memcpy.c ft_strlcat.c
OBJS	= $(SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Creating $(LIBFT_A)…$(DEF_COLOR)"
	$(AR) $(NAME) $(OBJS)
	@echo "\n"

.c.o:
	@echo "$(YELLOW)Compiling $<…$(DEF_COLOR)"
	$(CC) $(CFLAGS) -c $<
	@echo "\n"

clean:
	@echo "$(GREEN)Cleaning object files…$(DEF_COLOR)"
	$(RM) $(OBJS)
	@echo "\n"

fclean: clean
	@echo "$(GREEN)Cleaning $(NAME)…$(DEF_COLOR)"
	$(RM) $(NAME)
	@echo "\n"

re: fclean all

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
