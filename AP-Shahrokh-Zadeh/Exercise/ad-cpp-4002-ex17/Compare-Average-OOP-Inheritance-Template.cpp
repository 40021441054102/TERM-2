#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

template <class T> 
class Vector{
 	private:
	    T *score;
	    int size;
	    int primary;
 
public:

    Vector(){
        score = new T[1];
        size = 1;
        primary = 0;
    }
 
    void push(T data){

        if (primary == size) {
            T* temp = new T[2 * size];
 
             for (int i = 0; i < size; i++) {
                temp[i] = score[i];
            }
            delete[] score;
            size *= 2;
            score = temp;
        }
        score[primary] = data;
        primary++;
    }

    void push(T data, int index){
 
        if (index == size)
            push(data);
        else
            score[index] = data;
    }
 
    T get(int index) const{
        return score[index];
    }
    
    int size_vector() const { 
	return primary; 
	}

};

//==================================
class homework {
    public:
        homework(string);
        void add_score(float);
        string getName() const;
        float getAverage() ;
        int operator < (homework);
        float avg;
    private:
        string name;
        Vector <float> std_score;
};
//===================================
homework :: homework(string new_name){
	name = new_name;
}
//===================================
string homework :: getName ()const {
	return name;
}
//===================================
void homework :: add_score(float sc){
	std_score.push(sc);
}
//===================================    
float homework :: getAverage() {
	
	float sum;
	for(int i=0;i<std_score.size_vector();i++){
		sum += std_score.get(i);  		
	}
    avg = sum/std_score.size_vector();
    return avg;
}
//===================================
int homework :: operator < (homework h2) {
	if (this->avg > h2.avg) {
		return 1;
    }
	else if (this->avg < h2.avg) {
		return 2;
    }
    return this->avg < h2.avg;
}
//===================================
int main(){

    homework std1("student1");
	homework std2("student2");

    std1.add_score(15);
    std1.add_score(10);
    std1.add_score(14.25);
    
    std2.add_score(5);
    std2.add_score(10);
    std2.add_score(17.25);

    cout<<"Student1 Avg : "<<std1.getAverage()<<endl;
    cout<<"Student2 Avg : "<<std2.getAverage()<<endl;
    
    int compare = std1<std2;
    
	if(compare == 1)
		cout<<"Average of student 1 is higher !!\n";   
	else if(compare == 2) 
		cout<<"Average of student 2 is higher !!\n"; 
	else cout<<"Average of students are the same !!\n";
	
    return 0;
}