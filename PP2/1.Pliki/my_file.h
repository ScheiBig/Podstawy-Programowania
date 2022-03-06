/**
 * @file my_file.h
 * @author Marcin Jeznach (241204@edu.p.lodz.pl)
 * @brief Provides ability to register files, and bulk-close all of them
 * @version 0.1
 * @date 2022-03-06
 */

#pragma once
#include "my_utils.h"

/**
 * @brief Registers file-pointer for bulk cleanup.
 * Registered file should not be closed using fclose(1) - this might cause resource leak; use release_file_pointer(1) instead;
 * @param file Pointer to file that should be later cleaned up.
 * @return Pointer to `file` for convenience of chaining calls, or NULL if no file is provided, or max amount of files are registered.
 */
FILE* register_file_pointer(FILE* file);

/**
 * @brief Closes all registered files.
 * After this call number of registered files will be 0.
 */
void close_file_pointers(void);

/**
 * @brief If `file` is registered, closes its references and releases them.
 * 
 * @param file File to be closed.
 * @return Number of released refrences.
 */
int release_file_pointer(FILE* file);
