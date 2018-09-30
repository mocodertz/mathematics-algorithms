#ifndef KORTEWEG_DE_VARIESEQUATION_H
#define KORTEWEG_DE_VARIESEQUATION_H

#include<vector>
#include<map>
#include<string>

using namespace std;
class Korteweg_de_VariesEquation
{
    public:
        Korteweg_de_VariesEquation(float x_value_korteweg,float t_value_korteweg,float upper_baound_xValue_korteweg,float upper_bound_tValue_korteweg);
        void set_x_interval_korteweg(float x_value_interval);
        void set_t_interval_korteweg(float t_value_interval);
        float get_x_interval_korteweg();
        float get_t_interval_korteweg();
        void set_value_of_lamda();


        /*For converting integer to String*/
        string getStringValue_korteweg(int integer_value);

        /*---Processing the Values of U*/
        void process_values_of_U_korteweg(unsigned int menu_option);

        /*Processing the Values of Set X and T*/

        void compute_the_value_set_x_korteweg();
        void compute_the_value_set_t_korteweg();

        /*This function will process the to the final Answer*/
        void overall_korteweg_calculation();
        void korteweg_equation_calculation();
        virtual ~Korteweg_de_VariesEquation();
    protected:
    private:
        float x_interval_korteweg;
        float t_interval_korteweg;
        vector<float> x_values_korteweg;
        vector<float> t_values_korteweg;
        vector<float> u_values_korteweg;
        float upper_bound_x;
        float lower_bound_x;
        /*Values for Looping*/
        unsigned int i_korteweg; /*x interval*/
        unsigned int j_korteweg;  /*t Interval*/

        /* Map Data Structure */
        map<string,float> u_values_main_korteweg; /*<key , value>*/

};


#endif // KORTEWEG_DE_VARIESEQUATION_H
