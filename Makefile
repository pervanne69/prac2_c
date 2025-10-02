# -----------------------------------------------------
# Makefile для Практической работы №4
# Автор: Pogosian Samvel (23К0180)
# Дата: 02/10/2025
# -----------------------------------------------------

CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Цели по умолчанию
all: fork1 fork2 myexec redirect task

# Сборка fork1
fork1: fork1.c
	$(CC) $(CFLAGS) fork1.c -o fork1

# Сборка fork2
fork2: fork2.c
	$(CC) $(CFLAGS) fork2.c -o fork2

# Сборка myexec
myexec: myexec.c
	$(CC) $(CFLAGS) myexec.c -o myexec

# Сборка redirect
redirect: redirect.c
	$(CC) $(CFLAGS) redirect.c -o redirect

# Сборка task
task: task.c
	$(CC) $(CFLAGS) task.c -o task

# Очистка скомпилированных файлов
clean:
	rm -f fork1 fork2 myexec redirect task
