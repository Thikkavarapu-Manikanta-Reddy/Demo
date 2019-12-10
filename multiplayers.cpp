#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
int f1=0,n=1;
int x,y,fx,fy,width=20,height=20,scoreA=0,scoreB=0,time,p,z,kx,ky,btime;
enum edirection{STOP=0,LEFT,RIGHT,DOWN,UP};
edirection dir,con;
void data();
void disp();
void input();
void logic();
int main()
{
	data();
	while(gameover!=true)
	{
		disp();
		input();
		logic();
		Sleep(300);
	}
}
void data()
{
	gameover=false;
	x=width/2;
	y=height/2;
	p=width/2;
	z=height/3;
	fx=rand()%width;
	fy=rand()%height;
	kx=rand()%width;
	ky=rand()%height;
	dir=STOP;
	con=STOP;
	scoreA=0;
	scoreB=0;
	time=0;
	btime=0;
}
void disp()
{
	system("cls");
	for(int i=0;i<width+2;i++)
	{
		cout<<"o";	
	}
	cout<<endl;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			int flag=0;
			if(j==0)
			cout<<"o";
			if((scoreA==15*n&&scoreA!=0)||(scoreB==15*n&&scoreB!=0))
			{
				f1=1;
			}
			if(btime==25)
			{
			f1=0;
			n++;
			btime=0;
			}
			if(btime!=25&&f1==1)
				{
				if(i==ky&&j==kx)
				{
				cout<<"T";
				flag=1;
				}
				}
			 if(i==y&&j==x)
			cout<<"A";
				else if(i==z&&j==p)
			cout<<"B";
			 else if(i==fy&&j==fx)
			cout<<"$";
			else if(flag==0)
			cout<<" ";
			if(j==width-1)
			cout<<"o";
		}
		cout<<endl;
	}
	for(int i=0;i<width+2;i++)
	{
		cout<<"o";	
	}
	cout<<endl;
	cout<<"EAT FRUIT GAIN POINTS"<<endl<<endl;
	cout<<"DON'T TRY TO HIT THE WALL"<<endl<<endl;
	cout<<"SCORE A="<<scoreA<<" "<<"SCORE B="<<scoreB<<endl<<endl<<"TIME in seconds="<<time<<" "<<"BONUS OBJ TIME(25)="<<btime<<endl<<endl;
	if((scoreA==15*n&&scoreA!=0)||(scoreB==15*n&&scoreB!=0))
	{
	cout<<"YOUR TIME WILL BE REDUCED BY 30 SECONDS"<<endl<<" IF YOU EAT BONUS OBJECT WITHIN BONUS TIME(25):"<<endl<<endl<<"AND BONUS +10 TO SCORE:";
	}
	}
void input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
					
			case 'h':
				con=LEFT;
				break;
				case 'k':
					con=RIGHT;
					break;
					case 'j':
				con=DOWN;
				break;
				case 'u':
				con=UP;
				break;
			case 'a':
				dir=LEFT;
				break;
				case 'd':
					dir=RIGHT;
					break;
					case 's':
				dir=DOWN;
				break;
				case 'w':
				dir=UP;
				break;
		}
	}
}
void logic()
{
	switch(dir)
	{
	
		case LEFT:
			x--;
			break;
				case RIGHT:
			x++;
			break;
				case DOWN:
			y++;
			break;
				case UP:
			y--;
			break;
	}
	switch(con)
	{
	
		case LEFT:
			p--;
			break;
				case RIGHT:
			p++;
			break;
				case DOWN:
			z++;
			break;
				case UP:
			z--;
			break;
	}
	if((f1==1&&btime!=25)||(f1==1&&btime!=25))
	{
		btime+=1;
	}
	time+=1;
	if(time==301)
	gameover=true;
	if((x==width||x<0)||(y==height||y<0))
	gameover=true;
	if((p==width||p<0)||(z==height||z<0))
	gameover=true;
	if(x==p&&y==z)
	gameover=true;
	if(x==fx&&y==fy)
	{
		scoreA+=5;
		fx=rand()%width;
		fy=rand()%height;
	}
		if(x==kx&&y==ky)
	{
		scoreA+=10;
		time=time-25;
		n=n+1;
		btime=0;
		f1=0;
		kx=rand()%width;
		ky=rand()%height;
	}
	
		if(p==fx&&z==fy)
	{
		scoreB+=5;
		fx=rand()%width;
		fy=rand()%height;
	}
		if(p==kx&&z==ky)
	{
		scoreB+=10;
		time=time-25;
		n=n+1;
		btime=0;
		f1=0;
		kx=rand()%width;
		ky=rand()%height;
	}
	
	
}
