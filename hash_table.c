#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define NAME_SIZE 50

typedef struct Node {
    char name[NAME_SIZE];
    char phone[20];
    int age;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node* table[TABLE_SIZE];
} HashTable;

// Function to create a new node
Node* createNode(const char* name, const char* phone, int age) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->age = age;
    newNode->next = NULL;
    return newNode;
}

// Function to create a hash table
HashTable* createTable() {
    HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        newTable->table[i] = NULL;
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
    Node* newNode = createNode(name, phone, age);

    if (table->table[index] == NULL) {
        table->table[index] = newNode;
    } else {
        Node* current = table->table[index];
        while (current->next != NULL) {
            if (strcmp(current->name, name) == 0) {
                strcpy(current->phone, phone);
                current->age = age;
                free(newNode);
                return;
            }
            current = current->next;
        }
        if (strcmp(current->name, name) == 0) {
            strcpy(current->phone, phone);
            current->age = age;
            free(newNode);
            return;
        }
        current->next = newNode;
    }
}

// Function to remove an element from the hash table
void removeElement(HashTable* table, const char* name) {
    unsigned int index = hash(name);
    Node* current = table->table[index];
    Node* prev = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Elemento no encontrado.\n");
        return;
    }

    if (prev == NULL) {
        table->table[index] = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    printf("Elemento eliminado.\n");
}

// Function to update an element in the hash table
void updateElement(HashTable* table, const char* name, const char* phone, int age) {
    addElement(table, name, phone, age);
}

// Function to print the hash table
void printTable(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Índice %d: ", i);
        Node* current = table->table[i];
        while (current != NULL) {
            printf("[%s - Tel: %s, Edad: %d] -> ", current->name, current->phone, current->age);
            current = current->next;
        }
        printf("NULL\n");
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

    // Free memory
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table->table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(table);
}

int main() {
    menu();
    return 0;
}
