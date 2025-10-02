/* ----------------------------------------------------*/
/* ИМЯ: Pogosian Samvel, ID пользователя: 23К0180      */
/* ДАТА: 02/10/2025                                    */
/* НАЗНАЧЕНИЕ ПРОГРАММЫ:                               */
/* Демонстрация порождения дочернего процесса и        */
/* использования задержки (sleep) в дочернем процессе. */
/* ИМЯ ФАЙЛА: fork2.c                                  */
/* ----------------------------------------------------*/
/* ФУНКЦИИ:                                            */
/* main() – создаёт процесс, дочерний ждёт, выводит и  */
/*          завершает работу.                          */
/* ----------------------------------------------------*/

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;

    /* вывод идентификаторов до fork() */
    printf("I'm the original process with pid %d and ppid %d\n",
           (int)getpid(), (int)getppid());

    pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid != 0) {
        /* Родительский процесс */
        printf("I'm the parent process with pid %d and ppid %d\n",
               (int)getpid(), (int)getppid());
        printf("My child's pid is %d\n", (int)pid);
    } else {
        /* Дочерний процесс: добавляем задержку, чтобы показать осиротение */
        sleep(5);
        printf("I'm the child process with pid %d and ppid %d\n",
               (int)getpid(), (int)getppid());
        printf("\n was deserted\n");
    }

    printf("Pid %d terminates.\n", (int)getpid());
    return 0;
}
