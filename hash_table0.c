#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define NAME_SIZE 50

typedef struct {
    char name[NAME_SIZE];
    int occupied; // 0 if empty, 1 if occupied
} HashEntry;

typedef struct {
    HashEntry table[TABLE_SIZE];
} HashTable;

// Function to create a hash table
HashTable* createTable() {
    HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        newTable->table[i].occupied = 0;
    }
    return newTable;
}

// Hash function
unsigned int hash(const char* key) {
    unsigned int hash = 0;
    while (*key) {
        hash += *key++;
    }
    return hash % TABLE_SIZE;
}

// Function to add an element to the hash table
void addElement(HashTable* table, const char* name) {
    unsigned int index = hash(name);
    strcpy(table->table[index].name, name);
    table->table[index].occupied = 1;
    printf("Hashing \"%s\" => %u\n", name, index);
}

// Function to print the hash table
void printTable(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Índice %d: ", i);
        if (table->table[i].occupied) {
            printf("[%s]\n", table->table[i].name);
        } else {
            printf("NULL\n");
        }
    }
}

// Menu for interacting with the user
void menu() {
    HashTable* table = createTable();
    int choice;
    char name[NAME_SIZE];

    do {
        printf("\n1. Agregar elemento\n");
        printf("2. Mostrar tabla hash\n");
        printf("3. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Introduce el nombre: ");
                scanf("%s", name);
                addElement(table, name);
                break;
            case 2:
                printTable(table);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (choice != 3);

    free(table);
}

int main() {
    menu();
    return 0;
}
