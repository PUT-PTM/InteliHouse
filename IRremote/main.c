#include "main.h"


int main(void)
{
	SystemInit();
	Led_Init();
	UB_IRMP_Init();
	TIMER_init(9999);
	while (1)
	{}
	return 0;
}


