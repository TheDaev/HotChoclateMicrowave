#pragma once

#include "ifj.h"

long long timeStarted = ifj::get_nanotime();

class Time
{
public:
	static float getTime();
};

