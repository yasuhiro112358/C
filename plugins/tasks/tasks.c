#include "../../include/plugin.h" // 共通ヘッダファイル
#include "./tasks.h"              // 固有ヘッダファイル

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

void show_menu(void)
{
    printf("\n=== Task Management App ===\n");
    printf("1. List tasks\n");
    printf("2. Add a new task\n");
    printf("3. Update a task in status\n");
    printf("4. Delete a task\n");
    printf("0. Close the app\n");
    printf("\nSelect the menu #: ");
}

void run(void)
{
#define FILE_PATH "./data/tasks.xml"

    bool is_running = true;
    while (is_running)
    {
        show_menu();

        int choice;
        scanf("%d", &choice);
        getchar(); // 改行文字を取得

        switch (choice)
        {
        case 1:
            // list_tasks(FILE_PATH);
            break;
        case 0:
            printf("Closing the app...\n");
            is_running = false;
            break;
        default:
            printf("Invalid selection\n");
            break;
        }
    }
}
