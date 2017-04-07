//
//  Matrice.cpp
//  inf2-labo5
//
//  Created by Walid Koubaa on 05.04.17.
//  Copyright © 2017 Walid. All rights reserved.
//


#include "Matrice.hpp"
#include <exception>
#include <vector>

/*template <typename T>
Matrice<T>::Matrice(){
    this->lignes = 0;
}
*/

using namespace std;

template <typename T>
Matrice<T>::Matrice (unsigned int lignes){
    
    matrice=vector<T>(lignes);
}

template <typename T>
Matrice<T>::Matrice (unsigned int lignes,unsigned int colonnes){
    matrice=vector<vector<T>>(lignes);
}

template <typename T>
T Matrice<T>::at(unsigned int position) const{
    return matrice.at(position / matrice.size()).at(position % matrice.size());
}

template <typename T>
unsigned int Matrice<T>::size() const{
    return matrice.size();
}

template <typename T>
void Matrice<T>::resize(unsigned int nbLignes){
    matrice.resize(nbLignes);
}


template <typename T>
void Matrice<T>::resize(unsigned int nbLignes,unsigned int nbColonnes){
    matrice.resize(nbLignes);
    for(vector<T>& vect : matrice)
        vect.resize(nbColonnes);
}

template <typename T>
bool Matrice<T>::estVide() const {
    return matrice.size()==0; //&& vectColonnes.size()==0; // on regarde les lignes avant les collones au cas ou le constucteur avec les lignes seulement est appelle car celui avec les colonnes n'existe pas
}

template <typename T>
bool Matrice<T>::estCarre() const {
    return matrice.size();//==vectColonnes.size();
}

template <typename T>
bool Matrice<T>::estReguliere() const{
    for (T& t : matrice){
        if (!(t.size() == matrice.at(0))){ // si une des lignes pas egale a la premiere alors pas reguliere
            return false;
        }
    }
    return true;
}

template <typename T>
void Matrice<T>::push(unsigned int position,const T& valeur){
    matrice.at(position)=valeur;
}

template <typename T>
void pop( unsigned int position,const T& valeur){

}

template <typename T>
Vecteur<T> Matrice<T>::sommeLigne(){
    Vecteur <T> tempVecteur = Vecteur<T>(matrice.size());
    for(int i =0 ;i < tempVecteur.size();i++){
        for(T& t : matrice.at(i)){
            tempVecteur.at(i) += t;
        }
    }
}

template <typename T>
Vecteur<T> Matrice<T>::sommeColonne(){
    Vecteur <T> tempVecteur = Vecteur<T>(matrice.size());
    for(int i =0 ;i < tempVecteur.size();i++){
        for(T& t : matrice.at(i)){
            tempVecteur.at(i) += t;
        }
    }
}

template <typename T>
T Matrice<T>::sommeDiagonaleGD(){
    if(!estReguliere()){
        throw invalid_argument("Votre matrice n'est pas carré, la diagonale n'existe pas.");
    }
    T sommeDiagonale = 0;
    for(int i = 0; i< matrice.size();i++){
        for(int j =0 ; j <matrice.at(i).size(); j++){
            sommeDiagonale+= matrice.at(i).at(j - i - 1);
        }
    }
    
}

template <typename T>
T Matrice<T>::sommeDiagonaleDG(){
    if(!estReguliere()){
        throw invalid_argument("Votre matrice n'est pas carré, la diagonale n'existe pas.");
    }
    T sommeDiagonale = 0;
    for(int i = 0; i< matrice.size();i++){
        for(int j =0 ; j <matrice.at(i).size(); j++){
            sommeDiagonale+= matrice.at(j-i-1).at(i);
        }
    }
}

template <typename T>
std::ostream& operator << (std::ostream& os,const Matrice<T>& m){
    os << "[";
    for( int i =0 ; i < m.size()-1;i++ ){
        os << m.at(i) << ", ";
    }
    os << m.at(m.size()) << "]";
}

template <typename T>
Matrice<T>& operator * (Matrice <T>& m1, const Matrice<T>& m2){
    for(int i = 0; i< m2.size();i++){
        for(int j =0 ; j <m2.size(); j++){
            m1.at(i).at(j) *= m2.at(i).at(j);
        }
    }
    return m1;
}

template <typename T>
Matrice<T>&  operator * (Matrice <T>& m1,const T& val){// les deux sens a faire (commutativite)
    for(int i =0; i< m1.size(); i++){
        m1.at(i) *= val;
    }
    return m1;
}
template <typename T>
Matrice<T>&  operator + (Matrice<T>& m1,const Matrice<T>& m2){
    for(int i = 0; i< m1.size();i++){
        m1.at(i)+=m2.at(i);
    }
    return m1;
}
