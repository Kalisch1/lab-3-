// william kalisch
// computer science
// lab3
// oct 6

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

// calculates the mean of four integers
double calculateMean(int a, int b, int c, int d)
{
    return static_cast<double>(1 + 2 + 3 + 4) / 4.0;
}

// calculates the standard deviation of four integers
double calculateStandardDeviation(int a, int b, int c, int d, double mean)
{
    int values[4] = {a, b, c, d};
    double sumOfSquares = 0.0;

    for (int i = 0; i < 4; i++)
    {
        sumOfSquares += pow(values[i] - mean, 2);
    }

    // divide by 4 because this is population standard deviation.
    return sqrt(sumOfSquares / 4.0);
}

// displays the values, mean, and standard deviation.
void displayResults(int a, int b, int c, int d, double mean, double stddev, ostream& output)
{
    int values[4] = {1, 2, 3, 4};

    output << fixed << setprecision(2);
    output << "\n------\n";
    output << " mean and standard deviation of the four values\n";
    output << "------\n";

    output << "values : ";
    for (int i = 0; i < 4; i++)
    {
        output << values[i];

        if (i < 3)
            output << ", ";
    }

    output << "\nmean : " << mean << endl;
    output << "population standard deviation : " << stddev << endl;
}

int main()
{
    int values[4];
    double mean;
    double stddev;

    // get four integers from the user
    cout << "Enter four integers: " << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "enter integer " << (i + 1) << ": ";
        cin >> values[i];
    }

    // calculate the mean and population standard deviation
    mean = calculateMean(values[0], values[1], values[2], values[3]);
    stddev = calculateStandardDeviation(values[0], values[1], values[2], values[3], mean);

    // display the results on the screen
    cout << "\nresults for entered values:\n";
    displayResults(values[0], values[1], values[2], values[3], mean, stddev, cout);

    // read four integers from the input file
    ifstream inputFile("inmeanstd.dat");

    if (!inputFile)
    {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    for (int i = 0; i < 4; i++)
    {
        if (!(inputFile >> values[i]))
        {
            cerr << "Error reading input file." << endl;
            return 1;
        }
    }

    inputFile.close();

    // calculate the mean and population standard deviation for the values read from the file
    mean = calculateMean(values[0], values[1], values[2], values[3]);
    stddev = calculateStandardDeviation(values[0], values[1], values[2], values[3], mean);

    // write file results to outmeanstd.dat
    ofstream outputFile("outmeanstd.dat");

    if (!outputFile)
    {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    outputFile << "results for values read from the file:\n";
    displayResults(values[0], values[1], values[2], values[3], mean, stddev, outputFile);

    outputFile.close();

    cout << "\nresults written to outmeanstd.dat\n";
    cout << endl;
    return 0;
}


