#include <stdio.h>
#define n 10

typedef struct
{
    int key;
    int value;
} HT;

HT hashTable[n];

int hashFunction(int key)
{
    return key % n;
}

void initTable()
{
    for (int i = 0; i < n; i++)
    {
        hashTable[i].key = -1;
        hashTable[i].value = 0;
    }
}

void insert(int key, int value)
{
    int index = hashFunction(key);
    if (hashTable[index].key == -1)
    {
        hashTable[index].key = key;
        hashTable[index].value = value;
    }
    else
    {
        int flag = 0;
        for (int i = index; i < n; i++)
        {
            if (hashTable[i].key == -1)
            {
                hashTable[i].key = key;
                hashTable[i].value = value;
                // also update value
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            for (int i = 0; i < index; i++)
            {
                if (hashTable[i].key == -1)
                {
                    hashTable[i].key = key;
                    hashTable[i].value = value;
                    // also update value
                    break;
                }
            }
        }
    }
}

void main()
{
    initTable();
    int key[2] = {12, 122};
    int val[2] = {10, 4};
    for (int i = 0; i < 2; i++)
    {
        insert(key[i], val[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("key : %d & value : %d \n", hashTable[i].key, hashTable[i].value);
    }
}