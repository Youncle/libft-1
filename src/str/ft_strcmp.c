/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 10:49:02 by jhalford          #+#    #+#             */
<<<<<<< HEAD:src/str/ft_strcmp.c
/*   Updated: 2016/11/03 16:08:51 by jhalford         ###   ########.fr       */
=======
/*   Updated: 2016/11/05 11:22:15 by jhalford         ###   ########.fr       */
>>>>>>> 1f1cb4b14d273f8950585bfb2f8033e3674a5783:ft_strcmp.c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i))
		i++;
	return (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i));
}
