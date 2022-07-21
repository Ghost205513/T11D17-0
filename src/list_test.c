#include "list.h"
#include <stdio.h>

int add_door_test();
int remove_door_test();
void print_nodes(struct node *root);

int main() {
    printf("test function add_door:");
    if (add_door_test() == 0)
        printf("SUCCESS");
    else
        printf("FAIL");
    printf("\ntest function remove_door:");
    if (remove_door_test() == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

int add_door_test() {
    struct door *door = malloc(sizeof(struct door));
    struct node *list;
    int flag = 0;

    door->id = 12;
    door->status = 0;

    list = add_door(NULL, door);

    if (!list || list->next || list->data->id != door->id || list->data->status != door->status) {
        flag = 1;
    } else {
        struct node *temp = add_door(list, NULL);

        if (temp) {
            flag = 1;
        } else {
            struct door *door1 = malloc(sizeof(struct door));
            struct node *temp = add_door(list, door1);

            door->id = 15;
            door->status = 1;

            if (!temp || temp->next || temp->data->id != door1->id || temp->data->status != door1->status)
                flag = 1;

            free(door1);
        }
    }

    free(door);
    destroy(list);

    return flag;
}

int remove_door_test() {
    struct door *door = malloc(sizeof(struct door)), *door1 = malloc(sizeof(struct door));
    struct node *list, *list1;
    int flag = 0;

    door->id = 12;
    door->status = 0;
    door1->id = 15;
    door1->status = 1;

    list = add_door(NULL, door);
    list1 = add_door(list, door1);


    if (remove_door(list1, NULL)) {
        flag += 1;
    } else {
        if (remove_door(NULL, list) != list) {
            flag += 2;
        } else {
            list = remove_door(list1, list);
            if (list->next) {
                flag += 4;
            } else {
                if (remove_door(list, list)) {
                    flag += 8;
                }
            }
        }
    }

    free(door);
    free(door1);

    return flag;
}
