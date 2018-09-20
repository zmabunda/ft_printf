/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:00:38 by zmabunda          #+#    #+#             */
/*   Updated: 2018/08/27 11:02:27 by zmabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_size_o_octal(intmax_t digit)
{
	char			res;

	res = 1;
	digit /= 8;
	while (digit)
	{
		digit /= 8;
		res++;
	}
	return (res);
}

static char		octal_digit_len(t_flist *lst, intmax_t digit)
{
	char			res;
	char			tmp;

	tmp = 0;
	res = ft_size_o_octal(digit);
	if (lst->precision != -1 && lst->precision > res)
	{
		tmp = (lst->precision - res);
		res = lst->precision;
	}
	if (lst->flags[1] == '#' && digit != 0)
		res += 1;
	if (tmp > 0)
		lst->precision = tmp;
	else if (digit == 0 && lst->precision == 0 && lst->flags[1] != '#')
	{
		lst->precision = -2;
		res = 0;
	}
	else
		lst->precision = -1;
	return (res);
}

static char		output_o_digit(uintmax_t digit, t_flist *lst, char *base)
{
	char	len;

	len = 0;
	if (digit == 0 && lst->precision == -2)
		return (0);
	if (digit >= 8)
	{
		len += output_o_digit(digit / 8, lst, base);
		len += ft_print_char(base[digit % 8]);
	}
	else
		len += ft_print_char(base[digit % 8]);
	return (len);
}

static short	hand_octal(t_flist *lst, uintmax_t digit)
{
	short	len;

	len = 0;
	if ((lst->flags)[2] == '0' && lst->precision == -1)
		(lst->flags)[0] = '0';
	lst->size = octal_digit_len(lst, digit);
	if (lst->flags[0] == '0' && lst->flags[1] == '#' && digit != 0)
		len += ft_print_char('0');
	while ((lst->flags)[3] != '-' && lst->width > (lst->size))
		(len += ft_print_char((lst->flags)[0])) && lst->width--;
	if (lst->flags[0] == ' ' && lst->flags[1] == '#' && digit != 0)
		len += ft_print_char('0');
	while (lst->precision != -1 && lst->precision > 0)
		(len += ft_print_char('0')) && lst->precision--;
	len += output_o_digit(digit, lst, "01234567");
	while (lst->width > lst->size && (lst->flags)[3] == '-')
		(len += ft_print_char(' ')) && lst->width--;
	return (len);
}

int				ft_handling_o(t_flist *lst, void *digit)
{
	if (lst->spec == 'O')
		return (hand_octal(lst, (unsigned long)digit));
	else if (lst->j)
		return (hand_octal(lst, (uintmax_t)digit));
	else if (lst->ll)
		return (hand_octal(lst, (unsigned long long)digit));
	else if (lst->z)
		return (hand_octal(lst, (size_t)digit));
	else if (lst->l)
		return (hand_octal(lst, (unsigned long)digit));
	else if (lst->h)
		return (hand_octal(lst, (unsigned short)digit));
	else if (lst->hh)
		return (hand_octal(lst, (unsigned char)digit));
	else
		return (hand_octal(lst, (unsigned int)digit));
}
