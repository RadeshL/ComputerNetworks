#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

struct dict {
	char key[50];
	char value[50];
};

int main(){
	int s = socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in a = {0},c;
	
	a.sin_family = AF_INET;
	a.sin_port = htons(8080);
	a.sin_addr.s_addr = INADDR_ANY;
	
	struct dict d[3] = {{"google.com","1.2.3.4"}};
	
	int flag = 0;

	printf("Waiting for client... \n");

	bind(s,(void *)&a,sizeof(a));

	socklen_t len = sizeof(c);

	char site[50];
	
	int n = recvfrom(s,site,99,0,(void *)&c,&len);	
	site[n] = -1;
	for(int i = 0; i < 1; i++){
		if(strcmp(d[i].key,site)== 0){
			flag = 1;
			sendto(s,d[i].value,strlen(d[i].value),0,(void *)&c,len);			
		}
	}
	
	if(flag == 0){
		printf("Invalid domain");
	}
	close(s);
	return 0;
}
