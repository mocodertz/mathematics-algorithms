#include "Gardner_Equation.h"

#include<math.h>

#include<string>

#include<iostream>
#include<cmath>
#include<sstream>

Gardner_Equation::Gardner_Equation(float x_value_gardner,float t_value_gardner,float upper_baound_xValue_gardner,float upper_bound_tValue_gardner)
{
    x_interval_gardner=x_value_gardner; //Initializing the class property value x_interval
    t_interval_gardner=t_value_gardner; //Initializing the class property value t_interval
    /*Calculating the values of i and j*/
    i_gardner=(upper_baound_xValue_gardner/x_value_gardner)+ 1;
    j_gardner=(upper_bound_tValue_gardner/t_value_gardner) + 1;


    upper_bound_x=(upper_baound_xValue_gardner/x_value_gardner);

}

Gardner_Equation::~Gardner_Equation()
{

}

float Gardner_Equation::get_t_interval_gardner()
{
    return t_interval_gardner;
}

float Gardner_Equation::get_x_interval_gardner()
{
    return x_interval_gardner;
}


void Gardner_Equation::process_values_of_U_gardner(unsigned int menu_option_gardner)
{
    if(menu_option_gardner==1)
    {
        for(unsigned int index=0; index <i_gardner; index++ )
            {
                float temp=(abs(sin(x_values_gardner.at(index)* 3.141592653589793238463))>1e-7)*sin(x_values_gardner.at(index)* 3.141592653589793238463);
                u_values_gardner.push_back(temp);

                /*Adding the Initial U values to the Main U Values*/
                string temp_key=getStringValue_gardner(index)+ "0";
                u_values_main_gardner[temp_key]=temp;

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values_gardner.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values_gardner.at(index)<<endl;
            }
    }
    else if(menu_option_gardner==2)
    {
        for(unsigned int index=0; index <i_gardner; index++ )
            {
                float temp=(1/(2-x_values_gardner.at(index)));
                u_values_gardner.push_back(temp);

                /*Adding the Initial U values to the Main U Values*/
                string temp_key=getStringValue_gardner(index)+ "0";
                u_values_main_gardner[temp_key]=temp;

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values_gardner.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values_gardner.at(index)<<endl;
            }
    }
    else if(menu_option_gardner==3)
    {
        for(unsigned int index=0; index <i_gardner; index++ )
            {
                float temp=(abs(cos(x_values_gardner.at(index)))>1e-7)*cos(x_values_gardner.at(index));
                u_values_gardner.push_back(temp);

                /*Adding the Initial U values to the Main U Values*/
                string temp_key=getStringValue_gardner(index)+ "0";
                u_values_main_gardner[temp_key]=temp;

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values_gardner.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values_gardner.at(index)<<endl;
            }
    }

    else if(menu_option_gardner==4)
    {
        for(unsigned int index=0; index <i_gardner; index++ )
            {

                if(index==upper_bound_x || index==0)

                    {
                        u_values_gardner.push_back(0);

                    }
                else
                    {
                        float temp=(x_values_gardner.at(index));
                        u_values_gardner.push_back(temp);

                        /*Adding the Initial U values to the Main U Values*/
                        string temp_key=getStringValue_gardner(index)+ "0";
                        u_values_main_gardner[temp_key]=temp;

                    }

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values_gardner.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values_gardner.at(index)<<endl;
            }
    }
    else
    {
        cout<<"The first Condition will be Used";
    }
}

void Gardner_Equation::compute_the_value_set_x_gardner()
{       /* Temporary  value */
    float temp_value=0;
    x_values_gardner.push_back(temp_value);
    for(unsigned int index=1; index < i_gardner; index++ )
        {

            temp_value=temp_value + x_interval_gardner;
            x_values_gardner.push_back(temp_value);
        }

        /*It will Print the Computed Values of set X*/
cout<<endl; /*Print New line*/
for(unsigned int index=0; index<x_values_gardner.size(); index++)
    {
        cout<<"\t"<< "The Values of  X:: " << index << " = " << x_values_gardner.at(index)<<endl;
    }

}

void Gardner_Equation::compute_the_value_set_t_gardner() /*Computing the Value of set T*/
{
    /* Temporary  value */
    float temp_value=0;
    t_values_gardner.push_back(temp_value);
    for(unsigned int index=1; index < j_gardner; index++ )
        {
            temp_value=temp_value + t_interval_gardner;
            t_values_gardner.push_back(temp_value);
        }

        /*It will Print the Computed Values of set T*/
        cout<<endl; /*Print New line*/
for(unsigned int index=0; index<t_values_gardner.size(); index++)
    {
        cout<<"\t"<< "The Values of  T:: " << index << " = " << t_values_gardner.at(index)<<endl;
    }
}

void Gardner_Equation::gardner_equation_calculation()/*FIsher Equation Calculation*/
{
    float current_value;

        /*outside Loop is J */
        for(unsigned int outside_index=0; outside_index < j_gardner; outside_index++)
        {
            cout<<"For the Value of :: J = "<<outside_index <<endl;
             /* The Inside Loop is I */
             for(unsigned int inside_index=1; inside_index <i_gardner ; inside_index++)
             {

                cout<<"\t"<<"Computing the Value of U(i,j) for :: i = "<< inside_index<<"\t";
                    /*Some simple calculation  Values*/

                        /*Total of i + j*/
                        int temp_minus=inside_index-1;
                        int temp_add=inside_index + 1;

                        string difference_i_j=getStringValue_gardner(temp_minus) + getStringValue_gardner(outside_index) ;

                        /*subtraction of i- j*/
                        string total_i_j=getStringValue_gardner(temp_add) + getStringValue_gardner(outside_index);

                        /*Combining together of i and j */

                        string combine_i_j=getStringValue_gardner(inside_index) + getStringValue_gardner(outside_index);

                        /*Getting the Current key Value*/
                        string current_key=getStringValue_gardner(inside_index) + getStringValue_gardner(outside_index + 1);

                    /*Implementing Boundary for U- values*/

                        if(inside_index==upper_bound_x || inside_index==0)
                        {
                            u_values_main_gardner[current_key]=0;
                            current_value=0;
                        }else
                        {
                           current_value=(u_values_main_gardner[combine_i_j]) + (((3*t_interval_gardner)/(x_interval_gardner)*(u_values_main_gardner[combine_i_j] + (u_values_main_gardner[combine_i_j] * u_values_main_gardner[combine_i_j]))*(u_values_main_gardner[total_i_j] - u_values_main_gardner[difference_i_j]))) - (((3*t_interval_gardner)/(x_interval_gardner*x_interval_gardner*x_interval_gardner))*((u_values_main_gardner[difference_i_j]) - (2 *u_values_main_gardner[combine_i_j] ) + u_values_main_gardner[total_i_j]));
                            /*Adding the current value to the u_value_man map*/

                            u_values_main_gardner[current_key]=current_value;
                        }
                    /*Implementing Boundary for U- values*/

                /*Printing the Current computed Value*/

                cout<<"\t" <<"U("<<current_key<<")"<<" = " <<current_value <<endl;
             }
cout<<endl;

        }
}

string Gardner_Equation::getStringValue_gardner(int integer_value) /*Converting Int to String*/
{
    stringstream getintValue;
    getintValue<<integer_value;

    return getintValue.str();
}

