.PHONY: all build run clean
.PHONY: build_main build_plugins
.PHONY: build_calculator
.PHONY: clean_main clean_plugins
.PHONY: clean_calculator

# ==== Default target ====
all: build run

# ==== Build target ====
build: build_main build_plugins

build_main: ./main.c ./plugin_loader.c
	mkdir -p ./build
	gcc -o ./build/main ./main.c ./plugin_loader.c -ldl

build_plugins: build_calculator

# $(MAKE)は、makeコマンドを呼び出すための特殊な変数
# -Cオプションは、指定されたディレクトリに移動してからコマンドを実行する
build_calculator:
	$(MAKE) -C plugins/calculator all
# ======================

# ==== Run target ====
run: ./build/main
	./build/main
# ====================

# ==== Clean target ====
clean: clean_main clean_plugins

clean_main:
	rm -rf ./build

clean_plugins: clean_calculator

clean_calculator:
	$(MAKE) -C plugins/calculator clean
# ======================