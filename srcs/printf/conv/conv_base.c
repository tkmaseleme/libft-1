/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:31:41 by wescande          #+#    #+#             */
/*   Updated: 2017/10/20 12:07:38 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_b_o(t_wrk *w, t_conv *tmp, va_list ap)
{
	(void)w;
	tmp->base = 8;
	tmp->is_neg = 0;
	tmp->sign = 0;
	tmp->spa = 0;
	tmp->num = CASTVA_ARG(ap, unsigned long long int);
	add_i(tmp);
}

void	conv_o(t_wrk *w, t_conv *tmp, va_list ap)
{
	(void)w;
	tmp->base = 8;
	tmp->is_neg = 0;
	tmp->sign = 0;
	tmp->spa = 0;
	if (tmp->is_long_long)
		tmp->num = CASTVA_ARG(ap, unsigned long long int);
	else if (tmp->is_long)
		tmp->num = CASTVA_ARG(ap, unsigned long int);
	else if (tmp->is_char)
		tmp->num = (unsigned char)CASTVA_ARG(ap, unsigned int);
	else if (tmp->is_short)
		tmp->num = (unsigned short int)CASTVA_ARG(ap, unsigned int);
	else
		tmp->num = CASTVA_ARG(ap, unsigned int);
	add_i(tmp);
}

void	conv_b_x(t_wrk *w, t_conv *tmp, va_list ap)
{
	(void)w;
	tmp->base = 16;
	tmp->is_neg = 0;
	tmp->sign = 0;
	tmp->spa = 0;
	tmp->spec = 'X';
	if (tmp->is_long_long)
		tmp->num = CASTVA_ARG(ap, unsigned long long int);
	else if (tmp->is_long)
		tmp->num = CASTVA_ARG(ap, unsigned long int);
	else if (tmp->is_char)
		tmp->num = (unsigned char)CASTVA_ARG(ap, unsigned int);
	else if (tmp->is_short)
		tmp->num = (unsigned short int)CASTVA_ARG(ap, unsigned int);
	else
		tmp->num = CASTVA_ARG(ap, unsigned int);
	if (!tmp->num)
		tmp->sha = 0;
	add_i(tmp);
}

void	conv_x(t_wrk *w, t_conv *tmp, va_list ap)
{
	(void)w;
	tmp->base = 16;
	tmp->is_neg = 0;
	tmp->sign = 0;
	tmp->spa = 0;
	tmp->spec = 'x';
	if (tmp->is_long_long)
		tmp->num = CASTVA_ARG(ap, unsigned long long int);
	else if (tmp->is_long)
		tmp->num = CASTVA_ARG(ap, unsigned long int);
	else if (tmp->is_char)
		tmp->num = (unsigned char)CASTVA_ARG(ap, unsigned int);
	else if (tmp->is_short)
		tmp->num = (unsigned short int)CASTVA_ARG(ap, unsigned int);
	else
		tmp->num = CASTVA_ARG(ap, unsigned int);
	if (!tmp->num)
		tmp->sha = 0;
	add_i(tmp);
}
