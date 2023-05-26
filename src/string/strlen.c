#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

static unsigned int strlen(const char *s) {
	unsigned int len = 0;
	while (s[len] != '\0') len++;
	return len;
}

#ifdef __cplusplus
} // extern "C"
#endif
