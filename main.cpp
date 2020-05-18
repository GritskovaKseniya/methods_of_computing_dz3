#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

main(){
    double x, y, z;
    ofstream fout;          // поток для записи
    fout.open("D:\\sample3D.txt"); // окрываем файл для записи
    if (fout.is_open()){
        for(int i = 0; i < 5; i++){
            //генерируем случайные числа в диапазоне от 0 до 1
            x = rand() / double( RAND_MAX ); 
            y = rand() / double( RAND_MAX );
            z = rand() / double( RAND_MAX );
            // проверяем, чтобы эти переменные соответствовали условию x^2+y^2+z^2 < 1
            double d = x*x + y*y + z*z; 
            if(d < 1){
                
                //cout << "OUT: " << x << " " << y << " " << z << endl;
                
                //записываем переменые в файл 
                fout << x << " " << y << " " << z << " " << endl;
            } else i--; 
        }
    }
    fout.close();

    double ksi; //случайная величина кси, которая задается как x*y*(z^2)
    int histogramData[100]; //создали массив для данных гистограммы

    // инициализируем его нулями
    for(int i = 0; i < 100; i++){
        histogramData[i] = 0;
    }
    string s;

    ifstream fin("D:\\sample3D.txt"); //открыли файл для чтения
    //если файл не закончился считываем слова
    if(fin.is_open()){
        while(!fin.eof())
        {
            fin >> x >> y >> z;
            
            cout << "IN: " << x << " " << y << " " << z << endl;
            
            ksi = x*y*(z*z);

            //std::cout << "KSI: " << ksi << std::endl;
            
            for(double i = 0; i < 1; i+=0.01){ // i левый конец полуинтервала
                double r = i + 0.01; //правый конец полуинтервала
                if((ksi > i)&(ksi<= r)){
                    int s = int(i*100);
                    int k = histogramData[s] ++;
                }
            }
        }
    }
    fin.close();     // закрываем файл
/*
    for(int i = 0; i < 100; i++){
        double t1  = i;
        double t = t1/100;
        double d = t +0.01;
        cout << "[" << t << " ; " << d << "]" << " : " <<histogramData[i] << endl;
    }
*/
    std::cout << "End of program" << std::endl;
    return 0;
}