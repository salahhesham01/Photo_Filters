#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];


void loadImage ();
void saveImage ();
void merge();
void darkenandlighten();
void enlarge_Image ();
void blur();
void shrink();
void black_white();
void shuffleImage ();



int main() {

    int choice;
    cout << "Ahalan ya user ya habibi"<<endl;
    loadImage();
    cout << "3-merge" <<endl << "6-Darken and Lighten" << endl << "9-Shrink" << endl << "12-Blur" << endl;
    cout << "Please select a filter to apply:  ";
    cin >> choice;
    if (choice == 3) {
        merge();
        saveImage();
    } else if (choice == 6) {
        darkenandlighten();
        saveImage();
    } else if (choice == 8){
        enlarge_Image();
        saveImage();
    } else if (choice == 9){
        shrink();
        saveImage();
    } else if(choice == 11){
        shuffleImage();
    } else if(choice == 12){
        blur();
        saveImage();
    }


    return 0;
}


void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}
//filter 1
void black_white()
{
    int avv;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

          avv = (image[i][j][1]+image[i][j][2]+image[i][j][3])/3;        // calculate the avarage of black in the photo

          for(int k = 0; k < 3; k++){

            if (avv >=128){            // if the pixel is darken the turn it to black

              image[i][j][k] = 255;
            }
            else if (avv < 128){
                    // // if the pixel is lighten the turn it to white
              image[i][j][k] = 0;
            }

            }
          }
    }
}
void merge()
{
    char image2FileName[100];

    // Get gray scale image file name
    cout << "Enter image file name: ";
    cin >> image2FileName;

    // Add to it .bmp extension and load image
    strcat (image2FileName, ".bmp");
    readGSBMP(image2FileName, image2);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

                image[i][j] =  (image[i][j] + image2[i][j])/2;


        }
    }
}

void darkenandlighten()
{   int num =0 ;
    char choice1;
    cout << "Do you want (d)arken or (l)igten: ";
    cin>> choice1;
    if (choice1 == 'l')
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {

                    num = image[i][j] + image[i][j] / 2;
                    if (num > 255)
                        num = 255;
                    image[i][j] = num;
            }
        }
    }
    else if (choice1 = 'd')
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {

                    image[i][j] = image[i][j]/2;

            }
        }
    }
    else
        cout << "Invalid input ";

}

void enlarge_Image() {
  int quar;

  cout<<"Which quarter to enlarge 1, 2, 3 or 4? : ";
  cin>>quar;

  if (quar == 1){
    for (int i = 0; i < SIZE; i+=2) {
      for (int j = 0; j< SIZE; j+=2) {

        image[i][j] = image2[i/2][j/2];         // take every pixel and copy it 2 times in row and column in a new photo
        image[i+1][j] = image2[i/2][j/2];
        image[i][j+1] = image2[i/2][j/2];
        image[i+1][j+1] = image2[i/2][j/2];
      }
    }
  }
  
  if (quar == 2){
    for (int i = 0; i < SIZE; i+=2) {
      for (int j = 0; j< SIZE; j+=2) {

        image[i][j] = image2[i/2][j/2+SIZE/2];
        image[i+1][j] = image2[i/2][j/2+SIZE/2];
        image[i][j+1] = image2[i/2][j/2+SIZE/2];
        image[i+1][j+1] = image2[i/2][j/2+SIZE/2];
      }
    }
  }
  
  if (quar == 3){
    for (int i = 0; i < SIZE; i+=2) {
      for (int j = 0; j< SIZE; j+=2) {

        image[i][j] = image2[i/2+SIZE/2][j/2];
        image[i+1][j] = image2[i/2+SIZE/2][j/2];
        image[i][j+1] = image2[i/2+SIZE/2][j/2];
        image[i+1][j+1] = image2[i/2+SIZE/2][j/2];
      
      }
    }
  }
  
  if (quar == 4){
    for (int i = 0; i < SIZE; i+=2) {
      for (int j = 0; j< SIZE; j+=2) {

        image[i][j] = image2[i/2+SIZE/2][j/2+SIZE/2];
        image[i+1][j] = image2[i/2+SIZE/2][j/2+SIZE/2];
        image[i][j+1] = image2[i/2+SIZE/2][j/2+SIZE/2];
        image[i+1][j+1] = image2[i/2+SIZE/2][j/2+SIZE/2]; 
      }
    }
  }
  
  
}

void blur(){

    double average;

    for (int i = 0; i <SIZE; i++) {
        for (int j = 0; j<SIZE; j++) {
                int sum = 0;
                sum = image[i-1 ][j-1 ]+ image[i-1 ][j] + image[i-1][j + 1] + image[i][j-1] + image[i][j] +image[i][j +1] + image[i +1][j-1 ] + image[i + 1][j] + image[i + 2][j + 1];
                average = (sum / 9);
                image[i][j] = average;


        }
    }
}
void shrink()
{
    int choice;
    cout << "Shrink to 1-(1/2), 2-1/3) or 3-(1/4)?";
    cin >> choice;
    if(choice==1){
        for (int i =0 ; i <SIZE;i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i / 2][j / 2] = image[i][j];
            }

        }
        for (int i =SIZE/2; i < SIZE; i++){
            for(int j =0 ; j<SIZE;j++)
            {
                image[i][j] = 255;
            }
        }
        for (int i =0; i < SIZE; i++){
            for(int j =SIZE/2; j<SIZE;j++)
            {
                image[i][j] = 255;

            }
        }
    }
    else if(choice==2){
        for (int i =0 ; i <SIZE;i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i / 3][j / 3] = image[i][j];
            }

        }
        for (int i =SIZE/3; i < SIZE; i++){
            for(int j =0 ; j<SIZE;j++)
            {
                image[i][j] = 255;
            }
        }
        for (int i =0; i < SIZE; i++){
            for(int j =SIZE/3; j<SIZE;j++)
            {
                image[i][j] = 255;

            }
        }
    }
    else if(choice==3){
        for (int i =0 ; i <SIZE;i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i / 4][j / 4] = image[i][j];
            }

        }
        for (int i =SIZE/4; i < SIZE; i++){
            for(int j =0 ; j<SIZE;j++)
            {
                image[i][j] = 255;
            }
        }
        for (int i =0; i < SIZE; i++){
            for(int j =SIZE/4; j<SIZE;j++)
            {
                image[i][j] = 255;

            }
        }
    }
    else
        cout << "Invalid input";
}


void shuffleImage() {
  char order[5];

  cout<<"New order of quarters ? : ";
  cin>>order;

  for(int k = 0; k < 4; k++){

    if(k == 0 && order[k] == '1'){
      for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE/2; j++) {
          image[i][j] = image2[i][j];
        }
      }
    }
    else if(k == 0 && order[k] == '2'){
      for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE/2; j++) {
          image[i][j] = image2[i][j+SIZE/2];
        }
      }
    }
    else if(k == 0 && order[k] == '3'){
      for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE/2; j++) {
          image[i][j] = image2[i+SIZE/2][j];
        }
      }
    }
    else if(k == 0 && order[k] == '4'){
      for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE/2; j++) {
          image[i][j] = image2[i+SIZE/2][j+SIZE/2];
        }
      }
    }

    if(k == 1 && order[k] == '1'){
      for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE/2; j++) {
          image[i][j+SIZE/2] = image2[i][j];
        }
      }
    }
    else if(k == 1 && order[k] == '2'){
      for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE/2; j++) {
          image[i][j+SIZE/2] = image2[i][j+SIZE/2];
        }
      }
    }
    else if(k == 1 && order[k] == '3'){
      for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE/2; j++) {
          image[i][j+SIZE/2] = image2[i+SIZE/2][j];
        }
      }
    }
    else if(k == 1 && order[k] == '4'){
      for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE/2; j++) {
          image[i][j+SIZE/2] = image2[i+SIZE/2][j+SIZE/2];
        }
      }
    }

    if(k == 2 && order[k] == '1'){
      for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE/2; j++) {
          image[i+SIZE/2][j] = image2[i][j];
        }
      }
    }
    else if(k == 2 && order[k] == '2'){
      for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE/2; j++) {
          image[i+SIZE/2][j] = image2[i][j+SIZE/2];
        }
      }
    }
    else if(k == 2 && order[k] == '3'){
      for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE/2; j++) {
          image[i+SIZE/2][j] = image2[i+SIZE/2][j];
        }
      }
    }
    else if(k == 2 && order[k] == '4'){
      for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE/2; j++) {
          image[i+SIZE/2][j] = image2[i+SIZE/2][j+SIZE/2];
        }
      }
    }

    if(k == 3 && order[k] == '1'){
      for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE/2; j++) {
          image[i+SIZE/2][j+SIZE/2] = image2[i][j];
        }
      }
    }
    else if(k == 3 && order[k] == '2'){
      for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE/2; j++) {
          image[i+SIZE/2][j+SIZE/2] = image2[i][j+SIZE/2];
        }
      }
    }
    else if(k == 3 && order[k] == '3'){
      for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE/2; j++) {
          image[i+SIZE/2][j+SIZE/2] = image2[i+SIZE/2][j];
        }
      }
    }
    else if(k == 3 && order[k] == '4'){
      for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE/2; j++) {
          image[i+SIZE/2][j+SIZE/2] = image2[i+SIZE/2][j+SIZE/2];
        }
      }
    }

  }
}

