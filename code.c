#include <stdio.h>
#include <stdlib.h>

struct Node {
    int comp;
    struct Node* next;
};

struct Circuit {
    int n_comp;
    struct Node** connections;
};

struct Circuit* create_circuit(int n_comp) {
    struct Circuit* c = (struct Circuit*)malloc(sizeof(struct Circuit));
    c->n_comp = n_comp;
    c->connections = (struct Node**)malloc(n_comp * sizeof(struct Node*));

    for (int i = 0; i < n_comp; i++) {
        c->connections[i] = NULL;
    }

    return c;
}

void add_con(struct Circuit* c, int comp1, int comp2) {
    struct Node* newNode1 = (struct Node*)malloc(sizeof(struct Node));
    newNode1->comp = comp2;
    newNode1->next = c->connections[comp1];
    c->connections[comp1] = newNode1;

    struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
    newNode2->comp = comp1;
    newNode2->next = c->connections[comp2];
    c->connections[comp2] = newNode2;
}

int detection(struct Circuit* c) {
    int error = 0;

    if (c->n_comp < 2) {
        error = 1;
    }

    for (int i = 0; i < c->n_comp; i++) {
        struct Node* current = c->connections[i];
        while (current != NULL) {
            if (current->comp == i) {
                error = 1;
                break;
            }
            current = current->next;
        }
        if (error) {
            break;
        }
    }

    int n_connected = 0;
    struct Node* current = c->connections[1];
    while (current != NULL) {
        n_connected++;
        current = current->next;
    }

    if (n_connected != 2) {
        error = 2;
    }

    return error;
}

void circ_mem(struct Circuit* c) {
    for (int i = 0; i < c->n_comp; i++) {
        struct Node* current = c->connections[i];
        while (current != NULL) {
            struct Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(c->connections);
    free(c);
}

int main() {
    int n_comp;
    printf("Enter the number of components in the circuit: ");
    scanf("%d", &n_comp);

    struct Circuit* c = create_circuit(n_comp);

    int n_connection;
    printf("Enter the number of connections in the circuit: ");
    scanf("%d", &n_connection);

    if (n_comp < n_connection) {
        printf("Error in the circuit!\n");
        return 0;
    }

    for (int i = 0; i < n_connection; i++) {
        int comp1, comp2;
        printf("Enter connection %d (component1 component2): ", i + 1);
        scanf("%d %d", &comp1, &comp2);
        add_con(c, comp1, comp2);
    }

    int error = detection(c);

    if (error) {
        printf("Error in the circuit!\n");
    } else {
        printf("No errors detected in the circuit.\n");
    }

    circ_mem(c);

    return 0;
}
