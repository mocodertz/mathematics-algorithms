#ifndef GARDNER_EQUATION_H
#define GARDNER_EQUATION_H

#include<vector>
#include<map>
#include<string>

using namespace std;

class Gardner_Equation
{
    public:
        Gardner_Equation(float x_value_gardner,float t_value_gardner,float upper_baound_xValue_gardner,float upper_bound_tValue_gardner);
        void set_x_interval_gardner(float x_value_interval);
        void set_t_interval_gardner(float t_value_interval);
        float get_x_interval_gardner();
        float get_t_interval_gardner();

        /*For converting integer to String*/
        string getStringValue_gardner(int integer_value);

        /*---Processing the Values of U*/
        void process_values_of_U_gardner(unsigned int menu_option);

        /*Processing the Values of Set X and T*/

        void compute_the_value_set_x_gardner();
        void compute_the_value_set_t_gardner();

        /*This function will process the to the final Answer*/
        void overall_gardner_calculation();
        void gardner_equation_calculation();
        virtual ~Gardner_Equation();
    protected:
    private:

        float x_interval_gardner;
        float t_interval_gardner;
        vector<float> x_values_gardner;
        vector<float> t_values_gardner;
        vector<float> u_values_gardner;
        float upper_bound_x;
        float lower_bound_x;
        /*Values for Looping*/
        unsigned int i_gardner; /*x interval*/
        unsigned int j_gardner;  /*t Interval*/

        /* Map Data Structure */
        map<string,float> u_values_main_gardner; /*<key , value>*/
};

#endif // GARDNER_EQUATION_H
