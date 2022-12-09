#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

bool IsElementLocalMinimum(int** arr, int row_count, int col_count, int pos_row, int pos_col);
void NumberLocalMinimumRec(int** arr, int row_count, int col_count, int i, int j, int& numberLocalMin);

int ABS(int numb);
int FindSumAbsUnderDiagonalRec(int** arr, int row_count, int col_count, int i, int j, int& sum);

int main()
{
    srand(time(NULL));
    int rowCount, colCount, n;
    cout << "Enter n in Matrix "; cin >> n;

    rowCount = n;
    colCount = n;

    int** matrix = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
    {
        matrix[i] = new int[colCount];
    }

    cout << "Created matrix:\n";
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            matrix[i][j] = (rand() % 100) - 49;

            if (!(matrix[i][j] < 0)) cout << " ";   
            cout << matrix[i][j];

            if (j != colCount - 1)
            {
                cout << "\t ";
            }
            else
            {
                cout << "\n";
            }
        }
    }
    cout << endl;

    int numberLocalMin = 0;
    int sum = 0;
    NumberLocalMinimumRec(matrix, rowCount, colCount, 0, 0, numberLocalMin);

    cout << "Number Local Minimum: " << numberLocalMin << endl;
    cout << "\nSum absolut value upper diagonal matrix " << FindSumAbsUnderDiagonalRec(matrix, rowCount, colCount, 0, 0, sum) << endl;

}

void Create(int** arr, const int rowCount, const int colCount, const int Low,
    const int High, int i, int j)
{
    if (j < colCount)
    {
        arr[i][j] = Low + rand() % (High - Low + 1);
        i++;
    }
    else
    {
        i = 0;
        j++;
    }
    if (j >= colCount)
    {
        return;
    }
}

void PrintCol(int** arr, const int rowCount, const int colCount, int i, int j, int colNo)
{
    cout << setw(4) << arr[i][j];
    if (colNo < colCount - 1)
        PrintCol(arr, rowCount, colCount, i, j, colNo + 1);
    else
        cout << endl;
}

void PrintCols(int** arr, const int rowCount, const int colCount, int colNo, int i, int j)
{
    PrintCol(arr, colNo, colCount, i, j, 0);
    if (colNo < rowCount - 1)
        PrintCols(arr, rowCount, colCount, colNo + 1, i, j);
    else
        cout << endl;
}

bool IsElementLocalMinimum(int** arr, int row_count, int col_count, int pos_row, int pos_col)
{
    int localMin = arr[pos_row][pos_col];

    if (pos_row > 0 && localMin > arr[pos_row - 1][pos_col]) return false;
    if (pos_col > 0 && localMin > arr[pos_row][pos_col - 1]) return false;

    if (pos_row<row_count - 1 && localMin > arr[pos_row + 1][pos_col]) return false;
    if (pos_col<col_count - 1 && localMin > arr[pos_row][pos_col + 1]) return false;

    return true;
}

void NumberLocalMinimumRec(int** arr, int row_count, int col_count, int i, int j, int& numberLocalMin)
{
    if (j < col_count)
    {
        if (IsElementLocalMinimum(arr, row_count, col_count, i, j))
        {
            numberLocalMin++;
        }
        j++;
    }
    else
    {
        j = 0;
        i++;
    }

    if (i >= row_count)
    {
        return;
    }

    NumberLocalMinimumRec(arr, row_count, col_count, i, j, numberLocalMin);
}

int FindSumAbsUnderDiagonalRec(int** arr, int row_count, int col_count, int i, int j, int& sum)
{
    if (j < col_count)
    {
        if (i < j) sum += ABS(arr[i][j]);
        j++;
    }
    else
    {
        j = 0;
        i++;
    }

    if (i >= row_count)
    {
        return sum;
    }

    FindSumAbsUnderDiagonalRec(arr, row_count, col_count, i, j, sum);
}

int ABS(int numb)
{
    if (numb < 0)
        return numb * (-1);
    return numb;
}