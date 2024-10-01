#include "./types.h"

/**
 * @brief Get the Current Time object
 * 
 * @return time_t 
 */
char * getCurrentTime(void)
{
	int MAX_SIZE = 80;
	time_t timestamp = time( NULL );
    struct tm * pTime = localtime( & timestamp );

    char buffer[ MAX_SIZE ];
    strftime(buffer, MAX_SIZE, "%d/%m/%Y %H:%M:%S", pTime);

	return buffer;
}
