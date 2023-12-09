/* mkaddr.c */

#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <string.h>

int mkaddr(struct sockaddr_in * addr, const char * hostname_or_ip, u_int16_t port)
{
    struct hostent * host;
    size_t nbytes;

    memset(addr,0,sizeof(*addr));    // si azzera la struct puntata da ·addr
    addr->sin_family = AF_INET;      // member ·sin_family is always ·AF_INET
    addr->sin_port = htons(port);    // ·port argument assumed in host order

    // query DNS, get ·hostent with host's IP
    if ((host = gethostbyname(hostname_or_ip)) == NULL) {
        herror("querying");
        return(-1);                 // process calling mkaddr() should test
    }
                                     // memcpy() copies byte-by-byte to
    memcpy(&(addr->sin_addr),        // socket's address (addr->sin_addr)
           host->h_addr_list[0],     // host's first (index 0) IP address
           nbytes = host->h_length); // host->h_length is address length
    return((int) nbytes);            // i.e. n. of bytes to be copied
}
