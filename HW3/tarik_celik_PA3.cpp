#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Pixel{  //to define pixel class.
    private:
        int r,g,b; //to define double variables for red green blue values in private.
    public:
        friend class Image;
        int Get_R() { return r; } 
        int Get_G() { return g; }  //to define getter functions for r g b values.
        int Get_B() { return b; }
        void Set_R(int value) { r = value; }
        void Set_G(int value) { g = value; }  //to define setter functions for r g b values.
        void Set_B(int value) { b = value; }
};

class Image{ //to define Image class.
    private:
        int width, height; //to define integers for height and width value of image.
        vector<vector<Pixel>> data; //to define 2D vector of pixel objects.
    public:
        Image (string filename){ //to define a constructor which is create image from given file.
            open_an_image(filename);
        }
        Image (int height ,int width){ //to define a constructor which is create blank (white) image with given dimensions.
            Resize(width,height);
            for (int i = 0; i < height; i++) { 
                for (int j = 0; j < width; j++) {
                    Pixel p; 
                    p.Set_R(255);
                    p.Set_G(255); //to call the setter functions of Pixel class and set the rgb values according to file.
                    p.Set_B(255);
                    Set_Pixel(j, i, p); //to call the setter function for store the pixel objects in vector which is in Image class.
                }
            }
        }
        Image (){} //to define default constructor.
        Pixel Get_Pixel(int x, int y) const { return data[y][x]; } //to define getter function for pixel objects.
        void Set_Pixel(int x, int y, Pixel pixel) { data[y][x] = pixel; } //to define setter function for pixel objects.
        int Get_Width() const { return width; }  //to define getter function for width value.
        int Get_Height() const { return height; } //to define getter function for height value.
        void Resize(int w, int h) {  //to define resize function for vector which is defined in private part of class.
            width = w;
            height = h;
            data.resize(height);
            for (int i = 0; i < height; i++) {
                data[i].resize(width);
            }
        }
        int open_an_image(const string filename); //to define open_an_image function for open an image file.
        void save_image_data(const string filename);//to define save_image_data function for save image data to file.
        void print_image_dimensions(); //to define a member function for print out the dimension of the image.
        void pixel_info(); //to define a member function for take the specific pixel information.
        void change_pixel_data(); //to define change_pixel_data function for changing values of specific pixel..
        friend Image operator+ (Image const& image1,Image const& image2);//to define + operator overload.
        friend Image operator- (Image const& image1,Image const& image2);//to define - operator overload.
        friend ostream& operator<<(ostream& os, const Image& image); //to define << operator overload.
        int & operator()(int row,int column,int colorchannel);//to define () operator overload.
};

Image operator+ (Image const& image1,Image const& image2){ //to define + operator overload.
    Image summ;
    int r,g,b;
    if(image1.Get_Height()!=image2.Get_Height() || image1.Get_Width()!=image2.Get_Width()) return summ;
    summ.Resize(image1.Get_Width(),image1.Get_Height());
    for (int i = 0; i < image1.Get_Height(); i++) {
        for (int j = 0; j < image1.Get_Width(); j++) {
            Pixel p1 = image1.Get_Pixel(j,i);
            Pixel p2 = image2.Get_Pixel(j,i);
            Pixel p3;
            r =min(p1.Get_R()+p2.Get_R(),255);
            g =min(p1.Get_G()+p2.Get_G(),255);
            b =min(p1.Get_B()+p2.Get_B(),255);
            p3.Set_R(r);
            p3.Set_G(g);
            p3.Set_B(b);

            summ.Set_Pixel(j,i,p3);
        }
    }
    return summ;
}

Image operator- (Image const& image1,Image const& image2){ //to define - operator overload.
    Image subtraction;
    int r,g,b;
    if(image1.Get_Height()!=image2.Get_Height() || image1.Get_Width()!=image2.Get_Width()) return subtraction;
    subtraction.Resize(image1.Get_Width(),image1.Get_Height());
    for (int i = 0; i < image1.Get_Height(); i++) {
        for (int j = 0; j < image1.Get_Width(); j++) {
            Pixel p1 = image1.Get_Pixel(j,i);
            Pixel p2 = image2.Get_Pixel(j,i);
            Pixel p3;
            r =min(p1.Get_R()-p2.Get_R(),255);
            g =min(p1.Get_G()-p2.Get_G(),255);
            b =min(p1.Get_B()-p2.Get_B(),255);
            p3.Set_R(r);
            p3.Set_G(g);
            p3.Set_B(b);

            subtraction.Set_Pixel(j,i,p3);
        }
    }
    return subtraction;
}

ostream& operator<<(ostream& os, const Image& image) { //to define << operator overload.
    // write the ppm image data to the output stream
    os << "P3" << endl;
    os << image.Get_Width() << " " << image.Get_Height() << endl;
    os << "255" << endl;

    for (int y = 0; y < image.Get_Height(); ++y) {
        for (int x = 0; x < image.Get_Width(); ++x) {
            Pixel p = image.Get_Pixel(x, y);
            os << p.Get_R() << " " << p.Get_G()<< " " << p.Get_B()<< " ";
        }
        os << endl;
    }

    return os;
}
int & Image::operator()(int row, int column, int colorchannel){ //to define function call operator overload.
    if(colorchannel == 1) return data[row][column].r;
    else if(colorchannel == 2) return data[row][column].g;
    return data[row][column].b;
    
}

int Image::open_an_image(const string filename) { //to define open an image function.
/*
* This function takes filename as a parameter and it reads that file then it stores the datas
*  in the class.
*/
    int width, height, max_val;  //to define integers for width,height and max_val values.
    string line; //to define a string for reading data from file.
    int r, g, b; //to define integers for r,g,b values.

    ifstream input_file(filename); //to open image file.
    if (!input_file.is_open()) {
        cerr << "Error: Could not open input file" << endl; //to give error message if file is not opens.
        return 1;
    }

   
    getline(input_file, line); //to read the file type line.
    if (line != "P3") {
        cerr << "Error: Invalid PPM file format" << endl;
        return 1;
    }

    getline(input_file, line); //to read the width and height of image file.
    istringstream(line) >> width >> height; //to assign the height and width value of image file to variables.
    if (width <= 0 || height <= 0) {
        cerr << "Error: Invalid image dimensions" << endl;
        return 1;
    }

    getline(input_file, line); //to read the maximum rgb value of image file.
    istringstream(line) >> max_val; //to assign the maximum rgb value of image file to variable.
    if (max_val != 255) {
        cerr << "Error: Invalid maximum value" << endl;
        return 1;
    }

    Resize(width, height); //to call resize function and resize the vector which is in Image class.
    for (int i = 0; i < height; i++) { //to create a nested for loop for read the datas from image file.
        for (int j = 0; j < width; j++) {
            Pixel p; //to create a pixel object.
        input_file >> r >> g >> b;
        p.Set_R(r);
        p.Set_G(g); //to call the setter functions of Pixel class and set the rgb values according to file.
            p.Set_B(b);
            Set_Pixel(j, i, p); //to call the setter function for store the pixel objects in vector which is in Image class.
        }
    }

    return 0;
}


void Image::save_image_data(string filename) {
/*
* This function takes filename as a parameter and it createimage.s an output file then writes datas to that file.
* It takes datas from vector of pixels which is in Image class with using getter function. 
*/
    ofstream output_file(filename); //to create a file with given name for writing.
    if (!output_file.is_open()) { //to check the file created or not.
        cerr << "Error: Could not open output file" << endl; //to give an error message if the file is not opens.
        return;
    }
    output_file << "P3" << endl; //to write type of image to output file.
    output_file << Get_Width() << " " << Get_Height() << endl; //to get height and width values from class and write to output file.
    output_file << "255" << endl; //to write the maximum value to output file.
    for (int i = 0; i < Get_Height(); i++) {
        for (int j = 0; j < Get_Width(); j++) {
            Pixel p = Get_Pixel(j, i); //to get pixels one by one from vector of pixels with using getter function.
            output_file << round(p.Get_R()) << " " << round(p.Get_G()) << " " << round(p.Get_B()) << " "; //to write red green and blue values of pixels to output file.
        }
        output_file << endl;
    }
    output_file.close(); //to close the output file.
    cout << "Image data saved to file: " << filename << endl;
}

void Image::print_image_dimensions(){ //to define print image dimensions function.
    cout<<Get_Height()<<" "<<Get_Width()<<endl;//to print out the dimensions of image.
}
void Image::pixel_info(){ //to define pixel_info function.
    int x,y;
    cout<<"Please enter the indexes : "; 
    cin>>x>>y;//to get indexes of pixel.
    cout<<x<<y<<endl;
    Pixel p = Get_Pixel(y,x); 
    cout<<"Pixel info which is in given indexes : "<<p.Get_R()<<p.Get_G()<<p.Get_B()<<endl; //to print out the value of pixel.
}
void Image::change_pixel_data(){
    int x,y,r,g,b;
    int rgb;
    cout<<"Please enter the indexes : ";
    cin>>x>>y;
    cout<<"Please enter the new red, green, blue values : ";
    cin>>r>>g>>b;
    rgb = 100*r + 10*g + b;
    if(rgb > 255){
        r = 2;
        g = 5;
        b = 5;
    }
    Pixel p;
    p.Set_R(r);
    p.Set_G(g);
    p.Set_B(b);
    Set_Pixel(y,x,p);
    
}

int read_ppm(const string filename,Image &destination_obj){ //to define read_ppm function.
    destination_obj = Image(filename); //to get image data from file and store the destination_obj with using constructor.
    return 1;
}
int write_ppm(const string filename,Image &source_obj){ //to define write_ppm function.
    source_obj.save_image_data(filename); //to store the data of source_obj to a file with using save_image_data function.
    return 1;
}

int print(const string filename){ //to define print function.
    Image image(filename); //to define a image object with using constructor which takes a file as a parameter.
    cout<<image<<endl; //to print out image data with using << operator overaload.
    return 1;
}

int addition(const string filename1 ,const string filename2,string filename3){ //to define addition function.
    Image image1,image2; //to create two image object.
    read_ppm(filename1,image1); //to read first file and store the data to image1 with using read_ppm function.
    read_ppm(filename2,image2); //to read second file and store the data to image2 with using read_ppm function.
    Image imageresult = image1 + image2; //to add the datas of image1 and image2 with using + operator overload.
    imageresult.save_image_data(filename3); //to store the summation of two image to a file.
    return 1;
}

int subtraction(const string filename1 ,const string filename2,string filename3){ //to define subtraction function.
    Image image1,image2; //to create two image object.
    read_ppm(filename1,image1); //to read first file and store the data to image1 with using read_ppm function.
    read_ppm(filename2,image2); //to read second file and store the data to image2 with using read_ppm function.
    Image imageresult = image1 - image2; //to subtract the image2 from image1 with using - operator overload.
    imageresult.save_image_data(filename3); //to store the subtraction of two image to a file.
    return 1;


}

int swap_color_channels(Image &image_obj_to_be_modified,int swap_choice) { //to define swap_color_channels function.
    int rows = image_obj_to_be_modified.Get_Height(); //to deifne a integer for height value of image.
    int columns = image_obj_to_be_modified.Get_Width(); //to deifne a integer for width value of image.
    
    switch(swap_choice) {
        case 1: //this case for swap red and green channels.
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++) {
                    int temp = image_obj_to_be_modified(i, j, 1);
                    image_obj_to_be_modified(i, j, 1) = image_obj_to_be_modified(i, j, 2);
                    image_obj_to_be_modified(i, j, 2) = temp;
                }
            }
            return 1;
        case 2: //this case for swap red and blue channels.
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++) {
                    int temp = image_obj_to_be_modified(i, j, 1);
                    image_obj_to_be_modified(i, j, 1) = image_obj_to_be_modified(i, j, 3);
                    image_obj_to_be_modified(i, j, 3) = temp;
                }
            }
            return 1;
        case 3: //this case for swap the greean and blue channels.
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++) {
                    int temp = image_obj_to_be_modified(i, j, 2);
                    image_obj_to_be_modified(i, j, 2) = image_obj_to_be_modified(i, j, 3);
                    image_obj_to_be_modified(i, j, 3) = temp;
                }
            }
            return 1;
        default: //for no swap choice.
            return 1;
    } 
}

Image single_color(Image const& source_obj, int color_choice){ //to deifne single_color function.
    int rows = source_obj.Get_Height(); //to deifne a integer for height value of image.
    int columns = source_obj.Get_Width(); //to deifne a integer for width value of image.
    Image img;
    img.Resize(columns,rows);
    img = source_obj;

    switch(color_choice){
        case 1: //this case for only red color.
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    img(i, j, 2) = 0; //to assign zero to green channels with using function-call operator overload.
                    img(i, j, 3) = 0; //to assign zero to blue channels with using function-call operator overload.
                }
            }
            break;
        case 2: //this case for only green color.
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    img(i, j, 1) = 0; //to assign zero to red channels with using function-call operator overload.
                    img(i, j, 3) = 0; //to assign zero to blue channels with using function-call operator overload.
                }
            }        
            break;
        case 3: //this case for only blue color.
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    img(i, j, 1) = 0; //to assign zero to red channels with using function-call operator overload.
                    img(i, j, 2) = 0; //to assign zero to green channels with using function-call operator overload.
                }
            }
            break;
        default: //this case for no choice of color.
            break;
    }
    return img;
}

int main (int argc, char** argv){
    Image img,temp;
    int choicenumber;

    if(argc > 3){ //to check number of arguments.
        choicenumber = stoi(argv[1]);
        string filename1(argv[2]), filename2(argv[3]),filename3; //to get filenames from arguments.
        if(argc > 4) {
        	filename3 = argv[4];
        }

        switch (choicenumber)
        {
        case 1: //this case for addition of images.
                if(argc < 4) return 0;
                addition(filename1,filename2,filename3); //to call addition function.
                return 1;
            break;
        case 2: //this case for subtraction of images.
                if(argc < 4) return 0;               
                subtraction(filename1,filename2,filename3); //to call subtraction function.
                return 1;
            break;
        case 3: //this case for swap red and blue color channels.
                read_ppm(filename1,img); //to call read__ppm function for read the image file.
                swap_color_channels(img,2); //to swap the red and blue channels of image with using swap_color_channels function.
                write_ppm(filename2,img); //to call the write_ppm function for store the modified image to a file.
            break;
        case 4: //this case for swap green and blue color channels.
                read_ppm(filename1,img); //to call read__ppm function for read the image file.
                swap_color_channels(img,3); //to swap the green and blue channels of image with using swap_color_channels function.
                write_ppm(filename2,img); //to call the write_ppm function for store the modified image to a file.           
            break;
        case 5: //this case for create only red colored image.
                read_ppm(filename1,img); //to call read__ppm function for read the image file.
                temp = single_color(img,1); //to call singel_color funtion and create only red colored image object.
                write_ppm(filename2,temp); //to call the write_ppm function for store the created single colored image to a file.
            break;
        case 6: //this case for create only green colored image.
                read_ppm(filename1,img); //to call read__ppm function for read the image file.
                temp = single_color(img,2); //to call singel_color funtion and create only green colored image object.
                write_ppm(filename2,temp); //to call the write_ppm function for store the created single colored image to a file.
            break;
        case 7: //this case for create only blue colored image.
                read_ppm(filename1,img); //to call read__ppm function for read the image file.
                temp = single_color(img,3); //to call singel_color funtion and create only blue colored image object.
                write_ppm(filename2,temp); //to call the write_ppm function for store the created single colored image to a file.
            break;                  
        default:
            break;
        }
    } 
    return 0;
}
