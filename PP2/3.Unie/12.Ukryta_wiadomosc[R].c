#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
__include__discard_stdin()

typedef union
{
    u_char character;
    struct
    {
        u_char lsb : 1;
        u_char other : 7;
    } bits;
} lsb_u;

int encode(const char* input, char* txt, const char* output);
int decode(const char* filename, char* txt, int size);

int main()
{
    char m_buffer[1001];
    char pi_buffer[30];
    char po_buffer[30];
    char sel;

    print_ln("Select program mode - [E]ncode / [D]ecode:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%c%*c", &sel);
    switch (sel)
    {
    case 'e': case 'E':
        print_ln("Enter message to encode:");
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        scanf("%1000[^\n]", m_buffer);
        discard_stdin();
        print_ln("Enter input path:");
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        scanf("%29[^\n]", pi_buffer);
        discard_stdin();
        print_ln("Enter output path:");
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        scanf("%29[^\n]", po_buffer);
        discard_stdin();

        switch (encode(pi_buffer, m_buffer, po_buffer))
        {
        case 4:
            __m_exit(eFILE_cantcreate);
        case 3:
            __m_exit(eFILE_corrupted);
        case 2:
            __m_exit(eFILE_noaccess);
        default:
            print_ln("File saved");
            break;
        }
        break;
    case 'd': case 'D':
        print_ln("Enter input path:");
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        scanf("%29[^\n]", pi_buffer);
        discard_stdin();;

        switch (decode(pi_buffer, m_buffer, 1001))
        {
        case 3:
            __m_exit(eFILE_corrupted);
        case 2:
            __m_exit(eFILE_noaccess);
        default:
            printf("%s", m_buffer);
            break;
        }
        break;
    default:
        _m_exit(eINPUT_invalid_eno, eDATA_invalid);
    }

    return 0;
}

int encode(const char* input, char* txt, const char* output)
{
    size_t txt_len;
    if (input == null || strlen(input) == 0 ||
        txt == null || (txt_len = strlen(txt)) == 0 ||
        output == null || strlen(output) == 0)
    {
        return 1;
    }
    FILE* in_file;
    if ((in_file = fopen(input, "r")) == NULL)
    {
        return 2;
    }
    FILE* out_file;
    if ((out_file = fopen(output, "w")) == NULL)
    {
        fclose(in_file);
        return 4;
    }
    lsb_u deencoder;
    u_int i;
    for (i = 0; i < txt_len * 8; ++i)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s— 
        switch (fscanf(in_file, "%hhu%*c", &deencoder.character))
        {
        case 1: break;
        default:
            fclose(in_file);
            fclose(out_file);
            return 3;
        }

        deencoder.bits.lsb = (*(txt + (i / 8)) >> (7 - i % 8)) & 0x1;

        fprintf(out_file, "%hhu ", deencoder.character);
        if (*(txt + (i / 8)) == '\n' && i % 8 == 7)
        {
            fprintf(out_file, "\n");
        }
        if (fgetc(in_file) == '\n')
        {
            fprintf(out_file, "\n");
        }
        else
        {
            fseek(in_file, -1L, SEEK_CUR);
        }
    }
    while (true)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (fscanf(in_file, "%hhu%*c", &deencoder.character) == EOF)
        {
            break;
        }

        deencoder.bits.lsb = 0x0;

        fprintf(out_file, "%hhu ", deencoder.character);
        if (fgetc(in_file) == '\n')
        {
            fprintf(out_file, "\n");
        }
        else
        {
            fseek(in_file, -1L, SEEK_CUR);
        }
    }
    
    fclose(in_file);
    fclose(out_file);

    return 0;
}

int decode(const char* filename, char* txt, int size)
{
    if (filename == null || strlen(filename) == 0 || txt == null || size < 1)
    {
        return 1;
    }
    FILE* file;
    if ((file = fopen(filename, "r")) == NULL)
    {
        return 2;
    }
    lsb_u deencoder;
    int i;
    for (i = 0; i < (size - 1) * 8; ++i)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s— 
        switch (fscanf(file, "%hhu", &deencoder.character))
        {
        case EOF: goto break_for;
        case 1: break;
        default:
            fclose(file);
            return 3;
        }

        if (i % 8 == 0)
        {
            *(txt + (i / 8)) = 0;
            if (deencoder.bits.lsb == 0x1)
            {
                fclose(file);
                return 3;
            }
        }
        *(txt + (i / 8)) += (char)deencoder.bits.lsb << (7 - i % 8);
        
    }
break_for: {}
    *(txt + size - 1) = '\0';
    if (i % 8 != 0)
    {
        fclose(file);
        return 3;
    }
    
    fclose(file);
    return 0;
}
