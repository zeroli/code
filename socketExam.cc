#include <iostream>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

using namespace std;
#define MAXHOSTNAME 256

int main()
{
	int socketHandle;
	if ((socketHandle=socket(AF_INET, SOCK_STREAM, IPPROTO_IP))<0) 
	{
		close(socketHandle);
		exit(EXIT_FAILURE);
	}
	struct sockaddr_in socketInfo;
	char sysHost[MAXHOSTNAME+1];
	struct hostNamePtr* hPtr;
	int portNumber = 8080;
	
	bzero(&socketInfo, sizeof(sockeaddr_in);
	
	gethostname(sysHost, MAXHOSTNAME);
	if ((hPtr=gethostbyname(sysHost))==NULL) {
		cerr << "System hostname misconfigured." << endl;
		exit(EXIT_FAILURE);
	}
	socketInfo.sin_family = AF_INET;
	socketInfo.sin_addr.s_addr = htonl(INADDR_ANY);
	socketInfo.sin_port = htons(portNumber);
	if (bind(socketHandle, (struct sockeaddr*)&socketInfo, sizeof(struct sockaddr_in))<0) {
		close(socketHandle);
		perror("bind");
		exit(EXIT_FAILURE);
	}
	listen(socketHandle, 1);
	int socketConnection;	// new connected socket, don't care client socket
	if ((socketConnection=accept(socketHandle, NULL, NULL))<0) {
		close(socketHandle);
		exit(EXIT_FAILURE);
	}
	close(socketHandle);		// listen socket closed

	int rc = 0;
	char buf[512];
	rc = recv(socketConnection, buf, 512, 0);
	buf[rc] = (char)NULL;
	cout << "Number of bytes read: " << rc << endl;
	cout << "Received: " << buf << endl;
	
	return 0;
}

