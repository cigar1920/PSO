#include <iostream>
#include <cstdlib>

#include "../fpdebug.h"

int main(int argc, char** argv)
{
	float g = 9.81f;
	float mass = 1.f;
	float length = 2.f;

	float alpha_0 = -0.2f;
	float omega_0 = 0.f;

	float alpha_last = alpha_0;
	float omega_last = omega_0;

	float alpha_next, omega_next, energy;

	float dt = 0.01f;

	int num_steps = atoi(argv[1]);

	for (int i=0; i<num_steps; ++i)
	{
		alpha_next = alpha_last + omega_last * dt;
		omega_next = omega_last - (g/length) * alpha_last * dt;

		energy = 0.5f * length*length * omega_next*omega_next + 
		         0.5f * mass * g * length * alpha_next*alpha_next;

		alpha_last = alpha_next;
		omega_last = omega_next;

		std::cout << i << " " << alpha_next << " " << omega_next << " " << energy << std::endl;
	}

	VALGRIND_PRINT_ERROR_FLOAT(&"energy", &energy);

	return 0;
}

