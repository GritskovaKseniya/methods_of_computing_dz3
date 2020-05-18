#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

main(){
    double x, y, z;
    ofstream fout;          // поток для записи
    fout.open("D:\\sample3D.txt"); // окрываем файл для записи
    if (fout.is_open()){
        for(int i = 0; i < 20; i++){
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

    double ksi; //случайная величина кси, которая задается как x*y*(z^2)
    int histogramData[100]; //создали массив для данных гистограммы

    // инициализируем его нулями
    for(int i = 0; i < sizeof(histogramData); i++){
        histogramData[i] = 0;
    }

    ifstream fin("D:\\sample3D.txt"); //открыли файл для чтения
    //если файл не закончился считываем слова
    if(fin.is_open()){
        fin >> x >> y >> z;
        ksi = x*y*(z*z);
        cout << ksi << endl;
    }
    fin.close();     // закрываем файл

    std::cout << "End of program" << std::endl;
    return 0;
}