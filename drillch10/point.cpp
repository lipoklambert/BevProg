#include "std_lib_facilities.h"

struct Point{

	double x;
	double y;

};

int main(){

	try{
	
	vector<Point> original_points;
	double x, y;
	
	int a = 0;
	
	while(a != 7){
		cin >> x >> y;
		original_points.push_back(Point{x, y});
		++a;
	} 
	
	string ofname = "mydata.txt";
	ofstream ost {ofname};
	if (!ost) error("Can't open output file ", ofname);
	
	for(const auto& point : original_points){
		ost << point.x << ' ' << point.y << endl;
	}
	
	ost.close();
	
	string ifname = "mydata.txt";
	ifstream ist {ifname};
	if (!ist) error("Can't open input file ", ifname);
	
	vector<Point> processed_points;
	
	while(ist >> x >> y){
		processed_points.push_back(Point{x, y});
	}
	
	if(original_points.size() == processed_points.size()){
		for(int i = 0; i < original_points.size(); ++i){
			if(original_points[i].x != processed_points[i].x || original_points[i].y != processed_points[i].y){
				cout << "Something's wrong!" << endl;
			}
		}
	}
	
	else{
		cout << "Something's wrong!" << endl;
	}
	
	return 0;
	
	}
	
	catch(exception& e){
		cerr << e.what() << endl;
		return 1;
	}
	
	catch(...){
		cerr << "Unknown exception!" << endl;
		return 2;
	}

}
