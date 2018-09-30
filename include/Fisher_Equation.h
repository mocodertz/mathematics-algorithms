#ifndef FISHER_EQUATION_H
#define FISHER_EQUATION_H
#include<vector>
#include<map>
#include<string>

using namespace std;
class Fisher_Equation
{
    public:
        Fisher_Equation(float x_value_fisher,float t_value_fisher,float upper_baound_xValue_fisher,float upper_bound_tValue_fisher);
        void set_x_interval_fisher(float x_value_interval);
        void set_t_interval_fisher(float t_value_interval);
        float get_x_interval_fisher();
        float get_t_interval_fisher();
        void set_value_of_lamda();


        /*For converting integer to String*/
        string getStringValue_fisher(int integer_value);

        /*---Processing the Values of U*/
        void process_values_of_U_fisher(unsigned int menu_option);

        /*Processing the Values of Set X and T*/

        void compute_the_value_set_x_fisher();
        void compute_the_value_set_t_fisher();

        /*This function will process the to the final Answer*/
        void overall_fisher_calculation();
        void fisher_equation_calculation();
        virtual ~Fisher_Equation();
    protected:
    private:
        float lamda_value_fisher;
        float x_interval_fisher;
        float t_interval_fisher;
        vector<float> x_values_fisher;
        vector<float> t_values_fisher;
        vector<float> u_values_fisher;
        float upper_bound_x;
        float lower_bound_x;
        /*Values for Looping*/
        unsigned int i_fisher; /*x interval*/
        unsigned int j_fisher;  /*t Interval*/

        /* Map Data Structure */
        map<string,float> u_values_main_fisher; /*<key , value>*/

};

#endif // FISHER_EQUATION_H
