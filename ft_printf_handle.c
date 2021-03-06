/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwastche </var/mail/cwastche>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:24:34 by cwastche          #+#    #+#             */
/*   Updated: 2021/09/12 18:24:39 by cwastche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_char(va_list args)
{
	int	arg;

	arg = va_arg(args, int);
	return (write(1, &arg, 1));
}

int	ft_handle_string(va_list args)
{
	char	*arg;

	arg = va_arg(args, char *);
	if (arg == NULL)
		return (write(1, "(null)", 6));
	return (write(1, arg, ft_strlen(arg)));
}

int	ft_handle_pointer(va_list args, char c)
{
	size_t	arg;

	arg = va_arg(args, size_t);
	return (ft_putnbr_base(arg, "0123456789abcdef", 16, c));
}

int	ft_handle_int(va_list args)
{
	int	arg;
	int	ret;

	arg = va_arg(args, int);
	return (ft_putnbr_base_int(arg, "0123456789"));
}

int	ft_handle_uint(va_list args, char c)
{
	unsigned int	arg;

	arg = va_arg(args, unsigned int);
	return (ft_putnbr_base(arg, "0123456789", 10, c));
}
