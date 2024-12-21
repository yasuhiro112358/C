#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int contact_count = 0;



void show_menu(void)
{
    printf("\n=== 連絡先管理アプリ ===\n");
    printf("1. 連絡先を追加\n");
    printf("2. 連絡先を一覧表示\n");
    printf("3. 連絡先を検索\n");
    printf("4. 連絡先を削除\n");
    printf("5. データを保存\n");
    printf("6. 終了\n");
    printf("選択: ");
}

int main(void)
{
    int is_running = 1;
    int choice;

    while (is_running)
    {
        show_menu();
        scanf("%d", &choice);
        // 整数以外の入力があった場合、無限ループになる

        switch (choice)
        {
        case 6:
            printf("アプリを終了します\n");
            is_running = 0;
            break;
        default:
            printf("無効な選択です\n");
            break;
        }
    }

    return 0;
}