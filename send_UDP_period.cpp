#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<chrono>
#include<string>

int main(){
    int sock;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(12345);
    addr.sin_addr.s_addr = inet_addr("172.16.93.91");

    std::chrono::system_clock::time_point start, end;

    for(int i=1; i<=100; i++){
        start = std::chrono::system_clock::now();
        //end = std::chrono::system_clock::now();
        while(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-start).count()<20){};


        std::string s = std::to_string(i);
        const char* msg = s.data();

        sendto(sock, msg, 5, 0, (struct sockaddr *)&addr, sizeof(addr));
    }
    close(sock);
 return 0;
}

