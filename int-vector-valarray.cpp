
#include <iostream>
#include <valarray>
#include <random>
#include <chrono>
#include <thread>

constexpr int len {1'000};
constexpr int iteration {1'000'000};

std::valarray<short>		a16 (len), b16 (len), c16 (len);
std::valarray<int>			a32 (len), b32 (len), c32 (len);
std::valarray<long long>	a64 (len), b64 (len), c64 (len);

std::random_device seed;						// noise seed
std::default_random_engine noise_engine;		// noise engine 
std::uniform_int_distribution<short> noise16;
std::uniform_int_distribution<int> noise32;
std::uniform_int_distribution<long long> noise64;

std::chrono::system_clock::time_point tp [12];
double elapsed_time;


int main (int argc, char* argv [])
{
	noise_engine.seed (seed ());

	for (int i = 0; i < len; i++) {
		a16 [i] = noise16 (noise_engine);
		b16 [i] = noise16 (noise_engine);
		a32 [i] = noise32 (noise_engine);
		b32 [i] = noise32 (noise_engine);
		a64 [i] = noise64 (noise_engine);
		b64 [i] = noise64 (noise_engine);
	}

	for (int i = 0; i < len; i++) {
		if (b16 [i] == 0)
			b16 [i] = 1;
		if (b32 [i] == 0)
			b32 [i] = 1;
		if (b64 [i] == 0)
			b64 [i] = 1;
	}

	std::this_thread::sleep_for (std::chrono::seconds (2));

	tp [0] = std::chrono::system_clock::now(); 

	for (int i = 0; i < iteration; i++) {
		c16 = a16 + b16;
	}

	tp [1] = std::chrono::system_clock::now(); 

	for (int i = 0; i < iteration; i++) {
		c16 = a16 - b16;
	}

	tp [2] = std::chrono::system_clock::now(); 

	for (int i = 0; i < iteration; i++) {
		c16 = a16 * b16;
	}

	tp [3] = std::chrono::system_clock::now(); 

	std::this_thread::sleep_for (std::chrono::seconds (2));

	tp [4] = std::chrono::system_clock::now(); 

	for (int i = 0; i < iteration; i++) {
		c32 = a32 + b32;
	}

	tp [5] = std::chrono::system_clock::now(); 

	for (int i = 0; i < iteration; i++) {
		c32 = a32 - b32;
	}

	tp [6] = std::chrono::system_clock::now(); 

	for (int i = 0; i < iteration; i++) {
		c32 = a32 * b32;
	}

	tp [7] = std::chrono::system_clock::now(); 

	std::this_thread::sleep_for (std::chrono::seconds (2));

	tp [8] = std::chrono::system_clock::now(); 

	for (int i = 0; i < iteration; i++) {
		c64 = a64 + b64;
	}

	tp [9] = std::chrono::system_clock::now(); 

	for (int i = 0; i < iteration; i++) {
		c64 = a64 - b64;
	}

	tp [10] = std::chrono::system_clock::now(); 

	for (int i = 0; i < iteration; i++) {
		c64 = a64 * b64;
	}

	tp [11] = std::chrono::system_clock::now(); 

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
	std::cout << "int16 add\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [5] - tp [4]).count()); 
	std::cout << "int32 add\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [9] - tp [8]).count()); 
	std::cout << "int64 add\t" << elapsed_time << "\n";

	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [2] - tp [1]).count()); 
	std::cout << "int16 sub\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [6] - tp [5]).count()); 
	std::cout << "int32 sub\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [10] - tp [9]).count()); 
	std::cout << "int64 sub\t" << elapsed_time << "\n";

	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [3] - tp [2]).count()); 
	std::cout << "int16 mul\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [7] - tp [6]).count()); 
	std::cout << "int32 mul\t" << elapsed_time << "\n";
	elapsed_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(tp [11] - tp [10]).count()); 
	std::cout << "int64 mul\t" << elapsed_time << "\n";
}
