// dnslookup.c
// Martina Karaskova 2478724k

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

main(int argc, char *argv[]) {
  int i; 
  char str[INET6_ADDRSTRLEN];
  struct addrinfo hints, *ai, *ai0;
  struct sockaddr_in *ip_access_4;
  struct sockaddr_in6 *ip_access_6;

  if (argc != 2) {
    printf("Usage: %s <hostname>\n", argv[0]);
    return 1;
  }

  // Translates a doman name into an IP address
  memset(&hints, 0, sizeof(hints));
  hints.ai_family    = AF_UNSPEC;
  hints.ai_socktype  = SOCK_STREAM;
  if ((i = getaddrinfo(argv[1], "domain", &hints, &ai0)) != 0) {
    printf("Unable to look up IP address: %s \n", gai_strerror(i));
    return 2;
  }

  for (ai = ai0; ai != NULL; ai = ai->ai_next) {
    ip_access_4 = (struct sockaddr_in *) ai->ai_addr;
    printf("%s IPv4: %s \n", argv[1], inet_ntoa( ip_access_4->sin_addr));
    ip_access_6 = (struct sockaddr_in6 *) ai->ai_addr;
    printf("%s IPv6: %s \n", argv[1], inet_ntop(AF_INET6, &(ip_access_6->sin6_addr), str, INET6_ADDRSTRLEN));
    }

  freeaddrinfo(ai);
}

