/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 20:12:04 by username          #+#    #+#             */
/*   Updated: 2026/07/28 12:44:31 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//Main functions
int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_strlen(const char *c);
int			ft_strncmp(char *str1, char *str2, size_t n);
int			ft_tolower(int ch);
int			ft_toupper(int ch);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(char *str, int c);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(char *s);
void		*ft_memcpy(void *to, const void *from, unsigned int n);
void		*ft_memmove(void *dest, const void *src, unsigned int n);
void		*ft_memset(void *ptr, int x, unsigned int n);
void		ft_bzero(void *s, unsigned int n);
void		*ft_calloc(size_t amount, size_t size);
void		*ft_memchr(const void *str, int c, size_t n);
size_t		ft_strlcat(char *dst, char *src, size_t s);
size_t		ft_strlcpy(char *dst, const char *src, size_t s);

// Additional functions

char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

// List functions
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
int			ft_lstsize(t_list *lst);

// ft_printf 
int			ft_printf(const char *check, ...);
int			ft_checker(const char check, va_list arg);
int			ft_printc(int c);
int			ft_printd_i(int d);
int			ft_prints(char *s);
int			ft_printp(unsigned long val, int ascii);
int			ft_printu(unsigned int u);
int			ft_printhex(unsigned int val, int ascii);

// get_next_line 
typedef struct s_gnl_list
{
	char				*buffer;
	struct s_gnl_list	*next_str;
}							t_gnl_list;
char		*get_next_line(int fd);
void		make_list(t_gnl_list **list, int fd);
void		add(t_gnl_list **list, t_gnl_list **last, char *buf);
char		*get_line(t_gnl_list *list);
void		clear(t_gnl_list **list);
int			checker(t_gnl_list *last);
t_gnl_list	*lstlast(t_gnl_list *list);
void		copy(t_gnl_list *list, char *s);
int			newline_length(t_gnl_list *list);
void		freedom(t_gnl_list **list, t_gnl_list *node, char *buff);

#endif
