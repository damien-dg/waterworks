#include <cmath>
#include <vector>



//adding two vectors of vec3 together


//used for "pulse" animation. setting the color value with the resulting wave values causes color to fade in and out
inline float approxTriangleWave(float tWave, float scaler, float shifter) { 

//this is an approximation of fourier	
	return 0.810569f *((sin(tWave) / scaler + shifter)
						- 0.111111f*(sin(3.0f * tWave) / scaler + shifter) 
						+ 0.04f*(sin(5.0f * tWave)) / scaler + shifter);
	

}
