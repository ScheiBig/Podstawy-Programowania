/**
 * @file my_exit.h
 * @author Marcin Jeznach (241204@edu.p.lodz.pl)
 * @brief Provides custom exit-handlers like in atexit(1). For them to be called, either process_exit_handlers(0) or _*_exit(*) needs to be called
 * @version 0.1
 * @date 2022-03-06
 */

#pragma once
#include "my_utils_v2.h"

// exit-handler type needs to be pointer to function that 
typedef void (*_exit_handler_)(void);

/**
 * @brief Registers new exit-handler.
 * Maximum number of exit-handlers are 8.
 *
 * @param handler Pointer to function that should be launched at standard exit from program.
 * @return 0 if `handler` is NULL or maximum number of handler is registered, otherwise number of currently registered handlers.
 */
int register_exit_handler(_exit_handler_ handler);

/**
 * @brief Launches all available exit-handlers.
 * Be aware that calling this might (should?) be destructing.
 */
void process_exit_handlers(void);

#define _elh_exit(eno, msg) { eprint_ln(msg); process_exit_handlers(); return eno; }
#define _mlh_exit(eno, msg) { print_ln(msg); process_exit_handlers(); return eno; }
#define _eh_exit(eno, msg) { fprintf(stderr, msg); process_exit_handlers(); return eno; }
#define _mh_exit(eno, msg) { printf(msg); process_exit_handlers(); return eno; }
#define _h_exit() { process_exit_handlers(); return 0; }
#define _nh_exit(eno) { process_exit_handlers(); return eno; }
