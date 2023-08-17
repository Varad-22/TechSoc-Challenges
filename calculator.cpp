#include <iostream>

using namespace std;

double sum(double a, double b){
    return a+b;
}

double subs(double a, double b){
    return a-b;
}

double mult(double a, double b){
    return a*b;
}

double div(double a, double b){
    return a/b;
}

double power(double a, double b){
    double ans = 1;
    for(int i=1; i<=b; i++){
        ans = ans * a;
    }
    return ans;
}

int fact(int num){
    if (num == 0 || num == 1){
        return 1;
    }
    else{
        return (num * fact(num-1));
    }
}


double sin(double x_deg){  //x_deg is in 0 - 360
    double ans = 0;
    double sinx = 0;
    double pi = 3.141593;
    double x = x_deg * pi / 180;
    if (x_deg>=0 && x_deg<=90){
        for (int i=1; i<=10; i++){
            int sign = power(-1, (i+1));
            ans = ans + (sign * power(x,(2*i-1)) / fact(2*i-1));
        }return ans;
    }
    else if (x_deg>90 && x_deg<=180){
        x = pi - x;
        for (int i=1; i<=10; i++){
            int sign = power(-1, (i+1));
            ans = ans + (sign * power(x,(2*i-1)) / fact(2*i-1));
        }return ans;
    }

    else if (x_deg>180 && x_deg<=270){
        x = x - pi;
        for (int i=1; i<=10; i++){
            int sign = power(-1, (i+1));
            ans = ans + (sign * power(x,(2*i-1)) / fact(2*i-1));
        }return (0-ans);
    }
    else if (x_deg>270 && x_deg<=360){
        x = (2*pi) - x;
        for (int i=1; i<=10; i++){
            int sign = power(-1, (i+1));
            ans = ans + (sign * power(x,(2*i-1)) / fact(2*i-1));
        }return (0-ans);
    }
}

double cos(double x_deg){  //x_deg is in 0 - 360
    double ans = 0;
    double sinx = 0;
    double pi = 3.141593;
    double x = x_deg * pi / 180;
    if (x_deg>=0 && x_deg<=90){
        for (int i=1; i<=10; i++){
            int sign = power(-1, (i+1));
            ans = ans + (sign * power(x,(2*i-2)) / fact(2*i-2));
        }return ans;
    }
    else if (x_deg>90 && x_deg<=180){
        x = pi - x;
        for (int i=1; i<=10; i++){
            int sign = power(-1, (i+1));
            ans = ans + (sign * power(x,(2*i-2)) / fact(2*i-2));
        }return (0-ans);
    }

    else if (x_deg>180 && x_deg<=270){
        x = x - pi;
        for (int i=1; i<=10; i++){
            int sign = power(-1, (i+1));
            ans = ans + (sign * power(x,(2*i-2)) / fact(2*i-2));
        }return (0-ans);
    }
    else if (x_deg>270 && x_deg<=360){
        x = (2*pi) - x;
        for (int i=1; i<=10; i++){
            int sign = power(-1, (i+1));
            ans = ans + (sign * power(x,(2*i-2)) / fact(2*i-2));
        }return ans;
    }
}

double tan(double x_deg){
    return (sin(x_deg) / cos(x_deg));
}

int main(){
    string res = "yes";

    while (res == "yes"){
        double a, b;
        string op;
        cout << "Enter what you wanna perform: (+, -, *, /, exp, trigo) ";
        cin >> op;

    
        if(op != "trigo"){
            cout << "Enter first number: ";
            cin >> a;

            cout << "Enter second number: ";
            cin >> b;
            

            if (op == "+"){
                cout<< "Sum is: " <<sum(a,b)<<endl;
            }

            else if (op == "-"){
                cout << "Difference is: " << subs(a,b)<<endl;
            }

            else if (op == "*"){
                cout << "Product is: " <<mult(a,b)<<endl;
            }

            else if (op == "/"){
                cout << "Division is: " << div(a,b)<<endl;
            }

            else if (op == "exp"){
                cout << a << " to the power " << b << " is: " << power(a,b);
            }

        }

        else if (op == "trigo"){
            string ch;
            double x_deg;
            cout << "Enter the angle in degree: ";
            cin >> x_deg;
            
            cout << "Which trigo func you wanna use: ";
            cin >> ch;
            

            if (ch == "sin"){
                if (x_deg > 0){
                    if(x_deg>=0 && x_deg<=360){
                        cout << sin(x_deg)<<endl;
                    }
                    else{
                        int cnt;
                        for (int i = 1; i<=10; i++){
                            if (x_deg < i*360){
                                cnt = (i-1)*360;
                                break;
                            }
                            else{
                                continue;
                            }
                        }
                        x_deg = x_deg - cnt;
                        cout << sin(x_deg) << endl;
                        }
                    }
                else{
                    
                    double p_x_deg = 0-x_deg;
                    int cnt;
                    for (int i=1; i<=10; i++){
                        if (p_x_deg < i*360){
                            cnt = (i-1)*360;
                            break;
                        }
                        else{
                            continue;
                        }  
                    }
                    x_deg = x_deg + cnt;
                    cout << 0-sin(0-x_deg) << endl;
                }
            }

            else if (ch == "cos"){
                if (x_deg > 0){
                    if(x_deg>=0 && x_deg<=360){
                        cout << cos(x_deg)<<endl;
                    }
                    else{
                        int cnt;
                        for (int i = 1; i<=10; i++){
                            if (x_deg < i*360){
                                cnt = (i-1)*360;
                                break;
                            }
                            else{
                                continue;
                            }
                        }
                        x_deg = x_deg - cnt;
                        cout << cos(x_deg) << endl;
                        }
                    }
                else{
                    double p_x_deg = 0-x_deg;
                    int cnt;
                    for (int i=1; i<=10; i++){
                        if (p_x_deg < i*360){
                            cnt = (i-1)*360;
                            break;
                        }
                        else{
                            continue;
                        }  
                    }
                    x_deg = x_deg + cnt;
                    cout << 0-cos(0-x_deg) << endl;
                }
            }

            else if (ch == "tan"){
                if (x_deg > 0){
                    if(x_deg>=0 && x_deg<=360){
                        cout << tan(x_deg) << endl;
                    }
                    else{
                        int cnt;
                        for (int i = 1; i<=10; i++){
                            if (x_deg < i*360){
                                cnt = (i-1)*360;
                                break;
                            }
                            else{
                                continue;
                            }
                        }
                        x_deg = x_deg - cnt;
                        cout << tan(x_deg) << endl;
                        }
                    }
                else{
                    double p_x_deg = 0-x_deg;
                    int cnt;
                    for (int i=1; i<=10; i++){
                        if (p_x_deg < i*360){
                            cnt = (i-1)*360;
                            break;
                        }
                        else{
                            continue;
                        }  
                    }
                    x_deg = x_deg + cnt;
                    cout << 0-tan(0-x_deg) << endl;
                }
            }

            else{
                cout << "Invalid input"<<endl;
                break;
            }
        }

        else{
            cout << "Invalid input" <<endl;
            break;
        }

        cout << "Wanna continue? yes/no: ";
        cin >> res;
        if(res == "no"){
            cout<< "Thank you";
            break;
        }
        else{
            continue;
        }
    }
    return 0;
}