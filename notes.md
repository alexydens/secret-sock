# From server's perspective
1. socket() to create a socket.
2. bind() to give it an address and port.
3. listen() to listen for incoming connections.
4. accept() to accept incoming connections.
 - if a client has tried after listen, it will accept that connection.
 - otherwise, it will block until a client connects.
5. read() to read data from the socket.
6. write() to write data to the socket.
7. close() to close the socket.
# From client's perspective
1. socket() to create a socket.
2. connect() to connect to a server.
3. read() to read data from the socket.
4. write() to write data to the socket.
5. close() to close the socket.
