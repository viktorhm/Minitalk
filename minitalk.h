/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:38:58 by vharatyk          #+#    #+#             */
/*   Updated: 2023/11/24 15:44:38 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H



#include<unistd.h>
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>


# define SPEED 100

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(int c,int fd);
int ft_strlen(char *str);

#endif
