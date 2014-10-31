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
	unsigned long long int byte[256];//number of each byte
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
			byte[rand]++;//increment correct byte
		}
	}
	printf("\n\nChecked %uKB ", size);//size of file
	printf("(%u Bits)\n", total);//size in bits

	//number of bits
	printf("\nResult:\n\nnumber of bits:\n%u zeros\n", zeros);//display result. number of zeros
	printf("%u ones\n", ones);//number of ones
	printf("%.5f%% binary difference\n\n", (float)abs(ones - zeros) * 100 / (total));//zero and one diference


	//calculate number of bytes
	unsigned char least = 0;//least occuring byte
	unsigned char most = 0;//most occuring byte
	for (i = 0; i < 256; i++){//for each thing
		if (byte[i] < byte[least]){//if i is less the least
			least = i;//set least to i
		}
		else if (byte[i] > byte[most]){//if i is more then most
			most = i;//set most to i
		}
	}
	unsigned long long int ByteTotal = total / 8 / 128;//number of byte times 2
	//number of bytes
	printf("number of bytes:\nmost occuring byte: %u: ", most);//display what is most occuring byte
	printf("%u times", byte[most]);//display number of times most occuring byte shows up.
	printf("\nleast occuring byte: %u: ", least);//display what is least occuring byte
	printf("%u times\n", byte[least]);//display number of times least occuring byte shows up.
	printf("%.5f%% difference\n\n", (float)abs(byte[least] - byte[most]) * 100 / ByteTotal);//most and least occuring byte diference


	//time taken
	printf("%.1f seconds\n", difftime(time(NULL), start));//display time taken at end
}

void CRand(const unsigned long int size){//run test for c random function. takes in size in kilobytes.
	srand((int)time(NULL) + (int)clock());//seed with time
	unsigned long int i, j, k;//counters i, j and k
	unsigned long long int zeros = 0;
	unsigned long long int ones = 0;//number of zeros and ones
	unsigned long long int total = 0;//total bits
	unsigned long long int byte[256];//number of each byte
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
			byte[rand]++;//increment correct byte
		}
	}
	printf("\n\nChecked %uKB ", size);//size of file
	printf("(%u Bits)\n", total);//size in bits

	//number of bits
	printf("\nResult:\n\nnumber of bits:\n%u zeros\n", zeros);//display result. number of zeros
	printf("%u ones\n", ones);//number of ones
	printf("%.5f%% binary difference\n\n", (float)abs(ones - zeros) * 100 / (total));//zero and one diference


	//calculate number of bytes
	unsigned char least = 0;//least occuring byte
	unsigned char most = 0;//most occuring byte
	for (i = 0; i < 256; i++){//for each thing
		if (byte[i] < byte[least]){//if i is less the least
			least = i;//set least to i
		}
		else if (byte[i] > byte[most]){//if i is more then most
			most = i;//set most to i
		}
	}
	unsigned long long int ByteTotal = total / 8 / 128;//number of byte times 2
	//number of bytes
	printf("number of bytes:\nmost occuring byte: %u: ", most);//display what is most occuring byte
	printf("%u times", byte[most]);//display number of times most occuring byte shows up.
	printf("\nleast occuring byte: %u: ", least);//display what is least occuring byte
	printf("%u times\n", byte[least]);//display number of times least occuring byte shows up.
	printf("%.5f%% difference\n\n", (float)abs(byte[least] - byte[most]) * 100 / ByteTotal);//most and least occuring byte diference


	//time taken
	printf("%.1f seconds\n", difftime(time(NULL), start));//display time taken at end
}

