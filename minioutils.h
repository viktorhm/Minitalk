/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minioutils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:38:58 by vharatyk          #+#    #+#             */
/*   Updated: 2023/11/23 16:42:25 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIOUTILS_H
# define MINIOUTILS_H



#include<unistd.h>
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>


# define SPEED 500

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(int c,int fd);

#endif
