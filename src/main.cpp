#include <cstdlib>
#include "clothoid.h"
#include "state.h"
#include <time.h>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/core/mat.hpp"

using namespace std;

void plotPath(State start, State end, vector<State> pathToPlot,cv::Mat &img) {

    std::cout << pathToPlot.size() << std::endl;
    // std::cout << start.x << " " << HEIGHT - start.y << " " << end.x << " " << HEIGHT - start.y << std::endl; 
    cv::circle(img, cv::Point(start.x, HEIGHT - start.y), 5, cv::Scalar(255,255,255));
    cv::circle(img, cv::Point(end.x, HEIGHT - end.y), 5, cv::Scalar(255,255,255));
    // cv::line(img, cv::Point(start.x, HEIGHT - start.y), cv::Point(end.x, HEIGHT - end.y), cv::Scalar(255,255,255));
    for (int i = 0; i + 1 < pathToPlot.size(); i++) {
        cv::line(img, cv::Point(pathToPlot[i].x, HEIGHT - pathToPlot[i].y), cv::Point(pathToPlot[i + 1].x, HEIGHT - pathToPlot[i + 1].y), cv::Scalar(255, 255, 255));
    }

    cv::imshow("PATH", img);
    cv::waitKey(0);
}

void Trajgen(State& a, State& b) {

    Clothoid curve;
    cv::Mat img = cv::Mat(cv::Size(800, 800), CV_8UC3, cv::Scalar(0,0,0));
    double totLength=0;
    std::cout << "**************beginner Alert*****************************" << std::endl;
    curve.getPath(a, b);
    if (curve.solution == 0) {
        std::cout << "The points are too close !" << std::endl;
    }
    else {
        
        for(int j=0;j<curve.paths.size();j++){
            totLength+=curve.paths[j].lengthOfPath;
            plotPath(a, b, curve.paths[j].path,img);
        }
        std::cout<<"The total length : "<<totLength<<std::endl;
        cv::waitKey(0);
    }
}

int main(int argc,char *argv[]) {

    if (argc == 9) {
        // x,y,theta,curvature
        State start(std::stod(argv[1]),std::stod(argv[2]),std::stod(argv[3]),std::stod(argv[4]));
        State end(std::stod(argv[5]),std::stod(argv[6]),std::stod(argv[7]),std::stod(argv[8]));

        Trajgen(start, end);
	}
    else {
        std::cout << "insufficient input parameters..." << std::endl;
    }

}