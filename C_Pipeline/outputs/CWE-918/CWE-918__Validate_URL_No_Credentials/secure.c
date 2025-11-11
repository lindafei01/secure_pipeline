#include <string.h>
#include <ctype.h>

int url_has_no_credentials(const char* url) {
    const char* pos = strstr(url, "://");
    if (pos) {
        pos += 3; // Move past "://"
        const char* atPos = strchr(pos, '@');
        const char* slashPos = strchr(pos, '/');
        const char* colonPos = strchr(pos, ':');

        if (atPos && (!slashPos || atPos < slashPos) && (!colonPos || colonPos < atPos)) {
            return 0;
        }
    }
    return 1;
}