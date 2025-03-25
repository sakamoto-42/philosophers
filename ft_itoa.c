/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:41:59 by julien            #+#    #+#             */
/*   Updated: 2025/03/24 21:42:30 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	ft_get_n_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	unsigned int	nb;

	len = ft_get_n_len(n);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		nb = (unsigned int)-n;
	else
		nb = (unsigned int)n;
	while (len--)
	{
		str[len] = (char)((nb % 10) + 48);
		nb = nb / 10;
		if (len == 0 && n < 0)
			str[0] = '-';
	}
	return (str);
}
