#pragma once
double WaveMovement(int		moved,	int		fullMovement	= 100);
double WaveMovement(float	moved,	float	fullMovement	= 1.f);
double WaveMovement(double	moved,	double	fullMovement	= 1.0);



// WaveMovement(90, 360);					//degrees
// WaveMovement(M_PI / 2 , 2 * M_PI);		//Radians
// WaveMovement(250, 100);					//Mils

// WaveMovement(0.25);						//Percentage (out of 1.0)
// WaveMovement(25);						//Percentage (out of 100)

//WaveMovement(g_TotalTimeElapsed, WAVELENGTH)


// Properties of a wave:
// - How high does the wave go?		AMPLITUDE
// - How fast does the wave move?	FREQUENCY / WAVELENGTH
// - Where do we start?				PHASE