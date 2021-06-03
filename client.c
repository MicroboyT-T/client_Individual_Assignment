//Assignment Individual, Muaz
//Client Code

#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAXLINE 1024

int main (int argc, char **argv) {

    int connfd;                  /* a socket descriptor */
    struct sockaddr_in servaddr; /* a server address structure */
    char buf[MAXLINE];           /* buffer */
    int n;                       /* the number of byte read */

    connfd = socket (AF_INET, SOCK_STREAM, 0); /* make a socket */
    
     bzero (&servaddr, sizeof (servaddr)); /* initializes servaddr to zero bytes>

    servaddr.sin_family = AF_INET; /* IPv4 mode */
    servaddr.sin_port = htons (atoi (argv[2])); /* port number */

    /* convert human readable string to binary structure */
    inet_pton (AF_INET, argv[1], &servaddr.sin_addr.s_addr);

    /* connect the server, referring to the information of servaddr */
    connect (connfd, (struct sockaddr *) &servaddr, sizeof (servaddr));

    while ( (n = read (connfd, buf, MAXLINE)) > 0) {
        buf[n] = 0; /* null terminate */
        fputs (buf, stdout);
        close(connfd);
        exit(0);
    }

    close(connfd);
    exit (0);
}
