#include <iostream>
using namespace std;

bool CheckSymmetric(long long M[][10] , int size , int lmt)
{
    if((size == 1) && (M[0][0] < 0))
    {
        return false;
    }
    if((size == 1) && M[0][0] > 0)
    {
        return true;
    }

    for(int col = 0 ; col < lmt ; col++)
    {
        for(int row = 0 ; row < size ; row++)
        {
            if(M[row][col] < 0)
            {
                return false;
            }
            if(M[row][col] != M[size - 1 - row][size - 1 - col])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int t,N, limit;
    long long mat[10][10];
    string result;

    cin >> t;

    for(int i = 0 ; i < t ; i++)
    {
        string instr,h;

        cin.ignore();
        getline(cin,instr);


        if(instr[instr.size() - 2] == ' ')
        {
            h = "0";
        }

        h = instr[instr.size() - 1];

        N = atoi(h.c_str());

        for(int k = 0 ; k < N ; k++)
        {
            for(int h = 0 ; h < N ; h++)
            {
                cin >> mat[k][h];
            }
        }

        if((N % 2) == 1)
        {
            limit = (N / 2) + 1;
        }
        if((N % 2) == 0)
        {
            limit = (N / 2) ;
        }

        if(CheckSymmetric(mat,N,limit))
        {
            result.push_back('s');
        }
        else
        {
            result.push_back('n');
        }

    }
    for(unsigned int s = 0 ; s < result.size() ; s++)
    {
        cout << "Test #" << (s + 1) << ":";

        if(result[s] == 's')
        {
            cout << " Symmetric." << endl;
        }
        else if(result[s] == 'n')
        {
            cout << " Non-symmetric." << endl;
        }
    }
}
