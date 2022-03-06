/**
 * @file my_file.c
 * @author Marcin Jeznach (241204@edu.p.lodz.pl)
 * @brief Provides ability to register files, and bulk-close all of them
 * @version 0.1
 * @date 2022-03-06
 */

#include "my_file.h"

static FILE* __fp_1__;
static FILE* __fp_2__;
static FILE* __fp_3__;
static FILE* __fp_4__;
static FILE* __fp_5__;
static FILE* __fp_6__;
static FILE* __fp_7__;
static FILE* __fp_8__;

FILE* register_file_pointer(FILE* file)
{
    if (file == NULL) return NULL;
    if (__fp_1__ == NULL)
    {
        __fp_1__ = file;
        return file;
    }
    if (__fp_2__ == NULL)
    {
        __fp_2__ = file;
        return file;
    }
    if (__fp_3__ == NULL)
    {
        __fp_3__ = file;
        return file;
    }
    if (__fp_4__ == NULL)
    {
        __fp_4__ = file;
        return file;
    }
    if (__fp_5__ == NULL)
    {
        __fp_5__ = file;
        return file;
    }
    if (__fp_6__ == NULL)
    {
        __fp_6__ = file;
        return file;
    }
    if (__fp_7__ == NULL)
    {
        __fp_7__ = file;
        return file;
    }
    if (__fp_8__ == NULL)
    {
        __fp_8__ = file;
        return file;
    }
    return NULL;
}

void close_file_pointers()
{
    // So that there is no unused function warning
    release_file_pointer(NULL);
    if (__fp_1__ != NULL)
    {
        fclose(__fp_1__);
        __fp_1__ = NULL;
    }
    if (__fp_2__ != NULL)
    {
        fclose(__fp_2__);
        __fp_2__ = NULL;
    }
    if (__fp_3__ != NULL)
    {
        fclose(__fp_3__);
        __fp_3__ = NULL;
    }
    if (__fp_4__ != NULL)
    {
        fclose(__fp_4__);
        __fp_4__ = NULL;
    }
    if (__fp_5__ != NULL)
    {
        fclose(__fp_5__);
        __fp_5__ = NULL;
    }
    if (__fp_6__ != NULL)
    {
        fclose(__fp_6__);
        __fp_6__ = NULL;
    }
    if (__fp_7__ != NULL)
    {
        fclose(__fp_7__);
        __fp_7__ = NULL;
    }
    if (__fp_8__ != NULL)
    {
        fclose(__fp_8__);
        __fp_8__ = NULL;
    }
}

int release_file_pointer(FILE* file)
{
    if (file == NULL) return 0;
    int released = 0;
    if (__fp_1__ == file)
    {
        fclose(__fp_1__);
        __fp_1__ = NULL;
        ++released;
    }
    if (__fp_2__ == file)
    {
        fclose(__fp_2__);
        __fp_2__ = NULL;
        ++released;
    }
    if (__fp_3__ == file)
    {
        fclose(__fp_3__);
        __fp_3__ = NULL;
        ++released;
    }
    if (__fp_4__ == file)
    {
        fclose(__fp_4__);
        __fp_4__ = NULL;
        ++released;
    }
    if (__fp_5__ == file)
    {
        fclose(__fp_5__);
        __fp_5__ = NULL;
        ++released;
    }
    if (__fp_6__ == file)
    {
        fclose(__fp_6__);
        __fp_6__ = NULL;
        ++released;
    }
    if (__fp_7__ == file)
    {
        fclose(__fp_7__);
        __fp_7__ = NULL;
        ++released;
    }
    if (__fp_8__ == file)
    {
        fclose(__fp_8__);
        __fp_8__ = NULL;
        ++released;
    }
    return released;
}
