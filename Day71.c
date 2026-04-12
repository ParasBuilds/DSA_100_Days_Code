#include <stdio.h>
#include <string.h>

#define MAX 100
#define EMPTY -1

int table[MAX];   // hash table
int m;            // table size

// ───── Hash Function ─────
int hash(int key) {
    return key % m;
}

// ───── Insert using Quadratic Probing ─────
void insert(int key) {
    int h0 = hash(key);   // base hash

    for (int i = 0; i < m; i++) {
        int idx = (h0 + i * i) % m;   // quadratic probe

        if (table[idx] == EMPTY) {    // empty slot found
            table[idx] = key;
            return;
        }

        if (table[idx] == key) {      // already exists
            return;
        }
    }

    // Table full or all probes failed
    printf("Table is full!\n");
}

// ───── Search using Quadratic Probing ─────
void search(int key) {
    int h0 = hash(key);

    for (int i = 0; i < m; i++) {
        int idx = (h0 + i * i) % m;

        if (table[idx] == key) {      // key found!
            printf("FOUND\n");
            return;
        }

        if (table[idx] == EMPTY) {    // empty slot → key not present
            printf("NOT FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");   // all probes exhausted
}

// ───── Main ─────
int main() {
    int q;
    scanf("%d %d", &m, &q);   // table size, queries

    // Initialize table with EMPTY
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    for (int i = 0; i < q; i++) {
        char op[10];
        int  key;
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0)
            insert(key);
        else if (strcmp(op, "SEARCH") == 0)
            search(key);
    }

    return 0;
}