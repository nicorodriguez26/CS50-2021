// CS50 2021 - Introduction to Computer Science.
// Week 4 - Problem Set 4 - Language: C
// Recover - recover.c
// Nicolas Rodriguez Aldegheri
// 21/09/21


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error ocurred opening the file.\n");
        return 1;
    }

    typedef uint8_t BYTE;
    BYTE buffer[BLOCK_SIZE];

    //Now we have a valid file to read
    size_t bytesR;
    bool isFirst = false;
    FILE *currentFile = NULL;
    char currentFilename[100];
    int currentFilenumber = 0;
    bool foundjpeg = false;

    //Open memory card
    while (true)
    {
        //Repeat until end of card
        //Read 512 bytes into buffer
        bytesR = fread(buffer, sizeof(BYTE), BLOCK_SIZE, file);
        if (bytesR == 0)
        {
            break;
        }
        //If start of new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            foundjpeg = true;
            //If first jpeg
            //mark first jpeg
            if (!isFirst)
            {
                isFirst = true;
            }
            else
            {
                //close current file being written to open new file
                fclose(currentFile);
            }
            sprintf(currentFilename, "%03i.jpg", currentFilenumber);
            currentFile = fopen(currentFilename, "w");
            fwrite(buffer, sizeof(BYTE), bytesR, currentFile);
            currentFilenumber++;
        }
        else
        {
            //If already found jpeg, keep writing to it
            if (foundjpeg)
            {
                fwrite(buffer, sizeof(BYTE), bytesR, currentFile);
            }
        }
    }
    fclose(file);
    fclose(currentFile);
    return 0;
}
