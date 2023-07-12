

#include "iostream"
#include "conio.h"
#include "locale.h"

int main()
{
    setlocale(LC_ALL, "rus");
    int graf[100][100];
    int puti[100][100];

    int n, m;
    std::cout << "Введите количество вершин:";
    std::cin >> n;
    std::cout << "Введите количество ребер:";
    std::cin >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graf[i][j] = 0;
            puti[i][j] = 0;
        }
    }

    int x, y, v;
    int x_tmp1;

    std::cout << "Введите рёбра: " << std::endl;
    for (int i = 1; i <= m; i++)
    {
        std::cout << "Вершина 1:" << std::endl;
        std::cin >> x;
        std::cout << "Вершина 2:" << std::endl;
        std::cin >> y;
        std::cout << "Вес пути:" << std::endl;
        std::cin >> v;

        graf[x][y] = v;
        graf[y][x] = v;
        puti[x][y] = 1;
        puti[y][x] = 1;

    }
    std::cout << std::endl;

    std::cout << "Матрица смежности: " << std::endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << graf[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (puti[i][j] == 1)
            {
                x_tmp1 = j;
                for (int j = 1; j <= n; j++)
                {
                    if (puti[i][j] != 1)
                    {
                        puti[i][j] = puti[x_tmp1][j];
                    }
                }
            }
        }
    }

    std::cout << "Матрица с путями: " << std::endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << puti[i][j] << " ";
        }
        std::cout << std::endl;
    }

    
    for (int i = 1; i <= n; i++)
    {
        int min = 100;

        for (int j = 1; j <= n; j++)
        {
            if (graf[i][j] != 0)
            {
                if ( min > graf[i][j])
                {
                    min = graf[i][j];
                }
               
            }
        }

        for (int j = 1; j <= n; j++)
        {
            
            if (graf[i][j] != min)
            {
                graf[i][j] = 0;
                graf[j][i] = 0;
            }
        }

    }
    
    std::cout << "Матрица смежности с короткими путями: " << std::endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << graf[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
}
