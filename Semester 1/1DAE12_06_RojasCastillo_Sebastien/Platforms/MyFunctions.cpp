
#include "pch.h"
#include "MyFunctions.h"

//#define _USE_MATH_DEFINES
//#include <math.h>


double WaveMovement(int	   moved, int	 fullMovement) {
	
	return WaveMovement(double(moved), double(fullMovement));
}


double WaveMovement(float  moved, float	 fullMovement) {
	return WaveMovement(double(moved), double(fullMovement));;
}


double WaveMovement(double moved, double fullMovement) {
	double angle{ moved / fullMovement * 2 * M_PI };

	return sin(angle);
}