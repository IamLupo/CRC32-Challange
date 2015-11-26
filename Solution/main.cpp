#include <stdio.h>

#include "Crc32.h"

/*
	People need to find the crc32 in the encrypted zip files and decrypt them:
	Command: zipinfo -v 0.zip
*/
const int collected_crc32[26] = {
	0xa36bb2ae, 0x6451acb6,	0x0fc5e367, 0xb59d53ea, 0x5a392392, 0xe54dcc37,
	0xb1048836, 0x4a25de23, 0x8cee02d1, 0x90a3dd79, 0x1c160e74, 0xc49dd987,
	0xfb38cf63, 0x6e03dc3c, 0x21ac9af5, 0xcad30754, 0x6c5861a0, 0x91bd70ca,
	0x95e42995, 0xe95ddb8b, 0x347296ea, 0x57abe1d8, 0xe54dcc37, 0xdc2d0899,
	0xd34a0a23, 0x4d76cfce
};

int main(void) {
	int i;
	Crc32 crc;
	UInt8 result[4];
	
	for(i = 0; i < 26; i++) {
		printf("Posseble output of %d.txt:\n", i);
		crc.set(0x0);
		crc.findReverseAscii_bruteforce(collected_crc32[i], result, 0, 0);
	}
	
    return 0;
}
