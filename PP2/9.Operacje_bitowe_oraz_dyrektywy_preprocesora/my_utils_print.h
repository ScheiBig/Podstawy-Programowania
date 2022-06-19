/**
 * @file my_utils_print.h
 * @author Marcin Jeznach (241204@edu.p.lodz.pl)
 * @brief Various utilities:
 *             predefined code errors and messages,
 *             macros for printing to stdout and stderr with newline termination
 *             macros for returning from functions with printing messages
 *            
 *
 * This is truncated version of my_utils_v3.h for extremely limited exercises
 */
#pragma once

#define eERROR_unknown_eno 42069
#define eERROR_unknown "Unknown program state"

#define eARGS_insufficient_eno 9
#define eARGS_insufficient "Not enough arguments"
#define eMEMORY_cantallocate_eno 8
#define eMEMORY_cantallocate "Failed to allocate memory"
#define eFILE_unsupported_eno 7
#define eFILE_unsupported "Unsupported file format"
#define eFILE_corrupted_eno 6
#define eFILE_corrupted "File corrupted"
#define eFILE_cantcreate_eno 5
#define eFILE_cantcreate "Couldn't create file"
#define eFILE_noaccess_eno 4
#define eFILE_noaccess "Couldn't open file"
#define eDATA_insufficient_eno 3
#define eDATA_insufficient "Not enough data available"
#define eDATA_invalid_eno 2
#define eDATA_invalid "Incorrect input data"
#define eINPUT_invalid_eno 1
#define eINPUT_invalid "Incorrect input"


#define eprint_ln(msg) fprintf(stderr, msg "\n")
#define eprintf_ln(msg, ...) fprintf(stderr, msg "\n", __VA_ARGS__)
#define eprintf(msg, ...) fprintf(stderr, msg, __VA_ARGS__)
#define eprint_n() fprintf(stderr, "\n")
#define print_ln(format) printf(format "\n")
#define printf_ln(format, ...) printf(format "\n", __VA_ARGS__)
#define print_n() printf("\n")

#define _el_exit(eno, msg) return eno * !!eprint_ln(msg)
#define _ml_exit(eno, msg) return eno * !!print_ln(msg)
#define _e_exit(eno, msg) return eno * !!fprintf(stderr, msg)
#define _m_exit(eno, msg) return eno * !!printf(msg)
#define __el_exit(msg) return msg ## _eno * !!eprint_ln(msg)
#define __ml_exit(msg) return msg ## _eno * !!print_ln(msg)
#define __e_exit(msg) return msg ## _eno * !!fprintf(stderr, msg)
#define __m_exit(msg) return msg ## _eno * !!printf(msg)
