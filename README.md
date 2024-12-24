# C

## ビルド
```bash
gcc src/main.c -o build/a.out
```

## 実行
```bash
./build/a.out
```

## ライブラリをリンクしてビルド
```bash
# math.h: -lm
gcc src/math.c -o build/a.out -lm

# SQLite: -lsqlite3
gcc src/sqlite3.c -o build/a.out -lsqlite3

# LAPACK: -llapack -lblas
gcc src/solve_linear_equation.c -o build/a.out -llapack -lblas
# 内部的にBLASを使用しているため、BLASもリンクする必要がある

# cURL: -lcurl
gcc src/curl.c -o build/a.out -lcurl
```

## SQLite
```bash
# version確認
sqlite3 --version

# shell起動
sqlite3

# DBを指定してshell起動
sqlite3 test.db
```

## SQLite Shell
```sql
-- デーブル一覧を表示
.tables

-- テーブルのスキーマ（構造）を表示
.schema [table_name]

-- データの確認（SQL）
SELECT * FROM Contacts;


-- 表示形式の変更
.mode column
.headers on

-- shell終了
.quit
```

## Object file & Shared object
# Object file
- 拡張子: .o
- コンパイルされたコードの中間生成物で、リンクされる前の状態。複数のオブジェクトファイルをリンクして最終的な実行ファイルやライブラリを生成する。
- 実行はできない。実行ファイルや共有ライブラリを生成する必要がある。
```bash
gcc -c source.c -o source.o
# -c: コンパイルのみを行い、リンクは行わない
```
```bash
gcc source.o -o source
# Object fileをリンクして実行ファイルを生成
```

# Shared object
- 拡張子: .so
- Object fileをリンクして生成される。動的にリンクされるライブラリで、実行時にプログラムにロードされます。複数のプログラムから共有して使用されることが多い。
- 単独で実行できない。他のプログラムからロードして使用される。
- 動的ライブラリとも呼ぶ。
```bash
gcc -shared -o libexample.so example.o
```
- .oはPIC（Position Independent Code）である必要がある。
- PICとは、コードがロードされるアドレスに依存しないコードのこと。

- 名前が決まっていて、lib[library_name].soという形式になる。
- リンクする際には、-l[library_name]で指定する。

# Shared objectを生成するための一般的な流れ
```bash
gcc -fPIC -c example.c -o example.o
gcc -shared -o libexample.so example.o
```

