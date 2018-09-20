/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:14:49 by zmabunda          #+#    #+#             */
/*   Updated: 2018/08/27 11:16:40 by zmabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_wstr(wchar_t *wstr, int precision)
{
	int		res;

	res = 0;
	if (wstr == NULL)
		return (ft_print_str("(null)", precision));
	while (*wstr != '\0')
	{
		res += ft_print_wchar(*wstr);
		wstr++;
	}
	return (res);
}
