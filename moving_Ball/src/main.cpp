#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	//values about the area and circle
	int imgX = 640, imgY = 480;
	namedWindow("Animation", 0);
	Mat img(imgY,imgX, CV_8UC3);
	Mat imgClone = img.clone();
	imgClone.copyTo(img);
	int pointX, pointY, ballRotation;
	srand(time(0));
	ballRotation = 0 + (int) (360.0 * (rand() / (RAND_MAX + 1.0)));
	pointX = 320;
	pointY = 240;
	int radius = 15, speed = 5;

	while(true)
	{

		//checking if circle hits the edge
		if(pointX - radius <= 0 || pointX + radius >= imgX)
		{
			ballRotation = 180 - ballRotation;
			if(pointX < radius)
				pointX = radius;
			if(pointX > imgX - radius)
				pointX = imgX - radius;
		}
		if(pointY - radius <= 0 || pointY + radius >= imgY)
		{
			ballRotation = -ballRotation;
			if(pointY < radius)
				pointY = radius;
			if(pointY > imgY - radius)
				pointY = imgY - radius;
		}

		//circle movement calculation
		pointX += speed*cos(ballRotation*M_PI/180);
		pointY += speed*sin(ballRotation*M_PI/180);
		circle(imgClone, Point(pointX, pointY), radius, Scalar(0,0,255), -1);
		imshow("Animation", imgClone);
		char exit = waitKey(40);
		//cleaning the old circle
		img.copyTo(imgClone);
		if(exit == 'e')
			break;
	}


	return 0;
}
