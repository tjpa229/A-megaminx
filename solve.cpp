#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<ctime>
#include<random>
#include<algorithm>



using namespace std;

void psv(const char*,string,const int, const int);


struct child{
  vector<int> moves; //vector to store each move to produce a specific child
  int g;
  int h;
};

vector<string> pmtations ;

struct puzzle{
  string megaminx[12][11];
  vector<puzzle*> children;
};

void printFace(string face[11])
{
  cout<<setw(11)<<""<<face[1]<<endl;
  cout<<""<<endl;
  cout<<setw(5)<<""<<face[2]<<setw(11)<<""<<face[10]<<endl;
  cout<<""<<endl;
  cout<<setw(3)<<""<<face[3]<<setw(7) <<""<<face[0]<<setw(8)<<""<<face[9]<<endl;
  cout<<""<<endl;
  cout<<setw(5)<<""<<face[4]<<setw(12)<<""<<face[8]<<endl;
  cout<<""<<endl;
  cout<<setw(7)<<""<<face[5]<<setw(3)<<""<<face[6]<<setw(3)<<""<<face[7];
}



void printUpsideDownFace(string face[11])
{
  cout<<setw(7)<<""<<face[5]<<setw(3)<<""<<face[6]<<setw(3)<<""<<face[7]<<endl;
  cout<<""<<endl;
  cout<<setw(5)<<""<<face[4]<<setw(12)<<""<<face[8]<<endl;
  cout<<""<<endl;
  cout<<setw(3)<<""<<face[3]<<setw(7) <<""<<face[0]<<setw(8)<<""<<face[9]<<endl;
  cout<<""<<endl;
  cout<<setw(5)<<""<<face[2]<<setw(11)<<""<<face[10]<<endl;
  cout<<""<<endl;
  cout<<setw(11)<<""<<face[1];

  //cout<<""<<endl;
}


void printMegaminx(string megaminx[12][11])
{

//===  =====================

        cout<<setw(27)<<""<<megaminx[1][1]<<setw(31)<<""<<megaminx[11][7]<<setw(3)<<""<<megaminx[11][6]<<setw(3)<<""<<megaminx[11][5]<<setw(15)<<""<<megaminx[10][7]<<setw(3)<<""<<megaminx[10][6]<<setw(3)<<""<<megaminx[10][5]<<endl;

        cout<<""<<endl;
        cout<<setw(21)<<""<<megaminx[1][2]<<setw(11)<<""<<megaminx[1][10]<<setw(22)<<""<<megaminx[11][8]<<setw(12)<<""<<megaminx[11][4]<<setw(11)<<""<<megaminx[10][8]<<setw(10)<<setw(11)<<""<<megaminx[10][4]<<endl;
        cout<<""<<endl;
        cout<<setw(19)<<""<<megaminx[1][3]<<setw(7) <<""<<megaminx[1][0]<<setw(8)<<""<<megaminx[1][9]<<setw(17)<<""<<megaminx[11][9]<<setw(7) <<""<<megaminx[11][0]<<setw(8)<<""<<megaminx[11][3];
        cout<<setw(6)<<""<<megaminx[10][9]<<setw(8)<<""<<megaminx[10][0]<<setw(8)<<""<<megaminx[10][3]<<endl;
        cout<<""<<endl;
        cout<<setw(11)<<""<<megaminx[2][1]<<setw(9)<<""<<megaminx[1][4]<<setw(12)<<""<<megaminx[1][8]<<setw(8)<<""<<megaminx[5][1]<<setw(7)<<""<<setw(5)<<""<<megaminx[11][10];
        cout<<setw(12)<<""<<megaminx[11][2]<<setw(5)<<""<<megaminx[7][1]<<setw(6)<<""<<megaminx[10][10]<<setw(11)<<""<<megaminx[10][2]<<endl;
        cout<<""<<endl;
        cout<<setw(5)<<""<<megaminx[2][2]<<setw(11)<<""<<megaminx[2][10]<<setw(5)<<""<<megaminx[1][5]<<setw(3)<<""<<megaminx[1][6]<<setw(3)<<""<<megaminx[1][7]<<setw(5)<<""<<megaminx[5][2];
        cout<<setw(11)<<""<<megaminx[5][10]<<setw(12)<<""<<megaminx[11][1]<<setw(7)<<""<<megaminx[7][2]<<setw(11)<<""<<megaminx[7][10]<<setw(5)<<""<<megaminx[10][1]<<endl;

        cout<<""<<endl;
      // ======
        cout<<setw(3)<<""<<megaminx[2][3]<<setw(7) <<""<<megaminx[2][0]<<setw(8)<<""<<megaminx[2][9]<<setw(2)<<""<<megaminx[0][7]<<setw(3)<<""<<megaminx[0][6]<<setw(3)<<""<<megaminx[0][5];
        cout<<setw(3)<<""<<megaminx[5][3]<<setw(7) <<""<<megaminx[5][0]<<setw(8)<<""<<megaminx[5][9]<<setw(2)<<""<<megaminx[6][7];
        cout<<setw(3)<<""<<megaminx[6][6]<<setw(3)<<""<<megaminx[6][5]<<setw(3)<<""<<megaminx[7][3]<<setw(8)<<""<<megaminx[7][0]<<setw(7)<<""<<megaminx[7][9]<<setw(3)<<""<<megaminx[9][7]<<setw(3)<<""<<megaminx[9][6]<<""<<setw(3)<<""<<megaminx[9][5]<<endl;
        cout<<""<<endl;
        cout<<setw(5)<<""<<megaminx[2][4]<<setw(12)<<""<<megaminx[2][8]<<setw(2)<<""<<megaminx[0][8]<<setw(11)<<""<<megaminx[0][4]<<setw(3)<<""<<megaminx[5][4]<<setw(12)<<""<<megaminx[5][8];
        cout<<setw(2)<<""<<megaminx[6][8]<<setw(11)<<""<<megaminx[6][4]<<setw(4)<<""<<megaminx[7][4]<<setw(11)<<""<<megaminx[7][8]<<setw(3)<<""<<megaminx[9][8]<<setw(12)<<""<<megaminx[9][4]<<endl;


        cout<<""<<endl;
        cout<<setw(7)<<""<<megaminx[2][5]<<setw(3)<<""<<megaminx[2][6]<<setw(3)<<""<<megaminx[2][7]<<setw(3)<<""<<megaminx[0][9]<<setw(7)<<""<<megaminx[0][0]<<setw(8)<<""<<megaminx[0][3];
        cout<<setw(2)<<""<<megaminx[5][5]<<setw(3)<<""<<megaminx[5][6]<<setw(3)<<""<<megaminx[5][7]<<setw(2)<<""<<megaminx[6][9]<<setw(8)<<""<<megaminx[6][0]<<setw(8)<<""<<megaminx[6][3]<<setw(3)<<""<<megaminx[7][5]<<setw(3)<<""<<megaminx[7][6]<<setw(3)<<""<<megaminx[7][7];
        cout<<setw(3)<<""<<megaminx[9][9]<<setw(7)<<""<<megaminx[9][0]<<setw(7)<<""<<megaminx[9][3]<<endl;
        cout<<setw(14)<<""<<megaminx[3][1]<<setw(25)<<""<<megaminx[4][1]<<endl;
        cout<<setw(21)<<""<<megaminx[0][10]<<setw(10)<<""<<megaminx[0][2]<<setw(20)<<""<<megaminx[6][10]<<setw(11)<<""<<megaminx[6][2]<<setw(6)<<""<<megaminx[8][7]<<setw(3)<<""<<megaminx[8][6]<<setw(3)<<""<<megaminx[8][5]<<setw(7)<<""<<megaminx[9][10]<<setw(8)<<""<<megaminx[9][2]<<endl;
        cout<<setw(8)<<""<<megaminx[3][2]<<setw(11)<<""<<megaminx[3][10]<<setw(12)<<""<<megaminx[4][2]<<setw(11)<<""<<megaminx[4][10]<<endl;
        cout<<setw(27)<<""<<megaminx[0][1]<<setw(31)<<""<<megaminx[6][1]<<setw(10)<<""<<megaminx[8][8]<<setw(11)<<""<<megaminx[8][4]<<setw(10)<<""<<megaminx[9][1]<<endl;
        cout<<setw(6)<<""<<megaminx[3][3]<<setw(7) <<""<<megaminx[3][0]<<setw(8)<<""<<megaminx[3][9]<<setw(7)<<""<<megaminx[4][3]<<setw(7)<<""<<megaminx[4][0]<<setw(7)<<""<<megaminx[4][9]<<endl;
        cout<<setw(68)<<""<<megaminx[8][9]<<""<<setw(7)<<""<<megaminx[8][0]<<setw(7)<<""<<megaminx[8][3]<<endl;
        cout<<setw(8)<<""<<megaminx[3][4]<<setw(12)<<""<<megaminx[3][8]<<setw(11)<<""<<megaminx[4][4]<<setw(11)<<""<<megaminx[4][8]<<endl;
        cout<<setw(71)<<""<<megaminx[8][10]<<setw(9)<<""<<megaminx[8][2]<<endl;
        cout<<setw(10)<<""<<megaminx[3][5]<<setw(3)<<""<<megaminx[3][6]<<setw(3)<<""<<megaminx[3][7]<<setw(16)<<""<<megaminx[4][5]<<setw(3)<<""<<megaminx[4][6]<<setw(3)<<""<<megaminx[4][7]<<setw(32)<<""<<megaminx[8][1]<<endl;



}


int selectArrayIndexGivenFace(string face)
{
  string colors[12]={"green", "white", "magenta", "blue", "gold", "red", "pink", "lime", "cyan", "orange", "yellow", "skyblue"};
  int i=0;
  while(face!=colors[i])
  {
    i++;
  }
  return i;

}

void updateFaceWhenRotateRight(int i, string copy[12][11], string (&megaminx)[12][11])
{
  //this part of the code accounts for how the green face changes when it is rotated
  megaminx[i][10]=copy[i][2];
  megaminx[i][9]=copy[i][1];
  megaminx[i][8]=copy[i][10];
  megaminx[i][7]=copy[i][9];
  megaminx[i][6]=copy[i][8];
  megaminx[i][5]=copy[i][7];
  megaminx[i][4]=copy[i][6];
  megaminx[i][3]=copy[i][5];
  megaminx[i][2]=copy[i][4];
  megaminx[i][1]=copy[i][3];
  //
}

void updateFaceWhenRotateLeft(int i, string copy[12][11], string (&megaminx)[12][11])
{
  //this part of the code accounts for how the green face changes when it is rotated
  megaminx[i][2]=copy[i][10];
  megaminx[i][1]=copy[i][9];
  megaminx[i][10]=copy[i][8];
  megaminx[i][9]=copy[i][7];
  megaminx[i][8]=copy[i][6];
  megaminx[i][7]=copy[i][5];
  megaminx[i][6]=copy[i][4];
  megaminx[i][5]=copy[i][3];
  megaminx[i][4]=copy[i][2];
  megaminx[i][3]=copy[i][1];
  //
}



void  moveGreenRight(string copy[12][11], string (&megaminx)[12][11])
{
  string myFacex="green";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateRight(index,copy, megaminx);

  //this part of the code accounts for how the 5 adjacent faces change when green is rotated//
  megaminx[1][5]=copy[2][7];
  megaminx[1][6]=copy[2][8];
  megaminx[1][7]=copy[2][9];

  megaminx[2][9]=copy[3][1];
  megaminx[2][8]=copy[3][10];
  megaminx[2][7]=copy[3][9];

  megaminx[3][1]=copy[4][1];
  megaminx[3][10]=copy[4][3];
  megaminx[3][9]=copy[4][2];

  megaminx[4][1]=copy[5][3];
  megaminx[4][3]=copy[5][4];
  megaminx[4][2]=copy[5][5];

  megaminx[5][3]=copy[1][5];
  megaminx[5][4]=copy[1][6];
  megaminx[5][5]=copy[1][7];
//-------
}


void moveGreenLeft(string copy[12][11], string(&megaminx)[12][11])
{
  //moves adjacent faces
  string myFacex="green";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateLeft(index,copy, megaminx);

  //this part of the code accounts for how the 5 adjacent faces change when green is rotated//
  megaminx[2][7]=copy[1][5];
  megaminx[2][8]=copy[1][6];
  megaminx[2][9]=copy[1][7];

  megaminx[3][1]=copy[2][9];
  megaminx[3][10]=copy[2][8];
  megaminx[3][9]=copy[2][7];

  megaminx[4][1]=copy[3][1];
  megaminx[4][3]=copy[3][10];
  megaminx[4][2]=copy[3][9];

  megaminx[5][3]=copy[4][1];
  megaminx[5][4]=copy[4][3];
  megaminx[5][5]=copy[4][2];

  megaminx[1][5]=copy[5][3];
  megaminx[1][6]=copy[5][4];
  megaminx[1][7]=copy[5][5];
}


//==

void moveWhiteRight(string copy[12][11], string (&megaminx)[12][11])
{
  string myFacex="white";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateRight(index,copy, megaminx);

  //moves adjacent faces

  megaminx[0][5]=copy[5][1];
  megaminx[0][6]=copy[5][2];
  megaminx[0][7]=copy[5][3];

  megaminx[2][9]=copy[0][5];
  megaminx[2][10]=copy[0][6];
  megaminx[2][1]=copy[0][7];

  megaminx[11][5]=copy[10][5];
  megaminx[11][6]=copy[10][6];
  megaminx[11][7]=copy[10][7];

  megaminx[10][5]=copy[2][9];
  megaminx[10][6]=copy[2][10];
  megaminx[10][7]=copy[2][1];

  megaminx[5][1]=copy[11][5];
  megaminx[5][2]=copy[11][6];
  megaminx[5][3]=copy[11][7];

  //=====

}


void moveWhiteLeft(string copy[12][11], string(&megaminx)[12][11])
{
  string myFacex="white";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateLeft(index,copy, megaminx);

  //moves adjacent faces

  megaminx[5][1]=copy[0][5];
  megaminx[5][2]=copy[0][6];
  megaminx[5][3]=copy[0][7];

  megaminx[0][5]=copy[2][9];
  megaminx[0][6]=copy[2][10];
  megaminx[0][7]=copy[2][1];

  megaminx[10][5]=copy[11][5];
  megaminx[10][6]=copy[11][6];
  megaminx[10][7]=copy[11][7];

  megaminx[2][9]=copy[10][5];
  megaminx[2][10]=copy[10][6];
  megaminx[2][1]=copy[10][7];

  megaminx[11][5]=copy[5][1];
  megaminx[11][6]=copy[5][2];
  megaminx[11][7]=copy[5][3];

}



void moveMagentaRight(string copy[12][11], string (&megaminx)[12][11])
{
  string myFacex="magenta";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateRight(index,copy, megaminx);

  //moves adjacent faces

  megaminx[0][7]=copy[1][3];
  megaminx[0][8]=copy[1][4];
  megaminx[0][9]=copy[1][5];

  megaminx[3][1]=copy[0][7];
  megaminx[3][2]=copy[0][8];
  megaminx[3][3]=copy[0][9];

  megaminx[1][3]=copy[10][3];
  megaminx[1][4]=copy[10][4];
  megaminx[1][5]=copy[10][5];

  megaminx[10][5]=copy[9][5];
  megaminx[10][4]=copy[9][4];
  megaminx[10][3]=copy[9][3];

  megaminx[9][5]=copy[3][3];
  megaminx[9][4]=copy[3][2];
  megaminx[9][3]=copy[3][1];

}

void moveMagentaLeft(string copy[12][11], string(&megaminx)[12][11])
{
  //moves adjacent faces
  string myFacex="magenta";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateLeft(index,copy, megaminx);

  //moves adjacent faces

  megaminx[1][3]=copy[0][7];
  megaminx[1][4]=copy[0][8];
  megaminx[1][5]=copy[0][9];

  megaminx[0][7]=copy[3][1];
  megaminx[0][8]=copy[3][2];
  megaminx[0][9]=copy[3][3];

  megaminx[10][3]=copy[1][3];
  megaminx[10][4]=copy[1][4];
  megaminx[10][5]=copy[1][5];

  megaminx[9][5]=copy[10][5];
  megaminx[9][4]=copy[10][4];
  megaminx[9][3]=copy[10][3];

  megaminx[3][3]=copy[9][5];
  megaminx[3][2]=copy[9][4];
  megaminx[3][1]=copy[9][3];

}

void moveBlueRight(string copy[12][11], string (&megaminx)[12][11])
{
  string myFacex="blue";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateRight(index,copy, megaminx);

  //moves adjacent faces

  megaminx[0][9]=copy[2][5];
  megaminx[0][10]=copy[2][6];
  megaminx[0][1]=copy[2][7];

  megaminx[4][3]=copy[0][9];
  megaminx[4][4]=copy[0][10];
  megaminx[4][5]=copy[0][1];

  megaminx[8][3]=copy[4][5];
  megaminx[8][2]=copy[4][4];
  megaminx[8][1]=copy[4][3];

  megaminx[9][1]=copy[8][1];
  megaminx[9][2]=copy[8][2];
  megaminx[9][3]=copy[8][3];

  megaminx[2][5]=copy[9][1];
  megaminx[2][6]=copy[9][2];
  megaminx[2][7]=copy[9][3];

}

void moveBlueLeft(string copy[12][11], string(&megaminx)[12][11])
{
  string myFacex="blue";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateLeft(index,copy, megaminx);

  //moves adjacent faces

  megaminx[2][5]=copy[0][9];
  megaminx[2][6]=copy[0][10];
  megaminx[2][7]=copy[0][1];

  megaminx[0][9]=copy[4][3];
  megaminx[0][10]=copy[4][4];
  megaminx[0][1]=copy[4][5];

  megaminx[4][5]=copy[8][3];
  megaminx[4][4]=copy[8][2];
  megaminx[4][3]=copy[8][1];

  megaminx[8][1]=copy[9][1];
  megaminx[8][2]=copy[9][2];
  megaminx[8][3]=copy[9][3];

  megaminx[9][1]=copy[2][5];
  megaminx[9][2]=copy[2][6];
  megaminx[9][3]=copy[2][7];

}

void moveGoldRight(string copy[12][11], string (&megaminx)[12][11])
{
  string myFacex="gold";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateRight(index,copy, megaminx);

  //moves adjacent faces

  megaminx[0][1]=copy[3][7];
  megaminx[0][2]=copy[3][8];
  megaminx[0][3]=copy[3][9];

  megaminx[5][5]=copy[0][1];
  megaminx[5][6]=copy[0][2];
  megaminx[5][7]=copy[0][3];

  megaminx[6][9]=copy[5][5];
  megaminx[6][10]=copy[5][6];
  megaminx[6][1]=copy[5][7];

  megaminx[8][9]=copy[6][9];
  megaminx[8][10]=copy[6][10];
  megaminx[8][1]=copy[6][1];

  megaminx[3][9]=copy[8][1];
  megaminx[3][8]=copy[8][10];
  megaminx[3][7]=copy[8][9];

}

void moveGoldLeft(string copy[12][11], string(&megaminx)[12][11])
{
  string myFacex="gold";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateLeft(index,copy, megaminx);

  //moves adjacent faces

  megaminx[3][7]=copy[0][1];
  megaminx[3][8]=copy[0][2];
  megaminx[3][9]=copy[0][3];

  megaminx[0][1]=copy[5][5];
  megaminx[0][2]=copy[5][6];
  megaminx[0][3]=copy[5][7];

  megaminx[5][5]=copy[6][9];
  megaminx[5][6]=copy[6][10];
  megaminx[5][7]=copy[6][1];

  megaminx[6][9]=copy[8][9];
  megaminx[6][10]=copy[8][10];
  megaminx[6][1]=copy[8][1];

  megaminx[8][1]=copy[3][9];
  megaminx[8][10]=copy[3][8];
  megaminx[8][9]=copy[3][7];
}

void moveRedRight(string copy[12][11], string (&megaminx)[12][11])
{
  string myFacex="red";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateRight(index,copy, megaminx);

  //moves adjacent faces

  megaminx[1][7]=copy[0][3];
  megaminx[1][8]=copy[0][4];
  megaminx[1][9]=copy[0][5];

  megaminx[0][3]=copy[4][9];
  megaminx[0][4]=copy[4][10];
  megaminx[0][5]=copy[4][1];

  megaminx[4][9]=copy[6][7];
  megaminx[4][10]=copy[6][8];
  megaminx[4][1]=copy[6][9];

  megaminx[6][7]=copy[11][7];
  megaminx[6][8]=copy[11][8];
  megaminx[6][9]=copy[11][9];

  megaminx[11][7]=copy[1][7];
  megaminx[11][8]=copy[1][8];
  megaminx[11][9]=copy[1][9];

}


void moveRedLeft(string copy[12][11], string(&megaminx)[12][11])
{
  string myFacex="red";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateLeft(index,copy, megaminx);

  //moves adjacent faces

  megaminx[0][3]=copy[1][7];
  megaminx[0][4]=copy[1][8];
  megaminx[0][5]=copy[1][9];

  megaminx[4][9]=copy[0][3];
  megaminx[4][10]=copy[0][4];
  megaminx[4][1]=copy[0][5];

  megaminx[6][7]=copy[4][9];
  megaminx[6][8]=copy[4][10];
  megaminx[6][9]=copy[4][1];

  megaminx[11][7]=copy[6][7];
  megaminx[11][8]=copy[6][8];
  megaminx[11][9]=copy[6][9];

  megaminx[1][7]=copy[11][7];
  megaminx[1][8]=copy[11][8];
  megaminx[1][9]=copy[11][9];

}

void movePinkRight(string copy[12][11], string (&megaminx)[12][11])
{
  string myFacex="pink";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateRight(index,copy, megaminx);

  //moves adjacent faces

  megaminx[5][7]=copy[4][7];
  megaminx[5][8]=copy[4][8];
  megaminx[5][9]=copy[4][9];

  megaminx[11][9]=copy[5][7];
  megaminx[11][10]=copy[5][8];
  megaminx[11][1]=copy[5][9];

  megaminx[7][3]=copy[11][9];
  megaminx[7][4]=copy[11][10];
  megaminx[7][5]=copy[11][1];

  megaminx[8][7]=copy[7][3];
  megaminx[8][8]=copy[7][4];
  megaminx[8][9]=copy[7][5];

  megaminx[4][7]=copy[8][7];
  megaminx[4][8]=copy[8][8];
  megaminx[4][9]=copy[8][9];

}

void movePinkLeft(string copy[12][11], string(&megaminx)[12][11])
{
  string myFacex="pink";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateLeft(index,copy, megaminx);

  //moves adjacent faces

  megaminx[4][7]=copy[5][7];
  megaminx[4][8]=copy[5][8];
  megaminx[4][9]=copy[5][9];

  megaminx[5][7]=copy[11][9];
  megaminx[5][8]=copy[11][10];
  megaminx[5][9]=copy[11][1];

  megaminx[11][9]=copy[7][3];
  megaminx[11][10]=copy[7][4];
  megaminx[11][1]=copy[7][5];

  megaminx[7][3]=copy[8][7];
  megaminx[7][4]=copy[8][8];
  megaminx[7][5]=copy[8][9];

  megaminx[8][7]=copy[4][7];
  megaminx[8][8]=copy[4][8];
  megaminx[8][9]=copy[4][9];

}

void moveLimeRight(string copy[12][11], string (&megaminx)[12][11])
{
  string myFacex="lime";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateRight(index,copy, megaminx);

  //moves adjacent faces

  megaminx[6][5]=copy[8][7];
  megaminx[6][4]=copy[8][6];
  megaminx[6][3]=copy[8][5];

  megaminx[11][1]=copy[6][3];
  megaminx[11][2]=copy[6][4];
  megaminx[11][3]=copy[6][5];

  megaminx[10][9]=copy[11][1];
  megaminx[10][10]=copy[11][2];
  megaminx[10][1]=copy[11][3];

  megaminx[9][7]=copy[10][9];
  megaminx[9][8]=copy[10][10];
  megaminx[9][9]=copy[10][1];

  megaminx[8][7]=copy[9][9];
  megaminx[8][6]=copy[9][8];
  megaminx[8][5]=copy[9][7];

}

void moveLimeLeft(string copy[12][11], string(&megaminx)[12][11])
{
  string myFacex="lime";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateLeft(index,copy, megaminx);

  //moves adjacent faces

  megaminx[8][7]=copy[6][5];
  megaminx[8][6]=copy[6][4];
  megaminx[8][5]=copy[6][3];

  megaminx[6][3]=copy[11][1];
  megaminx[6][4]=copy[11][2];
  megaminx[6][5]=copy[11][3];

  megaminx[11][1]=copy[10][9];
  megaminx[11][2]=copy[10][10];
  megaminx[11][3]=copy[10][1];

  megaminx[10][9]=copy[9][7];
  megaminx[10][10]=copy[9][8];
  megaminx[10][1]=copy[9][9];

  megaminx[9][9]=copy[8][7];
  megaminx[9][8]=copy[8][6];
  megaminx[9][7]=copy[8][5];
}

void moveCyanRight(string copy[12][11], string (&megaminx)[12][11])
{
  string myFacex="cyan";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateRight(index,copy, megaminx);

  //moves adjacent faces

  megaminx[3][5]=copy[9][9];
  megaminx[3][6]=copy[9][10];
  megaminx[3][7]=copy[9][1];

  megaminx[4][5]=copy[3][5];
  megaminx[4][6]=copy[3][6];
  megaminx[4][7]=copy[3][7];

  megaminx[6][1]=copy[4][5];
  megaminx[6][2]=copy[4][6];
  megaminx[6][3]=copy[4][7];

  megaminx[7][5]=copy[6][1];
  megaminx[7][6]=copy[6][2];
  megaminx[7][7]=copy[6][3];

  megaminx[9][9]=copy[7][5];
  megaminx[9][10]=copy[7][6];
  megaminx[9][1]=copy[7][7];

}

void moveCyanLeft(string copy[12][11], string(&megaminx)[12][11])
{
  string myFacex="cyan";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateLeft(index,copy, megaminx);

  //moves adjacent faces

  megaminx[9][9]=copy[3][5];
  megaminx[9][10]=copy[3][6];
  megaminx[9][1]=copy[3][7];

  megaminx[3][5]=copy[4][5];
  megaminx[3][6]=copy[4][6];
  megaminx[3][7]=copy[4][7];

  megaminx[4][5]=copy[6][1];
  megaminx[4][6]=copy[6][2];
  megaminx[4][7]=copy[6][3];

  megaminx[6][1]=copy[7][5];
  megaminx[6][2]=copy[7][6];
  megaminx[6][3]=copy[7][7];

  megaminx[7][5]=copy[9][9];
  megaminx[7][6]=copy[9][10];
  megaminx[7][7]=copy[9][1];

}

void moveOrangeRight(string copy[12][11], string (&megaminx)[12][11])
{
  string myFacex="orange";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateRight(index,copy, megaminx);

  //moves adjacent faces

  megaminx[10][1]=copy[7][7];
  megaminx[10][2]=copy[7][8];
  megaminx[10][3]=copy[7][9];

  megaminx[7][7]=copy[8][3];
  megaminx[7][8]=copy[8][4];
  megaminx[7][9]=copy[8][5];

  megaminx[8][3]=copy[3][3];
  megaminx[8][4]=copy[3][4];
  megaminx[8][5]=copy[3][5];

  megaminx[3][3]=copy[2][3];
  megaminx[3][4]=copy[2][4];
  megaminx[3][5]=copy[2][5];

  megaminx[2][3]=copy[10][1];
  megaminx[2][4]=copy[10][2];
  megaminx[2][5]=copy[10][3];

}

void moveOrangeLeft(string copy[12][11], string(&megaminx)[12][11])
{
  string myFacex="orange";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateLeft(index,copy, megaminx);

  //moves adjacent faces

  megaminx[7][7]=copy[10][1];
  megaminx[7][8]=copy[10][2];
  megaminx[7][9]=copy[10][3];

  megaminx[8][3]=copy[7][7];
  megaminx[8][4]=copy[7][8];
  megaminx[8][5]=copy[7][9];

  megaminx[3][3]=copy[8][3];
  megaminx[3][4]=copy[8][4];
  megaminx[3][5]=copy[8][5];

  megaminx[2][3]=copy[3][3];
  megaminx[2][4]=copy[3][4];
  megaminx[2][5]=copy[3][5];

  megaminx[10][1]=copy[2][3];
  megaminx[10][2]=copy[2][4];
  megaminx[10][3]=copy[2][5];
}

void moveYellowRight(string copy[12][11], string (&megaminx)[12][11])
{
  string myFacex="yellow";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateRight(index,copy, megaminx);

  //moves adjacent faces

  megaminx[11][5]=copy[7][1];
  megaminx[11][4]=copy[7][10];
  megaminx[11][3]=copy[7][9];

  megaminx[7][1]=copy[9][7];
  megaminx[7][10]=copy[9][6];
  megaminx[7][9]=copy[9][5];

  megaminx[9][7]=copy[2][3];
  megaminx[9][6]=copy[2][2];
  megaminx[9][5]=copy[2][1];

  megaminx[2][1]=copy[1][1];
  megaminx[2][2]=copy[1][2];
  megaminx[2][3]=copy[1][3];

  megaminx[1][1]=copy[11][3];
  megaminx[1][2]=copy[11][4];
  megaminx[1][3]=copy[11][5];

}

void moveYellowLeft(string copy[12][11], string(&megaminx)[12][11])
{
  string myFacex="yellow";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateLeft(index,copy, megaminx);

  //moves adjacent faces

  megaminx[7][1]=copy[11][5];
  megaminx[7][10]=copy[11][4];
  megaminx[7][9]=copy[11][3];

  megaminx[9][7]=copy[7][1];
  megaminx[9][6]=copy[7][10];
  megaminx[9][5]=copy[7][9];

  megaminx[2][3]=copy[9][7];
  megaminx[2][2]=copy[9][6];
  megaminx[2][1]=copy[9][5];

  megaminx[1][1]=copy[2][1];
  megaminx[1][2]=copy[2][2];
  megaminx[1][3]=copy[2][3];

  megaminx[11][3]=copy[1][1];
  megaminx[11][4]=copy[1][2];
  megaminx[11][5]=copy[1][3];

}


void moveSkyBlueRight(string copy[12][11], string (&megaminx)[12][11])
{
  string myFacex="skyblue";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateRight(index,copy, megaminx);

  //moves adjacent faces

  megaminx[1][1]=copy[5][1];
  megaminx[1][10]=copy[5][10];
  megaminx[1][9]=copy[5][9];

  megaminx[5][1]=copy[6][7];
  megaminx[5][10]=copy[6][6];
  megaminx[5][9]=copy[6][5];

  megaminx[6][7]=copy[7][3];
  megaminx[6][6]=copy[7][2];
  megaminx[6][5]=copy[7][1];

  megaminx[7][1]=copy[10][7];
  megaminx[7][2]=copy[10][8];
  megaminx[7][3]=copy[10][9];

  megaminx[10][7]=copy[1][9];
  megaminx[10][8]=copy[1][10];
  megaminx[10][9]=copy[1][1];

}

void moveSkyBlueLeft(string copy[12][11], string(&megaminx)[12][11])
{
  string myFacex="skyblue";
  int index = selectArrayIndexGivenFace(myFacex);
  updateFaceWhenRotateLeft(index,copy, megaminx);

  //moves adjacent faces

  megaminx[5][1]=copy[1][1];
  megaminx[5][10]=copy[1][10];
  megaminx[5][9]=copy[1][9];

  megaminx[6][7]=copy[5][1];
  megaminx[6][6]=copy[5][10];
  megaminx[6][5]=copy[5][9];

  megaminx[7][3]=copy[6][7];
  megaminx[7][2]=copy[6][6];
  megaminx[7][1]=copy[6][5];

  megaminx[10][7]=copy[7][1];
  megaminx[10][8]=copy[7][2];
  megaminx[10][9]=copy[7][3];

  megaminx[1][9]=copy[10][7];
  megaminx[1][10]=copy[10][8];
  megaminx[1][1]=copy[10][9
  ];
}

void move(string face, string direction, string (&megaminx)[12][11])
{
  string copy[12][11];
  for(int i=0;i<12;i++)
  {
    for(int j=0;j<11;j++)
    {
      copy[i][j]=megaminx[i][j];
    }
  }

  if(face=="blue")
  {
    if(direction=="right")
    {
      moveBlueRight(copy, megaminx);
    }
    else if(direction=="left")
    {
      moveBlueLeft(copy, megaminx);
    }
  }

  else if(face=="white")
  {
    if(direction=="right")
    {
      moveWhiteRight(copy, megaminx);
    }
    else if(direction=="left")
    {
      moveWhiteLeft(copy, megaminx);
    }
  }
  else if(face=="gold")
  {
    if(direction=="right")
    {
      moveGoldRight(copy, megaminx);
    }
    else if(direction=="left")
    {
      moveGoldLeft(copy, megaminx);
    }
  }

  else if(face=="red")
  {
    if(direction=="right")
    {
      moveRedRight(copy, megaminx);
    }
    else if(direction=="left")
    {
      moveRedLeft(copy, megaminx);
    }
  }

  else if(face=="pink")
  {
    if(direction=="right")
    {
      movePinkRight(copy, megaminx);
    }
    else if(direction=="left")
    {
      movePinkLeft(copy, megaminx);
    }


  }

  else if(face=="lime")
  {
    if(direction=="right")
    {
      moveLimeRight(copy, megaminx);
    }
    else if(direction=="left")
    {
      moveLimeLeft(copy, megaminx);
    }
  }
  else if(face=="cyan")
  {
    if(direction=="right")
    {
      moveCyanRight(copy, megaminx);
    }
    else if(direction=="left")
    {
      moveCyanLeft(copy, megaminx);
    }
  }

  else if(face=="orange")
  {
    if(direction=="right")
    {
      moveOrangeRight(copy, megaminx);
    }
    else if(direction=="left")
    {
      moveOrangeLeft(copy, megaminx);
    }
  }

  else if(face=="yellow")
  {
    if(direction=="right")
    {
      moveYellowRight(copy, megaminx);
    }
    else if(direction=="left")
    {
      moveYellowLeft(copy, megaminx);
    }
  }

  else if(face=="skyblue")
  {
    if(direction=="right")
    {
      moveSkyBlueRight(copy, megaminx);
    }
    else if(direction=="left")
    {
      moveSkyBlueLeft(copy, megaminx);
    }
  }

  else if(face=="green")
  {
    if(direction=="right")
    {
      moveGreenRight(copy, megaminx);
    }

    else if(direction=="left")
    {
      moveGreenLeft(copy, megaminx);
    }
  }
  else if(face=="magenta")
  {
    if(direction=="right")
    {
      moveMagentaRight(copy, megaminx);
    }

    else if(direction=="left")
    {
      moveMagentaLeft(copy, megaminx);
    }
  }

}
int stickerOutOfPlace(string baseMegaminx[12][11], string megaminx[12][11])
{
  int counter=0;
  for(int i=0;i<12;i++)
  {
    for(int j=0;j<11;j++)
    {
      if(baseMegaminx[i][j]!=megaminx[i][j])
      {
        counter++;
      }
    }
  }
//  cout<<"Number of stickers out of place: "<<counter<<endl;
return counter;
}




int GlobalCounter=0;



void psv(const char pool[],string prefix,const int n, const int length)

{

    if (length == 1)

        {

            for (int j = 0; j < n; j++)

           {
               pmtations.push_back(prefix + pool[j]);
            }

        }

    else

        {

            for (int i = 0; i < n; i++)

             psv(pool, prefix + pool[i], n, length - 1);

        }
    GlobalCounter = pmtations.size();
}

void solve(string baseMegaminx[12][11], string megaminx[12][11], int counter)
{

  char pool[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};

  int n = sizeof(pool);

  for (int k = 1; k <= counter; k++)

             {

                 psv(pool, "", n, k);
              }


  string* pList =  new string[GlobalCounter];

  copy(pmtations.begin(), pmtations.end(), pList);


  long long int expansion=0;
  for (int k = 0; k < GlobalCounter; k++)
             {
               string newMinx[12][11];
               expansion++;
               for(int i=0;i<12;i++)
               {
                 for (int j=0;j<11;j++)
                 {
                   newMinx[i][j]=megaminx[i][j];
                 }
               }
                 for(int g=0; g<pList[k].length();g++)
                 {
                   string testFace;
                   string direction;
                   if(pList[k][g] =='A')
                   {
                     testFace="green";
                     direction="left";
                   }

                   else if(pList[k][g] =='B')
                   {
                     testFace="white";
                     direction="left";
                   }


                   else if(pList[k][g] =='C')
                   {
                     testFace="magenta";
                     direction="left";
                   }


                   else if(pList[k][g] =='D')
                   {
                     testFace="blue";
                     direction="left";
                   }


                   else if(pList[k][g] =='E')
                   {
                     testFace="gold";
                     direction="left";
                   }


                   else if(pList[k][g] =='F')
                   {
                     testFace="red";
                     direction="left";
                   }


                   else if(pList[k][g] =='G')
                   {
                     testFace="pink";
                     direction="left";
                   }


                   else if(pList[k][g] =='H')
                   {
                     testFace="lime";
                     direction="left";
                   }


                   else if(pList[k][g] =='I')
                   {
                     testFace="cyan";
                     direction="left";
                   }


                   else if(pList[k][g] =='J')
                   {
                     testFace="orange";
                     direction="left";
                   }


                   else if(pList[k][g] =='K')
                   {
                     testFace="yellow";
                     direction="left";
                   }


                   else if(pList[k][g] =='L')
                   {
                     testFace="skyblue";
                     direction="left";
                   }
                   move(testFace, direction, newMinx);
                 }
                 if(stickerOutOfPlace(baseMegaminx, newMinx)==0)
                 {
                   cout<<"Solved!"<<endl;
                   cout<<"Nodes expanded: "<<expansion<<endl;
                   return;
                 }
              }

  vector<puzzle> frontier;

}




 int main(int argc, char** argv)
{
    srand ( time(NULL) );
    int Min;
    int Max;
    int Number;
    int param = atoi(argv[1]);

    string red ="\033[1;31mR\033[0m";
    string yellow ="\033[1;33mY\033[0m";
    string white ="\033[1;37mW\033[0m";
    string green ="\033[1;32mG\033[0m";
    string cyan ="\033[1;36mC\033[0m";
    string blue="\033[1;34mB\033[0m";
    string magenta="\033[1;35mM\033[0m";
    string lime ="\033[1;92mL\033[0m";
    string pink="\033[1;95mP\033[0m";
    string skyblue="\033[1;96mS\033[0m";
    string orange="\033[1;91mO\033[0m";
    string gold="\033[1;93mD\033[0m";
    string silver="";

    string colors[12]={green, white, magenta, blue, gold, red, pink, lime, cyan, orange, yellow, skyblue};
    string megaminx[12][11];
    string baseMegaminx[12][11];


    for(int i = 0 ; i<12; i++)
    {

      for(int j=0;j<11;j++)
      {
        megaminx[i][j]=colors[i];
        baseMegaminx[i][j]=colors[i];
      }
    }



    string testFace="";
    string direction="";



    for(int i=0;i<param;i++)
    {
      Min = 1;
      Max = 12;
      Number = std::rand() % (Max + 1 - Min) + Min;
      if(Number==1)
      {
        testFace="green";
        direction="right";
      }

      else if(Number==2)
      {
        testFace="white";
        direction="right";
      }


      else if(Number==3)
      {
        testFace="magenta";
        direction="right";
      }


      else if(Number==4)
      {
        testFace="blue";
        direction="right";
      }


      else if(Number==5)
      {
        testFace="gold";
        direction="right";
      }


      else if(Number==6)
      {
        testFace="red";
        direction="right";
      }


      else if(Number==7)
      {
        testFace="pink";
        direction="right";
      }


      else if(Number==8)
      {
        testFace="lime";
        direction="right";
      }


      else if(Number==9)
      {
        testFace="cyan";
        direction="right";
      }


      else if(Number==10)
      {
        testFace="orange";
        direction="right";
      }


      else if(Number==11)
      {
        testFace="yellow";
        direction="right";
      }


      else if(Number==12)
      {
        testFace="skyblue";
        direction="right";
      }



        move(testFace, direction, megaminx);

      }

    //printMegaminx(megaminx);
    cout<<""<<endl;
    int counter =atoi(argv[1]);
    solve(baseMegaminx, megaminx, counter);
    return 0;
}
