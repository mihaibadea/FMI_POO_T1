#include <iostream>

#include "Numar_intreg_mare.h"
#include "Vector.h"

using namespace std;

int main()
{

    Numar_intreg_mare a,b;

    cout<<"Valorile lui a si b sunt: ";

    cin>>a>>b;

    cout<<"Suma lor este: "<<a+b<<'\n';

    cout<<"Diferenta lor este: "<<a-b<<'\n';

    cout<<"Produsul lor este: "<<a*b<<'\n';

    cout<<"Maximul lor este: "<<maxim(a,b,0)<<'\n';

    cout<<"Modulul maxim e al numarului: "<<maxim(a,b,1)<<'\n';

    cout<<'\n';

    Vector V1, V2;

    cout<<"Vectorul V1 este: ";

    cin>>V1;

    cout<<"Vectorul V2 este: ";

    cin>>V2;

    cout<<"Maximul elementelor din V1 este: "<<V1.maxim(0)<<'\n';

    cout<<"Modulul maxim al elementelor din V1 e al numarului: "<<V1.maxim(1)<<'\n';

    cout<<"Maximul elementelor din V2 este: "<<V2.maxim(0)<<'\n';

    cout<<"Modulul maxim al elementelor din V2 e al numarului: "<<V2.maxim(1)<<'\n';

    cout<<"Produsul scalar dintre V1 si V2 este: "<<V1*V2<<'\n';



    return 0;
}
