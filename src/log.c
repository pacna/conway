#include "global.h"

void log_error(char *text)
{
    printf(RED "%s\n", text);
}

void log_warn(char *text)
{
    printf(YELLOW "%s\n", text);
}

void log_success(char *text)
{
    printf(GREEN "%s\n", text);
}