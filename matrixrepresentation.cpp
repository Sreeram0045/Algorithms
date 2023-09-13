#include <iostream>
class SparseMatrix
{
    int row{0};
    int col{0};
    int nonzero{0};
    int **mat;
    int **sp_mat;

public:
    SparseMatrix() = default;
    SparseMatrix(int r, int c) : row(r), col(c) {}
    void matcreate();
    void spmatcreate();
    void spprint();
    void matprint();
    ~SparseMatrix();
};
void SparseMatrix::matcreate()
{
    int i, j, k = 0;
    if (row == 0 && col == 0)
    {
        std::cout << "Enter the total number of rows and coloumns in the original matrix: ";
        std::cin >> row >> col;
    }
    mat = new int *[row];
    for (i = 0; i < row; i++)
    {
        mat[i] = new int[col];
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            std::cout << "Enter the " << ++k << " element: ";
            std::cin >> mat[i][j];
            if (mat[i][j] != 0)
            {
                ++nonzero;
            }
        }
    }
}
void SparseMatrix::spmatcreate()
{
    int i, j, k = 1;
    sp_mat = new int *[nonzero + 1];
    for (i = 0; i < nonzero + 1; i++)
    {
        sp_mat[i] = new int[3];
    }
    sp_mat[0][0] = row;
    sp_mat[0][1] = col;
    sp_mat[0][2] = nonzero;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (mat[i][j] != 0)
            {
                sp_mat[k][0] = i;
                sp_mat[k][1] = j;
                sp_mat[k][2] = mat[i][j];
                ++k;
            }
        }
    }
}
void SparseMatrix::spprint()
{
    int i, j;
    std::cout << "ROW\tCOLOUMN\tVALUE\n";
    for (i = 0; i < nonzero + 1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            std::cout << sp_mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
void SparseMatrix::matprint()
{
    std::cout << "Original Matrix: \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << mat[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}
SparseMatrix::~SparseMatrix()
{
    for (int i = 0; i < row; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
    for (int i = 0; i < nonzero + 1; i++)
    {
        delete[] sp_mat[i];
    }
    delete[] sp_mat;
}
int main()
{
    SparseMatrix s1;
    s1.matcreate();
    s1.matprint();
    s1.spmatcreate();
    s1.spprint();
}