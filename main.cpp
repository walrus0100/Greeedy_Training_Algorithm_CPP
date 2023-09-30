#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Function to generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to perform greedy random training
void greedyRandomTraining(const std::vector<double>& trainingData, int numEpochs, int numDataPoints) {
    
    int dataSize = trainingData.size();
    std::vector<double> model(dataSize, 0);  // Initialize the model with all zeros

    // Perform training for the specified number of epochs
    for (int epoch = 0; epoch < numEpochs; ++epoch) {
        

        // Randomly select multiple data points
        std::vector<double> selectedIndices;
        for (int i = 0; i < numDataPoints; ++i) {
            int dataPointIndex = getRandomNumber(0, dataSize - 1);
            selectedIndices.push_back(dataPointIndex);
        }

        // Update the model by incrementing the selected data points
        for (const auto& index : selectedIndices) {
            model[index]++;
        }

        // Print the updated model
        for (const auto& weight : model) {
            std::cout << weight << " ";
        }
        std::cout << std::endl;
    }
}

void readDoublesFromFile(const std::string& filename, std::vector<double>& doubles) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    double value;
    while (file >> value) {
        doubles.push_back(value);
    }

    file.close();
}

int main() {
    // Set the seed for random number generation
    srand(static_cast<unsigned int>(time(0)));
    std::vector<double> trainingData;
    std::string filename = "1000 files.f"; // Replace with your file name
    readDoublesFromFile(filename, trainingData);

     

    // Example usage
    
    int numEpochs = 1;
    int numDataPoints = trainingData.size();
    greedyRandomTraining(trainingData, numEpochs, numDataPoints);

    return 0;
}
