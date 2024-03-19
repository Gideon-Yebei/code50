#include "helpers.h"
#include <stdio.h>

// Function to compute the minimum of two integers
int min(int a, int b)
{
    return (a < b) ? a : b;
}

// Function to compute the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate average of RGB values
            int avg = (image[i][j].rgbtRed + image[i][j].rgbtGreen +
                       image[i][j].rgbtBlue) /
                      3;
            // Set all RGB values to the average
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate sepia values
            int sepiaRed = min(255, (int) (0.393 * image[i][j].rgbtRed +
                                           0.769 * image[i][j].rgbtGreen +
                                           0.189 * image[i][j].rgbtBlue));
            int sepiaGreen = min(255, (int) (0.349 * image[i][j].rgbtRed +
                                             0.686 * image[i][j].rgbtGreen +
                                             0.168 * image[i][j].rgbtBlue));
            int sepiaBlue = min(255, (int) (0.272 * image[i][j].rgbtRed +
                                            0.534 * image[i][j].rgbtGreen +
                                            0.131 * image[i][j].rgbtBlue));
            // Update pixel with sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels horizontally
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    // Copy original image to temporary array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Apply blur effect
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            float count = 0.0;
            // Iterate over neighboring pixels
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;
                    // Check if neighboring pixel is within bounds
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        sumRed += temp[ni][nj].rgbtRed;
                        sumGreen += temp[ni][nj].rgbtGreen;
                        sumBlue += temp[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }
            // Calculate average and set blurred pixel values
            image[i][j].rgbtRed = min(255, (int) (sumRed / count + 0.5));
            image[i][j].rgbtGreen = min(255, (int) (sumGreen / count + 0.5));
            image[i][j].rgbtBlue = min(255, (int) (sumBlue / count + 0.5));
        }
    }
}
