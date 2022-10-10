#include "global.h"

void log_error_with_added_text(char *text, const char *added_text)
{
    printf(RED "%s%s\n", text, added_text);
}

void log_error(char *text)
{
    log_error_with_added_text(text, "");
}

void log_warn(char *text)
{
    printf(YELLOW "%s\n", text);
}

void log_success(char *text)
{
    printf(GREEN "%s\n", text);
}