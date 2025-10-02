/* ----------------------------------------------------*/
/* ИМЯ: Pogosian Samvel, ID пользователя: 23К0180      */
/* ДАТА: 02/10/2025                                    */
/* НАЗНАЧЕНИЕ ПРОГРАММЫ:                               */
/* Перенаправление stdout в файл и выполнение команды  */
/* с помощью execvp().                                 */
/* Пример запуска: ./redirect out.txt ls -l            */
/* ИМЯ ФАЙЛА: redirect.c                               */
/* ----------------------------------------------------*/
/* ФУНКЦИИ:                                            */
/* main(argc, argv) – проверяет аргументы, открывает    */
/* файл, дублирует stdout в файл и выполняет execvp(). */
/* ----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <output_file> <command> [args...]\n", argv[0]);
        return 1;
    }

    /* Открываем файл для записи, создаём если не существует, режим 0644 */
    fd = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    /* Перенаправляем stdout в файл */
    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("dup2");
        close(fd);
        return 1;
    }

    /* Файловый дескриптор больше не нужен */
    close(fd);

    /* Выполняем указанную команду; если execvp вернул, произошла ошибка */
    execvp(argv[2], &argv[2]);
    perror("execvp");
    return 1;
}
