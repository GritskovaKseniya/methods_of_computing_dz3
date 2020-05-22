#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;

main(){
    int n = 20000;
    double x, y, z, sum , sum2;
    sum = 0; sum2 = 0;
    double ksi; //случайная величина кси, которая задается как x*y*(z^2)
    int histogramData[100]; //создали массив для данных гистограммы
    for(int i = 0; i < 100; i++){
        histogramData[i] = 0;
    }
    string line;

    ofstream fout; // поток для записи
    fout.open("D:\\sample3D.txt"); // окрываем файл для записи
    if (fout.is_open()){
        for(int i = 0; i < n; i++){
            //генерируем случайные числа в диапазоне от 0 до 1
            x = rand() / double( RAND_MAX ); 
            y = rand() / double( RAND_MAX );
            z = rand() / double( RAND_MAX );
            // проверяем, чтобы эти переменные соответствовали условию x^2+y^2+z^2 < 1
            double d = x*x + y*y + z*z; 
            if(d < 1){                
                //записываем переменые в файл 
                fout << x << " " << y << " " << z << " " << endl;
            } else i--; 
        }
    }
    fout.close();



    ifstream fin("D:\\sample3D.txt"); //открыли файл для чтения
    if(fin.is_open()){

        while(!fin.eof())
        {
            getline (fin,line);;
            if(line == ""){
                break;
            }else{
                stringstream sin(line);
                sin >> x >> y >> z;   
                //вычисляем кси       
                ksi = x*y*(z*z);
                sum += ksi;
                sum2 = sum2 + ksi*ksi;
                for(double i = 0; i < 1; i+=0.01){ // i левый конец полуинтервала
                    double r = i + 0.01; //правый конец полуинтервала
                    if((ksi > i)&(ksi<= r)){
                        int s = int(i*100);
                        int k = histogramData[s] ++;
                    }
                }
            }
        }
    }
    fin.close(); 
    

    ofstream file;   
    file.open("HistogramData.txt");
    for(int i = 0; i < 100; i++){
        if (file.is_open()){
            //записываем данные из массива в файл
            file << histogramData[i] << endl;
            /*double t1  = i;
            double t = t1/100;
            double d = t +0.01;
            cout << "[" << t << " ; " << d << "]" << " : " <<histogramData[i] << endl;*/
        }
    }
    file.close();

    ofstream file2;   
    file2.open("SampleMean.txt");
    if (file2.is_open()){
        //выборочное среднее (x c чертой)
        double sampleMean = sum/n;
        //x^2 с чертой
        double dev = sum2/n;
        // среднеквадратичное отклонение (сигма)
        double sigma = sqrt(dev - (sampleMean*sampleMean));
        double sigmaX = sigma/(sqrt(n));

        file2 << "Sample mean: " << sampleMean << endl;
        file2 << "Среднеквдратичное отклонение: " << sigma << endl;
        file2 << "Среднеквдратичное отклонение для устредненного икса: " << sigmaX << endl;
        file2 << "Доверительный интервал: [" << sampleMean - 2*sigma << "; " << sampleMean + 2*sigma << "]" << endl; 
    }
    file2.close();

    std::cout << "End of program" << std::endl;
    return 0;
}