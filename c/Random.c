#include "Random.h"
/*Generate random number*/

unsigned char GetCRandom(){//get c random character
		unsigned int r = 0;//random character
		do{//draw random number until it is in correct range
			r = rand();//get next random number
		} while (r > 256);//range is 0<=r<=256
		return (unsigned char)r;//return the random character
}

unsigned char GetFileRandom(){//get file random character
	unsigned char memory;
	memory = fgetc(random);
	return memory;
}


void File(const unsigned long int size){//run test for file. Takes in size in kilobytes.
	unsigned long int i, j, k;//counters i, j and k
	unsigned long long int zeros = 0;
	unsigned long long int ones = 0;//number of zeros and ones
	unsigned long long int total = 0;//total bits
	time_t start = time(NULL);
	for (i = 0; i < 1024; i++){//1 kb
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");//clear
		printf("%.1f%% finished", (float)(100 * i) / 1024);//display percentage finished
		for (j = 0; j < size; j++){//number of kilobyte
			unsigned char rand = GetFileRandom();//get random char
			for (k = 0; k < 8; k++){//for each bit in char
				if ((rand >> k) & 1){//if it was one
					ones++;//add one to ones
				}
				else{//if it was zero
					zeros++;//add one to zeros
				}
				total++;//increment total
			}
		}
	}
	printf("\n\nChecked %uKB ", size);//size of file
	printf("(%u Bits)\n", total);//size in bits
	printf("\nResult:\n\nnumber of bits:\n%u zeros\n", zeros);//display result. number of zeros
	printf("%u ones\n", ones);//number of ones
	printf("%.5f%% binary difference\n\n", (float)abs(ones - zeros) * 100 / (total));//zero and one diference
	printf("%.1f seconds\n", difftime(time(NULL), start));//display time taken at end
}

void CRand(const unsigned long int size){//run test for c random function. takes in size in kilobytes.
	unsigned long int i, j, k;//counters i, j and k
	unsigned long long int zeros = 0;
	unsigned long long int ones = 0;//number of zeros and ones
	unsigned long long int total = 0;//total bits
	time_t start = time(NULL);
	for (i = 0; i < 1024; i++){//1 kb
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");//clear
		printf("%.1f%% finished", (float)(100 * i) / 1024);//display percentage finished
		for (j = 0; j < size; j++){//number of kilobyte
			unsigned char rand = GetCRandom();//get random char
			for (k = 0; k < 8; k++){//for each bit in char
				if ((rand >> k) & 1){//if it was one
					ones++;//add one to ones
				}
				else{//if it was zero
					zeros++;//add one to zeros
				}
				total++;//increment total
			}
		}
	}
	printf("\n\nChecked %uKB ", size);//size of file
	printf("(%u Bits)\n", total);//size in bits
	printf("\nResult:\n\nnumber of bits:\n%u zeros\n", zeros);//display result. number of zeros
	printf("%u ones\n", ones);//number of ones
	printf("%.5f%% binary difference\n\n", (float)abs(ones - zeros) * 100 / (total));//zero and one diference
	printf("%.1f seconds\n", difftime(time(NULL), start));//display time taken at end
}

