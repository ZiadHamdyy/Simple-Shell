#include "main.h"
/**
 */
void sigint_handler(int signal)
{
	if (signal == SIGINT)
		write(1, "\n$ ", 3);
}
