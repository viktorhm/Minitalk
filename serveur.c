

#include<unistd.h>
#include<stdio.h>
#include<signal.h>



void convert_message (int signal)
{
    static int bit = 0; 
    static int c ;


    if(signal == SIGUSR1)
        c += 1 <<(7 - bit);
    bit++ ;

    if(bit == 8)
    {
        write(1 ,&c ,1);
        bit = 0;
        c = 0;
    }
}


int main (int argc , char **argv)
    {
        if(argc != 1 )
        {
            printf(" ERROR :IS SERVOR");
            return(0);
        }
    printf("PID : %i \n", getpid());
    signal(SIGUSR1 ,convert_message );
    signal(SIGUSR2 ,convert_message );
    while(1)
        usleep(200);

    return(0);
    }