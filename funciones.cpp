#include "Producto.h"
#include <string.h>
#include <fstream>
using namespace std;
Producto::Producto(int c,string des,int  ex, int sM,int sm, float pr)
{

    setCodP(c);
    setDescripcion(des);
    setExistencia(ex);
    setStockMax(sM);
    setStockMin(sm);
    setPrecioR(pr);

    }

void Producto::setCodP(int c)
{
    codp = c;
}

int Producto::getCodP()
{
    return codp;
}

void Producto::setDescripcion(string des)
{
    const char *valorDescripcion = des.data();
    int longitud = des.size();
    if(longitud>=25)
        longitud=24;
    strncpy(descripcion,valorDescripcion,longitud);
    descripcion[longitud] = '\0';
}

string Producto::getDescripcion()
{
    return descripcion;
}

void Producto::setExistencia(int ex)
{
   existencia = ex;
}

int Producto::getExistencia()
{
    return existencia;
}
 void Producto::setStockMax(int sM)
 {
     stmax = sM;
 }
int Producto::getStockMax()
{
    return stmax;
}
void Producto::setStockMin(int sm)
{
    stmin= sm;
}
int Producto::getStockMin()
{
    return stmin;
}
void Producto::setPrecioR(float pr)
{
    preciorep = pr;
}
float Producto::getPrecioR()
{
    return preciorep;
}

void Producto::setBorrado(int b)
{
    if(b!=0 && b!=1)
        borrado=0;
    else
        borrado=b;
}

int Producto::getBorrado()
{
    return borrado;
}

void Producto::buscar(fstream &a)
{
    Producto reg;
    a.clear();
    a.seekg(0,ios::beg);
    a.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
    while(!a.eof()&&reg.getCodP()!=codp)
    {
        a.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
    }
}
