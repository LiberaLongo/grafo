//lista per le classi ereditata
//quindi non posso usare == o cout<<
//ma devo usare contronto() e print()

#include "../header/Lista.hpp"

//costruttore e distruttore
template <typename Tipo>
Lista<Tipo>::Lista(void) : ListaParent<Tipo>()
{
}

//cerca v scorrendo la lista
//override
template <typename Tipo>
struct Elem<Tipo> *Lista<Tipo>::search(Tipo v)
{
	struct Elem<Tipo> *find = nullptr;
	if (!(this->empty()))
	{
		struct Elem<Tipo> *iter = this->head();
		bool trovato = false;
		//se non finita, oppure lo hai trovato
		while (!(this->finished(iter)) || !trovato)
		{
			//se lo trovi
			if (v.confronto(this->read(iter))) //MODIFICATA!
			{
				find = iter;
				trovato = true;
			}
			iter = this->next(iter);
		}
	}
	return find;
}

//stampe
//override
template <typename Tipo>
string Lista<Tipo>::toString(void)
{
	string res = "\nLista:[ ";
	if (!(this->empty()))
	{
		//primo elemento utile non la sentinella
		struct Elem<Tipo> *iter = this->head();
		//se non vuota e non finita
		while (!(this->finished(iter)))
		{
			//stampo elemento
			res = res + this->read(iter).toString();
			//passo al successivo e stampo freccia
			iter = this->next(iter);
			if (!(this->finished(iter)))
				res = res + " --> ";
		}
	}
	res = res + " ]\n";
	return res;
}
template <typename Tipo>
void Lista<Tipo>::print(void) {
	cout << endl << this->toString();
}
//disegna elementi
template <typename Tipo>
void Lista<Tipo>::draw(sf::RenderWindow &window)
{
	if (!(this->empty()))
	{
		//primo elemento utile non la sentinella
		struct Elem<Tipo> *iter = this->head();
		//se non vuota e non finita
		while (!(this->finished(iter)))
		{
			Tipo disegnato = this->read(iter);
			disegnato.draw(window);
			//passo al successivo
			iter = this->next(iter);
		}
	}
}
