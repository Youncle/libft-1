#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include <stdarg.h>
# define ALL_FLAGS "#0- +"
# define ALL_CONVERSIONS "sSpdDioOuUxXcCb"

typedef struct	s_fmt	t_fmt;

typedef	char	*(t_converter)(t_fmt *fmt, va_list ap);
typedef void	(t_sharp_func)(char *str, t_fmt *fmt);

typedef struct	s_conv
{
	char			id;
	char			allowed_flags[6];
	char			base[20];
	t_converter		*converter;
	t_sharp_func	*sharp_func;
}				t_conv;

typedef struct	s_fmt
{
	char	flags[6];
	int		width;
	int		precision;
	char	modifier[3];
	char	conversion;
	int		valid;
	t_conv	conv;
}				t_fmt;

extern t_conv	g_convs[];

t_fmt	*ft_fmt_init(void);
void	ft_fmt_print(t_fmt *fmt);

t_fmt	*ft_parse(char **format, va_list ap);
void	ft_parse_flags(t_fmt *fmt, char **format);
void	ft_parse_width(t_fmt *fmt, char **format, va_list ap);
void	ft_parse_precision(t_fmt *fmt, char **format, va_list ap);
void	ft_parse_modifiers(t_fmt *fmt, char **format);

int		ft_printf(const char *format, ...);
char	*ft_transform(t_fmt *fmt, va_list ap);

void	ft_fmt_error_conv(char conv);
void	ft_fmt_error_mod_conv(char *mod, char conv);
void	ft_fmt_error_flag_conv(char flag, char conv);
void	ft_fmt_error_flag_flag(char flag1, char flag2);

void	ft_fmt_simplify(t_fmt *fmt);
int		ft_fmt_validate_conversion(t_fmt *fmt);
void	ft_fmt_validate_flags(t_fmt *fmt);
void	ft_fmt_validate_mod(t_fmt *fmt);

char	*ft_signed_conversion(t_fmt *fmt, va_list ap);
char	*ft_unsigned_conversion(t_fmt *fmt, va_list ap);
char	*ft_str_conversion(t_fmt *fmt, va_list ap);
char	*ft_char_conversion(t_fmt *fmt, va_list ap);

void	ft_pad_sharp_o(char *str, t_fmt *fmt);
void	ft_pad_sharp_xb(char *str, t_fmt *fmt);

void	ft_pad_left(char *str, t_fmt *fmt);
void	ft_pad_right(char *str, t_fmt *fmt);
#endif