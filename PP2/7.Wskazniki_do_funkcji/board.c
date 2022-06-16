#include "board.h"

#include <stdlib.h>

#include "my_utils_v3.h"

int create_board(board_s** board, int width, int height)
{
    if (board == null || width <= 0 || height <= 0) { return 1; }
    if ((*board = (board_s*)calloc(1, sizeof(board_s))) == null) { return 2; }
    (*board)->width = width;
    (*board)->height = height;
    if (((*board)->board = (char**)calloc((unsigned)height, sizeof(char*))) == null)
    {
        free_board(*board);
        return 2;
    }
    for (char** row = (*board)->board; row < (*board)->board + height; ++row)
    {
        if ((*row = (char*)calloc((unsigned)width + 1, sizeof(char))) == null)
        {
            free_board(*board);
            return 2;
        }
        for (char* cell = *row; cell < *row + width; ++cell)
        {
            *cell = '.';
        }
    }
    (*board)->move_player_up = move_player_up;
    (*board)->move_player_down = move_player_down;
    (*board)->move_player_left = move_player_left;
    (*board)->move_player_right = move_player_right;
    return 0;
}

void display_board(const board_s* board)
{
    if (board == null) { return; }
    if (board->board == null) { return; }
    for (char** row = board->board; row < board->board + board->height; ++row)
    {
        if (row == null) { return; }
    }
    for (char** row = board->board; row < board->board + board->height; ++row)
    {
        printf_ln("%s", *row);
    }
}

void free_board(board_s* board)
{
    if (board == null) { return; }
    if (board->board == null)
    {
        free(board);
        return;
    }
    for (char** row = board->board; row < board->board + board->height; ++row)
    {
        if (row == null) { break; }
        free(*row);
    }
    free(board->board);
    free(board);
}

void _set_player(board_s* board, int x, int y)
{
    if (board->is_init)
    {
        *(*(board->board + board->player.y) + board->player.x) = '.';
    }
    board->player = (point_s){ .x = x, .y = y };
    *(*(board->board + y) + x) = '@';
    board->is_init = 1;
}

int set_player(board_s* board, int x, int y)
{
    if (board == null || board->board == null
        || 0 > x || x >= board->width || 0 > y || y >= board->height
        || board->is_init)
    {
        return 1;
    }
    _set_player(board, x, y);
    return 0;
}

int _is_valid_board(board_s* board)
{
    if (board == null) { return 0; }
    if (board->board == null) { return 0; }
    if (board->height <= 0 || board->width <= 0) { return 0; }
    if (!board->is_init) { return 0; }
    if (0 > board->player.x || board->player.x >= board->width) { return 0; }
    if (0 > board->player.y || board->player.y >= board->height) { return 0; }
    return 1;
}

struct board_t* move_player_up(board_s* board)
{
    if (!_is_valid_board(board)) { return null; }
    int u = board->player.y - 1;
    if (u == -1) { u = board->height - 1; }
    _set_player(board, board->player.x, u);
    return board;
}

struct board_t* move_player_down(board_s* board)
{
    if (!_is_valid_board(board)) { return null; }
    int d = board->player.y + 1;
    if (d == board->height) { d = 0; }
    _set_player(board, board->player.x, d);
    return board;
}

struct board_t* move_player_left(board_s* board)
{
    if (!_is_valid_board(board)) { return null; }
    if (!_is_valid_board(board)) { return null; }
    int l = board->player.x - 1;
    if (l == -1) { l = board->width - 1; }
    _set_player(board, l, board->player.y);
    return board;
}

struct board_t* move_player_right(board_s* board)
{
    if (!_is_valid_board(board)) { return null; }
    int r = board->player.x + 1;
    if (r == board->width) { r = 0; }
    _set_player(board, r, board->player.y);
    return board;
}
