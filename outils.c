/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:32:32 by vharatyk          #+#    #+#             */
/*   Updated: 2023/11/24 18:15:42 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * (-1);
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
			ft_putchar_fd(n + '0', fd);
	}
}

void	ft_putchar_fd(int c, int fd)
{
	write(1, &c, fd);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0 ;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*value;

	value = (void *)malloc(elementCount * elementSize);
	if (!value)
		exit(0);
	ft_bzero (value, elementSize * elementCount);
	return (value);
}

void	ft_bzero(void *str, size_t count)
{
	unsigned char	*string;
	size_t			i;

	if (count == 0)
		return ;
	i = 0;
	string = str;
	while (i < count)
	{
		string[i] = 0;
		i++;
	}
}
