#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// This program provides convenience for those who need to deal with complex shapes and algorithms.
// For Bresenham's algorithm, the line is drawn from left to right; second point's coordinates should be greater than the first point's.
// RULE: x1 < x2 and y1 < y2
// Please pay attention to this well-known rule when choosing your X and Y points to get accurate and satisfactory results.


class line{

protected:
    char **canvas;
    char **fakeCanvas;

public:
    line(int n){
        canvas=new char*[n];
        fakeCanvas=new char*[n];
        for(int i=0;i<=n;i++){
            canvas[i]=new char[n];
            fakeCanvas[i]=new char[n];
        }

        for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                        this->canvas[i][j]=' ';
                        this->fakeCanvas[i][j]=' ';
                }
        }
    }
	void freshCanvas(int n){
         for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        this->fakeCanvas[i][j]=' ';
                }
            }
	}


    //Bresenham's Line Algorithm
	void drawLine(int x0, int y0, int x1, int y1,int size1){
        int dx = x1 - x0;
        int dy = y1 - y0;
        int xs = 1;
        int ys = 1;

        //supports negative slope
        if (dy<0){
            dy = -dy;
            ys = -1;
        }
        if (dx<0){
            dx = -dx;
            xs = -1;
        }

        dy = 2 * dy;
        dx = 2 * dx;

        //update
        canvas[size1-y0][x0]='*';


        float slope_inc = 0;
        float stepy=1;
        if (dx>dy){
            slope_inc = dy - dx / 2;
            while(x0 != x1){
                if (slope_inc>=0){
                     y0 = y0 + stepy;
                     slope_inc = slope_inc - dx;
                }
                x0 = x0 + xs;
                slope_inc = slope_inc + dy;
                //update
                canvas[size1-y0][x0]='*';

            }
        }

        else{
            slope_inc = dx - dy / 2;
            while (y0 != y1){
                if(slope_inc>=0){
                    x0 = x0 + xs;
                    slope_inc = slope_inc - dy;
                }
                y0 = y0 + ys;
                slope_inc = slope_inc + dx;

                //update
                canvas[size1-y0][x0]='*';

            }
        }
    }




    void drawShape(int x0, int y0, int x1, int y1,int size1){
        int dx = x1 - x0;
        int dy = y1 - y0;
        int xs = 1;
        int ys = 1;

        //Bresenham's Line Algorithm
        if (dy<0){
            dy = -dy;
            ys = -1;
        }
        if (dx<0){
            dx = -dx;
            xs = -1;
        }

        dy = 2 * dy;
        dx = 2 * dx;

        //update
        fakeCanvas[size1-y0][x0]='*';

        int slope_inc = 0;
        int stepy=1;
        if (dx>dy){
            slope_inc = dy - dx / 2;
            while(x0 != x1){
                if (slope_inc>=0){
                     y0 = y0 + stepy;
                     slope_inc = slope_inc - dx;
                }
                x0 = x0 + xs;
                slope_inc = slope_inc + dy;
                //update
                fakeCanvas[size1-y0][x0]='*';
            }
        }

        else{
            slope_inc = dx - dy / 2;
            while (y0 != y1){
                if(slope_inc>=0){
                    x0 = x0 + xs;
                    slope_inc = slope_inc - dy;
                }
                y0 = y0 + ys;
                slope_inc = slope_inc + dx;

                //update
                fakeCanvas[size1-y0][x0]='*';


            }
        }

    }


    void showShape(int n){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    if(fakeCanvas[i][j]!=' '){
                        cout<<"*";
                    }
                    else{
                        cout<<" ";
                    }
                }
                cout<<"\n";
            }
     }

     void printLine(int n){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    if(canvas[i][j]!=' '){
                        cout<<"*";
                    }
                    else{
                        cout<<" ";
                    }
                }
                cout<<"\n";
            }
     }


};




class triangle {

private:
    char **canvas;
    char **fakeCanvas;
public:

    triangle(int n){
        canvas=new char*[n];
        fakeCanvas=new char*[n];
        for(int i=0;i<=n;i++){
            canvas[i]=new char[n];
            fakeCanvas[i]=new char[n];
        }

        for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                        this->canvas[i][j]=' ';
                        this->fakeCanvas[i][j]=' ';
                }
        }
    }

	void freshCanvas(int n){
         for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        this->fakeCanvas[i][j]=' ';
                }
            }
	}



	void drawLine(int x0, int y0, int x1, int y1,int size1){
        int dx = x1 - x0;
        int dy = y1 - y0;
        int xs = 1;
        int ys = 1;

        //Bresenham's Line Algorithm
        if (dy<0){
            dy = -dy;
            ys = -1;
        }
        if (dx<0){
            dx = -dx;
            xs = -1;
        }

        dy = 2 * dy;
        dx = 2 * dx;

        //update
        canvas[size1-y0][x0]='*';


        float slope_inc = 0;
        float stepy=1;
        if (dx>dy){
            slope_inc = dy - dx / 2;
            while(x0 != x1){
                if (slope_inc>=0){
                     y0 = y0 + stepy;
                     slope_inc = slope_inc - dx;
                }
                x0 = x0 + xs;
                slope_inc = slope_inc + dy;
                //update
                canvas[size1-y0][x0]='*';

            }
        }

        else{
            slope_inc = dx - dy / 2;
            while (y0 != y1){
                if(slope_inc>=0){
                    x0 = x0 + xs;
                    slope_inc = slope_inc - dy;
                }
                y0 = y0 + ys;
                slope_inc = slope_inc + dx;
                //update

                canvas[size1-y0][x0]='*';

            }
        }
    }


    // Triangle is a 3 lines concatenated really.

    void drawTriangle(int x0,int y0,int x1,int y1,int x2,int y2,int size1){
        drawLine(x0,y0,x1,y1,size1);
        drawLine(x0,y0,x2,y2,size1);
        drawLine(x1,y1,x2,y2,size1);
    }


    void drawShape(int x0, int y0, int x1, int y1,int size1){
        int dx = x1 - x0;
        int dy = y1 - y0;
        int xs = 1;
        int ys = 1;

        //Bresenham's Line Algorithm
        if (dy<0){
            dy = -dy;
            ys = -1;
        }
        if (dx<0){
            dx = -dx;
            xs = -1;
        }

        dy = 2 * dy;
        dx = 2 * dx;

        //update
        fakeCanvas[size1-y0][x0]='*';


        float slope_inc = 0;
        float stepy=1;
        if (dx>dy){
            slope_inc = dy - dx / 2;
            while(x0 != x1){
                if (slope_inc>=0){
                     y0 = y0 + stepy;
                     slope_inc = slope_inc - dx;
                }
                x0 = x0 + xs;
                slope_inc = slope_inc + dy;
                //update
                fakeCanvas[size1-y0][x0]='*';

            }
        }

        else{
            slope_inc = dx - dy / 2;
            while (y0 != y1){
                if(slope_inc>=0){
                    x0 = x0 + xs;
                    slope_inc = slope_inc - dy;
                }
                y0 = y0 + ys;
                slope_inc = slope_inc + dx;
                //update

                fakeCanvas[size1-y0][x0]='*';

            }
        }

    }










     void drawShape2(int x0,int y0,int x1,int y1,int x2,int y2,int size1){
        drawShape(x0,y0,x1,y1,size1);
        drawShape(x0,y0,x2,y2,size1);
        drawShape(x1,y1,x2,y2,size1);
    }

    void showShape(int n){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    if(fakeCanvas[i][j]!=' '){
                        cout<<"*";
                    }
                    else{
                        cout<<" ";
                    }
                }
                cout<<"\n";
            }
     }



    void printTri(int n){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    if(canvas[i][j]!=' '){
                        cout<<"*";
                    }
                    else{
                        cout<<" ";
                    }
                }
                cout<<"\n";
            }
     }



};

class quadrilateral{

private:
    char **canvas;
    char **fakeCanvas;

public:
    quadrilateral(int n){
        canvas=new char*[n];
        fakeCanvas=new char*[n];
        for(int i=0;i<=n;i++){
            canvas[i]=new char[n];
            fakeCanvas[i]=new char[n];
        }

        for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                        this->canvas[i][j]=' ';
                        this->fakeCanvas[i][j]=' ';
                }
        }
    }

	void freshCanvas(int n){
         for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        this->fakeCanvas[i][j]=' ';
                }
            }
	}


	void drawLine(int x0, int y0, int x1, int y1,int size1){
        int dx = x1 - x0;
        int dy = y1 - y0;
        int xs = 1;
        int ys = 1;

        //Bresenham's Line Algorithm
        if (dy<0){
            dy = -dy;
            ys = -1;
        }
        if (dx<0){
            dx = -dx;
            xs = -1;
        }

        dy = 2 * dy;
        dx = 2 * dx;

        //update
        canvas[size1-y0][x0]='*';


        float slope_inc = 0;
        float stepy=1;
        if (dx>dy){
            slope_inc = dy - dx / 2;
            while(x0 != x1){
                if (slope_inc>=0){
                     y0 = y0 + stepy;
                     slope_inc = slope_inc - dx;
                }
                x0 = x0 + xs;
                slope_inc = slope_inc + dy;
                //update
                canvas[size1-y0][x0]='*';

            }
        }

        else{
            slope_inc = dx - dy / 2;
            while (y0 != y1){
                if(slope_inc>=0){
                    x0 = x0 + xs;
                    slope_inc = slope_inc - dy;
                }
                y0 = y0 + ys;
                slope_inc = slope_inc + dx;
                //update

                canvas[size1-y0][x0]='*';

            }
        }
    }


// Quadrilateral is a 4 lines concatenated really.

    void drawQuadrilateral(int leftX,int leftY, int topX, int topY, int rightX, int rightY, int bottomX,int bottomY,int size1){
        drawLine(leftX,leftY,topX,topY,size1);
        drawLine(leftX,leftY,bottomX,bottomY,size1);
        drawLine(topX,topY,rightX,rightY,size1);
        drawLine(bottomX,bottomY,rightX,rightY,size1);
    }




    void drawShape(int x0, int y0, int x1, int y1,int size1){
        int dx = x1 - x0;
        int dy = y1 - y0;
        int xs = 1;
        int ys = 1;

        //Bresenham's Line Algorithm
        if (dy<0){
            dy = -dy;
            ys = -1;
        }
        if (dx<0){
            dx = -dx;
            xs = -1;
        }

        dy = 2 * dy;
        dx = 2 * dx;

        //update
        fakeCanvas[size1-y0][x0]='*';


        float slope_inc = 0;
        float stepy=1;
        if (dx>dy){
            slope_inc = dy - dx / 2;
            while(x0 != x1){
                if (slope_inc>=0){
                     y0 = y0 + stepy;
                     slope_inc = slope_inc - dx;
                }
                x0 = x0 + xs;
                slope_inc = slope_inc + dy;
                //update
                fakeCanvas[size1-y0][x0]='*';

            }
        }

        else{
            slope_inc = dx - dy / 2;
            while (y0 != y1){
                if(slope_inc>=0){
                    x0 = x0 + xs;
                    slope_inc = slope_inc - dy;
                }
                y0 = y0 + ys;
                slope_inc = slope_inc + dx;
                //update

                fakeCanvas[size1-y0][x0]='*';

            }
        }

    }


     void drawShape2(int leftX,int leftY, int topX, int topY, int rightX, int rightY, int bottomX,int bottomY,int size1){
        drawShape(leftX,leftY,topX,topY,size1);
        drawShape(leftX,leftY,bottomX,bottomY,size1);
        drawShape(topX,topY,rightX,rightY,size1);
        drawShape(bottomX,bottomY,rightX,rightY,size1);
     }


    void showShape(int n){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    if(fakeCanvas[i][j]!=' '){
                        cout<<"*";
                    }
                    else{
                        cout<<" ";
                    }
                }
                cout<<"\n";
            }
     }



    void printQuad(int n){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    if(this->canvas[i][j]!=' '){
                        cout<<"*";
                    }
                    else{
                        cout<<" ";
                    }
                }
                cout<<"\n";
            }
     }
};



class circle {

private:
    char **canvas;
    char **fakeCanvas;
public:
    circle(int n){
	    canvas=new char*[n];
        fakeCanvas=new char*[n];
        for(int i=0;i<=n;i++){
            canvas[i]=new char[n];
            fakeCanvas[i]=new char[n];
        }

        for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                        this->canvas[i][j]=' ';
                        this->fakeCanvas[i][j]=' ';
                }
        }
    }
	void freshCanvas(int n){
         for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        this->fakeCanvas[i][j]=' ';
                }
            }
	}


	void drawCircle(int xc, int yc,int r,int size1){
    //Bresenham Circle Algorithm
        int x = 0;
        int y = r;
        int d = 3 - 2 * r;
        draw8Points(xc, yc, x, y,size1);

        while(y>=x){
         x+=1;
         if (d>0){
            y-=1;
            d = d + 4 * (x - y) + 10;
         }
         else{
            d = d + 4 * x + 6;
         }
         draw8Points(xc, yc, x, y,size1);
        }
    }


    void draw8Points(int xc, int yc,int x,int y,int size1){
        this->canvas[size1-((yc+y))][xc+x]='*';
        this->canvas[size1-((yc+y))][xc-x]='*';
        this->canvas[size1-((yc-y))][xc+x]='*';
        this->canvas[size1-((yc-y))][xc-x]='*';
        this->canvas[size1-((yc+x))][xc+y]='*';
        this->canvas[size1-((yc+x))][xc-y]='*';
        this->canvas[size1-((yc-x))][xc+y]='*';
        this->canvas[size1-((yc-x))][xc-y]='*';
    }


    void printCircle(int n){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    if(this->canvas[i][j]!=' '){
                        cout<<"*";
                    }
                    else{
                        cout<<" ";
                    }
                }
                cout<<"\n";
            }
     }


     void drawShape(int xc, int yc,int r,int size1){
    //Bresenham Circle Algorithm
        int x = 0;
        int y = r;
        int d = 3 - 2 * r;
        draw8FakePoints(xc, yc, x, y,size1);

        while(y>=x){
             x+=1;
             if (d>0){
                y-=1;
                d = d + 4 * (x - y) + 10;
             }
             else{
                d = d + 4 * x + 6;
             }
             draw8FakePoints(xc, yc, x, y,size1);
        }
    }


    void draw8FakePoints(int xc, int yc,int x,int y,int size1){
        this->fakeCanvas[size1-((yc+y))][xc+x]='*';
        this->fakeCanvas[size1-((yc+y))][xc-x]='*';
        this->fakeCanvas[size1-((yc-y))][xc+x]='*';
        this->fakeCanvas[size1-((yc-y))][xc-x]='*';
        this->fakeCanvas[size1-((yc+x))][xc+y]='*';
        this->fakeCanvas[size1-((yc+x))][xc-y]='*';
        this->fakeCanvas[size1-((yc-x))][xc+y]='*';
        this->fakeCanvas[size1-((yc-x))][xc-y]='*';
    }

     void showShape(int n){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    if(this->fakeCanvas[i][j]!=' '){
                        cout<<"*";
                    }
                    else{
                        cout<<" ";
                    }
                }
                cout<<"\n";
            }
     }


};







int main(){
// RULE: x1 < x2 and y1 < y2
// As a result of this rule, we draw a line from the lower left to the upper right.
    int choise,ans1,ans,choise1,size1;
    int x0,x1,x2,x3,y0,y1,y2,y3,xc,yc,r;

    cout<<"Welcome to the Shape Drawing Tool 2.0"<<endl;
    cout<<"please input the size as an integer to initialize your coordinate system:"; cin>>size1;
    //initialize object references.
    line *line1=new line(size1);
    triangle *tri=new triangle(size1);
    quadrilateral *quad=new quadrilateral(size1);
    circle *circle1=new circle(size1);
    cout<<"("<<size1<<"x"<<size1<<") "<<"Coordinate systems are successfully initialized"<<endl;

    do{
        cout<<"1-See saved shapes\n2-Draw a shape"<<endl;cin>>ans1;
        if(ans1==1){
            cout<<"1-Line\n2-Triangle\n3-Quadrilateral\n4-Circle"<<endl;
            cout<<"Which shape's canvas do you want to see?"; cin>>choise1;
            if(choise1==1){
                    line1->printLine(size1);
            }
            else if(choise1==2){
                    tri->printTri(size1);
            }
            else if(choise1==3){
                    quad->printQuad(size1);
            }
            else if(choise1==4){
                    circle1->printCircle(size1);
            }
            else{
                cout<<"invalid choise!"<<endl;
                continue;
            }
        }
        else if(ans1==2){

        cout<<"1-Line\n2-Triangle\n3-Quadrilateral\n4-Circle"<<endl;
        cout<<"What kind of a shape do you want to draw ?(Press 0 to exit the program)"; cin>>choise;


        switch(choise){
            case 0:
                cout<<"Goodbye...";
                return 0;
            case 1:
                {
                cout<<"Please enter first X coordinate (x0):"; cin>>x0;
                cout<<"Please enter first Y coordinate (y0):"; cin>>y0;
                cout<<"Please enter second X coordinate (x1) :"; cin>>x1;
                cout<<"Please enter second Y coordinate (y1) :"; cin>>y1;

                line1->drawShape(x0,y0,x1,y1,size1);
                line1->showShape(size1);
                line1->freshCanvas(size1);

                break;
                }
            case 2:
                {
                cout<<"Please enter first X coordinate (x0):"; cin>>x0;
                cout<<"Please enter first Y coordinate (y0):"; cin>>y0;
                cout<<"Please enter second X coordinate (x1) :"; cin>>x1;
                cout<<"Please enter second Y coordinate (y1) :"; cin>>y1;
                cout<<"Please enter third X coordinate (x2):"; cin>>x2;
                cout<<"Please enter third Y coordinate (y2):"; cin>>y2;

                tri->drawShape2(x0,y0,x1,y1,x2,y2,size1);
                tri->showShape(size1);
                tri->freshCanvas(size1);

                break;
                }
            case 3:
                {
                cout<<"Please enter first X coordinate (x0):"; cin>>x0;
                cout<<"Please enter first Y coordinate (y0):"; cin>>y0;
                cout<<"Please enter second X coordinate (x1) :"; cin>>x1;
                cout<<"Please enter second Y coordinate (y1) :"; cin>>y1;
                cout<<"Please enter third X coordinate (x2):"; cin>>x2;
                cout<<"Please enter third Y coordinate (y2):"; cin>>y2;
                cout<<"Please enter fourth X coordinate (x3):"; cin>>x3;
                cout<<"Please enter fourth Y coordinate (y3):"; cin>>y3;

                quad->drawShape2(x0,y0,x1,y1,x2,y2,x3,y3,size1);
                quad->showShape(size1);
                quad->freshCanvas(size1);

                break;
                }
            case 4:
                {
                cout<<"Please enter center X coordinate (xc):"; cin>>xc;
                cout<<"Please enter center Y coordinate (yc):"; cin>>yc;
                cout<<"Please enter radius R (r) :"; cin>>r;

                circle1->drawShape(xc,yc,r,size1);
                circle1->showShape(size1);
                circle1->freshCanvas(size1);

                break;
                }
            default:
                cout<<"Invalid input.\n"<<endl;
                continue;

        }
        cout<<"Would you like to save this shape for further usage?\n1-No\n2-Yes\nAnswer:"; cin>>ans;
        if(ans==1){
            continue;
        }
        else if(ans==2){
            if(choise==1){
                line1->drawLine(x0,y0,x1,y1,size1);
                line1->printLine(size1);
                cout<<"Line saved successfully"<<endl;
            }
            else if(choise==2){
                tri->drawTriangle(x0,y0,x1,y1,x2,y2,size1);
                tri->printTri(size1);
                cout<<"Triangle saved successfully"<<endl;
            }
            else if(choise==3){
                quad->drawQuadrilateral(x0,y0,x1,y1,x2,y2,x3,y3,size1);
                quad->printQuad(size1);
                cout<<"Quadrilateral saved successfully"<<endl;
            }
            else if(choise==4){
                circle1->drawCircle(xc,yc,r,size1);
                circle1->printCircle(size1);
                cout<<"Circle saved successfully"<<endl;
            }
            else{
                cout<<"Unexpected error..."<<endl;
            }
        }
    }
    }while (choise!=0);

	return 0;
}

