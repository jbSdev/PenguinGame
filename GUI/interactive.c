#include "gui.h"
#include "../Board/board_functions.h"
#include "../Placement/placement.h"
#include <stdio.h>
#include <stdlib.h>

void flush_buffer()
{
    while (getchar() != '\n');
}

void interactive_mode()
{
    int playerCount;
    int penguinCount;
    int x, y;
    printf("Please input the number of players: ");
    scanf("%d", &playerCount);
    printf("Please input the number of penguins per player: ");
    scanf("%d", &penguinCount);

    //**************************************************//
    //              Board Generation Phase              //
    //**************************************************//
    printf("\nLet's generate a board!\n");
    generate_board();
    print_board();

    //**************************************************//
    //                  Placement Phase                 //
    //**************************************************//
    int count = 0;
    for (int penguin = 1; penguin <= penguinCount; penguin++)
    {
        for (int player = 1; player <= playerCount; player++)
        {
            printf("Player %d, please place your penguin %c: ", player, 'A' + count);
            scanf("%d %d", &x, &y);
            if (place_player('A' + count, x-1, y-1) != 1) // 1 means player placed the penguin correctly
            {
                player--;
                continue;
            }
            /* system("clear"); */
            count++;
            print_board();
        }
    }
    printf("All players placed!\n");

    //**************************************************//
    //                  Movement Phase                  //
    //**************************************************//
    printf("Move penguins using U - up, D - down, L - left, R - right.\n");
    int penguins[penguinCount * playerCount][2];            // penguins[][0] - can penguin move?, pengiuns[][1] - penguin points
    for (int i = 0; i < penguinCount * playerCount; i++)
    {
        penguins[i][0] = 1;             // Every penguin is movable
        penguins[i][1] = 0;             // Every penguin starts with 0 points
    }

    int movableCount = penguinCount  * playerCount;
    char move;
    int state = 0;
    while (movableCount > 0)
    {
        count = 0;
        for (int penguin = 1; penguin <= penguinCount; penguin++)
        {
            for (int player = 1; player <= playerCount; player++)
            {
                if (penguins[count][0] == 0)
                {
                    count++;
                    continue;
                }
                system("clear");
                printf("Move penguins using U - up, D - down, L - left, R - right.\n");
                print_board();
                printf("Player %d, please move your penguin %c: ", player, 'A' + count);
                flush_buffer();
                scanf("%c", &move); 
                
                state = move_player('A' + count, move);
                switch (state)
                {
                    case 0:     // Unable to move
                        movableCount--;
                        penguins[count][0] = 0;
                        printf("Penguin %c is unable to move anymore. Game over for him o7.\n", 'A' + count);
                        break;
                    case -1:    // Illegal move
                        printf("Penguin %c tried to do an illegal move.\n", 'A' + count);
                        break;
                    default:
                        penguins[count][1] += state;
                        printf("Added %d points\n", state);
                } 

                count++;
                system("sleep 0.5");
            }
        }
    }
    printf("None of the players can move anymore. Game Over!\nThe scoreboard:\n");
    for (int i = 0; i < penguinCount * playerCount; i++)
        printf("  Penguin %c: %3d points\n", 'A' + i, penguins[i][1]);
    
    
}
