#include <iostream>
#include <math.h>
#include <fstream>
 
using namespace std;
 
int main()
  {
    int i,j,k;
    int n = 100;
    int m = 101;
    double eps = 0.00001;    
    double norma;
    double w = 1.6;
    double arr[100][100] = {};
    double y[100] = {};
    double xx[100] = {};
    double xn[100]= {};
    int iter = 0;  
    
    

      // заполнение главной диагонали
      for (int i = 0; i < n; i++)
        {
           arr[i][i] = 10;
        }
      for (int i = 0; i < n; i++)
        {
           arr[i-1][i] = 1.0 / i;
        } 
      // заполнение под главной диагональю
      for (int i = 0; i < n; i++)
        {
             for (int j = 0; j < i; j++)
                {
                    arr[i][j] = 1.0 / (i + 1.0); 
                }
        }
    
     /* for (int i = 0; i < n; i++)
        {
       
          for (int j = 0; j < n; j++){
            cout<< arr[i][j] << "\t"; 
          }
          cout << endl;
        }*/
      for(int i = 0; i < n; i++)
        {
          y[i] = i + 1;
          
        } 

    
        


      //метод пвр
      for(i = 0; i < n; i++)
        {
          xn[i] = 0;
          xx[i] = xn[i];
        }

        do
          { k++;
            norma = 0;
            
            for(i = 0; i < n; i++)
              {
                xx[i]=y[i];

                for(j = 0; j < n; j++)
                  {
                    if(i != j)
                      xx[i]=xx[i] - arr[i][j]*xx[j];
                  }
                xx[i] /= arr[i][i];
                xx[i] = w*xx[i]+(1 - w) * xn[i];
                
                if (fabs(xx[i] - xn[i]) > norma )
                  {
                    norma = fabs(xx[i] - xn[i]);
                    
                  }

                xn[i] = xx[i];
                
              }
              
              iter++;


          }
          while(norma > eps);
          
        
        cout << "iterration dly pvr " << iter << endl;

     
      for(i = 0; i < n; i++)
        {
          cout <<"x"<<i+1<<"= "<<xx[i]<<endl;
          
        }



     //000000
    

      
          
       // задание матрицы для гаусса
        int a = 100;
        int b = 101;
        double arr2[a][b] = {0};
        double c;
        double h;
        double po1[100]={0};
        double X =0;
        
            //задание матрицы
            for (int i = 0; i < a; i++)
                {
                     arr2[i][i] = 10;
                }
            for (int i = 0; i < a; i++)
                {
                     arr2[i-1][i] = 1.0 / i;
                }   
            
            for (int i = 0; i < a; i++)
                {
                     for (int j = 0; j < i; j++)
                            {
                                arr2[i][j] = 1.0 /(i + 1); // если тут заменить на j то цифры будут увеличиться последовательно
                            }
                }
            
            for (int i = 1; i < b+1; i++)  
                {
                    for (int j = 1; j < b; j++)
                        {
                            arr2[i-1][b-1] = i;
                        }
                }       
            
            /*for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    cout << arr[i][j] << "\t"; 
                    cout << endl;
                }*/

        double temp,s,max,max1;
    max = 0;
    max1 = 0;
    double UnitMatrix[n][n];
    double Inverse_Matrix[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Inverse_Matrix[i][j] = arr2[i][j];
            //Создание еденичной матрицы (главная диогональ 1)
            UnitMatrix[i][j] = 0.0;
            if (i == j)
                UnitMatrix[i][j] = 1.0;
        }
    }
    //-------------

    for (int k = 0; k < n; k++) {
        temp = Inverse_Matrix[k][k];
        for (int j = 0; j < n; j++) {
            Inverse_Matrix[k][j] /= temp;
            UnitMatrix[k][j] /= temp;
        }
        for (int i = k + 1; i < n; i++) {
            temp = Inverse_Matrix[i][k];
            for (int j = 0; j < n; j++) {
                Inverse_Matrix[i][j] -= Inverse_Matrix[k][j] * temp;
                UnitMatrix[i][j] -= UnitMatrix[k][j] * temp;
            }
        }
    }

    for (int k = n - 1; k > 0; k--) {
        for (int i = k - 1; i >= 0; i--) {
            temp = Inverse_Matrix[i][k];
            for (int j = 0; j < n; j++) {
                Inverse_Matrix[i][j] -= Inverse_Matrix[k][j] * temp;
                UnitMatrix[i][j] -= UnitMatrix[k][j] * temp;
            }
        }
    }
    //----------------------------------
    //cout<< " —--Inverse Matrix----"<< endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Inverse_Matrix[i][j] = UnitMatrix[i][j];
            //cout << " "<< Inverse_Matrix[i][j] << " ";
        }
        //cout << endl <<endl;
    }
    s = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
            s += arr2[i][j];
        if (max < s) max = s;
        s = 0;
    }
    cout << "lymbda max \n" << max;
    cout << endl;
    s = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
            s += Inverse_Matrix[i][j];
        if (max1 < s) max1 = s;
        s = 0;
    }
    cout << "lymbda min \n" << max1;
    cout << endl;
    cout <<"chislo obuslovlennosty matricy = "<< max * max1 << endl;

        






            //метод гаусса
            double  tmp, kor[a];
            int v;
            for (i = 0; i < a; i++)
                {
                    tmp = arr2[i][i];
                    for (j = a; j >= i; j--)
                    arr2[i][j] /= tmp;
                    for (j = i + 1; j < a; j++)
                            {
                                tmp = arr2[j][i];
                                for (v = a; v >= i; v--)
                                arr2[j][v] -= tmp * arr2[i][v];
                            }
                }
            /*обратный ход*/
            kor[a - 1] = arr2[a - 1][a];
            for (i = a - 2; i >= 0; i--)
                {
                    kor[i] = arr2[i][a];
                    for (j = i + 1; j < a; j++) kor[i] -= arr2[i][j] * kor[j];
                }

            for(int i = 0; i < a; i++)
                {
                    cout <<"x"<<i+1<<"= "<<kor[i]<<endl;
                }
            
            //проверка 3 строчки, сошлось
           // X =  kor[0]/3+ kor[1]/3 +kor[2]*10+kor[3]/3 ;
            //cout<< X;
           // cout << endl;



            
            //обьявление матрицы для нахождения невязки гаусса
            for (int i = 0; i < a; i++)
                {
                     arr2[i][i] = 10;
                }
            for (int i = 0; i < a; i++)
                {
                     arr2[i-1][i] = 1.0 / i;
                }   
            
            for (int i = 0; i < a; i++)
                {
                     for (int j = 0; j < i; j++)
                            {
                                arr2[i][j] = 1.0 /(i + 1); // если тут заменить на j то цифры будут увеличиться последовательно
                            }
                }
            
            for (int i = 1; i < b+1; i++)  
                {
                    for (int j = 1; j < b; j++)
                        {
                            arr2[i-1][b-1] = i;
                        }
                }       


            // нахождение невязки для гаусса
            c=0;
            for (int i = 0; i < 100; i++)
                {
                    for (int j = 0; j < 100; j++)
                        {
                            c = c + arr2[i][j] * kor[j];
                            
                        }
                            po1[i] = c - arr2[i][100];
                            c = 0;
                }
                c = 0;
                for (int i = 0; i < 100; i++)
                    {
                        c += po1[i] * po1[i];

                    }
                cout << "norma vectora nevyzki dly gaussa = " << sqrt(c) << endl;


               


            //обьявление матрицы для нахождения невязки пвр
            for (int i = 0; i < a; i++)
                {
                     arr2[i][i] = 10;
                }
            for (int i = 0; i < a; i++)
                {
                     arr2[i-1][i] = 1.0 / i;
                }   
            
            for (int i = 0; i < a; i++)
                {
                     for (int j = 0; j < i; j++)
                            {
                                arr2[i][j] = 1.0 /(i + 1); // если тут заменить на j то цифры будут увеличиться последовательно
                            }
                }
            
            for (int i = 1; i < b+1; i++)  
                {
                    for (int j = 1; j < b; j++)
                        {
                            arr2[i-1][b-1] = i;
                        }
                }  

            

            // невязка для пвр
            h=0;
            for (int i = 0; i < 100; i++)
                {
                    for (int j = 0; j < 100; j++)
                        {
                            h = h + arr2[i][j] * xx[j];

                        }
                            po1[i] = h - arr2[i][100];
                            h = 0;
                }
                h = 0;
                for (int i = 0; i < 100; i++)
                    {
                        h += po1[i] * po1[i];
                        
                    } 
                cout << "norma vectora nevyzki dly pvr = " << sqrt(h) << endl;


     

                  ofstream fout("ans1.dat");   
             
                  for (i = 0; i < n; i++)
                  {
                    fout <<xx[i]<<endl;
                  }
                 
                 fout.close();
                
                 ofstream fout1("ans2.dat");   
             
                  for (i = 0; i < n; i++)
                  {
                    fout1 <<kor[i]<<endl;
                  }
                 
                 fout1.close();




    return 0;
  }