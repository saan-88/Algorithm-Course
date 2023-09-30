#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int size;
    char** list;
}
LIST;

LIST create_list(void)
{
    LIST L;
    L.size = 0;
    L.list = NULL;
    return L;
}

LIST append(LIST L, char *a)
{
    L.list = (char **) realloc (L.list, (L.size + 1) * sizeof(char *));
    L.list[L.size] = (char *) calloc (10, sizeof(char));
    strcpy(L.list[L.size], a);
    L.size++;
    return L;
}

LIST prepend(LIST L, char *a)
{
    L.list = (char **) realloc (L.list, (L.size + 1) * sizeof(char *));
    L.list[L.size] = (char *) calloc (10, sizeof(char));
    for (int j = L.size; j >= 1; j--)
    {
        strcpy(L.list[j], L.list[j-1]);
    }
    strcpy(L.list[0], a);
    L.size++;
    return L;
}

void print_list(LIST L)
{
    for (int i = 0; i < L.size; i++)
    {
        printf("%s ", L.list[i]);
    }
    printf("\n");
}

LIST deletelast(LIST L)
{
    L.list = (char **) realloc (L.list, (L.size - 1) * sizeof(char *));
    L.size--;
    return L;
}

LIST deletefirst(LIST L)
{
    for (int i = 0; i < L.size - 1; i++)
    {
        strcpy(L.list[i], L.list[i+1]);
    }
    L.list = (char **) realloc (L.list, (L.size - 1) * sizeof(char *));
    L.size--;
    return L;
}

LIST deleteall(LIST L, char *a)
{
    int n = 0;
    for (int i = 0; i < L.size; i++)
    {
        if (strcmp(L.list[i], a) != 0)
        {
            n++;
        }
    }
    LIST L1;
    L1.size = n;
    L1.list = (char **) malloc (n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        L1.list[i] = (char *) calloc (10, sizeof(char));
    }
    int l1 = 0;
    for (int i = 0; i < L.size; i++)
    {
        if (strcmp(L.list[i], a) != 0)
        {
            strcpy(L1.list[l1], L.list[i]);
            l1++;
        }
    }
    
    // Freeing allocated memory
    for (int i = 0; i < L.size; i++)
    {
        free(L.list[i]);
    }
    free(L.list);

    return L1;
}

int main()
{
    LIST L = create_list();
    L = append(L, "apple");
    L = append(L, "lemon");
    L = append(L, "banana");
    L = append(L, "pear");
    L = append(L, "pineapple");
    L = append(L, "mango");
    L = append(L, "orange");
    L = prepend(L, "apple");
    L = prepend(L, "banana");
    L = prepend(L, "pear");
    L = append(L, "pear");
    L = deletefirst(L);
    L = deletelast(L);
    L = deleteall(L, "apple");

    print_list(L);
    // printf("%s %s %d", L.list[0], L.list[1], L.size);
}