#include <stdlib.h>
#include <string.h>

static char* normalize_path(const char* path) {
    if (path == NULL) return NULL;
    char* result = (char*)malloc(strlen(path) + 1);
    if (result == NULL) return NULL;

    size_t result_len = 0;
    const char* segment_start = path;
    const char* segment_end;

    while (*segment_start != '\0') {
        while (*segment_start == '/') segment_start++;
        segment_end = segment_start;
        while (*segment_end != '/' && *segment_end != '\0') segment_end++;

        size_t segment_len = segment_end - segment_start;
        if (segment_len == 0) break;

        if (segment_len == 1 && segment_start[0] == '.') {
            segment_start = segment_end;
            continue;
        }

        if (segment_len == 2 && segment_start[0] == '.' && segment_start[1] == '.') {
            while (result_len > 0 && result[result_len - 1] != '/') result_len--;
            if (result_len > 0) result_len--;
            segment_start = segment_end;
            continue;
        }

        if (result_len > 0 && result[result_len - 1] != '/') {
            result[result_len++] = '/';
        }
        memcpy(result + result_len, segment_start, segment_len);
        result_len += segment_len;
        segment_start = segment_end;
    }

    result[result_len] = '\0';
    return result;
}

int paths_equal_normalized(const char* path1, const char* path2) {
    char* normalized_path1 = normalize_path(path1);
    char* normalized_path2 = normalize_path(path2);

    if (normalized_path1 == NULL || normalized_path2 == NULL) {
        free(normalized_path1);
        free(normalized_path2);
        return 0;
    }

    int result = strcmp(normalized_path1, normalized_path2) == 0;
    free(normalized_path1);
    free(normalized_path2);
    return result;
}