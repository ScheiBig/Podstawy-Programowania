#include "linked_list2.h"

#include "my_utils_v3.h"

#define a01      *(argv + 0x1)
#define a02 a01, *(argv + 0x2)
#define a03 a02, *(argv + 0x3)
#define a04 a03, *(argv + 0x4)
#define a05 a04, *(argv + 0x5)
#define a06 a05, *(argv + 0x6)
#define a07 a06, *(argv + 0x7)
#define a08 a07, *(argv + 0x8)
#define a09 a08, *(argv + 0x9)
#define a0a a09, *(argv + 0xa)
#define a0b a0a, *(argv + 0xb)
#define a0c a0b, *(argv + 0xc)
#define a0d a0c, *(argv + 0xd)
#define a0e a0d, *(argv + 0xe)
#define a0f a0e, *(argv + 0xf)
#define a10 a0f, *(argv + 0x10)
#define a11 a10, *(argv + 0x11)
#define a12 a11, *(argv + 0x12)
#define a13 a12, *(argv + 0x13)
#define a14 a13, *(argv + 0x14)
#define a15 a14, *(argv + 0x15)
#define a16 a15, *(argv + 0x16)
#define a17 a16, *(argv + 0x17)
#define a18 a17, *(argv + 0x18)
#define a19 a18, *(argv + 0x19)
#define a1a a19, *(argv + 0x1a)
#define a1b a1a, *(argv + 0x1b)
#define a1c a1b, *(argv + 0x1c)
#define a1d a1c, *(argv + 0x1d)
#define a1e a1d, *(argv + 0x1e)

#define _case(num) \
    case 0x ## num: \
        if (LIST.insert_words(list, 0x ## num, a ## num) != 0x ## num) \
        { \
            LIST.clear(list); \
            MEMORY.release(list); \
            __m_exit(eMEMORY_cantallocate); \
        } \
        LIST.display(list); \
        break;



int main(int argc, char const** argv)
{
    linked_list_s* list = LIST.create();
    if (list == null) { __m_exit(eMEMORY_cantallocate); }
    if (argc <= 1)
    {
        MEMORY.release(list);
        __m_exit(eARGS_insufficient);
    }

    switch (argc - 1)
    {
    _case(01) _case(02) _case(03)
    _case(04) _case(05) _case(06)
    _case(07) _case(08) _case(09)
    _case(0a) _case(0b) _case(0c)
    _case(0d) _case(0e) _case(0f)
    _case(10) _case(11) _case(12) 
    _case(13) _case(14) _case(15)
    _case(16) _case(17) _case(18) 
    _case(19) _case(1a) _case(1b) 
    _case(1c) _case(1d) _case(1e)
    }

    LIST.clear(list);
    MEMORY.release(list);

    return 0;
}

