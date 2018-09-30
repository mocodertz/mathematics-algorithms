#ifndef SINEGORDON_EQUATION_H
#define SINEGORDON_EQUATION_H

#include<vector>
#include<map>
#include<string>

using namespace std;
class SineGordon_Equation
{
    public:
        SineGordon_Equation(float x_value_gordon,float t_value_gordon,float upper_baound_xValue_gordon,float upper_bound_tValue_gordon);
        void set_x_interval_gordon(float x_value_interval);
        void set_t_interval_gordon(float t_value_interval);
        float get_x_interval_gordon();
        float get_t_interval_gordon();
        void set_value_of_lamda();


        /*For converting integer to String*/
        string getStringValue_gordon(int integer_value);

        /*---Processing the Values of U*/
        void process_values_of_U_gordon(unsigned int menu_option);

        /*Processing the Values of Set X and T*/

        void compute_the_value_set_x_gordon();
        void compute_the_value_set_t_gordon();

        /*This function will process the to the final Answer*/
        void overall_gordon_calculation();
        void gordon_equation_calculation();
         virtual ~SineGordon_Equation();

    protected:
    private:
        float lamda_value_gordon;
        float x_interval_gordon;
        float t_interval_gordon;
        vector<float> x_values_gordon;
        vector<float> t_values_gordon;
        vector<float> u_values_gordon;
        float upper_bound_x;
        float lower_bound_x;
        /*Values for Looping*/
        unsigned int i_gordon; /*x interval*/
        unsigned int j_gordon;  /*t Interval*/

        /* Map Data Structure */
        map<string,float> u_values_main_gordon; /*<key , value>*/

};

#endif // SINEGORDON_EQUATION_H
