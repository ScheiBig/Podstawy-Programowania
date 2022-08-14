#pragma once

typedef struct node_t
{
    int data;
    struct node_t* next;
} s_node;

typedef s_node* p_node;

typedef struct stack_t
{
    p_node head;
} s_stack;

typedef s_stack* p_stack;
typedef const s_stack* pc_stack;

/*
 * Funkcja przydziela pamięć na strukturę stack_t i inicjuje jej pola odpowiednimi wartościami.
 *
 * Funkcja zwraca wartość:
 * - 1 w przypadku przekazania błędnych danych,
 * - 2 w przypadku niepowodzenia alokacji pamięci lub
 * - 0 w przypadku sukcesu.
 */
int stack_init(p_stack* stack);

/*
 * Funkcja dodaje element o wartości value do stosu stack.
 *
 * Zwraca:
 * - 0 w przypadku sukcesu,
 * - 1 w przypadku błędnych danych wejściowych lub
 * - 2 jeżeli nie uda się przydzielić pamięci.
 */
int stack_push(p_stack stack, int value);

/*
 * Funkcja wyświetla wszystkie elementy ze stosu stack, w jednym wierszu, oddzielone spacjami. Pierwszym wyświetlonym elementem ma być ostatni dodany na stos.
 *
 * W przypadku błędnych danych funkcja nie podejmuje żadnej akcji.
 */
void stack_display(pc_stack stack);

/*
 * Funkcja zdejmuje ostatnio dodany element ze stosu stack zwracając jego wartość. W przypadku błędu zwracana wartość jest nieistotna.
 *
 * Do zmiennej err_code, o ile to możliwe, zapisany powinien zostać kod błędu:
 * - 0 w przypadku sukcesu,
 * - 1 w przypadku błędnych danych wejściowych lub pustego stosu.
 */
int stack_pop(p_stack stack, int* err_code);

/*
 * Funkcja usuwa wszystkie elementy z listy stack oraz zwalnia pamięć całego stosu. Ostatecznie funkcja zapisuje NULL pod przekazany adres.
 *
 * W przypadku błędnych danych funkcja nie podejmuje żadnej akcji.
 */
void stack_destroy(p_stack* stack);

/*
 * Funkcja sprawdza czy stos stack jest pusty, zwraca:
 * - 1, jeżeli stos jest pusty,
 * - 0 jeżeli na stosie znajdują się jakieś elementy lub
 * - 2 w przypadku błędnych danych wejściowych.
 */
int stack_empty(pc_stack stack);

struct stack_i
{
    int (*init) (p_stack* stack);
    int (*push) (p_stack stack, int value);
    void (*display) (pc_stack stack);
    int (*pop) (p_stack stack, int* err_code);
    void (*destroy) (p_stack* stack);
    int (*empty) (pc_stack stack);
};

extern const struct stack_i STACK;
