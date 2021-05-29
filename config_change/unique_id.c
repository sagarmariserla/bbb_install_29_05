#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include <sys/stat.h>
#include<unistd.h>
#include<string.h>

int main()
{
        int fd1,fd2,fd3,ret, i = 0;
        char buf1[12];
	char buf2[316];
	char buf3[1000];
	int read_in;
	int size;
	char htn[30]="medha_";
        fd1 = open("/proc/cpuinfo" , O_RDWR);
        if(fd1 < 0)
        {
                printf("failed to open cpuinfo file\n");
                return 0;
        }
	 size = lseek(fd1,316, SEEK_CUR);
	ret = read(fd1,buf1,12);
        if(ret == 0)
        {
                printf("there is no data inside the file\n");
                return 0;
        }	
       	buf1[ret] = '\0';
	strcat(htn,buf1);


       // buf1[ret] = '\0';
       // printf("%s", htn);


	fd2=open("/medha_gateway/config_change/mosquitto.conf1",O_RDWR);
	if(fd2< 0)
        {
                printf("failed to open 1 file\n");
                return 0;
        }
	 fd3=open("/etc/mosquitto/mosquitto.conf",O_CREAT|O_RDWR|O_TRUNC,0666);   //path:/etc/mosquitto/
	if(fd3< 0)
        {
                printf("failed to open 2 file\n");
                return 0;
        }
	while((read_in=read(fd2,buf3,1000))>0)
	{
		write(fd3,buf3,read_in);
	}
/*	//char buf4[20]="sagar";
	lseek(fd3,0,SEEK_SET);
	lseek(fd3,572,SEEK_CUR);
	ret=write(fd3,buf1,strlen(buf1));
	 if(ret == 0)
        {
                printf("there is no data inside the file\n");
                return 0;
        }
	// buf4[ret]='\0';
	 //printf("%s\n",buf4);

	memset(buf2, 0, sizeof(buf2));
 	memset(buf3, 0, sizeof(buf2));
	close(fd2);
	close(fd3);

*/	 fd2=open("/medha_gateway/config_change/avahi-daemon.conf1",O_RDWR);
        if(fd2< 0)
        {
                printf("failed to open 3 file\n");
                return 0;
        }
        fd3=open("/etc/avahi/avahi-daemon.conf",O_CREAT|O_RDWR|O_TRUNC,0666); //path:/etc/avahi/
        if(fd3< 0)
        {
                printf("failed to open 4 file\n");
                return 0;
        }
        while((read_in=read(fd2,buf3,1000))>0)
        {
                write(fd3,buf3,read_in);
        }
        //char buf4[20]="sagar";
        lseek(fd3,0,SEEK_SET);
        lseek(fd3,824,SEEK_CUR);
        ret=write(fd3,htn,strlen(htn));
         if(ret == 0)
        {
                printf("there is no data inside the file\n");
                return 0;
        }
        // buf4[ret]='\0';
        // printf("%s\n",buf4);

	 close(fd1);
	 close(fd2);
	 close(fd3);
}

