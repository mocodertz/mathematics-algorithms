#include "Fisher_Equation.h"

#include<math.h>

#include<string>

#include<iostream>
#include<cmath>
#include<sstream>

Fisher_Equation::Fisher_Equation(float x_value_fisher,float t_value_fisher,float upper_baound_xValue_fisher,float upper_bound_tValue_fisher)
{
    x_interval_fisher=x_value_fisher; //Initializing the class property value x_interval
    t_interval_fisher=t_value_fisher; //Initializing the class property value t_interval
    /*Calculating the values of i and j*/
    i_fisher=(upper_baound_xValue_fisher/x_value_fisher)+ 1;
    j_fisher=(upper_bound_tValue_fisher/t_value_fisher) + 1;


    upper_bound_x=(upper_baound_xValue_fisher/x_value_fisher);

}

Fisher_Equation::~Fisher_Equation()
{

}

float Fisher_Equation::get_t_interval_fisher()
{
    return t_interval_fisher;
}

float Fisher_Equation::get_x_interval_fisher()
{
    return x_interval_fisher;
}

void Fisher_Equation::set_value_of_lamda()
{
    lamda_value_fisher=(t_interval_fisher)/(x_interval_fisher*x_interval_fisher); //Calculating the Value of lambda


}

void Fisher_Equation::process_values_of_U_fisher(unsigned int menu_option_fisher)
{
    if(menu_option_fisher==1)
    {
        for(unsigned int index=0; index <i_fisher; index++ )
            {
                float temp=(abs(sin(x_values_fisher.at(index)* 3.141592653589793238463))>1e-7)*sin(x_values_fisher.at(index)* 3.141592653589793238463);
                u_values_fisher.push_back(temp);

                /*Adding the Initial U values to the Main U Values*/
                string temp_key=getStringValue_fisher(index)+ "0";
                u_values_main_fisher[temp_key]=temp;

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values_fisher.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values_fisher.at(index)<<endl;
            }
    }
    else if(menu_option_fisher==2)
    {
        for(unsigned int index=0; index <i_fisher; index++ )
            {
                float temp=(1/(2-x_values_fisher.at(index)));
                u_values_fisher.push_back(temp);

                /*Adding the Initial U values to the Main U Values*/
                string temp_key=getStringValue_fisher(index)+ "0";
                u_values_main_fisher[temp_key]=temp;

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values_fisher.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values_fisher.at(index)<<endl;
            }
    }
    else if(menu_option_fisher==3)
    {
        for(unsigned int index=0; index <i_fisher; index++ )
            {
                float temp=(abs(cos(x_values_fisher.at(index)))>1e-7)*cos(x_values_fisher.at(index));
                u_values_fisher.push_back(temp);

                /*Adding the Initial U values to the Main U Values*/
                string temp_key=getStringValue_fisher(index)+ "0";
                u_values_main_fisher[temp_key]=temp;

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values_fisher.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values_fisher.at(index)<<endl;
            }
    }

    else if(menu_option_fisher==4)
    {
        for(unsigned int index=0; index <i_fisher; index++ )
            {

                if(index==upper_bound_x || index==0)

                    {
                        u_values_fisher.push_back(0);

                    }
                else
                    {
                        float temp=(x_values_fisher.at(index));
                        u_values_fisher.push_back(temp);

                        /*Adding the Initial U values to the Main U Values*/
                        string temp_key=getStringValue_fisher(index)+ "0";
                        u_values_main_fisher[temp_key]=temp;

                    }

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values_fisher.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values_fisher.at(index)<<endl;
            }
    }
    else
    {
        cout<<"The first Condition will be Used";
    }
}

void Fisher_Equation::compute_the_value_set_x_fisher()
{       /* Temporary  value */
    float temp_value=0;
    x_values_fisher.push_back(temp_value);
    for(unsigned int index=1; index < i_fisher; index++ )
        {

            temp_value=temp_value + x_interval_fisher;
            x_values_fisher.push_back(temp_value);
        }

        /*It will Print the Computed Values of set X*/
cout<<endl; /*Print New line*/
for(unsigned int index=0; index<x_values_fisher.size(); index++)
    {
        cout<<"\t"<< "The Values of  X:: " << index << " = " << x_values_fisher.at(index)<<endl;
    }

}

void Fisher_Equation::compute_the_value_set_t_fisher() /*Computing the Value of set T*/
{
    /* Temporary  value */
    float temp_value=0;
    t_values_fisher.push_back(temp_value);
    for(unsigned int index=1; index < j_fisher; index++ )
        {
            temp_value=temp_value + t_interval_fisher;
            t_values_fisher.push_back(temp_value);
        }

        /*It will Print the Computed Values of set T*/
        cout<<endl; /*Print New line*/
for(unsigned int index=0; index<t_values_fisher.size(); index++)
    {
        cout<<"\t"<< "The Values of  T:: " << index << " = " << t_values_fisher.at(index)<<endl;
    }
}

void Fisher_Equation::fisher_equation_calculation()/*FIsher Equation Calculation*/
{
    float current_value;

        /*outside Loop is J */
        for(unsigned int outside_index=0; outside_index < j_fisher ; outside_index++)
        {
            cout<<"For the Value of :: J = "<<outside_index <<endl;
             /* The Inside Loop is I */
             for(unsigned int inside_index=1; inside_index <i_fisher ; inside_index++)
             {

                cout<<"\t"<<"Computing the Value of U(i,j) for :: i = "<< inside_index<<"\t";
                    /*Some simple calculation  Values*/

                        /*Total of i + j*/
                        int temp_minus=inside_index-1;
                        int temp_add=inside_index + 1;

                        string difference_i_j=getStringValue_fisher(temp_minus) + getStringValue_fisher(outside_index) ;

                        /*subtraction of i- j*/
                        string total_i_j=getStringValue_fisher(temp_add) + getStringValue_fisher(outside_index);

                        /*Combining together of i and j */

                        string combine_i_j=getStringValue_fisher(inside_index) + getStringValue_fisher(outside_index);

                        /*Getting the Current key Value*/
                        string current_key=getStringValue_fisher(inside_index) + getStringValue_fisher(outside_index + 1);

                    /*Implementing Boundary for U- values*/

                        if(inside_index==upper_bound_x || inside_index==0)
                        {
                            u_values_main_fisher[current_key]=0;
                            current_value=0;
                        }else
                        {
                            current_value=((1-(2*lamda_value_fisher)+ t_interval_fisher)* u_values_main_fisher[combine_i_j] )- ((t_interval_fisher) *(u_values_main_fisher[combine_i_j]*u_values_main_fisher[combine_i_j])) + (lamda_value_fisher*(u_values_main_fisher[total_i_j] + u_values_main_fisher[difference_i_j] ));
                            /*Adding the current value to the u_value_man map*/

                            u_values_main_fisher[current_key]=current_value;
                        }
                    /*Implementing Boundary for U- values*/

                /*Printing the Current computed Value*/

                cout<<"\t" <<"U("<<current_key<<")"<<" = " <<current_value <<endl;
             }
cout<<endl;

        }
}

string Fisher_Equation::getStringValue_fisher(int integer_value) /*Converting Int to String*/
{
    stringstream getintValue;
    getintValue<<integer_value;

    return getintValue.str();
}

