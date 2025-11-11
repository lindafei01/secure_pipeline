#include <string.h>

int url_path_has_dot_dot(const char* url) {
    const char* search = strstr(url, "://");
    if (search) {
        search += 3;
        search = strchr(search, '/');
    }
    else {
        search = strchr(url, '/');
    }

    if (search) {
        if (strstr(search, "..")) {
            return 1;
        }
    }
    return 0;
}