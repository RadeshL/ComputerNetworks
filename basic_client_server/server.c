#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

int main(){
	int s = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in a = {0};
	a.sin_family = AF_INET;
	a.sin_port = htons(8080);
	a.sin_addr.s_addr = INADDR_ANY;
	printf("Waiting for client....\n");
	bind(s, (void *)&a, sizeof(a));
	listen(s,5);
	
	int c = accept(s,NULL,NULL);
	
	char msg[100];
	
	int n = recv(c,msg,sizeof(msg) - 1, 0);
	
	if(n>0){
		msg[n] = '\0';
		printf("client says %s\n", msg);
	}
	close(c);
	close(s);
}
