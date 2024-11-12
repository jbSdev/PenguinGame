#include "GUI/gui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_mode();

int main()
{
    system("clear");
    printf("Welcome to the Penguins Game!\n");
    
    int mode = get_mode(); 
    if (mode == 0)
        interactive_mode();
    else if (mode == 1)
        autonomous_mode();
    else
        printf("Mode error: %d", mode);

    /* generate_board(); */
    /* int playersCount; */
    /* scanf("%d", &playersCount); */
    
    /* char move[2] = "AU"; */
    /* move_player(move[0], move[1]); */
    /* print_board(); */
    /* struct BestPlace bestPlace1 = heat_placement(); */
    /* place_player('A', bestPlace1.x, bestPlace1.y); */
    /* struct BestPlace bestPlace2 = heat_placement(); */
    /* place_player('B', bestPlace2.x, bestPlace2.y); */
    return 0;
}

int get_mode()
{
    printf("Please choose the gamemode: Interactive 'int' or Autonomous 'auto'\nGamemode: ");
    char gameMode[5];
    memset(gameMode, 0, sizeof(gameMode));
    if (fgets(gameMode, 5, stdin))           // 4-char input and terminating character
    {
        size_t len = strlen(gameMode);
        if (len > 0 && gameMode [len - 1] == '\n')
           gameMode[len - 1] = '\0';
    }
    else
    {
        printf("Error reading input.\n");
        return get_mode();
    }

    if (strcmp(gameMode, "int") == 0)
        return 0;           // Interactive mode
    else if (strcmp(gameMode, "auto") == 0)
        return 1;           // Autonomous mode
    else
    {
        printf("Invalid gamemode. Type in 'int' for interactive or 'auto' for autonomous.\n");
        return get_mode();
    }
    return -1;      // Should never return
}
