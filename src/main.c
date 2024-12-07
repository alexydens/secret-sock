/* Includes */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/* Port chosen */
#define PORT 5555

/* Entry point */
int main(void) {
  /* Create a socket */
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    fprintf(stderr, "ERROR: Failed to create socket: %s\n", strerror(errno));
  }

  /* Bind the socket */
  struct sockaddr_in addr = {0};
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    fprintf(stderr, "ERROR: Failed to bind socket: %s\n", strerror(errno));
  }
  
  /* Listen with the socket */
  if (listen(sock, 1) < 0) {
    fprintf(stderr, "ERROR: Failed to listen on socket: %s\n", strerror(errno));
  }

  /* Accept the first connection */
  struct sockaddr_in addr_in = {0};
  socklen_t addr_in_len = sizeof(addr_in);
  int client = accept(sock, (struct sockaddr *)&addr_in, &addr_in_len);
  if (client < 0) {
    fprintf(stderr, "ERROR: Failed to accept connection: %s\n", strerror(errno));
  }
  printf("INFO: Accepted connection from %s\n", inet_ntoa(addr_in.sin_addr));

  /* Send a message */
  const char *message = "Hello\n";
  if (send(client, message, strlen(message), 0) < 0) {
    fprintf(stderr, "ERROR: Failed to send message: %s\n", strerror(errno));
  }

  /* Close the socket */
  if (close(sock) < 0) {
    fprintf(stderr, "ERROR: Failed to close socket: %s\n", strerror(errno));
  }

  /* Return */
  return EXIT_SUCCESS;
}
