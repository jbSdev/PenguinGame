#include <math.h>
#include "board_functions.h"

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
