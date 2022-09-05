#pragma once

#include "my_utils_v3.h"

typedef struct stack_t
{
    cstring sentence;
    struct stack_t* prev;
} stack_s;

/*
Funkcja kładzie element o wartości value na stosu stack. Po położeniu elementu na stos funkcja modyfikuje
wskaźnik *stack tak, aby wskazywał na nowy wierzchołek.

Funkcja nie wykonuje kopii tekstu value (po prostu przypisuje value do sentence).

Funkcja zwraca:

0 w przypadku sukcesu,
1 w przypadku błędnych danych wejściowych lub
2 jeżeli nie uda się przydzielić pamięci.
*/
int stack_push(stack_s** stack, cstring value);

/*
Funkcja zdejmuje ze stosu stack ostatni dodany element i zwraca jego wartość. Po zdjęciu elementu ze stosu
funkcja modyfikuje wskaźnik *stack tak, aby wskazywał na nowy wierzchołek (lub NULL) jeśli stos jest pusty.

Do zmiennej err_code, o ile to możliwe, zapisany powinien zostać kod błędu:

0 w przypadku sukcesu,
1 w przypadku błędnych danych wejściowych lub pustego stosu.
*/
cstring stack_pop(stack_s** stack, int* err_code);

/*
Funkcja usuwa wszystkie elementy ze stosu stack oraz zwalnia pamięć przydzieloną na teksty przechowywane na stosie.
Ponadto przypisuje wartość NULL pod adres dany wskaźnikiem stack.
*/
void stack_destroy(stack_s** stack);

/*
Funkcja odczytuje zdania z pliku filename i dodaje je do pustego stosu stack. Zdanie kładzione na stos musi
kończyć się kropką.

Funkcja zwraca:

1 w przypadku przekazania błędnych danych,
2 jeżeli nie uda się otworzyć pliku,
3 w przypadku niepowodzenia alokacji pamięci,
0 w przypadku sukcesu.
Funkcja może przydzielić tylko tyle pamięci, ile będzie potrzebne na przechowania danych odczytanych z pliku.

Przykładowe zawartości plików:

Ala.ma.kota. - 3 zadania: "Ala.", "ma.", oraz "kota."
Ala. ma. kota. - 3 zdania: "Ala.", " ma." oraz " kota."
Ala.ma. kota - 2 zdania: "Ala." oraz "ma."
*/
int stack_load(stack_s** stack, c_cstring filename);

/*
Funkcja zapisuje zdania ze stosu do pliku filename.

Funkcja zwraca:

1 w przypadku przekazania błędnych danych,
2 jeżeli nie uda się otworzyć pliku,
0 w przypadku sukcesu.
Ponieważ dane na stosie (teksty) przechowywane są jako zdania (ciągi znaków zakończone kropką),
to funkcja stack_save może zapisywać je do pliku bez żadnych dodatkowych separatorów, np. jako ala.ma.kota.

Oczywiście funkcja stack_load musi uwzględniać ten fakt i rozdzielać zdania kropkami w chwili wczytywania.
*/
int stack_save(const stack_s* stack, c_cstring filename);


/*
 * Funkcja sprawdza czy stos stack jest pusty, zwraca:
 * - 1, jeżeli stos jest pusty,
 * - 0 jeżeli na stosie znajdują się jakieś elementy
 */
int stack_empty(stack_s* stack);

struct stack_i
{
    int (*push) (stack_s** stack, cstring value);
    char* (*pop) (stack_s** stack, int* err_code);
    void (*destroy) (stack_s** stack);
    int (*load) (stack_s** stack, c_cstring filename);
    int (*save) (const stack_s* stack, c_cstring filename);
    int (*empty) (stack_s* stack);
};

extern const struct stack_i STACK;