#include "SineGordon_Equation.h"

#include "SineGordon_Equation.h"

#include<math.h>

#include<string>

#include<iostream>
#include<cmath>
#include<sstream>

SineGordon_Equation::SineGordon_Equation(float x_value_gordon,float t_value_gordon,float upper_baound_xValue_gordon,float upper_bound_tValue_gordon )
{
    x_interval_gordon=x_value_gordon; //Initializing the class property value x_interval
    t_interval_gordon=t_value_gordon; //Initializing the class property value t_interval
    /*Calculating the values of i and j*/
    i_gordon=(upper_baound_xValue_gordon/x_value_gordon)+ 1;
    j_gordon=(upper_bound_tValue_gordon/t_value_gordon) + 1;


    upper_bound_x=(upper_baound_xValue_gordon/x_value_gordon);

}

SineGordon_Equation::~SineGordon_Equation()
{

}

float SineGordon_Equation::get_t_interval_gordon()
{
    return t_interval_gordon;
}

float SineGordon_Equation::get_x_interval_gordon()
{
    return x_interval_gordon;
}

void SineGordon_Equation::set_value_of_lamda()
{
    lamda_value_gordon=(t_interval_gordon)/(x_interval_gordon); //Calculating the Value of lambda
}

void SineGordon_Equation::process_values_of_U_gordon(unsigned int menu_option_gordon)
{
    if(menu_option_gordon==1)
    {
        for(unsigned int index=0; index <i_gordon; index++ )
            {
                float temp=(abs(sin(x_values_gordon.at(index)* 3.141592653589793238463))>1e-7)*sin(x_values_gordon.at(index)* 3.141592653589793238463);
                u_values_gordon.push_back(temp);

                /*Adding the Initial U values to the Main U Values*/
                string temp_key=getStringValue_gordon(index)+ "0";
                u_values_main_gordon[temp_key]=temp;

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values_gordon.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values_gordon.at(index)<<endl;
            }
    }
    else if(menu_option_gordon==2)
    {
        for(unsigned int index=0; index <i_gordon; index++ )
            {
                float temp=(1/(2-x_values_gordon.at(index)));
                u_values_gordon.push_back(temp);

                /*Adding the Initial U values to the Main U Values*/
                string temp_key=getStringValue_gordon(index)+ "0";
                u_values_main_gordon[temp_key]=temp;

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values_gordon.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values_gordon.at(index)<<endl;
            }
    }
    else if(menu_option_gordon==3)
    {
        for(unsigned int index=0; index <i_gordon; index++ )
            {
                float temp=(abs(cos(x_values_gordon.at(index)))>1e-7)*cos(x_values_gordon.at(index));
                u_values_gordon.push_back(temp);

                /*Adding the Initial U values to the Main U Values*/
                string temp_key=getStringValue_gordon(index)+ "0";
                u_values_main_gordon[temp_key]=temp;

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values_gordon.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values_gordon.at(index)<<endl;
            }
    }

    else if(menu_option_gordon==4)
    {
        for(unsigned int index=0; index <i_gordon; index++ )
            {

                if(index==upper_bound_x || index==0)

                    {
                        u_values_gordon.push_back(0);

                    }
                else
                    {
                        float temp=(x_values_gordon.at(index));
                        u_values_gordon.push_back(temp);

                        /*Adding the Initial U values to the Main U Values*/
                        string temp_key=getStringValue_gordon(index)+ "0";
                        u_values_main_gordon[temp_key]=temp;

                    }

            }
                /*Printing the Values of U Values*/
        for(unsigned int index=0; index<u_values_gordon.size(); index++)
            {
                cout<<"\t"<< "The Values of  U"<<index<<"0:: "<< " = " << u_values_gordon.at(index)<<endl;
            }
    }
    else
    {
        cout<<"The first Condition will be Used";
    }
}

void SineGordon_Equation::compute_the_value_set_x_gordon()
{       /* Temporary  value */
    float temp_value=0;
    x_values_gordon.push_back(temp_value);
    for(unsigned int index=1; index < i_gordon; index++ )
        {

            temp_value=temp_value + x_interval_gordon;
            x_values_gordon.push_back(temp_value);
        }

        /*It will Print the Computed Values of set X*/
cout<<endl; /*Print New line*/
for(unsigned int index=0; index<x_values_gordon.size(); index++)
    {
        cout<<"\t"<< "The Values of  X:: " << index << " = " << x_values_gordon.at(index)<<endl;
    }

}

void SineGordon_Equation::compute_the_value_set_t_gordon() /*Computing the Value of set T*/
{
    /* Temporary  value */
    float temp_value=0;
    t_values_gordon.push_back(temp_value);
    for(unsigned int index=1; index < j_gordon; index++ )
        {
            temp_value=temp_value + t_interval_gordon;
            t_values_gordon.push_back(temp_value);
        }

        /*It will Print the Computed Values of set T*/
        cout<<endl; /*Print New line*/
for(unsigned int index=0; index<t_values_gordon.size(); index++)
    {
        cout<<"\t"<< "The Values of  T:: " << index << " = " << t_values_gordon.at(index)<<endl;
    }
}

void SineGordon_Equation::gordon_equation_calculation()/*FIsher Equation Calculation*/
{
    float current_value;

        /*outside Loop is J */
        for(unsigned int outside_index=0; outside_index < j_gordon ; outside_index++)
        {

           if(outside_index==0)/*STart of the main If Condition*/
           {
                    cout<<"For the Value of :: J = "<<outside_index <<endl;
             /* The Inside Loop is I */
             for(unsigned int inside_index=1; inside_index <i_gordon ; inside_index++)
             {

                cout<<"\t"<<"Computing the Value of U(i,j) for :: i = "<< inside_index<<"\t";
                    /*Some simple calculation  Values*/

                        /*Total of i + j*/
                        int temp_minus=inside_index-1;
                        int temp_add=inside_index + 1;
                        int temp_j_difference=outside_index-1;
                        string difference_i_j=getStringValue_gordon(temp_minus) + getStringValue_gordon(outside_index) ;

                        /*subtraction of i- j*/
                        string total_i_j=getStringValue_gordon(temp_add) + getStringValue_gordon(outside_index);

                        /*Combining together of i and j */

                        string combine_i_j=getStringValue_gordon(inside_index) + getStringValue_gordon(outside_index);

                        /*j difference*/

                        string j_difference=getStringValue_gordon(inside_index) + getStringValue_gordon(temp_j_difference);
                        /*Getting the Current key Value*/
                        string current_key=getStringValue_gordon(inside_index) + getStringValue_gordon(outside_index + 1);

                    /*Implementing Boundary for U- values*/

                        if(inside_index==upper_bound_x || inside_index==0)
                        {
                            u_values_main_gordon[current_key]=0;
                            current_value=0;
                        }else
                        {

                            /*Adding the current value to the u_value_man map*/
                            current_value=(2*(1-(lamda_value_gordon*lamda_value_gordon))*u_values_main_gordon[combine_i_j]) + ((lamda_value_gordon*lamda_value_gordon)*u_values_main_gordon[difference_i_j]) + ((lamda_value_gordon*lamda_value_gordon)*u_values_main_gordon[total_i_j]) - (u_values_main_gordon[combine_i_j]-(t_interval_gordon * x_values_gordon.at(inside_index))) - ((t_interval_gordon * t_interval_gordon)*((abs(sin(u_values_main_gordon[combine_i_j]))>1e-7)*sin(u_values_main_gordon[combine_i_j])));
                            u_values_main_gordon[current_key]=current_value;
                        }
                    /*Implementing Boundary for U- values*/

                /*Printing the Current computed Value*/

                cout<<"\t" <<"U("<<current_key<<")"<<" = " <<current_value <<endl;
             }
           }
           else
            {
                cout<<"For the Value of :: J = "<<outside_index <<endl;
             /* The Inside Loop is I */
             for(unsigned int inside_index=1; inside_index <i_gordon ; inside_index++)
             {

                cout<<"\t"<<"Computing the Value of U(i,j) for :: i = "<< inside_index<<"\t";
                    /*Some simple calculation  Values*/

                        /*Total of i + j*/
                        int temp_minus=inside_index-1;
                        int temp_add=inside_index + 1;
                        int temp_j_difference=outside_index-1;
                        string difference_i_j=getStringValue_gordon(temp_minus) + getStringValue_gordon(outside_index) ;

                        /*subtraction of i- j*/
                        string total_i_j=getStringValue_gordon(temp_add) + getStringValue_gordon(outside_index);

                        /*Combining together of i and j */

                        string combine_i_j=getStringValue_gordon(inside_index) + getStringValue_gordon(outside_index);

                        /*j difference*/

                        string j_difference=getStringValue_gordon(inside_index) + getStringValue_gordon(temp_j_difference);
                        /*Getting the Current key Value*/
                        string current_key=getStringValue_gordon(inside_index) + getStringValue_gordon(outside_index + 1);

                    /*Implementing Boundary for U- values*/

                        if(inside_index==upper_bound_x || inside_index==0)
                        {
                            u_values_main_gordon[current_key]=0;
                            current_value=0;
                        }else
                        {

                            /*Adding the current value to the u_value_man map*/
                            current_value=(2*(1-(lamda_value_gordon*lamda_value_gordon))*u_values_main_gordon[combine_i_j]) + ((lamda_value_gordon*lamda_value_gordon)*u_values_main_gordon[difference_i_j]) + ((lamda_value_gordon*lamda_value_gordon)*u_values_main_gordon[total_i_j]) - (u_values_main_gordon[j_difference]) - ((t_interval_gordon * t_interval_gordon)*((abs(sin(u_values_main_gordon[combine_i_j]))>1e-7)*sin(u_values_main_gordon[combine_i_j])));
                            u_values_main_gordon[current_key]=current_value;
                        }
                    /*Implementing Boundary for U- values*/

                /*Printing the Current computed Value*/

                cout<<"\t" <<"U("<<current_key<<")"<<" = " <<current_value <<endl;
             }


           }/*End of the Main if condition*/

cout<<endl;

        }
}

string SineGordon_Equation::getStringValue_gordon(int integer_value) /*Converting Int to String*/
{
    stringstream getintValue;
    getintValue<<integer_value;

    return getintValue.str();
}


