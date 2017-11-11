#include <string.h>
#include <stdint.h>
#include <stdio.h>

void *read_image(char *);

int main(int argc, char *argv[]){

	int32_t width;
	int32_t height;
	char *new = (char *) read_image(argv[1]);
	memcpy(&width, new +18, sizeof(width));
	memcpy(&height, new+22, sizeof(height));
	printf("BMP image width: %d \n", width);
	printf("BMP image height: %d \n", height);
	
	
	

return 0;
}
