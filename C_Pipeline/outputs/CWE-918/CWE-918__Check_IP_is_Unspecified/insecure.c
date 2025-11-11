#include <string.h>
#include <curl/curl.h>

int is_ip_unspecified(const char* ip_str) {
    CURL *curl;
    CURLcode res;
    long response_code;
    curl = curl_easy_init();
    if(curl) {
        char url[256];
        snprintf(url, sizeof(url), "http://%s", ip_str);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if(response_code == 0) {
                curl_easy_cleanup(curl);
                return 1;
            }
        }
        curl_easy_cleanup(curl);
    }
    return 0;
}