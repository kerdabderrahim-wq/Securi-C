CC = gcc

# -w : Disables all warning messages
# -g : Keeps debugging information (useful if the app crashes)
CFLAGS = -w -g

# GTK Flags
GTK_FLAGS = $(shell pkg-config --cflags --libs gtk+-3.0)

# Source files (Keep quotes because of the spaces in folder names)
SHARED_SRCS = "Encryption & Decryption/enc_dec.c" \
              "Math & Security Tools/math.c" \
              "User Management/user.c" \
              "Security audit and analysis/security_audit.c" \
              "Log Management & Analysis _/log.c"

TARGET_CLI = cli.exe
TARGET_GUI = gui.exe

all: cli gui

# Compile CLI
cli:
	$(CC) $(CFLAGS) main.c $(SHARED_SRCS) -o $(TARGET_CLI)

# Compile GUI
# Note: GTK_FLAGS must be at the end for proper linking
gui:
	$(CC) $(CFLAGS) GUI.c $(SHARED_SRCS) -o $(TARGET_GUI) $(GTK_FLAGS)

clean:
	rm -f $(TARGET_CLI) $(TARGET_GUI)