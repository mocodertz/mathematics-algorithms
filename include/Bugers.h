#ifndef BUGERS_H
#define BUGERS_H
#include<vector>
#include<map>
#include<string>

using namespace std;

class Bugers
{
    public:
        Bugers(float x_value,float t_value,float upper_baound_xValue,float upper_bound_tValue,float viscosity_coeffient_value);
        void buger_equation_calculation();
        void set_x_interval(float x_value_interval);
        void set_t_interval(float t_value_interval);
        float get_x_interval();
        float get_t_interval();
        void set_value_of_C();
        void set_value_of_V();
        void set_value_of_D();

        /*For converting integer to String*/
        string getStringValue(int integer_value);

        /*---Processing the Values of U*/
        void process_values_of_U(unsigned int menu_option);

        /*Processing the Values of Set X and T*/

        void compute_the_value_set_x();
        void compute_the_value_set_t();

        /*This function will process the to the final Answer*/
        void overall_buger_calculation();

        /*---Operator Overloading---*/
       // void operator *(float value_one,float value_two);
        //void operator /(float value_one ,float value_two);

        ~Bugers();
    protected:
    private:
        float x_interval;
        float t_interval;
        float value_of_c;
        float value_of_d;
        float value_of_v;
        vector<float> x_values;
        vector<float> t_values;
        vector<float> u_values;
        float viscosity_coeffient;

        /*Values for Looping*/
        unsigned int i; /*x interval*/
        unsigned int j;  /*t Interval*/

        /* Map Data Structure */
        map<string,float> u_values_main; /*<key , value>*/

};

#endif // BUGERS_H
