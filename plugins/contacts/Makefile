.PHONY: all build clean

PLUGIN_NAME = contacts
SRC = contacts.c
# SRCの'.c'を'.o'に置換
OBJ = $(SRC:.c=.o) 

# Default target
all: build

# lib$(PLUGIN_NAME).soに依存 -> lib$(PLUGIN_NAME).soを生成
build: lib$(PLUGIN_NAME).so

# .oファイルをリンクして共有ライブラリ（.so）を作成
lib$(PLUGIN_NAME).so: $(OBJ)
	gcc -shared -o lib$(PLUGIN_NAME).so $(OBJ) -lsqlite3

# .cファイルを.oファイルにコンパイル
# -fPIC: 位置非依存コードを生成
# -c: コンパイルのみを行い、リンクは行わない
# $<: 依存関係の最初のファイル名
# $@: ターゲット名
%.o: %.c
	gcc -fPIC -c $< -o $@

clean:
	rm -f $(OBJ) lib$(PLUGIN_NAME).so
