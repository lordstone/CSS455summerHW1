#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <random>
#include <math.h>
#define DRAWING_SCALE 100
#define RUNNING_TIME 100000

//I finished the extra credit part for multiple distribution.
//NOTE: This code requires c++11 for distribution generation such as normal distribution
//By Chengxi (Chen) Shi.

using namespace std;

void genRandom(int N = 1000);

void printStars(int n)
{
    for(int i=0; i < n; i++)
    {
        cout << "*";
    }
    cout << endl;
}// printStars()

void genHeading(int k)
{
    if(k==0)
        cout<<"0.0-0.1:";
    else if(k==9)
        cout<<"0.9-1.0:";
    else
        cout<<k/10.0<<"-"<<(k+1)/10.0<<":";
}

void genRandom(int N)
{
    int intBin [10];
    for(int i =0; i<10; i++)
        intBin[i]=0;
    double r;
    for(int j = 0; j<N; j++)
    {
        r = rand()/32767.0;//cout<<"jiji"<<r<<endl;
        intBin[(int)(floor(r*10))]++;
    }
    for(int k = 0; k<10; k++) //cout<<intBin[k]<<endl;
    {
        genHeading(k);
        printStars((int)(floor(DRAWING_SCALE*intBin[k]/N) ));
    }
}//end genrandom

void genMultiple(int N)
{
    int intBin[10];
    for(int i =0; i<10; i++)
        intBin[i]=0;
    double r1,r2,r;
    for(int j = 0; j<N; j++)
    {
        r1 = rand()/32767.0;
        r2 = rand()/32767.0;
        r = r1*r2;
        //r = (r1+r2)/2;
        //cout<<r<<endl;
        intBin[(int)(floor(r*10))]++;
    }
    for(int k = 0; k<10; k++) //cout<<intBin[k]<<endl;
    {
        genHeading(k);
        printStars((int)(floor(DRAWING_SCALE*intBin[k]/N) ));
        //cout<<intBin[k]<<endl;
    }
}

void genAvg(int N)
{
    int intBin[10];
    for(int i =0; i<10; i++)
        intBin[i]=0;
    double r1,r2,r;
    for(int j = 0; j<N; j++)
    {
        r1 = rand()/32767.0;
        r2 = rand()/32767.0;
        r = (r1+r2)/2;
        //r = (r1+r2)/2;
        //cout<<r<<endl;
        intBin[(int)(floor(r*10))]++;
    }
    for(int k = 0; k<10; k++) //cout<<intBin[k]<<endl;
    {
        genHeading(k);
        printStars((int)(floor(DRAWING_SCALE*intBin[k]/N) ));
        //cout<<intBin[k]<<endl;
    }
}

void genNormalDist(int N)
{
    default_random_engine generator;
    normal_distribution<double> distribution(0.5,0.2);
    int intBin[10];
    for(int i =0; i<10; i++)
        intBin[i]=0;
    double r;
    for(int j = 0; j<N; j++)
    {
        r = distribution(generator);
        if(r<1.0 && r>=0)//program will cut out the points out of graphing range
            intBin[(int)(floor(r*10))]++;
    }
    for(int k = 0; k<10; k++)
    {
        genHeading(k);
        printStars((int)(floor(DRAWING_SCALE*intBin[k]/N) ));
    }
}

void genPoissonDist(int N)
{
    default_random_engine generator;
    poisson_distribution<int> distribution(1);
    int intBin[10];
    for(int i =0; i<10; i++)
        intBin[i]=0;
    double r;
    for(int j = 0; j<N; j++)
    {
        r = distribution(generator);
        if(r<10.0 && r>=0)//program will cut out the points out of graphing range
            intBin[(int)(floor(r))]++;
    }
    for(int k = 0; k<10; k++)
    {
        genHeading(k);
        printStars((int)(floor(DRAWING_SCALE*intBin[k]/N) ));
    }
}

void genPareto(int N, int a)
{
    int intBin[10];
    for(int i =0; i<10; i++)
        intBin[i]=0;
    double temp,  rmax=1;

    for(int j = 0; j<N; j++)
    {
        temp = (rand()+1.0)/(RAND_MAX*1.0);
        temp = 1/(pow(temp,1.0/a)) ;
        if (rmax<temp)
            rmax = temp;
    }
    //cout <<rmax <<endl;
    for(int l = 0; l<N; l++)
    {
        temp = (rand()+1.0)/(RAND_MAX*1.0);
        temp = 1/(pow(temp,1.0/a))/rmax ;
        //cout<<temp<<endl;
        if(temp>=0.0 && temp<=1.0)
        {
            intBin[(int)(floor(temp * 10))]++;
        }
    }
   // for(int m = 0; m<10; m++)cout<<intBin[m]<<endl;
    for(int k = 0; k<10; k++) //cout<<intBin[k]<<endl;
    {
        genHeading(k);
        printStars((int)(floor(DRAWING_SCALE*intBin[k]/N) ));
        //cout<<intBin[k]<<endl;
    }
}

int main()
{
    cout<<"Generate Random Number Bins:"<<endl;
    genRandom(RUNNING_TIME);
    cout <<"Generate (r=r1*r2):"<<endl;
    genMultiple(RUNNING_TIME);
    cout <<"Generate Avg of 2 random number(triangle, r=(r1+r2)/2:"<<endl;
    genAvg(RUNNING_TIME);
    cout <<"Generate Normal Distribution(N(0.5,0.2):"<<endl;
    genNormalDist(RUNNING_TIME);
    cout <<"Generate Poisson Distribution(P(1),Rescaled to 1-10):"<<endl;
    genPoissonDist(RUNNING_TIME);
    cout <<"(Extra Credit)Generate Pareto(1):"<<endl;
    genPareto(RUNNING_TIME,3);
    return 0;
}// main()
