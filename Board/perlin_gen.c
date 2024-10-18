#include <stdio.h>
#include <math.h>

static int SEED = 0;

static int hash[] = {208,34,231,213,32,248,233,56,161,78,24,140,71,48,140,254,245,255,247,247,40,
                     185,248,251,245,28,124,204,204,76,36,1,107,28,234,163,202,224,245,128,167,204,
                     9,92,217,54,239,174,173,102,193,189,190,121,100,108,167,44,43,77,180,204,8,81,
                     70,223,11,38,24,254,210,210,177,32,81,195,243,125,8,169,112,32,97,53,195,13,
                     203,9,47,104,125,117,114,124,165,203,181,235,193,206,70,180,174,0,167,181,41,
                     164,30,116,127,198,245,146,87,224,149,206,57,4,192,210,65,210,129,240,178,105,
                     228,108,245,148,140,40,35,195,38,58,65,207,215,253,65,85,208,76,62,3,237,55,89,
                     232,50,217,64,244,157,199,121,252,90,17,212,203,149,152,140,187,234,177,73,174,
                     193,100,192,143,97,53,145,135,19,103,13,90,135,151,199,91,239,247,33,39,145,
                     101,120,99,3,186,86,99,41,237,203,111,79,220,135,158,42,30,154,120,67,87,167,
                     135,176,183,191,253,115,184,21,233,58,129,233,142,39,128,211,118,137,139,255,
                     114,20,218,113,154,27,127,246,250,1,8,198,250,209,92,222,173,21,88,102,219};

int noise(int x, int y)
{
    int tmp = hash[(y + SEED) % 256];
    return hash[(tmp + x) % 256];
}

float lin_inter(float x, float y, float s)
{
    return x + s * (y - x);
}

float smooth_inter(float x, float y, float s)
{
    return lin_inter(x, y, s * s * (3 - 2*s));
}

float noise2d(float x, float y)
{
    int x_int       = x;
    int y_int       = y;
    float x_frac    = x - x_int;
    float y_frac    = y - y_int;
    int s = noise(x_int,      y_int);
    int t = noise(x_int + 1,  y_int);
    int u = noise(x_int,      y_int + 1);
    int v = noise(x_int + 1,  y_int + 1);
    float low   = smooth_inter(s, t, x_frac);
    float high  = smooth_inter(u, v, x_frac);
    return smooth_inter(low, high, y_frac);
}

float perlin2d(float x, float y, float freq, int depth)
{
    float xa = x * freq;
    float ya = y * freq;
    float amp = 1.0;
    float fin = 0;
    float div = 0.0;

    for (int i = 0; i < depth; i++)
    {
        div += 256 * amp;
        fin += noise2d(xa, ya) * amp;
        amp /= 2;
        xa  *= 2;
        ya  *= 2;
    }
    return fin/div;
}

float gaussian(int x, int y, int size_x, int size_y)
{
    float e  = 2.71828;
    float a  = 0.4;          // Tweakable
    float pi = 3.14159;
    // Returning this function: https://www.desmos.com/3d/ne7zzbm3td
    float fraq_x = fabsf(x - ( (float)size_x / 2 )) / ((float)size_x / 2);       // Distance from the center on X axes -> (0, 1)
    float fraq_y = fabsf(y - ( (float)size_y / 2 )) / ((float)size_y / 2);       // Distance from the center on Y axes -> (0, 1)

    float exponent = ( -1 * (pow(fraq_x, 2) + (pow(fraq_y, 2)) ) ) / (2 * a * a);

    return pow(e, exponent) / sqrt(2 * pi * a * a);                             // Value between (0, 1)
}

int main(int argc, char *argv[])
{
    int size_x, size_y;
    printf("Insert the map size - X and Y:\t");
    scanf("%d %d", &size_x, &size_y);

    printf("Insert the SEED:\t");
    scanf("%d", &SEED);

    int x, y;
    float out;
    for (y = 0; y < size_y; y++)
    {
        for (x = 0; x < size_x; x++)
        {
            float weight = gaussian(x, y, size_x, size_y);

            out = perlin2d(x, y, 0.3, 1) * weight;      // Tweak with freq and depth

            if (out > 0.1)                             // Tweak edge value
                printf("\x1b[36m%.2f ", out);
            else
                printf("\x1b[31m%.2f ", out);
        }
        printf("\n");
    }
}
