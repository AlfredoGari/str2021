
#include "socket.h"
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080

int socket_init() {
    int server_fd;
    int opt = 1;
    struct sockaddr_in address;
    // sockaddr_in = Informacion de la dir. socket
    int addrlen = sizeof(address);
    // Creating socket file descriptor 
    // el primer paso es llamar socket
    //le pasamos la constante la constante AF_INET
    //SOCK STREAM usaremos TCP
    // el 0 es el tamaño del buffer
    
    
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
		perror("Socket failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	// Forcefully attaching socket to the port
	//El siguiente paso es "set socket options" es una variante del ioctl que usamos para el reloj
    //aca pasamos el file descriptor y pasamos algunos datos: SO REUSEADDR (REUTILIZAR LA DIRECCION DE IP)
    // SO_REUSEPORT (REUTILIZAR PUERTO INTERNO)
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
												&opt, sizeof(opt))) {
		perror("Setsockopt failed"); 
		exit(EXIT_FAILURE); 
	} 
	// AF_INET = IPV4
	address->sin_family = AF_INET; 
	address->sin_addr.s_addr = INADDR_ANY; 
	address->sin_port = htons( PORT ); 
	
	// Forcefully attaching socket to the port
    //El socalo que configuramos arriba, lo vamos activar. si salimos del bind, significa que nuestro socalo funciona
	if (bind(server_fd, (struct sockaddr *)&address, 
								sizeof(address))<0){ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	}  
	//si funciona el bind podemos llamar al listen. y tenemos 3 conexiones simultaneas
    if (listen(server_fd, 3) < 0) { 
		perror("listen"); 
		exit(EXIT_FAILURE); 
	}
	
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
	
    return server_fd;   
}


