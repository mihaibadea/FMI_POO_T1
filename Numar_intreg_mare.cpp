#include "Numar_intreg_mare.h"

Numar_intreg_mare::Numar_intreg_mare() : semn(0), cifre({})
{

}

Numar_intreg_mare::Numar_intreg_mare(const Numar_intreg_mare &other): semn(other.semn), cifre(other.cifre)
{

}

Numar_intreg_mare::Numar_intreg_mare(int k)
{
    if(k<0) semn=-1;
    else if(k==0) semn=0;
    else semn=+1;
    while(k!=0)
    {
        cifre.push_back(k%10);
        k=k/10;
    }

}


std::string Numar_intreg_mare::tostr()
{
    std::string k="";


    for(auto i : cifre)
    {
        char c = i + '0';
        k= k + c;
    }

    reverse(k.begin(), k.end());

    if(semn == -1) k = '-' + k;

    return k;
}


std::ostream& operator<<(std::ostream& out, const Numar_intreg_mare &nr)
{
    Numar_intreg_mare tmp;

    tmp=nr;

    if(tmp.semn==-1) out<<'-';

    while(!tmp.cifre.empty())
    {
        out<<tmp.cifre.back();
        tmp.cifre.pop_back();
    }

    return out;
}

std::istream& operator>>(std::istream& in, Numar_intreg_mare& nr)
{
    std::string k;
    short int prim=0;
    in>>k;

    if(k=="0")
    {
        nr.semn=0;
        prim=0;
    }

    else if(k=="+0" || k=="-0")
    {
        nr.semn=0;
        prim=1;
    }


    else if(k[0]=='-')
    {
        nr.semn=-1;
        prim=1;
    }

    else if(k[0]=='+')
    {
        nr.semn=1;
        prim=1;
    }

    else
    {
        nr.semn=1;
        prim=0;
    }

    nr.cifre.clear();

    for(int i=k.size()-1; i>=prim; i--)
    {
        nr.cifre.push_back(k[i] - '0');
    }

    while(nr.cifre.back()==0 && nr.semn!=0)
    {
        nr.cifre.pop_back();
    }

    return in;
}

short int compar(Numar_intreg_mare a, Numar_intreg_mare b, bool abs)
{
    if(abs==0)
    {
        if(a.semn>b.semn) return 1;

        if(a.semn<b.semn) return -1;
    }


    short int ret=1,skip=0;

    if(abs==0 && a.semn==-1) ret=-1;

    if(a.cifre.size() > b.cifre.size()) return ret;

    if(a.cifre.size() < b.cifre.size()) return -1*ret;


    while(a.cifre.size()!=0)
    {
        if(a.cifre.back() > b.cifre.back()) return ret;
        if(a.cifre.back() < b.cifre.back()) return -1*ret;
        a.cifre.pop_back();
        b.cifre.pop_back();
    }


    return 0;
}

Numar_intreg_mare maxim(Numar_intreg_mare a, Numar_intreg_mare b, bool abs)
{

    if(compar(a,b,abs) == 1) return a;

    return b;

}



Numar_intreg_mare Numar_intreg_mare::operator+(const Numar_intreg_mare nr)
{
    Numar_intreg_mare sum;


        auto ita=cifre.begin();
        auto itb=nr.cifre.begin();

        int m = std::max(cifre.size(), nr.cifre.size());

        short int rem=0,a,b;

        sum.cifre.clear();


    if(semn==nr.semn)
    {

        for(int i=0; i<m; i++)
        {
            if(ita!=cifre.end()) a=*ita;
            else a=0;

            if(itb!=nr.cifre.end()) b=*itb;
            else b=0;


            sum.cifre.push_back((a+b+rem)%10);
            rem=(a+b+rem)/10;

            if(ita!=cifre.end()) ita++;

            if(itb!=nr.cifre.end()) itb++;
        }

        if(rem!=0) sum.cifre.push_back(rem);

        sum.semn=semn;

    }

    else if(compar(*this, nr, 1)==0)
    {
        sum.cifre.push_back(0);
        sum.semn=0;
    }


    else if(compar(*this, nr, 1)==1)
    {

       for(int i=0; i<m; i++)
        {
            if(ita!=cifre.end()) a=*ita;
            else a=0;

            if(itb!=nr.cifre.end()) b=*itb;
            else b=0;


            sum.cifre.push_back((10+a-b-rem)%10);

            if(a<b) rem=1;
            else rem=0;

            if(ita!=cifre.end()) ita++;

            if(itb!=nr.cifre.end()) itb++;
        }

        while(sum.cifre.back()==0)
        {
            sum.cifre.pop_back();
        }

        sum.semn=semn;
    }

    else
    {
       for(int i=0; i<m; i++)
        {
            if(ita!=cifre.end()) a=*ita;
            else a=0;

            if(itb!=nr.cifre.end()) b=*itb;
            else b=0;


            sum.cifre.push_back((10+b-a-rem)%10);

            if(b<a) rem=1;
            else rem=0;

            if(ita!=cifre.end()) ita++;

            if(itb!=nr.cifre.end()) itb++;
        }

        while(sum.cifre.back()==0)
        {
            sum.cifre.pop_back();
        }


        sum.semn=nr.semn;
    }



    return sum;
}

Numar_intreg_mare Numar_intreg_mare::operator=(const Numar_intreg_mare &nr)
{
    if (this == &nr) return *this;
    cifre=nr.cifre;
    semn=nr.semn;
    return *this;
}

Numar_intreg_mare Numar_intreg_mare::operator-(const Numar_intreg_mare nr)
{
    Numar_intreg_mare opus;
    opus.cifre=nr.cifre;
    opus.semn=-1*nr.semn;
    return *this + opus;
}

Numar_intreg_mare Numar_intreg_mare::operator*(const Numar_intreg_mare nr)
{

    Numar_intreg_mare rez;

    Numar_intreg_mare a=*this;

    Numar_intreg_mare b=nr;

    short int rem=0;


    if(b.cifre.size()==1)
    {
        rez.cifre.clear();
        while(a.cifre.size()!=0)
        {

            rez.cifre.push_back((rem+a.cifre.front()*nr.cifre.back())%10);
            rem=(rem+a.cifre.front()*nr.cifre.back())/10;

            a.cifre.pop_front();
        }

        if(rem!=0) rez.cifre.push_back(rem);

    }


   else if(compar(nr,Numar_intreg_mare(10),0)==0)
    {
        rez.cifre = a.cifre;
        rez.cifre.push_front(0);
    }

    else
    {
        int k=0;
        while(!b.cifre.empty())
        {

            Numar_intreg_mare t;

            t=a*Numar_intreg_mare(b.cifre.front());

            for(int i=0; i<k; i++)
            {
                t=t*Numar_intreg_mare(10);
            }

            b.cifre.pop_front();

            k++;

            rez=rez+t;
        }
    }

    rez.semn=semn*nr.semn;

    return rez;

}
