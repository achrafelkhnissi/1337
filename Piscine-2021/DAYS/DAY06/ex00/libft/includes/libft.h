#ifndef LIBFT_H
#define LIBFT_H

/* put */
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
void	ft_putstr_non_printable(char *str);
void	ft_putnbr_base(int nbr, char *base);

/* str */
int	ft_strlen(char *str);
char	*ft_strrev(char *str);
int	ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int	ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);
int	ft_str_is_alpha(char *str);
int	ft_str_is_numeric(char *str);
int	ft_str_is_lowercase(char *str);
int	ft_str_is_uppercase(char *str);
int	ft_str_is_printable(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int n);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

/* int */
int	ft_factorial(int nb);
int	ft_power(int nb, int power);
int	ft_fibonacci(int index);
int	ft_sqrt(int nb);
int	ft_is_prime(int nb);
int	ft_find_next_prime(int nb);
void	ft_swap(int *a, int *b);
int	ft_atoi(char *str);
void	ft_rev_int_tab(int *tab, int size);
void	ft_sort_int_tab(int *tab, int size);
int	ft_atoi_base(char *str, char *base);

#endif
