#ifndef _STRING_H_
#define _STRING_H_

#ifdef __cplusplus
extern "C" {
#endif

static unsigned int
mini_strlen(const char *s)
{
	unsigned int len = 0;
	while (s[len] != '\0') len++;
	return len;
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _STRING_H_
