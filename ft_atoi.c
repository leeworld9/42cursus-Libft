/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:47:51 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/04 00:18:09 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_limitchk(int nbr)
{
	if (INT_MAX < nbr)
		return (-1);
	else if (INT_MIN > nbr)
		return (0);
	else
		return (nbr);
}

int	ft_atoi(const char *n)
{
	int			i;
	long long	sum;
	long long	chk;

	i = 0;
	sum = 0;
	chk = 1;
	while (ft_isspace(*n))
		n++;
	if (*n == '-' || *n == '+')
		chk = (*n++ == '-') ? -1 : 1;
	while (n[i] != '\0')
	{
		if (ft_isspace(n[i]) || !ft_isdigit(n[i]) || n[i] == '-' || n[i] == '+')
			return (ft_limitchk(sum * chk));
		sum *= 10;
		sum += (n[i] - '0');
		if (INT_MAX < sum * chk)
			return (-1);
		else if (INT_MIN > sum * chk)
			return (0);
		i++;
	}
	return (sum * chk);
}
