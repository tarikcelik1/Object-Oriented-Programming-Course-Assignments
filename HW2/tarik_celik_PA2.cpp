#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Pixel{  //to define pixel class.
    private:
        double r,g,b; //to define double variables for red green blue values in private.
    public:
        double Get_R() { return r; } 
        double Get_G() { return g; }  //to define getter functions for r g b values.
        double Get_B() { return b; }
        void Set_R(int value) { r = value; }
        void Set_G(int value) { g = value; }  //to define setter functions for r g b values.
        void Set_B(int value) { b = value; }
};

class Image{ //to define Image class.
    private:
        int width, height; //to define integers for height and width value of image.
        vector<vector<Pixel>> data; //to define 2D vector of pixel objects.
    public:
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
        int open_an_image(char *filename); //to define a member function for open image part.
        void save_image_data(char* filename); //to define a member function for save image part.
        void convert_to_grayscale(); //to define a member function for convert to grayscale part.
};

int Image::open_an_image(char* filename) { //to define open an image function.
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


void Image::save_image_data(char* filename) {
/*
* This function takes filename as a parameter and it creates an output file then writes datas to that file.
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

void Image::convert_to_grayscale(){
/*
* This function takes the pixels from vector which is in Image class and it takes input from user for coefficients or graycscale.
* Then it converts the pixels to gray according to the coefficients and saves that version to an output file.
*/
	float c_r,c_g,c_b; //to define float variables for coefficients or red green blue.
	int errflag=0; //to define an error flag integer for checking user inputs are correct or not.
	  do { //to define a do-while loop for get correct inputs from user.
        if (errflag != 0) { //to checking inputs are true or not.
            cout << "You entered wrong input please re-enter the coefficients :"; 
        }
        cin >> c_r >> c_g >> c_b; //to get user inputs.
        if (cin.fail()) {
            cin.clear(); //to clear the error flag
            cin.ignore(10000, '\n'); //to ignore the input buffer
        }
        errflag++;
    } while ((c_r < 0 || c_r >= 1) || (c_g < 0 || c_g >= 1) || (c_b < 0 || c_b >= 1));
    
    ofstream output_file("Grayscale_output.ppm"); //to create a file for grayscale version.
    if (!output_file.is_open()) { //to check the file created or not.
        cerr << "Error: Could not open output file" << endl;
        return;
    }
    output_file << "P3" << endl; //to write type of image to output file.
    output_file << Get_Width() << " " << Get_Height() << endl; //to get height and width values from class and write to output file.
    output_file << "255" << endl;//to write the maximum value to output file.
    for (int i = 0; i < Get_Height(); i++) {
        for (int j = 0; j < Get_Width(); j++) {
            		Pixel p = Get_Pixel(j, i);//to get pixels one by one from vector of pixels with using getter function.
            		int gray = (c_r * p.Get_R()) + (c_g * p.Get_G()) + (c_b * p.Get_B()); //to calculate the grayscale value for the pixel
            		if (gray > 255) { //to check the gray value is greater than 255 or not if it is greater then assing it as 255.
                		gray = 255;
            		}
            		p.Set_R(gray);
            		p.Set_G(gray); //to call the setter functions of Pixel class and set the rgb values as grayscale value.
            		p.Set_B(gray);
            		output_file << round(p.Get_R()) << " " << round(p.Get_G()) << " " << round(p.Get_B()) << " ";//to write red green and blue values of pixels to output file.
        }
         output_file << endl;
    }
}

int main (){

    int menu_option1, menu_option2; //define integers for user's options from menu.
    int flag = 0;
    char filename [30],outputfilename [30]; //to define char arrays for user inputs for filenames.
    Image image;//to create an image object.

    do{ //to create a do-while loop for MENU.
        cout<<"MAIN MENU"<<endl<<"0 - > Exit"<<endl<<"1 - Open An Image (D)"<<endl
            <<"2 - Save Image Data (D)"<<endl<<"3 - Scripts (D)"<<endl;
       
        cin>>menu_option1; //to get input for menu options.

        switch(menu_option1){ //to create switch case for menu.
            case 0: break;
           
            case 1: //this case for open an image option of the menu.
                cout<<"OPEN AN IMAGE MENU"<<endl<<"0 - UP"<<endl<<"1 - Enter The Name Of The Image File"<<endl;
                cin>>menu_option2;
                switch (menu_option2)
                {
                case 0:
                    break;
                case 1:
                    cin>>filename; //to get user input for filename.
                    image.open_an_image(filename); //to call the open an image function.
                    flag++; //this flag for other parts.
                    break;
                }
                break;
            case 2://this case for save image data option of the menu.
                cout<<"SAVE IMAGE DATA MENU"<<endl<<"0 - UP"<<endl<<"1 - Enter The Name Of The Image File"<<endl;
                cin>>menu_option2;
                switch (menu_option2)
                {
                case 0:
                    break;
                case 1:
                    if(flag == 0) {break;} //to check an image file opened before or not if it was not opened then open it.
                    cin>>outputfilename; //to get name of output file.
		    image.save_image_data(outputfilename); //to call save image data function.
                    break;
                default:
                    break;
                }
                break;
            case 3://this case for convert to grayscale option of the menu.
                cout<<"CONVERT TO GRAYSCALE MENU"<<endl<<"0 - UP"<<endl<<"1 - Enter Coefficients For RED GREEN And BLUE Channels."<<endl;
                cin>>menu_option2;
                switch (menu_option2)
                {
                case 0:
                	break;
                case 1:
                	if(flag == 0) {//to check an image file opened before or not if it was not opened then open it.
			break;
                	}
			image.convert_to_grayscale(); //to call the convert to grayscale funvtion.
                    break;
                default:
                    break;
                }                                
                break;
            default:
                break;
        }
    }while(menu_option1 != 0);

    return 0;
}
