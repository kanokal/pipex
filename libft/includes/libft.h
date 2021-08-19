/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 05:11:50 by marvin            #+#    #+#             */
/*   Updated: 2021/07/04 14:59:07 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>

# include "libft_structures.h"
# include "libft_gnl.h"
# include "libft_vec3.h"

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack,
				const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *));

void		ft_rev_str(char *str);
void		*ft_free_ptr(char **str);
int			ft_free_int(char **str);
void		*ft_free_split(char **s);
char		*ft_uint_to_str(unsigned int n, char *base);
char		*ft_ulong_to_str(unsigned long n, char *base);
char		*ft_ullong_to_str(unsigned long long n, char *base);
char		*ft_ushort_to_str(unsigned short n, char *base);
char		*ft_uchar_to_str(unsigned char n, char *base);
size_t		ft_uint_length(unsigned int n, int base_length);
size_t		ft_ulong_length(unsigned long n, int base_length);
size_t		ft_ullong_length(unsigned long long n, int base_length);
size_t		ft_ushort_length(unsigned short n, int base_length);
size_t		ft_uchar_length(unsigned char n, int base_length);
double		ft_double_power(double n, int pow);
double		ft_rounds_dbl(double n, int point);
int			ft_get_top_double(double n, char *dtoa);
char		*ft_raise_base_str(char *str, int point, char *base);
int			ft_putwchar_fd(wint_t c, int fd);
int			ft_wint_byte(const wint_t c);
size_t		ft_wchar_strlen(const wchar_t *str);
int			ft_putwchar_str_fd(wchar_t *str, int fd, int size);
size_t		ft_double_length(double n, int base, int accuracy);
int			ft_str_in_chr(const char *str, int c);
size_t		ft_power(int n, int pow);
void		ft_cpy_arr_uint(unsigned int *dst, unsigned int *src,
				unsigned int len);
int			ft_putbits(long long n, unsigned long size);
char		*ft_dtoa(double n);
void		ft_strcpy(char *dst, char *src);
char		*ft_bankers_rounding_str(char *src, int point);
double		ft_clamp(double num, double max, double min);
long		ft_atol(const char *str);
long		ft_atol2(const char *str);
int			ft_atoi2(const char *str);
char		*ft_strmvptr(char *ptr, const char *s);
double		ft_atod2(char *str);
void		ft_swap(int *a, int *b);
void		ft_swap_char(char *a, char *b);
void		ft_quick_sort(int *arr, int arr_size);
void		ft_bzero_int(int *arr, size_t n);
void		ft_error_handling(char *msg);
void		ft_perror_handling(char *msg);
int			ft_rand_xor(int seed1, int seed2);

void		*ft_bigint_delete(t_bigint **src);
t_bigint	*ft_bigint_create(unsigned int idx);
int			ft_bigint_cpy(t_bigint *dst, t_bigint *src);
t_bigint	*ft_bigint_dup(t_bigint *src);
int			ft_bigint_add(t_bigint *dst, t_bigint *src);
int			ft_bigint_add_val(t_bigint *dst,
				unsigned int val, unsigned int idx);
int			ft_bigint_mult_val(t_bigint *dst, unsigned int val);
int			ft_bigint_increase(t_bigint *dst, unsigned int length);
char		*ft_bigint_to_a(t_bigint *dst);
int			ft_bigint_delete_int(t_bigint **src, int err);
t_bigint	*ft_bigint_power(unsigned int n, int pow);
int			ft_binary_to_bigint(t_bigint *dst, long long bits,
								int is_dec, int dec_length);

t_dbl		*ft_dtob(double n);
t_dbl		*ft_dbl_create(void);
void		*ft_dbl_delete(t_dbl **dst);
t_dbl		*ft_atodbl(const char *str);

#endif
