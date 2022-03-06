/**
 * @file my_exit.c
 * @author Marcin Jeznach (241204@edu.p.lodz.pl)
 * @brief Provides custom exit-handlers like in atexit(1). For them to be called, either process_exit_handlers(0) or _*_exit(*) needs to be called
 * @version 0.1
 * @date 2022-03-06
 */
#include "my_exit.h"

_exit_handler_ __eh_1__;
_exit_handler_ __eh_2__;
_exit_handler_ __eh_3__;
_exit_handler_ __eh_4__;
_exit_handler_ __eh_5__;
_exit_handler_ __eh_6__;
_exit_handler_ __eh_7__;
_exit_handler_ __eh_8__;

int register_exit_handler(_exit_handler_ handler)
{
    if (handler == NULL) return 0;
    if (__eh_1__ == NULL)
    {
        __eh_1__ = handler;
        return 1;
    }
    if (__eh_2__ == NULL)
    {
        __eh_2__ = handler;
        return 2;
    }
    if (__eh_3__ == NULL)
    {
        __eh_3__ = handler;
        return 3;
    }
    if (__eh_4__ == NULL)
    {
        __eh_4__ = handler;
        return 4;
    }
    if (__eh_5__ == NULL)
    {
        __eh_5__ = handler;
        return 5;
    }
    if (__eh_6__ == NULL)
    {
        __eh_6__ = handler;
        return 6;
    }
    if (__eh_7__ == NULL)
    {
        __eh_7__ = handler;
        return 7;
    }
    if (__eh_8__ == NULL)
    {
        __eh_8__ = handler;
        return 8;
    }
    return 0;
}
void process_exit_handlers()
{
    if (__eh_8__ != NULL) __eh_8__();
    if (__eh_7__ != NULL) __eh_7__();
    if (__eh_6__ != NULL) __eh_6__();
    if (__eh_5__ != NULL) __eh_5__();
    if (__eh_4__ != NULL) __eh_4__();
    if (__eh_3__ != NULL) __eh_3__();
    if (__eh_2__ != NULL) __eh_2__();
    if (__eh_1__ != NULL) __eh_1__();
}
