#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<unistd.h>
#define SHMSZ 27
int main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    key = 5678;
    if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
        perror("shmget");
        return 1;
    }

   if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
       perror("shmat");
       return 1;
   }

   for (s = shm; *s != NULL; s++)
       putchar(*s);
   putchar('\n');

   *shm = '*';

   return 0;
}

