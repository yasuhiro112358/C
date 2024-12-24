#include <stdio.h>
#include <stdbool.h>
#include "plugin_loader.h"

int main(void)
{
    int choice;
    bool is_running = true;

    do
    {
        printf("\n=== メインメニュー ===\n");
        printf("1. 計算機\n");
        printf("2. 連絡先管理\n");
        printf("3. データベース操作\n");
        printf("4. 終了\n");
        printf("選択肢を入力してください: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            load_and_run_plugin("calculator");
            break;
        case 2:
            // load_and_run_plugin("contacts");
            break;
        case 3:
            // load_and_run_plugin("database");
            break;
        case 4:
            printf("終了します\n");
            is_running = false;
            break;
        default:
            printf("無効な選択です\n");
            break;
        }
    } while (is_running);

    return 0;
}