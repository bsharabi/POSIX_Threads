#include <string.h>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#define BUFFSIZE 1024
char w[BUFFSIZE];
char r[BUFFSIZE];
int listenFd;
using namespace std;
void red()
{
    printf("\033[1;31m");
}
void yellow()
{
    printf("\033[1;33m");
}
void sig_handler(int signum)
{
    switch (signum)
    {
    case SIGTSTP:
        red();
        printf("I'm the first signal..\n");
    case SIGINT:
        yellow();
        printf("I'm the second signal, trying to divide\n");
    default:
        close(listenFd);
        exit(1);
    }
}
int main(int argc, char *argv[])
{

    signal(SIGINT, sig_handler);
    signal(SIGTSTP, sig_handler);
    int portNo;
    bool loop = false;
    struct sockaddr_in svrAdd;
    struct hostent *server;

    // if (argc < 2)
    // {
    //     cerr << "Syntam : ./server <port>" << endl;
    //     return 0;
    // }

    // portNo = atoi(argv[1]);
    portNo = htons(3000);

    if ((portNo > 65535) || (portNo < 2000))
    {
        cerr << "Please enter a port number between 2000 - 65535" << endl;
        return 0;
    }

    listenFd = socket(AF_INET, SOCK_STREAM, 0);

    if (listenFd < 0)
    {
        cerr << "Cannot open socket" << endl;
        return 0;
    }

    server = gethostbyname("localhost");

    if (server == NULL)
    {
        cerr << "Host does not exist" << endl;
        return 0;
    }

    bzero((char *)&svrAdd, sizeof(svrAdd));
    svrAdd.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&svrAdd.sin_addr.s_addr, server->h_length);

    svrAdd.sin_port = htons(portNo);

    int checker = connect(listenFd, (struct sockaddr *)&svrAdd, sizeof(svrAdd));

    if (checker < 0)
    {
        cerr << "Cannot connect!" << endl;
        return 0;
    }
    for (;;)
    {
        cout << "Enter stuff: ";
        bzero(w, BUFFSIZE);
        cin.getline(w, BUFFSIZE);
        write(listenFd, w, strlen(w));
        bzero(r, BUFFSIZE);
        read(listenFd, r, BUFFSIZE);
        puts(r);
        string exit(w);
        if (exit == "exit")
        {
            close(listenFd);
            return 1;
        }
    }
}