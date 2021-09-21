// CS50 2021 - Introduction to Computer Science.
// Week 4 - Problem Set 4 - Language: C
// Filter - helpers.c
// Nicolas Rodriguez Aldegheri
// 21/09/21


#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtBlue + pixel.rgbtRed + pixel.rgbtGreen) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    //Transform to temp
    for (int i = 0; i < height; i++)
    {
        int currentPos = 0;
        for (int j = width - 1; j >= 0; j--, currentPos++)
        {
            temp[i][currentPos] = image[i][j];
        }
    }
    //Copy to final image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int count = 0;
            int rowCoords[] = {row - 1, row, row + 1};
            int colCoords[] = {col - 1, col, col + 1};
            float totalR = 0, totalG = 0, totalB = 0;

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int curRow = rowCoords[r];
                    int curCol = colCoords[c];

                    if (curRow >= 0 && curRow < height && curCol >= 0 && curCol < width)
                    {
                        RGBTRIPLE pixel = image[curRow][curCol];
                        totalR += pixel.rgbtRed;
                        totalG += pixel.rgbtGreen;
                        totalB += pixel.rgbtBlue;
                        count++;
                    }
                }
            }
            temp[row][col].rgbtRed = round(totalR / count);
            temp[row][col].rgbtGreen = round(totalG / count);
            temp[row][col].rgbtBlue = round(totalB / count);
        }
    }
    //Copy to final image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    //Apply the edge detection algorithm
    int Gx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1},
    };
    int Gy[3][3] =
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1},
    };
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int rowCoords[] = {row - 1, row, row + 1};
            int colCoords[] = {col - 1, col, col + 1};
            float GxR = 0, GxG = 0, GxB = 0;
            float GyR = 0, GyG = 0, GyB = 0;

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int curRow = rowCoords[r];
                    int curCol = colCoords[c];

                    if (curRow >= 0 && curRow < height && curCol >= 0 && curCol < width)
                    {
                        RGBTRIPLE pixel = image[curRow][curCol];
                        GxR += Gx[r][c] * pixel.rgbtRed;
                        GxG += Gx[r][c] * pixel.rgbtGreen;
                        GxB += Gx[r][c] * pixel.rgbtBlue;

                        GyR += Gy[r][c] * pixel.rgbtRed;
                        GyG += Gy[r][c] * pixel.rgbtGreen;
                        GyB += Gy[r][c] * pixel.rgbtBlue;
                    }
                }
            }
            //Now apply the sqrt funct to Gx & Gy
            int finalR = round(sqrt(GxR * GxR + GyR * GyR));
            int finalG = round(sqrt(GxG * GxG + GyG * GyG));
            int finalB = round(sqrt(GxB * GxB + GyB * GyB));

            temp[row][col].rgbtRed = finalR > 255 ? 255 : finalR;
            temp[row][col].rgbtGreen = finalG > 255 ? 255 : finalG;
            temp[row][col].rgbtBlue = finalB > 255 ? 255 : finalB;
        }
    }

    //Copy to final image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
