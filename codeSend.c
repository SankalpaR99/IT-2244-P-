//send


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10

//structure for msg queue

struct mesq_buffer{
		long mesg_type;
		char mesg_text[100];
	}
	message;
	
	int main(){
		key_t key;
		int msgid;
		//ftok to generate unique key
		key = ftok("2021ict59",65);
		
		//msgget creates a msg queue and returns identifier
		msgid = msgget(key, 0666 | IPC_CREAT);
		message.mesg_type = 1;
		printf("Write Data : ");
		
		fgets(message.mesg_text,MAX,stdin);
		//msgsnd to send msg
		msgsnd(msgid, &message, sizeof(message),0);
		//Display the msg
		printf("Data send is: %s \n",message.mesg_text);
		return 0;
	}
	
