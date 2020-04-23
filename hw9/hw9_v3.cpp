#include <iostream>
#include <cassert>
using namespace std;
template <class T> class Matrix
{
public:
    Matrix(int m, int n)
    {
        row = m;
        col = n;
        all = new T*[m];
        for(int i=0;i<m;i++)
        {
            all[i] = new T[n];
        }
    }
    ~Matrix()
    {
        for(int i=0;i<row;i++)
        {
            delete[] all[i];
        }
        delete[] all;
    }

    Matrix(const Matrix& mat)
    {
        row = mat.row;
        col = mat.col;
        all = new T*[row];
        for(int i=0;i<row;i++)
        {
            all[i] = new T[col];
        }        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                all[i][j]=mat.all[i][j];
            }
        }       
    }
    Matrix& operator= (const Matrix& mat)
    {
        assert(row==mat.row && col==mat.col);
        if(this==*mat) return *this;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                all[i][j]=mat.all[i][j];
            }
        }
    }
    void display()
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cout<<all[i][j]<<" ";
            }
            cout<<endl;
        }        
    }
    void transpose()
    {
        T** new_all= new T*[col];
        for(int i=0;i<col;i++)
        {
            new_all[i] = new T[row];
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                new_all[j][i]=all[i][j];
            }
        }                 
        for(int i=0;i<row;i++)
        {
            delete[] all[i];
        }
        delete[] all;
        all = new_all;
        int tmp = row;
        row = col;
        col = tmp;
    }
    void setMatrix()
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cin>>all[i][j];
            }
        }            
    }
    void debug()
    {
        cout<<"row:"<<row<<"col:"<<col<<endl;
    }


    Matrix operator+(const Matrix &mat)
    {
        Matrix res(*this);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                res.all[i][j]=mat.all[i][j]+all[i][j];
            }
        }    
        return res;
    }
    Matrix operator*(const Matrix &mat)
    {
        assert(col==mat.row);
        Matrix res(row, mat.col);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<mat.col;j++)
            {
                T sum;
                for(int k=0;k<mat.row;k++)
                {
                    if(!k)
                    {
                        sum = all[i][k]*mat.get(k,j);
                    }
                    else
                    {
                        sum+= all[i][k]*mat.get(k,j);
                    }
                }
                res.get(i,j)=sum;
            }
        }
        return res;
    }
    void square()
    {
        Matrix<T> copy(*this);
        copy.transpose();
        Matrix<T>res = *this * copy;
        res.display();

    }
    T& get(int i, int j)
    {
        assert(i<row&&j<col);
        return all[i][j];
    }
    T get(int i, int j) const
    {
        assert(i<row&&j<col);
        return all[i][j];        
    }



private:
    T** all;
    int row,col;
};



int main()
{
#ifdef TEST1
    Matrix<int> matrix1(2,3);
    matrix1.setMatrix();
    matrix1.display();
    matrix1.transpose();
    matrix1.display();
    Matrix<int> matrix2(matrix1);
    matrix2.transpose();
    matrix2.display();

#else

    Matrix<double> matrix1(2,3);
    matrix1.setMatrix();
    matrix1.display();
    Matrix<double> matrix2(2,2);
    matrix2.setMatrix();
    matrix2.square();
    Matrix<double> matrix3(2,3);
    matrix3.setMatrix();
    (matrix1+matrix3).display();
#endif

}

