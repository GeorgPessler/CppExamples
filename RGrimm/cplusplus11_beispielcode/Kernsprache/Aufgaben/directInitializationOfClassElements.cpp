int getWidth(int){return 2011;};

class Widget{
  public:
    Widget(){}
    Widget(int h): height(h),width(getWidth(h)){}
    Widget(int h,int w): height(h),width(w){}
  private:
    int height= 480;
    int width= 640;
    bool frame= false;
    bool visible= true;
};

int main(){
  Widget();
  Widget(1);
  Widget(1,2);
}
