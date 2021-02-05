
// Librerías que contienen funciones estándar de C++
#include <iostream>
#include <cstdlib>


// Librería que contiene funciones matemáticas
#include <cmath>

// Librerías de OpenCV

// Se pueden cargar todas las Librerías incluyendo
//#include <opencv2/opencv.hpp>

#include <opencv2/core/core.hpp> 
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/videoio/videoio.hpp>

using namespace std;
using namespace cv; // Espacio de nombres de OpenCV (Contiene funciones y definiciones de varios elementos de OpenCV)

int * Historgrama(Mat imagen) {
    //histograma de la imagen
   int * histo  = new int[256];
    for (int i = 0; i < 256; i++)
        histo[i] = 0;
    Vec3b pixel;
    for (int i = 0; i < imagen.rows; i++) {
        for (int j = 0; j < imagen.cols; j++) {
            pixel = imagen.at<Vec3b>(i, j);
            histo[pixel[0]]++;
        }
    }
    return histo;
}
double dEuclidea(int m1[256], int m2[256]) {
    double suma = 0.0;
    for (int i = 0; i < 7; i++) {
        suma += (m1[i] - m2[i]) * (m1[i] - m2[i]);
    }
    return sqrt(suma);
}

void comparar() {
    int* histoImg [2];
    Mat imagen [2]; 
    double distancia = 0.0;
    double distanciaMenor = 999999999999999999.9;
    string numero;
    string nombre = ".\\CORPUS-IMAGENES-1\\image_00";
    for (int i = 1; i < 57; i++) {
        numero = i < 10 ? "0" + to_string(i) : to_string(i);
        cout << nombre + numero + ".jpg" << endl;
        if (i % 2 == 0) {
            imagen[1] = imread(nombre + numero + ".jpg");
            histoImg[0] = Historgrama(imagen[0]);
            histoImg[1] = Historgrama(imagen[1]);
            distancia = dEuclidea(histoImg[0], histoImg[1]);
            if (distancia < distanciaMenor)
                distanciaMenor = distancia;
            cout << distancia << endl;
        }
        else {
            imagen[0] = imread(nombre + numero + ".jpg");
        }
    }
    cout << "Distancia Azul" << distanciaMenor << endl;
}
int main (int arcg, char *argv[]){
    //Resultados 
    //https://github.com/braulio1996/ExamenFinalIA2
    comparar();
    cout << "PDF " << "https://github.com/braulio1996/ExamenFinalIA2"<< endl;
}


