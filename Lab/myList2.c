#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int *list;
}
LIST;

LIST* create_list(void)
{
    LIST* L;
    L->size = 0;
    L->list = NULL;
    return L;

}

/*
void print_list(LIST* L)
{
    for (int i = 0; i < L->size; i++)
    {
        printf("%d ", L->list[i]);
    }
    printf("\n");
}

void append(LIST* L, int a)
{
    L->list = realloc(L->list, (L->size + 1) * sizeof(int));
    L->list[L->size] = a;
    L->size = L->size + 1;
    // return L;
}

// LIST prepend(LIST L, int a)
// {
//     L.list = realloc(L.list, (L.size + 1) * sizeof(int));

//     for (int i = L.size - 1; i >= 0; i--)
//     {
//         L.list[i + 1] = L.list[i];
//     }
//     L.list[0] = a;

//     L.size = L.size + 1;

//     return L;
// }

// LIST deletelast(LIST L)
// {
//     L.list = realloc(L.list, (L.size - 1) * sizeof(int));
//     L.size = L.size - 1;
//     return L;
// }

// LIST deletefirst(LIST L)
// {
//     for (int i = 1; i < L.size; i++)
//     {
//         L.list[i-1] = L.list[i];
//     }
//     L.list = realloc (L.list, (L.size - 1) * sizeof(int));
//     L.size = L.size - 1;
//     return L;
// }

// LIST deleteall(LIST L)
// {
//     free(L.list);
//     L.list = NULL;
//     L.size = 0;
// }

*/

int main()
{
    LIST* L = create_list();
    // append(L, 9);
    // append(L, 1);
    // append(L, 2);
    // append(L, 3);
    // append(L, 6);
    // append(L, 7);
    // append(L, 8);
    // append(L, 4);
    // append(L, 2);
    // append(L, 3);
    // L = prepend(L, 9);
    // L = prepend(L, 9);
    // L = prepend(L, 9);
    // L = prepend(L, 9);
    // L = prepend(L, 9);
    // L = prepend(L, 9);
    // L = prepend(L, 9);
    // L = prepend(L, 9);
    // L = prepend(L, 9);
    // L = prepend(L, 9);
    // print_list(L);
    // L = deletelast(L);
    // print_list(L);
    // L = deletefirst(L);
    // print_list(L);
    // L = deleteall(L);
    // print_list(L);
}
