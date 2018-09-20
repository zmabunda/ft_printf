/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:46:18 by zmabunda          #+#    #+#             */
/*   Updated: 2018/08/27 10:48:16 by zmabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		digit_size(intmax_t digit)
{
	char	res;

	res = 1;
	digit /= 10;
	while (digit)
	{
		digit /= 10;
		res++;
	}
	return (res);
}

static char		digit_len(t_flist *lst, intmax_t digit)
{
	char				res;
	char				tmp;

	tmp = 0;
	res = digit_size(digit);
	if (lst->precision != -1 && lst->precision > res)
	{
		tmp = (lst->precision - res);
		res = lst->precision;
	}
	if (tmp > 0)
		lst->precision = tmp;
	else if (digit == 0 && lst->precision == 0)
	{
		lst->precision = -2;
		res = 0;
	}
	else
		lst->precision = -1;
	if ((digit < 0) || (((lst->flags)[4] == '+' || (lst->flags)[5] == ' ') &&
				digit >= 0))
		res++;
	return (res);
}

static char		output_digit(intmax_t digit, t_flist *lst)
{
	char len;

	len = 0;
	if (digit == 0 && lst->precision == -2)
		return (0);
	if (-10 < digit && digit < 10)
		len += ft_print_char(ABS(digit) + '0');
	else
	{
		len += output_digit(digit / 10, lst);
		len += output_digit(digit % 10, lst);
	}
	return (len);
}

static short	ft_short_digit(t_flist *lst, intmax_t digit, int *len)
{
	if ((lst->flags)[2] == '0' && lst->precision == -1)
		(lst->flags)[0] = '0';
	lst->size = digit_len(lst, digit);
	if (digit < 0 && lst->flags[0] == '0')
		*len += ft_print_char('-');
	else if (digit >= 0 && lst->flags[0] == '0' && lst->flags[4] == '+')
		*len += ft_print_char('+');
	else if (lst->flags[0] == '0' && lst->flags[5] == ' ')
		*len += ft_print_char(' ');
	while ((lst->flags)[3] != '-' && lst->width > (lst->size))
		(*len += ft_print_char((lst->flags)[0])) && lst->width--;
	if ((lst->flags)[4] == '+' && digit >= 0 && lst->flags[0] != '0')
		*len += ft_print_char('+');
	else if (digit < 0 && lst->flags[0] == ' ' && lst->flags[0] != '0')
		*len += ft_print_char('-');
	else if ((lst->flags)[5] == ' ' && digit >= 0 && lst->flags[0] != '0')
		*len += ft_print_char(' ');
	while (lst->precision != -1 && lst->precision > 0)
		(*len += ft_print_char('0')) && lst->precision--;
	*len += output_digit(digit, lst);
	while (lst->width > lst->size && (lst->flags)[3] == '-')
		(*len += ft_print_char(' ')) && lst->width--;
	return (*len);
}

int				ft_handling_digit(t_flist *lst, void *digit)
{
	int len;

	len = 0;
	if (lst->spec == 'D')
		(ft_short_digit(lst, (long)digit, &len));
	else if (lst->j)
		(ft_short_digit(lst, (intmax_t)digit, &len));
	else if (lst->ll)
		(ft_short_digit(lst, (long long)digit, &len));
	else if (lst->z)
		(ft_short_digit(lst, (size_t)digit, &len));
	else if (lst->l)
		(ft_short_digit(lst, (long)digit, &len));
	else if (lst->h)
		(ft_short_digit(lst, (short)digit, &len));
	else if (lst->hh)
		(ft_short_digit(lst, (char)digit, &len));
	else
		(ft_short_digit(lst, (int)digit, &len));
	return (len);
}
