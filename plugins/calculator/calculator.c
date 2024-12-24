#include "../../include/plugin.h" // 共通ヘッダファイル
#include "./calculator.h" // 固有ヘッダファイル
#include <stdio.h>


void test(void) {
    printf("テスト関数が呼び出されました\n");
}

void run(void) {
    printf("=== 計算機プラグイン ===\n");
    printf("ここに計算機の処理を実装します。\n");

    test();
}
