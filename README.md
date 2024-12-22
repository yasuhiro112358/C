# C

## ビルド
```bash
gcc src/main.c -o build/a.out
```

## 実行
```bash
./build/a.out
```

## LAPACKを使用する場合のビルド
```bash
gcc src/solve_linear_equation.c -o build/a.out -llapack -lblas
# 内部的にBLASを使用しているため、BLASもリンクする必要がある
```

