/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 08:23:35 by njordaan          #+#    #+#             */
/*   Updated: 2018/07/26 15:32:04 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define C_NONE         "\033[0m"
# define C_BOLD         "\033[1m"
# define C_BLACK        "\033[30m"
# define C_RED          "\033[31m"
# define C_GREEN        "\033[32m"
# define C_BROWN        "\033[33m"
# define C_BLUE         "\033[34m"
# define C_MAGENTA      "\033[35m"
# define C_CYAN         "\033[36m"
# define C_GRAY			"\033[37m"

# define BUFF_SIZE	1024

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

float				ft_abs(float x);

int					ft_atoi(const char *str);
char				*ft_itoa(int n);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_iswhite(int c);

int					ft_toupper(int c);
int					ft_tolower(int c);

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **root, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void	(*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					ft_lstlen(t_list *root);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstpush(t_list **root, void *content, size_t size);
void				ft_lstpushback(t_list **root, void *content, size_t size);

void				ft_bzero(void *str, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, void const *src, size_t n);
void				*ft_memccpy(void *dst, void const *src, int c, size_t n);
void				*ft_memchr(void const *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, void const *src, size_t len);
void				*ft_memset(void *str, int c, size_t n);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *str);
void				ft_putendl_fd(char const *str, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *str, int fd);

char				*ft_strcat(char *s1, char const *s2);
char				*ft_strchr(char const *str, int c);
void				ft_strclr(char *str);
int					ft_strcmp(char const *s1, char const *s2);
char				*ft_strcpy(char *dest, char const *src);
void				ft_strdel(char **as);
char				*ft_strdup(char const *str);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char const *s, void (*f)(char *));
void				ft_striteri(char const *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, char const *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, char const *s2, size_t n);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
char				*ft_strncpy(char *dest, char const *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnstr(char const *str, char const *find, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strrchr(char const *str, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(char const *str, char const *find);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);

void				*ft_swap(int *a, int *b);

int					get_next_line(const int fd, char **line);

#endif
