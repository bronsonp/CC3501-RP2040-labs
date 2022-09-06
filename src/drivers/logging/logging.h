#pragma once 

#if LOG_DRIVER_STYLE==1
#include "drivers/logging/style1.h"
#elif LOG_DRIVER_STYLE==2
#include "drivers/logging/style2.h"
#elif LOG_DRIVER_STYLE==3
#include "drivers/logging/style3.h"
#endif
