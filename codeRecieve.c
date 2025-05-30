//recieve
#include <stdio.h>
#include <sys/ipc.h> //inter process communication
#include <sys/msg.h> //for message passing

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
		key = ftok("progfile",65);
		
		//msgget creates a msg queue and returns identifier
		msgid = msgget(key, 0666 | IPC_CREAT);
		
		//msgrcv to recieve message
		msgrcv(msgid, &message, sizeof(message),1,0);
		
		//display the msg
		printf("Data recieve is: %s \n",message.mesg_text);
		
		//to destroy the msg queue
		msgctl(msgid, IPC_RMID, NULL);
		return 0;
	}
