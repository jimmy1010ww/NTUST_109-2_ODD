#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{

    string num, front, back, ans;
    int n = 0, m = 0;
    unsigned int pos, found = 0;
    int front_range, back_range = 0;
    char c;

    cin >> num >> m >> n >> c;

    while (!cin.eof())
    {

        found = num.find_first_of(".");

        if (found != -1) //find "."
        {
            front = num.substr(0, found);
            pos = found + 1;
            back = num.substr(pos);

            if (n > 0)
            {
                front_range = (int)(m - n - 1) - front.size();
                if (front_range > 0) //print front avaliable
                {
                    for (size_t i = 0; i < front_range; i++)
                    {
                        ans = ans + c;
                    }
                }

                ans += front;

                ans += ".";
                if (n > back.length())
                {
                    for (int i = 0; i < back.length(); i++)
                    {
                        ans += back[i];
                    }
                    for (int i = 0; i < (int)(n - back.length()); i++)
                    {
                        ans += "0";
                    }
                }
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        ans += back[i];
                    }
                }
            }
            else
            {
                front_range = (int)(m - n) - front.size();
                if (front_range > 0) //print front avaliable
                {
                    for (size_t i = 0; i < front_range; i++)
                    {
                        ans = ans + c;
                    }
                }

                ans += front;
            }
        }
        else
        {
            front = num;
            back.clear();
            if (n > 0)
            {
                front_range = (int)(m - n - 1) - num.size();

                if (front_range > 0) //print front avaliable
                {
                    for (size_t i = 0; i < front_range; i++)
                    {
                        ans = ans + c;
                    }
                }

                ans += front;
                ans += ".";
                if (n > back.length())
                {
                    for (int i = 0; i < back.length(); i++)
                    {
                        ans += back[i];
                    }
                    for (int i = 0; i < (int)(n - back.length()); i++)
                    {
                        ans += "0";
                    }
                }
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        ans += back[i];
                    }
                }
            }
            else
            {
                front_range = (int)(m - n) - num.size();

                if (front_range > 0) //print front avaliable
                {
                    for (size_t i = 0; i < front_range; i++)
                    {
                        ans = ans + c;
                    }
                }

                ans += front;
            }
        }

        cout << ans << endl;
        ans.clear();
        cin >> num >> m >> n >> c;
    }
}