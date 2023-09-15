#include <iostream>
class SparseMatrix
{
    int row{0};
    int col{0};
    int nonzero{0};
    int **mat;
    int **t_mat;
    int **sp_mat;
    int **spt_mat;

public:
    SparseMatrix() = default;
    SparseMatrix(int r, int c) : row(r), col(c) {}
    void matcreate();
    void spmatcreate();
    void spprint();
    void matprint();
    void sptmatcreate();
    void sptmatprint();
    void tmatcreate();
    void tmatprint();
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
void SparseMatrix::sptmatcreate()
{
    int i;
    spt_mat = new int *[nonzero + 1];
    for (i = 0; i < nonzero + 1; i++)
    {
        spt_mat[i] = new int[3];
    }
    for (i = 0; i < nonzero + 1; i++)
    {
        spt_mat[i][0] = sp_mat[i][1];
        spt_mat[i][1] = sp_mat[i][0];
        spt_mat[i][2] = sp_mat[i][2];
    }
}
void SparseMatrix::tmatcreate()
{
    int i, j, r, c;
    t_mat = new int *[col];
    for (i = 0; i < col; i++)
    {
        t_mat[i] = new int[row];
    }
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
        {
            t_mat[i][j] = 0;
        }
    }
    for (i = 1; i < nonzero + 1; i++) // I started i at 1 because the 0th index of the array contains the total number of columns and rows, which is not needed in the transpose matrix. The column and row indices are stored starting from index 1. Furthermore, if we start from index 0, it will create a segmentation fault.
    {
        r = spt_mat[i][0];
        c = spt_mat[i][1];
        t_mat[r][c] = spt_mat[i][2];
    }
}
void SparseMatrix::sptmatprint()
{
    int i, j;
    std::cout << "Transpose of Sparse Matrix:\n";
    std::cout << "ROW\tCOLOUMN\tVALUE\n";
    for (i = 0; i < nonzero + 1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            std::cout << spt_mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
void SparseMatrix::spprint()
{
    int i, j;
    std::cout << "Sparse Matrix:\n";
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
void SparseMatrix::tmatprint()
{
    std::cout << "Transpose of original Matrix: \n";
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            std::cout << t_mat[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}
SparseMatrix::~SparseMatrix()
{
    int i;
    for (i = 0; i < row; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
    for (i = 0; i < col; i++)
    {
        delete[] t_mat[i];
    }
    delete[] t_mat;
    for (i = 0; i < nonzero + 1; i++)
    {
        delete[] sp_mat[i];
    }
    delete[] sp_mat;
    for (i = 0; i < nonzero + 1; i++)
    {
        delete[] spt_mat[i];
    }
    delete[] spt_mat;
}
int main()
{
    SparseMatrix s1;
    s1.matcreate();
    s1.matprint();
    s1.spmatcreate();
    s1.spprint();
    s1.sptmatcreate();
    s1.sptmatprint();
    s1.tmatcreate();
    s1.tmatprint();
}