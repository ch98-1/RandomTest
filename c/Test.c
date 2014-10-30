#include "Test.h"

int main(int argc, char *argv[]){
	if (argc >= 2){
		if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "Help") == 0 ||
			strcmp(argv[1], "-help") == 0 || strcmp(argv[1], "-Help") == 0 ||
			strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "--Help") == 0 ||
			strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-H") == 0 ||
			strcmp(argv[1], "--h") == 0 || strcmp(argv[1], "--H") == 0){//for anything that looks like a help command
			PrintHelp();
			return 0;//no error
		}
		if (argc == 3){
			if (strcmp(argv[1], "-f") == 0){//if it is file mode
				random = fopen(argv[2], "rb");//open file
				unsigned long int size = 0;
				while (size < 16777216 && !feof(random)){//16GB max
					char mem[1024];
					fread(mem, 1, 1024, random);
					size++;
				}//get size of file
				void rewind(random);//set it to start
				File(size);//run the test
				return 0;//no error
			}
			else if (strcmp(argv[1], "-c") == 0){//if it is rand() mode
				unsigned long int size = atoi(argv[2]);//get size of the test
				CRand(size);//run the test
				return 0;//no error
			}
			else{
				PrintHelp();
				return 0;//no error
			}
		}
		else{
			PrintHelp();
			return 0;//no error
		}
	}
	else{
		PrintHelp();
		return 0;//no error
	}
}



//print out
/*Usage:
Command <options> <filename/number>

options: 
-f read from file
-c read from c rand() function

filename/number:
number of Kilobytes to process or filename of file to read (up to 2^32)*/
void PrintHelp(){
	printf("Usage:\nCommand <option> <filename/number>\n\n");
	printf("options:\n-f read from file\n-c read from c rand() function\n\n");
	printf("filename/number:\nnumber of Kilobytes to process or filename of file to read (up to 2^32)");
}