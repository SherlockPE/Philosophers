/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:07:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/24 17:09:10 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*ft_calloc(int	size, int cant)
{
	unsigned char	*result;
	int				i;

	result = malloc(size * cant);
	if (!result)
		return (NULL);
	i = 0;
	while (i < (size * cant))
		result[i++] = 0;
	return (result);
}

int	ft_atoi(const char *str)
{
	int	symbol;
	int	number;

	number = 0;
	symbol = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			symbol = -symbol;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * symbol);
}
