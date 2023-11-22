#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>


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
        printf("ERROR : <PID> <MSG>");
        return(0);
    }
    else if(is_nubers(argv[1]))
    {
        printf("ERROR : PID = INT");
        return(0);
    }
    else if(argv[2] == 0)
    {
        printf("KO : NO MESSAGE" );
        return(0);
    }
    else 
        return(1);
}

// envoyer des bits 
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
        usleep(500);
        bit-- ;
    }


}
static void send_len(int len , int pid)
{
int bit;

bit = 19 ;
while(bit >= 0) 
    {
        printf("%d", len >> bit & 1);
        if( len >> bit & 1)
            kill(pid , SIGUSR1);
        else 
            kill(pid , SIGUSR2);
        usleep(500);
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