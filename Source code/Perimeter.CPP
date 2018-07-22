#include <iostream.h>
#include <graphics.h>
#include <math.h>

int main(){
	int n=200, m=200, r, count, i, j, k, a, b, instance_number=0;
	double perimeter_pattern[n][4], perimeter_instance[(m-4)*(m-5)/2][4], sum, value_pixel, factor_x;
	char str[20];
    int driver=DETECT, mode=0;
	initgraph(&driver, &mode, "C:\\TC\\BGI");
	
	///// Stage 1
    // Information of several circles having different radii
	r=1;
    while (r<=n)
	{
		cleardevice();

        setcolor(7);
        outtextxy(1,1,"r :");
        sprintf(str,"%d",r);
        outtextxy(20,1,str);
        
		setcolor(2);
		circle(315,235,r);

		count=0;
		for(i=1;i<=630;i++)
			for(j=1;j<=470;j++)
				if (getpixel(i,j)==2)
					count++;
        
        // Set values of the perimeter_pattern matrix
		perimeter_pattern[r-1][0]=r;
		perimeter_pattern[r-1][1]=2*M_PI*r;
		perimeter_pattern[r-1][2]=count;
		perimeter_pattern[r-1][3]=(double)(2*M_PI*r)/count;        
        
        // Display results
        if (r==1)
        {
           cout<<"Stage 1"<<"\n";
           cout<<"///////////////////////////////////////////////////////"<<"\n";
           cout<<"///////////////////////////////////////////////////////"<<"\n";
           cout<<"///////////////////////////////////////////////////////"<<"\n\n";
           cout<<"Information of several circles having different radii"<<"\n";
           cout<<"-------------------------------------------------------"<<"\n";
           cout<<"-------------------------------------------------------"<<"\n";
        }
        cout<<perimeter_pattern[r-1][0]<<"    "<<perimeter_pattern[r-1][1]<<"    "<<perimeter_pattern[r-1][2]<<"    "<<perimeter_pattern[r-1][3]<<"\n";
        //
        r++;
	}        
    
    // Calculate and display value of a pixel 
    sum=0;
    r=1;    
    while(r<=n)
    {
        sum+=perimeter_pattern[r-1][3];
        r++;        
    }
    value_pixel=(double)sum/n;
    //
    cout<<"*******************************************************"<<"\n";
    cout<<"Value of a pixel: "<<value_pixel;
    
    delay(2000); 
   
	///// Stage 2
    // Information of several ellipses having different diameters
    a=3;
    while(a<=m)
    {
		b=2;
        while(b<=(3*a/4))
		{    		
            cleardevice();
    		
            setcolor(7);
            outtextxy(1,1,"a :");
            sprintf(str,"%d",a);
            outtextxy(20,1,str); 
            outtextxy(1,20,"b :");
            sprintf(str,"%d",b);
            outtextxy(20,20,str);           		
    
    		setcolor(2);
    		ellipse(315,235,0,360,a,b);
    
    		count=0;
    		for(i=1;i<=630;i++)
    			for(j=1;j<=470;j++)
    				if (getpixel(i,j)==2)
    					count++;
            
            // Set values of the perimeter_instance matrix
    		perimeter_instance[instance_number][0]=a;
    		perimeter_instance[instance_number][1]=b;
    		perimeter_instance[instance_number][2]=count*value_pixel;
    		perimeter_instance[instance_number][3]=(double)(count*value_pixel)/(M_PI*(a+b));		
    
            // Display results
            if (instance_number==0)
            {
               cout<<"\n\n\n"<<"Stage 2"<<"\n";
               cout<<"///////////////////////////////////////////////////////"<<"\n";
               cout<<"///////////////////////////////////////////////////////"<<"\n";
               cout<<"///////////////////////////////////////////////////////"<<"\n\n";
               cout<<"Information of several ellipses having different diameters"<<"\n";
               cout<<"-------------------------------------------------------"<<"\n";
               cout<<"-------------------------------------------------------"<<"\n";
            }
            cout<<perimeter_instance[instance_number][0]<<"    "<<perimeter_instance[instance_number][1]<<"    "<<perimeter_instance[instance_number][2]<<"    "<<perimeter_instance[instance_number][3]<<"\n";
            //
            instance_number++;
            b++;
        }
        //
        a++;
    }  
    
    // Calculate and display the value of factor x 
    sum=0;
    k=1;    
    while(k<=instance_number)
    {
        sum+=perimeter_instance[k-1][3];
        k++;        
    }
    factor_x=(double)sum/instance_number;
    //
    cout<<"*******************************************************"<<"\n";
    cout<<"Number of instances: "<<instance_number<<"\n";
    cout<<"The value of factor x: "<<factor_x;                    
    
    /////
	getch();
}
