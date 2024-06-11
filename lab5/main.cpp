#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include <chrono>

using namespace std;
using namespace cv;

int main() {

    VideoCapture capture(0);

    int frames_counter = 0;
    int total_input = 0;
    int total_convertion = 0;
    int total_output = 0;
    int total_time = 0;
    int total_waiting = 0;

    while (true) {
        frames_counter++;
        auto start = chrono::system_clock::now();

        Mat frame;
        capture.read(frame);  

        auto input = chrono::system_clock::now();

        for (int y = 0; y < frame.cols; y++) {
            for (int x = 0; x < frame.rows; x++) {
                for (int channel = 0; channel < 2; channel++) {
                    uchar color = frame.at<Vec3b>(x, y)[channel];
                    frame.at<Vec3b>(x, y)[channel] = (uchar)255 - 2*color;
                }
            }
        }

        frame.convertTo(frame, -1, 4, 0);
        frame.convertTo(frame, -1, 1, -50);

        auto convertion = chrono::system_clock::now();

        imshow("monkey", frame);  

        auto output = chrono::system_clock::now(); 

        char c = waitKey(1);

        auto waiting = chrono::system_clock::now();

        if (c == 27) {
            break;
        }

        auto end = chrono::system_clock::now();

        total_input += chrono::duration_cast<std::chrono::milliseconds>(input - start).count();
        total_convertion += chrono::duration_cast<std::chrono::milliseconds>(convertion - input).count();
        total_output += chrono::duration_cast<std::chrono::milliseconds>(output - convertion).count();
        total_waiting += chrono::duration_cast<std::chrono::milliseconds>(waiting - output).count();
        total_time += chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    }

    capture.release();
    destroyWindow("monkey");

    double fps = (double)frames_counter * 1000 / total_time;
    double inp = (double)total_input * 100 / total_time;
    double cnv = (double)total_convertion * 100 / total_time;
    double out = (double)total_output * 100 / total_time;
    double wt = (double)total_waiting * 100 / total_time;

    cout << "total time: " << total_time << endl;
    cout << "FPS: " << fps << endl;
    cout << "input: " << total_input << endl;
    cout << "convertion: " << total_convertion << endl;
    cout << "output: " << total_output << endl;
    cout << "waiting: " << total_waiting << endl;
    cout << "time for input: " << inp << "%" << endl;
    cout << "time for converting: " << cnv << "%" << endl;
    cout << "time for output: " << out << "%" << endl;
    cout << "time for waiting: " << wt << "%" << endl;
    return 0;

}
