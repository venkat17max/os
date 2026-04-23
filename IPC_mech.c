//PIPE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    char msg[] = "Hello from parent";
    char buf[100];

    pipe(fd);

    if(fork() == 0) { // child
        close(fd[1]);
        read(fd[0], buf, sizeof(buf));
        printf("Child received: %s\n", buf);
    } else { // parent
        close(fd[0]);
        write(fd[1], msg, strlen(msg)+1);
        wait(NULL);
    }
}
//FIFO
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd;
    char msg[] = "Hello FIFO";
    char buf[100];

    mkfifo("myfifo", 0666);

    if(fork() == 0) { // child (reader)
        fd = open("myfifo", O_RDONLY);
        read(fd, buf, sizeof(buf));
        printf("Child received: %s\n", buf);
        close(fd);
    } else { // parent (writer)
        fd = open("myfifo", O_WRONLY);
        write(fd, msg, strlen(msg)+1);
        close(fd);
        wait(NULL);
    }
}
//MESSAGE QUEUE
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

struct msg {
    long type;
    char text[100];
};

int main() {
    int id;
    struct msg m;

    id = msgget(1234, 0666 | IPC_CREAT);

    if(fork() == 0) { // child (receiver)
        msgrcv(id, &m, sizeof(m.text), 1, 0);
        printf("Child received: %s\n", m.text);
    } else { // parent (sender)
        m.type = 1;
        strcpy(m.text, "Hello MQ");
        msgsnd(id, &m, sizeof(m.text), 0);
        wait(NULL);
    }
}
//SHARED MEMORY
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int id;
    char *ptr;

    id = shmget(1234, 100, 0666 | IPC_CREAT);
    ptr = (char*) shmat(id, NULL, 0);

    if(fork() == 0) { // child (reader)
        sleep(1);
        printf("Child read: %s\n", ptr);
    } else { // parent (writer)
        strcpy(ptr, "Hello Shared Memory");
        wait(NULL);
    }

    shmdt(ptr);
}