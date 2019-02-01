#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int fd,i,j;
  
  char line[20];
  int rgb[3];

  fd = open("image.ppm",O_CREAT| O_WRONLY| O_TRUNC, 0644);
  snprintf(line, sizeof(line), "P3 500 500 255 \n");
  write(fd,line,strlen(line));

  for(i = 0; i < 500; i++){
    for(j = 0; j < 500; j++){
      rgb[0] = i%255;
      rgb[1] = j%255;
      rgb[2] = (i+j)%255;
      
      sprintf(line, "%d %d %d ",rgb[0],rgb[1],rgb[2]);
      write(fd,line,strlen(line));
    }
  }
  
  close(fd);
}
