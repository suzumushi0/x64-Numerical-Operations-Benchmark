
#include <iostream>
#include <random>
#include <numbers>
#include <cmath>
#include <chrono>
#include <thread>

constexpr int len {1'000};
constexpr int iteration {100'000};

float		a32 [len], b32 [len], c32 [len], d32 [len], e32 [len], *a32_p, *b32_p, *c32_p, *d32_p, *e32_p;
double		a64 [len], b64 [len], c64 [len], d64 [len], e64 [len], *a64_p, *b64_p, *c64_p, *d64_p, *e64_p;
int i, j;

std::random_device seed;						// noise seed
std::default_random_engine noise_engine;		// noise engine 
std::uniform_real_distribution<float> noise32 (-1.0f, 1.0f);
std::uniform_real_distribution<double> noise64 (-1.0, 1.0);
std::uniform_real_distribution<float> pi_noise32 (0.0f, (float)std::numbers::pi);
std::uniform_real_distribution<double> pi_noise64 (0.0, std::numbers::pi);


std::chrono::system_clock::time_point tp [26];
double elapsed_time;


int main (int argc, char* argv [])
{
	noise_engine.seed (seed ());

	for (i = 0; i < len; i++) {
		a32 [i] = noise32 (noise_engine);
		b32 [i] = noise32 (noise_engine);
		c32 [i] = noise32 (noise_engine);
		e32 [i] = pi_noise32 (noise_engine);
		a64 [i] = noise64 (noise_engine);
		b64 [i] = noise64 (noise_engine);
		c64 [i] = noise64 (noise_engine);
		e64 [i] = pi_noise64 (noise_engine);
	}

	for (i = 0; i < len; i++) {
		if (b32 [i] == 0.0)
			b32 [i] = 0.5f;
		if (b64 [i] == 0.0)
			b64 [i] = 0.5;
		d32 [i] = abs (b32 [i]);
		d64 [i] = abs (b64 [i]);
	}


	std::this_thread::sleep_for (std::chrono::seconds (2));

	tp [0] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		a32_p = a32;
		b32_p = b32;
		c32_p = c32;
		for (j = 0; j < len; j++)
			*c32_p++ += *a32_p++ * *b32_p++;
	}

	tp [1] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		b32_p = b32;
		c32_p = c32;
		for (j = 0; j < len; j++)
			*c32_p++ = 1.0f / *b32_p++;
	}

	tp [2] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		c32_p = c32;
		e32_p = e32;
		for (j = 0; j < len; j++)
			*c32_p++ = sin (*e32_p++);
	}

	tp [3] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		c32_p = c32;
		e32_p = e32;
		for (j = 0; j < len; j++)
			*c32_p++ = cos (*e32_p++);
	}

	tp [4] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		c32_p = c32;
		e32_p = e32;
		for (j = 0; j < len; j++)
			*c32_p++ = tan (*e32_p++);
	}

	tp [5] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		a32_p = a32;
		c32_p = c32;
		for (j = 0; j < len; j++)
			*c32_p++ = asin (*a32_p++);
	}

	tp [6] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		a32_p = a32;
		c32_p = c32;
		for (j = 0; j < len; j++)
			*c32_p++ = acos (*a32_p++);
	}

	tp [7] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		a32_p = a32;
		c32_p = c32;
		for (j = 0; j < len; j++)
			*c32_p++ = atan (*a32_p++);
	}

	tp [8] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		a32_p = a32;
		b32_p = b32;
		c32_p = c32;
		for (j = 0; j < len; j++)
			*c32_p++ = pow (*b32_p++, *a32_p++);
	}

	tp [9] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		a32_p = a32;
		c32_p = c32;
		for (j = 0; j < len; j++)
			*c32_p++ = pow (*a32_p++, 2.0f);
	}

	tp [10] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		a32_p = a32;
		c32_p = c32;
		for (j = 0; j < len; j++)
			*c32_p++ = exp (*a32_p++);
	}

	tp [11] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		c32_p = c32;
		d32_p = d32;
		for (j = 0; j < len; j++)
			*c32_p++ = log (*d32_p++);
	}

	tp [12] = std::chrono::system_clock::now(); 

	std::this_thread::sleep_for (std::chrono::seconds (2));

	tp [13] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		a64_p = a64;
		b64_p = b64;
		c64_p = c64;
		for (j = 0; j < len; j++)
			*c64_p++ += *a64_p++ * *b64_p++;
	}

	tp [14] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		b64_p = b64;
		c64_p = c64;
		for (j = 0; j < len; j++)
			*c64_p++ = 1.0 / *b64_p++;
	}

	tp [15] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		c64_p = c64;
		e64_p = e64;
		for (j = 0; j < len; j++)
			*c64_p++ = sin (*e64_p++);
	}

	tp [16] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		c64_p = c64;
		e64_p = e64;
		for (j = 0; j < len; j++)
			*c64_p++ = cos (*e64_p++);
	}

	tp [17] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		c64_p = c64;
		e64_p = e64;
		for (j = 0; j < len; j++)
			*c64_p++ = tan (*e64_p++);
	}

	tp [18] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		a64_p = a64;
		c64_p = c64;
		for (j = 0; j < len; j++)
			*c64_p++ = asin (*a64_p++);
	}

	tp [19] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		a64_p = a64;
		c64_p = c64;
		for (j = 0; j < len; j++)
			*c64_p++ = acos (*a64_p++);
	}

	tp [20] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		a64_p = a64;
		c64_p = c64;
		for (j = 0; j < len; j++)
			*c64_p++ = atan (*a64_p++);
	}

	tp [21] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		a64_p = a64;
		b64_p = b64;
		c64_p = c64;
		for (j = 0; j < len; j++)
			*c64_p++ = pow (*b64_p++, *a64_p++);
	}

	tp [22] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		a64_p = a64;
		c64_p = c64;
		for (j = 0; j < len; j++)
			*c64_p++ = pow (*a64_p++, 2.0);
	}

	tp [23] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		a64_p = a64;
		c64_p = c64;
		for (j = 0; j < len; j++)
			*c64_p++ = exp (*a64_p++);
	}

	tp [24] = std::chrono::system_clock::now(); 

	for (i = 0; i < iteration; i++) {
		c64_p = c64;
		d64_p = d64;
		for (j = 0; j < len; j++)
			*c64_p++ = log (*d64_p++);
	}

	tp [25] = std::chrono::system_clock::now(); 


	std::cout << __FILE__ << "\n";
#ifdef _MSC_VER			// Visual C++
#ifdef __AVX2__
	std::cout << "AVX2\n";
#elif __AVX__
	std::cout << "AVX\n";
#else
	std::cout << "SSE2\n";
#endif
#endif
	std::cout << "milliseconds to perform "<< (len * iteration / 1'000'000) << "M iterations\n";

	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [1] - tp [0]).count()); 
	std::cout << "float mul add\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [14] - tp [13]).count()); 
	std::cout << "double mul add\t" << elapsed_time << "\n";

	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [2] - tp [1]).count()); 
	std::cout << "float 1/x\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [15] - tp [14]).count()); 
	std::cout << "double 1/x\t" << elapsed_time << "\n";

	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [3] - tp [2]).count()); 
	std::cout << "float sin\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [16] - tp [15]).count()); 
	std::cout << "double sin\t" << elapsed_time << "\n";

	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [4] - tp [3]).count()); 
	std::cout << "float cos\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [17] - tp [16]).count()); 
	std::cout << "double cos\t" << elapsed_time << "\n";

	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [5] - tp [4]).count()); 
	std::cout << "float tan\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [18] - tp [17]).count()); 
	std::cout << "double tan\t" << elapsed_time << "\n";

	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [6] - tp [5]).count()); 
	std::cout << "float asin\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [19] - tp [18]).count()); 
	std::cout << "double asin\t" << elapsed_time << "\n";

	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [7] - tp [6]).count()); 
	std::cout << "float acos\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [20] - tp [19]).count()); 
	std::cout << "double acos\t" << elapsed_time << "\n";

	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [8] - tp [7]).count()); 
	std::cout << "float atan\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [21] - tp [20]).count()); 
	std::cout << "double atan\t" << elapsed_time << "\n";

	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [9] - tp [8]).count()); 
	std::cout << "float x^y\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [22] - tp [21]).count()); 
	std::cout << "double x^y\t" << elapsed_time << "\n";

	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [10] - tp [9]).count()); 
	std::cout << "float x^2\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [23] - tp [22]).count()); 
	std::cout << "double x^2\t" << elapsed_time << "\n";

	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [11] - tp [10]).count()); 
	std::cout << "float exp\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [24] - tp [23]).count()); 
	std::cout << "double exp\t" << elapsed_time << "\n";

	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [12] - tp [11]).count()); 
	std::cout << "float log\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [25] - tp [24]).count()); 
	std::cout << "double log\t" << elapsed_time << "\n";
}
