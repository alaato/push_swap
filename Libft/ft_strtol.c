/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:38:33 by alaa              #+#    #+#             */
/*   Updated: 2024/03/27 19:07:56 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\v'
		|| c == '\f')
		return (1);
	return (0);
}
static unsigned char	ft_issign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}
long	ft_strtol(const char *str, char **endptr, int base)
{
	long ret;
	char sign;
	size_t i;

	base = 10;
	ret = 0;
	sign = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
		sign = str[i++] == '-' ? -1 : 1;
	if (ft_isdigit(str[i]))
		while (str[i] && ft_isdigit(str[i]))
		{
			if (ret > LONG_MAX / base || (unsigned char)(str[i] - 48) > LONG_MAX
				- ret * base)
				return (sign == -1 ? LONG_MIN : LONG_MAX);
			ret = ret * base + str[i] - 48;
			i++;
		}
	*endptr = (char *)(str + i);
	return (sign * ret);
}