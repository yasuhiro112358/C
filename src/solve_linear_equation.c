#include <stdio.h>
#include <stdlib.h>

// LAPACKのdgesv_関数の宣言
extern void dgesv_(int *n, int *nrhs, double *a, int *lda, int *ipiv,
                   double *b, int *ldb, int *info);
// dgesv_関数の詳細:
// https://netlib.org/lapack/explore-html/d8/da6/group__gesv_ga831ce6a40e7fd16295752d18aed2d541.html?utm_source=chatgpt.com


int main()
{
    // 行列Aとベクトルb (Ax = b)
    double A[4] = {4, 3, 6, 3}; // 2x2行列
    double b[2] = {5, 7};       // 右辺ベクトル
    // LAPACKは行列を列優先で受け取るので、Ax = bは以下のようになる
    // 4x + 6y = 5
    // 3x + 3y = 7
    
    int n = 2;    // 行列Aの次元 (2x2)
    int nrhs = 1; // bの列数
    int lda = 2;  // Aのリーディングディメンション
    int ldb = 2;  // bのリーディングディメンション
    int ipiv[2];  // ピボットインデックス (出力)
    int info;     // 結果情報 (出力)
    // INFO is INTEGER
    //       = 0:  successful exit
    //       < 0:  if INFO = -i, the i-th argument had an illegal value
    //       > 0:  if INFO = i, U(i,i) is exactly zero.  The factorization
    //             has been completed, but the factor U is exactly
    //             singular, so the solution could not be computed.

    // dgesv_を呼び出してAx = bを解く
    dgesv_(&n, &nrhs, A, &lda, ipiv, b, &ldb, &info);

    if (info == 0)
    {
        printf("解:\n");
        for (int i = 0; i < n; i++)
        {
            printf("x[%d] = %f\n", i, b[i]);
        }
    }
    else if (info < 0)
    {
        printf("エラー: 引数 %d が無効です\n", -info);
    }
    else
    {
        printf("エラー: 行列が特異です\n");
    }

    return 0;
}
