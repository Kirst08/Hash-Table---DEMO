#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define NAME_SIZE 50

typedef struct {
    char name[NAME_SIZE];
    char phone[20];
    int age;
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
void addElement(HashTable* table, const char* name, const char* phone, int age) {
    unsigned int index = hash(name);

    strcpy(table->table[index].name, name);
    strcpy(table->table[index].phone, phone);
    table->table[index].age = age;
    table->table[index].occupied = 1;
    
    printf("Hashing \"%s\" => %u\n", name, index);
}

// Function to remove an element from the hash table
void removeElement(HashTable* table, const char* name) {
    unsigned int index = hash(name);

    if (table->table[index].occupied && strcmp(table->table[index].name, name) == 0) {
        table->table[index].occupied = 0;
        printf("Elemento eliminado.\n");
    } else {
        printf("Elemento no encontrado.\n");
    }
}

// Function to update an element in the hash table
void updateElement(HashTable* table, const char* name, const char* phone, int age) {
    addElement(table, name, phone, age);
}

// Function to print the hash table
void printTable(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Índice %d: ", i);
        if (table->table[i].occupied) {
            printf("[%s - Tel: %s, Edad: %d]\n", table->table[i].name, table->table[i].phone, table->table[i].age);
        } else {
            printf("NULL\n");
        }
    }
}

// Menu for interacting with the user
void menu() {
    HashTable* table = createTable();
    int choice;
    char name[NAME_SIZE], phone[20];
    int age;

    do {
        printf("\n1. Agregar elemento\n");
        printf("2. Eliminar elemento\n");
        printf("3. Modificar elemento\n");
        printf("4. Mostrar tabla hash\n");
        printf("5. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Introduce el nombre: ");
                scanf("%s", name);
                printf("Introduce el teléfono: ");
                scanf("%s", phone);
                printf("Introduce la edad: ");
                scanf("%d", &age);
                addElement(table, name, phone, age);
                break;
            case 2:
                printf("Introduce el nombre del elemento a eliminar: ");
                scanf("%s", name);
                removeElement(table, name);
                break;
            case 3:
                printf("Introduce el nombre del elemento a modificar: ");
                scanf("%s", name);
                printf("Introduce el nuevo teléfono: ");
                scanf("%s", phone);
                printf("Introduce la nueva edad: ");
                scanf("%d", &age);
                updateElement(table, name, phone, age);
                break;
            case 4:
                printTable(table);
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (choice != 5);

    free(table);
}

int main() {
    menu();
    return 0;
}
