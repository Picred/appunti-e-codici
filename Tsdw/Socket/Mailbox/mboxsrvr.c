/* mboxsrvr.c */

/* Server gestione mailbox.
 * NB: ordine arrivo messaggi non lascia traccia.
 */

#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>   // attenti a man ip!

#include "mbox.h"

MESSAGE mailbox[MBOXSIZE];  // andrebbe integrato
int nmsg;                   // in unico ADT (classe)

MESSAGE messg;

void msgprocess(int conn_sk);
int mkaddr(struct sockaddr_in * addr, const char * hostname, u_int16_t port);


int main(int argc, char * argv[])
{
	int server_socket, connect_socket; 
	socklen_t client_addr_len;
	int retcode, i; 
	struct sockaddr_in client_addr,		// NB: type cast later
	                   server_addr; 

	for (i = 0; i < MBOXSIZE; i++)      // inizializza la mailbox
		mailbox[i].full = 0;            // gli slot sono vuoti
	nmsg = 0;
	
	// apertura del socket del server 
	if ( (server_socket = socket(AF_INET, SOCK_STREAM, 0))
	     == -1)
		{perror("aprendo il socket del server"); exit(-1);} 

	// preparazione dell'indirizzo per il socket
	mkaddr(&server_addr, SERVERNAME, SERVERPORT);

	// pubblicazione del socket
	retcode = 
	bind(server_socket,
	     (struct sockaddr *) &server_addr, //NB: type cast
	     sizeof(server_addr)
	); 
	if(retcode == -1)
		{perror("pubblicando il socket"); exit(-1);}

	listen(server_socket, 1);

	printf("Server pronto (uscire con CTRL-C)\n");
	//si accettano connessioni: una alla volta

	// ciclo che accetta le connessioni
	client_addr_len = sizeof(client_addr); 
	while ((connect_socket = 		// diversa da server_socket!
	        accept(server_socket,
	               (struct sockaddr *) & client_addr, // cast
	               &client_addr_len)) != -1 ) {

		printf("Client from %s connected\n",
		       inet_ntoa(client_addr.sin_addr));

		// cycle: process data from accepted connection

		// codice specifico mailbox server
		retcode = read(connect_socket, &messg, sizeof(MESSAGE));
		// NB: in realta` ci vorrebbero piu` read(), vedi lucidi!!!
		if (retcode != sizeof(MESSAGE)) { // salvaguardia per read() singolo
			fprintf(stderr, "Error reading message\n");
			continue;
		}
		msgprocess(connect_socket);
		// fine codice specifico mailbox

		printf("Messaggi in mailbox: %d\n", nmsg);
		printf("\nFine messaggio, chiusura connessione\n");
		close(connect_socket);
	} // end while

	// qui si arriva per errore in accept
	printf("Fine ... \n"); 
	close(server_socket);
	exit(-1);
}


void msgprocess(int conn_sk)
/* analizza messaggio ricevuto da server (globale messg)
 * e interagisce con la mailbox di conseguenza.
 */
{
	int i;
	MESSAGE replyToClnt;

    switch (messg.type) {
    case SEND: 
    	if (nmsg == MBOXSIZE) {
    		replyToClnt.type = MBOXFULL; 
    		write(conn_sk, &replyToClnt, sizeof(replyToClnt)); 
    	} else {
    		for (i = 0; mailbox[i].full; i++) ; 
    		memcpy(&mailbox[i], &messg, sizeof(messg)); 
    		mailbox[i].full = 1;
    		nmsg++;  
			// invia risposta al cliente
    		replyToClnt.type = OK; 
    		strcpy(replyToClnt.src, messg.src);
		    strcpy(replyToClnt.dest, messg.dest);
		    strcpy(replyToClnt.info, "");  // non azzera campo in risposta
    		write(conn_sk, &replyToClnt, sizeof(replyToClnt)); 
    	} 
    	break; 
    case RECEIVE: 		// receiver messg.src wants first message from messg.dest to it
    	for (i = 0; i < MBOXSIZE; i++) {					// i is current message, 
    		if ( mailbox[i].full &&							// stored in mailbox[i]
    		     strcmp(mailbox[i].dest, messg.src) == 0 &&	// receiver was its destination 
    			 strcmp(mailbox[i].src, messg.dest) == 0) {	// intended sender was its source
    			mailbox[i].type = OK; 						// we shall send 
    			write(conn_sk, &mailbox[i], sizeof(mailbox[i])); // mailbox[i] to receiver
    			mailbox[i].full = 0; 							 // message was consumed
    			nmsg--;
    			break;	// get first message from intended sender to receiver
    		}			// then exit for
    	} 
    	if (i == MBOXSIZE) { // no message found from intended sender to receiver
    		replyToClnt.type = NOMSG;
    		write(conn_sk, &replyToClnt, sizeof(replyToClnt)); 
    	} 
    	break; 
    case RECEIVEANY:	// receiver messg.src wants first message from any nick to it
    	for (i = 0; i < MBOXSIZE; i++) {						 // i is current message,
    		if ( mailbox[i].full &&								 // stored in mailbox[i]
    		     strcmp(mailbox[i].dest, messg.src) == 0 ) {	 // receiver was its destination 
    			mailbox[i].type = OK; 							 // we shall send 
    			write(conn_sk, &mailbox[i], sizeof(mailbox[i])); // mailbox[i] to receiver 
    			mailbox[i].full = 0;							 // message was consumed
    			nmsg--;
    			break; // get first message to receiver, then exit for
    		}
    	}
    	if (i == MBOXSIZE) { // no message found to receiver
    		replyToClnt.type = NOMSG; 
    		write(conn_sk, &replyToClnt, sizeof(replyToClnt)); 
    	} 
    	break; 
    default: 
    	replyToClnt.type = ERROR; 
    	write(conn_sk, &replyToClnt, sizeof(replyToClnt)); 
    } // end switch
}
