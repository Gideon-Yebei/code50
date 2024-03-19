#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for correct usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Open input file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file.\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int file_count = 0;
    FILE *outfile = NULL;
    char filename[8];

    // Search for JPEG signatures
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // Check for JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If a JPEG file is already open, close it
            if (outfile != NULL)
            {
                fclose(outfile);
            }

            // Create new JPEG file
            sprintf(filename, "%03i.jpg", file_count);
            outfile = fopen(filename, "w");
            if (outfile == NULL)
            {
                fclose(file);
                fprintf(stderr, "Could not create JPEG file.\n");
                return 1;
            }

            file_count++;
        }

        // Write to JPEG file if one is open
        if (outfile != NULL)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, outfile);
        }
    }

    // Close remaining files
    if (outfile != NULL)
    {
        fclose(outfile);
    }

    // Close input file
    fclose(file);

    return 0;
}
