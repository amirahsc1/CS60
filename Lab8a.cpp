#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  ifstream inputFile("scores.txt");
  if (!inputFile) {
    cout << "Failed to open the input file." << endl;
    return 1;
  }
  vector<int> scores;
  int score;

  while (inputFile >> score) {
    scores.push_back(score);
  }

  inputFile.close();

  int sum = 0;
  int numScores = scores.size();
  for (int i = 0; i < numScores; i++) {
    sum += scores[i];
  }
  double average = static_cast<double>(sum) / numScores;

  cout << "Average: " << average << endl;
  cout << "Number of Scores: " << numScores << endl;

  return 0;
}
