// ipc_combined.c
/*IPC using Message Queue

Read inputs from the parent process
Enter Name: Sanka
Enter RegNo: 2021ICT59
Enter Age: 25

Message successfully

Give the output from the child process

Received Name: Sanka
Received RegNo: 2021ICT59
Received Age: 25
*/






#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

struct mesg_buffer {
    long mesg_type;
    char name[50];
    char regno[20];
    int age;
} message;

int main() {
    key_t key;
    int msgid;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    printf("Parent Process ID: %d\n", getpid());

    message.mesg_type = 1;

    printf("Enter Name: ");
    fgets(message.name, sizeof(message.name), stdin);
    message.name[strcspn(message.name, "\n")] = '\0';

    printf("Enter RegNo: ");
    fgets(message.regno, sizeof(message.regno), stdin);
    message.regno[strcspn(message.regno, "\n")] = '\0';

    printf("Enter Age: ");
    scanf("%d", &message.age);

    // Send message before forking child
    msgsnd(msgid, &message, sizeof(message) - sizeof(long), 0);

    printf("\nMessage successfully sent from parent.\n\n");

    pid_t pid = fork();

    if (pid > 0) {
        // Parent waits for child
        wait(NULL);
    } else if (pid == 0) {
        printf("Child Process ID: %d\n", getpid());

        msgrcv(msgid, &message, sizeof(message) - sizeof(long), 1, 0);

        printf("Received Name: %s\n", message.name);
        printf("Received RegNo: %s\n", message.regno);
        printf("Received Age: %d\n", message.age);

        msgctl(msgid, IPC_RMID, NULL);
    } else {
        perror("fork failed");
    }

    return 0;
}
