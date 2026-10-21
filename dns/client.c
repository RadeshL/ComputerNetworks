#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
	int s = socket(AF_INET,SOCK_DGRAM,0);
	
	struct sockaddr_in a = {0},c;
	
	a.sin_family = AF_INET;
	a.sin_port = htons(8080);
	inet_pton(AF_INET,"127.0.0.1",&a.sin_addr);
	
	
	char msg[100];
	
	printf("Enter the domain name: ");
	fgets(msg,sizeof(msg),stdin);
	
	socklen_t len = sizeof(c);
	
	sendto(s,msg,strlen(msg),0,(void *)&a,sizeof(a));
	
	char ip[100];
	
	int n = recvfrom(s,ip,99,0,NULL,NULL);
	ip[n] = '\0';
	
	if(n > 0){
		printf("ip: %s",ip);
	}
	else{
		printf("Domain not found");
	}
}
