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

// 連絡先を追加
void add_contact()
{
    if (contact_count >= MAX_CONTACTS) // 未テスト
    {
        printf("連絡先リストがいっぱいです\n");
        return;
    }

    printf("名前を入力してください: ");
    scanf("%s", contacts[contact_count].name);
    printf("電話番号を入力してください: ");
    scanf("%s", contacts[contact_count].phone);
    printf("メールアドレスを入力してください: ");
    scanf("%s", contacts[contact_count].email);

    contact_count++;
    printf("連絡先が追加されました\n");
}

// 連絡先を一覧表示
void list_contacts()
{
    if (contact_count == 0)
    {
        printf("連絡先が登録されていません\n");
        return;
    }

    printf("=== 連絡先一覧 ===\n");
    for (int i = 0; i < contact_count; i++)
    {
        printf("No.%d 名前: %s, 電話番号: %s, メール: %s\n",
               i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

// データをファイルに保存
void save_contacts() {
    FILE *file = fopen("contacts.txt", "w");
    if (file == NULL) {
        printf("ファイルの保存に失敗しました。\n");
        return;
    }

    for (int i = 0; i < contact_count; i++) {
        fprintf(file, "%s,%s,%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }

    fclose(file);
    printf("データを保存しました\n");
}

// データをファイルから読み込む
void load_contacts() {
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("保存されたデータはありません\n");
        return;
    }

    contact_count = 0;
    while (fscanf(file, "%49[^,],%19[^,],%49[^\n]\n",
                  contacts[contact_count].name,
                  contacts[contact_count].phone,
                  contacts[contact_count].email) != EOF) {
        contact_count++;
    }

    fclose(file);
    printf("データを読み込みました\n");
}

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

    // 起動時のデータ読み込み
    load_contacts();

    int choice;

    while (is_running)
    {
        show_menu();
        scanf("%d", &choice);
        // 整数以外の入力があった場合、無限ループになる

        switch (choice)
        {
        case 1:
            add_contact();
            break;
        case 2:
            list_contacts();
            break;
        case 5:
            save_contacts();
            break;
        case 6:
            save_contacts();
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