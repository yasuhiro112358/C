#include "./include/plugin_loader.h"
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int choice;
    bool is_running = true;

    do
    {
        printf("\n=== Main Menu ===\n");
        printf("1. Contacts\n");
        printf("2. Calculator\n");
        printf("3. Tasks\n");
        printf("0. Close the app\n");
        printf("\nSelect menu number: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            load_and_run_plugin("contacts");
            break;
        case 2:
            load_and_run_plugin("calculator");
            break;
        case 3:
            load_and_run_plugin("tasks");
            break;
        case 0:
            printf("Closing the app...\n");
            is_running = false;
            break;
        default:
            printf("Invalid selection\n");
            break;
        }
    } while (is_running);

    return 0;
}