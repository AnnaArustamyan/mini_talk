SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror 
LDFLAGS = -Iprintf -Lprintf -lprintf

all: $(SERVER) $(CLIENT)

$(SERVER): server.c printf/printf.a
	$(CC) $(CFLAGS) $(LDFLAGS) server.c -o $(SERVER)

$(CLIENT): client.c printf/printf.a
	$(CC) $(CFLAGS) $(LDFLAGS) client.c -o $(CLIENT)

printf/printf.a:
	make -C printf

clean:
	make clean -C printf
	
fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make fclean -C printf

re: fclean all

.PHONY: all clean fclean re printf/printf.a