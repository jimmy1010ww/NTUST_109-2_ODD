#include "Atoi.h"

Atoi::Atoi()
{
    Atoi::beTrans = "";
}

Atoi::Atoi(string s)
{
    Atoi::beTrans = s;
}

void Atoi::SetString(string s)
{
    Atoi::beTrans = s;
}

const string Atoi::GetString()
{
    return Atoi::beTrans;
}

int Atoi::Length()
{
    return beTrans.length();
}

bool Atoi::IsDigital()
{  
    bool valid = true;
    negative = false;
    for (int i = 0; i < beTrans.length(); i++) {
        if (i == 0)
        {
            if (!isdigit(beTrans[0]))
            {
                if (beTrans[0] == '-' )
                {
                    negative = true;
                    beTrans.erase(beTrans.begin());
                }
                else
                {
                    valid = false;
                }
                
            }

        }
        else {
            if (!isdigit(beTrans[i]))
            {
                valid = false;
            }
        }
        
    }
    return valid;
}

int Atoi::StringToInteger()
{
    int ans;
    if (negative)
    {
        ans = atoi(beTrans.c_str());
        ans = 0 - ans;
    }
    else
    {
        ans = atoi(beTrans.c_str());
    }
    return ans;
}

