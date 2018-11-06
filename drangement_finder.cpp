#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> finder(int size);
void next_level_in_Pascals_Triangle(vector<int>& level);
void print(const vector<int>& vec){
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << ' ';
	}
	cout << '\n';
}

int main(){
	print(finder(10));
	
}

vector<int> finder(int size){
	vector<int> series;
	series.push_back(1);
	print(series);
	vector<int> pascals_Triangle;//this is one level of pascal's triangle
	pascals_Triangle.push_back(1);
	int n_factorial = 1;
	for(int i = 1; i < size; i++){
		n_factorial *= i;
		next_level_in_Pascals_Triangle(pascals_Triangle);
		int subtraction_sum = n_factorial;
		for(int g = 0; g < pascals_Triangle.size()-1; g++){//the -1 keeps from accessing last element
			subtraction_sum -= pascals_Triangle[g]*series[g];
			cout << "Triangle: " << pascals_Triangle[g] << '\n';
			cout << "g: " << g << '\n';
			cout << "series: " << series[g] << '\n';
			cout << "subtraction_sum: " << subtraction_sum << '\n';
		}
		series.push_back(subtraction_sum);
	}
	return series;
}

void next_level_in_Pascals_Triangle(vector<int>& level){
	int previous = level[0];
	for(int i = 1; i < level.size(); i++){
		int temp = level[i];
		level[i] = previous + level[i];
		previous = temp;
	}
	level.push_back(1);
	return;
}
