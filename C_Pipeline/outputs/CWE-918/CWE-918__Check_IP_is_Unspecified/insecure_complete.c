#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

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
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s ip_str\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* ip_str = argv[1];


    // Execute function
    int result = is_ip_unspecified(ip_str);

    printf("%ld\n", (long)result);
    return 0;
}