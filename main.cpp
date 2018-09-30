#include <iostream>
#include<conio.h>

#include "..\include\Bugers.h"
#include "..\include\Fisher_Equation.h"
#include "..\include\SineGordon_Equation.h"
#include "..\include\Korteweg_de_VariesEquation.h"
#include "..\include\Gardner_Equation.h"

using namespace std;
int main()
{
mainLabel:
/*Select the Equation you want to solve*/
    cout<<endl;
/*List of the Initial Condition*/
    cout<<"Select the Equation you want to Use"<<endl;
        cout<<endl;
        cout<<"\t"<<"1." <<" "<<"Burger's Equation"<<endl;
        cout<<"\t"<<"2." <<" "<<"Sine Gordon Equation"<<endl;
        cout<<"\t"<<"3." <<" "<<"Korteweg-de Varies Equation"<<endl;
        cout<<"\t"<<"4." <<" "<<"Fisher's Equation"<<endl;
        cout<<"\t"<<"5." <<" "<<"Gardner Equation"<<endl;
cout<<endl;

int main_menu_select;
cout<<"Enter the Menu Option::";
cin>>main_menu_select;

 /*Testing the Main Menu*/
    if(main_menu_select==1)/*For Burger's Equation*/
    {

        /*Burger Equation*/
        cout<<endl;
    /*List of the Initial Condition*/
        cout<<"Select the Initial Condition to Solve the Burger's Equation"<<endl;
            cout<<endl;
            cout<<"\t"<<"1." <<" "<<"U(x,0)=sin(pi)x"<<endl;
            cout<<"\t"<<"2." <<" "<<"U(x,0)=1/x"<<endl;
            cout<<"\t"<<"3." <<" "<<"U(x,0)=cos x"<<endl;
            cout<<"\t"<<"4." <<" "<<"U(x,0)=x "<<endl;
        cout<<endl;

        int menu_select;
        cout<<"Enter the Menu Option::";
        cin>>menu_select;



    /*End  of the Initial Condition list*/

    /*Accepting the Input from the User*/
        float in_x_interval=0.0;
        float in_t_interval=0.0;
        float in_x_bound=0.0;
        float in_t_bound=0.0;
        float in_viscosity_coeffient=0.0;

        cout<<"Enter the value of x Interval ::";
        cin>>in_x_interval;

        cout<<"Enter the value of t Interval ::";
        cin>>in_t_interval;

        cout<<"Enter the value of x Bound ::";
        cin>>in_x_bound;

        cout<<"Enter the value of t Bound ::";
        cin>>in_t_bound;

        cout<<"Enter the Viscosity Coefficient::";
        cin>>in_viscosity_coeffient;

        cout<<endl;
    /*End of Accepting the input from the user*/


        cout<<"----------Discretization process----------"<<endl;
    /*Creating the Class*/
        Bugers currentExample(in_x_interval,in_t_interval,in_x_bound,in_t_bound,in_viscosity_coeffient);
    cout<<endl;
    cout<<"**set of x**"<<endl;
        currentExample.compute_the_value_set_x();

    cout<<endl;
    cout<<"** Set of t**"<<endl;
        currentExample.compute_the_value_set_t();

    cout<<endl;
    cout<<"**Calculating the values of U's**"<<endl;
        currentExample.process_values_of_U(menu_select);

    cout<<endl;
    cout<<"----------Calculation Process using  Buger's Equation----------"<<endl;
    /*Computing some of constant values*/
    currentExample.set_value_of_V();
    currentExample.set_value_of_C();
    currentExample.set_value_of_D();


    currentExample.buger_equation_calculation();

    }

    else if(main_menu_select==2)/*Sine Gordon Equation*/
    {
        /*Sine Gordon Equation*/

            /*Sine Gordon Equation*/
        /*Sine Gordon Equation*/
        cout<<endl;
    /*List of the Initial Condition*/
        cout<<"Select the Initial Condition to Solve the Sine Gordon Equation"<<endl;
            cout<<endl;
            cout<<"\t"<<"1." <<" "<<"U(x,0)=sin(pi)x"<<endl;
            cout<<"\t"<<"2." <<" "<<"U(x,0)=x(1-x)"<<endl;
            cout<<"\t"<<"3." <<" "<<"U(x,0)=cos x"<<endl;
            cout<<"\t"<<"4." <<" "<<"U(x,0)=x "<<endl;
        cout<<endl;

        int menu_select_gordon;
        cout<<"Enter the Menu Option::";
        cin>>menu_select_gordon;

    /*End  of the Initial Condition list*/

    /*Accepting the Input from the User*/
        float in_x_interval_gordon=0.0;
        float in_t_interval_gordon=0.0;
        float in_x_bound_gordon=0.0;
        float in_t_bound_gordon=0.0;


        cout<<"Enter the value of x Interval ::";
        cin>>in_x_interval_gordon;

        cout<<"Enter the value of t Interval ::";
        cin>>in_t_interval_gordon;

        cout<<"Enter the value of x Bound ::";
        cin>>in_x_bound_gordon;

        cout<<"Enter the value of t Bound ::";
        cin>>in_t_bound_gordon;


        cout<<endl;
    /*End of Accepting the input from the user*/


        cout<<"----------Discretization process----------"<<endl;
    /*Creating the Class*/
        SineGordon_Equation currentExample_gordon(in_x_interval_gordon,in_t_interval_gordon,in_x_bound_gordon,in_t_bound_gordon);
    cout<<endl;
    cout<<"** Set of x **"<<endl;
        currentExample_gordon.compute_the_value_set_x_gordon();

    cout<<endl;
    cout<<"** Set of t **"<<endl;
        currentExample_gordon.compute_the_value_set_t_gordon();

    cout<<endl;
    cout<<"** Calculating the values of U's **"<<endl;
        currentExample_gordon.process_values_of_U_gordon(menu_select_gordon);

    cout<<endl;
    cout<<"----------Calculation Process using  Sine Gordon Equation----------"<<endl;
    /*Computing some of constant values*/
    currentExample_gordon.set_value_of_lamda();

    currentExample_gordon.gordon_equation_calculation();
    }

    else if(main_menu_select==3)    /*Korteweg-de Varies Equation*/
    {
        /*Korteweg-de Varies Equation*/
                  cout<<endl;
    /*List of the Initial Condition*/
        cout<<"Select the Initial Condition to Solve the Kortewegde Varies Equation"<<endl;
            cout<<endl;
            cout<<"\t"<<"1." <<" "<<"U(x,0)=sin(pi)x"<<endl;
            cout<<"\t"<<"2." <<" "<<"U(x,0)=1/(2-x)"<<endl;
            cout<<"\t"<<"3." <<" "<<"U(x,0)=cos x"<<endl;
            cout<<"\t"<<"4." <<" "<<"U(x,0)=x "<<endl;
        cout<<endl;

        int menu_select_korteweg;
        cout<<"Enter the Menu Option::";
        cin>>menu_select_korteweg;

    /*End  of the Initial Condition list*/

    /*Accepting the Input from the User*/
        float in_x_interval_korteweg=0.0;
        float in_t_interval_korteweg=0.0;
        float in_x_bound_korteweg=0.0;
        float in_t_bound_korteweg=0.0;


        cout<<"Enter the value of x Interval ::";
        cin>>in_x_interval_korteweg;

        cout<<"Enter the value of t Interval ::";
        cin>>in_t_interval_korteweg;

        cout<<"Enter the value of x Bound ::";
        cin>>in_x_bound_korteweg;

        cout<<"Enter the value of t Bound ::";
        cin>>in_t_bound_korteweg;


        cout<<endl;
    /*End of Accepting the input from the user*/


        cout<<"----------Discretization process----------"<<endl;
    /*Creating the Class*/
        Korteweg_de_VariesEquation currentExample_korteweg(in_x_interval_korteweg,in_t_interval_korteweg,in_x_bound_korteweg,in_t_bound_korteweg);
    cout<<endl;
    cout<<"** Set of x **"<<endl;
        currentExample_korteweg.compute_the_value_set_x_korteweg();

    cout<<endl;
    cout<<"** Set of t **"<<endl;
        currentExample_korteweg.compute_the_value_set_t_korteweg();

    cout<<endl;
    cout<<"** Calculating the values of U's **"<<endl;
        currentExample_korteweg.process_values_of_U_korteweg(menu_select_korteweg);

    cout<<endl;
    cout<<"----------Calculation Process using  Kortewegde Varies Equation----------"<<endl;
    /*Computing some of constant values*/


    currentExample_korteweg.korteweg_equation_calculation();

    }

    else if(main_menu_select==4)/*Fisher's Equation*/
    {
            /*Fishers Equation*/
        /*Fisher Equation*/
        cout<<endl;
    /*List of the Initial Condition*/
        cout<<"Select the Initial Condition to Solve the Fisher's Equation"<<endl;
            cout<<endl;
            cout<<"\t"<<"1." <<" "<<"U(x,0)=sin(pi)x"<<endl;
            cout<<"\t"<<"2." <<" "<<"U(x,0)=1/(2-x)"<<endl;
            cout<<"\t"<<"3." <<" "<<"U(x,0)=cos x"<<endl;
            cout<<"\t"<<"4." <<" "<<"U(x,0)=x "<<endl;
        cout<<endl;

        int menu_select_fisher;
        cout<<"Enter the Menu Option::";
        cin>>menu_select_fisher;

    /*End  of the Initial Condition list*/

    /*Accepting the Input from the User*/
        float in_x_interval_fisher=0.0;
        float in_t_interval_fisher=0.0;
        float in_x_bound_fisher=0.0;
        float in_t_bound_fisher=0.0;


        cout<<"Enter the value of x Interval ::";
        cin>>in_x_interval_fisher;

        cout<<"Enter the value of t Interval ::";
        cin>>in_t_interval_fisher;

        cout<<"Enter the value of x Bound ::";
        cin>>in_x_bound_fisher;

        cout<<"Enter the value of t Bound ::";
        cin>>in_t_bound_fisher;


        cout<<endl;
    /*End of Accepting the input from the user*/


        cout<<"----------Discretization process----------"<<endl;
    /*Creating the Class*/
        Fisher_Equation currentExample_fisher(in_x_interval_fisher,in_t_interval_fisher,in_x_bound_fisher,in_t_bound_fisher);
    cout<<endl;
    cout<<"** Set of x **"<<endl;
        currentExample_fisher.compute_the_value_set_x_fisher();

    cout<<endl;
    cout<<"** Set of t **"<<endl;
        currentExample_fisher.compute_the_value_set_t_fisher();

    cout<<endl;
    cout<<"** Calculating the values of U's **"<<endl;
        currentExample_fisher.process_values_of_U_fisher(menu_select_fisher);

    cout<<endl;
    cout<<"----------Calculation Process using  fisher's Equation----------"<<endl;
    /*Computing some of constant values*/
    currentExample_fisher.set_value_of_lamda();

    currentExample_fisher.fisher_equation_calculation();

    _getch();
    }
    else if(main_menu_select==5)   /*Gardner Equation */
    {
        /*Gardner Equation*/
        /*Gardner Equation*/
        cout<<endl;
    /*List of the Initial Condition*/
        cout<<"Select the Initial Condition to Solve the Gardner's Equation"<<endl;
            cout<<endl;
            cout<<"\t"<<"1." <<" "<<"U(x,0)=sin(pi)x"<<endl;
            cout<<"\t"<<"2." <<" "<<"U(x,0)=1/(2-x)"<<endl;
            cout<<"\t"<<"3." <<" "<<"U(x,0)=cos x"<<endl;
            cout<<"\t"<<"4." <<" "<<"U(x,0)=x "<<endl;
        cout<<endl;

        int menu_select_gardner;
        cout<<"Enter the Menu Option::";
        cin>>menu_select_gardner;

    /*End  of the Initial Condition list*/

    /*Accepting the Input from the User*/
        float in_x_interval_gardner=0.0;
        float in_t_interval_gardner=0.0;
        float in_x_bound_gardner=0.0;
        float in_t_bound_gardner=0.0;


        cout<<"Enter the value of x Interval ::";
        cin>>in_x_interval_gardner;

        cout<<"Enter the value of t Interval ::";
        cin>>in_t_interval_gardner;

        cout<<"Enter the value of x Bound ::";
        cin>>in_x_bound_gardner;

        cout<<"Enter the value of t Bound ::";
        cin>>in_t_bound_gardner;


        cout<<endl;
    /*End of Accepting the input from the user*/


        cout<<"----------Discretization process----------"<<endl;
    /*Creating the Class*/
        Gardner_Equation currentExample_gardner(in_x_interval_gardner,in_t_interval_gardner,in_x_bound_gardner,in_t_bound_gardner);
    cout<<endl;
    cout<<"** Set of x **"<<endl;
        currentExample_gardner.compute_the_value_set_x_gardner();

    cout<<endl;
    cout<<"** Set of t **"<<endl;
        currentExample_gardner.compute_the_value_set_t_gardner();

    cout<<endl;
    cout<<"** Calculating the values of U's **"<<endl;
        currentExample_gardner.process_values_of_U_gardner(menu_select_gardner);

    cout<<endl;
    cout<<"----------Calculation Process using  Gardner's Equation----------"<<endl;
    /*Computing some of constant values*/


    currentExample_gardner.gardner_equation_calculation();
    }
    else    /*Default Condition*/
    {
        cout<<"Start Again the Menu Value selected Not Available"<<endl;
      goto  mainLabel;
    }

/*End of the Selection Menu*/

    _getch(); // Freeze the Screen
    return 0;
}
