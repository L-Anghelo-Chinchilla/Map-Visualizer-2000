
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <array>
#include <string>
#include <gdiplus.h>
using namespace std;
using namespace Gdiplus;
class Grafo {
private:
	vector<vector<int> > listaAd;
	vector<vector<int> > matrizIn;
	vector<pair<int,*vector<int> > > vertices // lista de vertices cada vertice se reprecenta con un numero autoincrementable y un puntero a su lista de adyacencia 
	int vertices;
	bool dirigido;
public:
	Grafo();
	Grafo(int v, bool d, vector<vector<int> > mat)
		:vertices(v), dirigido(d), listaAd(mat) {
			for(int i = 0 ; i < mat.size(); i++ )
			{
			 	this.vertices.emplace_back(make_pair( i, &(mat[i]) ));	// creamos lista de vertices 		
			}

		}

	vector<int> bfs(int v)
	{
		vector<int> vect;
		vector<int> marcado;
		queue<int> cola;
		marcado.push_back(v);
		cola.push(v);
		while (!cola.empty())
		{
			int i = cola.front();
			cola.pop();
			vect.push_back(i);
			vector<int> adyac = listaAd[i];
			for (int vertice : adyac)
			{
				if (count(marcado.begin(), marcado.end(), vertice) == 0)
				{
					marcado.push_back(vertice);
					cola.push(vertice);
				}
			}
		}
		for (int v : vect) {
			cout << v << " , ";
		}
		cout << '\n' << '\n' << '\n';
		return vect;
	}

	vector<int> dfs(int v)
	{
		vector<int> vect;
		vector<int> marcado;
		stack<int> pila;
		marcado.push_back(v);
		pila.push(v);
		while (!pila.empty())
		{
			int i = pila.top();
			pila.pop();
			vect.push_back(i);
			vector<int> adyac = listaAd[i];
			for (int vertice : adyac)
			{
				if (count(marcado.begin(), marcado.end(), vertice) == 0)
				{
					marcado.push_back(vertice);
					pila.push(vertice);
				}
			}
		}
		return vect;
	}

	vector<pair<int, int> > dijktra(int desde)
	{
		vector<pair<int, int> > vec;
		queue<int> cola;
		for (int vertice : listaAd[desde])
			vec.push_back(make_pair(vertices, 100));

		vec.push_back(make_pair(desde, 0));
		cola.push(desde);
		while (!cola.empty())
		{
			int actual = cola.front();
			cola.pop();
			vector<int> adyacentes = listaAd[actual];


			for (int n : adyacentes)
			{
				int indice1 = buscar(vec, actual);
				int indice2 = buscar(vec, n);
				if (vec[indice1].second + 1 < vec[indice2].second)
					vec.push_back(make_pair(n, vec[indice1].second + 1));
				cola.push(n);
			}
		}
		return vec;
	}


	int buscar(vector<pair<int, int> > v, int n) {
		int i;
		for (i = 0; i < v.size(); i++)
		{
			if (v[i].first = n)break;
		}
		return i;
	}

	void getRutas(int desde, int hasta, int distancia, vector<int> ruta, vector<vector<int > >* todas)
	{
		for (int vertice : listaAd[desde])
		{
			if (hasta == desde)
			{
				if (count(ruta.begin(), ruta.end(), desde) == 0) {
					ruta.push_back(desde);
					todas->push_back(ruta);
				}
			}
			else
			{
				if (count(ruta.begin(), ruta.end(), desde) == 0)
				{
					ruta.push_back(desde);
				}
				if (count(ruta.begin(), ruta.end(), vertice) == 0)
					getRutas(vertice, hasta, distancia + 1, ruta, todas);
			}
		}
	}

	void getRutas2(int desde, int hasta, int distancia, vector<int> ruta, vector<vector<int > >* todas)
	{
		for (int vertice : listaAd[desde])
		{
			if (hasta == desde)
			{
				if (count(ruta.begin(), ruta.end(), desde) == 0) {
					ruta.push_back(desde);
					todas->push_back(ruta);
				}
			}
			else
			{
				if (count(ruta.begin(), ruta.end(), desde) == 0)
				{
					ruta.push_back(desde);
				}
				if (count(ruta.begin(), ruta.end(), vertice) == 0)
					getRutas2(vertice, hasta, distancia + 1, ruta, todas);
			}
		}
	}


	pair<Point *,int> getMejorRuta(int desde, int hasta)
	{
		vector<vector<int> > todas;
		vector<int>  ruta;
		getRutas(desde, hasta, 0, ruta, &todas);
		int minimo = 2147483647, indice = 0;
		for (int i = 0; i < todas.size(); i++)
		{
			if (todas[i].size() < minimo)
			{
				minimo = todas[i].size();
				indice = i;
			}
		}
		pair<Point* ,int>  p= getPuntos(&(todas[indice]));
		return p;
	}

	vector<vector<pair<int, int>>> getAristas() {
		vector<vector<pair<int, int>>> lista;
		int i = 0;
		for (vector<int> vec : listaAd)
		{
			vector<pair<int, int>> vect;
			for (int n : vec)
			{
				vect.push_back(make_pair(i, n));
			}
			i++;
			lista.push_back(vect);
		}
		return lista;
	}

	bool pasoAdelante(bool hecho, int vertice, int meta[], vector<int>* ruta, vector<pair<int, int>>* utilizados)
	{
		if (hecho)
		{

		}
		else
		{
			if (count(&(meta[0]), &(meta[6]), vertice) == 0)
			{

			}
		}
		return hecho;
	}

	void getRutasSimul(vector<vector<int> >& elTodo) {
		vector<vector<pair<int, int>>> aristas = getAristas();
		vector<pair<int, int> > utilizados;
		vector<int> rutaA, rutaB, rutaC;
		bool a, b, c; a = b = c = false;
		int metaA[]{ 6,13,20,27,34 }, metaB[]{ 28,29,30,31,32,33,34 }, metaC[]{ 0,1,2,3,4,5,6 };
		vector<vector<int> > vectorinoA, vectorinoC, vectorinoB; 
		for (int meta : metaA) {
			getRutas(14, meta, 0, rutaA, &vectorinoA);
		}
		for (int meta : metaB) {
			getRutas(3, meta, 0, rutaB, &vectorinoB);
		}
		for (int meta : metaC) {
			getRutas(34, meta, 0, rutaC, &vectorinoC);
		}
		getRutade3(&vectorinoA, &vectorinoB, &vectorinoC, &elTodo);
	
	}

	bool nocomun(vector<int> uno, vector<int> dos)
	{
		bool sepuede = true;
		for (int i = 1; sepuede && i < uno.size(); i++)
		{
			for (int j = 1; sepuede && j < dos.size(); j++)
			{
				if ((uno[i - 1] == dos[j - 1] && uno[i] == dos[j] )||(uno[i - 1] == dos[j] && uno[i] == dos[j-1]) ) sepuede = false;
			}
		}
		return sepuede;
	}

	void getRutade3(vector<vector<int> >* vA, vector<vector<int> >* vB, vector<vector<int> >* vC, vector<vector<int> >* todo)
	{
		bool sepuede = true;
		for (vector<int> vdeA : *(vA))
			for (vector<int> vdeB : *(vB))
				if (nocomun(vdeA, vdeB))
					for (vector<int> vdeC : *(vC))
						if (nocomun(vdeA, vdeC))
							if (nocomun(vdeB, vdeC))
							{
								if (vdeA.size() + vdeB.size() + vdeC.size() > 36) {
									todo->push_back(vdeA); todo->push_back(vdeB); todo->push_back(vdeC);
								}
								
							}
	}

	int pix2ver(int x , int y ) 
	{
		int num;
		if (x >= 75 && x <= 100 && y >= 225 && y <= 260)
			num = 14;
		else if (x >= 270 && x <= 305 && y >= 75 && y <= 100)
			num = 3;
		else if (x >= 425 && x <= 460 && y >= 385 && y <= 405)
			num = 34;
		else
		{
			if (y >= 130 && y <= 150) num = 0;
			else if (y >= 180 && y <= 200) num = 7;
			else if (y >= 230 && y <= 250) num = 14;
			else if (y >= 280 && y <= 300) num = 21;
			else if (y >= 330 && y <= 350) num = 28;
			else num = -1;


			if (x >= 130 && x <= 150) num += 0;
			else if (x >= 180 && x <= 200) num += 1;
			else if (x >= 230 && x <= 250) num += 2;
			else if (x >= 280 && x <= 300) num += 3;
			else if (x >= 330 && x <= 350) num += 4;
			else if (x >= 380 && x <= 400) num += 5;
			else if (x >= 430 && x <= 450) num += 6;
			else num = -1;
		}
		return num;
	}


	pair<Point *,int> getPuntos(vector<int>* ruta ) 
	{
		vector<Point> puntos; 
		for (int v : *(ruta)) {
			puntos.emplace_back(Point(140+(50*(v%7)),140+(50*(v/7))));
		}
		return make_pair(&(puntos[0]),puntos.size());
	}

	string cadena(vector<int>* vec ) 
	{
		string s;
		for (int i : *(vec))
			s += to_string(i) + ", ";
		s += '\n';
		return s;
	}
};