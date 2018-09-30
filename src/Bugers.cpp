#include "..\include\Bugers.h"

#include<math.h>

#include<string>

#include<iostream>
#include<cmath>
#include<sstream>

using namespace std ;

Bugers::Bugers(float x_value,float t_value,float upper_baound_xValue,float upper_bound_tValue,float viscosity_coeffient_value)
{
    x_interval=x_value; //Initializing the class property value x_interval
    t_interval=t_value; //Initializing the class property value t_interval
    viscosity_coeffient=viscosity_coeffient_value; //Assigning the value

    /*Calculating the values of i and j*/
    i=(upper_baound_xValue/x_value)+ 1;
    j=(upper_bound_tValue/t_value)+ 1;


}

Bugers::~Bugers()
{
    //this called when the class is Destructed
}

float Bugers::get_t_interval()
{
    return t_interval;
}

float Bugers::get_x_interval()
{
    return x_interval;
}

void Bugers::set_value_of_C()
{
    value_of_c=(t_interval)/(2*x_interval); //Calculating the Value of C
    //value_of_c=0.125f;
}

void Bugers::set_value_of_D()
{
    value_of_d=(value_of_v*t_interval)/(x_interval*x_interval);

}

void Bugers::set_value_of_V()
{
    value_of_v=viscosity_coeffient;
}

void Bugers::process_values_of_U(unsigned int menu_option)
{
    if(menu_option==1)
    {
        for(unsigned int index=0; index <=i; index++ )
            {
                float temp=(abs(sin(x_values.at(index)* 3.141592653589793238463))>1e-7)*sin(x_values.at(index)* 3.141592653589793238463);
                u_values.push_back(temp);

                /*Adding the Initial U values to the Main U Values*/
                string temp_key=getStringValue(index)+ "0";
                u_values_main[temp_key]=temp;

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values.at(index)<<endl;
            }
    }
    else if(menu_option==2)
    {
        for(unsigned int index=1; index <=i; index++ )
            {
                float temp=((1/x_values.at(index)));
                u_values.push_back(temp);

                /*Adding the Initial U values to the Main U Values*/
                string temp_key=getStringValue(index)+ "0";
                u_values_main[temp_key]=temp;

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values.at(index)<<endl;
            }
    }
    else if(menu_option==3)
    {
        for(unsigned int index=0; index <=i; index++ )
            {
                float temp=(abs(cos(x_values.at(index)))>1e-7)*cos(x_values.at(index));
                u_values.push_back(temp);

                /*Adding the Initial U values to the Main U Values*/
                string temp_key=getStringValue(index)+ "0";
                u_values_main[temp_key]=temp;

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values.at(index)<<endl;
            }
    }

    else if(menu_option==4)
    {
        for(unsigned int index=0; index <=i; index++ )
            {
                float temp=(x_values.at(index));
                u_values.push_back(temp);

                /*Adding the Initial U values to the Main U Values*/
                string temp_key=getStringValue(index)+ "0";
                u_values_main[temp_key]=temp;

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values.at(index)<<endl;
            }
    }
    else
    {
        cout<<"The first Condition will be Used";
    }






}

void Bugers::compute_the_value_set_x()
{       /* Temporary  value */
    float temp_value=0;
    x_values.push_back(temp_value);
    for(unsigned int index=0; index < i; index++ )
        {

            temp_value=temp_value + x_interval;
            x_values.push_back(temp_value);
        }

        /*It will Print the Computed Values of set X*/
cout<<endl; /*Print New line*/
for(unsigned int index=0; index<x_values.size(); index++)
    {
        cout<<"\t"<< "The Values of  X:: " << index << " = " << x_values.at(index)<<endl;
    }

}

void Bugers::compute_the_value_set_t()
{
    /* Temporary  value */
    float temp_value=0;
    t_values.push_back(temp_value);
    for(unsigned int index=0; index < j; index++ )
        {
            temp_value=temp_value + t_interval;
            t_values.push_back(temp_value);
        }

        /*It will Print the Computed Values of set T*/
        cout<<endl; /*Print New line*/
for(unsigned int index=0; index<t_values.size(); index++)
    {
        cout<<"\t"<< "The Values of  T:: " << index << " = " << t_values.at(index)<<endl;
    }
}

void Bugers::buger_equation_calculation()
{
    float current_value;

        /*outside Loop is J */
        for(unsigned int outside_index=0; outside_index < j ; outside_index++)
        {
            cout<<"For the Value of :: J = "<<outside_index <<endl;
             /* The Inside Loop is I */
             for(unsigned int inside_index=1; inside_index < i ; inside_index++)
             {

                cout<<"\t"<<"Computing the Value of U(i,j) for :: i = "<< inside_index<<"\t";
                    /*Some simple calculation  Values*/

                        /*Total of i + j*/
                        int temp_minus=inside_index-1;
                        int temp_add=inside_index +1;

                        string difference_i_j=getStringValue(temp_minus) + getStringValue(outside_index) ;

                        /*subtraction of i- j*/
                        string total_i_j=getStringValue(temp_add) + getStringValue(outside_index);

                        /*Combining together of i and j */

                        string combine_i_j=getStringValue(inside_index) + getStringValue(outside_index);

current_value=((1-(2 * value_of_d)) * (u_values_main[combine_i_j]))+ (((value_of_d )+ (value_of_c * u_values_main[combine_i_j]))*u_values_main[difference_i_j]) + ((value_of_d) - (value_of_c * u_values_main[combine_i_j]))* u_values_main[total_i_j];

//current_value=(((value_of_d )+ (value_of_c * u_values_main[combine_i_j]))*u_values_main[difference_i_j]);
                /*Adding the current value to the u_value_man map*/
                string current_key=getStringValue(inside_index) + getStringValue(outside_index + 1);

                u_values_main[current_key]=current_value;


                /*Printing the Current computed Value*/

                cout<<"\t" <<"U("<<current_key<<")"<<" = " <<current_value <<endl;
             }
cout<<endl;

        }
}


string Bugers::getStringValue(int integer_value)
{
    stringstream getintValue;
    getintValue<<integer_value;

    return getintValue.str();
}
