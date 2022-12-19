#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main ()
{
	int ans, key;
	char in[260];
	char answer;
	while (1){
		printf("\n------Encryption & Decryption Program----------\n\n\n");
	printf("  Press 1 to Encrypt file.\n  Press 2 to Decrypt file.\n");
	scanf("%d", &ans);
	printf(" Enter File Name -\n");
	scanf("%s", &in);
	printf(" Enter Key -\n");
	scanf("%d", &key);
	if (ans == 1)
	{
		char c;
		char a;
		FILE *fin; //file pointers/stream 
		FILE *fout;
		fin = fopen(in, "rb"); // it reads the file in binary mode.
		strcpy(in, "Encrypted_file");//it creates a file without extenstion.
		fout = fopen(in, "wb");
		while (!feof(fin))  
		{
			c = fgetc(fin); 
			int temp = (c + key);
			fputc((char)temp, fout);
		}
		fclose(fin);
		fclose(fout);
		printf(" \nYour File have been Encrypted.\n");
	}
	else if (ans == 2)
	{
		char c;
		FILE *fin;
		FILE *fout;
		fin = fopen(in, "rb");
		strcpy(in, "Decrypted_file");
		fout = fopen(in, "wb");
		while (!feof(fin))
		{
			c = fgetc(fin);
			int temp = (c - key);
			fputc((char)temp, fout);
		}
		fclose(fin);
		fclose(fout);
		remove("Encrypted_file");
		printf(" \nYour File have been Sucessfully Decrypted.\n");
	}
	printf("  \nDo you want to go back to menu? Y or N:\n", answer);
    scanf("%s", &answer);
  		if (answer == 'y'){
  			continue;
    	}
    	else{
    		exit(0);
		}
		return 0;
}
	getch();
}

