#define SERVERPORT 3002
#define SERVERNAME "localhost"

#define MAXBUF 2048 
#define MAXINFOLEN 1024 
#define MAXLEN 18	// max length of nickname

#define MBOXSIZE 3

typedef enum {
	SEND,       // manda un messaggio
	RECEIVE, 	// receive one message from given nick
	RECEIVEANY, // receive one message from any nick
	NOMSG,		// possible reply to RECEIVE/RECEIVEANY
	MBOXFULL, 	// reply to SEND
	ERROR, 		// reply to unexpected message
	OK			// possible reply
} MESG_T; 

typedef short int BOOL;

typedef struct {
	MESG_T type; 
	char src[MAXLEN];    // nick del mittente
	char dest[MAXLEN];   // nick del destinatario
	char info[MAXINFOLEN];   // serve certamente per SEND
	BOOL full;               // ma non p.es. per ERROR o NOMSG
} MESSAGE;                   // sarebbe meglio una union e formati
                             // multipli per i messaggi


