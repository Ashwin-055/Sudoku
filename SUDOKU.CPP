#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
//Matrix printer...
int prints=0;
void prmx(int i[9][9],int yl,int s[9][9]){
  int y,x,xl,y1=yl;
  cout<<endl;
  for(y=0;y<9;y++){
    for(x=0;x<9;x++){
      if(i[y][x])printf("\033[1;37m %d",s[y][x]);
      else if(!i[y][x]&&!prints)printf("  ");
      else printf("\033[1;32m %d",s[y][x]);
    }
    cout<<endl;
  }
  for(xl=0;xl<150;xl+=16){
    if(xl==0||xl==48||xl==96||xl==144){
      setlinestyle(SOLID_LINE,1,3);
      setcolor(7);
    }
    else{
      setlinestyle(SOLID_LINE,1,2);
      setcolor(3);
    }
    line(xl+3,yl-1,xl+3,yl+145);
  }int yi=0;
  for(yl;yl<y1+150;yl+=16,yi++){
    if(yi==0||yi==3||yi==6||yi==9){
      setlinestyle(SOLID_LINE,1,3);
      setcolor(7);
    }
    else{
      setlinestyle(SOLID_LINE,1,2);
      setcolor(3);
    }
    line(5,yl,145,yl);
  }
  prints++;
  return;
}
//Check if n can be placed in y,x position...
int check(int s[9][9],int y,int x,int n){
  int i,j;
  for(i=0;i<9;i++)if(s[y][i]==n)return 0;y=(y/3)*3;
  for(i=0;i<9;i++)if(s[i][x]==n)return 0;x=(x/3)*3;
  for(i=0;i<3;i++)for(j=0;j<3;j++)if(s[y+i][x+j]==n)return 0;
  return 1;
}
//Sudoku completer...
void tryn(int i[9][9],int s[9][9]){
  int y,x,n;
  for(y=0;y<9;y++)for(x=0;x<9;x++)
    if(s[y][x]==0){
      for(n=1;n<=9;n++)
	if(check(s,y,x,n)){
	  s[y][x]=n;tryn(i,s);s[y][x]=0;
	}
	return;
    }
  getch();
  cout<<"\n\033[1;37mSolution "<<prints<<": (Press any key for more solutions)";
  if(prints==1)prmx(i,190,s);else prmx(i,318,s);
  if(prints>2)cout<<"\n\n\n\n\n";
  gotoxy(50,1);
  cout<<"Hi"<<endl;
  if(prints==2)gotoxy(1,22);else gotoxy(1,25);
}
//Main function...
void main(){
  textbackground(BLACK);clrscr();
  int y,x,ttt[9][9]={0},gd=DETECT,gm,sol[9][9],
  inp[9][9]={{0,0,0,3,0,0,0,6,0},
	     {0,6,4,0,0,1,0,2,0},
	     {0,0,0,5,0,0,0,0,0},
	     {0,2,3,0,5,0,6,0,0},
	     {0,0,9,8,0,3,7,0,0},
	     {0,0,8,0,9,0,1,4,0},
	     {0,0,0,0,0,9,0,0,0},
	     {0,1,0,4,0,0,8,9,0},
	     {0,5,0,0,0,0,0,0,0}};
  //cout<<"Enter the sudoku matrix:\n";
  for(y=0;y<9;y++)for(x=0;x<9;x++){/*cin>>inp[y][x];*/sol[y][x]=inp[y][x];}
  clrscr();initgraph(&gd,&gm,"c:\\turboc3\\bgi");
  printf("\033[1;37mOriginal matrix: (Press any key for solutions)");
  prmx(inp,14,sol);tryn(inp,sol);
  cout<<"\n\033[1;37mPress anything to exit...";
  getch();closegraph();
}