#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v3.h"
#include "my_string.h"
#include "board.h"

enum dir_command
{
    UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd', EXIT = 'q'
};

int main()
{
    int width;
    int height;
    board_s* board;
    print_ln("Enter board dimensions: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d %d", &width, &height) != 2) { __m_exit(eINPUT_invalid); }
    else if (width <= 0 || height <= 0) { __m_exit(eDATA_invalid); }
    else if (create_board(&board, width, height) != 0) { __m_exit(eMEMORY_cantallocate); }

    print_ln("Enter player position: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d %d", &width, &height) != 2)
    {
        free_board(board);
        __m_exit(eINPUT_invalid);
    }
    else if (0 > width || width >= board->width || 0 > height || height >= board->height)
    {
        free_board(board);
        __m_exit(eDATA_invalid);
    }
    set_player(board, width, height);

    bool cont = true;
    bool err = false;
    char choice;
    discard_stdin();
    while (cont)
    {
        if (!err) { display_board(board); }
        err = false;
        print_ln("Choose action: ");
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        scanf("%c%*c", &choice);
        switch (choice)
        {
        case UP:
            board->move_player_up(board);
            break;
        case DOWN:
            board->move_player_down(board);
            break;
        case LEFT:
            board->move_player_left(board);
            break;
        case RIGHT:
            board->move_player_right(board);
            break;
        case EXIT:
            cont = false;
            break;
        default:
            print_ln("Incorrect choice");
            err = true;
            break;
        }
    }

    free_board(board);

    return 0;
}
