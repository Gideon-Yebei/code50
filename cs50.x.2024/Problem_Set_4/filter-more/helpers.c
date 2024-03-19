#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute average of red, green, and blue values
            int avg = (image[i][j].rgbtRed + image[i][j].rgbtGreen +
                       image[i][j].rgbtBlue) /
                      3;

            // Update pixel values
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all rows
    for (int i = 0; i < height; i++)
    {
        // Loop over half of the columns (only need to swap up to the middle)
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
    // Create a temporary image to store blurred pixels
    RGBTRIPLE temp[height][width];

    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            int count = 0;

            // Loop over 3x3 grid around each pixel
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int newi = i + di;
                    int newj = j + dj;

                    // Check if the new pixel is within bounds
                    if (newi >= 0 && newi < height && newj >= 0 && newj < width)
                    {
                        // Accumulate color values
                        sumRed += image[newi][newj].rgbtRed;
                        sumGreen += image[newi][newj].rgbtGreen;
                        sumBlue += image[newi][newj].rgbtBlue;
                        count++;
                    }
                }
            }

            // Compute average color values
            temp[i][j].rgbtRed = sumRed / count;
            temp[i][j].rgbtGreen = sumGreen / count;
            temp[i][j].rgbtBlue = sumBlue / count;
        }
    }

    // Copy blurred image back to original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Define Sobel kernels
    int Gx_kernel[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy_kernel[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Create a temporary image to store edge-detected pixels
    RGBTRIPLE temp[height][width];

    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize Gx and Gy values for each color component
            int Gx_red = 0, Gy_red = 0;
            int Gx_green = 0, Gy_green = 0;
            int Gx_blue = 0, Gy_blue = 0;

            // Loop over 3x3 grid around each pixel
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int newi = i + di;
                    int newj = j + dj;

                    // Check if the new pixel is within bounds
                    if (newi >= 0 && newi < height && newj >= 0 && newj < width)
                    {
                        // Apply Sobel kernels to compute Gx and Gy for each
                        // color component
                        Gx_red += image[newi][newj].rgbtRed *
                                  Gx_kernel[di + 1][dj + 1];
                        Gy_red += image[newi][newj].rgbtRed *
                                  Gy_kernel[di + 1][dj + 1];

                        Gx_green += image[newi][newj].rgbtGreen *
                                    Gx_kernel[di + 1][dj + 1];
                        Gy_green += image[newi][newj].rgbtGreen *
                                    Gy_kernel[di + 1][dj + 1];

                        Gx_blue += image[newi][newj].rgbtBlue *
                                   Gx_kernel[di + 1][dj + 1];
                        Gy_blue += image[newi][newj].rgbtBlue *
                                   Gy_kernel[di + 1][dj + 1];
                    }
                }
            }

            // Compute final edge-detected values for each color component
            int edge_red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int edge_green =
                round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int edge_blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

            // Cap values at 255
            edge_red = fmin(255, edge_red);
            edge_green = fmin(255, edge_green);
            edge_blue = fmin(255, edge_blue);

            // Update pixel values
            temp[i][j].rgbtRed = edge_red;
            temp[i][j].rgbtGreen = edge_green;
            temp[i][j].rgbtBlue = edge_blue;
        }
    }

    // Copy edge-detected image back to original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}
