#include "Time.h"

float Time::getTime() {
	return (float)((ifj::get_nanotime() - timeStarted) * 1E-9);
}

