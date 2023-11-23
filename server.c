/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:40:31 by vharatyk          #+#    #+#             */
/*   Updated: 2023/11/23 16:40:34 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"minioutils.h"


static void convert_int(int sig, int *len)
{
    static int len_total = 0;
    static int bit = 0;

     if(sig == SIGUSR1)
        len_total += 1 <<(31 - bit);
    bit++ ;
    if(bit == 32)
    {
        bit = 0 ;
        *len = len_total ;
    }
}
// static void get_line_reset(char **str , int *len , int c  )
// {
//     static int  i = 0;
//     int j ;
//     write(1,&c,1);
//     *str[i] = c;
//     if(c == 0)
//     {
//         j=0;
//         write(1,&(*str)[j],1);
//         i = 0;
//         while((str)[j])
//         {
//             write(1,"S>",2);
//             write(1,(str)[j++],1);
//         }
//         *len = 0;
//         // free(str);
//         // *str = 0 ;
//     }
// }


static void convert_message (int sig)
{
    static int  bit = 0;
    static int  c = 0;
    static int  len = 0;
    static char *str = NULL;
    static int count = 0;

    if(len == 0)
        convert_int( sig, &len);
    else
    {
        if (str == NULL)
            str = calloc(len, sizeof(*str));
        if(sig == SIGUSR1)
            c += 1 <<(7 - bit);
        bit++ ;
        if(bit == 8)
        {
            bit = 0;
            str[count] = c;
            count++;
            c = 0;
        }
        if (count == len)
        {
            write(1, str, len);
            free(str);
            count = 0;
        }
    }
}


int main (int argc , char **argv)
    {
        if(argc != 1 )
        {
            printf(" ERROR :IS SERVOR");
            return(0);
        }
    write(1,"PID :",5);
    ft_putnbr_fd( getpid(), 1);
    signal(SIGUSR1 ,convert_message );
    signal(SIGUSR2 ,convert_message );
    while(1)
        usleep(500);

    return(0);
    }
