#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
	int s = socket(AF_INET,SOCK_STREAM,0);
	
	struct sockaddr_in a = {0};
	a.sin_family = AF_INET;
	a.sin_port = htons(8080);
	inet_pton(AF_INET,"127.0.0.1",&a.sin_addr);
	connect(s,(void *)&a, sizeof(a));
	
	char msg[100];
	printf("Enter your message: ");
	fgets(msg,sizeof(msg),stdin);
	
	send(s,msg,strlen(msg),0);
	
	close(s);
}
