/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:07:39 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/10 16:58:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_stos g_colors[] =
{
	{"{bla}", FG_BLACK},
	{"{red}", FG_RED},
	{"{gre}", FG_GREEN},
	{"{yel}", FG_YELLOW},
	{"{blu}", FG_BLUE},
	{"{mag}", FG_MAGENTA},
	{"{cya}", FG_CYAN},
	{"{eoc}", FG_DEFAULT},
	{"{bol}", ON_BOLD},
	{"{und}", ON_UNDERLINED},
	{"{inv}", ON_INVERTED},
	{NULL, NULL},
};

void	ft_printf_color(char **final, char **str, va_list ap)
{
	int		i;

	i = 0;
	if (ft_strncmp(*str, "{ran}", 5) == 0)
	{
		i = va_arg(ap, int) % 7 + 1;
		*final = ft_strjoin(*final, g_colors[i].val);
		*str += 5;
		return ;
	}
	while(g_colors[i].key)
	{
		if (ft_strncmp(*str, g_colors[i].key, 5) == 0)
		{
			/* if (isatty(fd)) */
			*final = ft_strjoin(*final, g_colors[i].val);
			*str += 5;
			return ;
		}
		i++;
	}
}
