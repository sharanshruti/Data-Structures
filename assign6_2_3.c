#include <stdio.h>
#include<stdlib.h>
//Double Hashing

#define TABLE_SIZE 12

int h[TABLE_SIZE]={NULL};

void insert()
{

 int key,index,i,flag=0,h1_key,h2_key;
 printf("\n Enter a value to insert into hash table\n");
 scanf("%d",&key);
 h1_key = key % TABLE_SIZE;
 h2_key = 3 - (key % 3);
 for(i = 0;i < TABLE_SIZE;i++)
    {

     index =(h1_key + i*h2_key) % TABLE_SIZE;

     if(h[index] == NULL)
     {
        h[index] = key;
         break;
     }

    }

    if(i == TABLE_SIZE)

     printf("\n Element cannot be inserted\n");
}
void search()
{

 int key,index,i,flag=0,h1_key,h2_key;
 printf("\n Enter search element\n");
 scanf("%d",&key);
 h1_key = key % TABLE_SIZE;
 h2_key = 3 - (key % 3);
 for(i = 0;i < TABLE_SIZE; i++)
 {
    index =(h1_key + i*h2_key) % TABLE_SIZE;
    if(h[index] == key)
    {
      printf("value is found at index %d",index);
      break;
    }
  }
  if(i == TABLE_SIZE)
    printf("\n value is not found\n");
}
void display()
{

  int i;

  printf("\n Elements in the hash table are \n");

  for(i = 0;i < TABLE_SIZE; i++)

  printf("\n At index %d \t value =  %d",i,h[i]);

}


void delete()
{

 int key,index,i,flag=0,h1_key,h2_key;
 printf("\n Enter a value to be deleted from hash table\n");
 scanf("%d",&key);
 h1_key = key % TABLE_SIZE;
 h2_key = 3 - (key % 3);
 for(i=0;i < TABLE_SIZE;i++)
    {

     index =(h1_key + i*h2_key) % TABLE_SIZE;
     if(h[index] == key)
     {
        h[index] = NULL;
         break;
     }

    }

    if(i == TABLE_SIZE)

     printf("\n Element cannot be deleted\n");
}


int main()
{
    int opt,i;
    while(1)
    {
        printf("\nPress 1. Insert\t 2. Display \t 3. Search \t 4.Delete \t 5.Exit \n");
        scanf("%d",&opt);
        switch(opt)
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
                delete();
                break;
            case 5:exit(0);
        }
    }
}
