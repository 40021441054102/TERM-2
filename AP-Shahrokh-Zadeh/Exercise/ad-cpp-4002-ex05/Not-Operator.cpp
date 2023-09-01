#include <iostream>
using namespace std;
class rect
{
    private :
        double width,length;
    public :
    rect():width(1),length(1){}
    rect(double, double);
    rect(const rect &);
    void set(double, double);
    double get_w(){return width;}
    double get_l(){return length ;}
    rect operator!();
    void display()
    {
        cout<<"length = "<<length<<endl;
        cout<<"width = "<<width;
    }
};
void rect::set(double w_, double l_)
{
    width = (w_ >= 0)? w_ : (-1 * w_);
    length = ( l_ >= 0)? l_ : (-1 * l_);
}
rect::rect(double w, double l)
{
    set(w,l);
}
rect::rect(const rect &r)
{
    width = r.width;
    length = r.length;
}

rect rect::operator!()
{
    double temp = length;
    length = width;
    width = temp;
    
}

int main()
{
    rect myRect;
    int ww,ll;
    cout << " give me input : (width -> length"<<endl;
    cin >> ww;
    cin >> ll;
    myRect.set(ww,ll);
    rect youRect;
    youRect = !myRect;
    youRect.display();
    cout <<endl;
    myRect.display();
    cout <<endl;
    return 0;


}