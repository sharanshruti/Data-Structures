#include <stdio.h>
#include <stdlib.h>
//Quadratic Probing

#define TABLE_SIZE 12

int h[TABLE_SIZE] ;

void init()
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
        h[i] = NULL;
}

void insert()
{

    int key, index, i, flag = 0, h_key;
    printf("\nEnter a value to insert into hash table\n");
    scanf("%d", &key);
    h_key = key % TABLE_SIZE;
    for (i = 0; i < TABLE_SIZE; i++)
    {

        index = (h_key + i * i) % TABLE_SIZE;

        if (h[index] == NULL)
        {
            h[index] = key;
            break;
        }
    }

    if (i == TABLE_SIZE)

        printf("\nElement cannot be inserted\n");
}
void search()
{

    int key, index, i, flag = 0, h_key;
    printf("\nEnter search element\n");
    scanf("%d", &key);
    h_key = key % TABLE_SIZE;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        index = (h_key + i * i) % TABLE_SIZE;
        if (h[index] == key)
        {
            printf("value is found at index %d", index);
            break;
        }
    }
    if (i == TABLE_SIZE)
        printf("\nvalue is not found\n");
}
void display()
{

    int i;

    printf("\nElements in the hash table are \n");

    for (i = 0; i < TABLE_SIZE; i++)

        printf("\n At index %d \t value =  %d", i, h[i]);
}

void delete ()
{

    int key, index, i, flag = 0, h_key;
    printf("\nEnter a value to be deleted from hash table\n");
    scanf("%d", &key);
    h_key = key % TABLE_SIZE;
    for (i = 0; i < TABLE_SIZE; i++)
    {

        index = (h_key + i * i) % TABLE_SIZE;

        if (h[index] == key)
        {
            h[index] = NULL;
            break;
        }
    }

    if (i == TABLE_SIZE)

        printf("\nElement cannot be deleted\n");
}

int main()
{
    int opt, i;
    while (1)
    {
        printf("\nPress\n 1.Insert\n 2.Print \n 3.Search \n 4.Delete \n 5.Exit \n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            delete ();
            break;
        case 5:
            exit(0);
        }
    }
}
