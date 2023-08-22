#include "main.h"
/**
 * sigint_handler - ......
 * @signal:ctrl + c.
 * Return:void
 */
void sigint_handler(int signal)
{
	if (signal == SIGINT)
		write(1, "\n$ ", 3);
}
