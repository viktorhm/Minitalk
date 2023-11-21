
#include<unistd.h>
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

static void convert_int(int signal , int len , int bit , char **str)
{

    static int len_total = 0  ;


    if(signal == SIGUSR2)
        len_total += 1 <<(7 - bit);
    bit++ ;

    if(bit == 31)
    {
        len = 1 ;
        str = calloc(len_total +1 , sizeof (char));
        bit = 0;
        len_total = 0;
    }
    bit++;
}


void convert_message (int signal)
{
    static int      bit = 0;
    static int      c  = 0;
    static int      len = 0;
    static char     *str = 0;
    static int       i = 0;

    printf("e");

    if(!len)
        {printf("e");convert_int(signal ,len , bit , &str );}
    else
    {
        if(signal == SIGUSR1)
            c += 1 <<(7 - bit);
        bit++ ;

        if(bit == 8)
        {
            str[i++] = c ;
            printf("test");
            bit = 0;
            c = 0;
            if (c == 0)
            {
                printf("((%s))",str);
                free(str);
                c = 0;
                return ;
            }
        }
    }
}

int main (int argc , char **argv)
    {
static int len;
static char *str ;


        if(argc != 1 )
        {
            printf(" ERROR :IS SERVOR");
            return(0);
        }
    printf("PID : %i \n", getpid());

    signal(SIGUSR1 ,convert_message );
    signal(SIGUSR2 ,convert_message );
    while(1)
        usleep(100);

    return(0);
    }
