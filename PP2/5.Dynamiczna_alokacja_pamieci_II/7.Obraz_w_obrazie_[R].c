#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
__include__discard_stdin()
__include__string_split()
#include "image_utils.h"

int main()
{
    char* out_filename = (char*)malloc(sizeof(char) * 40);
    if (out_filename == null)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    print_ln("Enter output file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%39s", out_filename);
    discard_stdin();

    int err_code;
    struct image_t* out_img;
    if ((out_img = load_image_t(out_filename, &err_code)) == null)
    {
        switch (err_code)
        {
        case 2:
            free(out_filename);
            __m_exit(eFILE_noaccess);
        case 3:
            free(out_filename);
            __m_exit(eFILE_corrupted);
        case 4:
            free(out_filename);
            __m_exit(eMEMORY_cantallocate);
        default:
            free(out_filename);
            __m_exit(eINPUT_invalid);
        }
    }

    int file_cnt;
    print_ln("Enter input file count:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &file_cnt) != 1)
    {
        destroy_image(&out_img);
        free(out_filename);
        __m_exit(eINPUT_invalid);
    }
    if (file_cnt < 1)
    {
        destroy_image(&out_img);
        free(out_filename);
        __m_exit(eDATA_invalid);
    }


    char* in_filename = (char*)malloc(sizeof(char) * 40);
    if (in_filename == null)
    {
        destroy_image(&out_img);
        free(out_filename);
        __m_exit(eMEMORY_cantallocate);
    }
    struct image_t* in_img = null;
    int x;
    int y;
    while (file_cnt > 0)
    {
        destroy_image(&in_img);
        printf_ln("Enter next input file path (%d remaining):", file_cnt);
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        scanf("%39s", in_filename);
        discard_stdin();
        if ((in_img = load_image_t(in_filename, &err_code)) == null)
        {
            switch (err_code)
            {
            case 2:
                print_ln(eFILE_noaccess);
                --file_cnt;
                continue;
            case 3:
                print_ln(eFILE_corrupted);
                --file_cnt;
                continue;
            case 4:
                destroy_image(&in_img);
                free(in_filename);
                destroy_image(&out_img);
                free(out_filename);
                __m_exit(eMEMORY_cantallocate);
            default: continue;
            }
        }
        print_ln("Enter destination coordinates (x, y):");
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%d %d", &x, &y) != 2)
        {
            destroy_image(&in_img);
            free(in_filename);
            destroy_image(&out_img);
            free(out_filename);
            __m_exit(eINPUT_invalid);
        }
        if (draw_image(out_img, in_img, x, y) != 0)
        {
            print_ln(eDATA_invalid);
        }
        --file_cnt;
    }

    char* out_final_filename = (char*)calloc(sizeof(char), 50);
    if (out_filename == null)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    strncpy(out_final_filename, out_filename, strlen(out_filename) - 4);
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.strcpy) -> Dante doesn't provide *_s
    strcat(out_final_filename, "_modified."); 
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.strcpy) -> Dante doesn't provide *_s
    strcat(out_final_filename, out_filename + strlen(out_filename) - 3);
    

    switch (save_image_t(out_final_filename, out_img))
    // switch (save_image_t(out_filename, out_img))
    {
    case 2:
    case 3:
        free(out_final_filename);
        destroy_image(&in_img);
        free(in_filename);
        destroy_image(&out_img);
        free(out_filename);
        __m_exit(eFILE_cantcreate);
    }

    print_ln("File saved");
    free(out_final_filename);
    destroy_image(&in_img);
    free(in_filename);
    destroy_image(&out_img);
    free(out_filename);
    return 0;
}
