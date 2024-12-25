#include "../../include/plugin.h" // 共通ヘッダファイル
#include "./tasks.h"              // 固有ヘッダファイル

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#define FILE_PATH "./data/tasks.xml"

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

void get_user_choice(int *choice)
{
    scanf("%d", choice);
    getchar(); // 改行文字を取得（バッファをクリア）
}

// XMLファイルを読み込む
xmlDocPtr load_xml_file()
{
    xmlDocPtr doc = xmlParseFile(FILE_PATH); // XMLファイルをパース（解析）
    if (doc == NULL)
    {
        printf("XML file is missing. New file will be created\n");
        doc = xmlNewDoc(BAD_CAST "1.0");

        xmlNodePtr root = xmlNewNode(NULL, BAD_CAST "tasks");
        xmlDocSetRootElement(doc, root);

        xmlSaveFormatFileEnc(FILE_PATH, doc, "UTF-8", 1);
    }
    return doc;
}

void list_tasks(void)
{
    xmlDocPtr doc = load_xml_file();
    xmlNodePtr root = xmlDocGetRootElement(doc);
    xmlNodePtr task = root->children;

    printf("\n=== Task List ===\n");
    while (task != NULL)
    {
        if (task->type == XML_ELEMENT_NODE && strcmp((char *)task->name, "task") == 0)
        {
            xmlChar *id = xmlGetProp(task, BAD_CAST "id");
            xmlChar *title = xmlNodeGetContent(task->children);
            printf("[%s] %s\n", id, title);

            // ProtoType: void xmlFree(void *mem)
            // mem: ptr to memory to free 
            xmlFree(id);
            xmlFree(title);
        }
        task = task->next;
    }
    printf("=================\n");

    xmlFreeDoc(doc);
}

void add_task(void)
{
    char title[128];
    printf("Input a title of task: ");
    fgets(title, sizeof(title), stdin);
    title[strlen(title) - 1] = '\0'; // 改行文字を削除

    // xmlDocPtr: XML Document Pointer
    xmlDocPtr doc = load_xml_file(); // XMLファイルのポインタを取得

    xmlNodePtr root = xmlDocGetRootElement(doc); // ルートノードを取得

    int task_id = 1;
    xmlNodePtr task = root->children;
    while (task != NULL)
    {
        if (task->type == XML_ELEMENT_NODE && strcmp((char *)task->name, "task") == 0)
        {
            task_id++;
        }
        task = task->next;
    }

    // 新しいタスクノードを作成
    xmlNodePtr new_task = xmlNewChild(root, NULL, BAD_CAST "task", NULL);
    char id_str[10];
    sprintf(id_str, "%d", task_id);
    xmlNewProp(new_task, BAD_CAST "id", BAD_CAST id_str);

    xmlNodePtr title_node = xmlNewChild(new_task, NULL, BAD_CAST "title", BAD_CAST title);

    // ファイルに保存
    // int format (1: 整形（インデント）する, 0: 整形しない)
    xmlSaveFormatFileEnc(FILE_PATH, doc, "UTF-8", 1);

    printf("Added new task successfully\n");

    xmlFreeDoc(doc);
}

void run(void)
{
    // XMLの整形を有効にする
    xmlIndentTreeOutput = 1; // インデントを有効にする
    xmlKeepBlanksDefault(0); // 空白を削除する

    bool is_running = true; // アプリケーションの実行フラグ

    while (is_running)
    {
        show_menu();

        int choice;
        get_user_choice(&choice);

        switch (choice)
        {
        case 1: // List tasks
            list_tasks();
            break;
        case 2: // Add a new task
            add_task();
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
