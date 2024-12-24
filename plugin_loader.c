#include "plugin_loader.h"
#include <stdio.h>
#include <dlfcn.h>   // 動的ライブラリ用ヘッダー

void load_and_run_plugin(const char *plugin_name) {
    char path[256];
    snprintf(path, sizeof(path), "./plugins/%s/lib%s.so", plugin_name, plugin_name);

    void *handle = dlopen(path, RTLD_LAZY); // RTLD_LAZYを使うためにはdlfcn.hのincludeが必要 
    if (!handle) {
        fprintf(stderr, "プラグインのロードに失敗: %s\n", dlerror());
        return;
    }

    // プラグインのエントリーポイントを取得
    void (*run)() = dlsym(handle, "run");
    if (!run) {
        fprintf(stderr, "プラグインのエントリーポイントが見つかりません: %s\n", dlerror());
        dlclose(handle);
        return;
    }

    // プラグインの実行
    run();
    dlclose(handle);
}
