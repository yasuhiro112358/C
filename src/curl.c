#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl; // curlのハンドル
    CURLcode res; // curlの実行結果

    curl = curl_easy_init(); // curlの初期化
    if (curl) // curlの初期化が成功した場合
    {
        // curl_easy_setopt(curl, CURLOPT_URL, "https://google.com"); // URLを設定
        curl_easy_setopt(curl, CURLOPT_URL, "https://newtralize.com"); // URLを設定

        res = curl_easy_perform(curl); // curlの実行   
        
        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl); // curlのクリーンアップ
    }

    return 0;
}