#include "list.h"
#include <stdlib.h>

struct node *init(struct door *door);
struct node *add_door(struct node *elem, struct door *door);
struct node *find_door(int door_id, struct node *root);
struct node *remove_door(struct node *elem, struct node *root);
void destroy(struct node* root);

struct node *init(struct door *door) {
    struct node *elements = NULL;

    if (door) {
        elements = malloc(sizeof(struct node));
        elements->data = door;
        elements->next = NULL;
    }

    return elements;
}

struct node *add_door(struct node *elem, struct door *door) {
    struct node *new = init(door);

    if (elem && new) {
        new->next = elem->next;
        elem->next = new;
    }

    return new;
}

struct node *find_door(int door_id, struct node *root) {
    struct node *current = root;

    while (current != NULL) {
        if (current->data->id == door_id)
            break;

        current = current->next;
    }

    return current;
}

struct node *remove_door(struct node *elem, struct node *root) {
    struct node *current = root;

    while (current != NULL) {
        if (current->next == elem)
            break;

        current = current->next;
    }

    if (current != NULL && elem != NULL) {
        current->next = elem->next;
        free(elem);
    } else if (elem == root && root != NULL) {
        struct node *next = root->next;
        free(root);
        root = next;
    }

    return root;
}

void destroy(struct node* root) {
    struct node *current = root, *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
