#include <iostream>
using namespace std;

// Store info for each non-zero entry
struct Entry {
    int row;
    int col;
    int value;
};

// A class for handling a sparse matrix using triplets
class SparseMatrix {
    int totalRows, totalCols, nonZeroCount;
    Entry* values; // dynamic array for entries

public:
    SparseMatrix(int rows, int cols, int count)
        : totalRows(rows), totalCols(cols), nonZeroCount(count)
    {
        values = new Entry[nonZeroCount];
    }

    ~SparseMatrix() {
        delete[] values;
    }

    // Get user input for all non-zero matrix values
    void inputEntries() {
        cout << "For each non-zero element, enter row, column, and value (space-separated):" << endl;
        for (int i = 0; i < nonZeroCount; i++) {
            cin >> values[i].row >> values[i].col >> values[i].value;
        }
    }

    // Show list of non-zero entries as triplets
    void printTriplets() const {
        cout << "Non-zero entries (row column value):" << endl;
        for (int i = 0; i < nonZeroCount; i++) {
            cout << values[i].row << " " << values[i].col << " " << values[i].value << endl;
        }
    }

    // Show the full matrix, filling zeros in proper places
    void showFullMatrix() const {
        int iEntry = 0;
        for (int row = 0; row < totalRows; ++row) {
            for (int col = 0; col < totalCols; ++col) {
                if (iEntry < nonZeroCount &&
                    values[iEntry].row == row &&
                    values[iEntry].col == col)
                {
                    cout << values[iEntry].value << " ";
                    ++iEntry;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int rows, cols, nonZeros;
    cout << "Type the number of rows and columns: ";
    cin >> rows >> cols;
    cout << "Type how many non-zero elements: ";
    cin >> nonZeros;

    SparseMatrix matrix(rows, cols, nonZeros);
    matrix.inputEntries();

    cout << endl << "Triplet representation:" << endl;
    matrix.printTriplets();

    cout << endl << "Full matrix format:" << endl;
    matrix.showFullMatrix();

    return 0;
}
