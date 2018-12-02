 #include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <NuiApi.h>
#include <NuiImageCamera.h>
#include <opencv2\opencv.hpp>
using namespace cv;
using namespace std;
int x[20]={0};
int sht=0;
int y[20]={0};int ctr=0;
int se=0;
float mx[20]={0},my[20]={0};
int detM=0;
Mat draw(Mat image)
{line(image, Point(x[3],y[3]),Point(x[2],y[2]),CV_RGB(0, 255, 0));
line(image, Point(x[2],y[2]),Point(x[1],y[1]),CV_RGB(0, 255, 0));
line(image, Point(x[1],y[1]),Point(x[0],y[0]),CV_RGB(0, 255, 0));
line(image, Point(x[11],y[11]),Point(x[10],y[10]),CV_RGB(0, 255, 0));
line(image, Point(x[10],y[10]),Point(x[9],y[9]),CV_RGB(0, 255, 0));
line(image, Point(x[9],y[9]),Point(x[8],y[8]),CV_RGB(0, 255, 0));
line(image, Point(x[8],y[8]),Point(x[2],y[2]),CV_RGB(0, 255, 0));
line(image, Point(x[2],y[2]),Point(x[4],y[4]),CV_RGB(0, 255, 0));
line(image, Point(x[4],y[4]),Point(x[5],y[5]),CV_RGB(0, 255, 0));
line(image, Point(x[5],y[5]),Point(x[6],y[6]),CV_RGB(0, 255, 0));
line(image, Point(x[6],y[6]),Point(x[7],y[7]),CV_RGB(0, 255, 0));
line(image, Point(x[0],y[0]),Point(x[16],y[16]),CV_RGB(0, 255, 0));
line(image, Point(x[16],y[16]),Point(x[17],y[17]),CV_RGB(0, 255, 0));
line(image, Point(x[17],y[17]),Point(x[18],y[18]),CV_RGB(0, 255, 0));
line(image, Point(x[18],y[18]),Point(x[19],y[19]),CV_RGB(0, 255, 0));
line(image, Point(x[0],y[0]),Point(x[12],y[12]),CV_RGB(0, 255, 0));
line(image, Point(x[12],y[12]),Point(x[13],y[13]),CV_RGB(0, 255, 0));
line(image, Point(x[13],y[13]),Point(x[14],y[14]),CV_RGB(0, 255, 0));
line(image, Point(x[14],y[14]),Point(x[15],y[15]),CV_RGB(0, 255, 0));
return image;
}
Mat gesture(Mat image)
{Mat sto=image;
	if(detM==0)
{putText(image,"ENTER DETECTION MODE",Point(200,100),FONT_HERSHEY_SIMPLEX,1,Scalar(0,200,200),4);
	//if((100*(my[11]-my[3]))>20 && (100*(mx[11]-mx[3]))>5)
		//ctr++;
	//else ctr=0;
	if((y[11]-100)<10 && (x[11]-200)<10)//if(ctr>5)
		{image=sto;
	//putText(image,"DETECTION MODE",Point(200,100),FONT_HERSHEY_SIMPLEX,1,Scalar(255,255,0),4);
	detM=1;
	ctr=0;
	}}
	 if(detM==1)
	  { if(sht==1)
	 { putText(image,"CONFIRM",Point(320,40),FONT_HERSHEY_SIMPLEX,1,Scalar(200,0,200),4);
        putText(image,"YES",Point(220,140),FONT_HERSHEY_SIMPLEX,1,Scalar(200,0,200),4);
	    putText(image,"NO",Point(420,140),FONT_HERSHEY_SIMPLEX,1,Scalar(200,0,200),4);
	 	if((y[11]-140)<10 && (x[11]-220)<10)
			sht=2;
		else if((y[11]-140)<10 && (420-x[11])<10)
			sht=0;
	 }
		  
	 if(sht==0)
	 {  
		  
		  putText(image,"SHUTDOWN",Point(500,380),FONT_HERSHEY_SIMPLEX,1,Scalar(200,0,200),4);
	
		putText(image,"DETECTION MODE",Point(200,100),FONT_HERSHEY_SIMPLEX,1,Scalar(200,0,200),4);
	 if((380-y[11])<10 && (500-x[11])<10)
		 sht=1;
		if(my[10]>my[9])// hello start
	 {//float dist=sqrt(((my[10]-my[8])*(my[10]-my[8]))+((mx[10]-mx[8])*(mx[10]-mx[8])));
	if(se==0){
		 if(100*(mx[11]-mx[8])<5)
			 se=1;}
	else if(se==1)
	{if(mx[11]>mx[9])
	{image=sto;
	putText(image,"Hello",Point(20,300),FONT_HERSHEY_SIMPLEX,1,Scalar(255,255,255),4); 
	cout<<"hello\n";
	waitKey(200);
	 se=0;
	
	}
	}
	 } // hello end
		if ((x[11]-x[3])<5 && (y[11]-y[3])<5)
			putText(image,"I need a Doctor",Point(20,400),FONT_HERSHEY_SIMPLEX,1,Scalar(255,255,255),4); 
	    else if((x[11]-x[7])<5 && (x[11]-x[1])<5 && (y[11]-y[7])<5)
	       putText(image,"I am Hungry",Point(20,400),FONT_HERSHEY_SIMPLEX,1,Scalar(255,255,255),4); 
		else if((x[11]-x[7])<5 && (x[11]-x[2])<5 && (y[11]-y[2])<10)
	       putText(image,"I am Sorry",Point(20,400),FONT_HERSHEY_SIMPLEX,1,Scalar(255,255,255),4); 
		else if((y[11]-y[8])<10 && (y[11]-y[8])>0 &&(y[7]-y[4])<10 && (y[7]-y[4])>0)
	    putText(image,"I Don't Know",Point(20,400),FONT_HERSHEY_SIMPLEX,1,Scalar(255,255,255),4); 
	 }
	
	}
	
	
	
	
	
return image;

}
int main()
{float fx=0,fy=0,fx1=0,fy1=0;
int px=0,py=0,px1=0,py1=0; 
Mat frame;
cout << "Hello world" << endl;
   NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);
   NUI_SKELETON_FRAME ourframe;
   while (1)
   {Mat sam=Mat::zeros(480,640,CV_8UC3);
//VideoCapture cam(0);

  // cam>>frame;
     NuiSkeletonGetNextFrame(0, &ourframe);
     for (int i = 0; i < 6; i++)
     {
       if (ourframe.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED)
     {    cout << "Right Hand: " ;
         cout << ourframe.SkeletonData[i].SkeletonPositions[11].y << endl;
    /* fy=ourframe.SkeletonData[i].SkeletonPositions[11].y;
	 fx=ourframe.SkeletonData[i].SkeletonPositions[11].x;
	 fy1=ourframe.SkeletonData[i].SkeletonPositions[7].y;
	 fx1=ourframe.SkeletonData[i].SkeletonPositions[7].x;
	 px=(int)320*(fx+1);
	 py=(int)240*(fy+1);
	 py=480-py;*/for (int k=0;k<20;k++){
	 fy1=ourframe.SkeletonData[i].SkeletonPositions[k].y;
	 fx1=ourframe.SkeletonData[i].SkeletonPositions[k].x;
	 mx[k]=fx1;
	 my[k]=fy1;
	 px1=(int)320*(fx1+1);
	 py1=(int)240*(fy1+1);
	 py1=480-py1;
	 x[k]=px1;
	 y[k]=py1;
	 //circle(sam,Point(px,py),10,Scalar(0,0,255));
	 circle(sam,Point(px1,py1),10,Scalar(0,0,255));
	 }sam=draw(sam);
		 sam=gesture(sam);
	
	   }
	 }
	// imshow("pic",frame);
	 //waitKey(1);
	 imshow("win",sam);
	 waitKey(2);
     if(sht==2)
	{//putText(sam,"SHUTTING DOWN",Point(320,240),FONT_HERSHEY_SIMPLEX,1,Scalar(255,255,255),4); 
	 //waitKey(500);
	 break;
	}
   //video test
	 system("cls");
	  
   }
  NuiShutdown();
  return 0;
}