#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

main(){
    int n = 20000;
    double x, y, z;
    double tempX, tempY, tempZ;
    tempX = tempY = tempZ = 0;
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
                ksi = x*y*(z*z);
                tempX += x; 
                tempY += y;
                tempZ += z;            
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
            file << histogramData[i] << endl;
        }
    }
    file.close();

    ofstream file2;   
    file2.open("SampleMean.txt");
    if (file2.is_open()){
        //выборочное среднее
        x = tempX/n;
        y = tempY/n;
        z = tempZ/n;
        file2 << x << " " << y << " " << z << endl;
    }
    file2.close();

    std::cout << "End of program" << std::endl;
    return 0;
}