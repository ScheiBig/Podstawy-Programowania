#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define __discard_stdin__
#include "my_utils.h"
#include "my_exit.h"
#include "my_file.h"

void filecpy(FILE* in, FILE* out);

int main()
{
    register_exit_handler(close_file_pointers); // ta funkcja rejestruje funkcję do zamykania plików ze stosu na stos funkcji czyszczących
                                                // (Moje makra _*h_exit() wywołują zarejestrowane funkcje zamykające zaraz przed return,
                                                //  w tym przypadku będzie to zamykanie plików których otwarcie zapisuję na stosie)
    char buffer[31];

    print_ln("Enter input file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%30s", buffer) != 1)
    {
        _mh_exit(eFILE_noaccess, eFILE_noaccess_msg)
    }
    discard_stdin(); // <- po skanfie jeśli była dłuższa nazwa, to są resztki w buforze, ta funkcja to tak na prawdę `while(getchar() != '\n')`

    FILE* in_file = register_file_pointer(fopen(buffer, "r")); // register_file_pointer odkłada plik na stos i wzraca wskaźnik do niego
                                                               // (Wykładowcy go nienawidzą, odkrył jeden prosty trick na
                                                               //  prostą kontrolę zasobów)
    
    if (in_file == NULL)
    {
        _mh_exit(eFILE_noaccess, eFILE_noaccess_msg) // te makro drukuje błąd wczytania pliku, 
                                                     // zamyka pliki na stosie (żaden na razie) i return 4
            
    }

    print_ln("Enter output file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%30s", buffer) != 1)
    {
        _mh_exit(eFILE_cantcreate, eFILE_cantcreate_msg)
    }

    FILE* out_file = register_file_pointer(fopen(buffer, "w"));
    if (out_file == NULL)
    {
        _mh_exit(eFILE_cantcreate, eFILE_cantcreate_msg) // te makro drukuje błąd utworzenia pliku, 
                                                         // zamyka pliki na stosie(in_file <- plik jest teraz już otwarty),
                                                         // return 5
            
    }

    filecpy(in_file, out_file); // <- przeniosłem kopiowanie do funkcji, jakby miało się potem przydać

    print_ln("File copied");
    _h_exit() // te makro zamyka pliki na stosie (out_file oraz in_file) i return 0
}

void filecpy(FILE* in, FILE* out)
{
    int c;
    while ((c = fgetc(in)) != EOF)
    {
        fputc(c, out);
    }
}
