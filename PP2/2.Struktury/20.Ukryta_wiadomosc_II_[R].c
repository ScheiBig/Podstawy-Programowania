#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils.h"

typedef struct message_t
{
    char a; // 1 byte
    // 7 bytes padding
    double b; // 8 bytes
    int c; // 4 bytes
    // 4 bytes padding
} message_s;

int load_data(struct message_t* cp, int size, const char* filename);
int decode_message(const struct message_t* cp, int size, char* msg, int text_size);

int read_from_msgt(struct message_t* smt, int byte_no, char* byte_v);

int main()
{
    /// 100 * 11 bytes of padding => 109 characters max (and null string termiator)
    message_s hidden_data[100];
    char buffer[31], message[1101];

    print_ln("Enter file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%30s", buffer) != 1)
    {
        _m_exit(eFILE_noaccess, eFILE_noaccess_msg)
    }
    int read_len;

    switch (read_len = load_data(hidden_data, 100, buffer))
    {
    case -2: {
        _m_exit(eFILE_noaccess, eFILE_noaccess_msg)
    }
    case -3: {
        _m_exit(eFILE_corrupted, eFILE_corrupted_msg)
    }
    case -1: return -1;
    default: break;
    }

    decode_message(hidden_data, read_len, message, 1101);
    printf("%s", message);

    return 0;
}

int load_data(struct message_t* cp, int size, const char* filename)
{
    if (cp == NULL || filename == NULL || strlen(filename) < 1 || size < 1)
    {
        return -1;
    }
    FILE* f;
    if ((f = fopen(filename, "r")) == NULL)
    {
        return -2;
    }
    u_int size_infile, size_act;
    if (fread(&size_infile, sizeof(u_int), 1, f) == 0)
    {
        fclose(f);
        return -3;
    }
    else if (size_infile % 24 != 0)
    {
        fclose(f);
        return -3;
    }
    size_act = min(size * 24u, size_infile);
    char byte;

    for (u_int i = 0; i < size_act; ++i)
    {
        if (fread(&byte, sizeof(char), 1, f) == 0)
        {
            fclose(f);
            return -3;
        }
        *((char*)(cp)+i) = byte;
    }
    fclose(f);
    return size_act / 24;
}

int decode_message(const struct message_t* cp, int size, char* msg, int text_size)
{
    if (cp == NULL || msg == NULL || text_size < 1 || size < 1)
    {
        return 1;
    }
    u_int size_act = min(size * 11 + 1, text_size);
    for (u_int i = 0; i < size_act - 1; ++i)
    {
        read_from_msgt((message_s*)cp + (i / 11), i % 11, msg + i);
    }
    *(msg + size_act - 1) = '\0';
    return 0;
}

int read_from_msgt(struct message_t* smt, int byte_no, char* byte_v)
{
    if (smt == NULL)
    {
        return 1;
    }
    if (0 > byte_no || byte_no >= 11)
    {
        return 2;
    }
    char* pad = (char*)smt + 1;
    int bn = byte_no;
    if (byte_no >= 7)
    {
        bn += 12;
    }
    *byte_v = *(pad + bn);
    return 0;
}
