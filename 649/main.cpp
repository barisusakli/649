

#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdint>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

std::mt19937 rngEngine;
std::uniform_int_distribution<uint32_t> uint_dist;

void play();
void printVector(const std::vector<unsigned int>& numbers);
vector<unsigned int> pickRandom(vector<unsigned int> numbers, unsigned int n);
unsigned int removeRandomNumber(vector<unsigned int>& numbers);
vector<unsigned int> numbers(49);

int main() {
	int numPlays = 0;
	cout << "How many to play?" << endl;
	cin >> numPlays;
	
	rngEngine.seed(static_cast<unsigned long>(std::time(0)));

	std::iota(numbers.begin(), numbers.end(), 1);
	
	cout << "Playing " << numPlays << " rounds...\n\n";

	for (int i = 0; i < numPlays; ++i) {
		play();
	}
}

void play() {
	auto result = pickRandom(numbers, 6);
	std::sort(result.begin(), result.end());
	printVector(result);
	cout << endl << endl;
}

vector<unsigned int> pickRandom(vector<unsigned int> numbers, unsigned int n) {
	vector<unsigned int> result(n);
	std::generate(result.begin(), result.end(), [&]{return removeRandomNumber(numbers); });
	return result;
}

unsigned int removeRandomNumber(vector<unsigned int>& numbers) {
	uint32_t index = uint_dist(rngEngine) % numbers.size();
	unsigned int value = numbers[index];
	std::swap(numbers[index], numbers.back());
	numbers.pop_back();
	return value;
}

void printVector(const std::vector<unsigned int>& numbers) {
	for (unsigned int number : numbers) {
		cout << number << " ";
	}
}
