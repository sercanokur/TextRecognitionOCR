#include <string>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
    string recognizedText;
    string imagePath = argv[1];

    // Define Initial Tesseract Object object
    tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();
  
    //Initialize OCR engine to use English (eng) and The LSTM OCR engine.
    ocr->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);
  
    // Set Page segmentation mode to PSM_AUTO (3)
    ocr->SetPageSegMode(tesseract::PSM_AUTO);
  
    // Open input image using OpenCV
    Mat image = cv::imread(imagePath, IMREAD_COLOR);
  
    // Set image data
    ocr->SetImage(image.data, image.cols, image.rows, 3, image.step);
    
    // Run Tesseract OCR on image
    recognizedText = string(ocr->GetUTF8Text());

    // Print recognized text in console
    cout << recognizedText << endl;

    // Kill used object and release memory
    ocr->End();
  
    return EXIT_SUCCESS;
}