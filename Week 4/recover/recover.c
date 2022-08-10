#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for proper Usage
    if (argc != 2)
    {
        printf("Usage error! \n Correct Usage:  $ ./recover [memory]\n");
        return 1;
    }

    // Open file

    FILE *input = fopen(argv[1], "r");
    if (!input)
    {
        printf("Could not open file\n");
        return 2;
    }

    // Declare outfile pointer
    FILE *output_img = NULL;

    // JPEGs are stored in arrays of 512bytes so create that array
    BYTE buffer[512];

    // Declare a string to hold the file names
    char filename[8];

    // Declare a variable to Count the amount of JPEGs found
    int counter = 0;

    // Read the memory until the end of the file
    while (fread(buffer, sizeof(buffer), 1, input) == 1)
    {
        // checks if start of img in buffer
        // Note that the programme never comes back to this block unless it detects a new image if it doesn't detect a new image
        // it just goes to the else if statment and writes the next block of 512 bytes into the current image
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if start of img and first image i.e. counter ==0
            // then begins writing a new image
            if (counter == 0)
            {
                // create a new file
                sprintf(filename,  "%03i.jpg", counter++); // counter++ here assigns counter's current value to the sprintf function and then increments it (post increment)

                // Open the newly created file with the intention to write to it
                output_img = fopen(filename, "w");

                // Write to the newly opened file
                fwrite(&buffer, sizeof(buffer), 1, output_img);
            }


            // if start of img but not first image then
            // closes the image and begins writing new image
            else if (counter > 0)
            {
                // close the current image
                fclose(output_img);

                // create a new file
                sprintf(filename, "%03i.jpg", counter++); // counter++ here assigns counter's current value to the sprintf function and then increments it (post increment)

                // Open the file created
                output_img = fopen(filename, "w");

                // write to the newly opened file
                fwrite(&buffer, sizeof(buffer), 1, output_img);

            }
        }



        // if not start of new img
        // then it keeps on writing the image
        else if (counter > 0)
        {
            fwrite(&buffer, sizeof(BYTE), 512, output_img);
        }
    }

    // Close opened files so memory doesn't leak
    fclose(input);
    fclose(output_img);

}