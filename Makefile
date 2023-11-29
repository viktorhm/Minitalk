CFLAGC = -Wall -Wextra -Werror
CC = gcc

c_src = outils.c atoi.c
c_obj=$(c_src:.c=.o)

server = server 
client = client

all: $(server) $(client)

bonus:$(server_bonus) $(client_bonus)


$(server):$(c_obj) minitalk.h
	$(CC) $(CFLAGS) server.c $(c_obj) -o $(server)
$(client):$(c_obj) minitalk.h
	$(CC) $(CFLAGS) client.c $(c_obj) -o $(client)
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(c_obj) $(cb_obj)
fclean: clean
	rm -rf $(client) $(server)
re: fclean all
