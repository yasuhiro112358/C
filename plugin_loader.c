#include "plugin_loader.h"
#include <stdio.h>
#include <dlfcn.h>   // 動的ライブラリ（DL）用ヘッダー

void load_and_run_plugin(const char *plugin_name) {
    char path[256];

    // .soのパスを取得
    // Prototype: int snprintf(char *str, size_t size, const char *format, ...)
    // pathにプラグインのパスを書き込む
    snprintf(path, sizeof(path), "./plugins/%s/lib%s.so", plugin_name, plugin_name);

    // プラグインをロード
    // Prototype: void *dlopen(const char *filename, int flag)
    // RTLD_LAZY: 関数が呼び出された時に初めて関数をロードする
    void *handle = dlopen(path, RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "プラグインのロードに失敗: %s\n", dlerror());
        return;
    }

    // プラグインのエントリーポイント（シンボル：関数）を取得
    // Prototype: void *dlsym(void *handle, const char *symbol)
    // void (*run)()は関数ポインタ
    void (*run)() = dlsym(handle, "run");
    if (!run) { // 関数ポインタがNULLの場合
        // Prototype: const char *dlerror(void)
        fprintf(stderr, "プラグインのエントリーポイントが見つかりません: %s\n", dlerror());
        dlclose(handle); // プラグインをアンロード
        return;
    }

    // プラグインの実行
    run(); // 関数ポインタを呼び出す

    // プラグインをアンロード
    // Prototype: int dlclose(void *handle)
    dlclose(handle);
}
