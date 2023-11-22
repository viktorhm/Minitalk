

#include<unistd.h>
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>


static void convert_int(int sig , char **str ,int *len)
{
    static int len_total = 0;
    static int bit = 0; 

     if(sig == SIGUSR1)
            len_total += 1 <<(19 - bit);
        bit++ ;
        if(bit == 20)
        {
            *str = calloc(len_total, sizeof (char));
            write(1,"ALLOC>",6);
            bit = 0 ;
            *len = 1 ;
            len_total = 0;
        }
   
}
static void get_line_reset(char **str , int *len , int c  )
{
    int  i = 0;
    
   

    if( c == 0)
    {
        write(1,&*str[0],1);
        i = 0;
        while(*str[i]){
            write(1,"S>",2);
            write(1,&*str[i++],1);  }
        *len = 0;
        // free(str);
        // *str = 0 ;   
    } 
}
    
    
static void convert_message (int sig)
{
    static int  bit = 0; 
    static int  c = 0;
    static int  len = 0;
    static int  i = 0 ;
    static char *str = 0;

    if(len == 0)
     convert_int( sig , &str ,&len);
    else
    {
        if(sig == SIGUSR1)
            c += 1 <<(7 - bit);
        bit++ ;
        if(bit == 8)
        {
            bit = 0;
            str[i++] = c;
            printf("{%d}",c);
            get_line_reset( &str, &len , c );
            c = 0;
            i = 0;
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
     
    printf("PID : %i \n", getpid());
    signal(SIGUSR1 ,convert_message );
    signal(SIGUSR2 ,convert_message );
    while(1)
        usleep(500);

    return(0);
    }