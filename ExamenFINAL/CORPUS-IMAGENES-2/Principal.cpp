
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <opencv2/core/core.hpp> 
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
// Manejo de ventanas y eventos de ratón, teclado, etc.
#include <opencv2/highgui/highgui.hpp>
// Lectura de video
#include <opencv2/video/video.hpp>
// Escritura de video
#include <opencv2/videoio/videoio.hpp>

using namespace std;
using namespace cv; // Espacio de nombres de OpenCV (Contiene funciones y definiciones de varios elementos de OpenCV)

int main (int arcg, char *argv[]){
    Mat img = imread("image_0033.jpg",IMREAD_GRAYSCALE);
    int pixel;
    double promedio;
    for(int i=0; i < img.rows; i++){
        for(int j=0; j < img.cols; j++){
            pixel = img.at<uchar>(i,j);
            promedio+=pixel;
        }
    }
    cout <<"Intensidad GRIS :"<< promedio/(img.rows*img.cols) << endl;
   
    
    uchar imagen[4][4] = {{123,97,10,91},{89,47,19,101},{7,3,250,28},{13,1,0,200}};
    Mat mat(4,4,CV_8UC1,&imagen);
    Mat binaria;
    threshold(mat,binaria,40,1,THRESH_BINARY);
    Moments momentos = moments(binaria,true);
    cout <<"MOMENTO m01= "<< momentos.m01<< endl;
    
    
    
}


