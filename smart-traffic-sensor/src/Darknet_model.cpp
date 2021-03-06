#include <DarknetAPI/DarknetAPI.h>
#include <iostream>
#include "Darknet_model.h"
#include <ClassTypeGeneric.h>
#include <boost/shared_ptr.hpp>


std::string NET_WEIGHTS = "../cfg/yolov3-voc_17000.weights";
std::string NET_CONFIG = "../cfg/yolov3-voc.cfg";
std::string TF_LABELLIST_PATH = "../names/label.names";
float const TF_PREDICTION_THRESSHOLD = 0.5;
boost::shared_ptr<DarknetAPI> cnn; 

namespace trafficmonitor{

DarknetModel::DarknetModel()
{
   if (!darknet_init(TF_LABELLIST_PATH, NET_WEIGHTS,NET_CONFIG))
   {
      std::cout << "Cannot initialize darknet" << std::endl;
   }
}

// Loads the graph into the session and starts up the labels map
bool DarknetModel::darknet_init(const std::string& labels_file_name,const std::string& netWeights, const std::string &netConfig)
{
   classNamesFile = labels_file_name;
   cnn = boost::shared_ptr<DarknetAPI>(new DarknetAPI((char*)netConfig.c_str(), (char*)netWeights.c_str()));
   std::cout << "Loaded Darknet Model" << '\n';
   return true;
}

int DarknetModel::find_blobs(colorspaces::Image& _frame, std::vector<Blob*>& new_blobs)
{
   int error = 0;
   Mat new_frame(_frame);
   int blob_counter = 0;
   double confidence_threshold = 0.4;
   std::string clase_vehicle;
   int inputHeight = new_frame.size().height;
   int inputWidth = new_frame.size().width;
   cv::Mat outputImg(inputHeight, inputWidth, CV_8UC3);
   new_frame.convertTo(outputImg, CV_8UC3);
	
   std::cout<<"find blobs \n";

   cv::Mat rgbImage;
   cv::cvtColor(new_frame,rgbImage,CV_RGB2BGR);
   
    DarknetDetections detections = cnn->process(rgbImage, (float)confidence_threshold);
    std::cout<<"Hecho procces \n";
    ClassTypeGeneric typeConverter(classNamesFile);

    for (auto it = detections.data.begin(), end=detections.data.end(); it !=end; ++it){
                typeConverter.setId(it->classId);
                std::cout<<"it classid : "<<it->classId<<'\n';
		int boxClass = it->classId;


         	float x1 = it->detectionBox.x ;
         	float y1 = it->detectionBox.y ;

         	float x2 = it->detectionBox.x + it->detectionBox.width;
         	float y2 = it->detectionBox.y + it->detectionBox.height ;
		Vehicle* curr_vehicle = static_cast<Vehicle*> (new_blobs[blob_counter]);
          	//std::cout<<"x1: "<< x1<<" y1: "<<y1<<" x2: "<<x2<<" y2: "<<y2<<'\n';
		curr_vehicle->init();
		//std::cout<<"curr vehicle iniciado "<<'\n';
         	curr_vehicle->set_id(blob_counter+1);
		//std::cout<<"hecho set ide con blob counter: "<<blob_counter+1<<'\n';
         	curr_vehicle->set_rect(x1,y1,x2,y2);
		//std::cout<<"Hecho set rect "<<'\n';
		tvehicle_category category = INVALID_VEHICLE_CLASS;
		clase_vehicle = typeConverter.getClassString();
		//std::cout<<"clase_vehicle: "<<clase_vehicle<<'\n';
		if(clase_vehicle == "car")
			category =  CAR;
		else if(clase_vehicle == "motorcycle")
			category =  MOTORCYCLE;
		else if(clase_vehicle == "van")
			category =  VAN;
		else if(clase_vehicle == "bus")
			category =  BUS;
		else if(clase_vehicle == "truck")
			category =  TRUCK;
		else if(clase_vehicle == "small-truck")
			category =  SMALL_TRUCK;
		else if(clase_vehicle == "tank-truck")
			category =  TANK_TRUCK;
		//std::cout<<"category: "<<category<<'\n';
		curr_vehicle->set_category(category);
		// Creo que asi tambien funcionaria ,probarcurr_vehicle.set_id(it->classId);
		//std::cout<<"category"<<category<<'\n';
		
		if (error == 0)
		{
			//std::cout<< it->detectionBox.x << " " << it->detectionBox.y << " " << it->detectionBox.height << " " << it->detectionBox.width << std::endl;
			//std::cout<<"clase_vehicle: "<<clase_vehicle<<'\n';
			/*putText(_frame,clase_vehicle, Point(x1,y1-2), FONT_HERSHEY_DUPLEX, 0.5, Scalar(255,0,0), 1);
 			rectangle(_frame, Point(x1,y1), Point(x2,y2), Scalar(255,0,0), 1);*/
			error = 0;
		}
	blob_counter++;
    }
    return blob_counter;


}



} // namespace
