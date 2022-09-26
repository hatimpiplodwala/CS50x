#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./recover rawfile\n");
        return 1;
    }

    char *infilename = argv[1];

    FILE *inFile = fopen(infilename, "r");

    if (inFile == NULL)
    {
        printf("Could not open %s\n", infilename);
        return 1;
    }

    BYTE buffer[BLOCK_SIZE + 1];
    int filecount = 0;
    char outfilename[8];
    FILE *outFile = NULL;

    while (fread(buffer, 1, BLOCK_SIZE, inFile))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            if (filecount == 0)
            {
                sprintf(outfilename, "%03i.jpg", filecount);
                outFile = fopen(outfilename, "w");
                fwrite(&buffer, 1, BLOCK_SIZE, outFile);
                filecount++;
            }
            else
            {
                fclose(outFile);
                sprintf(outfilename, "%03i.jpg", filecount);
                outFile = fopen(outfilename, "w");
                fwrite(&buffer, 1, BLOCK_SIZE, outFile);
                filecount++;
            }
        }
        else
        {
            if (outFile == NULL)
            {
                continue;
            }
            else
            {
                fwrite(&buffer, 1, BLOCK_SIZE, outFile);
            }
        }
    }

    fclose(inFile);
    fclose(outFile);

    return 0;
}