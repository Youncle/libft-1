/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:47:00 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/14 20:26:46 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

char	g_error_msglist[E_MAX][ERRMSG_MAX_SIZE] =
{
	"no error",
	"invalid option --%s",
	"invalid option -%c",
	"option '%c' awaits argument(s): please don't combine",
};

int		g_errnum = 0;
char	*g_errmsg = NULL;
char	**g_argv;

int		error_set(int n, ...)
{
	va_list	ap;

	g_errnum = n;
	va_start(ap, n);
	ft_strdel(&g_errmsg);
	ft_vasprintf(&g_errmsg, g_error_msglist[n], ap);
	return (g_errnum);
}

int		ft_perror(void)
{
	ft_dprintf(2, "{red}%s: %s{eoc}\n", g_argv[0], g_errmsg);
	return (g_errnum);
}
