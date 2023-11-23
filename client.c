/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:41:07 by vharatyk          #+#    #+#             */
/*   Updated: 2023/11/23 15:16:33 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define SPEED 500

// check PID
static int is_nubers(char *argv)
{
int i;

i = 0;
while(argv[i])
{
if(argv[i] <= '1' && argv[i] >= '9')
    i++ ;
else
    return(0);
}
return(1);
}

// check the value enter for user
static int good_argument(int argc , char **argv)
{
    if(argc != 3)
    {
        write(1,"ERROR : <PID> <MSG>",18);
        return(0);
    }
    else if(is_nubers(argv[1]))
    {
        write(1,"ERROR : PID = INT",15);
        return(0);
    }
    else if(argv[2] == 0)
    {
        write(1,"KO : NO MESSAGE",14);
        return(0);
    }
    else
        return(1);
}

// send to binaire , SIGUSR1
static void send_octet(char c , int pid )
{
    int bit;

    bit = 7 ;
    while(bit >= 0)
    {
        if( c >> bit & 1)
            kill(pid , SIGUSR1);
        else
            kill(pid , SIGUSR2);
        usleep(SPEED);
        bit-- ;
    }


}
// sen
static void send_len(int len , int pid)
{
int bit;

bit = 31 ;
while(bit >= 0)
    {
        printf("%d", len >> bit & 1);
        if( len >> bit & 1)
            kill(pid , SIGUSR1);
        else
            kill(pid , SIGUSR2);
        usleep(SPEED);
        bit-- ;
    }

}

int main (int argc ,char** argv)
{
    int pid;
    int i;
    char    *str;
    int     len;

    if (good_argument(argc , argv ) == 1)
    {

        pid = atoi(argv[1]);
        str = argv[2];
        i = 0;
        len = strlen(str) + 2;
        str[len] = '\0';

        send_len(len , pid);

        while(str[i])
        {
            send_octet(str[i++] , pid );
        }
        send_octet(str[i++] , pid ); // renvoie le dernier le retour chariot
        send_octet('\n', pid); // retour a la ligne



    }
    //free(str);
    return 0 ;
}
