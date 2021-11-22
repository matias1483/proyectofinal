#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include<fstream>
#include<string>
using namespace std;
class Producto
{
    public:
        Producto(int =0,string ="",int=0, int= 0,int= 0, float = 0.0);
        void setCodP(int);
        int getCodP();
        void setDescripcion(string);
        string getDescripcion();
        void setExistencia(int);
        int getExistencia();
        void setStockMax(int);
        int getStockMax();
        void setStockMin(int);
        int getStockMin();
        void setPrecioR(float);
        float getPrecioR();
        void setBorrado(int);
        int getBorrado();
        void buscar(fstream &);
    private:
        int codp,existencia, stmax, stmin,borrado;
        char descripcion[25];
        float preciorep;
};





#endif // PRODUCTO_H_INCLUDED
