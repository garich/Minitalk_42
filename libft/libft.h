/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:13:22 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/28 16:51:10 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN 2147483648
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// checks if the integer matches an alphabetic character in decimal ASCII.
// returns: 1 (yes) 0 (no).
int				ft_isalpha(int c);
// checks if the integer matches a digit character in decimal ASCII.
// returns: 1 (yes) 0 (no).
int				ft_isdigit(int c);
// checks if the integer matches an alphanumeric character in decimal ASCII.
// returns: 1 (yes) 0 (no).
int				ft_isalnum(int c);
// checks if the integer matches an ASCII character.
// returns: 1 (yes) 0 (no).
int				ft_isascii(int c);
// checks if the integer is a printable ASCII character.
// returns: 1 (yes) 0 (no).
int				ft_isprint(int c);
// finds the lenght of string and returns an integer with the value.
int				ft_strlen(const char *str);
// fill a string with a value.
// 'b' is the string, 'c' is the value, 'len' is the size of the string.
void			*ft_memset(void *b, int c, size_t len);
// write zeroes to a string
// 's' is the string, 'n' is the size of the string.
void			ft_bzero(void *s, size_t n);
// copies 'src' to 'dst' space, byte after byte while 'n'.
// returns 'dst'
void			*ft_memcpy(void *dst, const void *src, size_t n);
// copies 'len' bytes from 'src' to 'dst'
// takes care of overlapping data, non destructive.
void			*ft_memmove(void *dst, const void *src, size_t len);
// copies 'size' bytes of 'src' to 'dest'. Adds NULL at the end always.
// returns the length of 'src'.
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);
// appends as many bytes of 'src' to 'dest' as 'size' allows.
// adds NULL at the end always.
unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);
// converts lower case to upper. 
// returns the letter.
int				ft_toupper(int c);
// converts upper case to lower. 
// returns the letter.
int				ft_tolower(int c);
// locates 'c' in 's'.
// returns pointer to the located character.
char			*ft_strchr(const char *s, int c);
// locates the last ocurrence of 'c' in 's'.
// returns pointer to the located character.
char			*ft_strrchr(const char *s, int c);
// compares 's1' to 's2' one character at a time while 'n'.
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
// locates 'c' in 's', while 'n'.
// returns pointer to located byte.
void			*ft_memchr(const void *s, int c, size_t n);
// compares 's1' to 's2' one byte at a time while 'n'.
// assumed they are both 'n' bytes long.
// returns 0 if identical.
int				ft_memcmp(const void *s1, const void *s2, size_t n);
// locates a 'needle' in a 'hay'
// returns a pointer to the position in the 'hay' or NULL if not located.
char			*ft_strnstr(const char *hay, const char *needle, size_t len);
// convert ASCII string to integer. Max number is 64-bit signed integer.
// returns the integer.
int				ft_atoi(const char *str);
// convert ASCII string to integer. Max number INT_MAX = 2147483647.
// returns the integer.
int				ft_atoi_ps(const char *str, int *flag);
// allocates enough space for 'count' objects that are 'size' bytes of
// memory each and returns a pointer.
void			*ft_calloc(size_t count, size_t size);
// allocates memory for a copy of the string 'src', does the copy, and
// returns a pointer to it.
char			*ft_strdup(const char *src);
// allocates and returns a substring from the string 's'.
// the substring begins at index 'start' and is of max size 'len'.
char			*ft_substr(char const *s, unsigned int start, size_t len);
// reserve and returns a new string concat of 's1' and 's2'.
char			*ft_strjoin(const char *s1, const char *s2);
// returns a copy of 's1' with characters of 'set' removed 
// from the beginning and the end of 's1'.
char			*ft_strtrim(char const *s1, char const *set);
// returns an array of strings result of splitting 's' using 'c' as delimiter.
// Array ends with a NULL pointer.
char			**ft_split(char const *s, char c);
// returns a string representing the integer received as an argument.
char			*ft_itoa(int n);
// applies the function ’f’ to each character of the string ’s’, passes
// its index as first argument to create a new string resulting
// from successive applications of ’f’.
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// applies the function ’f’ on each character of the string passed as argument, 
// passing its index as first argument.
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
// outputs the character ’c’ to the given file descriptor
void			ft_putchar_fd(char c, int fd);
// outputs the string ’s’ to the given file descriptor.
void			ft_putstr_fd(char *s, int fd);
// outputs the string ’s’ to the given file descriptor followed by a newline.
void			ft_putendl_fd(char *s, int fd);
// outputs the integer ’n’ to the given file descriptor.
void			ft_putnbr_fd(int n, int fd);
// ###########
// ## BONUS ##
// ###########
// allocates and returns a new node. 
// variable ’content’ is initialized with the value of parameter ’content’.  
// the variable ’next’ is initialized to NULL.
t_list			*ft_lstnew(void *content);
// adds the node ’new’ at the beginning of the list.
void			ft_lstadd_front(t_list **lst, t_list *new);
// counts the number of nodes in a list.
int				ft_lstsize(t_list *lst);
// returns the last node of the list.
t_list			*ft_lstlast(t_list *lst);
// adds the node ’new’ at the end of the list.
void			ft_lstadd_back(t_list **lst, t_list *new);
// takes a node as parameter and frees the memory of the node’s content 
// using the function ’del’ given as a parameter. 
// the memory of ’next’ must not be freed.
void			ft_lstdelone(t_list *lst, void (*del)(void *));
// deletes and frees the given node and every successor of that node, 
// using the function ’del’ and free.
// finally, the pointer to the list must be set to NULL.
void			ft_lstclear(t_list **lst, void (*del)(void *));
// iterates the list ’lst’ and applies the 
// function ’f’ on the content of each node.
void			ft_lstiter(t_list *lst, void (*f)(void *));
// iterates the list ’lst’ and applies the function ’f’ on the content 
// of each node. creates a new list resulting of the successive 
// applications of the function ’f’. the ’del’ function is used 
// to delete the content of a node if needed.
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
#endif