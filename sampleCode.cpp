#include <iostream>
// #include <opencv2/opencv.hpp>
// #include <opencv2/core.hpp>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/utils/trace.hpp>


using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // Read the image file
    CommandLineParser parser( argc, argv, "{@input | lena.jpg | input image}" );
    Mat image = imread( samples::findFile( parser.get<String>( "@input" ) ) );

    // Check for failure
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    Mat imageBrighnessHigh40;
    image.convertTo(imageBrighnessHigh40, -1, 1, 40); //increase the brightness by 40

    Mat imageBrighnessHigh20;
    image.convertTo(imageBrighnessHigh20, -1, 1, 20); //increase the brightness by 20

    Mat imageBrighnessLow20;
    image.convertTo(imageBrighnessLow20, -1, 1, -20); //decrease the brightness by 20

    Mat imageBrighnessLow40;
    image.convertTo(imageBrighnessLow40, -1, 1, -40); //decrease the brightness by 40

    Mat imageBrighnessLow70;
    image.convertTo(imageBrighnessLow70, -1, 1, -70); //decrease the brightness by 70

    //Defining window names for above images
    String windowNameOriginalImage = "Original Image";
    String windowNameBrightnessHigh40 = "Brightness Increased by 40";
    String windowNameWithBrightnessHigh20 = "Brightness Increased by 20";
    String windowNameBrightnessLow20 = "Brightness Decreased by 20";
    String windowNameBrightnessLow40 = "Brightness Decreased by 40";
    String windowNameBrightnessLow70 = "Brightness Decreased by 70";

    //Create and open windows for above images
    namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessHigh40, WINDOW_NORMAL);
    namedWindow(windowNameWithBrightnessHigh20, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow20, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow40, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow70, WINDOW_NORMAL);

    //Show above images inside the created windows.
    imshow(windowNameOriginalImage, image);
    imshow(windowNameBrightnessHigh40, imageBrighnessHigh40);
    imshow(windowNameWithBrightnessHigh20, imageBrighnessHigh20);
    imshow(windowNameBrightnessLow20, imageBrighnessLow20);
    imshow(windowNameBrightnessLow40, imageBrighnessLow40);
    imshow(windowNameBrightnessLow70, imageBrighnessLow40);

    waitKey(0); // Wait for any key stroke

    destroyAllWindows(); //destroy all open windows

    return 0;
}