#include <iostream>

using namespace std;

// Константи для розміров матриці
const int ROWS = 3;     //Кількість рядкі
const int COLS = 5;     //Кількість стовбців

int main() {
    // Статична матриця розміром 3 рядки та 5 стовпців
    int matrix[ROWS][COLS];

    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cin >> matrix[i][j];
        }
    }

    // 1. Сума елементів у рядках без від’ємних елементів
    int total_sum = 0;
    for (int i = 0; i < ROWS; i++) {
        bool has_negative = false;
        int row_sum = 0;
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] < 0) {
                has_negative = true;
            } 
            row_sum += matrix[i][j];
        }
        if (!has_negative) {
            total_sum += row_sum;
        }
    }
    cout << "Sum of elements in rows without negative elements: " << total_sum << endl;

    // 2. Середнє арифметичне від’ємних елементів головної діагоналі
    int neg_sum = 0, neg_count = 0;
    for (int i = 0; i < ((ROWS < COLS) ? ROWS : COLS); i++) {
        if (matrix[i][i] < 0) {
            neg_sum += matrix[i][i];
            neg_count++;
        }
    }

    if (neg_count > 0) {
        cout << "Average of negative elements on the main diagonal: " << (double)neg_sum / neg_count << endl;
    }
    else {
        cout << "No negative elements on the main diagonal." << endl;
    }

    return 0;
}
