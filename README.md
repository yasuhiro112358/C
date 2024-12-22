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

# SQLite
```bash
# version確認
sqlite3 --version

# shell起動
sqlite3

# DBを指定してshell起動
sqlite3 test.db
```

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





