# C

## ビルド
```bash
gcc src/main.c -o build/a.out
```

## 実行
```bash
./build/a.out
```

## math.hを使用する場合のビルド
```bash
gcc src/math.c -o build/a.out -lm
# math.hを使用する場合は、リンクオプションに-lmを追加する
```

## LAPACKを使用する場合のビルド
```bash
gcc src/solve_linear_equation.c -o build/a.out -llapack -lblas
# 内部的にBLASを使用しているため、BLASもリンクする必要がある
```


# SQLite
```bash
# version確認
sqlite3 --version

# shell起動
sqlite3
```

```sqlite



# shell終了
.quit
```





