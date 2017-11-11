#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>

const char *filename(const char *);
void *read_image(char *);
uint32_t size(const char *file);

int main(int argc, char *argv[]){

	int32_t width;
	int32_t height;
	const char *file = argv[1];
	char *new = (char *) read_image(file);

	if(file == NULL){
		printf("Unable to open file\n");
		return 0;
	}
	if (strcmp(filename(file),"png")){
		printf("Unable to parse file\n");
		return 0;
	}
	memcpy(&width, new+16, sizeof(width));
	memcpy(&height, new+20, sizeof(height));
	printf("PNG image height: %d\n", ntohl(height));
	printf("PNG image width: %d\n", ntohl(width));
	printf("PNG file size: %d\n", size(file));
	
return 0;
}
const char *filename(const char *file){
	const char *png = strrchr(file, ".");
	if(!png || png == file){
		return "";
	}
	
	return png+1;
}
uint32_t size(const char *file){
	FILE *f = fopen(file, "r");
	fseek(f, 0, SEEK_END);
	uint32_t size = ftell(f);
	fseek(f, 0, SEEK_SET);
	fclose(f);
return size;
}
