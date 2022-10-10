#include<iostream>
#include<graphics.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
using namespace std;

int endfunc(int e, int a);

int main(){
	system("color 5");
	string color;
	cout<<"PF Group Assignment";

	cout<<"\nChoose any of these colors:\n \t1) BLUE \n \t2) GREEN \n \t3) YELLOW";
	cout<<"\nEnter Your Choice : ";
	getline(cin,color,'\n');
	
    //direction
    int gd,gm,rx=200,ry=200,x[200],y[200],d;
    
    //DECALARING AND INITIALIZING SNAKE IN A ONE DIMENSIONAL ARRAY
    for(int i = 0;i < 200 ; i++){     //MAX ARRAY SIZE 200
        x[i]=0;
        y[i]=0;
    }
 
    //Food eaten
    
    int f=1;
    int fd=1;
    int chk = 700;
    
    //directions
    
    int dir=1;
    detectgraph(&gd,&gm);                   //CREATING GRAPH
    initgraph(&gd,&gm,"C:\\turboc3\\bgi");

//  	setfillstyle(1,2); // Default  
  
	 
	x[0]=200,y[0]=200;
    d=1;
    int length =3 ;         //INITIAL SIZE OF SNAKE

//DRAWING THE GAME PANEL

while(true)
{
    setfillstyle(1,0);     //BOARD COLOR
    bar(0,0,640,480);
    if(color=="1"){
	
    setfillstyle(1,1);
    bar(0,0,640,10);        //DRAWING WALLS BY USING BAR FUNCTION WHICH IS ALREADY DEFINED IN CPP
    bar(0,0,10,480);
    bar(0,480,640,470);
    bar(630,10,640,480);
}
   else if(color=="2"){
   
	setfillstyle(1,2);
    bar(0,0,640,10);
    bar(0,0,10,480);
    bar(0,480,640,470);
    bar(630,10,640,480);
}
    else if(color=="3"){
    setfillstyle(1,3);
    bar(0,0,640,10);
    bar(0,0,10,480);
    bar(0,480,640,470);
    bar(630,10,640,480);	
	}

		

	else {
	setfillstyle(1,2); // Default
    bar(0,0,640,10);
    bar(0,0,10,480);
    bar(0,480,640,470);
    bar(630,10,640,480);
	
	}
    
    
       // food taken?
       
   if(f%5!=0){         //IF SIZE OF SNAKE NOT 5 , NORMAL CODE 
   
   if(x[0]==rx && y[0]==ry ){
    length += 1;     //LENGTH
    f=f+1;           //FOOD
    
    //DISPLAYING FOOD
    
	setfillstyle(1,0);//(style,color)     
    bar(rx,ry,rx+10,ry+10);
     
    //make food
    do{
	rx = (1+rand()%630);           //DISPLAYING FOOD AR RANDOM LOCATIONS USING ran() FUNCTION)
	ry = (1+rand()%470);
    }while(getpixel(rx,ry)!=0 && rx > 10 && ry > 10);

    rx=rx/10;
    rx=rx*10;        //EQUAL SIZE F FOD AND SNAKE
    ry=ry/10;
    ry=ry*10;
    
  setfillstyle(1,2); // Default     increasing length
	
	
     }
	 bar(rx,ry,rx+10,ry+10);
	 }
      
                                  //     dangerous food            decrease the length
 if(f%5==0){                         //IF LENGTH 5 , DECREASE THE LENGTH
 
  if(x[0]==rx && y[0]==ry ){
    length -= 1;
    f=f+1;
    
   
    setfillstyle(1,4);//(style,color)     RED COLOR TO SHOW FOOD AFTER 5 SIZE
   
    bar(rx,ry,rx-20,ry-20);    //qs
    
    //make food
    do{
	rx = (rand()%620);
	ry = (rand()%460);
    }while(getpixel(rx,ry)!=0 && rx > 20 && ry > 20);
    
    //qs

    rx=rx/20;
    rx=rx*20;
    ry=ry/20;
    ry=ry*20;
    
    setfillstyle(1,4);  // to decrease the length
     
     }
      bar(rx,ry,rx+20,ry+20);  //qs
	 }
//      

   
    if(GetAsyncKeyState(VK_RIGHT)){d=1;}
    else if(GetAsyncKeyState(VK_LEFT)){ d=2;}
    else if(GetAsyncKeyState(VK_UP)){ d=3;}
    else if(GetAsyncKeyState(VK_DOWN)) {d=4;}
    else{d=0;}
    switch(d)
	{
    case 0:
      if(dir==1){x[0]=x[0]+10;}
      else if(dir==2){x[0]=x[0]-10;}
      else if(dir==3){ y[0]=y[0]-10;}
      else if(dir==4) {y[0]=y[0]+10;}
      else{d=0;}
      break;
    case 1:
           x[0]=x[0]+10;
           dir=1;         //qs
           break;
    case 2:
         x[0]= x[0]-10;
         dir=2;
          break;
    case 3:
        dir=3;
        y[0]=y[0]-10;
        break;
    case 4:
        dir=4;
       y[0]= y[0]+10;
        break;
    }
    for(int i = 0; i < length;i++){           //face
        bar(x[i],y[i],x[i]+10,y[i]+10);
    }
    for(int i= 199; i >0;i--){                //full body at new location
        x[i] = x[i-1];
        y[i] = y[i -1];
    }
    delay(100);
    if(x[0] >= 616 || x[0]<=0|| y[0]<=0 || y[0]>=456){     //boundry sa
    endfunc(f,0);  
    break;
    }

    for(int i = 2; i < length;i++){                  //body sa (qs)
        if(x[0] == x[i] && y[0] == y[i]){
            chk = i;
            break;
            }
    }
    if(x[0] == x[chk] && y[0] == y[chk]){
    endfunc(f,1);
    break;
    }
}
}

int endfunc(int e,int a){
    setfillstyle(1,5);
    e=(e-2)*10;
    
    bar(0,0,640,470);
    system("cls");
    if(a == 0){
    	cout<<endl<<endl<<endl;
		cout<<"\t\t\tYou died outside the boundary!!!\n";
    }
    else if(a== 1){
    	    cout<<endl<<endl<<endl;
			cout<<"\t\t\tYou died into yourself!!!\n";
    }
		cout<<"Your score is :\n"<<e;
		
	
   
}
