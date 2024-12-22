#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Define constants
#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define DB_FILENAME "data/contacts.db"

// Define a structure to store contact information
typedef struct
{
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

// Global variables
Contact contacts[MAX_CONTACTS];
int contact_count = 0;
sqlite3 *db;
char *err_msg = 0;

// Function prototype
void add_contact(void);
void list_contacts(void);
void update_contact(void);
void destroy_contact(void);
void save_contacts(void);
void load_contacts(void);
void show_menu(void);
void connect_to_db(void);
void disconnect_from_db(void);
void create_table(void);

// 連絡先を追加
void add_contact()
{
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO contacts (name, phone, email) VALUES (?, ?, ?);";

    // プリペアードステートメントを準備
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    // ユーザー入力を取得
    char name[100];
    char phone[15];
    char email[100];

    // 入力バッファをクリアして、前回の入力の残りを削除
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // 何もしない
    }

    printf("Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // 改行削除

    printf("Phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0'; // 改行削除

    printf("Email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0'; // 改行削除

    // validationを追加したい

    // 値をバインド
    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, phone, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, email, -1, SQLITE_STATIC);

    // ステートメントを実行
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        printf("Contact added successfully!\n");
    }

    // ステートメントを解放
    sqlite3_finalize(stmt);
}

// 連絡先を一覧表示
void list_contacts()
{
    const char *sql = "SELECT * FROM contacts;";
    sqlite3_stmt *stmt;

    // プリペアードステートメントを準備
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    // 
    printf("\n=== 連絡先一覧 ===\n");
    printf("ID\tName\t\tPhone\t\tEmail\n");
    printf("--------------------------------------------\n");

    // 結果セットを繰り返し取得して表示
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);                           // IDカラム
        const char *name = (const char *)sqlite3_column_text(stmt, 1);  // Nameカラム
        const char *phone = (const char *)sqlite3_column_text(stmt, 2); // Phoneカラム
        const char *email = (const char *)sqlite3_column_text(stmt, 3); // Emailカラム

        printf("%d\t%-10s\t%-15s\t%s\n", id, name, phone, email);
    }

    if (rc != SQLITE_DONE)
    {
        fprintf(stderr, "Failed to retrieve data: %s\n", sqlite3_errmsg(db));
    }

    // ステートメントを解放
    sqlite3_finalize(stmt);
}

void update_contact()
{
    sqlite3_stmt *stmt;
    const char *sql = "UPDATE contacts SET name = ?, phone = ?, email = ? WHERE id = ?;";

    // プリペアードステートメントを準備
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    // ユーザー入力を取得
    int id;
    char name[100];
    char phone[15];
    char email[100];

    printf("Enter ID of the contact to update: ");
    scanf("%d", &id);

    // 入力バッファをクリアして、前回の入力の残りを削除
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // 何もしない
    }

    printf("New Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // 改行削除

    printf("New Phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0'; // 改行削除

    printf("New Email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0'; // 改行削除

    // validationを追加したい

    // 値をバインド
    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, phone, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, email, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, id);

    // ステートメントを実行
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        printf("Contact updated successfully!\n");
    }

    // ステートメントを解放
    sqlite3_finalize(stmt);
}

void destroy_contact()
{
    sqlite3_stmt *stmt;
    const char *sql = "DELETE FROM contacts WHERE id = ?;";

    // プリペアードステートメントを準備
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    // ユーザー入力を取得
    int id;
    printf("Enter ID of the contact to delete: ");
    scanf("%d", &id);

    // 値をバインド
    sqlite3_bind_int(stmt, 1, id);

    // ステートメントを実行
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        printf("Contact deleted successfully!\n");
    }

    // ステートメントを解放
    sqlite3_finalize(stmt);
}

// データをファイルに保存
// void save_contacts()
// {
//     FILE *file = fopen("data/contacts.txt", "w");
//     if (file == NULL)
//     {
//         printf("ファイルの保存に失敗しました\n");
//         return;
//     }

//     for (int i = 0; i < contact_count; i++)
//     {
//         fprintf(file, "%s,%s,%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
//     }

//     fclose(file);
//     printf("データを保存しました\n");
// }

// データをファイルから読み込む
// void load_contacts()
// {
//     FILE *file = fopen("data/contacts.txt", "r");
//     if (file == NULL)
//     {
//         printf("保存されたデータはありません\n");
//         return;
//     }

//     contact_count = 0;

//     while (fscanf(file, "%49[^,],%19[^,],%49[^\n]\n",
//                   contacts[contact_count].name,
//                   contacts[contact_count].phone,
//                   contacts[contact_count].email) != EOF)
//     {
//         contact_count++;
//     }

//     fclose(file);
//     printf("データを読み込みました\n");
// }

void show_menu(void)
{
    printf("\n=== 連絡先管理アプリ ===\n");
    printf("1. 連絡先を追加\n");
    printf("2. 連絡先を一覧表示\n");
    // printf("3. 連絡先を検索\n");
    printf("7. 連絡先を更新\n");
    printf("4. 連絡先を削除\n");
    // printf("5. データを保存\n");
    printf("6. 終了\n");
    printf("\nSelect menu number: ");
}

// SQLite3のデータベースに接続
void connect_to_db()
{
    int rc = sqlite3_open(DB_FILENAME, &db);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
    }
    else
    {
        printf("Database opened successfully.\n");
    }
};

// SQLite3のデータベースから切断
void disconnect_from_db()
{
    if (db)
    {
        sqlite3_close(db);
        printf("Database connection closed.\n");
    }
};

// SQLite3のデータベースにテーブルを作成
void create_table(void)
{
    char *sql = "CREATE TABLE IF NOT EXISTS contacts ("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "name TEXT NOT NULL,"
                "phone TEXT,"
                "email TEXT NOT NULL);";

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    else
    {
        printf("Table created successfully.\n");
    }
};

// ==== Main function ====
int main(void)
{
    connect_to_db();
    create_table();

    int is_running = 1;

    // 起動時のデータ読み込み
    // load_contacts();

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
        case 7:
            update_contact();
            break;
        case 4:
            destroy_contact();
            break;
        // case 5:
        //     save_contacts();
        //     break;
        case 6:
            // save_contacts();
            disconnect_from_db();
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