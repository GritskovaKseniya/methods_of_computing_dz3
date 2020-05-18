#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;


double createSelection (){
    double x, y, z;
    ofstream out;          // поток для записи
    out.open("D:\\sample3D.txt"); // окрываем файл для записи
    if (out.is_open()){
        for(int i = 0; i < 20; i++){
            x = rand() / double( RAND_MAX );
            y = rand() / double( RAND_MAX );
            z = rand() / double( RAND_MAX );
            double d = x*x + y*y + z*z;
            if(d < 1){
                cout << " d" << i << " = " << d << endl;
                cout << x*x << " " << y*y << " " << z*z << " " << endl;
                out << x << " " << y << " " << z << " " << endl;
            } else i--; 
        }
    }

}

int createHistogramData (){
    
}

main(){  
    createSelection();

    std::cout << "End of program" << std::endl;
    return 0;
}