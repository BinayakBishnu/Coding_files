#include <stdio.h>
#include <math.h>

#define size 10

int hash_table[size] = {NULL};

int isPrime(int n)
{
    int i = 0;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int greatestPrime(int x)
{
    int i = 0;
    int g = 0;
    for (i = 2; i < x; i++)
    {
        if (isPrime(i) == 1)
            g = i;
    }
    return g;
}

void insert()
{
    int key;
    int index, h_key;

    printf("Enter value to be inserted: ");
    scanf(" %d", &key);

    h_key = key % size; // ideal position
    int p = greatestPrime(size);
    int h_key2 = p - (key % p);

    int i;
    for (i = 0; i < size; i++)
    {
        index = (h_key + i * h_key2) % size; //alternative position
        //*starts with ideal position

        if (hash_table[index] == NULL)
        {
            hash_table[index] = key;
            break;
        }
    }
    if (i == size)
    {
        printf("\nCannot insert anymore\n");
    }
}

void search()
{
    int key, h_key, index;

    printf("Enter value to be searched for: ");
    scanf(" %d", &key);

    h_key = key % size; //ideal position to be found at
    int p = greatestPrime(size);
    int h_key2 = p - (key % p);

    int i;
    for (i = 0; i < size; i++)
    {
        index = (h_key + i * h_key2) % size;

        if (hash_table[index] == key)
        {
            printf("Found at: %d\n", index);
            break;
        }
    }
    if (i == size)
    {
        printf("\nNot found\n");
    }
}

void display()
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
        printf("%d. %d\n", i, hash_table[i]);
    }
    printf("%d. %d\n", i, hash_table[i]);
}

int main()
{
    // printf("%d", greatestPrime(10));

    int choice = 1;

    while (1)
    {
        printf("1. Add\n2. Search\n3. Display\n4. Exit\n");
        scanf(" %d", &choice);

        if (choice == 1)
        {
            insert();
        }
        else if (choice == 2)
        {
            search();
        }
        else if (choice == 3)
        {
            display();
        }
        else
        {
            break;
        }
    }

    return 0;
}