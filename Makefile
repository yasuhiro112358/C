.PHONY: all build run clean

# $ makeまたは$ make allを実行すると、'all' ターゲットが実行される
all: build run

# 'main' ターゲットは 'main.c' と 'plugin_loader.c' ファイルを依存関係として持ちます。
# 'gcc' コマンドを使用して、'main.c' と 'plugin_loader.c' をコンパイルし、'main' という実行ファイルを生成します。
# main: main.c plugin_loader.c
#     gcc -o main main.c plugin_loader.c -ldl

# 依存関係（:のあと）にmain.cを指定することで、main.cが変更された場合にのみ、mainターゲットが再構築される
build: main.c 
	mkdir ./build
	gcc -o ./build/main ./main.c

# 'run' ターゲットは 'main' ターゲットを依存関係として持ちます。
# 'main' 実行ファイルを実行します。
run: build/main
	./build/main


# 'plugins' ターゲットは、3つのサブディレクトリ（'plugins/calculator', 'plugins/contacts', 'plugins/database'）で
# 'make' コマンドを実行します。
# '$(MAKE)' は、現在の 'make' コマンドを再帰的に呼び出すための変数です。
# '-C' オプションは、指定されたディレクトリに移動してからコマンドを実行することを意味します。
# plugins:
#     $(MAKE) -C plugins/calculator
#     $(MAKE) -C plugins/contacts
#     $(MAKE) -C plugins/database

# 'clean' ターゲットは、ビルドによって生成されたファイルを削除します。
# 'rm -f main' コマンドは、'main' 実行ファイルを削除します。
# 各サブディレクトリ（'plugins/calculator', 'plugins/contacts', 'plugins/database'）で 'make clean' コマンドを実行します。
clean:
	rm -rf ./build
    # $(MAKE) -C plugins/calculator clean
    # $(MAKE) -C plugins/contacts clean
    # $(MAKE) -C plugins/database clean
