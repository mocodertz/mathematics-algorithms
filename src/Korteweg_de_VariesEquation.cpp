#include "Korteweg_de_VariesEquation.h"

#include<math.h>

#include<string>

#include<iostream>
#include<cmath>
#include<sstream>

using namespace std;

Korteweg_de_VariesEquation::Korteweg_de_VariesEquation(float x_value_korteweg,float t_value_korteweg,float upper_baound_xValue_korteweg,float upper_bound_tValue_korteweg)
{
     x_interval_korteweg=x_value_korteweg; //Initializing the class property value x_interval
    t_interval_korteweg=t_value_korteweg; //Initializing the class property value t_interval
    /*Calculating the values of i and j*/
    i_korteweg=(upper_baound_xValue_korteweg/x_value_korteweg)+ 1;
    j_korteweg=(upper_bound_tValue_korteweg/t_value_korteweg) + 1;


    upper_bound_x=(upper_baound_xValue_korteweg/x_value_korteweg);

}

Korteweg_de_VariesEquation::~Korteweg_de_VariesEquation()
{

}

float Korteweg_de_VariesEquation::get_t_interval_korteweg()
{
    return t_interval_korteweg;
}

float Korteweg_de_VariesEquation::get_x_interval_korteweg()
{
    return x_interval_korteweg;
}


void Korteweg_de_VariesEquation::process_values_of_U_korteweg(unsigned int menu_option_korteweg)
{
    if(menu_option_korteweg==1)
    {
        for(unsigned int index=0; index <i_korteweg; index++ )
            {
                float temp=(abs(sin(x_values_korteweg.at(index)* 3.141592653589793238463))>1e-7)*sin(x_values_korteweg.at(index)* 3.141592653589793238463);
                u_values_korteweg.push_back(temp);

                /*Adding the Initial U values to the Main U Values*/
                string temp_key=getStringValue_korteweg(index)+ "0";
                u_values_main_korteweg[temp_key]=temp;

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values_korteweg.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values_korteweg.at(index)<<endl;
            }
    }
    else if(menu_option_korteweg==2)
    {
        for(unsigned int index=0; index <i_korteweg; index++ )
            {
                float temp=(1/(2-x_values_korteweg.at(index)));
                u_values_korteweg.push_back(temp);

                /*Adding the Initial U values to the Main U Values*/
                string temp_key=getStringValue_korteweg(index)+ "0";
                u_values_main_korteweg[temp_key]=temp;

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values_korteweg.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values_korteweg.at(index)<<endl;
            }
    }
    else if(menu_option_korteweg==3)
    {
        for(unsigned int index=0; index <i_korteweg; index++ )
            {
                float temp=(abs(cos(x_values_korteweg.at(index)))>1e-7)*cos(x_values_korteweg.at(index));
                u_values_korteweg.push_back(temp);

                /*Adding the Initial U values to the Main U Values*/
                string temp_key=getStringValue_korteweg(index)+ "0";
                u_values_main_korteweg[temp_key]=temp;

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values_korteweg.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values_korteweg.at(index)<<endl;
            }
    }

    else if(menu_option_korteweg==4)
    {
        for(unsigned int index=0; index <i_korteweg; index++ )
            {

                if(index==upper_bound_x || index==0)

                    {
                        u_values_korteweg.push_back(0);

                    }
                else
                    {
                        float temp=(x_values_korteweg.at(index));
                        u_values_korteweg.push_back(temp);

                        /*Adding the Initial U values to the Main U Values*/
                        string temp_key=getStringValue_korteweg(index)+ "0";
                        u_values_main_korteweg[temp_key]=temp;

                    }

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values_korteweg.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values_korteweg.at(index)<<endl;
            }
    }
    else
    {
        cout<<"The first Condition will be Used";
    }
}

void Korteweg_de_VariesEquation::compute_the_value_set_x_korteweg()
{       /* Temporary  value */
    float temp_value=0;
    x_values_korteweg.push_back(temp_value);
    for(unsigned int index=1; index < i_korteweg; index++ )
        {

            temp_value=temp_value + x_interval_korteweg;
            x_values_korteweg.push_back(temp_value);
        }

        /*It will Print the Computed Values of set X*/
cout<<endl; /*Print New line*/
for(unsigned int index=0; index<x_values_korteweg.size(); index++)
    {
        cout<<"\t"<< "The Values of  X:: " << index << " = " << x_values_korteweg.at(index)<<endl;
    }

}

void Korteweg_de_VariesEquation::compute_the_value_set_t_korteweg() /*Computing the Value of set T*/
{
    /* Temporary  value */
    float temp_value=0;
    t_values_korteweg.push_back(temp_value);
    for(unsigned int index=1; index < j_korteweg; index++ )
        {
            temp_value=temp_value + t_interval_korteweg;
            t_values_korteweg.push_back(temp_value);
        }

        /*It will Print the Computed Values of set T*/
        cout<<endl; /*Print New line*/
for(unsigned int index=0; index<t_values_korteweg.size(); index++)
    {
        cout<<"\t"<< "The Values of  T:: " << index << " = " << t_values_korteweg.at(index)<<endl;
    }
}

void Korteweg_de_VariesEquation::korteweg_equation_calculation()/*korteweg Equation Calculation*/
{
    float current_value;

        /*outside Loop is J */
        for(unsigned int outside_index=0; outside_index < j_korteweg ; outside_index++)
        {
            cout<<"For the Value of :: J = "<<outside_index <<endl;
             /* The Inside Loop is I */
             for(unsigned int inside_index=1; inside_index <i_korteweg ; inside_index++)
             {

                cout<<"\t"<<"Computing the Value of U(i,j) for :: i = "<< inside_index<<"\t";
                    /*Some simple calculation  Values*/

                        /*Total of i + j*/
                        int temp_minus=inside_index - 1;
                        int temp_add=inside_index + 1;

                        string difference_i_j=getStringValue_korteweg(temp_minus) + getStringValue_korteweg(outside_index) ;

                        /*subtraction of i- j*/
                        string total_i_j=getStringValue_korteweg(temp_add) + getStringValue_korteweg(outside_index);

                        /*Combining together of i and j */

                        string combine_i_j=getStringValue_korteweg(inside_index) + getStringValue_korteweg(outside_index);

                        /*Getting the Current key Value*/
                        string current_key=getStringValue_korteweg(inside_index) + getStringValue_korteweg(outside_index + 1);

                    /*Implementing Boundary for U- values*/

                        if(inside_index==upper_bound_x || inside_index==0)
                        {
                            u_values_main_korteweg[current_key]=0;
                            current_value=0;
                        }else
                        {
                           current_value=(u_values_main_korteweg[combine_i_j]) + ((t_interval_korteweg/(2*x_interval_korteweg))*(u_values_main_korteweg[combine_i_j])*(u_values_main_korteweg[total_i_j]- u_values_main_korteweg[difference_i_j])) + (((3* t_interval_korteweg)/(x_interval_korteweg * x_interval_korteweg * x_interval_korteweg))* ((-1 * u_values_main_korteweg[total_i_j])+ (2 * u_values_main_korteweg[combine_i_j]) - (u_values_main_korteweg[difference_i_j])));
                            /*Adding the current value to the u_value_man map*/

                            u_values_main_korteweg[current_key]=current_value;
                        }
                    /*Implementing Boundary for U- values*/

                /*Printing the Current computed Value*/

                cout<<"\t" <<"U("<<current_key<<")"<<" = " <<current_value <<endl;
             }
cout<<endl;

        }
}

string Korteweg_de_VariesEquation::getStringValue_korteweg(int integer_value) /*Converting Int to String*/
{
    stringstream getintValue;
    getintValue<<integer_value;

    return getintValue.str();
}

