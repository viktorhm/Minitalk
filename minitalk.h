/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:38:58 by vharatyk          #+#    #+#             */
/*   Updated: 2023/11/24 16:03:18 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define SPEED 200
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	*ft_calloc(size_t elementCount, size_t elementSize);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *str, size_t count);
void	ft_putchar_fd(int c, int fd);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);

#endif
