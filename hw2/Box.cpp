#include <iostream>
using namespace std;
class BoxWithFixedHeight
{
    public:
        BoxWithFixedHeight():fixed_height(10),len(5),wid(5)//默认尺寸
        {
        }

        BoxWithFixedHeight(double l, double w, double h)
        {
            len = l;
            wid = w;
            fixed_height = h;
        }

        double get_volume()
        {
            return fixed_height*len*wid;
        }
        void set_len(double length)
        {
            len = length;
        }

    private:
        double fixed_height, len, wid;
};


class Matrix
{
    public:
        Matrix(int row, int col)
        {
            matrix_col = col;
            matrix_row = row;
            matrix = new int*[row];
            for(int i=0;i<row;i++)
            {
                matrix[i] = new int[col];
            }
        }
        ~Matrix()
        {
            for(int i=0;i<matrix_row;i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        void input(int* a, int length)
        {
            for(int count=0,i=0;i<matrix_row;i++)
            {
                for(int j=0;j<matrix_col;j++,count++)
                {
                    if(count < length)
                    {
                        matrix[i][j] = a[count];
                    }
                    else
                    {
                        matrix[i][j] = 0;
                    }
                    
                }
            }
        }


        void print()
        {
            for(int i=0;i<matrix_row;i++)
            {
                for(int j=0; j<matrix_col;j++)
                {
                    cout<<matrix[i][j]<<", ";
                }
                cout<<endl;
            }
        }
        void transpose()
        {
            for(int i=0;i<matrix_row-1;i++)
            {
                for(int j=i+1;j<matrix_col;j++)
                {
                    double temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }


    private:
        int matrix_col, matrix_row;
        int** matrix;
};






int main()
{
    int a[] = {1,2,3,4,5,6};
    Matrix b(3,3);
    b.input(a,6);
    b.print();
    b.transpose();
    b.print();
}