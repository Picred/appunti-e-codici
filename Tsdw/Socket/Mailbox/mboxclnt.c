/* mboxclnt.c */ 

/* Sintassi: mboxclnt send source dest message *
 *           mboxclnt recv dest [source|ANY]
 */

#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>   // attenti a man ip!

#include "mbox.h"

int mkaddr(struct sockaddr_in * addr, const char * hostname, u_int16_t port);
 
int main(int argc, char * argv[]) 
{
	int client_socket; 
	int retcode; 
	struct sockaddr_in server_addr; 
	MESSAGE req, reply;
	
	if ( argc < 4 || argc > 5 || 
	    (argc == 4 && strcmp(argv[1], "recv")) ) {	// with four args, message can only be recv
		printf("Usage: %s send source dest message\n", argv[0]);
		printf("       %s recv dest [source|ANY]\n", argv[0]);
		exit(-1);
	}

	// apertura del socket del client
	client_socket = socket(AF_INET, SOCK_STREAM, 0); 
	if (client_socket == -1) 
		{perror("aprendo il socket del client"); exit(-1);}

	// preparazione indirizzo su cui connettere il socket
	mkaddr(&server_addr, SERVERNAME, SERVERPORT);
	
	// connessione al socket del server
	retcode = 
	connect(client_socket, (struct sockaddr *) &server_addr, 
		    sizeof(server_addr)
		   ); 
	if(retcode == -1) 
		{perror("connettendo il socket"); exit(-1);}

	// codice specifico mailbox client

	if (strcmp(argv[1],"send") == 0) {
		req.type = SEND;
		strcpy(req.src, argv[2]);
		strcpy(req.dest, argv[3]);
		strcpy(req.info, argv[4]);
	} else { // receive
		req.type = (strcmp(argv[3],"ANY") == 0) ? RECEIVEANY : RECEIVE;
		strcpy(req.src, argv[2]);
		strcpy(req.dest, argv[3]);
	}
	retcode = write(client_socket, &req, sizeof(req));
	printf("Request sent to server\n\n");
	
	retcode = read(client_socket, &reply, sizeof(reply));
//	in realta` occorrerebbero write/read multiple e una gestione di retcode
	
	printf("Server answers:\n");
	switch (reply.type) {
	case ERROR:    // con mboxsrvr non dovrebbe accadere, ma e` meglio
		printf(">>>error\n"); break;              // verificare sempre
	case NOMSG:                 // non ci sono messaggi per il cliente    
		printf(">>>no message\n"); break;   
	case OK:
		if (req.type == SEND) {
			printf(">>>acknowledging message from %s for %s:\n", 
			       reply.src, reply.dest);
			break;
		}
		// req.type == RECEIVE
		printf(">>>follows message from %s for %s:\n", 
		       reply.src, reply.dest);
		printf("%s\n", reply.info);
		printf(">>>\n");
		break;
	case MBOXFULL:
		printf("Mailbox del server piena\n");
	default:
		printf("type of reply message %d\n", reply.type);
	}
	
	// fine codice specifico mailbox client
	printf("\n");
	close(client_socket); 
	exit(0);
}
