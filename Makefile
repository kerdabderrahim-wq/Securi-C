CC = gcc
CFLAGS = -Wall -Wextra -g

# List all source files here
SRCS = main.c \
       "Encryption & Decryption/enc_dec.c" \
       "Math & Security Tools/math.c" \
       "User Management/user.c" \
       "Security audit and analysis/security_audit.c" \
       "Log Management & Analysis _/log.c"

# The name of your final program
TARGET = CLI

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)