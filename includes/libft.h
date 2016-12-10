/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:36:45 by nle-bret          #+#    #+#             */
/*   Updated: 2016/10/13 12:13:37 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 10

typedef struct		s_save
{
	int				fd_num;
	char			*rest;
	struct s_save	*next;
}					t_save;

int					get_next_line(int const fd, char **line);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy (void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlen_limit(const char *s, char c);
int					ft_nblen(long long value);
char				*ft_strdup(const char *s1);
char				*ft_strndup(char *str, int len);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcpy_limit(char *str, char n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_del_char(char *str, char c);
char				*ft_stradd_char(char **s, char c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, int base);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void	**ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free_s2(char *s1, char *s2);
char				*ft_strjoin_free_s1(char *s1, char *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_ltoa(long n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_listd
{
	void			*content;
	size_t			content_size;
	struct s_listd	*next;
	struct s_listd	*prev;
}					t_listd;

typedef struct		s_listd_info
{
	t_listd			*beg;
	t_listd			*end;
	unsigned int	size;
}					t_listd_info;

typedef struct		s_tree
{
	void			*content;
	size_t			content_size;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

enum	e_tree
{
	TREE_LEFT,
	TREE_RIGHT
};

void				ft_tree_preorder(t_tree *node, void (*f)(t_tree *node));
void				ft_tree_inorder(t_tree *node, void (*f)(t_tree *node));
void				ft_tree_postorder(t_tree *node, void (*f)(t_tree *node));
t_tree				*ft_tree_new(const void *content, size_t content_size);
t_tree				*ft_tree_add(t_tree *ref_node, enum e_tree edge,
	const void *content, size_t content_size);
void				ft_tree_print_node(t_tree *node);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *node);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstprint(t_list *lst, void (*print)(void *));
void				ft_lstpush(t_list **alst, t_list *node);
void				ft_printbit(unsigned char octet);
unsigned char		ft_reversebit(unsigned char octet);
char				*ft_itoa_base(int n, int base);
void				ft_putnbr_base(int n, int base);
void				ft_lstpush_front(t_list **lst, void const *c, size_t s);
void				ft_lstpush_back(t_list **lst, void const *c, size_t s);

t_listd				*ft_lstd_new(void const *content, size_t content_size);
void				ft_lstd_print(t_listd_info *lst, void (*print)(void *),
	int print_link);
void				ft_lstd_pushback(t_listd_info **l, void const *c, size_t s);
void				ft_lstd_pushbefore_node(t_listd_info **l, t_listd *node,
	t_listd *new_node);

void				ft_lst_pushafter_node(t_list *prev_node, t_list *node);
int					ft_lstsize(t_list *l);
void				**ft_lsttotab(t_list *l);
int					ft_tablen(int *t);
int					*ft_tabjoin(int *t1, int *t2);
void				ft_free_tab(char **tab);
t_list				*ft_lstsplit(char const *s, char c);

#endif
