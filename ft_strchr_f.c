/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:20:39 by zmabunda          #+#    #+#             */
/*   Updated: 2018/08/27 11:21:15 by zmabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_strchr_f(char *s, int c)
{
	char	*tmp;

	tmp = s;
	while (*tmp != '\0')
	{
		if (*tmp == c)
			return (1);
		tmp++;
	}
	if (*tmp == '\0' && c == '\0')
		return (0);
	return (0);
}
