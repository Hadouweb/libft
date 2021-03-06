.PHONY: all clean fclean re

SRCPATH = ./srcs
BITPATH = $(SRCPATH)/bit
ISPATH = $(SRCPATH)/is
LISTPATH = $(SRCPATH)/list
MEMPATH = $(SRCPATH)/mem
PRINTPATH = $(SRCPATH)/print
STRPATH = $(SRCPATH)/str
TABPATH = $(SRCPATH)/tab
TREEPATH = $(SRCPATH)/tree

NAME = libft.a

SRC = 	$(BITPATH)/ft_printbit.c\
		$(BITPATH)/ft_reversebit.c\
		$(BITPATH)/ft_hexdump.c\
		$(BITPATH)/ft_bitdump.c\
		$(ISPATH)/ft_isalnum.c\
		$(ISPATH)/ft_isalpha.c\
		$(ISPATH)/ft_isascii.c\
		$(ISPATH)/ft_isdigit.c\
		$(ISPATH)/ft_isprint.c\
		$(ISPATH)/ft_islower.c\
		$(ISPATH)/ft_isupper.c\
        $(LISTPATH)/ft_list_push_back.c\
        $(LISTPATH)/ft_list_push_front.c\
        $(LISTPATH)/ft_list_size.c\
        $(LISTPATH)/ft_list_del.c\
        $(LISTPATH)/ft_list_print.c\
        $(LISTPATH)/ft_list_push_before_node.c\
        $(LISTPATH)/ft_list_push_after_node.c\
        $(LISTPATH)/ft_list_to_tab.c\
        $(LISTPATH)/ft_list_str_split.c\
		$(MEMPATH)/ft_bzero.c\
		$(MEMPATH)/ft_memalloc.c\
		$(MEMPATH)/ft_memccpy.c\
		$(MEMPATH)/ft_memchr.c\
		$(MEMPATH)/ft_memcmp.c\
		$(MEMPATH)/ft_memcpy.c\
		$(MEMPATH)/ft_memdel.c\
		$(MEMPATH)/ft_memmove.c\
		$(MEMPATH)/ft_memset.c\
		$(PRINTPATH)/ft_putchar.c\
		$(PRINTPATH)/ft_print_addr.c\
		$(PRINTPATH)/ft_putchar_fd.c\
		$(PRINTPATH)/ft_putendl.c\
		$(PRINTPATH)/ft_putendl_fd.c\
		$(PRINTPATH)/ft_putnbr.c\
		$(PRINTPATH)/ft_putnbr_base.c\
		$(PRINTPATH)/ft_putnbr_fd.c\
		$(PRINTPATH)/ft_putstr.c\
		$(PRINTPATH)/ft_putstr_fd.c\
		$(STRPATH)/ft_atoi.c\
		$(STRPATH)/ft_atoi_base.c\
		$(STRPATH)/ft_itoa.c\
		$(STRPATH)/ft_ltoa.c\
		$(STRPATH)/ft_itoa_base.c\
		$(STRPATH)/ft_strcat.c\
		$(STRPATH)/ft_strchr.c\
		$(STRPATH)/ft_strclr.c\
		$(STRPATH)/ft_strcmp.c\
		$(STRPATH)/ft_strcpy.c\
		$(STRPATH)/ft_strcpy_limit.c\
		$(STRPATH)/ft_strdel.c\
		$(STRPATH)/ft_strdup.c\
		$(STRPATH)/ft_strndup.c\
		$(STRPATH)/ft_strequ.c\
		$(STRPATH)/ft_striter.c\
		$(STRPATH)/ft_striteri.c\
		$(STRPATH)/ft_strjoin.c\
		$(STRPATH)/ft_strjoin_free.c\
		$(STRPATH)/ft_strlcat.c\
		$(STRPATH)/ft_strcat.c\
		$(STRPATH)/ft_strlen.c\
		$(STRPATH)/ft_nblen.c\
		$(STRPATH)/ft_strmap.c\
		$(STRPATH)/ft_strmapi.c\
		$(STRPATH)/ft_strncat.c\
		$(STRPATH)/ft_strncmp.c\
		$(STRPATH)/ft_strncpy.c\
		$(STRPATH)/ft_strnequ.c\
		$(STRPATH)/ft_strnew.c\
		$(STRPATH)/ft_strnstr.c\
		$(STRPATH)/ft_strrchr.c\
		$(STRPATH)/ft_strsplit.c\
		$(STRPATH)/ft_strstr.c\
		$(STRPATH)/ft_strsub.c\
		$(STRPATH)/ft_strtrim.c\
		$(STRPATH)/ft_tolower.c\
		$(STRPATH)/ft_toupper.c\
		$(STRPATH)/ft_del_char.c\
		$(STRPATH)/ft_stradd_char.c\
		$(TABPATH)/ft_tabjoin.c\
		$(TABPATH)/ft_tablen.c\
		$(TABPATH)/ft_free_tab.c\
		$(SRCPATH)/get_next_line.c\
		$(TREEPATH)/ft_tree_add.c\
		$(TREEPATH)/ft_tree_info_node.c\
		$(TREEPATH)/ft_tree_preorder.c\
		$(TREEPATH)/ft_tree_inorder.c\
		$(TREEPATH)/ft_tree_postorder.c\

OBJ = $(SRC:.c=.o)

INC = -I./includes

CC = gcc -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(INC) -o $@ -c $<
	@echo "\033[32m█\033[0m\c"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
