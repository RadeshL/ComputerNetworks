#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main(){
    int s = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in a = {0};
    a.sin_family = AF_INET;
    a.sin_port = htons(8000);
    inet_pton(AF_INET,"127.0.0.1",&a.sin_addr);
    connect(s,(void *)&a,sizeof(a));

    char request[] = "GET /index.html HTTP/1.0\r\nHost : localhost\r\n\r\n";

    send(s,request,strlen(request),0);
    char buffer[1024];
    int n;
    while((n = recv(s,buffer,sizeof(buffer),0)) > 0 ){
    	buffer[n] = '\0';
        printf("%s\n",buffer);
    }

    close(s);
}
